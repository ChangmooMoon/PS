import sys
si = sys.stdin.readline

N = int(si())
a = []
for _ in range(N):
    s, e = map(int, si().split())
    a.append((s, e))
a.sort(key=lambda x: (x[1], x[0]))

ans, curr_end = 0, 0
for st, en in a:
    if curr_end <= st:
        curr_end = en
        ans += 1

print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 회의 안겹치게 할 수 있는 최대갯수
N 1~10만, 시작 끝시간 0~int

2. 시간을 배열로 처리 못함 21억
회의 갯수 10만 회의 포함 or 포함 안함 2^10만, 포함여부 체크 10만^2= 100억, O(N^2) 미만으로 풀어야
그리디하게 접근. 끝나는시간 순으로 정렬, 끝나는 시간이 같으면 시작이 빠른 순으로 정렬해서 안겹치는 회의만 사용
'''
