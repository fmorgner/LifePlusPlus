//
//  CWorld.cpp
//  Life++
//
//  Created by Felix Morgner on 23.02.13.
//  Copyright (c) 2013 Felix Morgner. All rights reserved.
//

#include "CWorld.h"
#include <iostream>

void World::Initialize()
  {
  m_vvWorld = pvvec(m_nHeight);
  
  for(pvvec::iterator it = m_vvWorld.begin(); it != m_vvWorld.end(); ++it)
    {
    (*it).resize(m_nWidth);
    }

  for(int i = 0; i < m_vvWorld.size(); i++)
    {
    for(int j = 0; j < m_vvWorld[i].size(); j++)
      {
      m_vvWorld[i][j] = new Cell;
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
