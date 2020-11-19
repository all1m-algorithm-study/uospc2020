#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 2e9 + 5;

int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N, L, R, U, D;
	cin >> N;

	L = -INF; R = INF;
	U = -INF; D = INF;
	for (int i = 0; i < N; i++) {
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		L = max(L, x - w);
		R = min(R, x + w);
		U = max(U, y - h);
		D = min(D, y + h);
	}

	if (L <= R && U <= D) {
		cout << L << ' ' << U << '\n';
	}
	else {
		cout << "impossible" << '\n';
	}
}