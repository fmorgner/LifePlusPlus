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

void World::Initialize()
  {
  for(int i = 0; i < m_nHeight; i++)
    {
    m_rrWorld.Add(cpring());
    
    for(int j = 0; j < m_nWidth; j++)
      {
      m_rrWorld[i].Add(new Cell);
      }
    }

  for(int y = 0; y < m_rrWorld.Size(); y++)
    {
    for (int x = 0; x < m_rrWorld[y].Size(); x++)
      {
      m_rrWorld[y][x]->AddNeighbour(m_rrWorld[y-1][x-1]);
      m_rrWorld[y][x]->AddNeighbour(m_rrWorld[y-1][x]);
      m_rrWorld[y][x]->AddNeighbour(m_rrWorld[y-1][x+1]);
      m_rrWorld[y][x]->AddNeighbour(m_rrWorld[y][x-1]);
      m_rrWorld[y][x]->AddNeighbour(m_rrWorld[y][x+1]);
      m_rrWorld[y][x]->AddNeighbour(m_rrWorld[y+1][x-1]);
      m_rrWorld[y][x]->AddNeighbour(m_rrWorld[y+1][x]);
      m_rrWorld[y][x]->AddNeighbour(m_rrWorld[y+1][x+1]);
      }
    }
  }

void World::Update()
  {
  for(int i = 0; i < m_rrWorld.Size(); i++)
    {
    for(int j = 0; j < m_rrWorld[i].Size(); j++)
      {
      m_rrWorld[i][j]->PrepareForNextGeneration();
      }
    }

  for(int i = 0; i < m_rrWorld.Size(); i++)
    {
    for(int j = 0; j < m_rrWorld[i].Size(); j++)
      {
      m_rrWorld[i][j]->Update();
      }
    }
  }

void World::Print()
  {
  for(int i = 0; i < m_rrWorld.Size(); i++)
    {
    for(int j = 0; j < m_rrWorld[i].Size(); j++)
      {
      if(m_rrWorld[i][j]->IsAlive())
        {
        std::cout << "O";
        }
      else
        {
        std::cout << " ";
        }
      }
    std::cout << std::endl;
    }
  }

void World::Seed(unsigned int nSeed)
  {
  if(!nSeed)
    {
    srandomdev();
    }
  else
    {
    srandom(nSeed);
    }

  for(prring::size_t i = 0; i < m_nWidth; i++)
    {
    for(prring::size_t j = 0; j < m_nHeight; j++)
      {
      if(!!(random()%2))
        {
        Animate(j, i);
        }
      }
    }
  
  }
