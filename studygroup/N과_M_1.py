import sys
input = sys.stdin.readline

N, M = map(int, input().split())
list = []
visited = [False] * 9


def dfs(curr):
    if curr == M:
        for num in list:
            print(num, end=" ")
        print()
        return

    for i in range(1, N + 1):
        if visited[i]:
            continue
        visited[i] = True
        list.append(i)
        dfs(curr + 1)

        visited[i] = False
        list.pop()


dfs(0)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

#1. 1~N 중에서 중복없이 M개를 고른 수열을 모두 출력 
#2. 재귀적으로 dfs탐색을 해서 길이 M의 수열에 도달하면 출력하고 되돌아옴. 
#3. 수열 담을 배열, 방문체크 배열, 순열 nPm - 중복허용x, 순서 고려. 순서 바뀌면 다른 원소
#4. dfs(int curr) O(N!)
'''
