/*
 *
 * CCell.cpp
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


#include "CCell.h"
#include <stdlib.h>

void Cell::PrepareForNextGeneration()
  {
  short nAliveCells = 0;
  
  for(cpvec::iterator it = m_vpoNeighbours.begin(); it != m_vpoNeighbours.end(); ++it)
    {
    if((*it)->IsAlive())
      {
      nAliveCells++;
      }
    }
    
  if(nAliveCells < 2 && m_bIsAlive)
    {
    m_bWillBeAlive = false;
    }
  else if((nAliveCells == 2 || nAliveCells == 3) && m_bIsAlive)
    {
    m_bWillBeAlive = true;
    }
  else if(nAliveCells == 3 && !m_bIsAlive)
    {
    m_bWillBeAlive = true;
    }
  else
    {
    m_bWillBeAlive = false;
    }
  }
