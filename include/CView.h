/*
 *
 * CWidget.h
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

#ifndef __Life____CWidget__
#define __Life____CWidget__

#include <ncurses.h>
#include <cstddef>
#include <vector>
#include <algorithm>

typedef struct point_st
  {
  int nX;
  int nY;
  } point_t;

class View
  {
  protected:
    int     m_nWidth;
    int     m_nHeight;
    point_t m_stOrigin;
    
    bool    m_bIsVisible;
    
    WINDOW* m_pstWindow;
    std::vector<View*> m_vpstSubviews;

  protected:
    void Initialize() { m_pstWindow = newwin(m_nHeight, m_nWidth, m_stOrigin.nY, m_stOrigin.nX); box(m_pstWindow, 0 , 0); }
  
  public:
    View()                                                    : m_nWidth(0), m_nHeight(0)                                  { point_t stOrigin; stOrigin.nX = 0; stOrigin.nY = 0; m_stOrigin = stOrigin; Initialize(); }
    View(int nWidth, int nHeight)                             : m_nWidth(nWidth), m_nHeight(nHeight)                       { point_t stOrigin; stOrigin.nX = 0; stOrigin.nY = 0; m_stOrigin = stOrigin; Initialize(); }
    View(point_t stOrigin, int nWidth, int nHeight)           : m_nWidth(nWidth), m_nHeight(nHeight), m_stOrigin(stOrigin) { Initialize(); }
    View(int nOriginX, int nOriginY, int nWidth, int nHeight) : m_nWidth(nWidth), m_nHeight(nHeight)                       { point_t stOrigin; stOrigin.nX = nOriginX; stOrigin.nY = nOriginY; m_stOrigin = stOrigin; Initialize(); }
    ~View() { wborder(m_pstWindow, ' ', ' ', ' ',' ',' ',' ',' ',' '); wrefresh(m_pstWindow); delwin(m_pstWindow); m_pstWindow = nullptr; }
  
  public:
    void Draw();
    void Show();
    void AddSubview(View* const poView) { m_vpstSubviews.push_back(poView); }

  public:
    point_t Origin() { return m_stOrigin; }
    bool HasSubview(View* const poView) { return std::find(m_vpstSubviews.begin(), m_vpstSubviews.end(), poView) != m_vpstSubviews.end(); }
  };

#endif /* defined(__Life____CWidget__) */
