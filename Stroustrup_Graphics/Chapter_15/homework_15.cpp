#include "homework_15.h"

namespace H15
{
	long long fac(int n)
	{
		return n > 1 ? n * fac(n-1) : 1;
	}

	long long fac_iter(int n)
	{
		if (n == 1) return 1;
		long long fac = n;
		while (n > 1)
		{
			fac = fac * (n - long long(1));
			--n;
		}

		return fac;
	}

	void compare_factorials(int n)
	{
		
		cout << "Factorials from 1 to 19" << endl;
		cout <<"Base\t" << setw(6) << "Recurency method" << setw(30) << "Iteration method" << endl;
		for (int i = 0; i < n; ++i)
		{
			cout << i << ":\t" <<setw(10)<< fac(i) << setw(30) << fac_iter(i) << endl;
		}
	}


//------------------------------------------------------------------------------
//Stroustrup: Programming -- Principles and Practice Using C++; Chapter 15, homework 2

	Fct::Fct(Graph_lib::Fct f, double r1, double r2, Point orig,
		int count, double xscale, double yscale, double prec) : f1(f), r1(r1), r2(r2), orig(orig), count(count), xscale(xscale), yscale(yscale), precision(prec)
	{
		reset();
	}
	//------------------------------------------------------------------------------
	void Fct::reset()
	{
		if (r2 - r1 <= 0) error("r2-r1 > 0. The range is incorrect");
		if (count <= 0) error("count (number of segments) is less than 0");
		if (precision < 1) error("presiiosn must be 1 or bigger");
		double dist = (r2 - r1) / count;
		double r = r1;
		Graph_lib::Shape::clear_points();
		for (int i = 0; i < count; ++i)
		{
			add(Point(int(int(r * xscale/precision)*precision) + orig.x, orig.y - int(int(f1(r) * yscale/precision)*precision))); //Closer to 1 presicion is better
			//Situation precision = 7, r*xscale = 20.6 ->  20.6/7 = 2.943, int(2.943) = 2 ->  2*7 = 14, so very imprecise
			//Situation precision = 1, r*xscale = 20.6 ->  20.6/1 = 20.6, int(20.6) = 20 ->  20*1 = 20, so very precise
			r += dist;
		}
	}

	//------------------------------------------------------------------------------	

	void Fct::reset_function(Graph_lib::Fct* new_function)
	{
		f1 = new_function;
		reset();
	}

	//------------------------------------------------------------------------------

	void Fct::reset_r1(double new_r1)
	{
		r1 = new_r1;
		reset();
	}

	//------------------------------------------------------------------------------

	void Fct::reset_r2(double new_r2)
	{
		r2 = new_r2;
		reset();
	}

	//------------------------------------------------------------------------------

	void Fct::reset_orig(Point new_orig)
	{
		orig = new_orig;
		reset();
	}

	//------------------------------------------------------------------------------

	void Fct::reset_count(int new_count)
	{
		if (new_count <= 0) error("count must be bigger than 0");
		count = new_count;
		reset();
	}

	//------------------------------------------------------------------------------

	void Fct::reset_xscale(double new_xscale)
	{
		if (new_xscale <= 0) error("xscale must be bigger than 0");
		xscale = new_xscale;
		reset();
	}

	//------------------------------------------------------------------------------

	void Fct::reset_yscale(double new_yscale)
	{
		if (new_yscale <= 0) error("yscale must be bigger than 0");
		xscale = new_yscale;
		reset();
	}

	void Fct::reset_precision(double new_precision)
	{
		if (new_precision < 1) error("presiiosn must be 1 or bigger");
		precision = new_precision;
		reset();
	}


	

	//------------------------------------------------------------------------------
	double square(double x)
	{
		return x * x;
	}

	//------------------------------------------------------------------------------

