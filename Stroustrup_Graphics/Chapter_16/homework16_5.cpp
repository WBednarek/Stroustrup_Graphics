#include "homework16_5.h"

namespace H16_5
{

	Hexagon::Hexagon(Point start, int edge_length) : start(start), curr_pos_x(start.x), curr_pos_y(start.y)
	{
		hexagon.add(start);

		int pointB_x = start.x + (edge_length / 2);
		int pointB_y = start.y + (edge_length * sqrt(3) / 2); //We are going down, this point in hexagon is made of equilateral triangle logic
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


	void Hexagon::move(int dx, int dy)    
	{
		hexagon.move(dx,dy);
	}

	void Hexagon::move_to_position(int x, int y)
	{
		hexagon.move(-curr_pos_x + x, -curr_pos_y + y); // -curr_pos means taht we start from Point(0,0) then add x and y
		curr_pos_x = x;
		curr_pos_y = y;
		
	}



	My_window::My_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		window_width(w),
		window_height(h),
		draw_button_pushed(false),
		x_coordinate_input(Point(20, 10), 30, button_height, "x"),
		y_coordinate_input(Point(70, 10), 30, button_height, "y"),
		message_box(Point(x_max() - 430, 10), 300, button_height, "Message"),
		next_position_button(Point(x_max() - 100, 10), 90, button_height, "Next", cb_next_figure_position),
		draw_figure_button(Point(x_max() - 100, 70), 90, button_height, "Draw", cb_place_hexagon)
	{
		attach(x_coordinate_input);
		attach(y_coordinate_input);
		attach(message_box);
		attach(next_position_button);
		attach(draw_figure_button);
	}

	int My_window::get_x_coordinate()
	{
		int x = x_coordinate_input.get_int();
		if (x_coordinate_input.get_string() == "")
		{
			message_box.put("insert x coordinate");
		}
		else if(x < 0)
		{
			message_box.put("inputted x coordinate cannot be less than 0");
		}
		else
		{
			return x;
		}

	}

	int My_window::get_y_coordinate()
	{
		int y = y_coordinate_input.get_int();
		if (y_coordinate_input.get_string() == "")
		{
			message_box.put("insert y coordinate");
		}
		else if(y < 0)
		{
			message_box.put("inputted y coordinate cannot be less than 0");
		}
		else
		{
			return y;
		}
		
	}

	void My_window::display_coords(int x, int y)
	{
		ostringstream os;
		os <<"Current figure position " << "(" << x << "," << y << ")";
		message_box.put(os.str());
	}

	void My_window::draw_figure()
	{
		draw_button_pushed = true;
		int x = window_width/2;
		int y = window_height/2;
		hexagons.push_back(new Hexagon(Point(x, y), edge_length));
		attach(hexagons[hexagons.size() - 1]);
		draw_figure_button.hide();
	}

	void My_window::cb_place_hexagon(Address, Address pw)
	{
		reference_to<My_window>(pw).draw_figure();
	}

	bool My_window::is_figure_in_scope(int curr_x, int curr_y)
	{
		if (curr_x < edge_length
			|| curr_x > MAX_X_BORDER
			|| curr_y < edge_length
			|| curr_y > MAX_Y_BORDER)
		{
			return false;
		}
		return true;
	}


	void My_window::next_figure_position()
	{
		if (draw_button_pushed == false)
		{
			message_box.put("First press draw button");
			return;
		}
		
		int x = get_x_coordinate();
		int y = get_y_coordinate();
		if (is_figure_in_scope(x, y) == false)
		{
			message_box.put("Coordinates out of scope, input again");
			return;
		}
		display_coords(x, y);
		hexagons[hexagons.size() - 1].move_to_position(x, y);
		redraw();
	}


	void My_window::cb_next_figure_position(Address, Address pw)
	{
		reference_to<My_window>(pw).next_figure_position();
	}




}