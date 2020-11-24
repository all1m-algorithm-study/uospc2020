#include <iostream>
#include <vector>
#include <set>
#include <cstring>

const int MAP_MAX = 100;
const int SRC_MAX = 500;

const std::pair<int, int> axisDiff[] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
enum Direction { East, South, West, North };
enum ExecResult { OK, Loop, Finished };

struct Status
{
    int row, col;
    Direction dir;

    bool operator<(const Status& s) const
    {
        return (row*MAP_MAX*4 + col*4 + dir) < (s.row*MAP_MAX*4 + s.col*4 + s.dir);
    }

    Status moveForward()
    {
        Status newSt;
        std::pair<int, int> diff = axisDiff[dir];
        newSt.row = row + diff.first;
        newSt.col = col + diff.second;
        newSt.dir = dir;

        return newSt;
    }
};

class Statement
{
private:
    int id;
    char keyword;
    Direction condition;
    std::vector<Statement*> program;
    std::set<Status> history;

    bool isSatisfied(Status& st, char map[][MAP_MAX+1], int rowCount, int colCount)
    {
        Direction absDir = Direction(st.dir + ((condition - North + 4) % 4));
        int row = st.row + axisDiff[absDir].first;
        int col = st.col + axisDiff[absDir].second;
        
        return  row < 0 || rowCount <= row ||
                col < 0 || colCount <= col ||
                map[row][col] == 'X';
    }

public:
    Statement(char* source, int& index)
    {
        keyword = source[index++];
        if (keyword == 'i' || keyword == 'w' || keyword == 'u')
        {
            switch (source[index++])
            {
            case 'E':
                condition = East;
                break;
            case 'W':
                condition = West;
                break;
            case 'S':
                condition = South;
                break;
            case 'N':
                condition = North;
                break;
            }

            ++index;
            while (source[index] != '}')
                program.push_back(new Statement(source, index));
            ++index;
        }
    }

    ExecResult execute(Status& st, char map[][MAP_MAX+1], int rowCount, int colCount)
    {
        if (history.find(st) != history.end())
            return Loop;
        else if (map[st.row][st.col] == 'D')
            return Finished;
        
        history.insert(st);
        ExecResult subResult;

        switch (keyword)
        {
        case 'L':
            {
                st.dir = Direction((st.dir - 1 + 4) % 4);
                break;
            }
        case 'R':
            {
                st.dir = Direction((st.dir + 1) % 4);
                break;
            }
        case 'G':
            {
                Status newSt = st.moveForward();
                if (0 <= newSt.row && newSt.row < rowCount && 
                    0 <= newSt.col && newSt.col < colCount && 
                    map[newSt.row][newSt.col] != 'X')
                    st = newSt;
                break;
            }
        case 'i':
            {
                if (isSatisfied(st, map, rowCount, colCount))
                {
                    for (Statement* state : program)
                    {
                        subResult = state->execute(st, map, rowCount, colCount);
                        if (subResult != OK)
                            return subResult;
                    }
                }
                break;
            }
        case 'w':
            {
                while (isSatisfied(st, map, rowCount, colCount))
                {
                    for (Statement* state : program)
                    {
                        subResult = state->execute(st, map, rowCount, colCount);
                        if (subResult != OK)
                            return subResult;
                    }
                }
                break;
            }
        case 'u':
            {
                while (!isSatisfied(st, map, rowCount, colCount))
                {
                    for (Statement* state : program)
                    {
                        subResult = state->execute(st, map, rowCount, colCount);
                        if (subResult != OK)
                            return subResult;
                    }
                }
                break;
            }
        }

        return OK;
    }
};

int R, C;
char map[MAP_MAX][MAP_MAX+1];
char source[SRC_MAX+1];

int main()
{
    scanf("%d %d", &R, &C);

    Status st;
    st.dir = North;
    for (int r = 0; r < R; ++r)
    {
        scanf("%s", map[r]);
        for (int c = 0; c < C; ++c)
        {
            if (map[r][c] == 'S')
            {
                st.row = r;
                st.col = c;
            }
        }
    }
    
    scanf("%s", source);
    int length = strlen(source);
    std::vector<Statement*> program;
    for (int i = 0; i < length;)
        program.push_back(new Statement(source, i));
    
    ExecResult result;
    for (int i = 0; ; i = (i+1) % int(program.size()))
    {
        result = program[i]->execute(st, map, R, C);
        if (result != OK)
            break;
    }

    if (result == Finished)
        printf("TERMINATED");
    else printf("LOOP FOREVER");

    return 0;
}
