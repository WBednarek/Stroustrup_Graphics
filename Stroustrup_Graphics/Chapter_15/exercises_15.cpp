#include "exercises_15.h"

using namespace Graph_lib;


namespace Ex15
{

	//Exercise 1 drawing charts
	const int xmax = 600;
	const int ymax = 600;
	const int hafl_xmax = xmax / 2;
	const int hafl_ymax = ymax / 2;

	const int xoffset = 100;
	const int yoffset = 100;

	const int xspace = 100;
	const int yspace = 100;

	const int xlenght = xmax - xoffset - xspace; //400
	const int ylenght = ymax - yoffset - yspace;


	const int base = -11;
	const int end = 10;
	const double xscale = xlenght / (end - base-1); //20
	const double yscale = ylenght / (end - base-1);


	double one1(double x) { return 1.0; }

	int exercises()
	{
		Point t1(100, 100);
		Simple_window win(t1, xmax, ymax, "Wykresy funkcji");

		Fct sw;

		// Function s(one1, base, end, Point(hafl_xmax,hafl_ymax), xlenght); // Exercise 1
		
		
		Function s(one1, base, end, Point(hafl_xmax,hafl_ymax), xlenght, xscale, yscale); // Exercise 2
	

		Axis x(Axis::x, Point(xlenght/4, hafl_ymax), xlenght, (end-base), "1 == 20 pixels");
		Axis y(Axis::y, Point(hafl_xmax, hafl_ymax), ylenght, (end-base), "1 == 20 pixels");

	

		x.set_color(Color::red);
		y.set_color(Color::red);

		win.attach(x);
		win.attach(y);
		win.attach(s);
		win.wait_for_button();


		return 0;
	}




	/*Exercises 1,2,3,4,5

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

			Axis x(Axis::x, Point(hafl_xmax, hafl_ymax), xlenght, (end-base), "1 == 20 pixels");
		Axis y(Axis::y, Point(hafl_xmax, hafl_ymax), ylenght, (end-base), "1 == 20 pixels");

		x.set_color(Color::red);
		y.set_color(Color::red);

		win.attach(x);
		win.attach(y);
		win.wait_for_button();


		return 0;
	}
	*/
}
