import sys
si = sys.stdin.readline

N, K = map(int, si().split())
s = list(map(int, si().split()))
d = list(map(lambda x: int(x) - 1, si().split()))  # order
p = [0] * N


for _ in range(K):
    for i in range(N):
        p[d[i]] = s[i]
    s = p[:]

print(*s, sep=' ')

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 
수가 적혀있는 N개의 카드 P
수가 하나씩 존재하는 D
d[i] = p[d[i]]
원래 카드의 배치 구하기

2.
d`[i] = p[d[i]]
d[i] = p`[d`[i]]
S에 대해서 역함수 연산을 K번 하면 원래 카드배치가 나옴

N 1만, K 1000 이니까
1000 * 1만 * 4 = 4000만? 시간초과. 더 줄여야됨
'''
