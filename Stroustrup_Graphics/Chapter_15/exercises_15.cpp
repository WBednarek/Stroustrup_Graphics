#include "exercises_15.h"

using namespace Graph_lib;


namespace Ex15
{

	const int xmax = 600;
	const int ymax = 600;

	const int xoffset = 100;
	const int yoffset = 100;

	const int xspace = 100;
	const int yspace = 100;

	const int xlenght = xmax - xoffset - xspace;
	const int ylenght = ymax - yoffset - yspace;


	const int base = 0;
	const int end = 20;
	const double xscale = xlenght / (end - base);
	const double yscale = ylenght / (end - base);

	int exercises()
	{
		Point t1(100, 100);
		Simple_window win(t1, xmax, ymax, "Wykresy funkcji");

		Axis x(Axis::x, Point(xoffset, ymax - yoffset), xlenght, 20, "1 == 20 pixels");
		Axis y(Axis::y, Point(xoffset, ymax - yoffset), ylenght, 20, "1 == 20 pixels");

		x.set_color(Color::red);
		y.set_color(Color::red);

		win.attach(x);
		win.attach(y);
		win.wait_for_button();


		return 0;
	}

}
