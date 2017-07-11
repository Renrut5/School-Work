#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>
using namespace std;

// ======================================================== //
//	Name: 	Andrew Turner									//
//	Class:	CSC601											//
//	Assignment 4											//
//															//
//	CSC601hw4-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: Employee Management program.		//
//	Displays menu for managing employee records.			//
//	User selects option to perform various employee			//
//	management functions. This program assumes at least		//
//  one employee is on record								//
//															//
//	File Name: employees.txt (Lines: )						//
//															//
// ======================================================== //
const int MAX_EMPLOYEES = 100;

// Employee Structure
struct employee_data {
	int 	employeeID;
	string	firstName,
			lastName,
			jobTitle,
			birthDate,
			hireDate,
			supervisor;
} ;

// Forward declarations of functions
// Forward declarations are in same order their definitions

// displays primary menu
void display_employee_menu(); 

// Functions called from main menu	
	// print all employees on record
	void add_new_employee(employee_data array[]); 
	// Delete a specified employee from records by ID number
	void delete_employee(employee_data array[]);
	// View a list of all employees loaded to the records
	void view_all_employees( employee_data array[] );
	// Save employee data and clear array
	void save_employee_data( employee_data to_save[] );


// Utility Functions
	// Count number of employees in record
	int num_employees( employee_data to_count[] ); 
	// Generate unique ID number
	int generate_employee_number( employee_data array[]); 
	// Load employee data from file
	void load_employee_data(employee_data array[]);
	// Empty employee array
	void empty_employee_array(employee_data array[]);

// Validation functions
	// Verify unique employee number
	int verify_employee_number( employee_data array[], int check );
	// verify input date
	int verify_date( string date ); 
	// verify yes or no only input
	int verify_yes_or_no(string input); 
	
// User input functions
	// gets input from user at menu
	int get_menu_selection();
	// force user to press enter to continue 
	void press_enter(); 
	// get date from user and validate
	string get_date(); 


// =============================================================== //
// =============================================================== //

int main(){
	// Local Variables
	int selection = 0; // Make sure ghost values are present
	
	employee_data employees[MAX_EMPLOYEES] = {};
	
	// Load Array
	load_employee_data(employees);
	
	// ================= //
	//   BEGIN PROGRAM 	 //
	// ================= //
	while (selection != 5) {
		// User select option
		display_employee_menu();
		
		// Get input and validate
		selection = get_menu_selection();
		
		// Load function based on input
		// Input is validated before this point
		switch(selection){
			case 1:
				add_new_employee( employees );
				break;
			case 2: // Erase Employee
				delete_employee( employees );
				break;
			case 3:
				view_all_employees( employees );
				break;
			case 4: // Save changes
				save_employee_data( employees );
				break;
			// No default
			// Validation on input ensures proper selection is made
		}
		
		// Stay in loop until user selects exit	
	};
	
	return 0;
}

// Display a menu to the user with a list of options.
void display_employee_menu(){
	cout << endl << "Select an option:" << endl;
	cout << "1 - Enter New Employee" << endl;
	cout << "2 - Erase Employee" << endl;
	cout << "3 - View all employees" << endl;
	cout << "4 - Save changes" << endl;
	cout << "5 - Exit (Changes will not be saved)" << endl;
	cout << endl;
} // end display_employee_menu();

// =============================================================== //
// MENU OPTION FUNCTIONS
// =============================================================== //

// Add new employee to records
void add_new_employee(employee_data array[]){
	int employeeNumber, arrayNumber;
	
	string 	input,
			firstName,
			lastName,
			jobTitle,
			birthDate,
			hireDate,
			supervisor, 
			save;
	
	// Get employee Info
	cout << "Enter a new employee." << endl;
	
	cout << "First Name: ";
	getline(cin, firstName);
	
	cout << "Last Name: ";
	getline(cin, lastName);
	
	cout <<"Job Title: ";
	getline(cin, jobTitle);
	
	cout << "Birth Date: ";
	birthDate = get_date();
	
	cout << "Hire Date: ";
	hireDate = get_date();
	
	cout << "Supervisor: ";
	getline(cin, supervisor);
	
	
	// Generate employee Number
	employeeNumber = generate_employee_number( array );
	
	// Display employee info to user
	
	// Confirm Employee Save
	cout << "Save employee data? Y / N" << endl;
	getline(cin, save);
	
	// Verify yes or no input
	while( verify_yes_or_no(save) == 0 ){
		cout << "Invalid input, please try again. ";
		getline(cin, save);
	}
	
	if( save.compare("Y") == 0 || save.compare("y") ){
		// Save employee to active array
		
		// Ensure it doesn't copy over current array value
		arrayNumber = num_employees(array) + 1;
		
		array[arrayNumber].employeeID = employeeNumber;
		array[arrayNumber].firstName = firstName;
		array[arrayNumber].lastName = lastName;
		array[arrayNumber].jobTitle = jobTitle;
		array[arrayNumber].birthDate = birthDate;
		array[arrayNumber].hireDate = hireDate;
		array[arrayNumber].supervisor = supervisor;
	
		cout << "Employee data saved. ";
		press_enter();
	
	}
}

