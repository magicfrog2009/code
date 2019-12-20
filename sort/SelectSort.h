#ifndef __SELECTSORT_H_
#define __SELECTSORT_H_
#include "SortBase.h"

template<typename T>
class SelectSort: public SortBase<T>
{
public:
    SelectSort() = default;
    ~SelectSort() = default;
    void Sort(std::vector<T>& Array) override final
    {
        const int ssize = Array.size();
        for(int i = 0; i < ssize; ++i)
        {
            int indexMin = i;
            for(int j = i+1; j < ssize; ++j)
                if(Array[j] < Array[indexMin])
                    indexMin = j;

            T tmp = Array[i];
            Array[i] = Array[indexMin];
            Array[indexMin] = tmp;
        }

    }
};


#endif
