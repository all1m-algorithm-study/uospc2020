#include <iostream>
#include <algorithm>
#include "testlib.h"

const int INF = 2e9 + 5;

using namespace std;

int main(int argc, char* argv[])
{
	registerTestlibCmd(argc, argv);

	int N, L, R, U, D;
	N = inf.readInt();
	inf.readEoln();

	L = -INF; R = INF;
	U = -INF; D = INF;
	for (int i = 0; i < N; i++) {
		int x, y, w, h;
		x = inf.readInt(); inf.readSpace();
		y = inf.readInt(); inf.readSpace();
		w = inf.readInt(); inf.readSpace();
		h = inf.readInt(); inf.readEoln();
		L = max(L, x - w);
		R = min(R, x + w);
		U = max(U, y - h);
		D = min(D, y + h);
	}

	if (L <= R && U <= D) {
		string t;
		t = ouf.readToken();
		if (t == "impossible") {
			quitf(_wa, "Wrong Answer: it is possible");
		}
		else {
			int x, y;
			ouf.readSpace();
			x = atoi(t.c_str());
			y = ouf.readInt(); ouf.readEoln();
			if (L <= x && x <= R && U <= y && y <= D) {
				quitf(_ok, "Correct!");
			}
			else {
				quitf(_wa, "Wrong Answer: x, y not in possible range");
			}
		}
	}
	else {
		string t;
		t = ouf.readToken();
		if (t == "impossible") {
			quitf(_ok, "Correct!");
		}
		else {
			quitf(_wa, "Wrong Answer: it is not possible");
		}
	}
}

