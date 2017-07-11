#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

// ======================================================== //
//	Name: 	Andrew Turner									//
//	Class:	CSC601											//
//	Assignment ###											//
//															//
//	CSC601hw5-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: This program uses a class			//
// 	to create a cube object. It then goes through a 		//
//	series of tests to ensure the class is working			//
//	properly.												//
//															//
//	This file is the 2nd (and correct) submission.			//
//															//
// ======================================================== //


// Forward declarations of functions


// Cube Class
class cube {
	private:
		double length;
		double width;
		double height;
	public:
		// Cube default constructor
		cube(){
			// Default Values to zero
			this->length 	= 0;
			this->width 	= 0;
			this->height 	= 0;
		}
		
		// Constructer with set values
		cube(double length, double width, double height){
			this->length 	= length;
			this->width		= width;
			this->height 	= height;
		}
		
		// Get Volume
		// Formula: length * width * height
		double getVolume(){
			return this->length * this->width * this->height;
		}
		
		// Get Surface Area
		// Formula: 2(lh) * 2(lw) * 2(wh)
		double getSurfaceArea(){
			return (2 * (this->length * this->height)) 
			+ (2 * (this->length * this->width)) 
			+ (2 * (this->width * this->height));
		}
		
		// Display values of cube
		void displayValues(){
			cout << endl;
			cout << "Length:\t \t" << this->length << endl;
			cout << "Width:\t \t" << this->width << endl;
			cout << "Height:\t \t" << this->height << endl;
			cout << "Volume:\t \t" << this->getVolume() << endl;
			cout << "Surface Area:\t" << this->getSurfaceArea() << endl;
		}
		
		// =============== //
		// Class Operators //
		// =============== //
		
		// Decrement each property by one
		cube operator-- ( int ) {
			cube temp(length, width, height);
			
			length--;
			if(length < 0)
				length = 0;
				
			width--;
			if(width < 0)
				width = 0;
			
			height--;
			if(height < 0)
				height = 0;
			
			return temp;
			
		}
		
		// Increment each property by one
		cube operator++ ( int ) { 
			cube temp(length, width, height); 
			width++; 
			length++;
			height++; 
			return temp; 
		}
		
		// Increment each property by specified amount
		cube operator+= ( double inc ) {
			cube temp(length, width, height);
			
			length += inc;
			width  += inc;
			height += inc;
			
			return temp;
		}
		
		// Decrement each property by specified amount
		cube operator-= ( double dec ) {
			cube temp(length, width, height);
			
			length -= dec;
			if(length < 0)
				length = 0;
			
			width  -= dec;
			if(width < 0)
				width = 0;
			
			height -= dec;
			if(height < 0)
				height = 0;
			
			return temp;
		}
		
};

int main(){
	cube cube1, cube2(10.235,10.235,10.235);
	
	// Test 1
	// Create cube with default constructor; display default values
	// Increment and decrement, display after each action.
	cout << "========================" << endl;
	
	// Initial test, values should be all zeros
	cout << "Cube Test 1: " << endl << endl;
	
	cout << "Display initial values from default construtor:";
 	cube1.displayValues();
	
	// Decrement by 1
	// Values should not go below zero
	cout << endl << "Decrement by 1 (Values should not be less than zero): ";
	cube1--;
	cube1.displayValues();
	
	// Increment by 1
	// Values should be equal to 1
	cout << endl << "Increment by 1: ";
	cube1++;
	cube1.displayValues();
	
	// Increment by value
	// Value should increase by 3
	cout << endl << "Increment by 3: ";
	cube1 += 3;
	cube1.displayValues();
	
	// Decrement by value
	// Value should decrease by 2
	cout << endl << "Decrement by 2:";
	cube1 -= 2;
	cube1.displayValues();
	
	// Decrement by 10
	// Value cannot be less than zero
	cout << endl << "Decrement by 10 (Should not be less than zero): ";
	cube1 -= 10;
	cube1.displayValues();
	
	cout << "========================" << endl;
	
	cout << endl << "Cube Test 2: " << endl << endl;
	
	cout << "Instantiate cube2 with values 10.235:";
	cube2.displayValues();
	
	// Increment by 1
	cout << endl << "Increment by 1:";
	cube2++;
	cube2.displayValues();
	
	// Decrement by 1
	cout << endl << "Decrement by 1:";
	cube2--;
	cube2.displayValues();
	
	// Increment by 3.8933
	cout << endl << "Increment by 3.8933:";
	cube2 += 3.8933;
	cube2.displayValues();
	
	// Decrement by 4.1283
	cout << endl << "Decrement by 4.1283 (Returns to value 10):";
	cube2 -= 4.1283;
	cube2.displayValues();
	
	// Decrement by 17.3883
	// All values should be 0
	cout << endl << "Decrement by 17.3883 (Should not be less than zero):";
	cube2 -= 17.3883;
	cube2.displayValues();
	
	
	return 0;
}

