# Stroustrup_Graphics

FLTK for already cloned code Visual Studio 2019 Community
(for description with images see the Word document)

1.	Log in to you github on VS2019. Clone the project, be careful clone the whole project that includes (Chapter12, Stroustrup_Graphics, and other files).
2.	Clone repository and open. If you cant see files of your project go to Widok -> Ekplorator rozwiazan
3.	Unzip fltk-1.1.10-source.zip
4.	Run fltk-1.1.10 ->visualc ->fltk.dsw. Important wait until it ends and then build a project that was open by fltk.dsw. Without building the project you won’t get needed files to FLTK folder. Do not worry about errors after the build.
5.	Close Visual studio
6.	Here is the change from VS 2015! Copy all files from fltk-1.1.10\lib folder apart from README.lib to C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\VS\lib\x64
And 
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\VS\lib\x86
7.	Copy FL folder to C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\VS\include
8.	Open Visual Studio and make sure you see files from Stroustrup_Graphics.sln view. To be sure double click on this file in VS. Or in explorator panel on the top click Przełacz widoki -> Stroustrup_Graphics.sln
 
9.	Right-click on the project name (the second from the bottom on list, Stroustrup_Graphics) then Properties (Właściwości) -> Linker (Konsolidator) ->Input (dane wejściowe) and pate the following at the beginning with colons

fltkd.lib;wsock32.lib;comctl32.lib;fltkjpegd.lib;fltkimagesd.lib;


10.	In a field ignore specific library (Ignoruj określone biblioteki domyślne) make sure there is libcd.lib

11.	In Properties -> C/C++->Code generation (generowanie kodu) -> Runtime library (Biblioteka środowiska uruchomieniowego) make sure there is Multi-threaded Debug DLL (/MDd) (Wielowątkowe debugowanie biblioteki DLL (/MDd) )


12.	Run using x86 Debug mode (depends on your Visual Studio most likely)

13.	Now it should work








FLTK installation with Visual Studio 2015

Other useful tutorials:
http://courses.cs.tamu.edu/daugher/cpsc121/10fall/Documentation/fltk06c.html, last access 13.04.2018
http://www.c-jump.com/bcc/common/Talk2/Cxx/FltkInstallVC/FltkInstallVC.html, last access 13.04.2018

!!! I was using here fltk-1.1.10 version (fltk-1.1.10-source.zip).
Do Everything as described in Stroustrup Programming: Principles and Practice Using (PPP) book, Dodatek D or above mentioned tutorials. 

If you were following the book instructions there are couple things that need to be mentioned.

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
