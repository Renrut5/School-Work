#include <iostream>
#include <fstream>
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
//	CSC601hw7-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: A demonstration of linked lists	//
//	in C++. 												//
//															//
// ======================================================== //


// Forward declarations of functions

class node {
	friend class list;
	private:
		float value;
		node *pnext;
	
	public:
		// Default constructor
		node(){
			this->pnext = NULL; 
		};
		
		node( float val ){
			this->value = val;
			this->pnext = NULL;
		};
		
		node( float val, node* next ){
			this->value = val;
			this->pnext = next;
		};
		
		float getValue(){
			return this->value;
		};
		
		void setValue(float val){
			this->value = val;
		};
		
		node* getNext(){
			return this->pnext;
		};
		
		void setNext( node* ptr ){
			this->pnext = ptr;
		};
};

class list {
	private:
		node* head;
		
	public:
		list(){
			this->head = NULL;
		};
		
		list( float val ){
			head = new node(val);
		};
		
		node* getHead(){ return head; };
		
		
		void print();
		void insertHead( float val );
		void insertTail(float val);
		void del(float val);
		node* search(float val);
		node* findLast();
};

void list::print(){
	node *ptrhead = this->head;
	int x = 0;
	
	// For Empty List
	if( ptrhead == NULL ){
		cout << "List is empty." << endl;
		return;
	}
	
	// Traverse the list
	while ( ptrhead != NULL ){
		cout << ptrhead->getValue() << " ";
		 ptrhead = ptrhead->getNext();
	}
	
}

void list::insertHead( float val ){
	node* tmpptr;
	
	tmpptr = this->head;
	head = new node( val, tmpptr );
}

void list::insertTail( float val ){
	node *lastptr;
	node *insert;
	
	lastptr = findLast();
	
	insert = new node(val);
	lastptr->setNext(insert);
	
}

void list::del( float val ){
	node *delptr;
	node *tmpptr;
	
	delptr = this->search( val );
	
	// Value not found
	if( delptr == NULL ){
		cout << "Value not found." << endl;
		return;
	}
	
	if( delptr->getValue() != val ){
		cout << "Value not found." << endl;
		return;
	}
	
	// If delete is first value
	if( delptr == head ){
		head = delptr->getNext();
		delete delptr;
		return;
	}
	
	// Find the node before delptr
	tmpptr = head;
	
	while( tmpptr->getNext() != delptr ){
		tmpptr = tmpptr->getNext();
	}
	
	// Set tmpptr next node to delptr next node
	tmpptr->setNext( delptr->getNext() );
	
	delete delptr;
}

node* list::findLast(){
	node *srchptr = head;
	node *lastptr;
	
	if( srchptr == NULL ){
		return NULL;
	}
	
	// Traverse the list until the last item is found
	while( srchptr != NULL ){
		lastptr = srchptr;
		srchptr = srchptr->getNext();
	}
	
	// lastptr is not the final item in the list
	return lastptr;
}

node* list::search( float val ){
	node *srchptr = head;
	node *lastptr;
	
	// String is empty
	if ( srchptr == NULL ){
		return NULL;
	}
	
	// Value found at head of list
	if ( srchptr != NULL && srchptr->value == val ){
		return srchptr;
	}
	
	// Search string if value not at head
	while (srchptr != NULL && srchptr->value != val){
		lastptr = srchptr;
		srchptr = srchptr->getNext();
	}
	
	// Return pointer to node or NULL
	return srchptr;
	/*if(srchptr == NULL){
		return NULL;
	} else {
		return lastptr;
	}
	*/
}



int main(){
	cout << endl;
	
	// Declare mylist and set initial value
	list mylist(15.5);
	float search, delvalue, insert1, insert2, del1, del2;
	node* mysearch;
	
	// Insert initial values into link list
	mylist.insertHead(10);
	mylist.insertHead(37.5);
	mylist.insertHead(28.9);
	mylist.insertHead(23);
	mylist.insertHead(44.1);
	mylist.insertHead(53);
	mylist.insertHead(11.6);
	mylist.insertHead(67.5);
	mylist.insertHead(1);
	mylist.insertTail(17.1);
	
	// Print list
	cout << "Original List:" << endl;
	mylist.print();
	
	// Ask user to search for two values
	// Assumes input from user is a valid float number
	
	// Search #1
	cout << endl << "Enter value to search for: ";
	cin >> search;
	mysearch = mylist.search(search);
	
	if ( mysearch != NULL ) {
		cout << "Value found at: " << mysearch << endl;
	} else {
		cout << "Value not found." << endl;
	}
	
	// Search #2
	cout << endl << "Enter a second value to search for: ";
	cin >> search;
	
	mysearch = mylist.search(search);
	
	if ( mysearch != NULL ) {
		cout << "Value found at: " << mysearch << endl;
	} else {
		cout << "Value not found." << endl;
	}
	
	cout << endl;
	
	// Delete a value in the list
	cout << "Enter a value to delete: ";
	cin >> delvalue;
	
	mylist.del(delvalue);
	
	// Print the list again
	cout << "List after first delete: " << endl;
	mylist.print();
	cout << endl;
	
	// Delete two more values
	cout << endl << "Please select two more values to delete." << endl;
	cout << "1: ";
	cin >> del1;
	
	mylist.del(del1);
	
	cout << "2: ";
	cin >> del2;
	
	mylist.del(del2);
	
	// Insert two values
	//
	
	cout << endl << "Enter a value to insert at head of list: ";
	cin >> insert1;
	
	cout << "Enter another value to insert at tail of list: ";
	cin >> insert2;
	
	mylist.insertHead(insert1);
	mylist.insertTail(insert2);
	
	
	// Print list one final time
	cout << endl << "List after values are inserted:" << endl;
	mylist.print();
	
	cout << endl << endl;
	return 0;
}

