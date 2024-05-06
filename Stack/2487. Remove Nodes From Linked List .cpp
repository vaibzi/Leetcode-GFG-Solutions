//Medium
// TC- O(N) SC-> O(N)
//Topic - Stack, LinkedList

// You are given the head of a linked list.

// Remove every node which has a node with a greater value anywhere to the right side of it.
// Return the head of the modified linked list.

// Example 1:
// Input: head = [5,2,13,3,8]
// Output: [13,8]
// Explanation: The nodes that should be removed are 5, 2 and 3.
// - Node 13 is to the right of node 5.
// - Node 13 is to the right of node 2.
// - Node 8 is to the right of node 3.



//        ⚙️ Dry Run:
// Given Linked List: 5 -> 2 -> 13 -> 3 -> 8
// Iteration	Node	Stack
// Step 1	5	5
// Step 2	2	5, 2
// Step 3	13	5X, 2X, 13
// Step 4	3	13, 3
// Step 5	8	13, 3X, 8 
//Reverse the stack to obtain the modified linked list.
// Return the head of the modified linked list.

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stack;
        
// 1) Initialize a stack to store nodes in non-decreasing order of their values.
// 2) Traverse the linked list:
// If the current node's value is greater than the top element of the stack, pop elements from the stack until the condition is met.
// Push the current node onto the stack.
        while (cur != nullptr) {
            while (!stack.empty() && stack.top()->val < cur->val) {
                stack.pop();
            }
            stack.push(cur);
            cur = cur->next;
        }

        ListNode* nxt = nullptr;
        while (!stack.empty()) {
            cur = stack.top();
            stack.pop();
            cur->next = nxt;
            nxt = cur;
        }
        
        return cur;
    }
};
