class Solution {
    public int solution(String s) {
        int ans = s.length();

        for (int i = 1; i <= s.length() / 2; ++i) {
            int len = go(s, i);
            if (ans > len)
                ans = len;
        }

        return ans;
    }

    int go(String s, int len) {
        String substr = s.substring(0, len);
        String tmp = "";
        String result = "";
        int cnt = 1;

        for (int i = len; i < s.length(); i += len) {
            if (i + len > s.length())
                tmp = s.substring(i, s.length());
            else
                tmp = s.substring(i, i + len);

            if (substr.equals(tmp)) {
                ++cnt;
            } else {
                if (cnt >= 2)
                    result += Integer.toString(cnt);
                result += substr;

                substr = tmp;
                cnt = 1;
            }
        }

        if (cnt >= 2)
            result += Integer.toString(cnt);
        result += substr;

        return result.length();
    }
}
