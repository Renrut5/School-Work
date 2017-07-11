#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// ======================================================== //
//	Name: 	Andrew Turner									//
//	Class:	CSC601											//
//	Assignment 3											//
//															//
//	CSC601hw3-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: This program will take 100 values	//
// 	input from a file and load them into an array. Then it	//
// 	prints out those values, sorts them from highest to		//
//	lowest and prints them again.							//
//															//
//	Filename: file.txt	(referenced in line 69)				//
//															//
// ======================================================== //

// Constants
const int ARRAY_COUNT = 100;

// Forward declarations of functions
	
// Loads integers from file to an array
void load_array_from_file( int array_to_load[] );
// Prints array to screen
void print_array( int array_to_print[] );
// Sorts array from lowest to highest
void sort_array( int array_to_sort[] );


int main(){
	// variable declarations
	int values[ARRAY_COUNT] = {};
	
	// Load values from file to array
	load_array_from_file( values );
	
	// Print array
	cout << endl << "Unsorted Array: " << endl;
	print_array(values);
	cout << endl;
	
	// Sort array using sort_array() function
	sort_array(values);
	
	// Print array again
	cout << "Array after being sorted: " << endl;
	print_array(values);
	
	return 0;
}


/**
 *	Load external file and load values from file to array.
 *	Array passed by reference in function call
 */
void load_array_from_file( int array_to_load[] ){
	// Local variables
	ifstream infile;
	
	// open the file
	infile.open( "file.txt" );
	
	// Load integer values into array
	for( int x = 0; x < ARRAY_COUNT; x++ ){
		// load values from file to array
		infile >> array_to_load[x];
	}
	
	// close the file
	infile.close();
}


/**
 *	Print array to screen as is.
 */
void print_array( int array_to_print[] ){
	for( int x = 0; x < ARRAY_COUNT ; x++){
		cout << array_to_print[x] << "\t";
		
		// Add line break every 10 integers for readability
		if( (x + 1) % 10 == 0 )
			cout << endl;
		
	}
	cout << endl << endl;
}


/**
 *	Sort array from lowest to highest values.
 *	Sorts array using a 'bubble sort'
 */
void sort_array( int array_to_sort[] ) {
	// sort array using bubble sort
	for( int x = 0; x < ARRAY_COUNT; x++){
		for( int y = x + 1; y < ARRAY_COUNT; y++){
			if(array_to_sort[x] > array_to_sort[y]) {
				swap(array_to_sort[x], array_to_sort[y]);
			} // end if
		}
	} // end lvl one for loop
}
