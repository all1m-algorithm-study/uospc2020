#include <iostream>
#include <vector>

int w, h, n;
char wall[1000][1001];

bool isAbleToPut(int width, int height, int row, int col)
{
    for (int dr = 0; dr < height; ++dr)
        for (int dc = 0; dc < width; ++dc)
            if (wall[row + dr][col + dc] == 'X')
                return false;
    
    return true;
}

bool isPossible(int width, int height)
{
    for (int row = 0; row <= h-height; ++row)
        for (int col = 0; col <= w-width; ++col)
            if (isAbleToPut(width, height, row, col))
                return true;
    
    return false;
}

int main()
{
    scanf("%d %d %d", &w, &h, &n);

    for (int r = 0; r < h; ++r)
        scanf("%s", wall[r]);
    
    std::vector<int> answer;
    for (int i = 0; i < n; ++i)
    {
        int width, height;
        scanf("%d %d", &width, &height);
        if (isPossible(width, height))
            answer.push_back(i+1);
    }

    printf("%d\n", (int)answer.size());
    for (int nTh : answer)
        printf("%d ", nTh);

    return 0;
}