	/*double pow(double base, int exp)
	{
		if (exp == 0) return 1;
		if (exp == 1) return base;
		while (exp > 1)
		{
			base *= base;
			--exp;
		}
		return base;
	}*/

	double pow3(double base)
	{
		const double pow_of_three = 3;
		return pow(base, pow_of_three);
	}

	double sin_cos_squared(double x)
	{
		return sin(x) * sin(x) + cos(x) * cos(x);
	}

	
	int homework()
	{


		//const int MAX_FCT = 21;
		//compare_factorials(MAX_FCT); //exercise 1
		const int xmax = 600;
		const int ymax = 600;

		const int xoffset = 100;
		const int yoffset = 100;

		const int xspace = 100;
		const int yspace = 100;

		const int xlength = xmax - xoffset - xspace; // 400 pixeles
		const int ylength = ymax - yoffset - yspace; // 400 pixeles

		const int xscale = 20;
		const int yscale = 20;

		const int r_min = -10;
		const int r_max = 11;

		const int number_of_notches = r_max - r_min -1; // 20

		const int scaled_length = abs(r_min - r_max) - 1; // length of 20 on axis which is eqivalent of 400 pixels 

		const Point orig(xmax / 2, ymax / 2); // Point(xmax/2, ymax/2) corresponds to Point(0,0) on displayed label

		const int graph_resolution = 300;
		const int PI = _Pi;
		const double graph_presicion = 1; // 1 is the best presicion, precision closer to one - better

		Simple_window win(Point(100, 100), 600, 600, "Homework chapter 15");
		Axis x_axis(Axis::x, Point(xoffset, ymax / 2), xlength, number_of_notches, "x asis");
		
		Axis y_axis(Axis::y, Point(xmax / 2, ymax-yoffset), ylength, number_of_notches, "y asis"); // Axis goes up from point (ymax-yoffset) = 500, to ylength = 100
		Fct sine(sin, r_min, r_max, orig, graph_resolution, xscale, yscale, graph_presicion);
		double x_sine_label = orig.x + (PI / 2)*xscale+15; // Label over the PI/2 heap on x axis in sine function
		double y_sine_label = orig.y - sin(PI / 2)*yscale - 5; // By subtracting we go up on y axis
		Text sine_label(Point(x_sine_label, y_sine_label), "sine");
		sine.set_color(Color::blue);
		sine_label.set_color(Color::blue);
		
		Fct cosine(cos, r_min, r_max, orig, graph_resolution, xscale, yscale, graph_presicion);
		double x_cos_label = orig.x + PI*xscale; 
		double y_cos_label = orig.y - cos(PI) * yscale + 10; // To go down we need to add pixels and cos(PI) is negative value, so by subtractng cos(PI) we add it and we go down.
		Text cosine_label(Point(x_cos_label, y_cos_label), "cosine");
		cosine.set_color(Color::red);
		cosine_label.set_color(Color::red);

		Fct sine_cosine_square_sum(sin_cos_squared, r_min, r_max, orig, graph_resolution, xscale, yscale, graph_presicion);
		double x_sine_cosine_square_sum_label = xoffset;
		double y_sine_cosine_square_sum_label = orig.y - sin_cos_squared(0) * yscale - 5;
		Text sine_cosine_square_sum_label(Point(x_sine_cosine_square_sum_label, y_sine_cosine_square_sum_label), "sin(x)*sin(x) + cos(x)*cos(x)");

		
		win.attach(x_axis);
		win.attach(y_axis);
		win.attach(sine);
		win.attach(sine_label);
		win.attach(cosine);
		win.attach(cosine_label);
		win.attach(sine_cosine_square_sum);
		win.attach(sine_cosine_square_sum_label);


		win.wait_for_button();



		//Fct homework2(square, r_min, r_max, orig, graph_resolution, xscale, yscale, graph_presicion);
		//homework2.reset_function(pow3); // works
		//homework2.reset_orig(Point(150, 150)); //works

		return 0;
	}
}