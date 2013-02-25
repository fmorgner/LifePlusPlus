/*
 *
 * CRing.h
 * Part of Life++ - Yet another implementation of the Game of Life in C++
 * -------------------------------------------------------------------------
 * begin                 : 2013-02-24
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

#ifndef __Life____CRing__
#define __Life____CRing__

#include <vector>

template <typename T>

class Ring
  {
  protected:
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
