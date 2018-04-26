
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities
#include "cwiczenia_13.h"

//------------------------------------------------------------------------------


using namespace Graph_lib;

namespace Ex13
{

	int cwiczenia()
	{
		//Exercise 1
		Point t(100, 100);
		Simple_window win(t, 800, 1000, "Exercises 13");
		
		squares(win);

		//Exercise 2
		Vector_ref<Rectangle> vecs;
		int square_size = 100;
		int count = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				vecs.push_back(new Rectangle(Point(j*square_size, i*square_size), Point((j*square_size) + square_size, (i*square_size) + square_size)));		
				win.attach(vecs[vecs.size() -1]);
				
			}
			vecs[i*8+i].set_fill_color(Color(Color::red));
		}

		//Exercise 3
		vector<Point> points = { Point(400, 0), Point(100,300), Point(400, 600)};
		Image img1(points[0], "200x200.gif");
		Image img2(points[1], "200x200.gif");
		Image img3(points[2], "200x200.gif");
		vector <Image> images;
		for (int i = 0; i < points.size(); ++i)
		{
			
			
			
		}
		win.attach(img1);
		win.attach(img2);
		win.attach(img3);
		

		win.wait_for_button();
		return 0;
	}


	void squares(Simple_window& win)
	{
		


	}
}