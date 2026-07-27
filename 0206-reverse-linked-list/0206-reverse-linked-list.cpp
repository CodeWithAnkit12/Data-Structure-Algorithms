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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* temp=head;
        vector<int> vec;
        while(temp!=nullptr){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        reverse(vec.begin(),vec.end());
        ListNode* ankit= new ListNode(0);
        ListNode* curr=ankit;
        for(int i=0;i<vec.size();i++){
            curr->next=new ListNode(vec[i]);
            curr=curr->next;
        }
        return ankit->next;
    }
};