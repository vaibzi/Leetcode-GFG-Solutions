//Medium
//TC-> O(n), SC- O(N)

// You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
// For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
// Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

// Example 1:

// Input: arr = [1,2,3,5], k = 3
// Output: [2,5]
// Explanation: The fractions to be considered in sorted order are:
// 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
// The third fraction is 2/5.



//Approach
// 1) Initialization: Start by initializing a priority queue (pq) to store pairs of fractions (x, {numerator, denominator}), where x represents the value of the fraction (numerator divided by denominator).

// 2) Pair Generation: Iterate through the array arr, considering every pair of elements (arr[i], arr[j]) where i < j. Calculate the fraction x = arr[i] / arr[j] as a double.

// 3) Priority Queue Management:
// If the size of the priority queue reaches k, check if the current fraction x is smaller than the top fraction in the queue. If it is, pop the top element and push the current fraction into the queue.
// If the size of the priority queue is less than k, simply push the current fraction into the queue.
  
// 4) Result Extraction: After processing all possible pairs, the top element of the priority queue will contain the kth smallest prime fraction. Extract the numerator and denominator from this element and return them as the result.


class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double,pair<int,int>>> pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double x = arr[i]/(arr[j]*1.0);
                
                if(pq.size() == k){
                    if(x < pq.top().first){
                        pq.pop();
                        pq.push({x,{arr[i],arr[j]}});
                    }
                }
                else{
                    pq.push({x,{arr[i],arr[j]}});
                }
            }
        }

        return {pq.top().second.first,pq.top().second.second};
    }
};
