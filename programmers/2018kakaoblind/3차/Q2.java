import java.util.*;

// 해싱, 문자열 파싱 substring
class Solution {
    public List<Integer> solution(String msg) {
        int N = msg.length();
        List<Integer> ans = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        int p = 1;
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            map.put(ch + "", p++);
        }

        for (int i = 0; i < N; ++i) {
            int width = 1;
            while (i + width <= N && map.containsKey(msg.substring(i, i + width))) {
                ++width;
            }
            if (i + width > N) {
                ans.add(map.get(msg.substring(i)));
                break;
            }

            ans.add(map.get(msg.substring(i, i + width - 1)));
            map.put(msg.substring(i, i + width), p++);
            if (width > 1)
                i += width - 2;
        }

        return ans;
    }
}
