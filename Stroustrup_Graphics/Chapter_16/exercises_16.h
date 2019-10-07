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
		const int button_height = 30;
		Button next_button;
		Button quit_buttton;
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		Menu color_menu;
		Button color_menu_button;
		Menu style_menu;
		Button style_menu_button;
	

		void change(Color c) { lines.set_color(c); }
		void change_style(Line_style s) { lines.set_style(s); }
		void hide_color_menu() { color_menu.hide(); color_menu_button.show(); }
		void hide_style_menu() { style_menu.hide(); style_menu_button.show(); }

		void next();
		void quit();
		void red_pressed() { change(Color::red); }
		void blue_pressed() { change(Color::blue); }
		void black_pressed() { change(Color::black); }
		void color_menu_pressed() { color_menu_button.hide(); color_menu.show(); }

		void solid_pressed() { change_style(Line_style::solid); }
		void dash_pressed() { change_style(Line_style::dash); }
		void dashdot_pressed() { change_style(Line_style::dashdot); }
		void dashdotdot_pressed() { change_style(Line_style::dashdotdot); }
		void style_menu_pressed() { style_menu_button.hide(); style_menu.show(); }


		

		static void cb_next(Address, Address);
		static void cb_quit(Address, Address);
		static void cb_red(Address, Address);
		static void cb_blue(Address, Address);
		static void cb_black(Address, Address);
		static void cb_color_menu(Address, Address);

		static void cb_solid(Address, Address);
		static void cb_dash(Address, Address);
		static void cb_dashdot(Address, Address);
		static void cb_dashdotdot(Address, Address);
		static void cb_style_menu(Address, Address);
		

	};
	
	



}
