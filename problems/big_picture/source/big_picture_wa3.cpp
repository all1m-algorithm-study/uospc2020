#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	string S, T;
	cin >> N;
	cin >> S;
	cin >> M;
	cin >> T;
	vector<int> dp_left(N), dp_right(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i + j > N) break;
			if (S[i + j] != T[j]) break;
			dp_left[i] = j + 1;
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (i - j < 0) break;
			if (S[i - j] != T[M - 1 - j]) break;
			dp_right[i] = j + 1;
		}
	}

	bool flag = false;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (dp_left[i] + dp_right[j] >= M) {
				flag = true;
			}
		}
	}
	if (flag) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}