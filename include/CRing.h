//
//  CRing.h
//  Life++
//
//  Created by Felix Morgner on 24.02.13.
//  Copyright (c) 2013 Felix Morgner. All rights reserved.
//

#ifndef __Life____CRing__
#define __Life____CRing__

#include <vector>

template <typename T>

class Ring
  {
  protected:
    int m_nSize;
    std::vector<T> m_vElements;
  
  protected:
    int RingIndex(int nIndex);
  
  public:
    Ring(int nSize = 10);
  
  public:
    void Resize(int nSize);
    T const& operator[](int i) const;
    T&       operator[](int i);
  };

#endif /* defined(__Life____CRing__) */
