import sys
si = sys.stdin.readline

N = int(si())
a = list(map(int, si().split()))
b = list(map(int, si().split()))

a.sort()
b.sort(reverse=True)
ans = 0
for i in range(N):
    ans += a[i] * b[i]
print(ans)

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. s = a[0] * b[0] + ... + a[n - 1] * b[n - 1]
s를 가장 작게 만들기 위해 a를 재배열, s의 최솟값 리턴
N 1~50, ai, bi 0~100

b가 클수록 a를 작은값을 넣어주면 됨. 그 대응되는값을 어떻게 매칭?
최소값만 찾으면 되니까 a는 오름차순 정렬 b는 내림차순 정렬해서 결과값만 출력
'''
