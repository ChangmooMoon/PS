import sys
si = sys.stdin.readline
inf = 0x3f3f3f3f

N = int(si())
d = [inf] * (N + 1)

d[0] = 0
for i in range(3, N + 1):
    if d[i - 3] == inf and d[i - 5] == inf:
        continue
    else:
        d[i] = min(d[i - 3], d[i - 5]) + 1

print(d[N] if d[N] != inf else -1)
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N킬로를 3, 5킬로 봉지로 들고가야됨. 최소 갯수 구하기
N 3~5000, 정확하게 N킬로 못만들면 -1 출력

2. 
d[i] = i를 3킬로, 5킬로로 나눈 최소갯수
d[i] = min(d[i - 3] if not i % 3, d[i - 5] if not i % 5) + 1
d[0] = 0 d[1] = 0 d[2] = 0 d[3] = 1 d[4] = 0 d[5] = 1
'''
