import sys
input = sys.stdin.readline

N, M = map(int, input().split())
visited = [False] * 9


def dfs(curr, pick):
    if pick == M:
        for i in range(1, 9):
            if visited[i]:
                print(i, end=' ')
        print()
        return

    for i in range(curr + 1, N + 1):
        if visited[i]:
            continue

        visited[i] = True
        dfs(i, pick + 1)
        visited[i] = False


dfs(0, 0)  # nCm

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

#1. 1~N중에서 중복없이 M개를 고른 수열 출력 1~8
#2. 재귀적으로 길이 M의 수열에 도달하면 출력하고 되돌아감. 오름차순으로 출력해야되서 중복제거해야됨
#3. 중복제거용 방문체크배열, dfs nCm
#4. 조합 - 중복허용x, 순서 고려x. 구성이 같으면 같은 원소, O(2^N)
'''
