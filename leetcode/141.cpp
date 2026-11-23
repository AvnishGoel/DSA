
#include <bits/stdc++.h>
using namespace std;

// Linked List Definition
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

// Main function for local testing
int main() {

    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create cycle: 4 -> 2
    head->next->next->next->next = head->next;

    Solution obj;

    bool result = obj.hasCycle(head);

    if (result) {
        cout << "Cycle detected!" << endl;
    }
    else {
        cout << "No cycle detected!" << endl;
    }

    return 0;
}
