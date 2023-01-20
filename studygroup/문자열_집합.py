import sys
si = sys.stdin.readline

N, M = map(int, si().split())
str_set = set([str(si()) for _ in range(N)])
ans = 0

for _ in range(M):
    ans += int(si() in str_set)

print(ans)


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N, M 1~10000이 주어짐. M개 문자열 중에 집합 S에 포함되는 것 몇개?
문자열 소문자, 길이 최대 500, 여러번x

2. 해시셋에 문자열이 포함되어 있는지 체크, 포함되면 +1
'''
