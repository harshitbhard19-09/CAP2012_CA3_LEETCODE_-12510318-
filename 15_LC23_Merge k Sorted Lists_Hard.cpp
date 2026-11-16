

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

      
        priority_queue<ListNode*, vector<ListNode*>,
        decltype([](ListNode* a, ListNode* b) {
            return a->val > b->val;
        })> pq;

       
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

           
            ListNode* curr = pq.top();
            pq.pop();

           
            tail->next = curr;
            tail = tail->next;

            
            if (curr->next != nullptr) {
                pq.push(curr->next);
            }
        }

        tail->next = nullptr;

        return dummy.next;
    }
};
