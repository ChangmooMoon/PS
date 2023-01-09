import sys
input = sys.stdin.readline

N, M = map(int, input().split())
list = []


def dfs(curr, pick):
    if pick == M:
        for num in list:
            print(num, end=" ")
        print()
        return

    for i in range(curr, N + 1):
        list.append(i)
        dfs(i, pick + 1)
        list.pop()


dfs(1, 0)  # H(n, m)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

#1. 1~N 중에 M개를 고른 수열을 모두 출력, 중복허용, 구성이 같으면 같은 원소
#2. 재귀적으로 dfs탐색을 해서 길이 M의 수열에 도달하면 출력하고 되돌아감
#3. 수열 담을 배열
'''
