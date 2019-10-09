#include "My_window.h"



namespace H16
{
	My_window::My_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		next_button(Point(w - 170, 10), 70, 30, "Dalej", cb_next),
		end_button(Point(w - 90, 10), 70, 30, "Koniec", cb_end),
		button_pushed(false)
	{
		attach(next_button);
		attach(end_button);

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




