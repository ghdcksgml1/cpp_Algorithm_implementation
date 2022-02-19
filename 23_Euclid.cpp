#include <iostream>

using namespace std;

int uclid(int a, int b) { // (a > b)
	if (b == 0) return a;
	else return uclid(b, a % b);
}

int main(void) {
	int n1 = 200;
	int n2 = 180;
	cout << uclid(n1, n2) << '\n';
}
