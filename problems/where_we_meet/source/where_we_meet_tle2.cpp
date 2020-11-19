#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 2e9 + 5;
const int MAX = 100000;
int x[MAX], y[MAX], w[MAX], h[MAX];
int main() {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i] >> w[i] >> h[i];
	}

	for (int i = 0; i < N; i++) {
		int xi, yi;
		bool flag;

		xi = x[i] - w[i];
		yi = y[i] - h[i];
		flag = true;
		for (int j = 0; j < N; j++) {
			if (abs(x[j] - xi) > w[j]) flag = false;
			if (abs(y[j] - yi) > h[j]) flag = false;
		}
		if (flag) {
			cout << xi << ' ' << yi << '\n';
			return 0;
		}

		xi = x[i] + w[i];
		yi = y[i] - h[i];
		flag = true;
		for (int j = 0; j < N; j++) {
			if (abs(x[j] - xi) > w[j]) flag = false;
			if (abs(y[j] - yi) > h[j]) flag = false;
		}
		if (flag) {
			cout << xi << ' ' << yi << '\n';
			return 0;
		}

		xi = x[i] - w[i];
		yi = y[i] + h[i];
		flag = true;
		for (int j = 0; j < N; j++) {
			if (abs(x[j] - xi) > w[j]) flag = false;
			if (abs(y[j] - yi) > h[j]) flag = false;
		}
		if (flag) {
			cout << xi << ' ' << yi << '\n';
			return 0;
		}

		xi = x[i] + w[i];
		yi = y[i] + h[i];
		flag = true;
		for (int j = 0; j < N; j++) {
			if (abs(x[j] - xi) > w[j]) flag = false;
			if (abs(y[j] - yi) > h[j]) flag = false;
		}
		if (flag) {
			cout << xi << ' ' << yi << '\n';
			return 0;
		}
	}
	cout << "impossible" << '\n';
}