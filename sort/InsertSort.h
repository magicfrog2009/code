#ifndef __H_INSERTSORT_H_
#define __H_INSERTSORT_H_

#include "SortBase.h"

template <typename T>
class InsertSort: public SortBase<T>
{
public:
    InsertSort() = default;
    ~InsertSort() = default;

    void Sort(std::vector<T>& Array) override final
    {
        const int ssize = Array.size();

        for(int i = 1; i < ssize; ++i)
        {
            T tmp = Array[i];
            int j = i;
            for(; j > 0; --j)
            {
                if(Array[j-1] > tmp)
                {
                    Array[j] = Array[j-1];
                }
                else
                {
                    break;
                }
            }
            Array[j] = tmp;
        }
    }
};



#endif
