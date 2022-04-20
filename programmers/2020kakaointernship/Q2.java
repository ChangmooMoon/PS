import java.util.*;

class Solution {
    char[] ch = { '+', '-', '*' };
    List<Character> order = new ArrayList<>();
    boolean[] check = new boolean[3];

    long ans = -1L;
    String[] nums;
    char[] op;

    public long solution(String expression) {
        nums = expression.split("\\+|\\*|-");
        op = expression.replaceAll("\\d", "").toCharArray();
        go(0);
        return ans;
    }

    void go(int p) {
        if (p == 3) {
            long ret = calcExp();
            if (ans == -1 || ans < ret)
                ans = ret;
            return;
        }

        for (int i = 0; i < 3; ++i) {
            if (check[i])
                continue;
            check[i] = true;
            order.add(ch[i]);
            go(p + 1);
            order.remove(order.size() - 1);
            check[i] = false;
        }
    }

    long calcExp() { // 우선순위 order, 숫자 nums, 연산자 op
        List<Long> num = new ArrayList<>();
        List<Character> oper = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            num.add(Long.parseLong(nums[i]));
        }
        for (int i = 0; i < op.length; ++i) {
            oper.add(op[i]);
        }

        for (int i = 0; i < 3; ++i) { // 우선순위 order
            for (int j = 0; j < oper.size(); ++j) { // 연산자 oper
                if (oper.get(j) == order.get(i)) {
                    if (oper.get(j) == '+')
                        num.set(j, num.get(j) + num.get(j + 1));
                    else if (oper.get(j) == '-')
                        num.set(j, num.get(j) - num.get(j + 1));
                    else
                        num.set(j, num.get(j) * num.get(j + 1));

                    num.remove(j + 1);
                    oper.remove(j);
                    --j;
                }
            }
        }
        return Math.abs(num.get(0));
    }
}
