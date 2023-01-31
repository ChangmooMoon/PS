import sys
si = sys.stdin.readline

s = si().strip()
nums, ops, curr = [], [], 0
for ch in s:
    if '0' <= ch <= '9':
        curr = curr * 10 + int(ch)
    else:
        ops.append(ch)
        nums.append(curr)
        curr = 0
nums.append(curr)

a = [nums[0]]
p = 0
for i in range(len(ops)):
    if ops[i] == '+':
        a[p] += nums[i + 1]
    else:
        p += 1
        a.append(nums[i + 1])

ans = a[0]
for n in a[1:]:
    ans -= n
print(ans)


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 수식에 괄호 씌웠을 때 최소값
2. 
- op, num 분리
- +연산 먼저 다 하고 - 연산한다
'''
