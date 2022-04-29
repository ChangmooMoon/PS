class Solution {
    public int solution(String s) {
        if(s.length() == 1) return 1;

            int answer = 1001;
            for (int i = 1; i <= s.length() / 2; i++) {
                String now, cut = "", result = "";
                int match = 1;
                
                for (int j = 0; j <= s.length() / i; j++) {
                    int start = j * i;
                    int end = i * (j + 1) > s.length() ? s.length() : i * (j + 1);
                    now = cut;
                    cut = s.substring(start, end);

                    if(now.equals(cut)) {
                        ++match;
                    } else {
                        result += (match > 1 ? Integer.toString(match): "") + now;
                        match = 1;
                    }
                }
                result += (match > 1 ? Integer.toString(match) : "") + cut;
                answer = Math.min(answer, result.length());
            }

            return answer;
     }
}
