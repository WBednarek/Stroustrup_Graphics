#pragma once
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities


namespace Ex14
{
	class B1
	{
	public:
		B1();
		~B1();
	virtual void vf() const;
	void f() const;
	virtual void pvf() const = 0; //Exercise 5. One virtual function creates abstract class - you can't create an object of that class.

	};

}





