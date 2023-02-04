import sys
si = sys.stdin.readline

N, K = map(int, si().split())
a = list(map(int, si().split()))

i, j = 0, K - 1
curr_sum = sum(a[:K])
max_sum = curr_sum

for e in range(j + 1, N):
    curr_sum += a[e] - a[i]
    i += 1
    max_sum = max(max_sum, curr_sum)

print(max_sum)


    

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 연속적인 몇일 동안의 온도의 합이 가장 큰 값 리턴
2. 투포인터로 범위 이동하면서 O(N)
'''