// =============================================================== //

// Delete employee from records
void delete_employee(employee_data array[]){
	// Local variables
	int deleteByID = 0, 
		arrayPos = -1; // negative number ensures employee won't be accidentally deleted
	string input, confirm;
	
	// Check if employees array is loaded
	if( num_employees(array) == 0 ) {
		load_employee_data(array);
		
		// If array still not loaded
		if(num_employees(array) == 0) {
			cout << "No Employees on file. ";
			press_enter();
			return;
		}
		
	}
	
	// User input: Select Employee to erase
	cout << "Delete employee by ID: ";
	getline(cin, input);
	stringstream(input) >> deleteByID;
	
	for(int x = 0; x < MAX_EMPLOYEES; x++){
		if(array[x].employeeID == deleteByID){
			arrayPos = x;
		}
	}
	
	// Exit function if no employee record found
	if( arrayPos == -1 ){
		cout << "No employee record found. ";
		press_enter();
		return;
	}
	
	// Confirm erase employee
	cout << "Are you sure you want to remove " << array[arrayPos].firstName
		 << " " << array[arrayPos].lastName << " from record? (Y / N) ";
	getline(cin, confirm);
	
	// Verify yes or no input
	while( verify_yes_or_no(confirm) == 0 ){
		cout << "Invalid input, please try again. ";
		getline(cin, confirm);
	}
	
	
	// Remove employee from array
	if(confirm.compare("Y") == 0 || confirm.compare("y") == 0){
		array[arrayPos].employeeID = 0;
		array[arrayPos].firstName = "";
		array[arrayPos].lastName = "";
		array[arrayPos].jobTitle = "";
		array[arrayPos].birthDate = "";
		array[arrayPos].hireDate = "";
		array[arrayPos].supervisor = "";
	
		cout << "Employee removed from records. ";
		press_enter();
	}
	
	
}

// =============================================================== //

// Check if employees array is loaded and print all employees to the screen
void view_all_employees( employee_data emp_array[] ){
	
	// Check if employees array is loaded
	if( num_employees(emp_array) == 0 ) {
		load_employee_data(emp_array);
		
		// If array still not loaded
		if(num_employees(emp_array) == 0) {
			cout << "No Employees on file.";
			press_enter();
			return;
		}
		
	}
	
	for( int x = 0; x < MAX_EMPLOYEES; x++){
		// Move to the next iteration if emp_array[x] is not loaded
		if( emp_array[x].employeeID != 0){
			cout << "Employee ID: \t" << emp_array[x].employeeID << endl;
			cout << "Employee Name: \t" << emp_array[x].firstName 
				 << " " << emp_array[x].lastName << endl;
			cout << "Job Title: \t" << emp_array[x].jobTitle << endl;
			cout << "Birth Date: \t" << emp_array[x].birthDate << endl;
			cout << "Hire Date: \t" << emp_array[x].hireDate << endl;
			cout << "Supervisor: \t" << emp_array[x].supervisor << endl;
			
			cout << endl;
		}
	}
	
	press_enter();
	return;
	
}

// =============================================================== //

// Save employee data from structure array to file
void save_employee_data( employee_data to_save[] ){
	// Local Variables
	
	// Prevent program from saving to
	if(num_employees(to_save) == 0){
		cout << "Unable to save, no employees found in memory. " << endl;
		press_enter();
		return;
	}
	
	ofstream outfile;
	
	// Open File
	outfile.open("employees.txt", ios::trunc);
	
	// Save array to file (save over old)
	for(int x = 0; x < MAX_EMPLOYEES; x++){
		// Save only if employee record is found in array position
		if( to_save[x].employeeID != 0){
			outfile << to_save[x].employeeID << ":";
			outfile << to_save[x].firstName << ":";
			outfile << to_save[x].lastName << ":";
			outfile << to_save[x].jobTitle << ":";
			outfile << to_save[x].birthDate << ":";
			outfile << to_save[x].hireDate << ":";
			outfile << to_save[x].supervisor << ":";
			outfile << "\n";
		}
	}
	
	// Erase current memory
	empty_employee_array(to_save);
	
	// Close File
	outfile.close();
	
	cout << endl << "Employees saved to file. ";
	press_enter();
}

// =============================================================== //
// END MENU OPTIONS
// =============================================================== //


// =============================================================== //
// BEGIN UTILITY FUNCTIONS
// =============================================================== //

// Counts number of employees in array
int num_employees( employee_data to_count[] ){
	int employee_count = 0;
	
	for( int x = 0; x < MAX_EMPLOYEES; x++){
		if (to_count[x].employeeID != 0){
			employee_count++;
		} 
	}
	
	return employee_count;
}

// =============================================================== //

// Generate new employee number
int generate_employee_number( employee_data array[]){
	int employeeNumber = 100;
	
	while( verify_employee_number(array, employeeNumber) == 0 ){
		employeeNumber++;
	}
	
	
	return employeeNumber;
}

// =============================================================== //

