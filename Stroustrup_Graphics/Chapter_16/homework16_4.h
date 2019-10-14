#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities


namespace H16_4
{
	class Triangle : public Polygon
	{
	public:
		Triangle(Point a, Point b, Point c);
		void draw_lines() const;
	private:
		Polygon triangle;
	};

	class Hexagon : public Polygon
	{
	public:
		Hexagon::Hexagon(Point start, int edge_length);
		void draw_lines() const;
	private:
		Polygon hexagon;
	};

	class My_window : Window
	{
	public:
		My_window(Point xy, int w, int h, const string& title);
	private:
		int display_menu_height;
		const int button_height = 30;
		const int radius = 30;
		const int edge_length = 40;
		bool button_pushed;
		Menu figures_menu;
		Button figures_menu_button;
		In_box x_coordinate_input;
		In_box y_coordinate_input;
		Out_box message_box;
		Vector_ref<Circle> circles;
		Vector_ref<Rectangle> squares;
		Vector_ref<Triangle> equilateral_triangles;
		Vector_ref<Hexagon> hexagons;

		int get_x_coordinate();
		int get_y_coordinate();
		
		void display_point(int x, int y);
		void show_menu();
		void place_circle();
		void place_square();
		void place_equilateral_triangle();
		void place_hexagon();


		static void cb_show_menu(Address, Address);
		static void cb_place_circle(Address, Address);
		static void cb_place_square(Address, Address);
		static void cb_place_equilateral_triangle(Address, Address);
		static void cb_place_hexagon(Address, Address);
	};










}


