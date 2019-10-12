#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities


namespace H16_4
{

	class My_window : Window
	{
	public:
		My_window(Point xy, int w, int h, const string& title);
	private:
		int display_menu_height;
		const int button_height = 30;
		const int radius = 30;
		int circle_counter;
		bool button_pushed;
		Menu figures_menu;
		Button figures_menu_button;
		In_box x_coordinate_input;
		In_box y_coordinate_input;
		Out_box coordinates_display;
		Vector_ref<Circle> circles;

		int get_x_coordinate();
		int get_y_cooordinate();
		
		void place_circle();
		void add_counter(int& counter);
		void show_menu();
		void display_point(int x, int y);
		static void cb_place_circle(Address, Address);
		static void cb_show_menu(Address, Address);
	};










}


