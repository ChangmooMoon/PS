data = input()


def solution(data):
    result = list()
    sum = 0
    for i in data:
        if i.isalpha():
            result += i
        elif i.isdigit():
            sum += int(i)

    result.sort()

    if sum != 0:
        result += str(sum)
    return "".join(result)


print(solution(data))