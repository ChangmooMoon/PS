import sys
si = sys.stdin.readline

N = int(si())
a = []
for _ in range(N):
    a.append(int(si()))
a.sort()

ans = 0
for k in range(1, N + 1):  # 전체에서 k개 고른다
    ans = max(ans, a[N - k] * k)
print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N 1~10만 개의 로프, 들 수 있는 중량이 다름
k개의 로프를 이용하면 w무게를 들 때 w/k만큼 중량이 걸림
로프들을 이용해서 들 수 있는 중량의 최대 무게

2. 사용할지 안할지 2^10만, 사용여부 체크 10만^2, O(N^2) 미만으로 풀어야
그리디하게 접근.  
1~N개 중에서 k개를 고른다고 하면 
가장 쎈 밧줄 K개 중에서 가장 약한 밧줄 중량 * K만큼 버팀
'''
