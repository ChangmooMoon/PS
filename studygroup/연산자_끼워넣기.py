import sys
input = sys.stdin.readline

N = int(input())
nums = list(map(int, input().split()))
op = list(map(int, input().split()))  # + - * //
ans = []


def dfs(curr, res, op1, op2, op3, op4):
    if not any([op1, op2, op3, op4]):
        ans.append(res)
        return

    if op1:
        dfs(curr + 1, res + nums[curr], op1 - 1, op2, op3, op4)
    if op2:
        dfs(curr + 1, res - nums[curr], op1, op2 - 1, op3, op4)
    if op3:
        dfs(curr + 1, res * nums[curr], op1, op2, op3 - 1, op4)
    if op4:
        if res < 0:
            dfs(curr + 1, -(-res // nums[curr]), op1, op2, op3, op4 - 1)
        else:
            dfs(curr + 1, res // nums[curr], op1, op2, op3, op4 - 1)


def solve():
    dfs(1, nums[0], op[0], op[1], op[2], op[3])
    ans.sort()
    return str(ans[-1]) + '\n' + str(ans[0])


print(solve())


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. N개의 수, N-1개 연산자 +-*/, 만들수 있는 최대값, 최소값 출력
-5//2 = 3 이니까 양수로 바꿔서 몫구하고 -처리해야
N 2~11, +-*/ 각각 갯수

2. dfs로 연산자를 하나씩 끼워넣어서 모든 조합 경우의 수로 연산한다. 
모든 결과값 소팅해서 최대최소 하나씩 출력
dfs(result, curr, op[4])
'''
