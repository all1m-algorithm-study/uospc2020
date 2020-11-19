#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int Nl = atoi(argv[1]);
	int Nr = atoi(argv[2]);
	int xyl = atoi(argv[3]);
	int xyr = atoi(argv[4]);
	int whl = atoi(argv[5]);
	int whr = atoi(argv[6]);

	int N = rnd.next(Nl, Nr);
	cout << N << '\n';
	for (int i = 0; i < N; i++) {
		int x = rnd.next(xyl, xyr);
		int y = rnd.next(xyl, xyr);
		int w = rnd.next(whl, whr);
		int h = rnd.next(whl, whr);
		cout << x << ' ' << y << ' ';
		cout << w << ' ' << h << '\n';
	}
	return 0;
}