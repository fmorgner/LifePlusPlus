/*
 *
 * FiniteRing.h
 * Part of Life++ - Yet another implementation of the Game of Life in C++
 * -------------------------------------------------------------------------
 * begin                 : 2013-02-27
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

#ifndef Life___CFiniteRing_h
#define Life___CFiniteRing_h

#include <list>

template <typename T> class FiniteRing : public std::list<T>
  {
  protected:
    void resize(typename FiniteRing<T>::size_type n);
    void resize(typename FiniteRing<T>::size_type n, typename FiniteRing<T>::value_type val);
    
    FiniteRing();

  protected:
    typename FiniteRing<T>::size_type m_nSizeLimit;

  public:
    FiniteRing(typename FiniteRing<T>::size_type nSizeLimit) : m_nSizeLimit(nSizeLimit) {}
    void Add(const typename FiniteRing<T>::value_type& val) { if(this->size() == m_nSizeLimit) { this->pop_back(); } this->push_front(val); }
    void Add(const typename FiniteRing<T>::value_type&& val) { if(this->size() == m_nSizeLimit) { this->pop_back(); } this->push_front(val); }

  };

#endif
