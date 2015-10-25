def visit(i, graph, visited):
    queue      = [i]
    size       = 1
    visited[i] = 1

    while queue:
        current = queue.pop()
        for child in graph[current]:
            if not visited[child]:
                queue.append(child)
                visited[child]=1
                size+=1

    return size


n,l = map(int, raw_input().split())
graph = [set() for i in xrange(n)]

for _ in xrange(l):
    a,b = map(int, raw_input().split())
    graph[a].add(b)
    graph[b].add(a)

visited = [False]*n
ans = 0

for i in xrange(n):
    if not visited[i]:
        size = visit(i,graph,visited)
        ans+=(size*(size-1))/2
        
print (n*(n-1))/2-ans
