//
//  CWorld.h
//  Life++
//
//  Created by Felix Morgner on 23.02.13.
//  Copyright (c) 2013 Felix Morgner. All rights reserved.
//

#ifndef __Life____CWorld__
#define __Life____CWorld__

#include <stdint.h>
#include <vector>
#include "CCell.h"

typedef std::vector<cpvec> pvvec;

class World
  {
  protected:
    uint16_t m_nHeight;
    uint16_t m_nWidth;
    pvvec m_vvWorld;
  
  protected:
    void Initialize();
    
  public:
    World()                                  : m_nWidth(12)    , m_nHeight(12)      { Initialize(); }
    World(uint16_t nSize)                    : m_nWidth(nSize) , m_nHeight(nSize)   { Initialize(); }
    World(uint16_t nWidth, uint16_t nHeight) : m_nWidth(nWidth), m_nHeight(nHeight) { Initialize(); }
  
  public:
    void Animate(uint8_t nX, uint8_t nY) { m_vvWorld[nY][nX]->Animate(); }
    void Update();
    void Print();
  };

#endif /* defined(__Life____CWorld__) */
