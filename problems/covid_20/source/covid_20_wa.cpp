#include <iostream>
#include <queue>

using namespace std;

const long long INF = 1000000000;
const int MAXN = 100000;
int curr_max[MAXN + 1];
vector<pair<int, int>> adj[MAXN + 1];
queue<int> q;
bool inq[MAXN + 1];

void push(int i) {
    if(!inq[i]) {
        q.push(i);
        inq[i] = true;
    }
}

int pop() {
    int front = q.front();
    q.pop();
    inq[front] = false;
    return front;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, l;
    cin >> n >> m >> l;

    for(int i=1; i<=m; i++) {
        curr_max[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int infected;
        cin >> infected;
        curr_max[infected] = INF;
        push(infected);
    }

    for(int i=0; i<l; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    while(!q.empty()) {
        int here = pop();
        for(auto there_weight : adj[here]) {
            int there = there_weight.first;
            int weight = there_weight.second;
            if(weight < curr_max[here] && curr_max[there] < weight) {
                curr_max[there] = weight;
                push(there);
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=m; i++) {
        if(curr_max[i] != -1)
            cout << i << '\n';
    }
}