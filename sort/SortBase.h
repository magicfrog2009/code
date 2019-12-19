#ifndef __SORTBASE_H__
#define __SORTBASE_H__

#include <vector>

template <typename T>
class SortBase
{
public:
    virtual ~SortBase() = default;
    virtual void Sort(std::vector<T>&) = 0;
};

#endif
