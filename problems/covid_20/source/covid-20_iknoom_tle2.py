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
adj = [[] for _ in range(m + 1)]
for i in range(l):
    u, v, t = sweep[i]
    stack.append((u, v))
    if i == l - 1 or sweep[i + 1][2] != t:
        covid_queue = []
        vst = set()
        # insert edge
        for u, v in stack:
            if is_covid[u]:
                covid_queue.append(u)
                vst.add(u)
            if is_covid[v]:
                covid_queue.append(v)
                vst.add(v)
            adj[v].append(u)
            adj[u].append(v)
        # bfs
        for u in covid_queue:
            for v in adj[u]:
                if v in vst:
                    continue
                vst.add(v)
                is_covid[v] = True
                covid_queue.append(v)
        # erase edge
        for u, v in stack:
            adj[u] = []
            adj[v] = []
        stack = []

# output
for i in range(1, m + 1):
    if is_covid[i]:
        print(i)