//intvec_main.cpp

#include "intvec.h"
#include "cmpt_error.h"
#include <iostream>
#include <cassert>

using namespace std;

void test1() {
	Intvec v;
	assert(v.size() == 0);
	assert(v.empty());

	for(int i = 1; i <=100; ++i){
		v.append(i);
		double usage = 100 * v.size() / double(v.capacity());
		int unused_bytes = sizeof(int) * (v.capacity() - v.size());
		cout << v.size() << " " << v.capacity() << " " << usage << "% "
			 << unused_bytes << " bytes unused\n";
	}
}

void test2() {
	Intvec v;

	for(int i = 1; i <= 10; ++i) {
		v.append(i);
	}
	v.println();

	v.insert(1,0);
	v.println();

	v.insert(2,10);
	v.println();

	v.insert(3,v.size());
	v.println();
}

void test3() {
	Intvec v;
	for(int i = 1; i <= 21; ++i) {
		v.insert_back(i);
		// v.insert_front(i);
		// v.println();
	}
	cout << "v.size = " << v.size() << " " << "v.capacity = " << v.capacity() << "\n";
}

void test4() {
	for(int i = 0; i < 10; ++i) {
		test3();
	}
}

void test5() {
	Intvec v;;

	for(int i = 1; i<= 20; i++) {
		v.insert_back(i);
	}
	v.println();

	v.remove(0);
	v.println();

	v.remove(10);
	v.println();

	v.remove(v.size() -1);
	v.println();
}

void test6() {
	Intvec v;

	for (int i = 1; i <= 20; ++i) {
		v.insert_back(i);
	}

	while(!v.empty()) {
		v.println();
		v.remove_front();
	}
	v.println();
}

void test7() {
	Intvec v;

	for (int i = 1; i <= 20; ++i) {
		v.insert_back(i);
	}
	while(!v.empty()) {
		v.println();
		v.remove_back();
	}
}

int main() {
	 test1();
	// test2(); 
	// test3(); 
	// test4(); 
	// test5(); 
	// test6(); 
	// test7(); 

}