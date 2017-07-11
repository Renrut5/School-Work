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
//	Assignment ###											//
//															//
//	CSC601hw8-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: Inventory management program.		//
//	Uses file to track inventory. Can create, delete, and	//										
//	save inventory.											//
//															//
// 	File Name: inventory.txt								//
//															//
// ======================================================== //

/**
DEV NOTES

File format:
 id:location:vendor:cost:price:qty:description

*/


class node {
	friend class inventoryList;
	private:
		// Inventory Items
		string description, location, vendor;
		float cost, price;
		int id, qty;
		
		node *pnext; 
		node *pprev;
	public:
		// Constructors
		node(){pnext = pprev = NULL;};
		node(int inId, string inDesc, string inLoc, string inVend, float inCost,
			float inPrice, float inQty){
			
			pnext = pprev = NULL;
			
			// Init values
			this->id = inId;
			this->description = inDesc;
			this->location = inLoc;
			this->vendor = inVend;
			this->cost = inCost;
			this->price = inPrice;
			this->qty = inQty;
			
		};
		
		// Get value functions
		int getId(){ return this->id; };
		string getDesc(){ return this->description; };
		string getLocation(){ return this->location; };
		string getVendor(){ return this->vendor; };
		float getCost(){ return this->cost; };
		float getPrice(){ return this->price; };
		int getQty(){ return this->qty; };
		
		// Set value functions
		void setId(int input){ this->id = input; };
		void setDesc(string input){ this->description = input;};
		void setLocation(string input){this->location = input;};
		void setVendor(string input){this->vendor = input;};
		void setCost(float input){this->cost = input;};
		void setPrice(float input){this->price = input;};
		void setQty(int input){this->qty = input;};
		
		// Next and previous pointers
		node *getNext(){return this->pnext;};
		node *getPrev(){return this->pprev;};
		
		void setNext(node *ptr){this->pnext = ptr;};
		void setPrev(node *ptr){this->pprev = ptr;};
};

class inventoryList {
	
	private:
		node *head;
		node *tail;
		node *currLoc;
		
		bool invLoaded;
		
	public:
		// Constructor
		// Only one constructor to init pointers to null
		// Items loaded manually from member function
		inventoryList(){this->currLoc = head = tail = currLoc = NULL;};
		
		void load_inventory();
		void add_inventory();
		void delAll();
		void delSingle(string id);
		void print();
		void change_location();
		int generate_id();
		void incrementQty(node *ptr);
		void decrementQty(node *ptr);
		void saveList();
		void deleteCurrent(node *delptr);
		void setLoc(node *ptr){this->currLoc = ptr;};
		
		// Search for node by ID
		node* searchById(int id);
		
		// Search for node by location
		node* searchByLoc(string loc);
		
		// Return current location pointer
		node* current_location(){return this->currLoc;};
		
		// Returns 1 if inventory is in memory
		int is_loaded(){
			if( this->head != NULL ){
				return 1;
			} else {
				return 0;
			}
		};
};

// Forward declarations of functions
	// Menu Functions
	int displayMenu(int isLoaded, node *currLoc);
	
	// Verification functions
	int verify_location(string input);
	
int main(){
	// Variable and object declarations
	int	selection, isLoaded;;
	node *currLoc;
	
	inventoryList inv;
	
	// Initialize selection to avoid garbage values
	selection = 0;
	currLoc = NULL;
	
	while( selection != 9 ){
		isLoaded = inv.is_loaded();
		currLoc = inv.current_location();
		selection = displayMenu(isLoaded, currLoc);
		
		// Select function based on input
		switch( selection ){
			case 1:
				// Enter New Item
				inv.add_inventory();
				break;
			case 2:
				// Print Item List
				inv.print();
				break;
			case 3:
				// Save Items to File
				inv.saveList();
				break;
			case 4:
				// Load Items from File
				inv.load_inventory();
				break;
			case 5:
				// Decrement Current Item Inventory
				inv.decrementQty(currLoc);
				break;
			case 6:
				// Increment Current Item Inventory
				inv.incrementQty(currLoc);
				break;
			case 7:
				// Change Location
				inv.change_location();
				break;
			case 8:
				// Delete by ID
				inv.deleteCurrent(currLoc);
				break;
			case 9:
				// Exit
				break;
		} // end switch
		
	} // end while
	
	return 0;
}



