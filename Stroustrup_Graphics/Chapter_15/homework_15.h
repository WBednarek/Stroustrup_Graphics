#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities
//#include "../Person.h"


namespace H15
{


	long long fac(int n);
	long long fac_iter(int n);
	int homework();

	struct Pair
	{
		double height;
		int number;
		Pair(double height, int number);
	};


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
		enum Bar_labels_position { labels_bottom, labels_up };
		Bar_chart();
		Bar_chart(Bar_chart& bg);
		Bar_chart(vector<double> values, Point orig, double width, double xscale, double yscale, Bar_labels_position lab_position);
		Bar_chart(vector<Pair> pairs, Point orig, double width, double xscale, double yscale, Bar_labels_position lab_position);
		void draw_lines() const;//The reason why we need to define this function in a derived class (here Bar_chart) from Shape is simple.
		//draw_lines() is a virtual function in Shape so we should define it in every class that inherits from Shape. 
		//Theoretically we should but we do not need to, however in this example we need since we will no see anything on a screen.
		
		//If draw_lines() function would be pure virtual in Shape we must override it. 
		//Otherwise we will no be able to create an object of our class - it will be an abstract class.
		//As a pure virtual function it would be declared in base class Shape as virtual void draw_lines() = 0; without const at the end.

		
		void init_bar_values();
		void init_bars_coordinates();
		void init_chart_label();
		void labels_init(Bar_labels_position lab);
		void set_bar_color(int bar_num, Color c);
		void set_bar_label(int bar_num, string lab);
		void set_chart_label(string name);
		void set_chart_label_color(Color c);
		string set_double_precision(double num, int precision);
		void transfer_doubles_to_strings(const vector<double>& vec);
		
		double find_max_value(const vector<double>& vec);
		

		double xscale;
		double yscale;
		double width;
		Text label;
		vector<Pair> bar_pairs;
		Bar_labels_position labels_position;
		Vector_ref<Rectangle> val;
		vector<Point> bars_points; // Stores coordinates of each bar
		Vector_ref<Text> labels;
		
		Point bar_orig;
		vector<double> bar_values;
		vector<double> bars_labels_double;
		vector<string> bar_values_str;
	};

	

	struct Histogram : Bar_chart
	{
		Histogram(vector<Pair>& pairs, Bar_chart& b);
		Bar_chart bch;
		void set_bar_values(vector<Pair>& pairs);
		void draw_lines() const;
	};


}