// Loads employee data from file to structure array
void load_employee_data(employee_data array[]){
	ifstream infile;
	string temp, input, employee;
	int pos, npos, x = 0;
	
	infile.open("employees.txt");
	
	// Load data from file to array
	while( !infile.eof() && x < MAX_EMPLOYEES ){
		// Initialize pos variable
		pos = 0;
		
		// Load the employee line from file
		getline(infile, input);
		
		// ===================================== //
		// Save employee data to array from file //
		// ===================================== //
		
		// Employee ID
		npos = input.find(':');
		// Convert string from Employee ID to int
		stringstream(input.substr(pos, npos)) >> array[x].employeeID;
		
		// First Name
		pos = npos + 1;
		npos = input.find(':', pos);
		array[x].firstName = input.substr(pos, npos - pos);
		
		// Last Name
		pos = npos + 1;
		npos = input.find(':', pos);
		array[x].lastName = input.substr(pos, npos - pos);
		
		// Job Title
		pos = npos + 1;
		npos = input.find(':', pos);
		array[x].jobTitle = input.substr(pos, npos - pos);
		
		// Birth Date
		pos = npos + 1;
		npos = input.find(':', pos);
		array[x].birthDate = input.substr(pos, npos - pos);
		
		// Hire Date
		pos = npos + 1;
		npos = input.find(':', pos);
		array[x].hireDate = input.substr(pos, npos - pos);
		
		// Supervisor
		pos = npos + 1;
		npos = input.find(':', pos);
		array[x].supervisor = input.substr(pos, npos - pos);
		
		// END OF EMPLOYEE RECORD
		
		// Move to next array location
		x++;
	}
	
	infile.close();
	return;
}

// =============================================================== //

// Clear employee structure array
void empty_employee_array(employee_data array[]){
	for(int x = 0; x < MAX_EMPLOYEES; x++){
		// Pass array positions without data, 
		// no need to delete something that isn't there
		if(array[x].employeeID != 0){
			array[x].employeeID = 0;
			array[x].firstName = "";
			array[x].lastName = "";
			array[x].jobTitle = "";
			array[x].birthDate = "";
			array[x].hireDate = "";
			array[x].supervisor = "";
		}
	}	
}

// =============================================================== //
// END UTILITY FUNCTIONS
// =============================================================== //

// =============================================================== //
// BEGIN VALIDATION FUNCTIONS
// =============================================================== //

// Verify generated employee number is unique
int verify_employee_number( employee_data array[], int check ){
	int verified = 1;
	
	for(int x = 0; x < MAX_EMPLOYEES; x++){
		if (array[x].employeeID == check){
			verified = 0;
		}
	}
	
	return verified;
}

// =============================================================== //

// Verify date input is valid
int verify_date( string date ){
	int verified = 1;
	
	// Ensure string length is correct
	if(date.length() != 10){
		verified = 0;
	}
	
	// Format must be mm/dd/yyyy
	char * cstr = new char [11];
	strcpy (cstr, date.c_str());
	
	// Check each character of string
	for( int x = 0; x < 10; x++){
		if( (x == 2) || (x == 5) ){
			if(cstr[x] != '/'){
				verified = 0;
			}
			} else {
				if( isdigit(cstr[x]) == 0 ){
					verified = 0;
				}
		} // end if
	} // end for
	
	return verified;
}

// =============================================================== //

// Verify input for Y or N input
int verify_yes_or_no(string input){
	int verified = 0;
	if( input.compare("Y") == 0 || input.compare("y") == 0 ||
		input.compare("N") == 0 || input.compare("n") == 0){
		verified = 1;
	}
	
	return verified;
}

// =============================================================== //
// END VALIDATION FUNCTIONS
// =============================================================== //

// =============================================================== //
// BEGIN USER INPUT FUNCTIONS
// =============================================================== //

// Takes menu selection from user and validates
int get_menu_selection(){
	int input, valid;
	string string_input;
	
	// Zero out input
	input = 0;
	
	cout << "Selection: ";
	getline(cin, string_input);
	stringstream (string_input) >> input;
	
	// Validate Input
	valid = 0;
	do {
		// Test input
		if ( input > 0 && input <= 5 ){
			valid = 1;
		}
		
		// If input is invalid
		if(valid == 0){
			cout << "Invalid input. Please try again: ";
			getline(cin, string_input);
			stringstream (string_input) >> input;
		}
		
	} while ( valid != 1);
	
	return input;
}

// =============================================================== //

// Pauses program and requires user to press enter in order to continue
void press_enter(){
	string press_enter;
	
	cout << endl << "Press enter to continue.";
	getline(cin, press_enter);
}

// =============================================================== //

// Get a date input from user and validate format
string get_date(){
	// Does not start with a cout command
	string input;
	getline(cin, input);
	
	while(verify_date( input ) == 0){
		cout << "Invalid format. Try again with format 'mm/dd/yyyy.'" << endl;
		getline(cin, input);
	}
	
	return input;
}

// =============================================================== //
// END USER INPUT FUNCTIONS
// =============================================================== //
