from collections import *
import sys
from typing import *
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

s = str(si().strip())
team = [-1] * len(s)
ans = set()

st = deque()
p = 0
for idx, val in enumerate(s):
    if val == '(':
        st.append(p)
        team[idx] = p
        p += 1
    elif val == ')':
        team[idx] = st.pop()


def dfs(ret: str, idx: int, paren: int):
    if idx == len(s):
        if paren != (1 << p) - 1:
            ans.add(ret)
        return

    if s[idx] == '(':
        dfs(ret + '(', idx + 1, paren | (1 << team[idx]))
        dfs(ret, idx + 1, paren)
    elif s[idx] == ')':
        if paren & (1 << team[idx]):
            dfs(ret + ')', idx + 1, paren)
        else:
            dfs(ret, idx + 1, paren)
    else:
        dfs(ret + s[idx], idx + 1, paren)


dfs("", 0, 0)
ans = list(ans)
ans.sort()
print(*ans, sep='\n')
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 괄호 제거해서 나올 수 있는 서로 다른 식들 출력.
수식 길이 200, 괄호쌍 10개
쌍이 되는 괄호끼리 제거해야됨

2. 재귀적으로 한쌍 씩 제거해나가면서 출력한다?
쌍이 되는 괄호를 제거해야되는데 그냥 여는 괄호만 카운트하면서 하니까 최근에 연 괄호를 제거하는게 안됨
괄호가 최대 10개니까 2^10 = 1024, 1024개의 괄호 제거 경우의 수를 dfs로 표현

6. (((0)))
중복되는 결과를 뺴야되서 set으로 중복처리
'''

