/*
 *
 * CWorld.h
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


#ifndef __Life____CWorld__
#define __Life____CWorld__

#include <cstddef>
#include <cstdlib>
#include <string>
#include "CRing.h"
#include "CCell.h"

typedef Ring<cpring> prring;
typedef prring::size_t location_t;

class World
  {  
  protected:
    prring::size_t m_nHeight;
    prring::size_t m_nWidth;
    prring m_rrWorld;
  
  protected:
    void Initialize();
    
  public:
    World() : m_nWidth(12), m_nHeight(12)      { Initialize(); }
    World(size_t nSize) : m_nWidth(nSize), m_nHeight(nSize)  { Initialize(); }
    World(size_t nWidth, size_t nHeight) : m_nWidth(nWidth), m_nHeight(nHeight) { Initialize(); }
  
  public:
    void Animate(location_t nX, location_t nY) { m_rrWorld[nY][nX]->Animate(); }
    void Update();
    void Print();
    void Seed(unsigned int nSeed = 0);
    std::string StringRepresentation(std::string sCellCharacter = "o", bool bIncludingLinebreaks = false);
  };

#endif /* defined(__Life____CWorld__) */
