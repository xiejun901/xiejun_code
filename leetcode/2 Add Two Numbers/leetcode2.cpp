class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *node=head;
        int c=0;
        while(l1&&l2){
            int sum=l1->val+l2->val+c;
            if(sum>=10){
                sum%=10;
                c=1;
            }
            else
                c=0;
            node->next=new ListNode(sum);
            node=node->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum=l1->val+c;
            if(sum>=10){
                sum%=10;
                c=1;
            }
            else
                c=0;
            node->next=new ListNode(sum);
            node=node->next;
            l1=l1->next;
        }
        while(l2){
            int sum=l2->val+c;
            if(sum>=10){
                sum%=10;
                c=1;
            }
            else
                c=0;
            node->next=new ListNode(sum);
            node=node->next;
            l2=l2->next;
        }
        if(c){
            node->next=new ListNode(1);
        }
        ListNode *ret=head->next;
        delete head;
        return ret;
    }
};