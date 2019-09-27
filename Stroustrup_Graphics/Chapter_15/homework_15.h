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

		void set_bar_color(int bar_num)
		{
			if (bar_num > val.size()) error("There is no such bar element to color");
			val[bar_num].set_color(Color::red);
		}

		void labels_init();
		void set_bar_label(int bar_num, string lab);
		string set_double_precision(double num, int precision);
		void transfer_doubles_to_strings(const vector<double>& vec);
		void init_chart_label();

		double find_max_value(const vector<double>& vec);
		void set_chart_label(string name, Color c);



		double xscale;
		double yscale;

		Text label;
		Vector_ref<Rectangle> val;
		vector<Point> bars_points; // Stores coordinated of each bar
		Vector_ref<Text> labels;
		Point bar_orig;
		vector<double> bar_values;
		vector<string> bar_values_str;
	};



}