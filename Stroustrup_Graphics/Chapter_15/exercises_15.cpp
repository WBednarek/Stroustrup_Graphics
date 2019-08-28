#include "exercises_15.h"

using namespace Graph_lib;


namespace Ex15
{

	//Exercises 1-5
	const int xmax = 600;
	const int ymax = 600;

	const int xoffset = 100;
	const int yoffset = 100;

	const int xspace = 100;
	const int yspace = 100;

	const int xlength = xmax - xoffset - xspace;
	const int ylength = ymax - yoffset - yspace;

	int exercises()
	{
		Simple_window win(Point(100, 100), 600, 600, "Wykresy funkcji");

		Axis x(Axis::x, Point(xoffset, xmax/2), xlength, 20, "1 == 20 pikseli"); // In Point() xoffset shows where the x segment (axix) starts from the left side of a window, the second parameter shows how "high" the asix should be placed - here is 300 pixels
		Axis y(Axis::y, Point(ymax/2, ymax - yoffset), ylength, 20, "1 == 20 pikseli"); // In Point() the second parameter is where y asix ends, we counting from the top of the window
		x.set_color(Color::red);
		y.set_color(Color::red);
		
		win.attach(x);
		win.attach(y);
		win.wait_for_button();

		return 0;
	}

}


