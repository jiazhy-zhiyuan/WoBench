#include <assert.h>
#include <string.h>
#define INCLUDEMAIN
/**********************************************************************************************/
/* The MIT License                                                                            */
/*                                                                                            */
/* Copyright 2016-2016 Twitch Interactive, Inc. or its affiliates. All Rights Reserved.       */
/*                                                                                            */
/* Permission is hereby granted, free of charge, to any person obtaining a copy               */
/* of this software and associated documentation files (the "Software"), to deal              */
/* in the Software without restriction, including without limitation the rights               */
/* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell                  */
/* copies of the Software, and to permit persons to whom the Software is                      */
/* furnished to do so, subject to the following conditions:                                   */
/*                                                                                            */
/* The above copyright notice and this permission notice shall be included in                 */
/* all copies or substantial portions of the Software.                                        */
/*                                                                                            */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR                 */
/* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,                   */
/* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE                */
/* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER                     */
/* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,              */
/* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN                  */
/* THE SOFTWARE.                                                                              */
/**********************************************************************************************/
#include "eia608_charmap.h"
// 0 - 95: Basic North American character set
// 96 - 111: Special North American character
// 112 - 127: Extended Western European character set : Extended Spanish/Miscellaneous
// 128 - 143: Extended Western European character set : Extended French
// 144 - 159: Extended Western European character set : Portuguese
// 160 - 175: Extended Western European character set : German/Danish
const char* eia608_char_map[] = {
    EIA608_CHAR_SPACE, EIA608_CHAR_EXCLAMATION_MARK, EIA608_CHAR_QUOTATION_MARK, EIA608_CHAR_NUMBER_SIGN, EIA608_CHAR_DOLLAR_SIGN, EIA608_CHAR_PERCENT_SIGN, EIA608_CHAR_AMPERSAND, EIA608_CHAR_RIGHT_SINGLE_QUOTATION_MARK,
    EIA608_CHAR_LEFT_PARENTHESIS, EIA608_CHAR_RIGHT_PARENTHESIS, EIA608_CHAR_LATIN_SMALL_LETTER_A_WITH_ACUTE, EIA608_CHAR_PLUS_SIGN, EIA608_CHAR_COMMA, EIA608_CHAR_HYPHEN_MINUS, EIA608_CHAR_FULL_STOP, EIA608_CHAR_SOLIDUS,
    EIA608_CHAR_DIGIT_ZERO, EIA608_CHAR_DIGIT_ONE, EIA608_CHAR_DIGIT_TWO, EIA608_CHAR_DIGIT_THREE, EIA608_CHAR_DIGIT_FOUR, EIA608_CHAR_DIGIT_FIVE, EIA608_CHAR_DIGIT_SIX, EIA608_CHAR_DIGIT_SEVEN, EIA608_CHAR_DIGIT_EIGHT,
    EIA608_CHAR_DIGIT_NINE, EIA608_CHAR_COLON, EIA608_CHAR_SEMICOLON, EIA608_CHAR_LESS_THAN_SIGN, EIA608_CHAR_EQUALS_SIGN, EIA608_CHAR_GREATER_THAN_SIGN, EIA608_CHAR_QUESTION_MARK, EIA608_CHAR_COMMERCIAL_AT,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_A, EIA608_CHAR_LATIN_CAPITAL_LETTER_B, EIA608_CHAR_LATIN_CAPITAL_LETTER_C, EIA608_CHAR_LATIN_CAPITAL_LETTER_D, EIA608_CHAR_LATIN_CAPITAL_LETTER_E, EIA608_CHAR_LATIN_CAPITAL_LETTER_F, EIA608_CHAR_LATIN_CAPITAL_LETTER_G, EIA608_CHAR_LATIN_CAPITAL_LETTER_H,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_I, EIA608_CHAR_LATIN_CAPITAL_LETTER_J, EIA608_CHAR_LATIN_CAPITAL_LETTER_K, EIA608_CHAR_LATIN_CAPITAL_LETTER_L, EIA608_CHAR_LATIN_CAPITAL_LETTER_M, EIA608_CHAR_LATIN_CAPITAL_LETTER_N, EIA608_CHAR_LATIN_CAPITAL_LETTER_O, EIA608_CHAR_LATIN_CAPITAL_LETTER_P,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_Q, EIA608_CHAR_LATIN_CAPITAL_LETTER_R, EIA608_CHAR_LATIN_CAPITAL_LETTER_S, EIA608_CHAR_LATIN_CAPITAL_LETTER_T, EIA608_CHAR_LATIN_CAPITAL_LETTER_U, EIA608_CHAR_LATIN_CAPITAL_LETTER_V, EIA608_CHAR_LATIN_CAPITAL_LETTER_W, EIA608_CHAR_LATIN_CAPITAL_LETTER_X,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_Y, EIA608_CHAR_LATIN_CAPITAL_LETTER_Z, EIA608_CHAR_LEFT_SQUARE_BRACKET, EIA608_CHAR_LATIN_SMALL_LETTER_E_WITH_ACUTE, EIA608_CHAR_RIGHT_SQUARE_BRACKET, EIA608_CHAR_LATIN_SMALL_LETTER_I_WITH_ACUTE, EIA608_CHAR_LATIN_SMALL_LETTER_O_WITH_ACUTE,
    EIA608_CHAR_LATIN_SMALL_LETTER_U_WITH_ACUTE, EIA608_CHAR_LATIN_SMALL_LETTER_A, EIA608_CHAR_LATIN_SMALL_LETTER_B, EIA608_CHAR_LATIN_SMALL_LETTER_C, EIA608_CHAR_LATIN_SMALL_LETTER_D, EIA608_CHAR_LATIN_SMALL_LETTER_E, EIA608_CHAR_LATIN_SMALL_LETTER_F, EIA608_CHAR_LATIN_SMALL_LETTER_G, EIA608_CHAR_LATIN_SMALL_LETTER_H,
    EIA608_CHAR_LATIN_SMALL_LETTER_I, EIA608_CHAR_LATIN_SMALL_LETTER_J, EIA608_CHAR_LATIN_SMALL_LETTER_K, EIA608_CHAR_LATIN_SMALL_LETTER_L, EIA608_CHAR_LATIN_SMALL_LETTER_M, EIA608_CHAR_LATIN_SMALL_LETTER_N, EIA608_CHAR_LATIN_SMALL_LETTER_O, EIA608_CHAR_LATIN_SMALL_LETTER_P,
    EIA608_CHAR_LATIN_SMALL_LETTER_Q, EIA608_CHAR_LATIN_SMALL_LETTER_R, EIA608_CHAR_LATIN_SMALL_LETTER_S, EIA608_CHAR_LATIN_SMALL_LETTER_T, EIA608_CHAR_LATIN_SMALL_LETTER_U, EIA608_CHAR_LATIN_SMALL_LETTER_V, EIA608_CHAR_LATIN_SMALL_LETTER_W, EIA608_CHAR_LATIN_SMALL_LETTER_X,
    EIA608_CHAR_LATIN_SMALL_LETTER_Y, EIA608_CHAR_LATIN_SMALL_LETTER_Z, EIA608_CHAR_LATIN_SMALL_LETTER_C_WITH_CEDILLA, EIA608_CHAR_DIVISION_SIGN, EIA608_CHAR_LATIN_CAPITAL_LETTER_N_WITH_TILDE, EIA608_CHAR_LATIN_SMALL_LETTER_N_WITH_TILDE, EIA608_CHAR_FULL_BLOCK,
    EIA608_CHAR_REGISTERED_SIGN, EIA608_CHAR_DEGREE_SIGN, EIA608_CHAR_VULGAR_FRACTION_ONE_HALF, EIA608_CHAR_INVERTED_QUESTION_MARK, EIA608_CHAR_TRADE_MARK_SIGN, EIA608_CHAR_CENT_SIGN, EIA608_CHAR_POUND_SIGN, EIA608_CHAR_EIGHTH_NOTE,
    EIA608_CHAR_LATIN_SMALL_LETTER_A_WITH_GRAVE, EIA608_CHAR_NO_BREAK_SPACE, EIA608_CHAR_LATIN_SMALL_LETTER_E_WITH_GRAVE, EIA608_CHAR_LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX, EIA608_CHAR_LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX, EIA608_CHAR_LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX, EIA608_CHAR_LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX, EIA608_CHAR_LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_A_WITH_ACUTE, EIA608_CHAR_LATIN_CAPITAL_LETTER_E_WITH_ACUTE, EIA608_CHAR_LATIN_CAPITAL_LETTER_O_WITH_ACUTE, EIA608_CHAR_LATIN_CAPITAL_LETTER_U_WITH_ACUTE, EIA608_CHAR_LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS, EIA608_CHAR_LATIN_SMALL_LETTER_U_WITH_DIAERESIS, EIA608_CHAR_LEFT_SINGLE_QUOTATION_MARK, EIA608_CHAR_INVERTED_EXCLAMATION_MARK,
    EIA608_CHAR_ASTERISK, EIA608_CHAR_APOSTROPHE, EIA608_CHAR_EM_DASH, EIA608_CHAR_COPYRIGHT_SIGN, EIA608_CHAR_SERVICE_MARK, EIA608_CHAR_BULLET, EIA608_CHAR_LEFT_DOUBLE_QUOTATION_MARK, EIA608_CHAR_RIGHT_DOUBLE_QUOTATION_MARK,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_A_WITH_GRAVE, EIA608_CHAR_LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX, EIA608_CHAR_LATIN_CAPITAL_LETTER_C_WITH_CEDILLA, EIA608_CHAR_LATIN_CAPITAL_LETTER_E_WITH_GRAVE, EIA608_CHAR_LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX, EIA608_CHAR_LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS, EIA608_CHAR_LATIN_SMALL_LETTER_E_WITH_DIAERESIS, EIA608_CHAR_LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS, EIA608_CHAR_LATIN_SMALL_LETTER_I_WITH_DIAERESIS, EIA608_CHAR_LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX, EIA608_CHAR_LATIN_CAPITAL_LETTER_U_WITH_GRAVE, EIA608_CHAR_LATIN_SMALL_LETTER_U_WITH_GRAVE, EIA608_CHAR_LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX, EIA608_CHAR_LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK, EIA608_CHAR_RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_A_WITH_TILDE, EIA608_CHAR_LATIN_SMALL_LETTER_A_WITH_TILDE, EIA608_CHAR_LATIN_CAPITAL_LETTER_I_WITH_ACUTE, EIA608_CHAR_LATIN_CAPITAL_LETTER_I_WITH_GRAVE, EIA608_CHAR_LATIN_SMALL_LETTER_I_WITH_GRAVE, EIA608_CHAR_LATIN_CAPITAL_LETTER_O_WITH_GRAVE, EIA608_CHAR_LATIN_SMALL_LETTER_O_WITH_GRAVE, EIA608_CHAR_LATIN_CAPITAL_LETTER_O_WITH_TILDE,
    EIA608_CHAR_LATIN_SMALL_LETTER_O_WITH_TILDE, EIA608_CHAR_LEFT_CURLY_BRACKET, EIA608_CHAR_RIGHT_CURLY_BRACKET, EIA608_CHAR_REVERSE_SOLIDUS, EIA608_CHAR_CIRCUMFLEX_ACCENT, EIA608_CHAR_LOW_LINE, EIA608_CHAR_VERTICAL_LINE, EIA608_CHAR_TILDE,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS, EIA608_CHAR_LATIN_SMALL_LETTER_A_WITH_DIAERESIS, EIA608_CHAR_LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS, EIA608_CHAR_LATIN_SMALL_LETTER_O_WITH_DIAERESIS, EIA608_CHAR_LATIN_SMALL_LETTER_SHARP_S, EIA608_CHAR_YEN_SIGN, EIA608_CHAR_CURRENCY_SIGN, EIA608_CHAR_BROKEN_BAR,
    EIA608_CHAR_LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE, EIA608_CHAR_LATIN_SMALL_LETTER_A_WITH_RING_ABOVE, EIA608_CHAR_LATIN_CAPITAL_LETTER_O_WITH_STROKE, EIA608_CHAR_LATIN_SMALL_LETTER_O_WITH_STROKE, EIA608_CHAR_BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT, EIA608_CHAR_BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT, EIA608_CHAR_BOX_DRAWINGS_LIGHT_UP_AND_RIGHT, EIA608_CHAR_BOX_DRAWINGS_LIGHT_UP_AND_LEFT,
};
