/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (63.46%)
 * Likes:    376
 * Dislikes: 0
 * Total Accepted:    62.2K
 * Total Submissions: 97.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* next(ListNode* l1)
    {
        if(l1 == nullptr)
            return nullptr;
        if(l1->next == nullptr)
            return l1;
        ListNode* l2 = l1->next;
        l1->next = next(l2->next);
        l2->next = l1;

        return l2;
    }
public:
    ListNode* swapPairs_R(ListNode* head) {
        return next(head);
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* first = head->next;
        ListNode* p1 = head;
        ListNode* last = nullptr;
        while(p1)
        {
            ListNode* p2= p1->next;
            if(p2)
            {
                if(last)
                    last->next = p2;
                p1->next = p2->next;
                p2->next = p1;
                last = p1;
                p1 = p1->next;
            }
            else
            {
                if(last)
                    last->next = p1;
                break;
            }
        }

        return first;
    }
};
// @lc code=end

