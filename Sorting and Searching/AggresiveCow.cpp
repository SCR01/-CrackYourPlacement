#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceCows(const vector<int>& stalls, int n, int c, int minDist) {
    int count = 1; // Place first cow in the first stall
    int lastPos = stalls[0]; // The position of the last placed cow

    for (int i = 1; i < n; ++i) {
        if (stalls[i] - lastPos >= minDist) {
            count++;
            lastPos = stalls[i];
        }
        if (count == c) {
            return true;
        }
    }
    return false;
}

int largestMinDist(vector<int>& stalls, int n, int c) {
    sort(stalls.begin(), stalls.end());
    int lo = 1; // Minimum possible distance
    int hi = stalls[n-1] - stalls[0]; // Maximum possible distance
    int best = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canPlaceCows(stalls, n, c, mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return best;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; ++i) {
            cin >> stalls[i];
        }
        cout << largestMinDist(stalls, n, c) << endl;
    }
    return 0;
}