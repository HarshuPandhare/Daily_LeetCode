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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>critical;
        vector<int>ans;
        vector<int>ans1 = {-1,-1};
        ListNode * ptr = head;
        ListNode * prev = head;
        int count = 2;
        while(ptr->next!=NULL){
             ptr = ptr->next;
             if (ptr->next != NULL &&
    ((prev->val > ptr->val && ptr->next->val > ptr->val) ||
     (prev->val < ptr->val && ptr->next->val < ptr->val))) {
    critical.push_back(count);
}
             
             prev = prev->next;
             count++;
        }
        sort(critical.begin(),critical.end());
        if(critical.size()<2)return ans1;
        int MinNUM = critical[1] - critical[0];
        int diff = critical[1] - critical[0];
        for(int i = 1;i<critical.size();i++){
            diff = critical[i] - critical[i-1];
            MinNUM = min(MinNUM,diff);
        }
        ans.push_back(MinNUM);
        ans.push_back(critical[critical.size()-1] - critical[0]);

        return ans;
    }
};
