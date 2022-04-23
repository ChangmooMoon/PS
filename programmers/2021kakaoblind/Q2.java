import java.util.*;
import java.util.Map.*;

class Solution {
    Map<String, Integer>[] cnt = new HashMap[11];
    boolean[] check;

    public String[] solution(String[] orders, int[] course) {
        List<String> ans = new ArrayList<>();

        for (int i = 2; i <= 10; ++i) {
            cnt[i] = new HashMap<String, Integer>();
        }

        for (String order : orders) {
            char[] tmp = order.toCharArray();
            Arrays.sort(tmp);
            order = String.valueOf(tmp);
            check = new boolean[10];
            go(0, "", order);
        }

        for (int n : course) {
            if (cnt[n].isEmpty())
                continue;

            List<Entry<String, Integer>> eList = new ArrayList<Entry<String, Integer>>(cnt[n].entrySet());
            Collections.sort(eList, (a, b) -> b.getValue() - a.getValue());

            int max = eList.get(0).getValue();
            if (max < 2)
                continue;
            for (var e : eList) {
                if (e.getValue() == max)
                    ans.add(e.getKey());
                else
                    break;
            }
        }

        Collections.sort(ans);
        return ans.toArray(String[]::new);
    }

    void go(int idx, String pick, String order) {
        if (idx == order.length())
            return;

        int N = pick.length();
        if (N >= 2)
            cnt[N].put(pick, cnt[N].getOrDefault(pick, 0) + 1);

        for (int i = idx; i < order.length(); ++i) {
            if (check[i])
                continue;
            check[i] = true;
            go(i, pick + order.charAt(i), order);
            check[i] = false;
        }
    }
}
