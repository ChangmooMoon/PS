class Solution {
    public String solution(String p) {
        if (p.isEmpty())
            return p;

        int pos = getBalancePos(p);
        String u = p.substring(0, pos);
        String v = p.substring(pos);

        if (isCorrect(u))
            return u + solution(v);

        StringBuilder newu = new StringBuilder();
        for (int i = 1; i < u.length() - 1; ++i) {
            if (u.charAt(i) == '(')
                newu.append(')');
            else
                newu.append('(');
        }

        return "(" + solution(v) + ")" + newu.toString();
    }

    int getBalancePos(String s) {
        int open = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(')
                ++open;
            else
                --open;
            if (open == 0)
                return i + 1;
        }

        return s.length();
    }

    boolean isCorrect(String s) {
        int open = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(')
                ++open;
            else
                --open;
            if (open < 0)
                return false;
        }

        return open == 0;
    }
}
