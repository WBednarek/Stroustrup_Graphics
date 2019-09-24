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
			int count, double xscale, double yscale);
	
		void reset();
		void reset_function(Graph_lib::Fct* new_function);
		void reset_r1(double new_r1);
		void reset_r2(double new_r2);
		void reset_orig(Point new_count);
		void reset_count(int new_count);
		void reset_xscale(double new_xscale);
		void reset_yscale(double new_yscale);

	private:
		Graph_lib::Fct* f1;
		double r1, r2;
		Point orig;
		int count;
		double xscale, yscale;

	};



}