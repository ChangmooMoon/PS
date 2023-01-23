import sys
si = sys.stdin.readline

d = [0] * 11
d[0] = d[1] = 1
d[2] = 2
for i in range(3, 11):
    d[i] = d[i - 3] + d[i - 2] + d[i - 1]

T = int(si())
for _ in range(T):
    N = int(si())
    print(d[N])


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 정수 N를 1,2,3의 합으로 나타내는 방법
2. d[i] = i를 1,2,3 합으로 나타내는 방합
d[i] = d[i - 1] + d[i - 2] + d[i - 3] (i >= 3)
d[0] = d[1] = 1
d[2] = 2

'''
