import java.util.*;
import java.util.regex.*;

class Solution {
    public int solution(String word, String[] pages) { // 1500^2 * 20 = 4000만
        Map<String, Page> map = new HashMap<>();

        Pattern home = Pattern.compile("<meta property=\"og:url\" content=\"(\\S*)\"");
        Pattern extUrl = Pattern.compile("<a href=\"https://(\\S*)\"");
        Pattern wordp = Pattern.compile("\\b" + word + "\\b", Pattern.CASE_INSENSITIVE);

        for (int i = 0; i < pages.length; ++i) {

        }
    }

    class Page {
        int idx;
        String url;
        ArrayList<String> extUrls = new ArrayList<>();
        double baseScore, linkScore;

        Page(int idx, String url) {
            this.idx = idx;
            this.url = url;
        }

        void setExternalUrls(List<String> urls) {
            extUrls.addAll(urls);
        }

        void setLinkScore() {
            this.linkScore = this.baseScore / extUrls.size();
        }
    }
}