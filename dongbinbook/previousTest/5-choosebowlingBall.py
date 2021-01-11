# 공 N개, 1~M 무게 범위 정수
# 5 3
# 1 3 2 3 2
# --> 8

N, M = map(int, input().split())
data = list(map(int, input().split()))


def solution(n, m, data):
    count = 0
    for i in range(n):
        for j in range(i + 1, n):
            if data[i] != data[j]:
                count += 1
    return count


print(solution(N, M, data))
