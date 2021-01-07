data = input()


def solution(data):
    flip0 = 0
    flip1 = 0

    if data[0] == "0":
        flip0 += 1
    else:
        flip1 += 1

    for i in range(len(data) - 1):
        if data[i] != data[i + 1]:
            # 0 -> 1
            if data[i + 1] == "1":
                flip1 += 1
            # 1 -> 0
            else:
                flip0 += 1
    return min(flip0, flip1)


print(solution(data))