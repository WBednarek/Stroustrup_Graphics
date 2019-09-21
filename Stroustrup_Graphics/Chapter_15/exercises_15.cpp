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
		string first_name1;
		string last_name1;
	public:
		string first_name() const
		{
			return first_name1;
		}
		string last_name() const
		{
			return last_name1;
		}


		int age() const
		{
			return age1;
		}
		
		Person();
		Person(string first_name_c, string last_name_c, int age_c);
		~Person();
	

	};


	void find_wrong_symbols(const string& name)
	{
		for (int i = 0; i < name.size(); ++i)
		{
			switch (name[i])
			{
			case ';': case ':': case '"': case '\'':
			case '[': case ']': case '*': case '&':
			case '^': case '%': case '$': case '#':
			case '@': case '!': case ',': // I added the ',' to the code for distinct the name with the separator , (comma)
				error("Not allowed symol occured in the name ; : \" \' [ ] * & ^ % $ # @ ! ");
			default:
				break;
			}

		}
	}

	
	
	istream& operator>>(istream& is, Person& per)
	{
		string first_name = "";
		string last_name = "";
		int age;
		char ch1, ch2;
		is >> first_name >> last_name;
		find_wrong_symbols(first_name);
		find_wrong_symbols(last_name);
		
		is >> ch1 >> age >> ch2;
		if (ch1 != ',' || ch2 != ';')
		{
			is.unget();
			is.clear(ios_base::failbit);
			return is;
		}

		
		per = Person(first_name, last_name, age);
		return is;

	}
	


	ostream& operator<<(ostream& os, Person per)
	{
		return os << "name: " << per.first_name() << " " <<per.last_name() << "\nage: " << per.age() << std::endl;
	}

	ostream& operator<<(ostream& os, vector<Person>& person_vec)
	{
		for (int i = 0; i < person_vec.size(); ++i)
		{
			os << "Person " << i+1 << "\nName: " << person_vec[i].first_name() << " " << person_vec[i].last_name()
				<< "\nAge: " << person_vec[i].age() << "\n\n";
		}

		return os;
	}

	vector<Person> get_persons(const string& communicate, const char termination)
	{
		vector<Person> persons;
		Person p;
		
		cout << communicate << endl;
		while (cin >> p) persons.push_back(p);
		
		if (cin.eof()) return persons;
		if (cin.bad()) error("Stream persons is broken");
		if (cin.fail())
		{
			cin.clear();
			char c;
			cin >> c;
			if (c = !termination)
				cin.clear(ios_base::failbit);
		}
		return persons;
	}


	Person::Person() {}
	Person::Person(string first_name_c, string last_name_c, int age_c) : first_name1(first_name_c), last_name1(last_name_c), age1(age_c) 
	{
		if (age1 < 0 || age1 >149)
			error("age is smaller than 0 or bigger than 149");
		find_wrong_symbols(first_name1);
		find_wrong_symbols(last_name1);
	}
	Person::~Person() {}
	
	
	const char& termination_sign()
	{
		const static char termination = '-';
		return termination;
	}

	
	const static char termination = '?';

	int exercises()
	{
		

		string communicate = "Insert new persons, format: name [space] , [space] age; name1 [space] , [space] age2; ...\ntermination sign is "  ;
		communicate.push_back(termination);
		vector<Person> persons; //exercise 9
		persons = get_persons(communicate,termination);
			
		cout << persons;

		return 0;




		/*
istream& operator>> (istream& is, vector<Person>& person_vec)
{
	while (is)
	{
		string name;
		int age;
		char ch1;
		is >> name >> ch1 >> age;
		if (ch1 != ',')
		{
			is.unget();
			is.clear(ios_base::failbit);
			return is;
		}

		char ch2;
		is >> ch2;
		if (ch2 != ';')
		{
			is.unget();
			is.clear(ios_base::failbit);
			return is;
		}

		person_vec.push_back(Person(name, age));
		return is;

	}
}
*/



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
		/*
		Person person("Goofy", 67); //exercise 3
		cout << "name: " << person.name << "\nage: " << person.age << endl; //exercise 3
		cout << person << std::endl; ;
		Person person2;
		cout << "Insert new person, format: name, age" << endl;

		cin >> person2;
		cout << person2;

		*/



	}

}


