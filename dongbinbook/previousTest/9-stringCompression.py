import math

s1 = "a a b b a c c c"  # length8 -> csize7
# 2a2ba3c
s2 = "ababcdcd ababcdcd"  # length16 -> csize 8
# 2ababcdcd
s3 = "abc abc ded e"  # length10 -> csize 8
# 3abcdede
s4 = "abcabc abcabc dedede dedede"  # length24 -> csize 14
# 2abcabc2dedede
s5 = "xababcdcdababcdcd"  # length17 -> csize 17(x)


def solution(s):
    answer = len(s)
    tryDiv = len(s) // 2
    

solution(s1)