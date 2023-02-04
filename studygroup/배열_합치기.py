import sys
si = sys.stdin.readline

N, M  = map(int, si().split())
a = list(map(int, si().split()))
b = list(map(int, si().split()))
ret = []

i, j = 0, 0
while i < N and j < M:
    if a[i] <= b[j]:
        ret.append(a[i])
        i += 1
    else:
        ret.append(b[j])
        j += 1

print(*ret + a[i:N] + b[j:M])
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 정렬된 두 배열 A, B 합쳐서 출력
A 크기 N, B 크기 M, 100만
'''