#include <iostream>

using namespace std;

const int INF = 1000000000, MAXN = 5000;
int card[MAXN + 1], sum[MAXN + 1], d[MAXN + 1][MAXN + 1];

int get_max(int l, int r) {
    if (d[l][r] != -INF)
        return d[l][r];

    if (l + 1 == r)
        return d[l][r] = card[l] + card[r];

    int l2 = card[l] + card[l + 1] + sum[r] - sum[l + 1] - get_max(l + 2, r);
    int r2 = card[r - 1] + card[r] + sum[r - 2] - sum[l - 1] - get_max(l, r - 2);
    int l1r1 = card[l] + card[r] + sum[r - 1] - sum[l] - get_max(l + 1, r - 1);
    return max(max(l2, r2), l1r1);
}

int main() {
    for (int i = 1; i <= MAXN; i++)
        for (int j = 1; j <= MAXN; j++)
            d[i][j] = -INF;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> card[i];
        sum[i] = sum[i - 1] + card[i];
    }

    cout << get_max(1, n);
}