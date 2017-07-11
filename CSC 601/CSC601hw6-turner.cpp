#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// ======================================================== //
//	Name: 	Andrew Turner									//
//	Class:	CSC601											//
//	Assignment ###											//
//															//
//	CSC601hw6-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: A program to demonstrate			//
//	class inheritance.										//											
// 															//
// ======================================================== //


// Forward declarations of functions

class entertainment {
	protected:
		string title;
		int year;
		
	public:
		int get_year(){
			return this->year;
		}
		
		void set_year( int input ){
			this->year = input;
		}
		
		string get_title(){
			return this->title;
		}
		
		void set_title( string input ){
			this->title = input;
		}
		
}; // end class entertainment

class book : public entertainment {
	protected:
		string 	publisher,
				isbn,
				author;
	public:
		string get_publisher(){
			return this->publisher;
		}
		
		void set_publisher(string input){
			this->publisher = input;
		}
		
		string get_isbn(){
			return this->isbn;
		}
		
		void set_isbn(string input){
			this->isbn = input;
		}
		
		string get_author(){
			return this->author;
		}
		
		void set_author(string input){
			this->author = input;
		}
	
}; // end class book

class movie : public entertainment {
	protected:
		string  director,
				studio;
		
	public:
		string get_director(){
			return this->director;
		}
		
		void set_director(string input){
			this->director = input;
		}
		
		string get_studio(){
			return this->studio;
		}
		
		void set_studio(string input){
			this->studio = input;
		}
	
}; // end class movie

class tv : public entertainment {
	protected:
		string  directors[24],
				studio;
		int years,
			episodes;
			
	public:
		// ARRAY STUFF
		string get_director(int pos){
			return this->directors[pos];
		}
		
		void set_director(string input, int pos){
			this->directors[pos] = input;
		}
		
		string get_studio(){
			return this->studio;
		}
		
		void set_studio(string input){
			this->studio = input;
		}
		
		int get_years(){
			return this->years;
		}
		
		void set_years(int input){
			this->years = input;
		}
		
		int get_episodes(){
			return this->episodes;
		}
		
		void set_episodes(int input){
			this->episodes = input;
		}
		
}; // end class tv

class play : public entertainment {
	protected:
		string director, 
			   theater, 
			   playwright;
		int performances;
	
	public:
		string get_director(){
			return this->director;
		}
		
		void set_director(string input){
			this->director = input;
		}
		
		string get_theater(){
			return this->theater;
		}
		
		void set_theater(string input){
			this->theater = input;
		}
		
		string get_playwright(){
			return this->playwright;
		}
		
		void set_playwright(string input){
			this->playwright = input;
		}
		
		int get_performances(){
			return this->performances;
		}
		
		void set_performances(int input){
			this->performances = input;
		}
}; // end class play




int main(){
	// Declare class variables
	entertainment ent1;
	book book1;
	movie movie1;
	tv tv1;
	play play1;
	
	cout << endl;
	
	// ============================== //
	//    Test entertainment class
	// ============================== //
	ent1.set_year(2014);
	ent1.set_title("Entertainment Title");
	
	cout << "Entertainment Class" << endl;
	cout << "==============================" << endl;
	cout << "Year: \t" << ent1.get_year() << endl;
	cout << "Title: \t" << ent1.get_title() << endl;
	
	cout << endl;
	
	// ============================== //
	// Test book class
	// ============================== //
	book1.set_year(1894);
	book1.set_title("Book Title");
	book1.set_publisher("Awesome US Publishing");
	book1.set_isbn("I-3885-33905-33-0");
	book1.set_author("Bob Sagat Junior");
	
	cout << "Book Class" << endl;
	cout << "==============================" << endl;
	cout << "Year: \t \t" << book1.get_year() << endl;
	cout << "Title: \t \t" << book1.get_title() << endl;
	cout << "Publisher: \t" << book1.get_publisher() << endl;
	cout << "ISBN: \t \t" << book1.get_isbn() << endl;
	cout << "Author: \t" << book1.get_author() << endl;
	cout << endl;
	
	// ============================== //
	// Test movie class
	// ============================== //
	movie1.set_year(2003);
	movie1.set_title("Movie Title");
	movie1.set_director("George Lucas");
	movie1.set_studio("A Galaxy Far Far Away");
	
	cout << "Movie Class" << endl;
	cout << "==============================" << endl;
	cout << "Year: \t \t" << movie1.get_year() << endl;
	cout << "Title: \t \t" << movie1.get_title() << endl;
	cout << "Director: \t" << movie1.get_director() << endl;
	cout << "Studio: \t" << movie1.get_studio() << endl;
	
	cout << endl;
	
	// ============================== //
	// Test tv class
	// ============================== //
	tv1.set_year(2009);
	tv1.set_title("TV Title");
	tv1.set_director("Roger Rabbit", 0);
	tv1.set_director("Tasmanian Devil", 1);
	tv1.set_director("Marvin the Martian", 2);
	tv1.set_director("Bugs Bunny", 3);
	tv1.set_studio("Friendly Hollywood Studio");
	tv1.set_years(17);
	tv1.set_episodes(153);
	
	cout << "TV Class" << endl;
	cout << "==============================" << endl;
	cout << "Year: \t \t" << tv1.get_year() << endl;
	cout << "Title: \t \t" << tv1.get_title() << endl;
	cout << "Director 1: \t" << tv1.get_director(0) << endl;
	cout << "Director 2: \t" << tv1.get_director(1) << endl;
	cout << "Director 3: \t" << tv1.get_director(2) << endl;
	cout << "Director 4: \t" << tv1.get_director(3) << endl;
	cout << "Studio: \t" << tv1.get_studio() << endl;
	cout << "Years: \t \t" << tv1.get_years() << endl;
	cout << "Episodes: \t" << tv1.get_episodes() << endl;
	
	cout << endl;
	
	// ============================== //
	// Test play class
	// ============================== //
	play1.set_year(1776);
	play1.set_title("Play Title");
	play1.set_director("William Shakespeare");
	play1.set_theater("Roman Colosseum");
	play1.set_playwright("To be or not to be");
	play1.set_performances(15);
	
	cout << "Play Class" << endl;
	cout << "==============================" << endl;
	cout << "Year: \t \t" << play1.get_year() << endl;
	cout << "Title: \t \t" << play1.get_title() << endl;
	cout << "Director: \t" << play1.get_director() << endl;
	cout << "Theater: \t" << play1.get_theater() << endl;
	cout << "Playwright: \t" << play1.get_playwright() << endl;
	cout << "Performances: \t" << play1.get_performances() << endl;
	
	cout << endl << endl;
	return 0;
}
