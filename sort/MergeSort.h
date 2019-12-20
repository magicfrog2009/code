#ifndef __MERGESORT_H_
#define __MERGESORT_H_
#include "SortBase.h"

template<typename T>
class MergeSort
{
public:
    MergeSort() = default;
    ~MergeSort() = default;
    void Sort(std::vector<T>& Array) override final
    {
        const int ssize = Array.size();

        for(int len = 1; len < ssize; len*=2)
        {
            
            merge(Array, j, j+len, j+2*len);
        }
    }

private:
    merge(std::vector<T>& Ain, std::vector<T>& Aout, int s, int p, int e)
    {
        int i = s;
        int j = p;
        int k = 0;
        while (i < p && j < e)
        {
            int min;
            if(Ain[i] > Ain[j])
            {
                min = j++;
            }
            else
            {
                min = i++;
            }
            
            Aout[k++] = Ain[min];
        }

        while(i < p)
        {
            Aout[k++] = Ain[i++];
        }
        
        while(j < e)
        {
            Aout[k++] = Ain[j++];
        }
    }
};


#endif
