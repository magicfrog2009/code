#include "Tree.h"

int main(int argc, char** argv)
{
    BinaryTree<int> it(1);

    _TreeNode<int>* proot = it.getRoot();
    _TreeNode<int>* two = it.insertLeft(proot, 2);
    it.insertLeft(two, 4);
    _TreeNode<int>* five = it.insertRight(two, 5);
    _TreeNode<int>* seven = it.insertLeft(five, 7);
    it.insertRight(five, 8);
    it.insertLeft(seven, 9);

    auto three = it.insertRight(proot, 3);
    it.insertRight(three, 6);

    // it.preorder(proot);
    // std::cout << std::endl;
    // it.preorderloop(proot);

    // it.inorder(proot);
    // std::cout << std::endl;
    // it.inorderloop(proot);

    it.postorder(proot);
    std::cout << std::endl;
    it.postorderloop(proot);

    // auto one = it.find(proot, 1);
    // std::cout << one->value << " " << one->left->value << " " << one->right->value << std::endl;

    // auto nine = it.find(proot, 9);
    // std::cout << nine->value << std::endl;

    return 0;
}