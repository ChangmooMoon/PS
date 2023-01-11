import sys
input = sys.stdin.readline

N = int(input())
S = str(input())
val = {chr(i + 65): int(input()) for i in range(N)}
st = []

for ch in S:
    if 'A' <= ch <= 'Z':
        st.append(val[ch])
    elif ch == '+':
        st.append(st.pop() + st.pop())
    elif ch == '-':
        st.append(-st.pop() + st.pop())
    elif ch == '/':
        fi = st.pop()
        st.append(st.pop() / fi)
    elif ch == '*':
        st.append(st.pop() * st.pop())

print(f'{st[0]:.2f}')

'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 후위표기식을 연산해야됨. 대응하는 숫자가 주어지고 이거를 연산하면됨
2. char:int 대응하는 해시맵 하나 선언해서 대응하는 숫자로 연산
연산 순서는 스택으로 처리
'''
