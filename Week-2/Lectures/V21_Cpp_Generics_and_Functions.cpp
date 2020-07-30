// The instructor asked to write a C function to sum an array (though the code is written in Cpp coz I felt lazy to create a new file)
#include<iostream>
using namespace std;

//double sum(double data[], int size)   // data[] & *data - both are correct  
				        // since arrays are base pointers
double sum(double *data, int size)
{
	double s = 0.0;
	int i;

	for (i = 0; i < size; ++i) {
		s += data[i];
	}
	cout << "Sum: " << s <<endl;
	return s; 
}

int main() {
	double data_arr[] = {4, 3};
	sum(data_arr, 2);
}

// ***** C++ Generic SUM an array *****

template <class T_summable>
T_summable sum(const T_summable data[], int size, T_summable s = 0) // 'const' (not available in C) makes data[] immutable
								    // s=0 is default initial value, however, we can over-write
{
	for (int i = 0; i < size; ++i)
		s += data[i];
	return s;
}

int main() {
	
	int a[] = { 1, 2, 3 };
	double b[] = { 2.1, 2.2, 2.3 };

	cout << sum(a, 3, 6) << endl;  // default s = 0 will be replaced by s = 6 (pass-by-value)
	cout << sum(b, 3) << endl;  // default s = 0.0

	return 0;
	
} 

// ***** EXERCISE - 1 *****
// Write a program (abbrv. WAP) for subtraction

template <class T_sub>
T_sub sub(const T_sub data[], int size, T_sub s = 0) 
{
	for (int i = 0; i < size; i++)
		s -= data[i];    // Iter-1: s = 5 - 2 ... Iter-2: s = 3 - 1
	return s;
}

int main() {

	int a[] = {2, 1};
	
	cout << sub(a, 2, 5) << endl; 

	return 0;
}

// ***** EXERCISE - 2 *****
// WAP that output the elements of the array

template <class T_ele>
T_ele dispArr(const T_ele data[], int size, T_ele s = 0)
{
	for (int i = size - 1; i >= 0; i--) {    // Reversed the loop for just a flavour
		s = data[i];
		cout << s << endl;     
		//cout << s << '\t';	   // output: 1 2 3 4 5
	}
	return s;
}

int main() {

	int a[] = {5, 4, 3, 2, 1};
	dispArr(a, 5);
	return 0;
}

