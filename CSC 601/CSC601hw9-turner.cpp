#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// ======================================================== //
//	Name: 	Andrew Turner									//
//	Class:	CSC601											//
//	Assignment 9											//
//															//
//	CSC601hw9-turner.cpp									//
//	Complier Used: g++ on Mac OS							//
//															//
//	Program Description: Demonstrate how to use a queue		//
// 	style linked list										//
//															//
// ======================================================== //

class node{
	private:
		string value;
		node* pnext;
		
	public:
		// Constructors
		node(string val){this->value = val; this->pnext = NULL;};
		
		node* getNext(){return this->pnext;};
		void setNext(node* next){this->pnext = next;};
		
		string getValue(){return this->value;};
		void setValue(string input){this->value = input;};		
};

class queue{
	private:
		node* head;
		node* tail;
		
	public:
		queue(){this->head = this->tail = NULL;};
		
		void enqueue(string input);
		string dequeueHead();
		string dequeueTail();
		void printAll();	
};


int main(){
	queue myqueue;
	
	
	cout << endl << "Output String: ";
	
	// Enqueue and dequeue strings
	myqueue.enqueue("C++");
	myqueue.enqueue("is");
	myqueue.enqueue("a");
	myqueue.enqueue("powerful");
	
	cout << myqueue.dequeueHead() << " ";
	cout << myqueue.dequeueHead() << " ";
	cout << myqueue.dequeueHead() << " ";
	cout << myqueue.dequeueHead() << " ";
	
	myqueue.enqueue("useful");
	myqueue.enqueue("and");
	
	cout << myqueue.dequeueTail() << " ";
	cout << myqueue.dequeueHead() << " ";
	
	myqueue.enqueue("computer");
	
	cout << myqueue.dequeueHead() << " ";
	
	myqueue.enqueue("language");
	myqueue.enqueue("programming");
	
	cout << myqueue.dequeueTail() << " ";
	cout << myqueue.dequeueHead() << " ";
	
	cout << endl << endl;
	
	return 0;
}

// Add new string to the queue
void queue::enqueue(string input){
	node* tmpptr;
	
	tmpptr = new node(input);
	
	// If empty queue
	if(this->head == NULL){
		this->head = this->tail = tmpptr;
		return;
	}
	
	// If only one item in queue
	else if( this->head == this->tail ){
		this->tail = tmpptr;
		this->head->setNext(tmpptr);
	}
	
	else {
		// more than one item in queue
		this->tail->setNext(tmpptr);
		this->tail = tmpptr;
	}
	
	return;
}

// return value at head of queue
string queue::dequeueHead(){
	node* tmpptr;
	string value;
	
	if(this->head == NULL){
		// No items in queue, return empty string
		cout << endl << "No items in queue." << endl;
		return "";
	}
	
	// Get string at front of queue
	tmpptr = this->head;
	
	if( this->head == this->tail ){
		// Only one item in queue
		this->head = this->tail = NULL;
	} else {
		this->head = tmpptr->getNext();
	}
	
	value = tmpptr->getValue();
	delete tmpptr;
	
	return value;
}

// return value at tail of queue
string queue::dequeueTail(){
	node* tmpptr;
	node* srchptr;
	string value;
	
	if(this->tail == NULL){
		// No items in queue, return empty string
		cout << endl << "No items in queue." << endl;
		return "";
	}
	
	// Get string at tail
	tmpptr = this->tail;
	value = tmpptr->getValue();
	
	// Remove tail from memory and set to new
	
	if( this->head == this->tail ){
		// Head is tail, set both to null
		this->head = this->tail = NULL;
	} else {
		srchptr = this->head;
		
		// Get pointer before tail
		while( srchptr->getNext() != tmpptr ){
			srchptr = srchptr->getNext();
		}
		
		this->tail = srchptr;
		srchptr->setNext(NULL);
	}
	
	return value;
}

// Print everything in queue
void queue::printAll(){
	node *tmpptr;
	
	
	tmpptr = this->head;
	if(tmpptr == NULL){
		return;
	}
	
	cout << endl;
	
	while(tmpptr != NULL){
		cout << tmpptr->getValue() << " ";
		tmpptr = tmpptr->getNext();
	}
	
}
