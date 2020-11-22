#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAX = 300000;
int color[MAX];
vector<int> adj[MAX];

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> color[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	set<int> answer;
	for (int u = 0; u < N; u++) {
		for (auto v : adj[u]) {
			if (color[u] == color[v]) {
				answer.insert(u + 1);
				answer.insert(v + 1);
			}
		}
	}

	cout << answer.size() << '\n';
	for (auto k : answer) {
		cout << k << ' ';
	}
	cout << '\n';
}