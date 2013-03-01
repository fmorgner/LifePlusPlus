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

void World::Initialize()
  {
  for(int nRow = 0; nRow < m_nHeight; nRow++)
    {
    m_oWorld.push_back(fmo::Ring<Cell*>());
    
    for(int nColumn = 0; nColumn < m_nWidth; nColumn++)
      {
      m_oWorld[nRow].push_back(new Cell);
      }
    }

  for(int nRow = 0; nRow < m_oWorld.size(); nRow++)
    {
    for (int nColumn = 0; nColumn < m_oWorld[nRow].size(); nColumn++)
      {
      m_oWorld[nRow][nColumn]->AddNeighbour(m_oWorld[nRow-1][nColumn-1]);
      m_oWorld[nRow][nColumn]->AddNeighbour(m_oWorld[nRow-1][nColumn]);
      m_oWorld[nRow][nColumn]->AddNeighbour(m_oWorld[nRow-1][nColumn+1]);
      m_oWorld[nRow][nColumn]->AddNeighbour(m_oWorld[nRow][nColumn-1]);
      m_oWorld[nRow][nColumn]->AddNeighbour(m_oWorld[nRow][nColumn+1]);
      m_oWorld[nRow][nColumn]->AddNeighbour(m_oWorld[nRow+1][nColumn-1]);
      m_oWorld[nRow][nColumn]->AddNeighbour(m_oWorld[nRow+1][nColumn]);
      m_oWorld[nRow][nColumn]->AddNeighbour(m_oWorld[nRow+1][nColumn+1]);
      }
    }
  }

void World::Update()
  {
  m_oGenerationBuffer.Add(this->StringRepresentation());
  
  for(decltype(m_oWorld.size()) nRow = 0; nRow < m_oWorld.size(); nRow++)
    {
    for(decltype(m_oWorld[nRow].size()) nColumn = 0; nColumn < m_oWorld[nRow].size(); nColumn++)
      {
      m_oWorld[nRow][nColumn]->PrepareForNextGeneration();
      }
    }

  for(decltype(m_oWorld.size()) nRow = 0; nRow < m_oWorld.size(); nRow++)
    {
    for(decltype(m_oWorld[nRow].size()) nColumn = 0; nColumn < m_oWorld[nRow].size(); nColumn++)
      {
      m_oWorld[nRow][nColumn]->Update();
      }
    }
  
  if(std::find(m_oGenerationBuffer.begin(), m_oGenerationBuffer.end(), this->StringRepresentation()) != m_oGenerationBuffer.end())
    {
    m_bIsStuck = true;
    }
  }

std::string World::StringRepresentation(std::string sCellCharacter, bool bIncludingLinebreaks)
  {
  std::string sReturnString;

  for(decltype(m_nHeight) nRow = 0; nRow < m_nHeight; nRow++)
    {
    for(decltype(m_nWidth) nColumn = 0; nColumn < m_nWidth; nColumn++)
      {
      if(m_oWorld[nRow][nColumn]->IsAlive())
        {
        sReturnString += sCellCharacter;
        }
      else
        {
        sReturnString += " ";
        }
      }
      if(bIncludingLinebreaks)
        {
        sReturnString += '\n';
        }
    }
  
  return sReturnString;
  }

void World::Seed(unsigned int nSeed)
  {
  if(m_bIsStuck)
    {
    m_bIsStuck = false;
    }
  
  if(!nSeed)
    {
    srandomdev();
    }
  else
    {
    srandom(nSeed);
    }

  for(decltype(m_nWidth) nX = 0; nX < m_nWidth; nX++)
    {
    for(decltype(m_nHeight) nY = 0; nY < m_nHeight; nY++)
      {
      if(!!(random()%2))
        {
        Animate(nX, nY);
        }
      }
    }
  }
