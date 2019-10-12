#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities
#include <chrono>

namespace H16_3
{
	struct Button_coord : Button // button that stores its data
	{
		Button_coord(Point xy, int w, int h, const string& label, Callback cb, int id);
		int get_x() const { return x; }
		int get_y() const { return y; }
		int get_width() const { return  width; }
		int get_height() const { return height; }
		string get_label() const { return label; }
		int get_id() const { return id; }
		void move(int dx, int dy);
		bool pressed;
	protected:
		int x;
		int y;
		int width;
		int height;
		string label;
		int id;
	};

	class My_window : Window
	{
	public:
		My_window(Point xy, int w, int h, const string& title);
	private:
		const int MAX_WIDTH = 500;
		const int MAX_HEIGHT = 300;
		int display_menu_height;
		Button_coord button;
		Image im;
		bool button_pushed;
		Out_box coordinates_display;

		int rint(int low, int high) { return low + rand() % (high - low); }
		int true_rand(int low, int high);
		void next_position();
		void display_point(int x, int y);
		static void cb_next_position(Address, Address);
	};

}