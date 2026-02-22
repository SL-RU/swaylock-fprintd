#ifndef _SWAYLOCK_SEAT_H
#define _SWAYLOCK_SEAT_H
#include <stdbool.h>
#include <stdint.h>
#include <wayland-client.h>
#include <xkbcommon/xkbcommon.h>

struct loop;
struct loop_timer;
struct swaylock_state;

struct swaylock_xkb {
	bool caps_lock;
	bool control;
	struct xkb_state *state;
	struct xkb_context *context;
	struct xkb_keymap *keymap;
};

struct swaylock_seat {
	struct swaylock_state *state;
	struct wl_seat *wl_seat;
	enum wl_seat_capability caps;
	struct wl_pointer *pointer;
	struct wl_keyboard *keyboard;
	int32_t repeat_period_ms;
	int32_t repeat_delay_ms;
	uint32_t repeat_sym;
	uint32_t repeat_codepoint;
	struct loop_timer *repeat_timer;
	struct wl_list link;
};

extern const struct wl_seat_listener seat_listener;
void ensure_virtual_keyboard_keymap(struct swaylock_state *state);
void ensure_virtual_keyboard_for_seats(struct swaylock_state *state);

#endif
