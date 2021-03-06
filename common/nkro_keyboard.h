/*
 * Copyright 2013 David Robert Nelson.
 *
 * This file is part of Clavis.
 * 
 * Clavis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Clavis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Clavis.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NKRO_KEYBOARD_H
#define NKRO_KEYBOARD_H

#include "interface.h"

/**
 * The interface data structure provided by this implementation.
 */
extern interface_t nkro_keyboard;

/**
 * Clear the current state of the nkro keyboard.
 *
 * Typical usage would be to clear the current key state, set any keys that are 
 * currently active (with zero or more calls to nkro_keyboard_set_key, below) 
 * and then to send the current key state to the host (with nkro_keyboard_send, 
 * below).
 */
void nkro_keyboard_clear (void);

/**
 * Convenience method to send a single keystroke plus modifiers.
 *
 * Any existing state is cleared, the single key is sent along with the 
 * modifiers, the state is cleared again, and again the (now empty) state is 
 * sent.  This simulates depressing and immediately releasing the key.
 */
int8_t nkro_keyboard_press(uint8_t key, uint8_t modifier);

/**
 * Set a key as being active/pressed.
 *
 * This method can be called multiple times, before sending the key state to 
 * the host.
 *
 * Any number of valid keyboard keycodes can be set.
 */
void nkro_keyboard_set_key (uint8_t key);

/**
 * Send the current state of the keyboard to the host.
 */
int8_t nkro_keyboard_send(void);

/**
 * Get the current LED selected state, as received from the host.
 *
 * This is sent as a bit array.
 */
uint8_t nkro_keyboard_get_leds (void);

#endif

