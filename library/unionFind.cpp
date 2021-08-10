int find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}