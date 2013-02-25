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
    int m_nAdditionIndex;
    std::vector<T> m_vElements;
  
  protected:
    int RingIndex(int nIndex) { return (nIndex % m_nSize >= 0) ? (nIndex % m_nSize) : ((nIndex % m_nSize) + m_nSize); }
  
  public:
    Ring() : m_nSize(0), m_nAdditionIndex(0) {}
    Ring(int nSize) : m_nSize(nSize), m_nAdditionIndex(0) { m_vElements = std::vector<T>(m_nSize); }
  
  
  public:
    void Resize(int nSize) { m_nSize = nSize; m_vElements.resize(m_nSize); }
    T const& operator[](int i) const { return m_vElements[RingIndex(i)]; }
    T&       operator[](int i)  { return m_vElements[RingIndex(i)]; }
    int Size() const { return m_nSize; }
    void Add(const T& crValue) { m_vElements[RingIndex(m_nAdditionIndex++)] = crValue; }
  };

#endif /* defined(__Life____CRing__) */
