
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
		const int grid_size = 8;
		
		squares(win);

		//Exercise 2
		Vector_ref<Rectangle> vecs;
		const int square_size = 100;
		int count = 0;
		for (int i = 0; i < grid_size; ++i)
		{
			for (int j = 0; j < grid_size; ++j)
			{
				vecs.push_back(new Rectangle(Point(j*square_size, i*square_size), Point((j*square_size) + square_size, (i*square_size) + square_size)));		
				win.attach(vecs[vecs.size() -1]);
				
			}
			//Exercise 3
			vecs[i*grid_size+i].set_fill_color(Color::red);
		}

		//Exercise 4 - better solution
		vector<Point> points = { Point(400, 0), Point(100,300), Point(400, 600)};
	
		for (int i = 0; i < points.size(); ++i)
		{
			win.attach(*new Image(points[i], "200x200.gif"));
			
			
		}
		/*
		//Exercise 4 Second solution - worse
		Image *img1 = new Image(points[0], "200x200.gif");
		Image img2(points[1], "200x200.gif");
		Image img3(points[2], "200x200.gif");
		vector <Image> images;
		win.attach(*img1);
		win.attach(img2);
		win.attach(img3);
		*/
		


		//Exercise 5
		while (true)
		{
			win.attach(*new Image(Point(0, 0), "fallout.gif"));
			win.attach(vecs[vecs.size()-1]);
			vecs[vecs.size() -1].set_fill_color(Color::red);
			
			int counter = 1;
			for (int i = 0; i < grid_size; ++i)
			{
				for (int j = 0; j < grid_size; ++j)
				{
					
				    win.attach(*new Image(Point(j*square_size, i*square_size), "fallout.gif"));
					if (counter > 1)
					{
						win.attach(vecs[counter-2]);
						vecs[counter - 2].set_fill_color(Color::red);
						
					}
					++counter;
					win.wait_for_button();
					
				}

			}





			
		}


		
		return 0;
	}


	void squares(Simple_window& win)
	{
		


	}
}