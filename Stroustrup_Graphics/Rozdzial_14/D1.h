#pragma once

// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
#include "../Simple_window.h"    // get access to our window library
#include "../Graph.h"            // get access to our graphics library facilities
#include "B1.h"


namespace Ex14
{
	class D1 : public B1 // Okay
	{
	public:
		void vf() const;
		void f() const;
		void pvf() const;
	};

}
	


	




