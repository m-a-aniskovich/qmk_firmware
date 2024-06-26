/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#if defined(KEYBOARD_keebio_quefrency_rev1)
    // Set 65% column (option 1) and Macro (option 2) on by default
    #define VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT 0x60

#elif defined(KEYBOARD_keebio_quefrency_rev2)
    // Set 65% column (option 3) and Macro (option 4) on by default
    #define VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT 0x00DE
    #define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

#elif defined(KEYBOARD_keebio_quefrency_rev3)
    // Set 65% column (option 3) and Macro (option 4) on by default
    #define VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT 0x00DE
    #define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

#endif
