import java.util.*;

class Solution {
    String[] stoi = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    public int solution(String s) {
        for (int i = 0; i < 10; ++i) {
            s = s.replaceAll(stoi[i], Integer.toString(i));
        }
        return Integer.parseInt(s);
    }
}