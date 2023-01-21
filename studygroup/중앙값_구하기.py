from collections import *
import heapq
import sys
from typing import *
si = sys.stdin.readline


def go(arr: list):
    minh, maxh = [], []
    mid = arr[0]
    ret = [arr[0]]

    for i, v in enumerate(arr[1:], 1):
        if v > mid:
            heapq.heappush(maxh, v)
        else:
            heapq.heappush(minh, -v)
        if not i % 2:
            if len(minh) < len(maxh):
                heapq.heappush(minh, -mid)
                mid = heapq.heappop(maxh)
            elif len(minh) > len(maxh):
                heapq.heappush(maxh, mid)
                mid = -heapq.heappop(minh)
            ret.append(mid)

    print(len(ret))
    for i in range(len(ret)):
        if i != 0 and (i + 1) % 10 == 1:
            print()
        print(ret[i], end=' ')
    print()


T = int(si())
for _ in range(T):
    M = int(input())
    arr = []

    for _ in range(M // 10 + bool(M % 10)):
        arr.extend(list(map(int, si().split())))

    go(arr)
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.
이때 이 두가지 규칙을 유지해 준다면 항상 최대 힙 top값이 중간값이 된다.
'''
