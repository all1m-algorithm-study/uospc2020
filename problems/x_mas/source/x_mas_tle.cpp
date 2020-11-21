#include <iostream>
#include <string>

#define INF 987654321

using namespace std;

int n;
string a;

inline char toggle(char c) {
    return c == '0' ? '1' : '0';
}

int dfs(int i, int cnt) {
    if(i == n - 1) {
        bool fail = false;
        for(int j=0; j<n; j++)
            if(a[j] == '0') {
                fail = true;
                break;
            }
        if(!fail)
            return cnt;
        else
            return INF;
    }

    int cnt1 = dfs(i+1, cnt);

    a[i] = toggle(a[i]);
    a[i+1] = toggle(a[i+1]);
    int cnt2 = dfs(i+1, cnt+1);
    a[i] = toggle(a[i]);
    a[i+1] = toggle(a[i+1]);

    return min(cnt1, cnt2);
}

int main() {
    cin >> n;
    cin >> a;

    int cnt = dfs(0, 0);

    if (cnt == INF)
        cout << -1;
    else
        cout << cnt;
}