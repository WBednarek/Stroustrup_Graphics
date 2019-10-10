#include "exercises_16.h"


using namespace Graph_lib;


namespace Ex16
{
	Lines_window::Lines_window(Point xy, int w, int h, const string& title)
		: Window(xy, w, h, title),
		next_button(Point(x_max() - 150, 0), 70, 20, "Nowy", cb_next),
		quit_buttton(Point(x_max() - 70, 0), 70, 20, "koniec", cb_quit),
		next_x(Point(x_max() - 310, 0), 50, 20, "x:"),
		next_y(Point(x_max() - 210, 0), 50, 20, "y:"),
		xy_out(Point(100,0), 100, 20, "bierz¹cy punkt:"),
		color_menu(Point(x_max() - 70, button_height), 70, 20,Menu::vertical, "Kolor" ),
		color_menu_button(Point(x_max() - 90, button_height), 80, 20, "Menu kolorów", cb_color_menu),
		style_menu(Point(x_max() - 70, button_height*4), 70, 20, Menu::vertical, "Style"),
		style_menu_button(Point(x_max() - 90, button_height * 4), 80, 20, "Menu stylów", cb_style_menu)
	{
		attach(next_button);
		attach(quit_buttton);
		attach(next_x);
		attach(next_y);
		attach(xy_out);
		xy_out.put("Brak");
		color_menu.attach(new Button(Point(0, 0), 0, 0, "czerwony", cb_red));
		color_menu.attach(new Button(Point(0, 0), 0, 0, "niebieski", cb_blue));
		color_menu.attach(new Button(Point(0, 0), 0, 0, "czarny", cb_black));
		style_menu.attach(new Button(Point(0, 0), 0, 0, "solid", cb_solid));
		style_menu.attach(new Button(Point(0, 0), 0, 0, "dash", cb_dash));
		style_menu.attach(new Button(Point(0, 0), 0, 0, "dashdot", cb_dashdot));
		style_menu.attach(new Button(Point(0, 0), 0, 0, "dashdotdot", cb_dashdotdot));
		attach(color_menu);
		attach(style_menu);
		color_menu.hide();
		style_menu.hide();
		attach(color_menu_button);
		attach(style_menu_button);
		attach(lines);
		
	}

	void Lines_window::cb_quit(Address, Address pw)
	{
		reference_to<Lines_window>(pw).quit();
	}

	void Lines_window::quit()
	{
		hide();
	}

	void Lines_window::cb_next(Address, Address pw)
	{
		reference_to<Lines_window>(pw).next();
	}

	void Lines_window::next()
	{
		int x = next_x.get_int();
		int y = next_y.get_int();
		lines.add(Point(x, y));
		ostringstream ss;
		ss << '(' << x << ',' << y << ')';
		xy_out.put(ss.str());
		redraw();
	}

	void Lines_window::cb_red(Address, Address pw)
	{
		reference_to<Lines_window>(pw).red_pressed();
		reference_to<Lines_window>(pw).hide_color_menu();
	}

	void Lines_window::cb_blue(Address, Address pw)
	{
		reference_to<Lines_window>(pw).blue_pressed();
		reference_to<Lines_window>(pw).hide_color_menu();

	}

	void Lines_window::cb_black(Address, Address pw)
	{
		reference_to<Lines_window>(pw).black_pressed();
		reference_to<Lines_window>(pw).hide_color_menu();
	
	}

	void Lines_window::cb_color_menu(Address, Address pw)
	{
		reference_to<Lines_window>(pw).color_menu_pressed();
	}

	void Lines_window::cb_solid(Address, Address pw)
	{
		reference_to<Lines_window>(pw).solid_pressed();
		reference_to<Lines_window>(pw).hide_style_menu();
	}

	void Lines_window::cb_dash(Address, Address pw)
	{
		reference_to<Lines_window>(pw).dash_pressed();
		reference_to<Lines_window>(pw).hide_style_menu();
	}

	void Lines_window::cb_dashdot(Address, Address pw)
	{
		reference_to<Lines_window>(pw).dashdot_pressed();
		reference_to<Lines_window>(pw).hide_style_menu();
	}

	void Lines_window::cb_dashdotdot(Address, Address pw)
	{
		reference_to<Lines_window>(pw).dashdotdot_pressed();
		reference_to<Lines_window>(pw).hide_style_menu();
	}

	void Lines_window::cb_style_menu(Address, Address pw)
	{
		reference_to<Lines_window>(pw).style_menu_pressed();
	}



}
