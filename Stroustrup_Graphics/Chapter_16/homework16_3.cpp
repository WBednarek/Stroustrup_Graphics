#include "homework16_3.h"

namespace H16_3
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

	void Button_coord::move(int dx, int dy)
	{
		hide();
		pw->position(loc.x += dx, loc.y += dy);
		show();
		x = loc.x;
		y = loc.y;
	}


	My_window::My_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		button(Point(200, 200), 100, 100, "Dalej", cb_next_position, 1),
		im(Point(200, 200), "fallout.gif"), // fallout.git is 100x100 image
		button_pushed(false),
		coordinates_display(Point(150, 10), 80, 30, "Current button point")
	{
		attach(button);
		attach(im);
		attach(coordinates_display);
		display_menu_height = 10 + 30; // this reflects y coordinate of coordinates_display variable - its height so 10 + 30
	}

	

	void My_window::cb_next_position(Address, Address pw)
	{
		reference_to<My_window>(pw).next_position();
	}

	void My_window::display_point(int x, int y)
	{
		ostringstream os;
		os << "(" << x << "," << y << ")";
		coordinates_display.put(os.str());
	}

	void My_window::next_position()
	{
		int move_step = 700; // huge step for tests
		int x = rint(-move_step, move_step);
		int y = rint(-move_step, move_step);
		int curr_button_x = button.get_x();
		int curr_button_y = button.get_y();
		//button and image will not get away from the frame of MAX_WIDTHxMAX_HEIGHT window. 
		//Actually won get away of (MAX_WIDTH + button_width) x (MAX_HEIGHT + button_height) window frame, 
		//since we validate point in the upper left corner of the button and image
		if ((curr_button_x + x) < 0
			|| (curr_button_y + y) < display_menu_height //to avoid covering out_box field by the image
			|| (curr_button_x + x) > MAX_WIDTH
			|| (curr_button_y + y) > MAX_HEIGHT)
		{
			next_position();
		}
		else
		{
			button.move(x, y);
			im.move(x, y);
			curr_button_x = button.get_x();
			curr_button_y = button.get_y();
			display_point(curr_button_x, curr_button_y);
		}
		
	}


	int My_window::true_rand(int low, int high)
	{
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		default_random_engine generator(seed);
		uniform_int_distribution<int> dist(low, high);
		return dist(generator);
	}

}