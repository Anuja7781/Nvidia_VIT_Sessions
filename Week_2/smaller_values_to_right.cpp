#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, int>>& a, int left, int mid, int right,
           vector<int>& ans) {

    vector<pair<int, int>> temp;

    int i = left;
    int j = mid + 1;
    int rightCount = 0;

    while (i <= mid && j <= right) {

        if (a[j].first < a[i].first) {
            temp.push_back(a[j]);
            rightCount++;
            j++;
        }
        else {
            ans[a[i].second] += rightCount;
            temp.push_back(a[i]);
            i++;
        }
    }

    while (i <= mid) {
        ans[a[i].second] += rightCount;
        temp.push_back(a[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(a[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        a[left + k] = temp[k];
    }
}

void mergeSort(vector<pair<int, int>>& a, int left, int right,
               vector<int>& ans) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid, ans);
    mergeSort(a, mid + 1, right, ans);

    merge(a, left, mid, right, ans);
}

vector<int> smallerToRight(vector<int>& nums) {

    int n = nums.size();

    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++) {
        a.push_back({nums[i], i});
    }

    vector<int> ans(n, 0);

    mergeSort(a, 0, n - 1, ans);

    return ans;
}

int main() {

    vector<int> a = {5, 2, 6, 1, 2};

    vector<int> ans = smallerToRight(a);

    for (int x : ans)
        cout << x << " ";

    return 0;
}