#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree createTestTree();

int main()
{
    BinarySearchTree testTree = createTestTree();
    cout << "Before traversal" << endl;

    if(testTree.getRoot() == NULL)
    {
        cout << "Root of tree is NULL" << endl;
    }

    testTree.BreadthFirstTraversal();
    testTree.DepthFirstPreOrder();
    testTree.DepthFirstPostOrder();
    testTree.DepthFirstInOrder();

    cout << "\n\n\nDeleting node with no children - 2" << endl;
    testTree.BSTDelete(2);
    testTree.BreadthFirstTraversal();
    testTree.DepthFirstPreOrder();
    testTree.DepthFirstPostOrder();
    testTree.DepthFirstInOrder();

    cout << "\n\n\nDeleting node with 1 child - 85" << endl;
    testTree.BSTDelete(85);
    testTree.BreadthFirstTraversal();
    testTree.DepthFirstPreOrder();
    testTree.DepthFirstPostOrder();
    testTree.DepthFirstInOrder();

    cout << "\n\n\nDeleting node with 2 children - 25" << endl;
    testTree.BSTDelete(25);
    testTree.BreadthFirstTraversal();
    testTree.DepthFirstPreOrder();
    testTree.DepthFirstPostOrder();
    testTree.DepthFirstInOrder();



    return 0;
}

BinarySearchTree createTestTree()
{
    cout << "Starting to create tree" << endl;
    BinarySearchTree tree;

    tree.BSTInsert(50);
    tree.BSTInsert(25);
    tree.BSTInsert(75);
    tree.BSTInsert(15);
    tree.BSTInsert(35);
    tree.BSTInsert(65);
    tree.BSTInsert(85);
    tree.BSTInsert(5);
    tree.BSTInsert(2);
    tree.BSTInsert(98);

    cout << "Completed Tree creation" << endl;

    return tree;
}
