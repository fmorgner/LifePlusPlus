/*
 *
 * main.cpp
 * Part of Life++ - Yet another implementation of the Game of Life in C++
 * -------------------------------------------------------------------------
 * begin                 : 2013-02-23
 * copyright             : Copyright (C) 2013 by Felix Morgner
 * email                 : felix.morgner@gmail.com
 * =========================================================================
 *                                                                         |
 *   This program is free software; you can redistribute it and/or modify  |
 *   it under the terms of the GNU General Public License as published by  |
 *   the Free Software Foundation; either version 2 of the License, or     |
 *   (at your option) any later version.                                   |
 *                                                                         |
 *   This program is distributed in the hope that it will be useful,       |
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        |
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
 *   GNU General Public License for more details.                          |
 *                                                                         |
 *   You should have received a copy of the GNU General Public License     |
 *   along with this program; if not, write to the                         |
 *                                                                         |
 *   Free Software Foundation, Inc.,                                       |
 *   59 Temple Place Suite 330,                                            |
 *   Boston, MA  02111-1307, USA.                                          |
 * =========================================================================
 *
 */

#include <unistd.h>
#include <string>
#include <sstream>
#include <ncurses.h>
#include "CWorld.h"
#include <inttypes.h>
#include <thread>
#include <mutex>

bool bShouldRun = true;
bool bShouldReseed = false;

std::mutex goShouldRunMutex;
std::mutex goShouldReseedMutex;

void printStuckMessage(uint64_t nGenerations)
  {
  clear();
  
  int nPosX, nPosY;

  std::string sMessageStuck = "The simulation got stuck. Reseeding...";
  std::ostringstream sMessageGenerations;
  
  sMessageGenerations << "Got stuck after " << nGenerations << " generations.";
  
  nPosX = (getmaxx(stdscr) - (int) sMessageStuck.length()) / 2;
  nPosY = getmaxy(stdscr) / 2;
  
  mvprintw(nPosY, nPosX, sMessageStuck.c_str());
  
  nPosX = (getmaxx(stdscr) - (int) sMessageGenerations.str().length()) / 2;
  nPosY = getmaxy(stdscr) / 2 + 1;

  mvprintw(nPosY, nPosX, sMessageGenerations.str().c_str());
  
  refresh();
  }

void handleInput()
  {
  bool bEndInput = false;
  
  while(!bEndInput)
    {
    int c = getch();
    
    switch(c)
      {
      case 'q':
        goShouldRunMutex.lock();
        bShouldRun = false;
        goShouldRunMutex.unlock();
        bEndInput = true;
        break;
      case 'r':
        goShouldReseedMutex.lock();
        bShouldReseed = true;
        goShouldReseedMutex.unlock();
        break;
      default:
        break;
      }
    }
  }

bool shouldRun()
  {
  goShouldRunMutex.lock();
  bool returnValue = bShouldRun;
  goShouldRunMutex.unlock();
  return returnValue;
  }

int main(int argc, const char * argv[])
  {
  usleep(1000000);
  initscr();
  cbreak();

  World oWorld(getmaxx(stdscr), getmaxy(stdscr));
  oWorld.Seed();

  uint64_t nGenerations = 0;

  std::thread oUserInteractionThread(handleInput);

  while(bShouldRun)
    {
    move(0,0);
    printw(oWorld.StringRepresentation().c_str());
    refresh();
    oWorld.Update();
    
    if(oWorld.IsStuck())
      {
      printStuckMessage(nGenerations);
      usleep(3000000);
      nGenerations = 0;
      oWorld.Seed();
      }
    else
      {
      goShouldReseedMutex.lock();
      if(bShouldReseed)
        {
        bShouldReseed = false;
        nGenerations = 0;
        oWorld.Seed();
        }
      goShouldReseedMutex.unlock();
      }
    
    nGenerations++;
    
    usleep(33333);
    }

  oUserInteractionThread.join();
    
  endwin();
  
  return 0;
  }
