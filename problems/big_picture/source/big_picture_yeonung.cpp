#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, M;
    char S[5001], T[5001];
    cin >> N >> S >> M >> T;

    int left[5000] = {}, right[5000] = {};
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(S[i + j] == T[j])
                left[i + j] = max(left[i + j], j + 1);
            else
                break;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        for(int j = M - 1; j >= 0; j--) {
            if(S[i - ((M - 1) - j)] == T[j])
                right[i - ((M - 1) - j)] = max(right[i - ((M - 1) - j)], ((M - 1) - j) + 1);
            else
                break;
        }
    }

    bool yes = false;
    for(int i = 0; i < N; i++) {
        if(left[i] == M)
            yes = true;
        for(int j = i + 1; j < N; j++) {
            if(left[i] + right[j] == M) {
                yes = true;
                break;
            }
        }
        if(yes)
            break;
    }

    if(yes)
        cout << "YES";
    else
        cout << "NO";
}