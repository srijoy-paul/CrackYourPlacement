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
class Solution
{
private:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newHead = reverseList(slow->next);
        // ListNode* first = head;
        // ListNode* second = newHead;
        while (newHead != NULL)
        {
            if (head->val != newHead->val)
            {
                // reverseList(newHead);
                return false;
            }
            head = head->next;
            newHead = newHead->next;
        }
        // reverseList(newHead);
        return true;
    }
};