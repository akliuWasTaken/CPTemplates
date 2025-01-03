// Original header by Phùng Đức Minh Manager on usaco.guide
// Basically just added comments and changed stuff based on my preference

const int MAXN = 2e5;
ll a[MAXN], st[4 * MAXN], lazy[4 * MAXN];
void build(int idx, int left, int right) {
	// If our segment bounds hit each other, return the actual value.
    if (left == right) {
        st[idx] = a[left];
        return;
    }

	// Consider the two child segments for recursion. 
    int mid = (left + right) / 2;
    build(idx * 2 + 1, left, mid); 
    build(idx * 2 + 2, mid + 1, right);

	// CHANGE THIS BASED ON OPERATION!!!
    st[idx] = st[idx * 2 + 1] + st[idx * 2 + 2]; 
}
 
void push(int idx, int left, int right) {
    if (lazy[idx] != 0) {
		// Compute total segment gain.
		// CHANGE BASED ON OPERATION!!!
        st[idx] += (right - left + 1) * lazy[idx];

		// If it's not a leaf, propogate to the children.
        if (left != right) {
            lazy[idx * 2 + 1] += lazy[idx];
            lazy[idx * 2 + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}
 
void update(int idx, int left, int right, int u, int v, ll val) {
	// Push the lazy values into our update,
	// they might be children of previous pushes. 
    push(idx, left, right);

	// If bounds dont work, return.
    if (right < u || v < left) return;

	// If segment is completely contained, update the lazy value and push. 
    if (u <= left && right <= v) {
        lazy[idx] += val;
        push(idx, left, right);
        return;
    }

	// If segment is not completely contained, split them. 
    int mid = (left + right) / 2;
    update(idx * 2 + 1, left, mid, u, v, val);
    update(idx * 2 + 2, mid + 1, right, u, v, val); 

	// CHANGE THIS BASED ON OPERATION!!!
    st[idx] = st[idx * 2 + 1] + st[idx * 2 + 2];
}
 
ll query(int idx, int left, int right, int u, int v) {
	// Push any pending lazy updates, just in case or something. 
    push(idx, left, right);

	// EDIT RETURN VALUE BASED ON OPERATOR!
	// EX: For multiplication, return 1, for addition, return 0, for min, return INF.
    if (right < u || v < left) return 0;

	// If it's completely in the range, return it. 
    if (u <= left && right <= v) return st[idx];

	// If it's split between ranges, compute that. 
    int mid = (left + right) / 2;
    ll q1 = query(idx * 2 + 1, left, mid, u, v);
    ll q2 = query(idx * 2 + 2, mid + 1, right, u, v);

	// CHANGE THIS BASED ON OPERATION!!!
    return q1 + q2;
}

// Notable uses below:
// Firstly, just input the array a[] before the build during solve();

// Build:                  build(0, 0, n-1);
// Builds the segment tree, given the starting index (usually 0), with a segment bound (usually 0, n-1).

// Range Update:                 update(0, 0, n-1, left, right, val);
// Point Update:                 update(0, 0, n-1, left, left, val);
// Updates the segment tree by using a range update. 
// To do point updates, set left = right instead. 

// Range Query:                  query(0, 0, n-1, left, right);
// Point Query:                  query(0, 0, n-1, left, left);
// For range query, we just find the operation's effect over [left, right].
// For a point query, set left = right. 

// Push:                   push(pos, s_left, s_right);
// Not actually called in main() usually, this is to push our pending values in a lazy array. 
