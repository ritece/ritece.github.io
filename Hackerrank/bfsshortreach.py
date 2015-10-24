t=input()

for _ in xrange(t):
    n,m = map(int,raw_input().split())
    graph = [set() for i in xrange(n+1)]
    for i in xrange(m):
        a,b=map(int,raw_input().split())
        graph[a].add(b)
        graph[b].add(a)
    start = input()

    q=[start]
    level=[-1]*(n+1)
    visited=[0]*(n+1)
    level[start]=0
    while q:
            current = q.pop(0)
            for child in graph[current]:
                if visited[child]==0:
                         level[child]=level[current]+1
                         q.append(child)
                         visited[child]=1
            visited[current] = 1

    for i in xrange(1,n+1):
        if i!=start:
            if level[i]!=-1:
                print 6*level[i],
            else:
                print -1,
    print             
