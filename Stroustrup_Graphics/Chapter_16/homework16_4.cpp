#include "homework16_4.h"


namespace H16_4
{
	Triangle::Triangle(Point a, Point b, Point c)
	{
		if (a.x == b.x && b.x == c.x && a.x == c.x) error("Points x are in line, it is not a triangle");
		if (a.y == b.y && b.y == c.y && a.y == c.y) error("Points y are in line, it is not a triangle");
		triangle.add(a);
		triangle.add(b);
		triangle.add(c);
	}

	void Triangle::draw_lines() const
	{
		triangle.draw();
	}

	Hexagon::Hexagon(Point start, int edge_length)
	{
		hexagon.add(start);

		int pointB_x = start.x + (edge_length / 2);
		int pointB_y = start.y + (edge_length*sqrt(3)/2); //We are going down, this point in hexagon is made of equilateral triangle logic
		hexagon.add(Point(pointB_x, pointB_y));

		int pointC_x = pointB_x + edge_length;
		int pointC_y = pointB_y;
		hexagon.add(Point(pointC_x, pointC_y));

		int pointD_x = pointC_x + (edge_length / 2);
		int pointD_y = pointC_y - (edge_length * sqrt(3) / 2); 
		hexagon.add(Point(pointD_x, pointD_y));

		int pointE_x = pointD_x - (edge_length / 2); // We going back
		int pointE_y = pointD_y - (edge_length * sqrt(3) / 2); 
		hexagon.add(Point(pointE_x, pointE_y));

		int pointF_x = pointE_x - edge_length;
		int pointF_y = pointE_y;
		hexagon.add(Point(pointF_x, pointF_y));
		
	}

	void Hexagon::draw_lines() const
	{
		hexagon.draw();
	}
	



	My_window::My_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		button_pushed(false),
		x_coordinate_input(Point(50,10), 30, button_height,"x"),
		y_coordinate_input(Point(100, 10), 30, button_height, "y"),
		message_box(Point(x_max()-200, 10), 150, button_height, "Message"),
		figures_menu(Point(x_max() -100, 70), 90, button_height,Menu::vertical,"figures"),
		figures_menu_button(Point(x_max() - 100, 70), 90, button_height,"Figures menu",cb_show_menu)
	{
		attach(x_coordinate_input);
		attach(y_coordinate_input);
		attach(message_box);
		figures_menu.attach(new Button(Point(0, 0), 0, 0, "Circle", cb_place_circle));
		figures_menu.attach(new Button(Point(0, 0), 0, 0, "Square", cb_place_square));
		figures_menu.attach(new Button(Point(0, 0), 0, 0, "Triangle", cb_place_equilateral_triangle));
		figures_menu.attach(new Button(Point(0, 0), 0, 0, "Hexagon", cb_place_hexagon));
		attach(figures_menu);
		figures_menu.hide();
		attach(figures_menu_button);
	
	}

	int My_window::get_x_coordinate()
	{
		if (x_coordinate_input.get_string() == "") 
		{ 
			message_box.put("insert x coordinate"); 
			return 0;
		}
		else
		{
			int x = x_coordinate_input.get_int();
			if (x < 0) error("inputted x coordinate cannot be less than 0");
			return x;
		}
		
	}

	int My_window::get_y_coordinate()
	{
		int y = y_coordinate_input.get_int();
		if (y_coordinate_input.get_string() == "")
		{
			message_box.put("insert y coordinate");
			return 0;
		}
		else
		{
			if (y < 0) error("inputted y coordinate cannot be less than 0");
			return y;
		}
		
	}


	void My_window::display_point(int x, int y)
	{
		ostringstream os;
		os << "(" << x << "," << y << ")";
		message_box.put(os.str());
	}


	void My_window::place_circle()
	{
		int x = get_x_coordinate();
		int y = get_y_coordinate();
		circles.push_back(new Circle(Point(x, y), radius));
		attach(circles[circles.size()-1]);
		figures_menu.hide();
		figures_menu_button.show();	
	}

	void My_window::place_square()
	{
		int x = get_x_coordinate();
		int y = get_y_coordinate();
		squares.push_back(new Rectangle(Point(x, y), Point(x+ edge_length,y+ edge_length)));
		attach(squares[squares.size() - 1]);
		figures_menu.hide();
		figures_menu_button.show();
	}

	void My_window::place_equilateral_triangle()
	{
		int x = get_x_coordinate();
		int y = get_y_coordinate();
		Point a = Point(x, y);
		Point b = Point(x + edge_length, y);
		int c_point_x_coord = x + (edge_length/ 2);
		int triangle_h = y - (edge_length * sqrt(3) / 2);
		Point c = Point(c_point_x_coord, triangle_h);
		equilateral_triangles.push_back(new Triangle(a, b, c));
		attach(equilateral_triangles[equilateral_triangles.size()-1]);
		figures_menu.hide();
		figures_menu_button.show();
	}

	void My_window::place_hexagon()
	{
		int x = get_x_coordinate();
		int y = get_y_coordinate();
		hexagons.push_back(new Hexagon(Point(x,y),edge_length));
		attach(hexagons[hexagons.size() - 1]);
		figures_menu.hide();
		figures_menu_button.show();
	}

	void My_window::show_menu()
	{
		figures_menu_button.hide();
		figures_menu.show();
	}

	void My_window::cb_show_menu(Address, Address pw)
	{
		reference_to<My_window>(pw).show_menu();
	}

	void My_window::cb_place_circle(Address, Address pw)
	{
		reference_to<My_window>(pw).place_circle();
	}


	void My_window::cb_place_square(Address, Address pw)
	{
		reference_to<My_window>(pw).place_square();
	}

	void My_window::cb_place_equilateral_triangle(Address, Address pw)
	{
		reference_to<My_window>(pw).place_equilateral_triangle();
	}

	void My_window::cb_place_hexagon(Address, Address pw)
	{
		reference_to<My_window>(pw).place_hexagon();
	}




}


