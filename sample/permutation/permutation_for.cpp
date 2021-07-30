void solve() {
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                archer[0] = i, archer[1] = j, archer[2] = k;
                kill();
            }
        }
    }
}
