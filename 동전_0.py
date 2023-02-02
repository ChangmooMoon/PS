import sys
si = sys.stdin.readline

N, K = map(int, si().split())
a = [int(si()) for _ in range(N)]

ans = 0
for v in a[::-1]:
    ans += K // v
    K %= v

print(ans)
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 동전 종류 N개, 갯수는 무한
동전 가치의 합을 K로 만들 때 필요한 동전 갯수의 최솟값
N 1~10, K 1억 a[i] 100만, a[i]는 a[i-1]의 배수

2. K가 1억이라서 dp로 못품 d[i] = 가치가 i인 동전의 최소갯수
그리디로 접근 최대가치 동전으로 만든다
동전 가치가 배수로 증가하니까 최대가치 동전부터 꽉 채워서 쓴다
'''
