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
    typename std::vector<T>::size_type RingIndex(long long nIndex) { return (nIndex % ((long long) this->Size()) >= 0) ? (nIndex % ((long long) this->Size())) : ((nIndex % ((long long) this->Size())) + ((long long) this->Size())); }
  
  public:
    Ring() { m_vElements = std::vector<T>(); }
    Ring(typename std::vector<T>::size_type nSize) { m_vElements = std::vector<T>(nSize); }
  
  
  public:
    void Resize(typename std::vector<T>::size_type nSize) { m_vElements.resize(nSize); }
    typename std::vector<T>::size_type  Size() const { return m_vElements.size(); }
    void Add(const T& crValue) { m_vElements.push_back(crValue); }
    void Set(typename std::vector<T>::size_type nIndex, const T &crValue) { m_vElements[RingIndex(nIndex)] = crValue;}

  public:
    T const& operator[](long long i) const { return m_vElements[RingIndex(i)]; }
    T&       operator[](long long i)       { return m_vElements[RingIndex(i)]; }
  };

#endif /* defined(__Life____CRing__) */
