import java.util.*;

// String.contains(seq)
class Solution {
    public String solution(String m, String[] musicinfos) {
        String ans = "(None)";
        int maxPTime = -1;

        m = convertSharp(m);
        for (String infos : musicinfos) {
            String[] info = infos.split(",");
            int s = convertTime(info[0]);
            int e = convertTime(info[1]);
            int playTime = e - s;
            String name = info[2];
            String code = convertSharp(info[3]);

            if (code.length() < playTime) {
                StringBuilder seq = new StringBuilder();
                for (int j = 0; j < playTime / code.length(); ++j) {
                    seq.append(code);
                }
                seq.append(code.substring(0, playTime % code.length()));
                code = seq.toString();
            } else {
                code = code.substring(0, playTime);
            }

            if (code.contains(m) && maxPTime < playTime) {
                ans = name;
                maxPTime = playTime;
            }
        }

        return ans;
    }

    String convertSharp(String s) {
        return s.replaceAll("C#", "c").replaceAll("D#", "d").replaceAll("F#", "f").replaceAll("G#", "g")
                .replaceAll("A#", "a");
    }

    int convertTime(String s) {
        return Integer.parseInt(s.substring(0, 2)) * 60 + Integer.parseInt(s.substring(3));
    }
}
