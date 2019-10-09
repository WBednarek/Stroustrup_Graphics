#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"




namespace H16
{
	class My_window : Window
	{
	public:

		My_window(Point xy, int w, int h, const string& title);
	private:
		Button next_button;
		Button end_button;
		bool button_pushed;

		void next();
		void end();

		static void cb_next(Address, Address);
		static void cb_end(Address, Address);


	};

}



