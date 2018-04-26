
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities
#include "cwiczenia_13.h"

//------------------------------------------------------------------------------


using namespace Graph_lib;

namespace Ex13
{

	int cwiczenia()
	{
		Point t(100, 100);
		Simple_window win(t, 800, 1000, "Exercises 13");
		
		squares(win);

		//Exercise 1
		Vector_ref<Rectangle> vecs;
		int square_size = 100;
		int count = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				vecs.push_back(new Rectangle(Point(j*square_size, i*square_size), Point((j*square_size) + square_size, (i*square_size) + square_size)));
				win.attach(vecs[vecs.size() -1]);
				
			}
		}

		win.wait_for_button();
		return 0;
	}


	void squares(Simple_window& win)
	{
		


	}
}