/**
 *	Display Menu Options, get input from user, and return selection
 *
 *	Menu Options:
 *	  1. Enter Item Data
 *	  2. Print Item List
 *	  3. Save Items to File
 *	  4. Load Items From File
 *	  5. Decrement Item Inventory
 *	  6. Increment Item Inventory
 *	  7. Change Location
 *	  8. Exit
 */
int displayMenu(int isLoaded, node *currLoc){
	string input, loaded, location;
	int selection;
	
	/*
	// Determine if inventory is loaded
	if(isLoaded == 1){
		loaded = "Yes";
	} else {
		loaded = "No";
	}
	*/
	
	// Load Location
	if( currLoc == NULL){
		location = "None";
	} else {
		location = currLoc->getLocation() + " - " + currLoc->getDesc();
	}
	
	
	cout << endl;
	cout << "================= Inventory Management =================" << endl;
	cout << endl;
	
	if( isLoaded != 1 ){
		// Inventory not loaded
		cout << "\tInventory not currently loaded" << endl << endl;
	} else if ( isLoaded == 1 && currLoc == NULL){
		cout << "\tInventory loaded. No item selected." << endl;
		cout << "\tPlease change location to select an item." << endl << endl;
	} else if( isLoaded == 1 && currLoc != NULL ){
		// Inventory Loaded and item is selected
		
		cout << "\tCurrent Location: " << currLoc->getLocation() << endl;
		cout << "\tItem ID: " << currLoc->getId() << endl;
		cout << "\tItem Description: " << currLoc->getDesc() << endl;
		cout << "\tItem Vendor: " << currLoc->getVendor() << endl;
		cout << "\tCurrent Quantity: " << currLoc->getQty() << endl;
		cout << "\tItem Cost: " << currLoc->getCost() << endl;
		cout << "\tItem Price: " << currLoc->getPrice() << endl;
		
		cout << endl;
	}
	
	cout << "\t1 - Add New Inventory Item" << endl;
	cout << "\t2 - Print Item List" << endl;
	cout << "\t3 - Save Items to File" << endl;
	cout << "\t4 - Load Items From File" << endl;
	cout << "\t5 - Decrease Current Item Inventory" << endl;
	cout << "\t6 - Increase Current Item Inventory" << endl;
	cout << "\t7 - Change Location" << endl;
	cout << "\t8 - Delete Current Item" << endl;
	cout << "\t9 - Exit" << endl;
	cout << endl << "\tPlease select an option: ";
	
	// Select option
	getline( cin, input );
	stringstream( input ) >> selection;
	
	return selection;
	
}

int verify_location(string input){
	int verified = 1;
	
	// Debug
	//cout << endl << "Input: " << input;
	
	// Ensure string length is correct
	if(input.length() != 4){
		//cout << endl << "Error: Wrong Length" << endl;
		verified = 0;
	}
	
	// Format must be AB##
	char * cstr = new char [5];
	strcpy (cstr, input.c_str());
	
	// Check each character of string
	for( int x = 0; x < 4; x++){
		// Verify characters
		if(x == 0 || x == 1){
			if( isalpha(cstr[x]) == 0 ){
				//cout << "Error: Not alpha" << endl;
				verified = 0;
			}
			// Check upper
			if( isupper(cstr[x]) == 0 ){
				verified = 0;
			}
		}
		// Verify Digits
		else {
			if( isdigit(cstr[x]) == 0 ){
				//cout << "Error: Not Digits" << endl;
				verified = 0;
			}
		}
		
	} // end for
	
	return verified;
}

