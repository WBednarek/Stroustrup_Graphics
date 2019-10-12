#include "homework16_4.h"


namespace H16_4
{

	My_window::My_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		button_pushed(false),
		x_coordinate_input(Point(50,10), 30, button_height,"x"),
		y_coordinate_input(Point(100, 10), 30, button_height, "y"),
		coordinates_display(Point(x_max()-150, 10), 80, button_height, "Current point"),
		figures_menu(Point(x_max() -100, 70), 90, button_height,Menu::vertical,"figures"),
		figures_menu_button(Point(x_max() - 100, 70), 90, button_height,"Figures menu",cb_show_menu),
		circle_counter(0)
	{
		attach(x_coordinate_input);
		attach(y_coordinate_input);
		attach(coordinates_display);
		figures_menu.attach(new Button(Point(0, 0), 0, 0, "Circle", cb_place_circle));
		attach(figures_menu);
		figures_menu.hide();
		attach(figures_menu_button);
	
	}

	int My_window::get_x_coordinate()
	{
		int x = x_coordinate_input.get_int();
		if (x < 0) error("inputted x coordinate cannot be less than 0");
		return x;
	}

	int My_window::get_y_cooordinate()
	{
		int y = y_coordinate_input.get_int();
		if (y < 0) error("inputted y coordinate cannot be less than 0");
		return y;
	}


	void My_window::display_point(int x, int y)
	{
		ostringstream os;
		os << "(" << x << "," << y << ")";
		coordinates_display.put(os.str());
	}

	void My_window::add_counter(int& counter)
	{
		if (counter >= INT_MAX) error("Too many figures placed");
		++counter;
		
	}

	void My_window::place_circle()
	{
		int x = get_x_coordinate();
		int y = get_y_cooordinate();
		circles.push_back(new Circle(Point(x, y), radius));
		attach(circles[circle_counter]);
		add_counter(circle_counter);
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








}


