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

	const int xscale = 20;
	const int yscale = 20;

	const int r_min = -10;
	const int r_max = 11;

	const int scaled_length = abs(r_min - r_max) - 1; // length of 20 on axis which is eqivalent of 400 pixels (I think...)

	const Point orig(xmax / 2, ymax / 2);

	double ones(double )
	{
		return 1;
	}

	double slope(double x)
	{
		return x / 2;
	}

	double square(double x)
	{
		return x * x;
	}

	double sloping_cos(double x)
	{
		return cos(x) + slope(x);
	}



	inline void error(string s)
	{
		throw std::runtime_error(s);
	}


	struct Person
	{
	private:
		int age1;
		string name1;
	public:
		string name() const
		{
			return name1;
		}
		int age() const
		{
			return age1;
		}
		
		Person();
		Person(string name_c, int age_c);
		~Person();
	

	};

	istream& operator>>(istream& is, Person& per)
	{
		string name;
		int age;
		char ch;
		is >> name >> ch >> age;
		if (!is) return is;
		if (ch != ',')
		{
			is.clear(ios_base::failbit);
			return is;
		}
		per = Person(name, age);
		return is;

	}

	ostream& operator<<(ostream& os, Person per)
	{
		return os << "name: " << per.name() << "\nage: " << per.age() << std::endl;
	}



	Person::Person() {}
	Person::Person(string name_c, int age_c) : name1(name_c), age1(age_c) 
	{
		if (age1 < 0 || age1 >149)
			error("age is smaller than 0 or bigger than 149");
		for (int i = 0; i < name1.size(); ++i)
		{
			switch (name1[i])
			{
			case ';': case ':': case '"': case '\'' : 
			case '[' : case ']': case '*' : case '&' : 
			case '^' : case '%': case '$' : case '#': 
			case '@': case '!' :
					error("Not allowed symol occured in the name ; : \" \' [ ] * & ^ % $ # @ ! ");
			default:
				break;
			}
		}
	}
	Person::~Person() {}
	


	int exercises()
	{
		
		/*
		Simple_window win(Point(100, 100), 600, 600, "Wykresy funkcji");

		Axis x(Axis::x, Point(xoffset, xmax/2), xlength, 20, "1 == 20 pikseli"); // In Point() xoffset shows where the x segment (axix) starts from the left side of a window, the second parameter shows how "high" the asix should be placed - here is 300 pixels
		Axis y(Axis::y, Point(ymax/2, ymax - yoffset), ylength, 20, "1 == 20 pikseli"); // In Point() the second parameter is where y asix ends, we counting from the top of the window
		x.set_color(Color::red);
		y.set_color(Color::red);
		
		
		Function one(ones, r_min, r_max, orig, 400, xscale, yscale); // count argument is for 
		Function slope_graph(slope, r_min, r_max, orig, 400, xscale, yscale);
		Text slope_label(Point(xmax - xoffset, slope(xlength) + 20), "x/2"); // +20 pixels below end of line of x/2 slope
		Function square_graph(square, r_min, r_max, orig, 400, xscale,yscale); 
		Function cos_graph(cos, r_min, r_max, orig, 400, xscale, yscale);
		cos_graph.set_color(Color::blue); // exrcise 8 from the second set
		Function sloping_sos_graph(sloping_cos, r_min, r_max, orig, 400, xscale, yscale); // exrcise 9 from the second set
		
		win.attach(x);
		win.attach(y);
		win.attach(one);
		win.attach(slope_graph);
		win.attach(slope_label);
		win.attach(square_graph);
		win.attach(cos_graph);
		win.attach(sloping_sos_graph);
		win.wait_for_button();
		*/

		Person person("Goofy", 67); //exercise 3
		//cout << "name: " << person.name << "\nage: " << person.age << endl; //exercise 3
		cout << person << std::endl; ;
		Person person2;
		cout << "Insert new person, format: name, age" << endl;
		
		cin >> person2;
		cout << person2;

		

		return 0;
	}

}


