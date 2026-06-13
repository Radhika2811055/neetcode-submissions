class Solution {
public:
    // Find end of first half
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Reverse linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find middle
        ListNode* middle = findMiddle(head);

        // Step 2: Reverse second half
        ListNode* second = middle->next;
        middle->next = nullptr;
        second = reverse(second);

        // Step 3: Merge alternately
        ListNode* first = head;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};