data = list(map(int, input()))


def solution(arr):
    result = 0
    for i in data:
        if i <= 1 or result <= 1:
            result += i
        else:
            result *= i
    return result


print(solution(data))
