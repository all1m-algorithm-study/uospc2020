// https://codeforces.com/blog/entry/18291

#include <iostream>
#include <vector>
#include "testlib.h"

using namespace std;
using pi = pair<int, int>;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);

	int n = atoi(argv[1]);
	int t = atoi(argv[2]);
	int c = atoi(argv[3]);

	if (n == 1) n++;
	if (n % 2 == 1) n--;

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
	vector<pi> edges;
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

	/* set color */
	vector<int> color;
	for (auto k : rnd.perm(n / 2, c)) {
		color.push_back(k);
		color.push_back(k);
	}
	shuffle(color.begin(), color.end());

	cout << n << '\n';
	
	for (int i = 0; i < n - 1; i++) {
		cout << color[i] << ' ';
	}
	cout << color[n - 1] << '\n';

	for (int i = 0; i < n - 1; i++) {
		cout << edges[i].first + 1 << ' ' << edges[i].second + 1 << '\n';
	}
}