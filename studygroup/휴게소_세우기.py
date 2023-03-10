import sys
si = sys.stdin.readline

N, M, L = map(int, si().split())
a = list(map(int, si().split()))
a.append(0)
a.append(L)
a.sort()

st, en = 1, L
ans = 0

while st <= en:
    mid = (st + en) // 2
    cnt = 0  # 사이에 넣을 수 있는 휴게소 갯수

    for i in range(1, N + 2):
        d = a[i] - a[i - 1]  # 간격
        if d > mid:
            cnt += (d - 1) // mid

    if cnt > M:
        st = mid + 1
    else:
        en = mid - 1
        ans = mid

print(ans)
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 휴게소 N개, 시작으로부터 거리 주어짐 여기에 M개 더 세움
휴게소가 없는 구간의 길이의 최대값을 최소로 하려고 함

N 0~50, M 1~100, L 100~1000
휴게소 위치 1~L-1

2. 정렬해서, 구간을 만들어서 최대힙에 넣고, 그걸 반으로 쪼개서 넣는다?
반레가 있어서 안됨

2. 
반으로 나누는 케이스 - 1개 건설
제일 큰 구간 / 2 <= 2번째 큰 구간
3등분하는 케이스 - 2개 건설
제일 큰 구간 / 2 > 2번째로 큰 구간

정수로 처리해야되네...
'''
