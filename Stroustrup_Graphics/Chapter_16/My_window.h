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
		const int chess_dimension = 4;
		Button next_button;
		Button end_button;
		Out_box xy_out;
		bool button_pushed;
		Vector_ref<Button>  chess;



		Vector_ref<Button> sd;

		void init_chess();

		void next();
		void end();

		static void cb_next(Address, Address);
		static void cb_end(Address, Address);


	};

}



