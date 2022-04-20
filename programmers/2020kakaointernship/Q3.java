import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        Set<String> set = new HashSet<>(Arrays.asList(gems));

        Map<String, Integer> map = new HashMap<>(); // 중복체크
        Queue<String> q = new LinkedList<>(); // seq 체크
        int s = 0, len = gems.length, p = 0;

        for (String gem : gems) {
            map.put(gem, map.getOrDefault(gem, 0) + 1);
            q.add(gem);

            while (map.get(q.peek()) > 1) {
                String tGem = q.poll();
                map.put(tGem, map.get(tGem) - 1);
                ++p;
            }

            if (map.size() == set.size()) {
                if (len > q.size()) {
                    s = p;
                    len = q.size();
                }
            }
        }

        return new int[] { s + 1, s + len };
    }
}
