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

#include <string>
#include <sstream>
#include <ncurses.h>
#include "CWorld.h"
#include <inttypes.h>
#include <thread>

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

int main(int argc, const char * argv[])
  {
  initscr();
  cbreak();
  noecho();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  
  int  nUserInput       = 0;
  bool bBreak           = false;
  bool bResetFrameDelay = false;

  World oWorld(getmaxx(stdscr), getmaxy(stdscr)-1);
  oWorld.Seed();

  std::chrono::microseconds oCurrentFrameDelay(60000), oOriginalFrameDelay(oCurrentFrameDelay), oMessageDelay(3000000),  oTimeStep(10000), oNullTime(0);
  std::chrono::microseconds oWaitTime(0);
  std::chrono::steady_clock::time_point oStartTimepoint, oEndTimepoint;

  while(true)
    {
    oStartTimepoint = std::chrono::steady_clock::now();
    
    nUserInput = getch();
    
    if(oWorld.IsStuck())
      {
      printStuckMessage(oWorld.CurrentGeneration());
      oOriginalFrameDelay = oCurrentFrameDelay;
      bResetFrameDelay = true;
      oCurrentFrameDelay += oMessageDelay;
      oWorld.Seed();
      }

    switch (nUserInput)
      {
      case 'q':
        bBreak = true;
        break;
      case 'r':
        oWorld.Seed();
        break;
      case KEY_UP:
        if(oCurrentFrameDelay > oNullTime && oCurrentFrameDelay > oTimeStep)
          {
          if(bResetFrameDelay)
            {
            oOriginalFrameDelay -= oTimeStep;
            }
          else
            {
            oCurrentFrameDelay -= oTimeStep;
            }
          }
        else
          {
          if(bResetFrameDelay)
            {
            oOriginalFrameDelay = oNullTime;
            }
          else
            {
            oCurrentFrameDelay = oNullTime;
            }
          }
        break;
      case KEY_DOWN:
        if(bResetFrameDelay)
          {
          oOriginalFrameDelay += oTimeStep;
          }
        else
          {
          oCurrentFrameDelay += oTimeStep;
          }
        break;
      default:
        break;
      }

    if(bBreak)
      break;

    oEndTimepoint = std::chrono::steady_clock::now();

    oWaitTime += std::chrono::duration_cast<std::chrono::microseconds>(oEndTimepoint - oStartTimepoint);

    if((oCurrentFrameDelay - oWaitTime) <= oNullTime)
      {
      if(bResetFrameDelay)
        {
        bResetFrameDelay = false;
        oCurrentFrameDelay = oOriginalFrameDelay;
        }
      oWaitTime = oNullTime;
      mvprintw(0, 0, oWorld.StringRepresentation().c_str());
      mvprintw(getmaxy(stdscr) - 1, 0, "generation: %i", oWorld.CurrentGeneration());
      refresh();
      oWorld.Update();
      }
    }

  endwin();
  
  return 0;
  }
