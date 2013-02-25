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


#include <iostream>
#include "CCell.h"
#include "CWorld.h"
#include "CRing.h"
#include <unistd.h>
#include <term.h>

void ClearScreen()
  {
  if (!cur_term)
    {
    int result;
    setupterm( NULL, STDOUT_FILENO, &result );
    if (result <= 0) return;
    }

  putp( tigetstr( "clear" ) );
  }

#define WORLD_SIZE 25

int main(int argc, const char * argv[])
  {
  World oWorld(WORLD_SIZE);

  for(int i = 0; i < WORLD_SIZE; i++)
    {
    for(int j = 0; j < WORLD_SIZE; j++)
      {
      if(rand()%2)
        {
        oWorld.Animate(j, i);
        }
      }
    }
    
  oWorld.Print();
  
  while(true)
    {
    ClearScreen();
    oWorld.Update();
    oWorld.Print();
    usleep(200000);
    }
  
  return 0;
  }
