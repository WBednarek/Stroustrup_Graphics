#include "My_window.h"



namespace H16
{
	My_window::My_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		next_button(Point(w - 170, 10), 70, 30, "Dalej", cb_next),
		end_button(Point(w - 90, 10), 70, 30, "Koniec", cb_end),
		button_pushed(false),
		xy_out(Point(100, 0), 100, 20, "Current button coordinates:")
	{
		attach(next_button);
		attach(end_button);
		attach(xy_out);
		xy_out.put("None");
		init_chess();
		
	}


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
				chess.push_back(new Button(Point(x, y), chequer_size, chequer_size, "But", cb_next));
				attach(chess[counter]);
				++counter;
			}
		} 

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
}




