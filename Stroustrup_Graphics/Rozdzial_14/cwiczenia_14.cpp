#include "cwiczenia_14.h"

//------------------------------------------------------------------------------

using namespace Graph_lib;

namespace Ex14
{

	
	void Ex1()
	{
		
	}

	void Ex2()
	{
		
	}
	



	void cwiczenia()
	{
		//Ex1();
		//Ex2();

		//Exricise 1
		/*B1 B1_obj;
		B1_obj.f();
		B1_obj.vf();*/

		//Exercise 2
		D1 D1_obj;
		D1_obj.f();
		D1_obj.vf();
		D1_obj.pvf();


		//Exercise 3
		B1& B1_ref = D1_obj;
		B1_ref.vf();
		B1_ref.f();
		B1_ref.pvf();

		

		/*
		//Exercise4
		Results
		B1::f()
		B1::vf()
		B1::f()
		D1::vf()
		D1::vf()
		B1::f()

		after declaring function f() in D1 class
		B1::f()
		B1::vf()
		D1::f()
		D1::vf()
		D1::vf()
		B1::f()
		*/

		//Exercise 6
		D2 D2_obj;
		D2_obj.vf();
		D2_obj.f();
		D2_obj.pvf();
	}





}