import java.util.*;
import java.util.regex.*;

class Solution {
    Map<String, Page> map = new HashMap<>();

    public int solution(String word, String[] pages) {
        Pattern wordP = Pattern.compile("\\b" + word + "\\b", Pattern.CASE_INSENSITIVE);
        Pattern homeP = Pattern.compile("<meta property=\"og:url\" content=\"https://(\\S*)\"/>");
        Pattern extP = Pattern.compile("<a href=\"https://(\\S*)\">");

        for (int i = 0; i < pages.length; ++i) {
            String html = pages[i];
            String homeURL;
            int baseScore;
            List<String> extLink = new ArrayList<>();

            Matcher homeMatcher = homeP.matcher(html);
            homeMatcher.find();
            homeURL = homeMatcher.group(1);

            String body = html.split("<body>")[1].split("</body>")[0].replaceAll("\\d", " ");
            baseScore = (int) wordP.matcher(body).results().count();

            Matcher extMatcher = extP.matcher(html);
            while (extMatcher.find()) {
                extLink.add(extMatcher.group(1));
            }

            map.put(homeURL, new Page(homeURL, i, baseScore, extLink));
        }

        for (Page page : map.values()) {
            for (String ext : page.extLink) {
                if (map.containsKey(ext)) {
                    Page extPage = map.get(ext);
                    extPage.linkScore += (double) page.baseScore / page.extLink.size();
                }
            }
        }

        int maxIdx = -1;
        double maxMatchingScore = -1;
        for (Page page : map.values()) {
            if (maxIdx == -1 || maxMatchingScore < page.getMatchingScore()) {
                maxIdx = page.idx;
                maxMatchingScore = page.getMatchingScore();
            }
        }

        return maxIdx;
    }

    class Page {
        String homeURL;
        int idx;
        int baseScore;
        List<String> extLink;
        double linkScore;

        Page(String homeURL, int idx, int baseScore, List<String> extList) {
            this.homeURL = homeURL;
            this.idx = idx;
            this.baseScore = baseScore;
            this.extLink = new ArrayList<>(extList);
            this.linkScore = 0;
        }

        double getMatchingScore() {
            return baseScore + linkScore;
        }
    }
}
