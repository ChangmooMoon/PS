import java.util.*;

class Solution {
    public String solution(String new_id) {
        new_id = new_id.toLowerCase().replaceAll("[^\\w\\-\\_\\.]", "").replaceAll("\\.{2,}", ".")
                .replaceAll("^\\.|\\.$", "");

        if (new_id.isEmpty())
            new_id = "a";
        if (new_id.length() >= 16) {
            new_id = new_id.substring(0, 15).replaceAll("\\.$", "");
        }
        if (new_id.length() <= 2) {
            new_id += new_id.substring(new_id.length() - 1).repeat(3 - new_id.length());
        }

        return new_id;
    }
}
