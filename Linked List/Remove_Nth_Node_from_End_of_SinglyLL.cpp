//Problem:  19. Remove Nth Node From End of List
//-------------------------------------------------------------------------------------
//Code :  Two-Pointer Technique

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode;
		dummy->next=head;
		ListNode* fast=dummy;
		ListNode* slow=dummy;
		int count=0;
		while(fast->next!=NULL && count<n){
			fast=fast->next;
			count++;
		}
		while(fast->next!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
		fast=slow->next;
		slow->next=slow->next->next;
		delete(fast);
		return dummy->next;
	}
};

//Time Complexity:  O(N)
//Auxilary Space Complexity:  O(1)
//-------------------------------------------------------------------------------------
