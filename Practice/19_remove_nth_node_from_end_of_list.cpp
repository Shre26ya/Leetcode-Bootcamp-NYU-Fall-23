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
    ListNode* removeNthFromEnd(ListNode* head, int k) {

        if(head == nullptr) return head;

        int cnt = 0;
        ListNode* temp = head;

        while(temp){
            temp = temp->next;
            cnt++;
        }

        int pos = cnt - k + 1;

        if(pos == 1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        
        int c = 0;
        temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            c++;
            if(c == pos){
                ListNode* delNode = prev->next;
                prev->next = delNode->next;
                delete delNode;
                break;
            }

            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};

