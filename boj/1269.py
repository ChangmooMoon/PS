import sys
from typing import *
si = sys.stdin.readline

_, _ = map(int, si().split())
a = set(map(int, si().split()))
b = set(map(int, si().split()))

print(len((a | b) - (a & b)))
'''
1. 문제 읽기
2. 논리적 순서
3. 필요한 자료연산 리스트업
4. 자료형, 시간복잡도, 유리한 자료구조 선택
5. 구현
6. 엣지케이스

1. 집합 A, B가 있는데 대칭 차집합의 원소의 갯수 출력
'''
