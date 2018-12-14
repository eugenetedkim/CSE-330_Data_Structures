class BST
{
private: // can only be accessed by the class itself
    struct node
    {
        int key;
        node* left;
        node* right;
    };

    node* root; // use to reference the top of the tree; the root node

public: // can be accessed by the main function

    BST(); // consructor prototype
    node* CreateLeaf(int key);



};
