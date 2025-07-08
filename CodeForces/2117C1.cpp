#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> total_count;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_count[a[i]]++;
        }

        unordered_map<int, int> seen_count;
        int active = 0, segments = 0;
        set<int> current_elements;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            seen_count[x]++;
            total_count[x]--;

            current_elements.insert(x);

            // If this was the last occurrence of x, remove from active tracking
            if (total_count[x] == 0) {
                current_elements.erase(x);
            }

            // If current segment elements are empty, we can cut
            if (current_elements.empty()) {
                segments++;
            }
        }

        cout << segments << '\n';
    }
    return 0;
}


