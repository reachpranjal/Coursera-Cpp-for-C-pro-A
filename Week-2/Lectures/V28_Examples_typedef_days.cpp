// Edsger Dijkstra's algorithm
/* Finding the shortest path between start 's' and destination node 'd'
Step-1: Include 's' in a closed set and all immediate successors of 's' with their
distance in the open set

Step-2: Pick the open node of least cost- say this node is 'n'*/

#include<iostream>
using namespace std;

typedef enum days{
	Sun, Mon, Tue, Wed, Thur, Fri, Sat
} days;

inline days operator++ (days d) {
	days convert_Int_to_Day;

	convert_Int_to_Day = static_cast<days> ((static_cast <int>(d) + 1) % 7);
	return convert_Int_to_Day;
}


ostream& operator<< (ostream& out, const days& d) {
		switch (d)
		{
		case Sun: out << "SUNDAY";
			break;
		case Mon: out << "MONDAY";
			break;
		case Tue: out << "TUESDAY";
			break;
		case Wed: out << "WEDNESDAY";
			break;
		case Thur: out << "THURSDAY";
			break;
		case Fri: out << "FRIDAY";
			break;
		case Sat: out << "SATURDAY";
			break;
		}
		return out;
}

int main() {

	days d = Wed, e;
	e = ++d;

	cout << d << '\t' << e << endl;

	return 0;
}