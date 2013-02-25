//
//  CRing.cpp
//  Life++
//
//  Created by Felix Morgner on 24.02.13.
//  Copyright (c) 2013 Felix Morgner. All rights reserved.
//

#include "CRing.h"

template <typename T>

Ring<T>::Ring(int nSize) : m_nSize(nSize)
  {
  m_vElements = std::vector<T>(m_nSize);
  }

template <typename T>

void Ring<T>::Resize(int nSize)
  {
  m_nSize = nSize;
  m_vElements.resize(m_nSize);
  }

template <typename T>

T const& Ring<T>::operator[](int i) const
  {
  return m_vElements[RingIndex(i)];
  }

template <typename T>

T& Ring<T>::operator[](int i)
  {
  return m_vElements[RingIndex(i)];
  }

template <typename T>

int Ring<T>::RingIndex(int nIndex)
  {
  if(nIndex % m_nSize >= 0)
    {
    return nIndex % m_nSize;
    }
  else
    {
    return (nIndex % m_nSize) + m_nSize;
    }
  }