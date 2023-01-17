import sys
from heapq import *
si = sys.stdin.readline


def solve(a, target):
    hq = []
    for val in a:
        heappush(hq, -val)

    idx = 1
    while hq:
        for i in range(len(a)):
            if a[i] != -hq[0]:
                continue
            if i == target:
                return idx
            heappop(hq)
            idx += 1


N = int(si())
for _ in range(N):
    n, m = map(int, si().split())
    a = list(map(int, si().split()))
    print(solve(a, m))
