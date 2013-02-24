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

struct point_s
  {
  int nX;
  int nY;
  };

class Widget
  {
  protected:
    int     m_nWidth;
    int     m_nHeight;
    point_s m_stOrigin;
    
    bool    m_bIsVisible;
    
    WINDOW* m_pstWindow;

  protected:
    void Initialize();
  
  public:
    Widget()                                                    : m_nWidth(0), m_nHeight(0)                                  { point_s stOrigin; stOrigin.nX = 0; stOrigin.nY = 0; m_stOrigin = stOrigin; Initialize(); }
    Widget(int nWidth, int nHeight)                             : m_nWidth(nWidth), m_nHeight(nHeight)                       { point_s stOrigin; stOrigin.nX = 0; stOrigin.nY = 0; m_stOrigin = stOrigin; Initialize(); }
    Widget(point_s stOrigin, int nWidth, int nHeight)           : m_nWidth(nWidth), m_nHeight(nHeight), m_stOrigin(stOrigin) { Initialize(); }
    Widget(int nOriginX, int nOriginY, int nWidth, int nHeight) : m_nWidth(nWidth), m_nHeight(nHeight)                       { point_s stOrigin; stOrigin.nX = nOriginX; stOrigin.nY = nOriginY; m_stOrigin = stOrigin; Initialize(); }
  
  public:
    void Draw();
  };

#endif /* defined(__Life____CWidget__) */
