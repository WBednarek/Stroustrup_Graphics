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

	//------------------------------------------------------------------------------

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
		if (precision < 1) error("precision must be 1 or bigger");
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
		if (new_precision < 1) error("precision must be 1 or bigger");
		precision = new_precision;
		reset();
	}

	//------------------------------------------------------------------------------

	double square(double x)
	{
		return x * x;
	}

	//------------------------------------------------------------------------------

	double pow3(double base)
	{
		const double pow_of_three = 3;
		return pow(base, pow_of_three);
	}

	//------------------------------------------------------------------------------

	double sin_cos_squared(double x)
	{
		return sin(x) * sin(x) + cos(x) * cos(x);
	}

	//------------------------------------------------------------------------------

	double term_Leibniz(double x)
	{
		return pow(-1,x) / (2*x+1);
	}

	//------------------------------------------------------------------------------

	double Leibniz_series(double x, int num_of_terms)
	{
		double sum = 0;
		for (int i = 0; i < num_of_terms; ++i)
		{
			sum += term_Leibniz(i);
		}
		return sum;
	}

	//------------------------------------------------------------------------------

	int LeibnizN_num_of_terms = 2;

	double LeibnizN_terms(double x)
	{
		return Leibniz_series(x, LeibnizN_num_of_terms);
	}

	//------------------------------------------------------------------------------

	Bar_chart::Bar_chart(vector<double> values, Point orig, double width, double xscale, double yscale, Bar_labels_position lab_position)
		: bar_values(values), bar_orig(orig), width(width), xscale(xscale), yscale(yscale), label(Point(0,0),"lab"), labels_position(lab_position)
	{
		init_bars_coordinates();
		transfer_doubles_to_strings(bar_values);
		init_chart_label();
		labels_init(labels_position);
		
	}

	//------------------------------------------------------------------------------

	Bar_chart::Bar_chart(vector<Pair> pairs, Point orig, double width, double xscale, double yscale, Bar_labels_position lab_position)
		:  bar_pairs(pairs), bar_orig(orig), width(width), xscale(xscale), yscale(yscale), label(Point(0, 0), "lab"), labels_position(lab_position)
	{
		init_bar_values();
		init_bars_coordinates();
		transfer_doubles_to_strings(bars_labels_double);
		init_chart_label();
		labels_init(labels_position);
	}

	//------------------------------------------------------------------------------

	Bar_chart::Bar_chart(Bar_chart& bg)
		: bar_values(bg.bar_values), bar_orig(bg.bar_orig), width(bg.width), xscale(bg.xscale), yscale(bg.yscale), label(Point(0, 0), "lab"), labels_position(bg.labels_position)
	{
		init_bars_coordinates();
		transfer_doubles_to_strings(bar_values);
		init_chart_label();
		labels_init(labels_position);
	}

	Bar_chart::Bar_chart() : label(Point(0, 0), "lab")
	{

	}

	//------------------------------------------------------------------------------

	void Bar_chart::draw_lines() const
	{
		Shape::draw_lines();
		label.draw();
		for (int i = 0; i < val.size(); ++i)
		{
			val[i].draw();
			labels[i].draw();
		
		}		
	}

	//------------------------------------------------------------------------------

	void Bar_chart::init_bar_values()
	{
		for (int i = 0; i < bar_pairs.size(); ++i)
		{
			bar_values.push_back(bar_pairs[i].number);
			bars_labels_double.push_back(bar_pairs[i].height);
		}
	}
	
	//------------------------------------------------------------------------------

	void Bar_chart::init_bars_coordinates()
	{
		double bar_width = 0;
		//val.push_back(new Rectangle(Point(orig.x, orig.y - 4 * yscale), 1 * xscale, 4 * yscale));
		for (int i = 0; i < bar_values.size(); ++i)
		{
			bars_points.push_back(Point(bar_orig.x + bar_width, bar_orig.y - bar_values[i] * yscale));
			val.push_back(new Rectangle(Point(bars_points[i]), 1 * xscale, bar_values[i] * yscale));
			bar_width += width;
		}
	}

	//------------------------------------------------------------------------------

	void Bar_chart::init_chart_label()
	{
		int chart_centre_x = bar_values.size() / 2;
		double x = bar_orig.x + chart_centre_x * xscale;
		double y = bar_orig.y - find_max_value(bar_values) * yscale - 10;
		label.move(x, y);
	}

	//------------------------------------------------------------------------------

	void Bar_chart::set_chart_label(string name)
	{
		label.set_label(name);
	}

	//------------------------------------------------------------------------------

	void Bar_chart::set_chart_label_color(Color c = Color::red)
	{
		label.set_color(c);
	}

	//------------------------------------------------------------------------------

	void Bar_chart::labels_init(Bar_labels_position lab)
	{
		double x = 0;
		double y = 0;
		switch (lab)
		{
		case H15::Bar_chart::labels_bottom:
			y = bar_orig.y+15; // If I would like to have the selected bar label on the bottom of the chart
			for (int i = 0; i < bars_points.size(); ++i)
			{
				x = bars_points[i].x;
				labels.push_back(new Text(Point(x, y), bar_values_str[i]));
			}
			break;
		case H15::Bar_chart::labels_up:
			y = 0;
			for (int i = 0; i < bars_points.size(); ++i)
			{
				x = bars_points[i].x;
				y = bars_points[i].y - 5;
				labels.push_back(new Text(Point(x, y), bar_values_str[i]));
			}
			break;
		default:
			error("There is no such bar label position");
			break;
		}
		
	}

	//------------------------------------------------------------------------------

	void Bar_chart::set_bar_label(int bar_num, string labl)
	{
		if (bar_num > bars_points.size()) error("There is no such bar element to be labeled");
		labels[bar_num].set_label(labl);
		
	}

	//------------------------------------------------------------------------------

	void Bar_chart::set_bar_color(int bar_num, Color c = Color::magenta)
	{
		if (bar_num > val.size()) error("There is no such bar element to color");
		val[bar_num].set_color(c);
	}

	//------------------------------------------------------------------------------

	string Bar_chart::set_double_precision(double num, int precision)
	{
		std::ostringstream streamObj3;
		streamObj3 << std::fixed;
		streamObj3 << std::setprecision(precision);
		streamObj3 << num;
		std::string strObj3 = streamObj3.str();
		return strObj3;
	}

	//------------------------------------------------------------------------------

	void Bar_chart::transfer_doubles_to_strings(const vector<double>& vec)
	{
		const int custom_precision = 0;
		for (int i = 0; i < vec.size(); ++i)
		{	
			string val_precision_2 = set_double_precision(vec[i], custom_precision);
			bar_values_str.push_back(val_precision_2);
		}
	}

	//------------------------------------------------------------------------------

	double Bar_chart::find_max_value(const vector<double>& vec)
	{
		int max = vec[0];
		for (int i = 1; i < vec.size(); ++i)
		{
			if (vec[i] > max)
			{
				max = vec[i];
			}
		}
		return max;
	}

	//------------------------------------------------------------------------------

	Pair::Pair(double height, int num) : height(height), number(num)
	{
		if (height <= 0) error("Height must be greater than 0");
		if (number < 1) error("There must be at least 1 element in Pair");
	}

	//------------------------------------------------------------------------------

	Histogram::Histogram(vector<Pair>& pairs, Bar_chart& b) : bch(b)
	{
		bch.labels_position = Bar_chart::labels_bottom;
		set_bar_values(pairs);
		bch.init_bars_coordinates();
		bch.labels_init(Bar_chart::labels_bottom);
		
	}

	//------------------------------------------------------------------------------

	void Histogram::draw_lines() const
	{
		bch.draw_lines();
	}

	void Histogram::set_bar_values(vector<Pair>& pairs)
	{
		bch.bar_values.clear();
		bch.bar_values_str.clear();
		vector<double> histogram_quantities;
		for (int i = 0; i < pairs.size(); ++i)
		{
			bch.bar_values.push_back(pairs[i].number);
			histogram_quantities.push_back(pairs[i].number);
		}
		bch.transfer_doubles_to_strings(histogram_quantities);
	}

	//------------------------------------------------------------------------------

	ifstream& operator >> (ifstream& is, vector<Pair>& vec_pairs)
	{
		while (is)
		{
			char ch;
			double height = 7878484591;
			double quantity = 118559457;

			is >> ch;
			if (ch != '(')
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
			}
			is >> ch;
			if (!isdigit(ch))
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
			}
			is.unget();
			is >> height;
			is >> ch;
			if (ch != ',')
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
			}
			is >> ch;
			if (!isdigit(ch))
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
			}
			is.unget();
			is >> quantity;
			is >> ch;
			if (ch != ')')
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
			}
			is >> ch;
			if (is.eof())
			{
				ch = ',';
			}

			if (ch != ',')
			{
				is.unget();
				is.clear(ios_base::failbit);
				break;
			}


			vec_pairs.push_back(Pair(height, quantity));

		}

		return is;
	}

	//------------------------------------------------------------------------------

	ofstream& operator << (ofstream& ofs, vector<Pair>& points)
	{
		for (int i = 0; i < points.size()-1; ++i)
		{
			ofs << "(" << points[i].height << "," << points[i].number << "), ";
		}
		ofs << "(" << points[points.size()-1].height << "," << points[points.size()-1].number << ")";

		return ofs;
	}

	//------------------------------------------------------------------------------

	vector<Pair> get_pairs(string filename, vector<Pair>& points)
	{
		ifstream ifs;
		ifs.open(filename.c_str());
		ifs >> points;
		return points;
	}

	//------------------------------------------------------------------------------

	double find_max(const vector<double>& max_vec)
	{
		double max = max_vec[0];
		for (int i = 0; i < max_vec.size(); ++i)
		{
			if (max_vec[i] > max)
			{
				max = max_vec[i];
			}
		}
		return max;
	}

	//------------------------------------------------------------------------------

	vector<double> get_vector_of_quantities(const vector<Pair>& pairs)
	{
		vector<double> quantities;
		for (int i = 0; i < pairs.size(); ++i)
		{
			quantities.push_back(pairs[i].number);
		}
		return quantities;
	}

	


	int homework()
	{


		//const int MAX_FCT = 21;
		//compare_factorials(MAX_FCT); //exercise 1

		//Exercise 9
		vector<Pair> pairs;
		get_pairs("heights_ex_9.txt", pairs);
		vector<double> quant = get_vector_of_quantities(pairs);
		const int number_of_x_notches = quant.size(); // Scaling the axis for diffrent input number
		const int number_of_y_notches = int(find_max(quant));
		/*
		The case of one vector, remember also to put vals as the parameter of vals object

		vector<double> vals = { 9.2, 4,3,1,7,5 };
		const int number_of_x_notches = vals.size(); // Scaling the axis for diffrent input number
		const int number_of_y_notches = int(find_max(vals));
		*/
		
		const int xmax = 800;
		const int ymax = 800;

		const int xoffset = 100;
		const int yoffset = 100;

		const int xspace = 100;
		const int yspace = 100;

		const int xlength = xmax - xoffset - xspace; // 400 pixeles
		const int ylength = ymax - yoffset - yspace; // 400 pixeles

		const int xscale = xlength / number_of_x_notches;
		const int yscale = ylength / number_of_y_notches;

		const int r_min = -(xscale/2);
		const int r_max = xscale/2 + 1;

		//const int number_of_x_notches = xlength / xscale; // The best if it is divided by xlenght without the rest
		//const int number_of_y_notches = ylength / yscale; // The best if it is divided by ylenght without the rest

		const int scaled_length = abs(r_min - r_max) - 1; // length of 20 on axis which is eqivalent of 400 pixels 

		const Point orig(xoffset, ymax - yoffset); // Point(xmax/2, ymax/2) corresponds to Point(0,0) on displayed label

		const int graph_resolution = 300;
		const double PI = _Pi;
		const double graph_presicion = 1; // 1 is the best presicion, precision closer to one - better

	
		Simple_window win(Point(100, 100), xmax, ymax, "Homework chapter 15");
		Axis x_axis(Axis::x, Point(orig.x, orig.y), xlength, number_of_x_notches, "x asis");
		string label_y = "y axis, max represents value of " + to_string(number_of_y_notches);
		Axis y_axis(Axis::y, Point(orig.x, orig.y), ylength, number_of_y_notches, label_y);
		
		win.attach(x_axis);
		win.attach(y_axis);

		//Exercise 8
		Bar_chart bar_chart(pairs,orig,xscale,xscale,yscale, Bar_chart::labels_bottom); // Histogram
		bar_chart.set_bar_color(0, Color::cyan);
		bar_chart.set_chart_label("Histogram, female height");
		bar_chart.set_chart_label_color(Color::dark_green);	

		string nam = "saved_pairs.txt"; // The saved file will be strored in Debug folder of the project's root
		ofstream ofs(nam.c_str());
		ofs << pairs;
		win.attach(bar_chart);

		win.wait_for_button();


		/*
		Exercise 7
		vector<double> vals = { 9.2, 4,3,1,7,5 };
		Bar_chart bar_chart(vals,orig,xscale,xscale,yscale);
		bar_chart.set_bar_color(0, Color::cyan);
		bar_chart.set_bar_label(1,"ONE");
		bar_chart.set_bar_label(0, "Zero");
		bar_chart.set_bar_label(5, "The last");
		bar_chart.set_chart_label("The chart");
		bar_chart.set_chart_label_color(Color::dark_green);



		const Point orig(xmax / 2, ymax / 2);// The set if you want to have the axis in the middle of the screen
		Axis x_axis(Axis::x, Point(xoffset, orig.y), xlength, number_of_notches, "x asis");
		Axis y_axis(Axis::y, Point(orig.x, ymax - yoffset), ylength, number_of_notches, "y asis"); // Axis goes up from point (ymax-yoffset) = 500, to ylength = 100





			for (int i = 0; i < 30; ++i)
		{
			ostringstream title;
			title << "The estimation of Leibniz series; n==" << i;
			win.set_label(title.str());
			LeibnizN_num_of_terms = i;
			Fct Leibniz(LeibnizN_terms, r_min, r_max, orig, graph_resolution, xscale, yscale, graph_presicion);
			win.attach(Leibniz);
		
			win.detach(Leibniz);
		}





		Exercise 4

	
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

		win.attach(sine);
		win.attach(sine_label);
		win.attach(cosine);
		win.attach(cosine_label);
		win.attach(sine_cosine_square_sum);
		win.attach(sine_cosine_square_sum_label);
		*/


		//Fct homework2(square, r_min, r_max, orig, graph_resolution, xscale, yscale, graph_presicion);
		//homework2.reset_function(pow3); // works
		//homework2.reset_orig(Point(150, 150)); //works

		return 0;
	}
}