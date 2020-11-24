#include <bits/stdc++.h>

#define MAXN 300001

using namespace std;

int color[MAXN];
set<int> adj[MAXN];
map<int, int> leaf;
bool alive[MAXN];
int n_alive;
bool pushed[MAXN];

void push_and_check(int i);

void erase_node(int i) {
    n_alive--;
    alive[i] = false;
    if(!adj[i].empty()) {
        int j = *adj[i].begin();
        adj[j].erase(i);
        if (adj[j].size() == 1) {
            push_and_check(j);
        }
    }
}

void push_and_check(int i) {
    if(pushed[i])
        return;
    pushed[i] = true;
    if (leaf[color[i]] == 0) {
        leaf[color[i]] = i;
    } else {
        if(alive[leaf[color[i]]])
            erase_node(leaf[color[i]]);
        if(alive[i])
            erase_node(i);
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> color[i];
    }
    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    fill_n(alive + 1, N, true);
    n_alive = N;
    for (int i = 1; i <= N; i++) {
        if (adj[i].size() == 1) {
            push_and_check(i);
        }
    }

    cout << n_alive << '\n';
    for (int i = 1; i <= N; i++) {
        if (alive[i]) {
            cout << i << ' ';
        }
    }
}

// 31분 WA
