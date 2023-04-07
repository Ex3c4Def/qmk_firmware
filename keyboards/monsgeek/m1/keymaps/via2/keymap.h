/* Copyright 2023 @Trex4Git
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#ifdef USE_SECOND_COLOR
 #include "rgb_matrix.h"
	typedef union {
		uint32_t raw;
		struct PACKED {
			HSV         hsv; //24bit (3x8bit) of the 32bit
		};
	} via2_config_t;
	
	extern via2_config_t rgb_color2_config;
#endif  

