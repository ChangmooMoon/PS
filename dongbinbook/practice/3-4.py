N, K = map(int, input().split())


def solution(n, k):
    result = 0
    while True:
        target = (n // k) * k  # -1 횟수
        result += n - target
        n = target
        if n < k:
            break
        n //= k
        result += 1  # 나누기 k 횟수
    result += n - 1
    return result


print(solution(N, K))
