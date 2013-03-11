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
#include <stdint.h>
#include <string>
#include "CRing.h"
#include "CFiniteRing.h"
#include "CCell.h"

class World
  {  
  protected:
    fmo::Ring<fmo::Ring<Cell>>::size_type  m_nWidth  = 12;
    decltype(m_nWidth)                     m_nHeight = 12;
    
    fmo::Ring<fmo::Ring<Cell>>             m_oWorld;
    fmo::FiniteRing<std::string>           m_oGenerationBuffer = fmo::FiniteRing<std::string>(3);
    
    bool     m_bIsStuck    = false;
    uint64_t m_nGeneration = 0;
  
  protected:
    void Initialize();
    
  public:
    World() { Initialize(); }
    World(decltype(m_nWidth) nSize) : m_nWidth(nSize), m_nHeight(nSize) { Initialize(); }
    World(decltype(m_nWidth) nWidth, decltype(m_nHeight) nHeight) : m_nWidth(nWidth), m_nHeight(nHeight) { Initialize(); }
  
  public:
    void Animate(decltype(m_nWidth) nX, decltype(m_nHeight) nY) { m_oWorld[nY][nX].Animate(); }
    void Seed(unsigned int nSeed = 0);
    void Update();
    
    std::string StringRepresentation(std::string sCellCharacter = "o", bool bIncludingLinebreaks = false);
    bool IsStuck() { return m_bIsStuck; }
    uint64_t CurrentGeneration() { return m_nGeneration; }
  };

#endif
