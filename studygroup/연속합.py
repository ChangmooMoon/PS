import sys
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
d = [0 for _ in range(N)]

d[0] = a[0]
for i in range(1, N):
    d[i] = max(a[i], d[i - 1] + a[i])

print(max(d))

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 정수 중 연속된 몇개 합 중 가장 큰 합 찾기
N 10만, 10만^2 = 100억, O(N^2) 미만으로 풀어야됨

2. 부분배열의 최대합 문제 - kadane 알고리즘 
d[i] = i번째 원소인 부분 수열합 중 최댓값

d[1] = a[1]
d[i] = max(a[i], d[i - 1] + a[i])


'''
