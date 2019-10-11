#include "My_window.h"



namespace H16
{
	Button_coord::Button_coord(Point xy, int w, int h, const string& label, Callback cb, int id)
		:Button(xy, w, h, label, cb),
		x(xy.x),
		y(xy.y),
		width(w),
		height(h),
		label(label),
		id(id),
		pressed(false)
	{}


	My_window::My_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		next_button(Point(w - 170, 10), 70, 30, "Dalej", cb_next),
		end_button(Point(w - 90, 10), 70, 30, "Koniec", cb_end),
		rectangle_on_second_button(Point(300, 100), 100, 100),
		first_button(Point(200, 100), 100, 100, "first", cb_first_button, 1),
		second_button(Point(300, 100), 100, 100, "second", cb_second_button, 2),
		third_button(Point(200, 200), 100, 100, "third", cb_third_button, 3),
		fourth_button(Point(300, 200), 100, 100, "fourth", cb_fourth_button, 4),
		button_pushed(false),
		xy_out(Point(200, 10), 100, 20, "Current button coordinates:")
	{
		attach(next_button);
		attach(end_button);
		attach(first_button);
		attach(second_button);
		attach(third_button);
		attach(fourth_button);
		attach(xy_out);
		xy_out.put("None");	
	}

	void My_window::cb_first_button(Address, Address pw)
	{
		reference_to<My_window>(pw).pressed_first_button();
	}


	void My_window::cb_second_button(Address, Address pw)
	{
		reference_to<My_window>(pw).pressed_second_button();
	}


	void My_window::cb_third_button(Address, Address pw)
	{
		reference_to<My_window>(pw).pressed_third_button();
	}


	void My_window::cb_fourth_button(Address, Address pw)
	{
		reference_to<My_window>(pw).pressed_fourth_button();
	}


	void My_window::pressed_first_button()
	{
		int x = first_button.get_x();
		int y = first_button.get_y();
		display_point(x, y);
	}


	void My_window::pressed_second_button()
	{
		int x = second_button.get_x();
		int y = second_button.get_y();
		display_point(x, y);
		rectangle_on_second_button.set_color(Color::red);
		rectangle_on_second_button.set_fill_color(Color::red);
		attach(rectangle_on_second_button);
		second_button.hide();

	}

	void My_window::pressed_third_button()
	{
		int x = third_button.get_x();
		int y = third_button.get_y();
		display_point(x, y);
		rectangle_on_second_button.set_color(Color::invisible);
		rectangle_on_second_button.set_fill_color(Color::invisible);
		second_button.show();
	}

	void My_window::pressed_fourth_button()
	{
		int x = fourth_button.get_x();
		int y = fourth_button.get_y();
		display_point(x, y);
	}
	
	void My_window::display_point(int x, int y)
	{
		ostringstream os;
		os << '(' << x << "," << y << ')';
		xy_out.put(os.str());
	}


	void My_window::next()
	{
		button_pushed = true;
	}

	void My_window::end()
	{
		hide();
	}

	void My_window::cb_next(Address, Address pw)
	{
		reference_to<My_window>(pw).next();
	}

	void My_window::cb_end(Address, Address pw)
	{
		reference_to<My_window>(pw).end();
	}





/*

	//Maybye next time I'll figure out using lambda how to make anonymouns functions for each new unnamed button


	void My_window::init_chess() // Homwework 16.2
	{
		int row_beginning_point_x = 210; //for window width euqal 600, so that row of lenght 120 (4*30) will perfectly fit in the middle of the screen.
		int row_beginning_point_y = 110;
		const int chequer_size = 30;
		int x, y;
		int counter = 0;
		for (int row = 1; row <= chess_dimension; ++row)
		{
			y = row * chequer_size + row_beginning_point_y;
			for (int column = 1; column <= chess_dimension; ++column)
			{
				x = column * chequer_size + row_beginning_point_x;
				coordinates.push_back(new Point(x, y));
				checkboard.push_back(new Button_coord(coordinates[counter], chequer_size, chequer_size, "But", cb_coordinates,counter));
					//[](Address, Address pw) {reference_to<My_window>(pw).get_coordinates(0); })); // lambda style
				attach(checkboard[counter]);
				++counter;
			}
		}
	}

	void My_window::cb_coordinates(Address, Address pw)
	{
		int i = 0;
		reference_to<My_window>(pw).get_coordinates(i);
	}

	
	//Concept function
	int My_window::get_pressed_button_id()
	{
		for (int i = 0; i < checkboard.size(); ++i)
		{
			if (checkboard[i].pressed == true)
			{
			}
		}
		return 1;
	}
	


	void My_window::get_coordinates(int counter)
	{
		int i = get_pressed_button_id();

		//int i = counter; //reinitialized for readibility
		int x = coordinates[i].x;
		int y = coordinates[i].y;
		ostringstream os;
		os << '(' << x << "," << y << ')';
		xy_out.put(os.str());
		redraw();
	}
	
	*/
	
	

}




