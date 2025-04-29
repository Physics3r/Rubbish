#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<int> bit;

int lowbit(int x) {
    return x & (-x);
}

void add(int index, int value) {
    for (; index <= n; index += lowbit(index)) {
        bit[index] += value;
    }
}

int query(int index) {
    int ans = 0;
    for (; index > 0; index -= lowbit(index)) {
        ans += bit[index];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    bit.resize(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int temp;
        cin >> temp;
        add(i, temp);
    }

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) {
            add(l, r);
        } else {
            cout << query(r) - query(l - 1) << endl;
        }
    }

    return 0;
}
