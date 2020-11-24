#include <bits/stdc++.h>

#define MAXRC 502

using namespace std;

char wall[MAXRC][MAXRC];
int d[2][MAXRC][MAXRC];

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int W, H, N;
    cin >> W >> H >> N;
    for(int r=1; r<=H; r++) {
        cin >> (wall[r] + 1);
    }

    int max_width[MAXRC] = {};

    for(int r=1; r<=H; r++) {
        for(int c=1; c<=W; c++) {
            if(wall[r][c] == '.') {
                d[1][r][c] = d[1][r][c-1] + 1;
                max_width[1] = max(max_width[1], d[1][r][c]);
            }
        }
    }

    for(int h=2; h<=H; h++) {
        for(int r=1; r<=H; r++) {
            for(int c=1; c<=W; c++) {
                if(wall[r][c] == '.') {
                    d[h % 2][r][c] = d[(h-1) % 2][r-1][c] != 0 ? d[h % 2][r][c-1] + 1 : 0;
                    max_width[h] = max(max_width[h], d[h % 2][r][c]);
                }
            }
        }
    }

    vector<int> answer;

    for(int i=1; i<=N; i++) {
        int a, b;
        cin >> a >> b;
        if(max_width[b] >= a) {
            answer.push_back(i);
        }
    }

    cout << answer.size() << '\n';
    for(int a : answer) {
        cout << a << ' ';
    }

    return 0;
}