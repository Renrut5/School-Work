#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// ======================================================== //
//															//
//	Name: 	Andrew Turner									//
//	Class:	CSC601											//
//	Assignment CSC601hw2-turner.cpp							//
//															//
//	CSC601hw2-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: This program receives 10 integer	//
// 	from the user and determines the highest value, the		//
//	lowest value, and the average of all 10 integers.		//
//															//
// ======================================================== //


// Reference functions in program
int check_input(int check);

int main(){
	// Declare variables
	string string_input;
	int from_user, max, min;
	float avg, total;
	
	// Zero out total at beginning of program
	total = 0;
	
	cout << endl;
	cout << "Enter ten integers greater than zero:" << endl;
	
	// Loop through user inputs and store values where needed
	for(int i = 1; i <= 10; i++ ){
		// Set from_user to 0 so it doesn't use previous value
		from_user = 0;
		
		// Get user input
		cout << "Integer " << i << ": ";
		getline(cin, string_input); 
 		stringstream( string_input ) >> from_user; 
		
		/*
		 *	Validate user input.
		 *	If input is invalid, re-enter input.
		 *	Stays in while loop as long as input is invalid.
		 *	Will not enter loop if user input is valid.
		 */
		while ( check_input(from_user) != 1 ){
			// Set from_user to 0 so it doesn't use previous value 
			from_user = 0;
			
			// User input invalid, try again
			cout << "The value you entered is not accepted. Please try again." << endl;
			cout << "Integer " << i << ": ";
			getline(cin, string_input); 
 			stringstream( string_input ) >> from_user; 
		} // end while
		
		// ============================ //
		// USER INPUT IS NOW VALIDATED	//
		// ============================ //
		
		// Add input to total
		total += from_user;
		
		// Determine max/min
		if ( i == 1 ){
			// Sets max and min values if first time in loop
			max = from_user;
			min = from_user;
		} else {
			if( from_user > max )
				max = from_user;
			if( from_user < min )
				min = from_user;	
		}
	} // end for
	
	// Average the numbers
	avg = total / 10;
	
	// Print results
	cout << endl;
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	cout << "Avg: " << avg << endl;
	
	return 0;
} 	// END int main()

/*
 *	int function check_input( int check );
 *
 *	Check the value of the user input to ensure it meets
 *	specific criteria.
 *
 *	@return: 1 - Input validated
 *	@return: 0 - Input invalid, try again
 */
int check_input(int check){
	int valid;
	
	// User input must be an integer greater than zero.
	if ( check <= 0 )
		valid = 0;
	else
		valid = 1;
	
	return valid;
}
