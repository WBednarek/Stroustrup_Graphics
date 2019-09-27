#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities
//#include "../Person.h"


namespace H15
{


	long long fac(int n);
	long long fac_iter(int n);
	int homework();

	class Fct : public Graph_lib::Shape {
	public:
		Fct(Graph_lib::Fct f, double r1, double r2, Point orig,
			int count, double xscale, double yscale, double prec);
	
		void reset();
		void reset_function(Graph_lib::Fct* new_function);
		void reset_r1(double new_r1);
		void reset_r2(double new_r2);
		void reset_orig(Point new_count);
		void reset_count(int new_count);
		void reset_xscale(double new_xscale);
		void reset_yscale(double new_yscale);
		void reset_precision(double new_precision);

	private:
		Graph_lib::Fct* f1;
		double r1, r2;
		Point orig;
		int count;
		double xscale, yscale;
		double precision; // 1 is the best presicion, precision closer to one - better

	};


	struct Bar_chart : public Graph_lib::Shape
	{

		Bar_chart(vector<double> values, Point orig, double width, double xscale, double yscale);
		void draw_lines() const;// !!!!!!!!!!!!!!!!!!!!!!!!!!!   I have no idea why but the code does not work without it. I Think we need to inherit this function.
		//Hovewer where is this function invoked?! I am not using it explicitly, have no idea what is happening....
		Vector_ref<Rectangle> val;
	};



}