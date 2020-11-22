#include <iostream>
#include <algorithm>
#include <vector>

typedef long long Long;

struct ChildInfo
{
    int number;
    Long pipeHeight;

    bool operator<(const ChildInfo& ch) const
    {
        return pipeHeight < ch.pipeHeight;
    }
};

int n;
Long areas[10000], heights[10000];
std::vector<ChildInfo> children[10000];
Long answer[10000];

Long getTime(int node, Long currTime)
{
    Long bottom = 0;

    for (ChildInfo child : children[node])
    {
        Long elapsed = (child.pipeHeight - bottom) * areas[node];
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
        Long s, h;
        scanf("%lld %lld", &s, &h);
        areas[i] = s;
        heights[i] = h;
    }

    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        Long h;
        scanf("%d %d %lld", &u, &v, &h);
        children[u-1].push_back({v-1, h});
    }

    for (int i = 0; i < n; ++i)
        std::sort(children[i].begin(), children[i].end());
    
    getTime(0, 0);
    for (int i = 0; i < n; ++i)
        printf("%lld\n", answer[i]);

    return 0;
}