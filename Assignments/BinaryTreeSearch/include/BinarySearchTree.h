#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <queue>
#include <stack>

#include "TreeNode.h"

using namespace std;

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        TreeNode* getRoot();

        void BSTInsert(int);
        void BSTDelete(int);
        bool BSTSearch(int);

        void BreadthFirstTraversal();
        void DepthFirstPreOrder();
        void DepthFirstPostOrder();
        void DepthFirstInOrder();


    private:
        TreeNode* root;

        void NodeInsert(TreeNode*&, int);
        void DeleteNoChildren(TreeNode*, TreeNode*);
        void DeleteOneChild(TreeNode*, TreeNode*);
        void DeleteTwoChildren(TreeNode*, TreeNode*);

        void DestroyBranch(TreeNode*);
        void PreOrder(TreeNode*);
        void PostOrder(TreeNode*);
        void InOrder(TreeNode*);
};

#endif // BINARYSEARCHTREE_H
