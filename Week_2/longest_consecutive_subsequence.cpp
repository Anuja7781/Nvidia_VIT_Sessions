#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSeq(vector<int>& nums)
{
    int maxLen = 1;

    unordered_map<int, bool> mp; //for checking which numbers are visited 

    //first put all the numbers in map 
    for(int num : nums)
    {
        mp[num] = false;
    }

    //traverse each number 
    for(int num : nums)
    {
        if(mp[num] == true)
            continue;
        
            int currLen = 1;

            mp[num] = true;

            //check next number 
            int nextNum = num+1;
            //in while -- check if neztnum exists and it hasnt been explored yet 
            while(mp.find(nextNum) != mp.end() && mp[nextNum] == false)
            {
                currLen++;
                mp[nextNum] == true;

                nextNum++;
            }


            //check in reverse order 

            int prevNum = num-1;

            while(mp.find(prevNum) != mp.end() && mp[prevNum] == false)
            {
                currLen++;
                mp[prevNum] = true;

                prevNum--;
            }

            maxLen = max(maxLen, currLen);

    }

    return maxLen;
}

int main() {

    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << longestSeq(nums);

    return 0;
}