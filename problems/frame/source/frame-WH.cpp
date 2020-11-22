#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

int w, h, n;
char wall[1000][1001];
int distToCeil[1000][1000];
int maxWidth[1001];

void findRectanglesFromHist(int bottom)
{
    std::stack<std::pair<int, int>> s;
    s.emplace(distToCeil[bottom][0], 0);
    for (int i = 1; i < w; ++i)
    {
        while (!s.empty() && distToCeil[bottom][i] < s.top().first)
        {
            std::pair<int, int> prev = s.top();
            s.pop();
            int height = prev.first;
            int width = (s.empty() ? i : i - s.top().second - 1);
            maxWidth[height] = std::max(maxWidth[height], width);
        }

        s.emplace(distToCeil[bottom][i], i);
    }

    while (!s.empty())
    {
        std::pair<int, int> prev = s.top();
        s.pop();
        int height = prev.first;
        int width = (s.empty() ? w : w - s.top().second - 1);
        maxWidth[height] = std::max(maxWidth[height], width);
    }
}

int main()
{
    scanf("%d %d %d", &w, &h, &n);

    for (int r = 0; r < h; ++r)
        scanf("%s", wall[r]);
    
    for (int c = 0; c < w; ++c)
    {
        distToCeil[0][c] = (wall[0][c] == 'X' ? 0 : 1);
        for (int r = 1; r < h; ++r)
        {
            if (wall[r][c] == 'X')
                distToCeil[r][c] = 0;
            else distToCeil[r][c] = distToCeil[r-1][c] + 1;
        }
    }

    for (int r = 0; r < h; ++r)
        findRectanglesFromHist(r);
    
    std::vector<int> answer;
    for (int i = 0; i < n; ++i)
    {
        int width, height;
        scanf("%d %d", &width, &height);
        if (width <= maxWidth[height])
            answer.push_back(i+1);
    }

    printf("%d\n", (int)answer.size());
    for (int nTh : answer)
        printf("%d ", nTh);

    return 0;
}