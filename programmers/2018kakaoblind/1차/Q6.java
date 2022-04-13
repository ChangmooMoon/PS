import java.util.*;

class Solution {
    public List<String> solution(int n, int[] arr1, int[] arr2) { // 16*16
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            String s = convertBase2(arr1[i] | arr2[i], n);
            ans.add(s);
        }
        return ans;
    }

    String convertBase2(int num, int len) {
        StringBuilder sb = new StringBuilder();
        while (num > 0) {
            if (num % 2 == 1)
                sb.append('#');
            else
                sb.append(' ');
            num /= 2;
        }

        if (sb.length() != len) {
            while (sb.length() != len) {
                sb.append(' ');
            }
        }
        return sb.reverse().toString();
    }
}
