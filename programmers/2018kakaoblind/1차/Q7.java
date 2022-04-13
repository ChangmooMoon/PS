import java.util.*;

class Solution {
    public int solution(String dartResult) {
        int N = dartResult.length();

        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < N; ++i) {
            char now = dartResult.charAt(i);
            if (Character.isDigit(now)) {
                char next = dartResult.charAt(i + 1);
                if (now == '1' && next == '0') {
                    st.push(10);
                    ++i;
                } else {
                    st.push(now - '0');
                }
            } else { // now : S D T * #
                if (now == 'D') {
                    int fi = st.pop();
                    st.push(fi * fi);
                } else if (now == 'T') {
                    int fi = st.pop();
                    st.push(fi * fi * fi);
                } else if (now == '*') { // 해당점수, 바로전 점수 2배, st.size() == 1이면 앞에꺼만 2배
                    int fi = st.pop();
                    if (!st.isEmpty()) {
                        int se = st.pop();
                        st.push(se * 2);
                    }
                    st.push(fi * 2);
                } else if (now == '#') { // 해당점수 마이너스
                    int fi = st.pop();
                    st.push(fi * -1);
                }
            }
        }

        int ans = 0;
        while (!st.isEmpty()) {
            ans += st.pop();
        }
        return ans;
    }
}
