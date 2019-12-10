#include <iostream>
#include <utility>
#include "Stack.h"


template<typename T>
struct _TreeNode
{
    _TreeNode* left;
    _TreeNode* right;
    T value;

    _TreeNode(const T& v): value(v), left(nullptr), right(nullptr){}
    _TreeNode(void): left(nullptr), right(nullptr){}
};

template<typename T>
class BinaryTree
{
private:
    _TreeNode<T>* _root;

public:
    BinaryTree(): 
        _root(nullptr){}

    BinaryTree(const T& v): 
        _root(nullptr)
    {
        _root =  new _TreeNode<T>(v);
    }

    _TreeNode<T>* getRoot(void)
    {
        return _root;
    }

    _TreeNode<T>* insertLeft(_TreeNode<T>* cur, const T& v)
    {
        cur->left = new _TreeNode<T>(v);
        return cur->left;
    }

    _TreeNode<T>* insertRight(_TreeNode<T>* cur, const T& v)
    {
        cur->right = new _TreeNode<T>(v);
        return cur->right;
    }

    _TreeNode<T>* find(_TreeNode<T>* cur, const T& v)
    {
        if(cur == nullptr)
            return nullptr;
        
        if(cur->value == v)
            return cur;
        
        _TreeNode<T>* ret = find(cur->left, v);
        if(ret != nullptr)
            return ret;
        else
            return find(cur->right, v);
    }

    void preorder(_TreeNode<T>* cur)
    {
        if(cur == nullptr)
            return;

        std::cout << cur->value << std::endl;
        preorder(cur->left);
        preorder(cur->right);
    }

    void inorder(_TreeNode<T>* cur)
    {
        if(cur == nullptr)
            return;

        inorder(cur->left);
        std::cout << cur->value << std::endl;
        inorder(cur->right);
    }

    void postorder(_TreeNode<T>* cur)
    {
        if(cur == nullptr)
            return;

        postorder(cur->left);
        postorder(cur->right);
        std::cout << cur->value << std::endl;
    }

    void preorderloop(_TreeNode<T>* cur)
    {
        Stack<_TreeNode<T>*> nodeStack;

        while(true)
        {
            if(cur)
            {
                std::cout << cur->value << std::endl;
                nodeStack.push(cur);
                cur = cur->left;
            }
            else
            {
                if(nodeStack.empty())
                    break;

                cur = nodeStack.pop();
                cur = cur->right;
            }
        }
    }

    void inorderloop(_TreeNode<T>* cur)
    {
        Stack<_TreeNode<T>*> nodeStack;

        while(true)
        {
            if(cur)
            {
                nodeStack.push(cur);
                cur = cur->left;
            }
            else
            {
                if(nodeStack.empty())
                    break;

                cur = nodeStack.pop();
                std::cout << cur->value << std::endl;
                cur = cur->right;
            }
        }
    }

    // void postorderloop(_TreeNode<T>* cur)
    // {
    //     if(cur == nullptr)
    //         return;

    //     Stack<std::pair<_TreeNode<T>*, unsigned int>> nodeStack;

    //     nodeStack.push(std::make_pair(cur, make_flag(cur)));
    //     auto top = nodeStack.get();

    //     while(true)
    //     {
    //         cur = top.first;
    //         if(top.second&0x01)
    //         {
    //             top.second &= ~0x01;
    //             nodeStack.push(std::make_pair(cur->left, make_flag(cur->left)));
    //             top = nodeStack.get();
    //         }
    //         else if (top.second&0x02)
    //         {
    //             top.second &= ~0x02;
    //             nodeStack.push(std::make_pair(cur->right, make_flag(cur->right)));
    //             top = nodeStack.get();
    //         }
    //         else
    //         {
    //             std::cout << cur->value << std::endl;
    //             nodeStack.pop();
    //             top = nodeStack.get();
    //             // std::cout << top.first->value << " " << top.second << std::endl;
    //         }
            
    //     }

    // }
    void postorderloop(_TreeNode<T>* cur)
    {
        if(cur == nullptr)
            return;

        Stack<std::pair<_TreeNode<T>*, unsigned int>> nodeStack;

        nodeStack.push(std::make_pair(cur, make_flag(cur)));

        while(!nodeStack.empty())
        {
            auto& top = nodeStack.get();
            cur = top.first;
            if(top.second&0x01)
            {
                top.second &= ~0x01;
                nodeStack.push(std::make_pair(cur->left, make_flag(cur->left)));
            }
            else if (top.second&0x02)
            {
                top.second &= ~0x02;
                nodeStack.push(std::make_pair(cur->right, make_flag(cur->right)));
            }
            else
            {
                std::cout << cur->value << std::endl;
                nodeStack.pop();
            }
            
        }
    }

private:
    unsigned int make_flag(_TreeNode<T>* cur)
    {
        unsigned int flag = 0;

        if(cur->left != nullptr)
        {
            flag |= 0x01;
        }

        if(cur->right != nullptr)
        {
            flag |= 0x02;
        }

        return flag;
    }

};
