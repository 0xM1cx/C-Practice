#include <iostream>
using namespace std;

// Blue print of node
class node {
public:
    int data;
    node *left;
    node *right;
};

// Create a Node
node *createNode(int data) {
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

int main() {
    node *root = createNode(14);
    root->left = createNode(13);
    root->right = createNode(15);

    printf("root node => %d\nleft leaf => %d\nright leaf => %d", root->data, root->left->data, root->right->data);
    printf("\n The size of the tree is: %d", sizeof(root) / sizeof(3));
    return 0;
}
