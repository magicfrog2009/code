/*
 * *******************************************************************
 * File: stack.h
 * Created Date: 2019-11-30
 * Author: Pengfei Xu xupengfei@axontech.cn
 * 
 * Copyright (c) 2019 AXONINTELLIGENCE Ltd
 * *******************************************************************
 */


#include <memory>

template<typename T>
struct stack_ptr
{
    T element;
    std::shared_ptr<stack_ptr> next;
};

template<typename T>

class stack
{
public:
    stack():
    m_stack(nullptr)
    {

    }

    ~stack() = default;

    void push(T& val)
    {
        std::shared_ptr<stack_ptr<T>> ele{new stack_ptr<T>};
        ele->element = val;
        ele->next = m_stack;
        m_stack = ele;
    }

    T pop()
    {
        T val = m_stack->element;
        m_stack = m_stack->next;
        return val;
    }

    T& get()
    {
        return m_stack->element;
    }

    bool empty()
    {
        return (m_stack.get() == nullptr);
    }

private:
    std::shared_ptr<stack_ptr<T>> m_stack;
};