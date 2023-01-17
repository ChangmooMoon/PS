import sys
from typing import *
si = sys.stdin.readline

N = int(si())


def isvps(s: str) -> bool:
    st = []
    for i in range(len(s)):
        if s[i] == '(':
            st.append(True)
        else:
            if not st:
                return False
            st.pop()
    return not st


for _ in range(N):
    s = str(input())
    print("YES") if isvps(s) else print("NO")
