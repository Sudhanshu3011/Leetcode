class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0, value;
        ListNode *dummy = nullptr;
        ListNode *current = dummy;
        ListNode *ptr = dummy;

        while (l1 != nullptr && l2 != nullptr)
        {
            value = (l1->val + l2->val) + carry;
            if (value >= 10)
            {
                value = value % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            l1 = l1->next;
            l2 = l2->next;

            if (current == nullptr)
            {
                dummy = new ListNode(value);
                current = dummy;
                ptr = dummy;
            }
            else
            {
                current->next = new ListNode(value);
                current = current->next;
            }
        }

        while (l1 != nullptr)
        {
            value = l1->val + carry;
            if (value >= 10)
            {
                value = value % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            current->next = new ListNode(value);
            current = current->next;

            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            value = l2->val + carry;
            if (value >= 10)
            {
                value = value % 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            current->next = new ListNode(value);
            current = current->next;

            l2 = l2->next;
        }

        if (carry > 0)
        {
            current->next = new ListNode(carry);
        }

        return ptr;
    }
};