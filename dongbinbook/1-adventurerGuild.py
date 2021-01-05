n = int(input())
data = list(map(int, input().split()))


def solution(n, data):
    result = 0
    count = 0

    data.sort()
    for i in data:
        count += 1
        if count >= i:
            result += 1
            count = 0
    return result


print(solution(n, data))
