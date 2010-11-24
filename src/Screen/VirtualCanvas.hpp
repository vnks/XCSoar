/*
Copyright_License {

  XCSoar Glide Computer - http://www.xcsoar.org/
  Copyright (C) 2000-2010 The XCSoar Project
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#ifndef XCSOAR_SCREEN_VIRTUAL_CANVAS_HPP
#define XCSOAR_SCREEN_VIRTUAL_CANVAS_HPP

#include "Screen/Canvas.hpp"

/**
 * A #Canvas implementation which draws to an off-screen surface.
 * This is an abstract class; see #BufferCanvas for
 * a concrete implementation.
 */
class VirtualCanvas : public Canvas {
public:
  VirtualCanvas() {}
  VirtualCanvas(unsigned _width, unsigned _height);
  VirtualCanvas(const Canvas &canvas, unsigned _width, unsigned _height);

#ifndef ENABLE_OPENGL
  ~VirtualCanvas();
#endif

  void set(unsigned _width, unsigned _height);

  void set(const Canvas &canvas, unsigned _width, unsigned _height);
  void set(const Canvas &canvas);

#ifndef ENABLE_SDL
  void reset();
#endif

#ifdef ENABLE_SDL
  void resize(unsigned _width, unsigned _height) {
    if (_width != get_width() || _height != get_height())
      set(*this, _width, _height);
  }

  void grow(unsigned _width, unsigned _height);
#endif
};

#endif
