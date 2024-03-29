import sys
si = sys.stdin.readline
MOD = 10007

N = int(si())
d = [[0] * 10 for _ in range(1001)]

for i in range(10):
    d[1][i] = 1

for i in range(2, N + 1):
    for j in range(10):
        if j == 0:
            d[i][0] = 1
        else:
            d[i][j] = (d[i - 1][j] + d[i][j - 1]) % MOD

ans = 0
for i in range(10):
    ans += d[N][i]

print(ans % MOD)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 오르막수: 수의 자리가 오름차순을 이루는 수, 숫자가 같아도 오름차순임
길이 N이 주어졌을 떄 오르막수 갯수를 구하는 프로그램. 수는 0으로 시작 가능
N 1000

2. 
길이 1000이니까 2^1000 안됨
d[i] = 길이가 i인 오르막수의 갯수

d[1] = {0 1 2 3 4 5 6 7 8 9} 10
d[2] = {01~09, 11~19, 22~29, 33~39, 44~49, 55~59, 66~69, 77~79, 88, 89, 99} 45
d[3] = {001~099, 111~199, 222~299, 333~399, 444~499, 555~599, 666~699, 777~799, 888~899, 999}

2. d[i][j] = 길이가 i이고 ,j로 끝나는 오르막수 갯수

d[1] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} 0 1 2 3 4 5 6 7 8 9
d[2] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} 00, 01 11, 02 12 22, .. 09~99

d[i][j] = d[i - 1][j] + d[i][j - 1]

'''
