import sys
si = sys.stdin.readline

N = int(si())
st = []

for _ in range(N):
    s = si().rstrip().split(' ')
    if s[0] == 'push':
        st.append(s[1])
    elif s[0] == 'pop':
        if not st:
            print(-1)
        else:
            print(st.pop())
    elif s[0] == 'size':
        print(len(st))
    elif s[0] == 'empty':
        if not st:
            print(1)
        else:
            print(0)
    elif s[0] == 'top':
        if not st:
            print(-1)
        else:
            print(st[-1])
