class Solution {
    int M, N;

    public boolean solution(int[][] key, int[][] lock) {
        M = key.length;
        N = lock.length;

        int[][] Lock = new int[N + 2 * M][N + 2 * M];
        for (int i = M; i < M + N; ++i) {
            for (int j = M; j < M + N; ++j) {
                Lock[i][j] = lock[i - M][j - M];
            }
        }

        for (int k = 0; k < 4; ++k) {
            key = rotate(key);

            for (int i = 0; i < M + N; ++i) {
                for (int j = 0; j < M + N; ++j) { // 시작점
                    int[][] lockcpy = new int[Lock.length][Lock.length];
                    for (int l = 0; l < Lock.length; ++l) {
                        System.arraycopy(Lock[l], 0, lockcpy[l], 0, Lock.length);
                    }

                    if (isOK(lockcpy, key, i, j))
                        return true;
                }
            }
        }

        return false;
    }

    int[][] rotate(int[][] key) {
        int[][] ret = new int[M][M];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                ret[i][j] = key[j][M - 1 - i];
            }
        }

        return ret;
    }

    boolean isOK(int[][] Lock, int[][] key, int r, int c) {
        for (int i = r; i < r + M; ++i) {
            for (int j = c; j < c + M; ++j) {
                Lock[i][j] += key[i - r][j - c];
            }
        }

        for (int i = M; i < M + N; ++i) {
            for (int j = M; j < M + N; ++j) {
                if (Lock[i][j] != 1)
                    return false;
            }
        }
        return true;
    }
}
