def solution(n, arr1, arr2):
    ans = []
    for i in range(n):
        # arr1[i], arr2[i]
        ret = []
        a, b = format(arr1[i], 'b'), format(arr2[i], 'b')
        a = '0' * (n - len(a)) + a
        b = '0' * (n - len(b)) + b
        for j in range(n):
            ret.append(' ' if a[j] == '0' and b[j] == '0' else '#')
        ans.append(''.join(ret))

    return ans
