#include <iostream>

using namespace std;

int uclid(int a, int b) {
	if (b == 0) return a;
	else return uclid(b, a % b);
}

int main(void) {
	int n1 = 180;
	int n2 = 200;
	cout << uclid(n1, n2) << '\n';
}