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
#include <iostream>
#include <ncurses.h>
#include "CWorld.h"

int main(int argc, const char * argv[])
  {
  initscr();
  cbreak();

  World oWorld(getmaxx(stdscr), getmaxy(stdscr));
  oWorld.Seed();

  while(true)
    {
    move(0,0);
    printw(oWorld.StringRepresentation().c_str());
    refresh();
    oWorld.Update();
    if(oWorld.IsStuck())
      {
      usleep(10000000);
      oWorld.Seed();
      }
    usleep(33333);
    }
    
  endwin();
  
  return 0;
  }
