import sys
import bisect as bs
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
LIS = [a[0]]

for i in range(1, N):
    if LIS[-1] < a[i]:
        LIS.append(a[i])
    else:
        idx = bs.bisect_left(LIS, a[i])
        LIS[idx] = a[i]

print(len(LIS))
