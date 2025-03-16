/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemont <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:55:40 by pdemont           #+#    #+#             */
/*   Updated: 2024/12/20 17:44:26 by pdemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* @file keycodes.h
* @brief Defines keycode constants for keyboard input handling.
*/
#ifndef KEYCODES_H
# define KEYCODES_H

/*
 *  Summary:
 *    Virtual keycodes
 *  
 *  Discussion:
 *    These constants are the virtual keycodes defined originally in
 *    Inside Mac Volume V, pg. V-191. They identify physical keys on a
 *    keyboard. Those constants with "ANSI" in the name are labeled
 *    according to the key position on an ANSI-standard US keyboard.
 */
# ifdef __APPLE__
/* Key ANSI */
#  define KEY_A 0x00
#  define KEY_S 0x01
#  define KEY_D 0x02
#  define KEY_F 0x03
#  define KEY_H 0x04
#  define KEY_G 0x05
#  define KEY_Z 0x06
#  define KEY_X 0x07
#  define KEY_C 0x08
#  define KEY_V 0x09
#  define KEY_B 0x0B
#  define KEY_Q 0x0C
#  define KEY_W 0x0D
#  define KEY_E 0x0E
#  define KEY_R 0x0F
#  define KEY_Y 0x10
#  define KEY_T 0x11
#  define KEY_1 0x12
#  define KEY_2 0x13
#  define KEY_3 0x14
#  define KEY_4 0x15
#  define KEY_6 0x16
#  define KEY_5 0x17
#  define KEY_EQUAL 0x18
#  define KEY_9 0x19
#  define KEY_7 0x1A
#  define KEY_MINUS 0x1B
#  define KEY_8 0x1C
#  define KEY_0 0x1D
#  define KEY_RIGHTBRACKET 0x1E
#  define KEY_O 0x1F
#  define KEY_U 0x20
#  define KEY_LEFTBRACKET 0x21
#  define KEY_I 0x22
#  define KEY_P 0x23
#  define KEY_L 0x25
#  define KEY_J 0x26
#  define KEY_QUOTE 0x27
#  define KEY_K 0x28
#  define KEY_SEMICOLON 0x29
#  define KEY_BACKSLASH 0x2A
#  define KEY_COMMA 0x2B
#  define KEY_SLASH 0x2C
#  define KEY_N 0x2D
#  define KEY_M 0x2E
#  define KEY_PERIOD 0x2F
#  define KEY_GRAVE 0x32
#  define KEY_KEYPADDECIMAL 0x41
#  define KEY_KEYPADMULTIPLY 0x43
#  define KEY_KEYPADPLUS 0x45
#  define KEY_KEYPADCLEAR 0x47
#  define KEY_KEYPADDIVIDE 0x4B
#  define KEY_KEYPADENTER 0x4C
#  define KEY_KEYPADMINUS 0x4E
#  define KEY_KEYPADEQUALS 0x51
#  define KEY_KEYPAD0 0x52
#  define KEY_KEYPAD1 0x53
#  define KEY_KEYPAD2 0x54
#  define KEY_KEYPAD3 0x55
#  define KEY_KEYPAD4 0x56
#  define KEY_KEYPAD5 0x57
#  define KEY_KEYPAD6 0x58
#  define KEY_KEYPAD7 0x59
#  define KEY_KEYPAD8 0x5B
#  define KEY_KEYPAD9 0x5C
/* keycodes for keys that are independent of keyboard layout */
#  define KEY_RETURN 0x24
#  define KEY_TAB 0x30
#  define KEY_SPACE 0x31
#  define KEY_DELETE 0x33
#  define KEY_ESCAPE 0x35
#  define KEY_COMMAND 0x37
#  define KEY_SHIFT 0x38
#  define KEY_CAPSLOCK 0x39
#  define KEY_OPTION 0x3A
#  define KEY_CONTROL 0x3B
#  define KEY_RIGHTCOMMAND 0x36
#  define KEY_RIGHTSHIFT 0x3C
#  define KEY_RIGHTOPTION 0x3D
#  define KEY_RIGHTCONTROL 0x3E
#  define KEY_FUNCTION 0x3F
#  define KEY_F17 0x40
#  define KEY_VOLUMEUP 0x48
#  define KEY_VOLUMEDOWN 0x49
#  define KEY_MUTE 0x4A
#  define KEY_F18 0x4F
#  define KEY_F19 0x50
#  define KEY_F20 0x5A
#  define KEY_F5 0x60
#  define KEY_F6 0x61
#  define KEY_F7 0x62
#  define KEY_F3 0x63
#  define KEY_F8 0x64
#  define KEY_F9 0x65
#  define KEY_F11 0x67
#  define KEY_F13 0x69
#  define KEY_F16 0x6A
#  define KEY_F14 0x6B
#  define KEY_F10 0x6D
#  define KEY_CONTEXTUALMENU 0x6E
#  define KEY_F12 0x6F
#  define KEY_F15 0x71
#  define KEY_HELP 0x72
#  define KEY_HOME 0x73
#  define KEY_PAGEUP 0x74
#  define KEY_FORWARDDELETE 0x75
#  define KEY_F4 0x76
#  define KEY_END 0x77
#  define KEY_F2 0x78
#  define KEY_PAGEDOWN 0x79
#  define KEY_F1 0x7A
#  define KEY_LEFTARROW 0x7B
#  define KEY_RIGHTARROW 0x7C
#  define KEY_DOWNARROW 0x7D
#  define KEY_UPARROW 0x7E
# elif defined(__linux__)
#  define KEY_A 0x61
#  define KEY_S 0x73
#  define KEY_D 0x64
#  define KEY_F 0x66
#  define KEY_H 0x68
#  define KEY_G 0x67
#  define KEY_Z 0x7A
#  define KEY_X 0x78
#  define KEY_C 0x63
#  define KEY_V 0x76
#  define KEY_B 0x62
#  define KEY_Q 0x71
#  define KEY_W 0x77
#  define KEY_E 0x65
#  define KEY_R 0x72
#  define KEY_Y 0x79
#  define KEY_T 0x74
#  define KEY_1 0x31
#  define KEY_2 0x32
#  define KEY_3 0x33
#  define KEY_4 0x34
#  define KEY_6 0x36
#  define KEY_5 0x35
#  define KEY_EQUAL 0x3D
#  define KEY_9 0x39
#  define KEY_7 0x37
#  define KEY_MINUS 0x2D
#  define KEY_8 0x38
#  define KEY_0 0x30
#  define KEY_RIGHTBRACKET 0x5D
#  define KEY_O 0x6F
#  define KEY_U 0x75
#  define KEY_LEFTBRACKET 0x5B
#  define KEY_I 0x69
#  define KEY_P 0x70
#  define KEY_L 0x6C
#  define KEY_J 0x6A
#  define KEY_QUOTE 0x27
#  define KEY_K 0x6B
#  define KEY_SEMICOLON 0x3B
#  define KEY_BACKSLASH 0x5C
#  define KEY_COMMA 0x2C
#  define KEY_SLASH 0x2F
#  define KEY_N 0x6E
#  define KEY_M 0x6D
#  define KEY_PERIOD 0x2E
#  define KEY_GRAVE 0x60
#  define KEY_KEYPADDECIMAL 0x2E
#  define KEY_KEYPADMULTIPLY 0x2A
#  define KEY_KEYPADPLUS 0x2B
#  define KEY_KEYPADCLEAR 0xFF0B
#  define KEY_KEYPADDIVIDE 0x2F
#  define KEY_KEYPADENTER 0xFF0D
#  define KEY_KEYPADMINUS 0x2D
#  define KEY_KEYPADEQUALS 0x3D
#  define KEY_KEYPAD0 0x30
#  define KEY_KEYPAD1 0x31
#  define KEY_KEYPAD2 0x32
#  define KEY_KEYPAD3 0x33
#  define KEY_KEYPAD4 0x34
#  define KEY_KEYPAD5 0x35
#  define KEY_KEYPAD6 0x36
#  define KEY_KEYPAD7 0x37
#  define KEY_KEYPAD8 0x38
#  define KEY_KEYPAD9 0x39
/* keycodes for keys that are independent of keyboard layout */
#  define KEY_RETURN 0xFF0D
#  define KEY_TAB 0xFF09
#  define KEY_SPACE 0x20
#  define KEY_DELETE 0xFFFF
#  define KEY_ESCAPE 0xFF1B
#  define KEY_COMMAND 0xFFE9
#  define KEY_SHIFT 0xFFE1
#  define KEY_CAPSLOCK 0xFFE5
#  define KEY_OPTION 0xFFE7
#  define KEY_CONTROL 0xFFE3
#  define KEY_RIGHTCOMMAND 0xFFEA
#  define KEY_RIGHTSHIFT 0xFFE2
#  define KEY_RIGHTOPTION 0xFFE8
#  define KEY_RIGHTCONTROL 0xFFE4
#  define KEY_F17 0xFFCE
#  define KEY_F18 0xFFCE
#  define KEY_F19 0xFFD0
#  define KEY_F20 0xFFD1
#  define KEY_F5 0xFFC2
#  define KEY_F6 0xFFC3
#  define KEY_F7 0xFFC4
#  define KEY_F3 0xFFC0
#  define KEY_F8 0xFFC5
#  define KEY_F9 0xFFC6
#  define KEY_F11 0xFFC8
#  define KEY_F13 0xFFCA
#  define KEY_F16 0xFFCD
#  define KEY_F14 0xFFCB
#  define KEY_F10 0xFFC7
#  define KEY_F12 0xFFC9
#  define KEY_F15 0xFFCC
#  define KEY_HOME 0xFF95
#  define KEY_PAGEUP 0xFF9A
#  define KEY_FORWARDDELETE 0xFF9F
#  define KEY_F4 0xFFC1
#  define KEY_END 0xFF9C
#  define KEY_F2 0xFFBF
#  define KEY_PAGEDOWN 0xFF9B
#  define KEY_F1 0xFFBE
#  define KEY_LEFTARROW 0xFF96
#  define KEY_RIGHTARROW 0xFF98
#  define KEY_DOWNARROW 0xFF99
#  define KEY_UPARROW 0xFF97
# endif
#endif // !KEYCODES_H
