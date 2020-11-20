#include <iostream>
#include <string>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int Nl = atoi(argv[1]);
	int Nr = atoi(argv[2]);
	int Ml = atoi(argv[3]);
	int Mr = atoi(argv[4]);
	int k = atoi(argv[5]);

	int N = rnd.next(Nl, Nr);
	int M = rnd.next(Ml, Mr);
	string a = "[A-";
	a.push_back(char('A' + k - 1));
	string b = "]{1}";
	string q = a + b;
	
	cout << N << '\n';
	for (int i = 0; i < N; i++) cout << rnd.next(q);
	cout << '\n';
	cout << M << '\n';
	for (int i = 0; i < M; i++) cout << rnd.next(q);
	cout << '\n';
	return 0;
}
