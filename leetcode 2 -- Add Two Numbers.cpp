/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        //p和q记录末尾节点
        ListNode *head = NULL, *p, *q;
        ListNode *head1 = l1, *head2 = l2;
        int t;
        //bef记录进位的值，初始化为0
        int bef = 0;
        //任何一个链表到达末尾就停止循环
        while(l1 != NULL && l2 != NULL){
            t = l1->val + l2->val + bef;
            //如果和大于等于10，进位值为1，否则为0
            if(t >= 10){
                l1->val = t%10;
                bef = 1;
            }else{
                l1->val = t;
                bef = 0;
            }
            //标记短链表到达末尾时的节点和此刻长链表所到达的节点
            p = l1;
            q = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        head = head1;
        /*我默认是l1为返回链表，所以如果l1比l2短，只需要l1末尾
        节点的next指针域指向l2比l1长的部分即可*/
        //长度一样的情况
        if(l1 == NULL && l2 == NULL){
            if(bef == 1){
                p->next = new ListNode(bef);
            }   
        }else if(l1 == NULL || l2 == NULL){
            //如果l1短接上l2的余下部分
            if(l1 == NULL)
                p->next = q->next;
            //看是否余下的单链表出现循环进位的情况
            while(p->next != NULL){
                p->next->val += bef; 
                if(p->next->val >= 10){
                    p->next->val %= 10;
                    p = p->next;
                    bef = 1;
                }else{
                    bef = 0;
                    break;
                }
            }
            //最后一个节点若出现进位还需new一个新节点
            if(bef == 1){
                p->next = new ListNode(1);
            }
        }
        return head;
    }
};
