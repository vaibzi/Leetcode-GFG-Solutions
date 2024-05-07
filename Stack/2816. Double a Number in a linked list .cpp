//Medium
//TC- O(N), SC-O(N)
//You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.
// Input: head = [1,8,9]
// Output: [3,7,8]


class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        std::stack<int> s;
        
        // Push values of the linked list onto the stack
        while (head != nullptr) {
            s.push(head->val);
            head = head->next;
        }
        
        ListNode* tail = nullptr;
        int res = 0;
        // Process each digit in the sum, starting from the least significant digit
        while (!s.empty() || res != 0) {
            tail = new ListNode(0, tail); //in (0,tail) 0 = val, tail = this tails next, cuz building LL from back
            if (!s.empty()) {
                res += s.top() * 2; // Double the digit and add the carry
                s.pop(); // Pop the used digit
            }
            tail->val = res % 10; // Store the least significant digit
            res /= 10; // Update the carry for the next iteration
        }

        return tail;
    }
};

