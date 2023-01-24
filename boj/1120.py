import sys
si = sys.stdin.readline

a, b = sorted(si().strip().split(), key=len)  # len(a) <= len(b)
ans = 0x3f3f3f3f

for i in range(0, len(b) - len(a) + 1):
    cnt = 0
    for j in range(i, i + len(a)):
        if a[j - i] != b[j]:
            cnt += 1
    ans = min(ans, cnt)
print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 문자열 x,y가 주어짐, x,y 길이가 같을 때 차이의 최소값 리턴
길이 50

2. 길이 50이하니까 kmp처럼 0 ~ len(b)-len(a) 부터 len(a)-1, len(b)-1 까지 탐색해서 차이가 제일 작은 값 리턴
'''
