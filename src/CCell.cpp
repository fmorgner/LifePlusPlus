//
//  CCell.cpp
//  Life++
//
//  Created by Felix Morgner on 23.02.13.
//  Copyright (c) 2013 Felix Morgner. All rights reserved.
//

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
