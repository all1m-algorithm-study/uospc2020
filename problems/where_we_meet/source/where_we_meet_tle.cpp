#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 2e9 + 5;
const int MAX = 100000;
int x[MAX], y[MAX], w[MAX], h[MAX];
int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N, L, R, U, D;
	cin >> N;
	L = INF; R = -INF;
	U = INF; D = -INF;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i] >> w[i] >> h[i];
		L = min(L, x[i] - w[i]);
		R = max(R, x[i] + w[i]);
		U = min(U, y[i] - h[i]);
		D = max(D, y[i] + h[i]);
	}
	
	for (int i = L; i <= R; i++) {
		for (int j = U; j <= D; j++) {
			bool flag = true;
			for (int k = 0; k < N; k++) {
				if (abs(x[k] - i) > w[k]) flag = false;
				if (abs(y[k] - j) > h[k]) flag = false;
			}
			if (flag) {
				cout << i << ' ' << j << '\n';
				return 0;
			}
		}
	}
	cout << "impossible" << '\n';
}