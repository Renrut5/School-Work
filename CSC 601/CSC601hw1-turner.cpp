#include <iostream>
using namespace std;

// ======================================================== //
//															//
//	Name: 	Andrew Turner									//
//	Class:	CSC601											//
//	Assignment 1											//
//															//
//	CSC601hw1-turner.cpp									//
//	Complier Used: Apple LLVM version 5.1 (clang-503.0.40)	//
//															//
//	Program Description: This program will display 			//
//	information regarding my undergraduate degree and		//
//	why I chose Computer Science for my Masters Degree.		//
//	Library used is the iostream in order to use the 		//
//	cout function.											//
//															//
// ======================================================== //


int main(){
	// Declare and define int gradYear
	int gradYear = 2012;
		
	// Add a blank line for readability
	cout << endl;
	
	cout << "Name: Andrew Turner" << endl;
	
	// Undergraduate Information
	cout << "Degree: B.S. in Journalism" << endl;
	cout << "Graduation Year: " << gradYear << endl;
	cout << "Institution: South Dakota State University" << endl;
	cout << endl;
	
	// Why I chose a masters degree in CSC
	cout << "I first started college at the South Dakota School" << endl;
	cout << "of Mines & technology pursuing a degree in Computer Engineering." << endl;
	cout << "Due to life situations, I ended up graduating with a degree" << endl;
	cout << "in Journalism. I was able to start learning to code with PHP in" << endl;
	cout << "my full-time job and decided I wanted to get a formal education" << endl;
	cout << "after starting with object oriented programming and MVC frameworks." << endl;
	
	// End with another blank line for readability
	cout << endl;
	return 0;
}
