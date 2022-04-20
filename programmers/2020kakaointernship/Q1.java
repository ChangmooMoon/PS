class Solution {
    int[][] pos = { { 3, 1 }, { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
            { 2, 2 } };
    String Hand;
    int[] left = { 3, 0 };
    int[] right = { 3, 2 };

    public String solution(int[] numbers, String hand) {
        StringBuilder ans = new StringBuilder();
        Hand = hand;

        for (int n : numbers) {
            ans.append(solve(n));
        }
        return ans.toString();
    }

    char solve(int n) {
        if (n == 1 || n == 4 || n == 7) {
            left = pos[n];
            return 'L';
        } else if (n == 3 || n == 6 || n == 9) {
            right = pos[n];
            return 'R';
        } else {
            int[] target = pos[n];
            int leftDist = Math.abs(left[0] - target[0]) + Math.abs(left[1] - target[1]);
            int rightDist = Math.abs(right[0] - target[0]) + Math.abs(right[1] - target[1]);
            if (leftDist > rightDist) {
                right = target;
                return 'R';
            } else if (leftDist < rightDist) {
                left = target;
                return 'L';
            } else {
                if (Hand.equals("right")) {
                    right = target;
                    return 'R';
                } else {
                    left = target;
                    return 'L';
                }
            }
        }
    }
}
