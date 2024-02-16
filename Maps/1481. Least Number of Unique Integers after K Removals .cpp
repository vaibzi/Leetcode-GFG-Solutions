//Medium
//Topics -> Maps, Pair Vector
// Time Complexity ~O(n) 

// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

// Example 2:
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> m;

        for(auto i: arr) m[i]++;

        vector<pair<int, int>> countArr;

        for(auto i = m.begin(); i != m.end(); i++){
            countArr.push_back( make_pair(i->first, i->second) );
        }

        sort(countArr.begin(), countArr.end(), [](auto a,auto b){
            return a.second < b.second;
        });
    

        int count = 0;
        for(auto it: countArr){
            if(k>=it.second){  //Can remove this element completely,, so dont count, and reduce k for next iteration
                k-=it.second;
                count++;
            }
            else break;
        }
        
        return size(countArr)-count;
    }
};
