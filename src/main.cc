/*
 * Heapsort.cc
 *
 *  Created on: Nov 25, 2014
 *      Author: carl
 */

#include <iostream>
#include <stdlib.h>
#include <cstring>

using std::cout;
using std::endl;

const size_t WIDTH = 100;

void max_heapify(int *a, size_t location, size_t size) {
	size_t maximum_location = location;
	size_t left_location = 2*location +1;
	size_t right_location = 2*location +2;
	if((left_location < size) && (*(a + location) < *(a + left_location))) {
		maximum_location = left_location;
	}
	if((right_location < size) && (*(a + maximum_location) < *(a + right_location))) {
		maximum_location = right_location;
	}
	if(maximum_location != location) {
		int t = *(a + maximum_location);
		*(a + maximum_location) = *(a + location);
		*(a + location) = t;
		max_heapify(a, maximum_location, size);
	}
}

void build_maximum_heap(int *a, size_t size) {
	for(size_t i=size/2;i>=1;--i) {
		max_heapify(a, i-1, size - i + 1); //cover [1,,,n] to [0,,,,n-1]
	}
}

void heapsort(int *a, size_t size) {
	build_maximum_heap(a, size);

	for(size_t i=size;i>0;--i) {
		int maximum = a[0];
		a[0] = a[i-1];
		a[i-1] = maximum;
		max_heapify(a, 0, --size);
	}
}

void gen_random(int *a, size_t size) {
	for(size_t i=0;i<size;++i) {
		*(a+i) = random()/10000000;
	}
}

void display(int *a, size_t size) {
	for(size_t i=0;i<size;++i) {
		cout << *(a+i) << "\t";
	}
	cout << endl;
}

int main() {
	int *data = NULL;
	data = new int[WIDTH];
	gen_random(data, WIDTH);
	cout << "Before Sort:" << endl;
	display(data, WIDTH);
	heapsort(data, WIDTH);
	cout << "After Sort:" << endl;
	display(data, WIDTH);
	delete [] data;
}



