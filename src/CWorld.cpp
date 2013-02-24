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
  m_vvWorld = pvvec(m_nHeight);
  
  for(pvvec::iterator it = m_vvWorld.begin(); it != m_vvWorld.end(); ++it)
    {
    for(int x = 0; x < m_nWidth; x++)
      {
      (*it).push_back(new Cell);
      }
    }

  for(int i = 0; i < m_vvWorld.size(); i++)
    {
    for(int j = 0; j < m_vvWorld[j].size(); j++)
      {
      if(i == 0)
        {
        if(j == 0)
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+0][j+1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j+0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j+1]);
          }
        else if(j < (m_vvWorld[i].size() - 1))
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+0][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+0][j+1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j+0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j+1]);
          }
        else if(j == (m_vvWorld[i].size() - 1))
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+0][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j-0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j-1]);
          }
        }
      else if(i < (m_vvWorld.size() - 1))
        {
        if(j == 0)
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j+0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j+1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+0][j+1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j+0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j+1]);
          }
        else if(j < (m_vvWorld[i].size() - 1))
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j+0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j+1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+0][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+0][j+1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j+0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j+1]);
          }
        else if(j == (m_vvWorld[i].size() - 1))
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j-0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+0][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j-0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i+1][j-1]);
          }
        }
      else if(i == (m_vvWorld.size() - 1))
        {
        if(j == 0)
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-0][j+1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j+0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j+1]);
          }
        else if(j < (m_vvWorld[i].size() - 1))
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-0][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-0][j+1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j+0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j+1]);
          }
        else if(j == (m_vvWorld[i].size() - 1))
          {
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-0][j-1]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j-0]);
          m_vvWorld[i][j]->AddNeighbour(m_vvWorld[i-1][j-1]);
          }
        }
      }
    }
  }

void World::Update()
  {
  for(int i = 0; i < m_vvWorld.size(); i++)
    {
    for(int j = 0; j < m_vvWorld[i].size(); j++)
      {
      m_vvWorld[i][j]->PrepareForNextGeneration();
      }
    }

  for(int i = 0; i < m_vvWorld.size(); i++)
    {
    for(int j = 0; j < m_vvWorld[i].size(); j++)
      {
      m_vvWorld[i][j]->Update();
      }
    }
  }

void World::Print()
  {
  for(int i = 0; i < m_vvWorld.size(); i++)
    {
    for(int j = 0; j < m_vvWorld[i].size(); j++)
      {
      if(m_vvWorld[i][j]->IsAlive())
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
