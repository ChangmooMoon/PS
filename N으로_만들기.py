import sys
from typing import *
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

s = si().strip()
ans = set()


def dfs(L, R, ret):
    if len(ret) == len(s) * (len(s) + 1) // 2:
        ans.add(ret)
        return
    if L > 0:
        dfs(L - 1, R, ret + s[L - 1: R + 1])
    if R < len(s):
        dfs(L, R + 1, ret + s[L: R + 2])


for i in range(len(s)):
    dfs(i, i, s[i])

print(len(ans))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. int N을 만드는 방법의 수, 과정에서 나온 수가 순서대로 같으면 같은 방법
2. 재귀적으로 방문한 숫자를 제외하고 방문하는데, 방문한 숫자 순서가 같으면 방법에서 제외해야됨
N 길이 최대 8
'''
