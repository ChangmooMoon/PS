import sys
si = sys.stdin.readline

N, K = map(int, si().split())
q = [_ for _ in range(1, N + 1)]
ans = []

idx = 0
for i in range(N):
    idx = (idx + K - 1) % len(q)
    ans.append(q[idx])
    q.pop(idx)
print('<' + ', '.join(map(str, ans)) + '>')

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 1~N 사람이 원을 이루고, K번째 사람을 계속 제거했을 때, 해당 인덱스를 출력
2. 원형큐를 구현하면 됨. 큐에서 pop 된걸 다시 넣으면 원형큐가 됨. 그러다가 K번째로 뺀 수를 출력하고 넣지 않으면 된다
이렇게 해도 N = 5000 이므로 5000^2 = 2500만 -> 통과는 하는데 엄청 느렸음
음

2. 큐에 넣었다 뺐다 하지 말고 배열에서 해당 인덱스 값만 빼버리는게 더 빠른 경우이다
'''
