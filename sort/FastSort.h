#ifndef __FASTSORT_H_
#define __FASTSORT_H_
#include <stack>
#include "SortBase.h"

template<typename T>
class FastSort: public SortBase<T>
{
private:
    class part
    {
    public:
        std::vector<T>& Array;
        int left;
        int right;
    };

    std::stack<part> m_stack;
    void Partition()
    {
        part top = m_stack.top();
        m_stack.pop();

        std::vector<T>& Array = top.Array;
        int left = top.left;
        int right = top.right;
        T tmp = Array[left];

        while (left < right)
        {
            while(left < right)
            {
                if(Array[right] < tmp)
                {
                    Array[left] = Array[right];
                    // Array[right] = tmp;
                    left++;
                    break;
                }
                else
                {
                    right--;
                }
            }
            while(left < right)
            {
                if(Array[left] > tmp)
                {
                    Array[right] = Array[left];
                    // Array[left] = tmp;
                    right--;
                    break;
                }
                else
                {
                    left++;
                }
            }
        }

        int mid = left;
        Array[mid] = tmp;

        if(mid - top.left > 1)
        {
            part tmp{Array, top.left, mid-1};
            m_stack.push(tmp);
        }

        if(top.right - mid > 1)
        {
            part tmp{Array, mid+1, top.right};
            m_stack.push(tmp);
        }
        
    }

public:
    FastSort() = default;
    ~FastSort() =default;

    void Sort(std::vector<T>& Array) override final
    {
        const int ssize = Array.size();

        part ap{Array, 0, ssize-1};
        m_stack.push(ap);

        while(!m_stack.empty())
        {
            Partition();
        }
    }

};

#endif