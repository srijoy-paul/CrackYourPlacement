/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *temp = headA;
        ListNode *temp2 = headB;
        while (temp != temp2)
        {
            temp = temp->next;
            temp2 = temp2->next;

            if (temp == temp2)
                break;

            if (temp == NULL)
                temp = headB;
            if (temp2 == NULL)
                temp2 = headA;
        }
        return temp;
    }
};