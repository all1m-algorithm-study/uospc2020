#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int MAX = 300000;
int color[MAX], cnt[MAX], vst[MAX];
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
		cnt[u]++; cnt[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	map<int, int> dic;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (cnt[i] == 1) {
			q.push(i);
			vst[i] = 1;
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if (dic.find(color[u]) == dic.end()) {
			dic[color[u]] = u;
		}
		else {
			int v = dic[color[u]];
			// w
			for (auto w : adj[u]) {
				if (vst[w]) continue;
				cnt[w]--;
				if (cnt[w] == 1) {
					vst[w] = 1;
					q.push(w);
				}
			}
			// v
			for (auto w : adj[v]) {
				if (vst[w]) continue;
				cnt[w]--;
				if (cnt[w] == 1) {
					vst[w] = 1;
					q.push(w);
				}
			}
			color[u] = -1;
			color[v] = -1;
		}
	}

	vector<int> answer;

	for (int i = 0; i < N; i++) {
		if (color[i] > 0) answer.push_back(i + 1);
	}

	cout << answer.size() << '\n';
	for (auto k : answer) {
		cout << k << ' ';
	}
	cout << '\n';
}