#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

int main() {
	srand(time(NULL));
	al_init();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = al_create_display(600, 600);
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60);
	al_start_timer(timer);

	al_install_keyboard();
	al_install_mouse();

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));

	int cx = 300, cy = 300;
	int px = 100;
	int py = 100;
	ALLEGRO_EVENT ev;
	int r = 20;
	int rotation = 1;
	int velocity = 2;

	while (1) {

		al_wait_for_event(queue, &ev);

		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_draw_filled_circle(px, py, 2, al_map_rgb(255, 255, 255));


		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
			rotation = 1;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
			rotation = 2;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
			rotation = 3;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			rotation = 4;
		}

		if (rotation == 1) {
			al_draw_filled_pieslice(cx += velocity, cy, r, 0.5, 5, al_map_rgb(255, 255, 255));
		}
		else if (rotation == 2) {
			al_draw_filled_pieslice(cx -= velocity, cy, r, 3.7, 5, al_map_rgb(255, 255, 255));
		}
		else if (rotation == 3) {
			al_draw_filled_pieslice(cx, cy -= velocity, r, 5.2, 5, al_map_rgb(255, 255, 255));
		}
		else if (rotation == 4) {
			al_draw_filled_pieslice(cx, cy += velocity, r, 2.2, 5, al_map_rgb(255, 255, 255));
		}

		if (abs(px - cx) < r && abs(py - cy) < r) {
			px = rand() % 400 + 100;
			py = rand() % 400 + 100;
			r += 5;
			velocity += 1;
		}

		if (cx + r > 600 || cx - r < 0 || cy + r > 600 || cy - r < 0) {
			system("pause");
		}

		al_flip_display();
	}
	system("pause");
	return 0;
}