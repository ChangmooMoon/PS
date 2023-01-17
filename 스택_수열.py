import sys
si = sys.stdin.readline

N = int(si())
st, ans = [0], []


def solve():
    p = 0  # 스택에 마지막으로 넣은 값
    for _ in range(N):
        num = int(si())
        if st[-1] < num:  # 스택 top이 더 작으면 값을 넣어준다
            for i in range(p + 1, num + 1):
                st.append(i)
                ans.append('+')
            if st[-1] != num:
                return False

            p = num
            st.pop()
            ans.append('-')
        else:  # 스택 top이 더 크면 찾을때까지 값을 pop한다
            while st[-1] != num:
                if st[-1] == 0:
                    return False
                st.pop()
                ans.append('-')
            st.pop()
            ans.append('-')
    return True


print(*ans, sep='\n') if solve() else print("NO")


'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 1~N을 순서대로 스택에 넣고, 주어진 수열을 만들때 그 수열을 만들 수 있는지
만들수 있으면 push+ pop- 연산을 어떻게 수행하는지 출력, 못만들면 NO 출력
'''
