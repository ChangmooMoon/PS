import sys
si = sys.stdin.readline

N = int(si())  # 도시 갯수
dist = list(map(int, si().split()))  # 도로 길이
price = list(map(int, si().split()))  # 주유소 리터당가격

ans = dist[0] * price[0]
p = 0  # 주유를 하는 지점
for i in range(1, N - 1):
    if price[p] >= price[i]:
        p = i
    ans += price[p] * dist[i]
print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 도시가 일직선도로. 왼쪽에서 오른쪽으로 이동
1킬로마다 1리터 기름이용. 도시마다 주유소, 가격 다름
기름통은 무제한. 제일 왼쪽에서 오른쪽으로 이동하는 최소비용 찾기

N 도시 갯수 2~10만, 도로길이 N-1개, 10억 이하 주유소 리터당 가격 10억 이하

2. N^2 = 100억 이니 NlogN 미만으로 풀어야됨

도로 2 3 1
가격 5 2 4 1

- 5*2 = 10, 2*3 = 6 2*1 = 2 -> 18
- 3 * 1 = 3, 3 * 1 = 3, 4 * 1 = 4 -> 10
- 오른쪽 도시에서 주유하는거보다 왼쪽이 싸면 도로길이만큼 더 넣는다로 접근
'''
