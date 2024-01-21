#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int zeros, ones;
};

class SegmentTree {
private:
    vector<Node> tree;
    vector<int> lazy;
    int n;

    void buildTree(const vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {a[tl] == 0, a[tl] == 1};
        } else {
            int tm = (tl + tr) / 2;
            buildTree(a, 2 * v, tl, tm);
            buildTree(a, 2 * v + 1, tm + 1, tr);
            mergeNodes(v);
        }
    }

    void mergeNodes(int v) {
        tree[v].zeros = tree[2 * v].zeros + tree[2 * v + 1].zeros;
        tree[v].ones = tree[2 * v].ones + tree[2 * v + 1].ones;
    }

    void applyLazy(int v, int tl, int tr) {
        if (lazy[v] != 0) {
            swap(tree[v].zeros, tree[v].ones);

            if (tl != tr) {
                lazy[2 * v] ^= 1;
                lazy[2 * v + 1] ^= 1;
            }

            lazy[v] = 0;
        }
    }

    void flipRange(int v, int tl, int tr, int l, int r) {
        applyLazy(v, tl, tr);

        if (r < tl || tr < l) {
            return;
        }

        if (l <= tl && tr <= r) {
            lazy[v] ^= 1;
            applyLazy(v, tl, tr);
            return;
        }

        int tm = (tl + tr) / 2;
        flipRange(2 * v, tl, tm, l, r);
        flipRange(2 * v + 1, tm + 1, tr, l, r);
        mergeNodes(v);
    }

    int query(int v, int tl, int tr, int l, int r) {
        applyLazy(v, tl, tr);

        if (r < tl || tr < l) {
            return 0;
        }

        if (l <= tl && tr <= r) {
            return tree[v].zeros;
        }

        int tm = (tl + tr) / 2;
        int left = query(2 * v, tl, tm, l, r);
        int right = query(2 * v + 1, tm + 1, tr, l, r);

        return left + right;
    }

public:
    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        buildTree(a, 1, 0, n - 1);
    }

    void flipElement(int index) {
        flipRange(1, 0, n - 1, index, index);
    }

    int queryRange(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    int n, q, m;
    cin >> n >> q >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    SegmentTree segmentTree(a);

    long long totalOperations = 0;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int index,z;
            cin >> index;
            cin>>z;
            segmentTree.flipElement(index - 1);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            totalOperations += segmentTree.queryRange(l - 1, r - 1);
        }
    }

    cout << totalOperations << endl;

    return 0;
}
