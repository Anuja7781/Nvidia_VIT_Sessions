#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& a, int k) {

    unordered_map<long long, int> freq;

    long long prefixSum = 0;
    int count = 0;

    freq[0] = 1;

    for (int num : a) {

        prefixSum += num;

        long long required = prefixSum - k;

        if (freq.find(required) != freq.end()) {
            count += freq[required];
        }

        freq[prefixSum]++;
    }

    return count;
}

int main() {

    vector<int> a = {1, 2, 3};
    int k = 3;

    cout << subarraySum(a, k);

    return 0;
}