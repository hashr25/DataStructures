#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    DestroyBranch(root);
}

TreeNode* BinarySearchTree::getRoot()
{
    return root;
}

void BinarySearchTree::BSTInsert(int value)
{
    NodeInsert(root, value);
}

void BinarySearchTree::BSTDelete(int value)
{
    TreeNode* nodeToDelete = NULL;
    TreeNode* parentNode = root;
    TreeNode* currentNode = root;

    ///Finding the Node
    while(nodeToDelete == NULL)
    {
        if(value == currentNode -> value)
        {
            nodeToDelete = currentNode;
        }
        else if(value < currentNode -> value)
        {
            parentNode = currentNode;
            currentNode = currentNode -> leftChild;
        }
        else if(value > currentNode -> value)
        {
            parentNode = currentNode;
            currentNode = currentNode -> rightChild;
        }
    }

    ///Case 1: No Children
    if(nodeToDelete -> leftChild  == NULL &&
       nodeToDelete -> rightChild == NULL)
    {
        DeleteNoChildren(nodeToDelete, parentNode);
    }

    ///Case 2: One Child
    else if((nodeToDelete -> leftChild != NULL && nodeToDelete -> rightChild == NULL) ||
            (nodeToDelete -> leftChild == NULL && nodeToDelete -> rightChild != NULL))
    {
        DeleteOneChild(nodeToDelete, parentNode);
    }

    ///Case 3: Two Children
    else if(nodeToDelete -> leftChild  != NULL &&
            nodeToDelete -> rightChild != NULL)
    {
        DeleteTwoChildren(nodeToDelete, parentNode);
    }
}

bool BinarySearchTree::BSTSearch(int value)
{
    bool ifFound = false;
    TreeNode* currentNode = root;

    while(currentNode != NULL)
    {
        if(value < currentNode -> value)
        {
            currentNode = currentNode -> leftChild;
        }
        else if(value > currentNode -> value)
        {
            currentNode = currentNode -> rightChild;
        }
        else if(value == currentNode -> value)
        {
            ifFound = true;
        }
    }

    return ifFound;
}


void BinarySearchTree::BreadthFirstTraversal()
{
    queue<TreeNode*> q;
    TreeNode* currentNode = root;

    int nodesThisLevel = 1;
    int nodesNextLevel = 0;

    q.push(root);

    while(q.size() != 0)
    {
        currentNode = q.front();
        q.pop();

        cout << currentNode -> value;

        if(currentNode -> leftChild != NULL)
        {
            q.push(currentNode -> leftChild);
            nodesNextLevel++;
        }

        if(currentNode -> rightChild != NULL)
        {
            q.push(currentNode -> rightChild);
            nodesNextLevel++;
        }

        nodesThisLevel--;
        if(nodesThisLevel == 0)
        {
            nodesThisLevel = nodesNextLevel;
            nodesNextLevel = 0;
            cout << endl;
        }
        else
        {
            cout << " - ";
        }
    }
}

void BinarySearchTree::DepthFirstPreOrder()
{
    cout << "Depth-First Pre-Order: " << endl;

    PreOrder(root);

    cout << endl;

}

void BinarySearchTree::DepthFirstPostOrder()
{
    cout << "Depth-First Post-Order: " << endl;

    PostOrder(root);

    cout << endl;
}

void BinarySearchTree::DepthFirstInOrder()
{
    cout << "Depth-First In-Order: " << endl;

    InOrder(root);

    cout << endl;
}

void BinarySearchTree::NodeInsert(TreeNode*& node, int value)
{
    if(node == NULL)
    {cout << "Inserting node " << value << endl;
        node = new TreeNode(value);
    }
    else if(value < node -> value)
    {
        NodeInsert(node -> leftChild, value);
    }
    else if(value > node -> value)
    {
        NodeInsert(node -> rightChild, value);
    }
}

void BinarySearchTree::DeleteNoChildren(TreeNode* nodeToDelete, TreeNode* parentNode)
{
    if(nodeToDelete -> leftChild  == NULL &&
       nodeToDelete -> rightChild == NULL)
    {
        if(nodeToDelete == parentNode -> leftChild)
        {
            parentNode -> leftChild = NULL;
        }
        else if(nodeToDelete == parentNode -> rightChild)
        {
            parentNode -> rightChild = NULL;
        }

        delete nodeToDelete;
    }
}

void BinarySearchTree::DeleteOneChild(TreeNode* nodeToDelete, TreeNode* parentNode)
{
    //Find node to connect back
    TreeNode* toConnectBack = NULL;
    if(nodeToDelete -> leftChild != NULL)
    {
        toConnectBack = nodeToDelete -> leftChild;
    }
    else if(nodeToDelete -> rightChild != NULL)
    {
        toConnectBack = nodeToDelete -> rightChild;
    }

    //Connect it back
    if(nodeToDelete == parentNode -> leftChild)
    {
        parentNode -> leftChild = toConnectBack;
    }
    else if(nodeToDelete == parentNode -> rightChild)
    {
        parentNode -> rightChild = toConnectBack;
    }

    //Delete the damn thing
    delete nodeToDelete;
}

void BinarySearchTree::DeleteTwoChildren(TreeNode* nodeToDelete, TreeNode* parentNode)
{
    //Find value to replace and switch deletion pointer
    TreeNode* bottomNode = nodeToDelete -> rightChild;
    TreeNode* newParent = nodeToDelete;
    while(bottomNode -> leftChild != NULL)
    {
        newParent = bottomNode;
        bottomNode = bottomNode -> leftChild;
    }

    //Switch values
    cout << "minimum value in branch is " << bottomNode -> value << endl;
    nodeToDelete -> value = bottomNode -> value;


    if(bottomNode -> leftChild  == NULL &&
       bottomNode -> rightChild == NULL)
    {
        DeleteNoChildren(bottomNode, newParent);
    }

    else if((bottomNode -> leftChild != NULL && bottomNode -> rightChild == NULL) ||
            (bottomNode -> leftChild == NULL && bottomNode -> rightChild != NULL))
    {
        DeleteOneChild(bottomNode, newParent);
    }

}

void BinarySearchTree::DestroyBranch(TreeNode* node)
{
    if(node -> leftChild != NULL)
    {
        DestroyBranch(node -> leftChild);
    }

    if(node -> rightChild != NULL)
    {
        DestroyBranch(node -> rightChild);
    }

    if(node -> leftChild  == NULL &&
       node -> rightChild == NULL)
    {
        delete node;
    }
}

void BinarySearchTree::PreOrder(TreeNode* node)
{
    if(node != NULL)
    {
        cout << node -> value << " - ";
        PreOrder(node -> leftChild);
        PreOrder(node -> rightChild);
    }
}

void BinarySearchTree::PostOrder(TreeNode* node)
{
    if(node != NULL)
    {
        PostOrder(node -> leftChild);
        PostOrder(node -> rightChild);
        cout << node -> value << " - ";
    }
}

void BinarySearchTree::InOrder(TreeNode* node)
{
    if(node != NULL)
    {
        InOrder(node -> leftChild);
        cout << node -> value << " - ";
        InOrder(node -> rightChild);
    }
}
