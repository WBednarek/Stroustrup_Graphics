
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
		

		win.wait_for_button();
		return 0;
	}


	void squares()
	{

	}
}