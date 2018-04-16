
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities
#include "cwiczenia.h"

//------------------------------------------------------------------------------


namespace Ex12
{

	int cwiczenia()
	{

		//Exercise 1
		/*
		using namespace Graph_lib;   // our graphics facilities are in Graph_lib
		Point tl(300, 651);           // to become top left  corner of window
		Simple_window win(tl, 600, 400, "Moje okno");    // make a simple window
		win.wait_for_button();       // give control to the display engine
		*/


		//
		//// This is example code from Chapter 12.3 "A first example" of
		//using namespace Graph_lib;   // our graphics facilities are in Graph_lib
		//Point tl(100, 100);           // to become top left  corner of window
		//Simple_window win(tl, 600, 400, "SZEW");    // make a simple window
		//Polygon poly;                // make a shape (a polygon)
		//poly.add(Point(300, 200));    // add a point
		//poly.add(Point(350, 100));    // add another point
		//poly.add(Point(400, 200));    // add a third point
		//poly.set_color(Color::red);  // adjust properties of poly
		//win.attach(poly);           // connect poly to the window
		//win.wait_for_button();       // give control to the display engine
		

		//Exercise 2


		
		////12.7.2
		//try
		//{
		//	Point tl000(100, 100);     // top-left corner of our window

		//	Simple_window win(tl000, 800, 900, "Canvas");
		//	// screen coordinate tl for top-left corner
		//	// window size(600*400)
		//	// title: Canvas
		//	win.wait_for_button(); // Display!
		//}
		//catch (exception& e) {
		//	// some error reporting
		//	return 1;
		//}
		//catch (...) {
		//	// some more error reporting
		//	return 2;
		//}

		//return 0;
	

	
	//12.7.3-1
	//try
	//{
	//	Point tl(100, 100);          // top-left corner of our window

	//	Simple_window win(tl, 600, 400, "Canvas");
	//	// screen coordinate tl for top-left corner
	//	// window size(600*400)
	//	// title: Canvas

	//	Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
	//														 // an axis is a kind of Shape
	//														 // Axis::x means horizontal
	//														 // starting at (20,300)
	//														 // 280 pixels long
	//														 // 10 "notches"
	//														 // label the axis "x axis"
	//	win.attach(xa);             // attach xa to the window, win
	//	win.set_label("Canvas Las canvas"); // re-label the window
	//	win.wait_for_button();      // Display!
	//}
	//catch (exception& e) {
	//	// some error reporting
	//	return 1;
	//}
	//catch (...) {
	//	// some more error reporting
	//	return 2;
	//}
	


	
	//12.7.3-2
	//try
	//{
	//	Point tl(100, 100);                   // top-left corner of our window

	//	Simple_window win(tl, 600, 400, "Canvas");
	//	// screen coordinate tl for top-left corner
	//	// window size(600*400)
	//	// title: Canvas

	//	Axis xa(Axis::x, Point(90, 300), 280, 10, "x axis"); // make an Axis
	//														 // an axis is a kind of Shape
	//														 // Axis::x means horizontal
	//														 // starting at (20,300)
	//														 // 280 pixels long
	//														 // 10 "notches"
	//														 // label the axis "x axis"
	//	win.attach(xa);                      // attach xa to the window, win

	//	Axis ya(Axis::y, Point(80, 300), 280, 10, "y axis");
	//	ya.set_color(Color::cyan);           // choose a color
	//	ya.label.set_color(Color::dark_red); // choose a color for the text
	//	win.attach(ya);
	//	win.set_label("Canvas #3");
	//	win.wait_for_button();               // Display!
	//}
	//catch (exception& e) {
	//	// some error reporting
	//	return 1;
	//}
	//catch (...) {
	//	// some more error reporting
	//	return 2;
	//}

	


	
	//12.7.4
	//try
	//{
	//Point tl(100, 100);    // top-left corner of our window

	//Simple_window win(tl, 600, 400, "Canvas");
	//// screen coordinate tl for top-left corner
	//// window size(600*400)
	//// title: Canvas

	//Axis xa(Axis::x, Point(20, 300), 280, 10, "X axis"); // make an Axis
	//// an axis is a kind of Shape
	//// Axis::x means horizontal
	//// starting at (20,300)
	//// 280 pixels long
	//// 10 "notches"
	//// label the axis "x axis"
	//win.attach(xa);                      // attach xa to the window, win

	//Axis ya(Axis::y, Point(20, 300), 280, 10, "Y axis");
	//ya.set_color(Color::Color(210));           // choose a color
	//ya.label.set_color(Color::dark_red); // choose a color for the text
	//win.attach(ya);

	//Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
	//// plot sin() in the range [0:100) with (0,0) at (20,150)
	//// using 1000 points; scale x values *50, scale y values *50
	//win.attach(sine);

	//win.set_label("Canvas #4");
	//win.wait_for_button();               // Display!
	//}
	//catch (exception& e) {
	//// some error reporting
	//return 1;
	//}
	//catch (...) {
	//// some more error reporting
	//return 2;
	//}
	//






////12.7.5
//try
//{
//Point tl(100, 100);    // top-left corner of our window
//
//Simple_window win(tl, 600, 400, "canvas");
//// screen coordinate tl for top-left corner
//// window size(600*400)
//// title: canvas
//
//Axis xa(Axis::x, Point(20, 300), 20, 10, "x axis"); // make an axis
//// an axis is a kind of shape
//// axis::x means horizontal
//// starting at (20,300)
//// 280 pixels long
//// 10 "notches"
//// label the axis "x axis"
//win.attach(xa);                      // attach xa to the window, win
//
//Axis ya(Axis::y, Point(20, 300), 20, 10, "y axis");
//ya.set_color(Color::cyan);           // choose a color
//ya.label.set_color(Color::dark_red); // choose a Color for the text
//win.attach(ya);
//
//Function sine(sin, 0, 100, Point(20, 150), 20, 50, 50);    // sine curve
//// plot sin() in the range [0:100) with (0,0) at (20,150)
//// using 1000 points; scale x values *50, scale y values *50
//win.attach(sine);
//sine.set_color(Color::blue);         // we changed our mind about sine's Color
//
//Polygon poly;                        // a polygon, a polygon is a kind of shape
//poly.add(Point(300, 200));            // three points makes a triangle
//poly.add(Point(350, 100));
//poly.add(Point(400, 200));
//
//poly.set_color(Color::red);
//poly.set_style(Line_style::dash);
//win.attach(poly);
//
//win.set_label("canvas #5");
//win.wait_for_button();               // display!
//}
//catch (exception& e) {
//// some error reporting
//return 1;
//}
//catch (...) {
//// some more error reporting
//return 2;
//}





//12.7.6
//try
//{
//Point tl(100, 100);    // top-left corner of our window
//
//Simple_window win(tl, 600, 400, "Canvas");
//// screen coordinate tl for top-left corner
//// window size(600*400)
//// title: Canvas
//
//Axis xa(Axis::x, Point(20, 300), 70, 10, "x axis"); // make an Axis
//// an axis is a kind of Shape
//// Axis::x means horizontal
//// starting at (20,300)
//// 280 pixels long
//// 10 "notches"
//// label the axis "x axis"
//win.attach(xa);                      // attach xa to the window, win
//
//Axis ya(Axis::y, Point(20, 300), 70, 10, "y axis");
//ya.set_color(Color::cyan);           // choose a color
//ya.label.set_color(Color::dark_red); // choose a color for the text
//win.attach(ya);
//
//Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
//// plot sin() in the range [0:100) with (0,0) at (20,150)
//// using 1000 points; scale x values *50, scale y values *50
//win.attach(sine);
//sine.set_color(Color::blue);         // we changed our mind about sine's color
//
//Polygon poly;                        // a polygon, a Polygon is a kind of Shape
//poly.add(Point(300, 200));            // three points makes a triangle
//poly.add(Point(350, 100));
//poly.add(Point(400, 200));
//
//poly.set_color(Color::red);
//poly.set_style(Line_style::dash);
//win.attach(poly);
//
//Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
//win.attach(r);
//win.set_label("Canvas #6");
//win.wait_for_button();               // Display!
//}
//catch (exception& e) {
//// some error reporting
//return 1;
//}
//catch (...) {
//// some more error reporting
//return 2;
//}




//12.7.6-1
//try
//{
//Point tl(900, 200);    // top-left corner of our window
//
//Simple_window win(tl, 600, 400, "Canvas");
//// screen coordinate tl for top-left corner
//// window size(600*400)
//// title: Canvas
//
//Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
//// an axis is a kind of Shape
//// Axis::x means horizontal
//// starting at (20,300)
//// 280 pixels long
//// 10 "notches"
//// label the axis "x axis"
//win.attach(xa);                      // attach xa to the window, win
//
//Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
//ya.set_color(Color::cyan);           // choose a color
//ya.label.set_color(Color::dark_red); // choose a color for the text
//win.attach(ya);
//
//Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
//// plot sin() in the range [0:100) with (0,0) at (20,150)
//// using 1000 points; scale x values *50, scale y values *50
//win.attach(sine);
//sine.set_color(Color::blue);         // we changed our mind about sine's color
//
//Polygon poly;                        // a polygon, a Polygon is a kind of Shape
//poly.add(Point(300, 200));            // three points makes a triangle
//poly.add(Point(350, 100));
//poly.add(Point(400, 200));
//
//poly.set_color(Color::red);
//poly.set_style(Line_style::dash);
//win.attach(poly);
//
//Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
//win.attach(r);
//
//Closed_polyline poly_rect;
//poly_rect.add(Point(100, 50));
//poly_rect.add(Point(200, 50));
//poly_rect.add(Point(200, 100));
//poly_rect.add(Point(100, 100));
//win.attach(poly_rect);
//
//win.set_label("Canvas #6.1");
//win.wait_for_button();               // Display!
//}
//catch (exception& e) {
//// some error reporting
//return 1;
//}
//catch (...) {
//// some more error reporting
//return 2;
//}





//12.7.6-2
//try
//{
//Point tl(100, 100);    // top-left corner of our window
//
//Simple_window win(tl, 600, 400, "Magneto");
//// screen coordinate tl for top-left corner
//// window size(600*400)
//// title: Canvas
//
//Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
//// an axis is a kind of Shape
//// Axis::x means horizontal
//// starting at (20,300)
//// 280 pixels long
//// 10 "notches"
//// label the axis "x axis"
//win.attach(xa);                      // attach xa to the window, win
//
//Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
//ya.set_color(Color::cyan);           // choose a color
//ya.label.set_color(Color::dark_red); // choose a color for the text
//win.attach(ya);
//
//Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
//// plot sin() in the range [0:100) with (0,0) at (20,150)
//// using 1000 points; scale x values *50, scale y values *50
//win.attach(sine);
//sine.set_color(Color::blue);         // we changed our mind about sine's color
//
//Polygon poly;                        // a polygon, a Polygon is a kind of Shape
//poly.add(Point(300, 200));            // three points makes a triangle
//poly.add(Point(350, 100));
//poly.add(Point(400, 200));
//
//poly.set_color(Color::red);
//poly.set_style(Line_style::dash);
//win.attach(poly);
//
//Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
//win.attach(r);
//
//Closed_polyline poly_rect;
//poly_rect.add(Point(100, 50));
//poly_rect.add(Point(200, 50));
//poly_rect.add(Point(200, 100));
//poly_rect.add(Point(100, 100));
//poly_rect.add(Point(50, 75));
//win.attach(poly_rect);
//
////win.set_label("Canvas #6.2");
//win.wait_for_button();               // Display!
//}
//catch (exception& e) {
//// some error reporting
//return 1;
//}
//catch (...) {
//// some more error reporting
//return 2;
//}




/*
//12.7.7
try
{
Point tl(100, 100);    // top-left corner of our window

Simple_window win(tl, 600, 400, "Canvas");
// screen coordinate tl for top-left corner
// window size(600*400)
// title: Canvas

Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
// an axis is a kind of Shape
// Axis::x means horizontal
// starting at (20,300)
// 280 pixels long
// 10 "notches"
// label the axis "x axis"
win.attach(xa);                      // attach xa to the window, win

Axis ya(Axis::y, Point(20, 300), 280, 25, "y axis");
ya.set_color(Color::cyan);           // choose a color
ya.label.set_color(Color::dark_red); // choose a color for the text
win.attach(ya);

Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
// plot sin() in the range [0:100) with (0,0) at (20,150)
// using 1000 points; scale x values *50, scale y values *50
win.attach(sine);
sine.set_color(Color::blue);         // we changed our mind about sine's color

Polygon poly;                        // a polygon, a Polygon is a kind of Shape
poly.add(Point(300, 200));            // three points makes a triangle
poly.add(Point(350, 100));
poly.add(Point(400, 200));

poly.set_color(Color::red);
poly.set_style(Line_style::dash);
win.attach(poly);

Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
win.attach(r);

Closed_polyline poly_rect;
poly_rect.add(Point(100, 50));
poly_rect.add(Point(200, 50));
poly_rect.add(Point(200, 100));
poly_rect.add(Point(100, 100));
poly_rect.add(Point(50, 75));
win.attach(poly_rect);

r.set_fill_color(Color::yellow);     // color the inside of the rectangle
poly.set_style(Line_style(Line_style::dash, 4));
poly_rect.set_style(Line_style(Line_style::dash, 2));
poly_rect.set_fill_color(Color::green);
win.set_label("Canvas #7");
win.wait_for_button();               // Display!
}
catch (exception& e) {
// some error reporting
return 1;
}
catch (...) {
// some more error reporting
return 2;
}

*/



/*
//12.7.8-1
try
{
Point tl(100, 100);    // top-left corner of our window

Simple_window win(tl, 600, 400, "Canvas");
// screen coordinate tl for top-left corner
// window size(600*400)
// title: Canvas

Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
// an axis is a kind of Shape
// Axis::x means horizontal
// starting at (20,300)
// 280 pixels long
// 10 "notches"
// label the axis "x axis"
win.attach(xa);                      // attach xa to the window, win

Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
ya.set_color(Color::cyan);           // choose a color
ya.label.set_color(Color::dark_red); // choose a color for the text
win.attach(ya);

Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
// plot sin() in the range [0:100) with (0,0) at (20,150)
// using 1000 points; scale x values *50, scale y values *50
win.attach(sine);
sine.set_color(Color::magenta);        // we changed our mind about sine's color

Polygon poly;                        // a polygon, a Polygon is a kind of Shape
poly.add(Point(300, 200));            // three points makes a triangle
poly.add(Point(350, 100));
poly.add(Point(400, 200));

poly.set_color(Color::red);
poly.set_style(Line_style::dash);
win.attach(poly);

Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
win.attach(r);

Closed_polyline poly_rect;
poly_rect.add(Point(100, 50));
poly_rect.add(Point(200, 50));
poly_rect.add(Point(200, 100));
poly_rect.add(Point(100, 100));
poly_rect.add(Point(50, 75));
win.attach(poly_rect);

r.set_fill_color(Color::yellow);    // color the inside of the rectangle
poly.set_style(Line_style(Line_style::dash, 4));
poly_rect.set_style(Line_style(Line_style::dash, 2));
poly_rect.set_fill_color(Color::green);

Text t(Point(150, 150), "Hello, graphical world! ");
win.attach(t);

win.set_label("Canvas #8");
win.wait_for_button();               // Display!
}
catch (exception& e) {
// some error reporting
return 1;
}
catch (...) {
// some more error reporting
return 2;
}
*/



/*
//12.7.8-2
try
{
Point tl(100, 100);    // top-left corner of our window

Simple_window win(tl, 600, 400, "Canvas");
// screen coordinate tl for top-left corner
// window size(600*400)
// title: Canvas

Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
// an axis is a kind of Shape
// Axis::x means horizontal
// starting at (20,300)
// 280 pixels long
// 10 "notches"
// label the axis "x axis"
win.attach(xa);                      // attach xa to the window, win

Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
ya.set_color(Color::cyan);           // choose a color
ya.label.set_color(Color::dark_red); // choose a color for the text
win.attach(ya);

Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
// plot sin() in the range [0:100) with (0,0) at (20,150)
// using 1000 points; scale x values *50, scale y values *50
win.attach(sine);
sine.set_color(Color::blue);         // we changed our mind about sine's color

Polygon poly;                        // a polygon, a Polygon is a kind of Shape
poly.add(Point(300, 200));            // three points makes a triangle
poly.add(Point(350, 100));
poly.add(Point(400, 200));
poly.add(Point(350, 300));

poly.set_color(Color::red);
poly.set_style(Line_style::dash);
win.attach(poly);

Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
win.attach(r);

Closed_polyline poly_rect;
poly_rect.add(Point(100, 50));
poly_rect.add(Point(200, 50));
poly_rect.add(Point(200, 100));
poly_rect.add(Point(100, 100));
poly_rect.add(Point(50, 75));
win.attach(poly_rect);

r.set_fill_color(Color::yellow);    // color the inside of the rectangle
poly.set_style(Line_style(Line_style::dash, 4));
poly_rect.set_style(Line_style(Line_style::dash, 2));
poly_rect.set_fill_color(Color::green);

Text t(Point(150, 150), "Hello, graphical world! ");
win.attach(t);
t.set_font(Font::times_bold);
t.set_font_size(20);

win.set_label("Canvas #9");
win.wait_for_button();               // Display!
}
catch (exception& e) {
// some error reporting
return 1;
}
catch (...) {
// some more error reporting
return 2;
}
*/




/*
//12.7.9-1
try
{
Point tl(100, 100);    // top-left corner of our window

Simple_window win(tl, 600, 480, "Canvas");
// screen coordinate tl for top-left corner
// window size(600*400)
// title: Canvas

Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
// an axis is a kind of Shape
// Axis::x means horizontal
// starting at (20,300)
// 280 pixels long
// 10 "notches"
// label the axis "x axis"
win.attach(xa);                      // attach xa to the window, win

Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
ya.set_color(Color::cyan);           // choose a color
ya.label.set_color(Color::dark_red); // choose a color for the text
win.attach(ya);

Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
// plot sin() in the range [0:100) with (0,0) at (20,150)
// using 1000 points; scale x values *50, scale y values *50
win.attach(sine);
sine.set_color(Color::blue);         // we changed our mind about sine's color

Polygon poly;                        // a polygon, a Polygon is a kind of Shape
poly.add(Point(300, 200));            // three points makes a triangle
poly.add(Point(350, 100));
poly.add(Point(400, 200));

poly.set_color(Color::red);
poly.set_style(Line_style::dash);
win.attach(poly);

Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
win.attach(r);

Closed_polyline poly_rect;
poly_rect.add(Point(100, 50));
poly_rect.add(Point(200, 50));
poly_rect.add(Point(200, 100));
poly_rect.add(Point(100, 100));
poly_rect.add(Point(50, 75));
win.attach(poly_rect);

r.set_fill_color(Color::yellow);    // color the inside of the rectangle
poly.set_style(Line_style(Line_style::dash, 4));
poly_rect.set_style(Line_style(Line_style::dash, 2));
poly_rect.set_fill_color(Color::green);

Text t(Point(150, 150), "Hello, graphical world! ");
win.attach(t);
t.set_font(Font::times_bold);
t.set_font_size(20);

Image ii(Point(100, 50), "image.jpg");    // 400*212 pixel jpg
win.attach(ii);

win.set_label("Canvas #10");
win.wait_for_button();               // Display!
}
catch (exception& e) {
// some error reporting
return 1;
}
catch (...) {
// some more error reporting
return 2;
}
*/



/*


//12.7.9-2
try
{
Point tl(300, 500);    // top-left corner of our window

Simple_window win(tl, 600, 400, "Canvas");
// screen coordinate tl for top-left corner
// window size(600*400)
// title: Canvas

Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
// an axis is a kind of Shape
// Axis::x means horizontal
// starting at (20,300)
// 280 pixels long
// 10 "notches"
// label the axis "x axis"
win.attach(xa);                      // attach xa to the window, win

Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
ya.set_color(Color::cyan);           // choose a color
ya.label.set_color(Color::dark_red); // choose a color for the text
win.attach(ya);

Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
// plot sin() in the range [0:100) with (0,0) at (20,150)
// using 1000 points; scale x values *50, scale y values *50
win.attach(sine);
sine.set_color(Color::blue);         // we changed our mind about sine's color

Polygon poly;                        // a polygon, a Polygon is a kind of Shape
poly.add(Point(300, 200));            // three points makes a triangle
poly.add(Point(350, 100));
poly.add(Point(400, 200));

poly.set_color(Color::red);
poly.set_style(Line_style::dash);
win.attach(poly);

Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
win.attach(r);

Closed_polyline poly_rect;
poly_rect.add(Point(100, 50));
poly_rect.add(Point(200, 50));
poly_rect.add(Point(200, 100));
poly_rect.add(Point(100, 100));
poly_rect.add(Point(50, 75));
win.attach(poly_rect);

r.set_fill_color(Color::yellow);     // color the inside of the rectangle
poly.set_style(Line_style(Line_style::dash, 4));
poly_rect.set_style(Line_style(Line_style::dash, 2));
poly_rect.set_fill_color(Color::green);

Text t(Point(150, 150), "Hello, graphical world! ");
win.attach(t);
t.set_font(Font::times_bold);
t.set_font_size(20);

Image ii(Point(100, 50), "image.jpg"); // 400*212 pixel jpg
win.attach(ii);
ii.move(100, 200);

win.set_label("Canvas #11");
win.wait_for_button();               // Display!
}
catch (exception& e) {
// some error reporting
return 1;
}
catch (...) {
// some more error reporting
return 2;
}
*/




/*


//12.7.10
try
{
Point tl(100, 100);    // top-left corner of our window

Simple_window win(tl, 600, 400, "Canvas");
// screen coordinate tl for top-left corner
// window size(600*400)
// title: Canvas

Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis"); // make an Axis
// an axis is a kind of Shape
// Axis::x means horizontal
// starting at (20,300)
// 280 pixels long
// 10 "notches"
// label the axis "x axis"
win.attach(xa);                      // attach xa to the window, win

Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
ya.set_color(Color::cyan);           // choose a color
ya.label.set_color(Color::dark_red); // choose a color for the text
win.attach(ya);

Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);    // sine curve
// plot sin() in the range [0:100) with (0,0) at (20,150)
// using 1000 points; scale x values *50, scale y values *50
win.attach(sine);
sine.set_color(Color::blue);         // we changed our mind about sine's color

Polygon poly;                        // a polygon, a Polygon is a kind of Shape
poly.add(Point(300, 200));            // three points makes a triangle
poly.add(Point(350, 100));
poly.add(Point(400, 200));

poly.set_color(Color::blue);
poly.set_style(Line_style::dash);
win.attach(poly);

Rectangle r(Point(200, 200), 100, 50);// top-left corner, width, height
win.attach(r);

Closed_polyline poly_rect;
poly_rect.add(Point(100, 50));
poly_rect.add(Point(200, 50));
poly_rect.add(Point(200, 100));
poly_rect.add(Point(100, 100));
poly_rect.add(Point(50, 75));
win.attach(poly_rect);

r.set_fill_color(Color::yellow);     // color the inside of the rectangle
poly.set_style(Line_style(Line_style::dash, 4));
poly_rect.set_style(Line_style(Line_style::dash, 2));
poly_rect.set_fill_color(Color::green);

Text t(Point(150, 150), "Hello, graphical world! ");
win.attach(t);
t.set_font(Font::times_bold);
t.set_font_size(20);

Image ii(Point(100, 50), "image.jpg"); // 400*212 pixel jpg
win.attach(ii);
ii.move(100, 200);

Circle c(Point(100, 200), 50);
Ellipse e(Point(100, 200), 75, 25);
e.set_color(Color::dark_red);
Mark m(Point(100, 200), 'x');

ostringstream oss;
oss << "screen size: " << x_max() << "*" << y_max()
<< "; window size: " << win.x_max() << "*" << win.y_max();
Text sizes(Point(100, 20), oss.str());

Image cal(Point(225, 225), "snow_cpp.gif"); // 320*240 pixel gif
cal.set_mask(Point(40, 40), 200, 150);       // display center part of image

win.attach(c);
win.attach(m);
win.attach(e);

win.attach(sizes);
win.attach(cal);

win.set_label("Canvas #12");
win.wait_for_button();               // Display!
}
catch (exception& e) {
// some error reporting
return 1;
}
catch (...) {
// some more error reporting
return 2;
}
*/





return 0;



	}








	cwiczenia::cwiczenia()
	{
	}


	cwiczenia::~cwiczenia()
	{
	}


}



//------------------------------------------------------------------------------
