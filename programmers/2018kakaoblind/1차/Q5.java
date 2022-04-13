import java.util.*;

class Solution {
    public int solution(int cacheSize, String[] cities) {
        if(cacheSize == 0) return cities.length * 5;
        
        LinkedHashMap<String, Integer> map = new LinkedHashMap<>(cacheSize, 1f, true) {
            @Override
            protected boolean removeEldestEntry(Map.Entry<String, Integer> eldest) {
                return size() > cacheSize;
            }
        };
        
        int ans = 0;
        for(String s: cities) {
            s = s.toLowerCase();
            if(!map.containsKey(s)) {
                map.put(s, 0);
                ans += 5;
            } else {
                map.get(s);
                ans += 1;
            }
        }
        
        return ans;
    }
}
