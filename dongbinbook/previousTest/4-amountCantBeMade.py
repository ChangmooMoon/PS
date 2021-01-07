N = int(input())
coins = list(map(int, input().split()))
N = 5
coins = [3, 2, 1, 1, 9]


def solution(coins):
    coins.sort()
    for i in range(1, sum(coins) + 1):
        result = i
        for coin in reversed(coins):
            if i >= coin:
                i -= coin
        if i != 0:
            return result
    return sum(coins) + 1


print(solution(coins))
