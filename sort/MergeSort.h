#ifndef __MERGESORT_H_
#define __MERGESORT_H_
#include "SortBase.h"

template<typename T>
class MergeSort: public SortBase<T>
{
public:
    MergeSort() = default;
    ~MergeSort() = default;
    void Sort(std::vector<T>& Array) override final
    {
        const int ssize = Array.size();
        std::vector<T> tmpArray;
        tmpArray.resize(ssize);

        int out = 0;
        for(int len = 1; len < ssize; len*=2)
        {
            if((++out)&0x01)
            {
                mergeL(Array, tmpArray, len);
            }
            else
            {
                mergeL(tmpArray, Array, len);
            }           
        }

        if(out&0x01)
        {
            for(int i = 0; i < ssize; ++i)
            {
                Array[i] = tmpArray[i];
            }
        }
    }

private:
    void merge(std::vector<T>& Ain, std::vector<T>& Aout, int s, int p, int e)
    {
        int i = s;
        int j = p;
        int k = s;
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

    void mergeL(std::vector<T>& Ain, std::vector<T>& Aout, int l)
    {
        const int ssize = Ain.size();
        const int loop = ssize / l /2;

        for(int i = 0; i < loop; ++i)
        {
            int start = i*2*l;
            int end = start + 2*l;
            merge(Ain, Aout, start, start+l, end);
        }

        int left = ssize%(2*l);
        if(left > l)
        {
            int start = loop*2*l;
            int end = ssize;
            merge(Ain, Aout, start, start+l, end);
        }
        else
        {
            for(int i = loop*2*l; i < ssize; ++i)
            {
                Aout[i] = Ain[i];
            }
        }
    }

};

#endif
