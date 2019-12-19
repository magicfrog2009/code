#ifndef __BUBBLESORT_H_
#define __BUBBLESORT_H_
#include "SortBase.h"

template<typename T>
class BubbleSort: public SortBase<T>
{
public:
    BubbleSort() = default;
    ~BubbleSort() = default;

    void Sort(std::vector<T>& Array) override final
    {
        const int ssize = Array.size();

        // n-1 store inorder element
        for(int k = ssize-1; k >= 1; --k)
            for(int i = 0; i < k; ++i)
            {
                if(Array[i] > Array[i+1])
                {
                    T tmp = Array[i];
                    Array[i] = Array[i+1];
                    Array[i+1] = tmp;
                }
            }
    }
};






#endif
