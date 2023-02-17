import sys
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))


def solve():
    L, R = 0, N - 1
    ret = 0

    while L <= R:
        ret = max(ret, (R - L - 1) * min(a[L], a[R]))
        if a[L] < a[R]:
            L += 1
        else:
            R -= 1

    return ret


print(solve())
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N명, 개발자 2명이 팀, 
- (A, B) 팀의 능력치 = A~B 사이 개발자 수 * min(A, B)
팀빌딩에서 나올수 있는 능력치 중 최대값

N 2~10만, Xi 1만

2. 
1 4 2 5
1 * min(4, 5) = 4

O(N^2) 미만으로 풀어야됨, 투포인터로 풀려면 정렬되어있어야됨
그리디하게 접근한다면 사이 갯수는 많아야 되고, 두 수는 다 커야된다. 
정렬을 해서 풀면 안됨. 사이 숫자 갯수를 알아야됨
두 수 사이의 거리? index 차 - 1

'''
