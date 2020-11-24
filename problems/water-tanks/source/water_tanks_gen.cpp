// https://codeforces.com/blog/entry/18291

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "testlib.h"

using namespace std;
using pi = pair<int, int>;
vector<pi> edges, edges2;
vector<int> adj[10000];
int vst[10000], S[10000];

void bfs(int root) {
	queue<int> q;
	q.push(root);
	vst[root] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : adj[u]) {
			if (vst[v]) continue;
			q.push(v);
			vst[v] = 1;
			edges2.emplace_back(u, v);
		}
	}
}

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n = atoi(argv[1]);
	int t = atoi(argv[2]);
	int s = atoi(argv[3]);

	vector<int> p(n);
	/* setup parents for vertices 1..n-1 */
	for (int i = 0; i < n; i++) {
		if (i > 0) {
			p[i] = rnd.wnext(i, t);
		}
	}
	/* shuffle vertices 1..n-1 */
	vector<int> perm(n);
	for (int i = 0; i < n; i++) {
		perm[i] = i;
	}
	shuffle(perm.begin() + 1, perm.end());
	/* put edges considering shuffled vertices */
	for (int i = 1; i < n; i++) {
		if (rnd.next(2)) {
			edges.emplace_back(perm[i], perm[p[i]]);
		}
		else {
			edges.emplace_back(perm[p[i]], perm[i]);
		}
	}
	/* shuffle edges */
	shuffle(edges.begin(), edges.end());

	/* set S */
	for (int i = 0; i < n; i++) {
		S[i] = rnd.next(1, s);
	}

	/* set adj */
	for (int i = 0; i < n - 1; i++) {
		int u = edges[i].first, v = edges[i].second;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	/* bfs and shuffle */
	bfs(0);
	shuffle(edges2.begin(), edges2.end());

	/* set H */
	vector<int> H(n, 1);
	for (int i = 0; i < n - 1; i++) {
		H[edges2[i].first]++;
	}
	
	/* set h_i */
	vector<vector<int>> h_i(n);
	for (int i = 0; i < n; i++) {
		if (H[i] == 1) {
			H[i] = rnd.next(1, s);
			continue;
		}
		h_i[i] = rnd.perm(H[i] - 1, 1);
		H[i] = rnd.next(H[i], max(H[i], s));
	}

	/* print */
	cout << n << '\n';
	for (int i = 0; i < n; i++) {
		cout << S[i] << ' ' << H[i] << '\n';
	}
	for (int i = 0; i < n - 1; i++) {
		cout << edges2[i].first + 1 << ' ' << edges2[i].second + 1 << ' ' << h_i[edges2[i].first].back() << '\n';
		h_i[edges2[i].first].pop_back();
	}
}