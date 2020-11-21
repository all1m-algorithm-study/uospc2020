#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int l = atoi(argv[3]);
    int c_min = atoi(argv[4]);
    int c_max = atoi(argv[5]);

    assert(1 <= n && n <= m);
    assert(1 <= m && m <= 100000);
    assert(0 <= l && l <= 100000);
    assert(0 <= c_min && c_min <= c_max && c_max <= 1000000000);

    vector<int> num_list(m + 1);
    for (int i = 1; i <= m; i++)
        num_list[i] = i;

    cout << n << ' ' << m << ' ' << l << '\n';

    // n명의 확진자 출력
    for (int i = 1; i <= n - 1; i++) {
        int rnd_num = rnd.next(i, m);
        swap(num_list[i], num_list[rnd_num]);
        cout << num_list[i] << ' ';
    }
    cout << num_list[n] << '\n';

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < l; i++) {
        int a = rnd.next(1, m - 1);
        int b = rnd.next(a + 1, m);
        int c = rnd.next(c_min, c_max);
        edges.emplace_back(a, b, c);
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i < l; i++) {
        assert(edges[i - 1] != edges[i]);
    }

    ::shuffle(edges.begin(), edges.end());

    // edges 출력
    for (auto edge : edges) {
        if (rnd.next(0, 1) == 0)
            cout << get<0>(edge) << ' ' << get<1>(edge) << ' ' << get<2>(edge) << '\n';
        else
            cout << get<1>(edge) << ' ' << get<0>(edge) << ' ' << get<2>(edge) << '\n';
    }

    return 0;
}