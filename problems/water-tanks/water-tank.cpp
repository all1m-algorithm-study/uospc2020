#include <iostream>
#include <algorithm>
#include <vector>

struct ChildInfo
{
    int number;
    int pipeHeight;

    bool operator<(const ChildInfo& ch) const
    {
        return pipeHeight < ch.pipeHeight;
    }
};

int n;
int areas[10000], heights[10000];
std::vector<ChildInfo> children[10000];
int answer[10000];

int getTime(int node, int currTime)
{
    int bottom = 0;

    for (ChildInfo child : children[node])
    {
        int elapsed = (child.pipeHeight - bottom) * areas[node];
        currTime = getTime(child.number, currTime + elapsed);
        bottom = child.pipeHeight;
    }

    currTime += (heights[node] - bottom) * areas[node];
    answer[node] = currTime;
    return currTime;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        int s, h;
        scanf("%d %d", &s, &h);
        areas[i] = s;
        heights[i] = h;
    }

    for (int i = 0; i < n-1; ++i)
    {
        int u, v, h;
        scanf("%d %d %d", &u, &v, &h);
        children[u-1].push_back({v-1, h});
    }

    for (int i = 0; i < n; ++i)
        std::sort(children[i].begin(), children[i].end());
    
    getTime(0, 0);
    for (int i = 0; i < n; ++i)
        printf("%d\n", answer[i]);

    return 0;
}