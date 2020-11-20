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
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (j - i + 1 < M) continue;
			int a, b;
			a = 0; b = 0;
			while (a < M && T[a] == S[i + a]) a++;
			while (b < M && T[M - 1 - b] == S[j - b]) b++;
			if (a + b >= M) {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}
	cout << "NO" << '\n';
}