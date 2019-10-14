#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities

namespace H16_5
{

	class Hexagon : public Polygon
	{
	public:
		Hexagon::Hexagon(Point start, int edge_length);
		void draw_lines() const;
		void move(int dx, int dy);
		void move_to_position(int x, int y);
		int get_curr_pos_x() { return curr_pos_x; }
		int get_curr_pos_y() { return curr_pos_y; }
	private:
		int curr_pos_x;
		int curr_pos_y;
		Point start;
		Polygon hexagon;
	};

	class My_window : Window
	{
	public:
		My_window(Point xy, int w, int h, const string& title);
	private:
		const int window_width;
		const int window_height;
		const int button_height = 30;
		const int MAX_X_BORDER = window_width - 2*button_height;
		const int MAX_Y_BORDER = window_height - button_height;
		const int radius = 30;
		const int edge_length = 40;
		bool draw_button_pushed;
		Button draw_figure_button;
		Button next_position_button;
		In_box x_coordinate_input;
		In_box y_coordinate_input;
		Out_box message_box;
		Vector_ref<Circle> circles;
		Vector_ref<Hexagon> hexagons;

		int get_x_coordinate();
		int get_y_coordinate();

		void display_coords(int x, int y);
		void draw_figure();
		bool is_figure_in_scope(int curr_x, int curr_y);
		void next_figure_position();


		static void cb_show_menu(Address, Address);
		static void cb_place_hexagon(Address, Address);
		static void cb_next_figure_position(Address, Address);
	};





}