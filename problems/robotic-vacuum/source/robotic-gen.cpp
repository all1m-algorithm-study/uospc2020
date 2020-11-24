#include "testlib.h"
#include <iostream>
#include <algorithm>

char map[100][101];
const char COND[4] = {'E', 'W', 'S', 'N'};

void generateCommand()
{
    int cType = rnd.next(0, 9);
    if (0 <= cType && cType <= 2)
        printf("L");
    else if (3 <= cType && cType <= 5)
        printf("R");
    else if (6 <= cType && cType <= 9)
        printf("G");
}

int generateStatement(int maxLength)
{
    int stType = rnd.next(0, 10);
    if (0 <= stType && stType <= 4 && maxLength >= 1)
    {
        generateCommand();
        return 1;
    }
    else if (maxLength >= 5)
    {
        if (5 <= stType && stType <= 6)
            printf("i%c{", COND[rnd.next(0, 3)]);
        else if (7 <= stType && stType <= 8)
            printf("w%c{", COND[rnd.next(0, 3)]);
        else if (9 <= stType && stType <= 10)
            printf("u%c{", COND[rnd.next(0, 3)]);

        int subLength = 0;
        while ((subLength += generateStatement(maxLength - 4)) == 0);
        printf("}");
        return 4 + subLength;
    }

    return 0;
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int w = atoi(argv[1]);
    if (w <= 0)
        w = rnd.next(1, 100);

    int h = atoi(argv[2]);
    if (h <= 0)
        h = rnd.next(1, 100);

    printf("%d %d\n", h, w);

    if (strcmp(argv[3], "random") == 0)
    {
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c)
                map[r][c] = rnd.next(0, 1) ? '.' : 'X';
    }
    else if (strcmp(argv[3], "sparse") == 0)
    {
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c)
                map[r][c] = rnd.next(0, 3) ? '.' : 'X';
    }
    else if (strcmp(argv[3], "empty") == 0)
    {
        for (int r = 0; r < h; ++r)
            for (int c = 0; c < w; ++c)
                map[r][c] = '.';
    }

    std::pair<int, int> s(0, 0), d(0, 0);
    
    while (s == d)
    {
        s.first = rnd.next(0, h-1);
        s.second = rnd.next(0, w-1);
        d.first = rnd.next(0, h-1);
        d.second = rnd.next(0, w-1);
    }

    map[s.first][s.second] = 'S';
    map[d.first][d.second] = 'D';

    for (int r = 0; r < h; ++r)
        printf("%s\n", map[r]);

    int maxLength = atoi(argv[4]);
    if (maxLength <= 0)
        maxLength = rnd.next(1, 500);

    if (strcmp(argv[5], "random") == 0)
    {
        int codeLength = 0, iterCount = 0;
        while ((codeLength += generateStatement(maxLength - codeLength)) < maxLength && iterCount++ < maxLength*2);
    }
    else if (strcmp(argv[5], "commandOnly") == 0)
    {
        for (int i = 0; i < maxLength; ++i)
            generateCommand();
    }
    printf("\n");

    return 0;
}
