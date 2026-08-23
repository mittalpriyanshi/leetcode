/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr->val != left){
            prev=curr;
            curr = curr->next;
        }
        ListNode* start = curr;
        ListNode* forw=curr->next;
        while(curr->val!=right){
            forw = forw->next;
            curr = curr->next;
        }
        // now prev = 1, curr =end=4, forw =5, start=2
        prev->next =nullptr;
        curr->next = nullptr;
        // 1 2->3->4 5
        ListNode* prevfirst = nullptr;
        ListNode* next = nullptr;
        ListNode* startOrg = start;
        
        while (start != nullptr) {
            next = start->next;  // Step 1: Save the rest of the list
            start->next = prevfirst;  // Step 2: Reverse the arrow
            prevfirst = start;        // Step 3: Move prev forward
            start = next;        // Step 4: Move curr forward
        }
        prev->next = curr;
        startOrg->next = forw;
        return prev;
    }
};