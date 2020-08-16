#include<iostream>

class point {
public:
	double x, y;
	double getx() {
		return x;
	}
	void setx(double v) {
		x = v;
	}
};

point operator+ (point& p1, point& p2) {
	point sum = {
		p1.x + p2.x,
		p1.y + p2.y
	};
	return sum;
}

std::ostream& operator<< (std::ostream& out, const point& p) {
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

int main() {

	point a = { 3.5, 2.5 }, b = { 2.5, 4.5 };

	std::cout << "a = " << a << "\nb = " << b << std::endl;
	std::cout << "sum = " << a + b << std::endl;
}

