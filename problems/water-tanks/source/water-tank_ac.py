from sys import stdin, setrecursionlimit
setrecursionlimit(10000)
input = stdin.readline

# input
N = int(input())
S = [0] * N
H = [0] * N
answer = [0] * N
childs = [[] for _ in range(N)]
for i in range(N):
    S[i], H[i] = map(int, input().split())

for _ in range(N - 1):
    p, c, h_i = map(int, input().split())
    p -= 1
    c -= 1
    childs[p].append((h_i, c))

def dfs(p, t):
    childs[p].sort()
    cur = t
    h = 0
    for h_i, c in childs[p]:
        cur += (h_i - h) * S[p]
        cur = dfs(c, cur)
        h = h_i
    cur += (H[p] - h) * S[p]
    answer[p] = cur
    return cur

dfs(0, 0)
print(*answer, sep='\n')