#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input
    long long n = 0;
    cin >> n;
    vector<long long> value(n, 0);
    for (long long i = 0; i < n; i++) {
        cin >> value[i];
    }

    if (n == 1) {
        cout << 2 * value[0] << endl;
        return 0;
    }

    // Stastic
    vector<long long> cnt(n, 0);
    for (long long i = 0; i < n - 1; i++) {
        long long tempA = 0, tempB = 0;
        cin >> tempA >> tempB;
        cnt[tempA - 1]++, cnt[tempB - 1]++;
    }

    vector<long long> result(0, 0);
    for (long long i = 0; i < n; i++) {
        if (cnt[i] == 1) {
            result.push_back(value[i]);
        }
    }

    // for (long long i = 0; i < cnt.size(); i++) {
    //     cout << cnt[i];
    // }

    // for (long long i = 0; i < result.size(); i++) {
    //     cout << result[i] << " ";
    // }

    long long ans = 0;
    for (long long i = 0; i < result.size(); i++) {
        ans += result[i];
    }
    if (result.size() % 2 != 0) {
        sort(value.begin(), value.end());

        ans += value[0];
    }

    cout << ans;

    return 0;
}
