#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"




namespace H16
{
	struct Button_coord : Button // button that stores its data
	{
		Button_coord(Point xy, int w, int h, const string& label, Callback cb, int id);
		int get_x() { return x; }
		int get_y() { return y; }
		int get_width() { return  width; }
		int get_height() { return height; }
		string get_label() { return label; }
		int get_id() { return id; }
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
	
		Button next_button;
		Button end_button;
		Out_box xy_out;
		bool button_pushed;
		Button_coord first_button;
		Button_coord second_button;
		Button_coord third_button;
		Button_coord fourth_button;
		Rectangle rectangle_on_second_button;
		
	
		void next();
		void end();
	
		void pressed_first_button();
		void pressed_second_button();
		void pressed_third_button();
		void pressed_fourth_button();
		void display_point(int x, int y);
		
		static void cb_next(Address, Address);
		static void cb_end(Address, Address);
		static void cb_first_button(Address, Address);
		static void cb_second_button(Address, Address);
		static void cb_third_button(Address, Address);
		static void cb_fourth_button(Address, Address);
	

		
		/*
		//Not finally used in chapter 15, homework 2 
		//const int chess_dimension = 4;
		Vector_ref<Button_coord> checkboard;
		Vector_ref<Point> coordinates;
		int counter;
		void init_chess();
		void get_coordinates(int counter);
		int get_pressed_button_id();
		static void cb_coordinates(Address, Address);
		*/
	};

}



