#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int sl = atoi(argv[1]);
	int sr = atoi(argv[2]);
	int tl = atoi(argv[3]);
	int tr = atoi(argv[4]);

	int s = rnd.next(sl, sr);
	int t = rnd.next(tl, tr);

	cout << s << ' ' << t << '\n';

	return 0;
}