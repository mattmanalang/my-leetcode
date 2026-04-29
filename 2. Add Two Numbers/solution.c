/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // Allocate dummy on the HEAP, not the STACK
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode *current = dummy;
    unsigned int carry = 0;

    while (l1 || l2 || carry) {
        int val1 = (l1) ? l1->val : 0;
        int val2 = (l2) ? l2->val : 0;

        int total = val1 + val2 + carry;
        carry = total / 10;  // Should result in truncation towards zero
        int digit = total % 10;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->val = digit;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;

        l1 = (l1)? l1->next : NULL;
        l2 = (l2)? l2->next : NULL;
    }
    struct ListNode *result = dummy->next;
    free(dummy);  // Freeing dummy because he's not needed anymore

    return result;
}

// What if we needed a helper function to free the entire result list later?
// This is what the caller would need to call once it's done with the result
void freeResultList(struct ListNode *head) {
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Cleaning up the original pointer that now points to freed memory
void freeAndNull(struct ListNode **headPtr) {
    freeResultList(*headPtr);
    *headPtr = NULL;  // Modify the caller's pointer to NULL
}

// Usage:
freeAndNull(&result);  // Now result is NULL
