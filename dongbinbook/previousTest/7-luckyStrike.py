N = str(input())


def solution(n):
    size = len(n)
    a = 0
    b = 0
    for i in range(0, size // 2):
        a += int(n[i])

    for i in range(size // 2, size):
        b += int(n[i])

    if a == b:
        return "LUCKY"
    return "READY"


print(solution(N))