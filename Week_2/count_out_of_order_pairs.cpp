#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& a, int left, int mid, int right) {

    vector<int> temp;

    int i = left;
    int j = mid + 1;

    long long count = 0;

    while (i <= mid && j <= right) {

        if (a[i] <= a[j]) {
            temp.push_back(a[i]);
            i++;
        }
        else {
            temp.push_back(a[j]);

            count += mid - i + 1;

            j++;
        }
    }

    while (i <= mid) {
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

    return count;
}

long long mergeSort(vector<int>& a, int left, int right) {

    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    long long count = 0;

    count += mergeSort(a, left, mid);
    count += mergeSort(a, mid + 1, right);

    count += merge(a, left, mid, right);

    return count;
}

long long countOutOfOrder(vector<int>& a) {

    if (a.size() <= 1)
        return 0;

    return mergeSort(a, 0, a.size() - 1);
}

int main() {

    vector<int> a = {2, 4, 1, 3, 5};

    cout << countOutOfOrder(a);

    return 0;
}