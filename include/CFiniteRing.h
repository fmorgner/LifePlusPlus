//
//  CFixedRing.h
//  Life++
//
//  Created by Felix Morgner on 27.02.13.
//  Copyright (c) 2013 Felix Morgner. All rights reserved.
//

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
