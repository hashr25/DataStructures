#ifndef TREENODE_H
#define TREENODE_H

#include <stdlib.h>


class TreeNode
{
public:
    TreeNode(int);

    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

#endif // TREENODE_H
