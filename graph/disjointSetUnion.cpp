const int MAX_N = 2e5;
int father[MAX_N], height[MAX_N], sizes[MAX_N];

void init() {
    for (int i = 0; i < N; ++i) {
        father[i] = i;
        sizes[i] = 1;
        height[i] = 0;
    }
}
 
int find(int x) {
    if (father[x] != x) x = find(father[x]);
    return x;
}
 
int sizefind(int x) {
    if (father[x] != x) x = sizefind(father[x]);
    return sizes[x];
}
 
void unite(int A, int B) {
    int rootA = find(A);
    int rootB = find(B);
    if (rootA == rootB) return;
    if (height[rootA] > height[rootB]) {
        father[rootB] = rootA;
        height[rootA] = max(rootA, rootB + 1);
        sizes[rootA] += sizes[rootB];
    } else {
        father[rootA] = rootB;
        height[rootB] = max(rootB, rootA + 1);
        sizes[rootB] += sizes[rootA];
    }
}

// Notable Uses:

// MAX_N:                   Change this accordingly.
// Sizes:                   Find the size of each Disjoint Set. Comment out if needed. 

// Init:                    init();
// Find:                    find(node);
// Size Find:               sizefind(node);
// Unite:                   unite(a, b);
