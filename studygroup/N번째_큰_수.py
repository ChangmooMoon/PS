import heapq
import sys
si = sys.stdin.readline

N = int(si())
a = []

for _ in range(N):
    tmp = list(map(int, si().split()))
    for i in tmp:
        heapq.heappush(a, i)
        if len(a) > N:
            heapq.heappop(a)

print(a[0])

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N*N 그리드, 모든 수는 자신의 한칸 위 숫자보다 크다. N번째 큰수는?
2. 그냥 다 배열로 받아서 정렬하면 될 것 같았는데 메모리 초과가 뜸. 메모리 제한이 빡빡한듯
값 하나씩 읽을 때마다 큰 숫자 N개만 업데이트하는 식으로 구현
'''
