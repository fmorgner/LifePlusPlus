//
//  CCell.h
//  Life++
//
//  Created by Felix Morgner on 23.02.13.
//  Copyright (c) 2013 Felix Morgner. All rights reserved.
//

#ifndef __Life____CCell__
#define __Life____CCell__

#include <vector>

class Cell;

typedef std::vector<Cell*> cpvec;

class Cell
  {
  protected:
    bool  m_bIsAlive;
    bool  m_bWillBeAlive;
    cpvec m_vpoNeighbours;

  public:
    Cell() : m_bIsAlive(false) { m_vpoNeighbours = cpvec();}

    void PrepareForNextGeneration();
    void Update() { m_bIsAlive = m_bWillBeAlive; }
    bool IsAlive() { return m_bIsAlive; }
    void AddNeighbour(Cell* poNeighbour) { m_vpoNeighbours.push_back(poNeighbour); }
    void Animate() { m_bIsAlive = true; }
  };


#endif /* defined(__Life____CCell__) */
