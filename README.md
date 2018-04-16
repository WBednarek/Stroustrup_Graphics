# Stroustrup_Graphics

FLTK installation with Visual Studio 2015

!!! I was using here fltk-1.1.10 version (fltk-1.1.10-source.zip).

Do Everything as described in Stroustrup Programming: Principles and Practice Using (PPP) book, Dodatek D. But there are couple things that need to be mentioned.

1.	fltk.dsw file is in visualc folder, not in the vc2005 or vnet as it was described in Stroustrup PPP dodatek D. 
But you may use fltk.sln from vc2005 file as well (not tested). 

2.	After Creation project in Visual stidio add some .cpp file (e.g. main.cpp) otherwise you won’t see „C/C++” section in Properties.

3.	Crucial part!!! 
In the step Properties->Linker-> Additional dependencies when you are adding files:
fltkd.lib wsock32.lib comctl32.lib fltkjpegd.lib fltkimagesd.lib
Also add:
Properties->Linker-> Ignore specific default libraries -> add libcd.lib
make sure that every of that is separated with semicolon ‘;’. Do not erase .libs that were there

You should have something like this:
kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;fltkd.lib; wsock32.lib; comctl32.lib; fltkjpegd.lib; fltkimagesd.lib;%(AdditionalDependencies)
 
If you are adding those files by Properties->Linker-> Additional dependencies->Edit
You should separate all .lib files with semicolon as well or with a new line.
 

RUN A CODE FROM THE BOOK

1.	Go to:
http://www.stroustrup.com/Programming/
and download Complete collection of code fragments for the 1st edition (revised) package
2.	Unzip and go to the GUI folder
3.	Copy everything to your project directory (           )
4.	Replace “std_lib_facilities.h with its newer version from:
http://www.stroustrup.com/Programming/PPP2code/std_lib_facilities.h
5.	Include those .h files and .cpp files into the project. 
For .h files right click on Header Files -> Add -> Existing item… -> select all (five) h. files
For .cpp files right click on Source Files -> Add -> Existing item… -> select all (three excluding main.cpp) .cpp files


 
6.	In the Graph.cpp file replace the code
bool can_open(const string& s)
// check if a file named s exists and can be opened for reading
{
    ifstream ff(s.c_str());
    return ff;
}

with

bool can_open(const string& s)
// check if a file named s exists and can be opened for reading
{
    ifstream ff(s.c_str());
	return static_cast<bool>(ff);
}
