// In C++, we use Structures to create a user-defined data-type

#include<iostream>
using namespace std;

typedef struct point {
	double x, y;
}point;

void addPoints(point* p1, point* p2, point* sum) {

	sum->x = p1->x + p2->x;
	sum->y = p1->y + p2->y;
	
	cout << "\nSum of Point-1 (" << p1->x << "," << p1->y << ") and Point-2 (" 
		<< p2->x << "," << p2->y << ") is: "<< endl;
	
	cout << "(" << sum->x << "," << sum->y << ")";

}

int main() {

	struct point A, B, z;
	
	cout << "Enter point 1: ";
	cin >> A.x >> A.y;

	cout << "\nEnter point 2: ";
	cin >> B.x >> B.y;

	addPoints(&A, &B, &z);

	return 0;
}