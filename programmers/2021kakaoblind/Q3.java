import java.util.*;

class Solution { // 4*3*3*3 = 108
    Map<String, Integer> parsed = new HashMap<>() {
        {
            put("-", 0);
            put("cpp", 1);
            put("java", 2);
            put("python", 3);
            put("backend", 1);
            put("frontend", 2);
            put("junior", 1);
            put("senior", 2);
            put("chicken", 1);
            put("pizza", 2);
        }
    };
    List<Integer>[][][][] a = new ArrayList[4][3][3][3];

    public int[] solution(String[] info, String[] query) { // 5만 + 10만
        int[] answer = new int[query.length];

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    for (int l = 0; l < 3; ++l)
                        a[i][j][k][l] = new ArrayList<>();

        for (String s : info) {
            StringTokenizer st = new StringTokenizer(s);
            int lang, pos, exp, food, score;
            lang = parsed.get(st.nextToken());
            pos = parsed.get(st.nextToken());
            exp = parsed.get(st.nextToken());
            food = parsed.get(st.nextToken());
            score = Integer.parseInt(st.nextToken());

            for (int i = 0; i < (1 << 4); ++i) { // 0000 ~ 1111
                int[] p = { lang, pos, exp, food };
                for (int j = 0; j < 4; ++j) {
                    if ((i & (1 << j)) == 0)
                        p[j] = 0;
                }
                a[p[0]][p[1]][p[2]][p[3]].add(score);
            }
        }

        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    for (int l = 0; l < 3; ++l)
                        Collections.sort(a[i][j][k][l]);

        for (int i = 0; i < query.length; ++i) {
            StringTokenizer st = new StringTokenizer(query[i]);
            int lang, pos, exp, food, score;
            lang = parsed.get(st.nextToken());
            st.nextToken();
            pos = parsed.get(st.nextToken());
            st.nextToken();
            exp = parsed.get(st.nextToken());
            st.nextToken();
            food = parsed.get(st.nextToken());
            score = Integer.parseInt(st.nextToken());
            answer[i] = getNum(a[lang][pos][exp][food], score);
        }

        return answer;
    }

    int getNum(List<Integer> list, int score) {
        if (list.isEmpty())
            return 0;
        int s = 0, e = list.size();
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (list.get(mid) >= score)
                e = mid;
            else
                s = mid + 1;
        }

        return list.size() - e;
    }
}
