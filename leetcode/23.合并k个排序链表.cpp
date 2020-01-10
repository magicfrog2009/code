/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.25%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    65.6K
 * Total Submissions: 135.7K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    void SwapList(ListNode* &l1, ListNode* &l2)
    {
        ListNode* t = l1;
        l1 = l2;
        l2 = l1;
    }

    int ClearNullList(vector<ListNode*>& lists)
    {
        // clear null list
        int ssize = lists.size();
        while (ssize)
        {
            if(lists[ssize-1] == nullptr)
                --ssize;
            else 
                break;
        }
        for(int i = 0 ; i < ssize; ++i)
        {
            if(lists[i] == nullptr)
            {
                SwapList(lists[i], lists[ssize-1]);
                --ssize;
            }
        }

        return ssize;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int ssize = ClearNullList(lists);
        if(ssize <= 0)
            return nullptr;
        
        auto comp = [](ListNode* l, ListNode* r){return l->val > r->val;};
        auto get_next = [&](){
            ListNode* min = lists[0];
            lists[0] = min->next;
            std::pop_heap(lists.begin(), lists.end(), comp);
            if(min->next == nullptr)
                lists.resize(lists.size()-1);
            else 
                std::push_heap(lists.begin(), lists.end(), comp);

            min->next = nullptr;
            return min;
        };

        lists.resize(ssize);
        std::make_heap(lists.begin(), lists.end(), comp);

        ListNode* first = get_next();
        ListNode* last = first;

        while(lists.size())
        {
            last->next = get_next();
            last = last->next;
        }


        return first;
    }
};
// @lc code=end

