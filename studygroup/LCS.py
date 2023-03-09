import sys
si = sys.stdin.readline

s1, s2 = ' ' + si().rstrip(), ' ' + si().rstrip()
d = [[0] * 1001 for _ in range(1001)]

for i in range(1, len(s1)):
    for j in range(1, len(s2)):
        if s1[i] == s2[j]:
            d[i][j] = d[i - 1][j - 1] + 1
        else:
            d[i][j] = max(d[i - 1][j], d[i][j - 1])

print(max(max(d)))
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. LCS구하기
문자열 2개 주어지고. 가장 긴 공통부분 수열 찾기
len 1000

2. 
d[i][j] = s1 i, s2 j까지 있을 때 공통부분의 최대 길이
d[i][j] = 
'''
