import heapq
from collections import *

class Solution:
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        connection1 = defaultdict(list)
        connection2 = defaultdict(list)
        for a,b,w in edges:
            if w == -1:
                connection1[a].append((b, 1, True))
                connection1[b].append((a, 1, True))
            else:
                connection1[a].append((b, w, False))
                connection1[b].append((a, w, False))
                connection2[a].append((b, w, False))
                connection2[b].append((a, w, False))
        def dijk(connection):
            hq = [(0, source, [])]
            visited = set()
            while hq:
                acc, loc, var = heapq.heappop(hq)
                if loc in visited:
                    continue
                visited.add(loc)
                if loc == destination:
                    return acc, var
                for nloc, w, isvar in connection[loc]:
                    if isvar:
                        nextvar = var + [(loc, nloc)]
                    else:
                        nextvar = var
                    heapq.heappush(hq, (acc+w, nloc, nextvar))
            return 9876543210, []
        nacc, nvar  = dijk(connection2)
        if nacc < target:
            return []
    
        acc, var = dijk(connection1)
        if acc > target:
            return []
        def setedge(targetedge, val):
            for edge in edges:
                a,b,w = edge
                if (a,b) == targetedge or (b,a) == targetedge:
                    edge[2] = val
                    return
        if var != []:
            for targetedge in var:
                setedge(targetedge, 1)
            setedge(var[0], target - acc+1)
        for edge in edges:
            if edge[2] == -1:
                edge[2] = 987654321
        return edges

