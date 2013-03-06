/*
 *
 * CWorld.cpp
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

#include "CWorld.h"
#include <iostream>
#include <algorithm>

#ifdef __gnu_linux__
#include <stdlib.h>
#include <time.h>
#endif

void World::Initialize()
  {
  m_oWorld = fmo::Ring< fmo::Ring<Cell> >(m_nHeight, fmo::Ring<Cell>(m_nWidth));

  for(int nRow = 0; nRow < m_oWorld.size(); nRow++)
    {
    for (int nColumn = 0; nColumn < m_oWorld[nRow].size(); nColumn++)
      {
      m_oWorld[nRow][nColumn].AddNeighbour(&m_oWorld[nRow-1][nColumn-1]);
      m_oWorld[nRow][nColumn].AddNeighbour(&m_oWorld[nRow-1][nColumn+0]);
      m_oWorld[nRow][nColumn].AddNeighbour(&m_oWorld[nRow-1][nColumn+1]);
      m_oWorld[nRow][nColumn].AddNeighbour(&m_oWorld[nRow+0][nColumn-1]);
      m_oWorld[nRow][nColumn].AddNeighbour(&m_oWorld[nRow+0][nColumn+1]);
      m_oWorld[nRow][nColumn].AddNeighbour(&m_oWorld[nRow+1][nColumn-1]);
      m_oWorld[nRow][nColumn].AddNeighbour(&m_oWorld[nRow+1][nColumn+0]);
      m_oWorld[nRow][nColumn].AddNeighbour(&m_oWorld[nRow+1][nColumn+1]);
      }
    }
  }

void World::Update()
  {
  m_oGenerationBuffer.Add(this->StringRepresentation());
  
  for(auto& oRow : m_oWorld)
    {
    for(auto& oCell : oRow)
      {
      oCell.PrepareForNextGeneration();
      }
    }

  for(auto& oRow : m_oWorld)
    {
    for(auto& oCell : oRow)
      {
      oCell.Update();
      }
    }
  
  if(std::find(m_oGenerationBuffer.begin(), m_oGenerationBuffer.end(), this->StringRepresentation()) != m_oGenerationBuffer.end())
    {
    m_bIsStuck = true;
    }
  }

std::string World::StringRepresentation(std::string sCellCharacter, bool bIncludingLinebreaks)
  {
  std::string oStringRepresentation;

  for(auto& oRow : m_oWorld)
    {
    for(auto& oCell : oRow)
      {
      oStringRepresentation += (oCell.IsAlive()) ? sCellCharacter : " ";
      }
      if(bIncludingLinebreaks)
        {
        oStringRepresentation += '\n';
        }
    }
  
  return oStringRepresentation;
  }

void World::Seed(unsigned int nSeed)
  {
  if(m_bIsStuck)
    {
    m_bIsStuck = false;
    }

  if(!nSeed)
    {
    #if defined(__APPLE__) && defined(__MACH__)
    srandomdev();
    #else
    srand(time(NULL));
    #endif
    }
  else
    {
    srandom(nSeed);
    }

  for(auto& oRow : m_oWorld)
    {
    for(auto& oCell : oRow)
      {
      if(!!(random()%2))
        {
        oCell.Animate();
        }
      }
    }
  }
