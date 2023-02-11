import sys
si = sys.stdin.readline
sys.setrecursionlimit(10**6)

N = int(si())
L = [0] * 27
R = [0] * 27

for _ in range(N):
    curr, left, right = si().rstrip().split()
    if left != '.':
        L[ord(curr) - ord('A') + 1] = ord(left) - ord('A') + 1
    if right != '.':
        R[ord(curr) - ord('A') + 1] = ord(right) - ord('A') + 1


def preOrder(curr):  # 전위 - 루왼오
    if not curr:
        return

    print(chr(curr + ord('A') - 1), end='')
    preOrder(L[curr])
    preOrder(R[curr])


def inOrder(curr):  # 중위 - 왼루오
    if not curr:
        return

    inOrder(L[curr])
    print(chr(curr + ord('A') - 1), end='')
    inOrder(R[curr])


def postOrder(curr):  # 후위 왼오루
    if not curr:
        return
    postOrder(L[curr])
    postOrder(R[curr])
    print(chr(curr + ord('A') - 1), end='')


preOrder(1)
print()
inOrder(1)
print()
postOrder(1)
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 트리 주어지고, 전위순회, 중위순회, 후위순회 출력

'''
