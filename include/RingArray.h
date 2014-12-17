/*
 *
 * CRing.h
 * Part of Life++ - Yet another implementation of the Game of Life in C++
 * -------------------------------------------------------------------------
 * begin                 : 2013-02-24
 * copyright             : Copyright (C) 2013,2014 by Felix Morgner
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

#ifndef _Life_RingArray
#define _Life_RingArray

#include <array>
#include <initializer_list>
#include <type_traits>

namespace fmo
  {

  template <typename ValueType, std::size_t ArraySize> struct RingArray
    {
    private:
      using container = std::array<ValueType, ArraySize>;
      container m_oData;

    public:

#pragma mark - member types -

      using size_type = typename container::size_type;
      using value_type = typename container::value_type;
      using difference_type = typename container::difference_type;
      using reference = typename container::reference;
      using pointer = typename container::pointer;
      using const_reference = typename container::const_reference;
      using const_pointer = typename container::const_pointer;
      using iterator = typename container::iterator;
      using const_iterator = typename container::const_iterator;
      using reverse_iterator = typename container::reverse_iterator;
      using const_reverse_iterator = typename container::const_reverse_iterator;

      using index_type = typename std::make_signed<size_type>::type;

#pragma mark - ctors -

      Ring(std::initializer_list<ValueType> oInitList) : m_oData{oInitList} {}

#pragma mark - element access -

      reference operator[](index_type nIndex) { return m_oData[effectiveIndex(nIndex)]; }
      const_reference operator[](index_type nIndex) const { return m_oData[effectiveIndex(nIndex)]; }

      reference at(index_type nIndex) { return m_oData.at(effectiveIndex(nIndex)); }
      const_reference at(index_type nIndex) const { return m_oData.at(effectiveIndex(nIndex)); }

      reference front() { return m_oData.front(); }
      const_reference front() const { return m_oData.front(); }

      reference back() { return m_oData.back(); }
      const_reference back() const { return m_oData.back(); }

#pragma mark - iterators -

      iterator begin() { return m_oData.begin(); }
      const_iterator begin() const { return m_oData.begin(); }
      const_iterator cbegin() const { return m_oData.cbegin(); }

      iterator end() { return m_oData.end(); }
      const_iterator end() const { return m_oData.end(); }
      const_iterator cend() const { return m_oData.cend(); }

      iterator rbegin() { return m_oData.rbegin(); }
      const_iterator rbegin() const { return m_oData.rbegin(); }
      const_iterator crbegin() const { return m_oData.crbegin(); }

      iterator rend() { return m_oData.rend(); }
      const_iterator rend() const { return m_oData.rend(); }
      const_iterator crend() const { return m_oData.crend(); }

#pragma mark - capacity -

      constexpr bool empty() { return m_oData.empty(); }
      constexpr size_type size() { return m_oData.size(); }

#pragma mark - operations -

      void fill(const_reference oValue) { m_oData.fill(oValue); }

#pragma mark - internals -

    private:
      size_type effectiveIndex(index_type nIndex) const
        {
        size_type arraySize = size();
        size_type realIndex;

        if(nIndex >= 0)
          {
          realIndex = nIndex % arraySize;
          }
        else
          {
          realIndex = arraySize + (nIndex % arraySize);
          }

        return realIndex;
        }

    };

  }
#endif
