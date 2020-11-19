#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int ml = atoi(argv[1]);
	int mr = atoi(argv[2]);
	int abl = atoi(argv[3]);
	int abr = atoi(argv[4]);

	int m = rnd.next(ml, mr);
	int a = rnd.next(abl, abr);
	int b = rnd.next(abl, abr);
	
	cout << m << '\n';
	cout << a << ' ' << b << '\n';

	return 0;
}