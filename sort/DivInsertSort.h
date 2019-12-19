#ifndef __DIVINSERTSORT_H__
#define __DIVINSERTSORT_H__
#include "SortBase.h"

template <typename T>
class DivInsertSort: public SortBase<T>
{
public:
    DivInsertSort() = default;
    ~DivInsertSort() = default;

    void Sort(std::vector<T>& Array) override final
    {
        const int ssize = Array.size();

        for(int i = 1; i < ssize; ++i)
        {
            T tmp = Array[i];
            int left = 0;
            int right = i-1;
            int mid;
            
            // find position
            while (left <= right)
            {
                mid = (left + right)/2;
                if(Array[mid] > tmp)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            // unnecessary left must great than tmp
            // if(Array[mid] <= tmp)
            //     mid++;

            // move elements            
            for(int j = i; j > left; --j)
                Array[j] = Array[j-1];
            
            Array[left] = tmp;
 
        }
    }
};


#endif
