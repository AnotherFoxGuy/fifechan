/***************************************************************************
 *   Copyright (c) 2017 by the fifechan team                               *
 *   https://github.com/fifengine/fifechan                                 *
 *   This file is part of fifechan.                                        *
 *                                                                         *
 *   fifechan is free software; you can redistribute it and/or             *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA          *
 ***************************************************************************/

/*      _______   __   __   __   ______   __   __   _______   __   __
 *     / _____/\ / /\ / /\ / /\ / ____/\ / /\ / /\ / ___  /\ /  |\/ /\
 *    / /\____\// / // / // / // /\___\// /_// / // /\_/ / // , |/ / /
 *   / / /__   / / // / // / // / /    / ___  / // ___  / // /| ' / /
 *  / /_// /\ / /_// / // / // /_/_   / / // / // /\_/ / // / |  / /
 * /______/ //______/ //_/ //_____/\ /_/ //_/ //_/ //_/ //_/ /|_/ /
 * \______\/ \______\/ \_\/ \_____\/ \_\/ \_\/ \_\/ \_\/ \_\/ \_\/
 *
 * Copyright (c) 2004 - 2008 Olof Naess�n and Per Larsson
 *
 *
 * Per Larsson a.k.a finalman
 * Olof Naess�n a.k.a jansem/yakslem
 *
 * Visit: http://guichan.sourceforge.net
 *
 * License: (BSD)
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Guichan nor the names of its contributors may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FCN_CLIPRECTANGLE_HPP
#define FCN_CLIPRECTANGLE_HPP

#include "fifechan/rectangle.hpp"
#include "fifechan/platform.hpp"

namespace fcn
{
    /**
     * A rectangle used when dealing with clipping. A clip rectangle is
     * a regular rectangle extended with variables for x offsets and y 
     * offsets. The offsets are used for calculations from relative
     * screen coordinates to actual screen coordinates.
     */
    class FCN_CORE_DECLSPEC ClipRectangle : public Rectangle
    {
    public:

        /**
         * Constructor.
         */
        ClipRectangle();

        /**
         * Constructor.
         *
         * @param x The rectangle x coordinate.
         * @param y The rectangle y coordinate.
         * @param width The rectangle width.
         * @param height The rectangle height.
         * @param xOffset The offset of the x coordinate. Used to for
         *                calculating the actual screen coordinate from
         *                the relative screen coordinate.
         * @param yOffset The offset of the y coordinate. Used to for
         *                calculating the actual screen coordinate from
         *                the relative screen coordinate.
         */
        ClipRectangle(int x, 
                      int y, 
                      int width, 
                      int height,
                      int xOffset, 
                      int yOffset);

        /**
         * Copy constructor. Copies x, y, width and height 
         * field from a rectangle to a clip rectangle.
         *
         * @param other The rectangle to copy data from.
         * @returns A clip rectangle with data copyied from a rectangle.
         */
        const ClipRectangle& operator=(const Rectangle& other);

        /**
         * Holds the x offset of the x coordinate.
         */
        int xOffset;

        /**
         * Holds the y offset of the y coordinate.
         */
        int yOffset;
    };
}

#endif // end FCN_CLIPRECTANGLE_HPP
