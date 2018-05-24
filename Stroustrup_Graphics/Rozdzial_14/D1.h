#pragma once

// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities
#include "B1.h"


namespace Ex14
{
	class D1 : B1 // Error can't see the B1 class. No namespace Ex14 on the D1 class.
	{
	public:
		void vf();
		void f();
	};

}
	


	




