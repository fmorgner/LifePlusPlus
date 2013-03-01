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
      typedef long long sizecast_t;

    protected:
      typename std::vector<T>::size_type RingIndex(sizecast_t nIndex) { return (nIndex % (sizecast_t) this->size() >= 0) ? (nIndex % (sizecast_t) this->size()) : ((nIndex % (sizecast_t) this->size()) + (sizecast_t) this->size()); }
    
    public:
      T const& operator[](long long i) const { return this->at(RingIndex(i)); }
      T&       operator[](long long i)       { return this->at(RingIndex(i)); }
    
    public:
      void Add(const typename std::vector<T>::value_type& val)  { this->push_back(val); }
      void Add(const typename std::vector<T>::value_type&& val) { this->push_back(val); }
    
    };

  }
#endif
