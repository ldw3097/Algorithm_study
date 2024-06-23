

n = int(input())
graph = {i:set() for i in range(1, n+1)}
for _ in range(n-1):
    a,b = map(int,input().split())
    graph[a].add(b)
    graph[b].add(a)

stack = []
visited = [False] * (n+1)
for i in range(1, n+1):
    if len(graph[i]) == 1:
        stack.append(i)

sol = 0
while stack:
    cur = stack.pop()
    if visited[cur]:
        continue
    parent = graph[cur].pop()
    sol += 1
    visited[parent] = True
    for child in graph[parent]:
        graph[child].discard(parent)
        if len(graph[child]) == 1:
            stack.append(child)
        elif len(graph[child]) == 0:
            visited[child] = True

print(sol)



