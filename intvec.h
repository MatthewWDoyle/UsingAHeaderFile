//intvec.h

#include "cmpt_error.h"
#include <iostream>
#include <cmath>

using namespace std;

class Intvec {
private:
	int* arr; // pointer to the underlying array
	int cap; // capacity of the underlying array, ie. its size
	int sz; // number of elements in the array

	// doubles the capacity of the underlying array
	void resizeArray() {
		cap = 2 * cap;

		// make the new array
		int* newArr = new int[cap];

		// copy elements into the new array
		for (int i = 0; i < sz; ++i){
			newArr[i] = arr[i];
		}

		// delete the old array
		delete[] arr;

		// set up the new array
		arr = newArr;
	}

	// Every element from arr[sz-1] to arr[start] is moved one position to the left.
	// the value at arr[start] is over-written.
	void shift_left(int start){
		for(int i = start; i < sz -1; i++){
			arr[i] = arr[i+1];
		}
	}

	// Every element from arr[start] to arr[sz-1] is moved one position to the
	// right. arr must have at least one extra space at the end.
	void shift_right(int start) {
		if (start >= sz) return;
		for(int i = sz; i >= start; i--) {
			arr[i] = arr[i-1];
		}
	}

public:
	// Default constructor that creates an empty array of size 0.
	// The initial capacity of 10 is just a guess
	Intvec()
	: cap(10), sz(0)
	{
		arr = new int[cap];
	}

	Intvec(const Intvec& other) {
		sz = other.sz;
		cap = other.cap;
		arr = new int[other.cap];
		for(int i = 0; i <other.sz; ++i) {
			arr[i] = other.arr[i];
		}
	}

	// This destructor is called automatically when an Intvec is deleted or 
	// Leaves scope.
	~Intvec() {
		delete[] arr; // note the use of []
	}

	// Someof the following functions have "const" before their bodies. This 
	// indicates that the function does not modify the object. In other words, 
	// using "const" like this makes the function read only.
	bool empty() const {
		return sz == 0;
	}

	int size() const {
		return sz;
	}

	int capacity() const {
		return cap;
	}

	int get(int i) {
		if( i <0 || i >= sz) cmpt::error("set: index out of bounds");
		return arr[i];
	}

	void set(int i, int x) {
		if( i <0 || i >= sz) cmpt::error("set: index out of bounds");
		arr[i] = x;
	}

	// Add x to the end of this Intvec, re-sizing the underlying array if
	// necessary
	void append(int x) {
		if(sz >= cap) {
			resizeArray();
		}
		arr[sz] = x;
		sz++;
	}

	// insert value x at location i.
	void insert(int x, int i) {
		// first check that i is a legal insertion index ie. 0 <= i <= sz
		if( i < 0 || i > sz) cmpt::error("insert: index out of bounds");

		// If necessary, re-size the underlying array.
		if (sz >= cap) {
			resizeArray();
		}

		// Make a new space for x at location i by shiftin all the elements
		// from arr[i] to arr[sz-1] one location to the right
		shift_right(i);

		// Insert x into location i and increase the size
		arr[i] = x;
		sz++;
	}

	// Does the smae thing as append, but implemented differently
	void insert_back(int x) {
		insert(x,sz);
	}

	// Puts x at the front of Intvec, moving all the other elements one 
	// position to the right
	void insert_front(int x) {
		insert(x,0);
	}

	// Removes (and returns) the item at loaction i. All the items from arr[i+1]
	// to arr[sz-1] are moved one position to the left, and the sice is decreased by 1
	int remove(int i) {
	// first check that i is a legal insertion index ie. 0 <= i <= sz
		if( i <0 || i >= sz) {
		cmpt::error("remove: index out of bounds");
		}
	
		// Save a copy of the value being removed
		int result = arr[i];

		// Move all items from arr[i] to arr[sz-1] one position to the left,
		// this over-writting arr[i]
		shift_left(i);
		sz--;

		return result;
	}

	int remove_back() {
		return remove(sz - 1);
	}

	int remove_front() {
		return remove(0);
	}

	void print() const {
		cout << "[";
		for(int i = 0; i < sz; ++i) {
			cout << arr[i] << " ";
		}
		cout << "]";
	}

	void println() const {
		print();
		cout << "\n";
	}
}; // Class Intvect

