#include <iostream>
#include <vector>
#include <algorithm>

void MaximumHeap(std::vector<int>& A)
{
    const int ssize = A.size();
    for(int i = ssize; i > 1; i -= 2)
    {
        int p = i / 2;
        int j = p * 2;
        if(j+1 <= ssize && A[j] > A[j-1]) 
            ++j;
        
        if(A[p-1] < A[j-1])
        {
            int tmp = A[p-1];
            A[p-1] = A[j-1];
            A[j-1] = tmp;

            for(int k = j; k <= ssize; )
            {
                int c = k*2;
                if(c+1 <= ssize && A[c] > A[c-1])
                    ++c;
                if(c <= ssize && A[c-1] > tmp)
                {
                    A[k-1] = A[c-1];
                    A[c-1] = tmp;
                    k = c;
                }
                else
                {
                    break;
                }
            }
        }

    }
}

void HeapSort(std::vector<int>& A)
{
    int ssize = A.size();
    do
    {
        int tmp = A[ssize-1];
        A[ssize-1] = A[0];
        A[0] = tmp;
        ssize--;

        
        for(int i = 1; i <= ssize;)
        {
            int c = 2*i;
            if(c+1 <= ssize && A[c] > A[c-1])
                c++;

            if(c <= ssize && A[c-1] > A[i-1])
            {
                A[i-1] = A[c-1];
                A[c-1] = tmp;
                i = c;
            }
            else
            {
                break;
            }
            
        }
    }
    while(ssize > 1);
}

int main(int argc, char** argv)
{
    std::vector<int> A{1,23,4534,123,564,323,56,345,234,45,79,97,54566,86,43,365,5327,89,63};
    // std::vector<int> A{1,23,4534,123,564,323,56,345,234};
    MaximumHeap(A);
    HeapSort(A);

    for(auto iter: A)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}