// Manually add inventory item to linked list
void inventoryList::add_inventory(){
	node *tmpptr;
	node *newptr;
	
	string description, location, vendor;
	string tmpinput;
	float cost, price;
	int id, qty;
	
	// Generate ID number
	id = this->generate_id();
	
	// Get values from user
	cout << endl << "Input new item information.";
	cout << endl << "Description:\t";
	getline(cin, description);
	
	cout << "Location:\t";
	getline(cin, location);
	
	// Verify Location
	while( verify_location(location) != 1 ){
		cout << "Invalid Input, use format AB##: ";
		getline(cin, location);
	}
	
	cout << "Vendor:\t\t";
	getline(cin, vendor);
	
	cout << "Cost:\t\t";
	getline(cin, tmpinput);
	stringstream(tmpinput) >> cost;
	
	cout << "Price:\t\t";
	getline(cin, tmpinput);
	stringstream(tmpinput) >> price;
	
	cout << "Quantity:\t";
	getline(cin, tmpinput);
	stringstream(tmpinput) >> qty;
	
	// ====================== //
	// Create the new pointer //
	// ====================== //
	// string inId, string inDesc, string inLoc, string inVend, float inCost,
	//		float inPrice, float inQty
	newptr = new node(id, description, location, vendor, cost, price, qty);
	
	// If empty list
	if(head == NULL){
		this->head = newptr;
		this->tail = newptr;
		newptr->setNext(NULL);
		newptr->setPrev(NULL);
		return;
	} 
	// Otherwise, add to end of list
	else {
		tmpptr = this->tail;
		tmpptr->setNext(newptr);
		
		newptr->setNext(NULL);
		newptr->setPrev(tmpptr);
		
		this->tail = newptr;
		return;
	}
}

// Generate random id and check if unique
int inventoryList::generate_id(){
	node *ptr;
	int id;
	
	srand (time(NULL));
	id = rand() % 9999 + 1000;
	
	ptr = this->head;
	
	if( ptr == NULL ){
		return id;
	} else {
		
		while( this->searchById(id) != NULL ){
			srand(time(NULL));
			id = rand() % 9000 + 1000;
		}
		
		return id;	
	}
}

node* inventoryList::searchById(int id){
	node *srchptr;
	
	srchptr = this->head;
	
	if(srchptr == NULL){
		return NULL;
	}
	
	while(srchptr != NULL){
		if(srchptr->id == id){
			return srchptr;
		}
		
		srchptr = srchptr->getNext();
	}
	
	return srchptr;
}

// Save list to file and erase from memory
void inventoryList::saveList(){
	node *tmpptr;
	ofstream outfile;
	
	tmpptr = this->head;
	cout << tmpptr->getId();
	// Empty List
	if(tmpptr == NULL){
		return;
	}
	
	outfile.open("inventory.txt", ios::trunc);
	
	// File save format
	// id:location:vendor:cost:price:qty:description
	while(tmpptr != NULL){
		outfile << tmpptr->getId() << ":";
		outfile << tmpptr->getLocation() << ":";
		outfile << tmpptr->getVendor() << ":";
		outfile << tmpptr->getCost() << ":";
		outfile << tmpptr->getPrice() << ":";
		outfile << tmpptr->getQty() << ":";
		outfile << tmpptr->getDesc() << ":";
		
		if(tmpptr->getNext() != NULL){
			outfile << "\n";
		}
		
		tmpptr = tmpptr->getNext();
	}
	
	outfile.close();
	
	this->delAll();
	return;
}

// Print inventory
void inventoryList::print(){
	node *ptr;
	
	ptr = this->head;
	
	// Empty List
	if(ptr == NULL){
		cout << endl << "No items loaded." << endl;
		return;
	}
	cout << endl << endl << "Inventory List" << endl << endl;
	
	cout << setw(6) << left << "ID  ";
	cout << setw(10) << left << "Location  ";
	cout << setw(12) << left << "Vendor  ";
	cout << setw(8) << left << "Cost  ";
	cout << setw(8) << left << "Price  ";
	cout << setw(6) << left << "Qty  ";
	cout << setw(20) << left << "Description";
	cout << endl;
	cout << "====================================================================================" << endl;
	while( ptr != NULL ){
		cout << setw(6) << left << ptr->getId();
		cout << setw(10) << left << ptr->getLocation();
		cout << setw(12) << left << ptr->getVendor();
		cout << setw(8) << left << ptr->getCost();
		cout << setw(8) << left << ptr->getPrice();
		cout << setw(6) << left << ptr->getQty();
		cout << setw(20) << left << ptr->getDesc();
		cout << endl;
		
		ptr = ptr->getNext();
	}
	
	
}

