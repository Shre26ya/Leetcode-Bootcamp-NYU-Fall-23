class Solution {
public:
   ListNode* ReverseLL(ListNode* head){
    if(!head || !head -> next) // Fixed base condition
        return head;

    ListNode* last = ReverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
   }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L1 = ReverseLL(l1);
        ListNode* L2 = ReverseLL(l2);

        int sum = 0;
        int carry = 0;
        ListNode* ans = new ListNode();

        while(L1 != NULL || L2 != NULL){

            if(L1 != NULL){
                sum += L1->val;
                L1 = L1->next; 
            }

            if(L2 != NULL){
                sum += L2->val;
                L2 = L2->next; 
            }

            ans->val = sum % 10;
            carry = sum / 10;

            ListNode* NewNode = new ListNode(carry);
            NewNode->next = ans;
            ans = NewNode;
            sum = carry;
        }

        return carry == 0 ? ans->next : ans; 
    }
};

