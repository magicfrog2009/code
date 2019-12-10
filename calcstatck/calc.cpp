/*
 * *******************************************************************
 * File: calc.cpp
 * Created Date: 2019-11-30
 * Author: Pengfei Xu xupengfei@axontech.cn
 * 
 * Copyright (c) 2019 AXONINTELLIGENCE Ltd
 * *******************************************************************
 */


#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

static inline bool isop(char& c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
        return true;
    else
    {
        return false;
    }
}

static inline bool isnum(char& c)
{
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}

static inline int op_pro(char& c)
{
    if(c == ')')
        return 0;
    else if(c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 3;
}

static inline bool opmorethan(char& op1, char& op2)
{
    if(op1 == '(')
        return (op_pro(op1)>(op_pro(op2)+op_pro(op1)));
    else
        return (op_pro(op1)>op_pro(op2));
}

static inline bool opout(char& c)
{
    if(c == '(' || c == ')')
        return false;
    else
    {
        return true;
    }
    
}

int main(int argc, char** argv)
{
    if(argc != 2)
        return -1;

    string suffixexp;
    stack<char> ops;

    char* c = argv[1];

    while(*c != '\0')
    {
        if(*c == ' ')
            continue;
        if(isnum(*c))
            suffixexp.push_back(*c);

        if(isop(*c))
        {
            if(ops.empty())
                ops.push(*c);
            else
            {
                if(!opmorethan(ops.get(), *c))
                {
                    ops.push(*c);
                }
                else
                {
                    do
                    {
                        char op = ops.pop();
                        if(opout(op))
                            suffixexp.push_back(op);
                    } while ((!ops.empty()) && opmorethan(ops.get(), *c));

                    ops.push(*c);
                }
                
            }
        }
        c++;
    }

    while(!ops.empty())
    {
        char op = ops.pop();
        if(opout(op))
            suffixexp.push_back(op);
    }

    cout << suffixexp << endl;

    stack<float> res;

    for(auto& c : suffixexp)
    {
        if(isnum(c))
        {
            float val = c - '0';
            res.push(val);
        }
        else
        {
            float v1 = res.pop();
            float v2 = res.pop();
            float tmp;
            if(c == '+')
                tmp = v1+v2;
            else if(c == '-')
                tmp = v2-v1;
            else if(c == '*')
                tmp = v1*v2;
            else
                tmp = v2/v1;

            res.push(tmp);
        }
        
    }


    cout << res.get() << endl;

    return 0;
}