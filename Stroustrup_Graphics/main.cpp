//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"    // get access to our window library
#include "Graph.h"            // get access to our graphics library facilities
//#include "Rozdzial_12\cwiczenia.h"
//#include "Rozdzial_13\cwiczenia_13.h"
//#include "Rozdzial_14\cwiczenia_14.h"
//#include "Chapter_15\exercises_15.h"
//#include "Chapter_15\homework_15.h"
//#include "Chapter_16\exercises_16.h"
//#include "Chapter_16/My_window.h"
#include"Chapter_16/homework16_3.h"
#include"Chapter_16/homework16_4.h"
#include"Chapter_16/homework16_5.h"

int main()
{
	system("chcp1250");
	
	try {
		
		H16_5::My_window win(Point(100, 100), 600, 400, "HW16_5");
		return gui_main(); // exercises 16

		/*
		H16_4::My_window win(Point(100, 100), 600, 400, "HW16_4");
		H16_3::My_window win(Point(100, 100), 600, 400, "HW16_3");
		H16::My_window win(Point(100, 100), 600, 400, "HW16");
		Ex16::Lines_window win(Point(100, 100), 600, 400, "Lines");
		H15::homework();
		Ex15::exercises();
		Ex14::cwiczenia();
		Ex13::cwiczenia();
		Ex12::cwiczenia();


		*/

		system("pause");
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1; // exercises 16
		//keep_window_open(); 
	}
	catch (...) {
		cerr << "exception\n";
		return 2; // exercises 16
		//keep_window_open();
	}

	//return 0;
}