from sys import stdin
input = stdin.readline

# input
n, m, l = map(int, input().split())
covid = list(map(int, input().split()))
sweep = [tuple(map(int, input().split())) for _ in range(l)]

# covid to is_covid
is_covid = [False] * (m + 1)
for t in covid:
    is_covid[t] = True

# sort
sweep.sort(key=lambda x:x[2], reverse=True)

# sweeping
stack = []
for i in range(l):
    u, v, t = sweep[i]
    if is_covid[u] or is_covid[v]:
        is_covid[u] = True
        is_covid[v] = True
    else:
        stack.append((u, v))
    if i == l - 1 or sweep[i + 1][2] != t:
        while True:
            is_in_covid = False
            nxt = []
            for u, v in stack:
                if is_covid[u] or is_covid[v]:
                    is_in_covid = True
                    is_covid[u] = True
                    is_covid[v] = True
                else:
                    nxt.append((u, v))
            if not is_in_covid:
                break
            stack = nxt
        stack = []

# output
for i in range(1, m + 1):
    if is_covid[i]:
        print(i)