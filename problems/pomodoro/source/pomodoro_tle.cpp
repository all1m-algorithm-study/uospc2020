#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int m, a, b, ans;
	cin >> m >> a >> b;
	ans = 0;
	while (m) {
		ans += min(a, m);
		m -= min(a, m);
		m -= min(b, m);
	}
	cout << ans << '\n';
}