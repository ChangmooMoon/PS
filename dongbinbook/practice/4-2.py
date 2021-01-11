hour = int(input())  # 0~23


def solution(hour):
    result = 0
    for h in range(hour + 1):
        for m in range(60):
            for s in range(60):
                if "3" in str(h) + str(m) + str(s):
                    result += 1
    return result


print(solution(hour))