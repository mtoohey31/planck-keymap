/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
/* #include "muse.h" */

enum planck_layers { _QWERTY, _NAV, _NUM, _FPS, _LEAGUE, _PLOVER, _SETTINGS };

enum custom_keycodes { TG_PLV };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_LPRN, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RPRN,
    LT(_SETTINGS,KC_BSLS), KC_A, KC_S, KC_D, KC_F, KC_G,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    _______, _______, _______, LALT_T(KC_ESC), LGUI_T(KC_BSPC), LCTL_T(KC_DEL), LT(_NAV, KC_ENT), KC_SPC, LT(_NUM, KC_TAB), _______, _______, _______
),

[_NAV] = LAYOUT_planck_grid(
    _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, _______, _______, _______, _______,
    _______, _______, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT_planck_grid(
    KC_LBRC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TILD, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, KC_RBRC,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_GRV,  KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_APP,
    _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HASH, KC_PERC, KC_1,    KC_2,    KC_3,    KC_EQL,  _______,
    _______, _______, _______, _______, _______, _______, DF(_NUM), KC_0,   DF(_QWERTY), _______, _______, _______
),

[_FPS] = LAYOUT_planck_grid(
    KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    _______, _______, _______, _______, _______, TG(_FPS),
    KC_1,    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______, _______, _______, _______, _______,
    KC_2,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LALT, KC_SPC,  KC_LCTL, _______, _______, _______, _______, _______, _______
),

[_LEAGUE] = LAYOUT_planck_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, TG(_LEAGUE),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, _______, _______, _______,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LCTL, KC_SPC,  KC_B,    _______, _______, _______, _______, _______, _______
),

[_PLOVER] = LAYOUT_planck_grid(
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    TG_PLV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,
    _______, _______, _______, _______, KC_C,    KC_V,    KC_N,    KC_M,    _______, _______, _______, _______
),

[_SETTINGS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, RESET,   _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, _______,
    _______, _______, _______, _______, TO(_FPS), TO(_LEAGUE), RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, _______,
    _______, _______, _______, _______, TG_PLV, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, MAGIC_SWAP_LCTL_LGUI, MAGIC_UNSWAP_LCTL_LGUI, _______, RGB_TOG, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_PLV:
            if (record->event.pressed) {
            } else {
                layer_invert(_PLOVER);
                register_code(KC_E);
                register_code(KC_R);
                register_code(KC_F);
                register_code(KC_V);
                register_code(KC_O);
                register_code(KC_L);
                unregister_code(KC_E);
                unregister_code(KC_R);
                unregister_code(KC_F);
                unregister_code(KC_V);
                unregister_code(KC_O);
                unregister_code(KC_L);
            }
            return false;
            break;
    }
    return true;
}

#ifdef AUDIO_ENABLE
bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;
#endif

#ifdef ENCODER_ENABLE
void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        } else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    }
}
#endif

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

#ifdef AUDIO_ENABLE
bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    default:
      return true;
  }
}
#endif
