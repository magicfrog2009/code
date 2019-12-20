#include <iostream>
#include <memory>
// #include <vector>
// #include <algorithm>
#include "SortBase.h"
#include "HeapSort.h"
#include "InsertSort.h"
#include "DivInsertSort.h"
#include "BubbleSort.h"
#include "FastSort.h"
#include "SelectSort.h"


int main(int argc, char** argv)
{
    // std::vector<int> Array{1};
    // std::vector<int> Array{3, 1};
    // std::vector<int> Array{1, 4534, 23};
    // std::vector<int> Array{1,23,4534,123,564,323,56,345,234};
    std::vector<int> Array{1,23,4534,123,564,323,56,345,234,45,79,97,54566,86,43,365,5327,89,63};

    // std::unique_ptr<SortBase<int>> sort {new HeapSort<int>};
    // std::unique_ptr<SortBase<int>> sort {new InsertSort<int>};
    // std::unique_ptr<SortBase<int>> sort {new DivInsertSort<int>};
    // std::unique_ptr<SortBase<int>> sort {new BubbleSort<int>};
    // std::unique_ptr<SortBase<int>> sort {new FastSort<int>};
    std::unique_ptr<SortBase<int>> sort {new SelectSort<int>};

    sort->Sort(Array);

    for(auto iter: Array)
    {
        std::cout << iter << std::endl;
    }

    return 0;
}
