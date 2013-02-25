/*
 *
 * CCell.h
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


#ifndef __Life____CCell__
#define __Life____CCell__

#include "CRing.h"

class Cell;

typedef Ring<Cell*> cpring;

class Cell
  {
  protected:
    bool  m_bIsAlive;
    bool  m_bWillBeAlive;
    cpring m_rpoNeighbours;

  public:
    Cell() : m_bIsAlive(false), m_rpoNeighbours(8) {}

    void PrepareForNextGeneration();
    void Update() { m_bIsAlive = m_bWillBeAlive; }
    bool IsAlive() { return m_bIsAlive; }
    void AddNeighbour(Cell* poNeighbour) { m_rpoNeighbours.Add(poNeighbour); }
    void Animate() { m_bIsAlive = true; }
  };


#endif /* defined(__Life____CCell__) */
