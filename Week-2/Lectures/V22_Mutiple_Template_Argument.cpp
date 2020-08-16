// Templates with multiple argument
#include<iostream>
using namespace std;

template <class T1, class T2>
void copy(const T1 source[], T2 destination[], int size) {

	for (int i = 0; i < size; i++) {
		destination[i] = static_cast <T2>(source[i]);
		cout << "Destination array: " << destination[i] << endl;
	}
}

void main() {
    
	int arr1[] = { 1, 2, 3 };  // source array is int type
	double arr2[3];
	//char arr3[3];    // destination array is char type

	copy(arr1, arr2, 3);   
	//copy(arr1, arr3, 3);   // invalid copy of int data to char data... Uncommment this part to see the output
}

/* Type Casting */
// changing one datatype to another- like int to float or float to double or double to int
// However, if we try to explicitly convert int to char then there will be mismatch in the type.
// So we use safe casting i.e. static_cast to prevent this unacceptable conversion and support valid conversion
//
// Ex:
// float a = 9.3;
// int b = a;  // this is the type-conversion method used in C (old-styled typecasting, it will work though)
// int b = static_cast <int>(a); // safe conversion of float type to int type (advantage of C++)

// However, suppose we take this example
//int a = 10;
//char c = 'a';

//int* q;
//q = &c ;
// OR
//int* q = static_cast<int*>(&c);

// Both are invalid conversions since the program is trying to convert a char type to int type. 
// static_cast will prevent this invalid conversion by throwing a type conversion error.