// 2. Add Two Numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* ans = head;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            head->next = new ListNode(sum);
            head = head->next;
        }
        return ans->next;
    }
};

//TC: O(max(l1,l2))
//SC: O(max(l1,l2))