#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int m, a, b, q, r;
	cin >> m >> a >> b;
	q = m / (a + b);
	r = min(a, m % (a + b));
	cout << q * a + r << '\n';
}