import sys
from typing import *
input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]


def getDiff(i) -> int:
    t1, t2 = [], []
    s1, s2 = 0, 0

    for j in range(N):
        if i & (1 << j):
            t1.append(j)
        else:
            t2.append(j)

    if len(t1) != len(t2):
        return sys.maxsize

    for j in range(N // 2):
        for k in range(j + 1, N // 2):
            s1 += board[t1[j]][t1[k]] + board[t1[k]][t1[j]]
            s2 += board[t2[j]][t2[k]] + board[t2[k]][t2[j]]

    return abs(s1 - s2)


def solve() -> int:
    ret = sys.maxsize
    for i in range(1 << N):
        ret = min(ret, getDiff(i))

    return ret


print(solve())

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N명을 두팀으로 나눔. 사람조합에 따라 능력치가 바뀜 S(i, j), S(j, i)가 팀능력치에 더해짐
두팀능력치 최소로 만들어야됨, 능력치차 최소값을 출력
N명 4~20, 2차원 배열

2. 20C10 = 18만개 조합에 대해서 각각의 팀 능력치 차를 구하자
3. 비트마스킹으로 탐색해도 2^20 = 104만 밖에 안되서 완전탐색
팀이 반으로 갈리는지 체크연산, 팀능력치 차를 구하는 연산
'''
