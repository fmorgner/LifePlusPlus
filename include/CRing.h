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

namespace fmo
  {

  template <typename T> class Ring : public std::vector<T>
    {
    public:
      using size_type  = typename std::vector<T>::size_type;
      using value_type = typename std::vector<T>::value_type;
      using allocator_type = typename std::vector<T>::allocator_type;
      using ssize_t = long long;
  
    protected:
      using std::vector<T>::front;
      using std::vector<T>::back;
      using std::vector<T>::size;
      using std::vector<T>::max_size;
      using std::vector<T>::clear;
      using std::vector<T>::empty;
    
      const size_type RingIndex(ssize_t nIndex) const { return (nIndex % (ssize_t) this->size() >= 0) ? (nIndex % (ssize_t) this->size()) : ((nIndex % (ssize_t) this->size()) + (ssize_t) this->size()); }
    
    public:
      T const& operator[](ssize_t i) const { return this->at(RingIndex(i)); }
      T&       operator[](ssize_t i)       { return this->at(RingIndex(i)); }

      void Add(const value_type& val)  { this->push_back(val); }
      void Add(const value_type&& val) { this->push_back(val); }
      
      size_type Size() const { return size(); }
      size_type MaxSize() const { return max_size(); }
      
      void Clear() { clear(); }
      
      bool IsEmpty() const { return empty(); }
      
      Ring() : std::vector<T>() {}
      Ring(size_type nSize, const T& rValue = T(), const allocator_type& rAllocator = allocator_type()) : std::vector<T>(nSize, rValue, rAllocator) {}
    };

  }
#endif
