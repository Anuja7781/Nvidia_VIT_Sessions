#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

int shortestSubarray(vector<int>& a, int K) {

    int n = a.size();

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    deque<int> dq;
    int minLength = INT_MAX;

    for (int j = 0; j <= n; j++) {

        while (!dq.empty() &&
               prefix[j] - prefix[dq.front()] >= K) {

            minLength = min(minLength, j - dq.front());
            dq.pop_front();
        }

        while (!dq.empty() &&
               prefix[dq.back()] >= prefix[j]) {

            dq.pop_back();
        }

        dq.push_back(j);
    }

    if (minLength == INT_MAX)
        return -1;

    return minLength;
}

int main() {

    vector<int> a = {2, -1, 2, -1, 2, 3};
    int K = 5;

    cout << shortestSubarray(a, K);

    return 0;
}