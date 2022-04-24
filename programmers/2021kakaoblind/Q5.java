class Solution {
    public String solution(String play_time, String adv_time, String[] logs) {
        int pTime = getTime(play_time);
        int advTime = getTime(adv_time);

        int[] d = new int[100 * 3600];

        for (String s : logs) {
            int start = getTime(s.substring(0, 8));
            int end = getTime(s.substring(9));

            for (int i = start; i < end; ++i) {
                ++d[i];
            }
        }

        int ans = 0;
        long rangeSum = 0, maxSum = 0;
        for (int i = 0; i < advTime; ++i) {
            rangeSum += d[i];
        }
        maxSum = rangeSum;

        for (int i = advTime; i < pTime; ++i) {
            rangeSum += d[i] - d[i - advTime];

            if (rangeSum > maxSum) {
                ans = i - advTime + 1;
                maxSum = rangeSum;
            }
        }

        return String.format("%02d:%02d:%02d", ans / 3600, ans / 60 % 60, ans % 60);
    }

    int getTime(String s) {
        int h = Integer.parseInt(s.substring(0, 2));
        int m = Integer.parseInt(s.substring(3, 5));
        int ss = Integer.parseInt(s.substring(6));
        return h * 3600 + m * 60 + ss;
    }
}
