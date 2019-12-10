
#ifndef __SPARSEMATRIX_H__
#define __SPARSEMATRIX_H__

#include <memory>
#include <random>
#include <iostream>

template <typename T>
struct Triple
{
    int i,j;
    T v;
};

template <typename T>
class SparseMatrix
{
private:
    int _rows;
    int _cols;
    std::unique_ptr<Triple<T>[]> _data;
    int _terms;

public:
    SparseMatrix(int rows, int cols):
        _rows(rows),
        _cols(cols),
        _data(nullptr),
        _terms(0)
    {
        std::default_random_engine e;
        std::uniform_int_distribution<unsigned int> u(0,9999);

        int pos = 0;
        _data.reset(new Triple<T>[cols*rows]);

        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
            {
                if(u(e) == 0)
                {
                    _data.get()[pos].i = i;
                    _data.get()[pos].j = j;
                    _data.get()[pos].v = 1;
                    ++pos;
                }
            }

        _terms = pos;
    }

    void info()
    {
        std::cout << _cols << " x " << _rows << " iterms " << _terms << std::endl;
    }

    SparseMatrix Transmatrix()
    {
        SparseMatrix am(_rows, _cols);
        
        for(int i = 0; i < cols; ++i)
            for(int pos = 0; pos < _terms; ++pos)
            {
                if(_data.get()[pos].j == i)
                {

                }
            }
    }

    SparseMatrix TransmatrixFast()
    {

    }
};

#endif
