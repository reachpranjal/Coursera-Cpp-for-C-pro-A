#include <iostream>	 // C++ I/O header file
#include <vector>	 // Header to use "vector"
using namespace std; // inline

const int N = 40;   

// declaration of function sum()
// *p = *(&0) = value at address of position 0
void sum(int* p, int n, vector<int> d) {

	int i;
	*p = 0;  // value at position 0 is initialized to 0

	for (i = 0; i < n; i++)
		*p = *p + d[i];   // sum of numbers from 0 to 39
}

int main() {

	int accum = 0;

	vector<int> data(N);

	for (int i = 0; i < data.size(); i++) {
		data[i] = i;	// vector of 40 elements
	}

	// function call by passing 3 arguments that are
	// address of memory allocated, range, elements
	sum(&accum, N, data);	

	// Print the sum of first 40 whole numbers
	cout << "Sum is\n" << accum;  

	return 0;
}