// Change current location
void inventoryList::change_location(){
	node *tmpptr;
	string loc, check;
	int match = 0;
	
	// Empty list
	if(this->head == NULL){
		return;
	}
	
	cout << endl << endl << "Enter location to move to: ";
	getline(cin, loc);
	
	tmpptr = this->head;
	
	while(tmpptr != NULL){
		check = tmpptr->getLocation();
		
		if(check == loc){
			this->currLoc = tmpptr;
			return;
		}
		tmpptr = tmpptr->getNext();
	}
	
	if(tmpptr == NULL){
		cout << "Location not found." << endl;
		return;
	}
	
}

// Delete all records in memory
void inventoryList::delAll(){
	node *currptr;
	node *nextptr;
	
	// Empty List
	if(this->head == NULL){
		return;
	}
	
	nextptr = this->head;
	
	while(nextptr != NULL){
		currptr = nextptr;
		nextptr = currptr->getNext();
		
		delete currptr;
	}
	
	// Set list head and tail to null
	this->head = this->tail = this->currLoc = NULL;
}

// Delete active record from memory
void inventoryList::deleteCurrent(node *delptr){
	node *tmpptr;
	
	if( delptr == NULL ){
		cout << endl << "No item selected." << endl;
		return;
	}	
	
	if(this->head == delptr){
		head = delptr->getNext();
	} else {
		tmpptr = delptr->getPrev();
		tmpptr->setNext(delptr->getNext());
	}
	
	delete delptr;
	this->setLoc(NULL);
	return;
	
}

// Load inventory from file
void inventoryList::load_inventory(){
	ifstream infile;
	string tmp, input;
	int pos, npos, tmpInt;
	float tmpFloat;
	node *tmpnode;
	infile.open("inventory.txt");
	
	
	
	while( !infile.eof() ){
		pos = 0;
		
		// Create new node
		tmpnode = new node();
		
		// Get line from file
		getline(infile, input);
		
		
		// Item ID
		npos = input.find(':');
		stringstream(input.substr(pos, npos - pos)) >> tmpInt;
		tmpnode->setId(tmpInt);
		
		// Location
		pos = npos + 1;
		npos = input.find(':', pos);
		tmpnode->setLocation(input.substr(pos, npos - pos));
		
		// Vendor
		pos = npos + 1;
		npos = input.find(':', pos);
		tmpnode->setVendor(input.substr(pos, npos - pos));
		
		// Cost
		pos = npos + 1;
		npos = input.find(':', pos);
		stringstream(input.substr(pos, npos - pos)) >> tmpFloat;
		tmpnode->setCost(tmpFloat);
		
		// Price
		pos = npos + 1;
		npos = input.find(':', pos);
		stringstream(input.substr(pos, npos - pos)) >> tmpFloat;
		tmpnode->setPrice(tmpFloat);
		
		// Quantity 
		pos = npos + 1;
		npos = input.find(':', pos);
		stringstream(input.substr(pos, npos - pos)) >> tmpInt;
		tmpnode->setQty(tmpInt);
		
		// Description
		pos = npos + 1;
		npos = input.find(':', pos);
		tmpnode->setDesc(input.substr(pos, npos - pos));
		
		// ========================== //
		// Insert node to linked list //
		// ========================== //
	
		// Empty list
		if ( this->head == NULL ){
			this->head = tmpnode;
			this->tail = tmpnode;
			tmpnode->setNext(NULL);
			tmpnode->setPrev(NULL);
		} 
		// Non-Empty List
		else {
			tmpnode->setPrev(this->tail);
			tmpnode->setNext(NULL);
			tail->setNext(tmpnode);
			
			tail = tmpnode;
		}
	}
	infile.close();
	
}

// Increment current item quantity
void inventoryList::incrementQty(node *ptr){
	int val;
	string input;
	
	if(ptr == NULL){
		cout << "No Item selected." << endl << endl;
		return;
	}
	
	cout << endl << "Enter quantity to increment by: ";
	getline(cin, input);
	
	stringstream(input) >> val;
	
	// Invalid input or 0
	if( val == 0 ){
		return;
	}
	
	ptr->qty += val;
	
}

// Decrement current item quantity
void inventoryList::decrementQty(node *ptr){
	int val;
	string input;
	
	if(ptr == NULL){
		cout << "No Item selected." << endl << endl;
		return;
	}
	
	cout << endl << "Enter quantity to decrement by: ";
	getline(cin, input);
	
	stringstream(input) >> val;
	
	// Invalid input or 0
	if( val == 0 ){
		return;
	}
	
	ptr->qty -= val;
}

