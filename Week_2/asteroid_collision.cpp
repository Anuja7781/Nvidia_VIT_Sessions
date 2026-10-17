#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {

    vector<int> st;

    for (int asteroid : asteroids) {

        bool destroyed = false;

        while (!st.empty() && st.back() > 0 && asteroid < 0) {

            if (st.back() < -asteroid) {
                st.pop_back();
            }
            else if (st.back() == -asteroid) {
                st.pop_back();
                destroyed = true;
                break;
            }
            else {
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
            st.push_back(asteroid);
    }

    return st;
}

int main() {

    vector<int> a = {10, 2, -5};

    vector<int> result = asteroidCollision(a);

    for (int x : result)
        cout << x << " ";

    return 0;
}