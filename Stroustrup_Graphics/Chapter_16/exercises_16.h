#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities


namespace Ex16
{
	
	struct Lines_window : Window
	{
		Lines_window(Point xy, int w, int h, const string& title);
		Open_polyline lines;
	private:
		Button next_button;
		Button quit_buttton;
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		Menu color_menu;
		Button menu_button;

		void change(Color c) { lines.set_color(c); }
		void hide_menu() { color_menu.hide(); menu_button.show(); }

		void next();
		void quit();
		void red_pressed() { change(Color::red); }
		void blue_pressed() { change(Color::blue); }
		void black_pressed() { change(Color::black); }
		void menu_pressed() { menu_button.hide(); color_menu.show(); }


		static void cb_next(Address, Address);
		static void cb_quit(Address, Address);
		static void cb_red(Address, Address);
		static void cb_blue(Address, Address);
		static void cb_black(Address, Address);
		static void cb_menu(Address, Address);
		

	};
	
	
	void exercises();





}
