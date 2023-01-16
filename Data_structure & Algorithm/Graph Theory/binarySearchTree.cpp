#include<bits/stdc++.h>

using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};
 
/* function to create a new node of tree and
return pointer */
struct Node* newNode(int key)
{
    struct Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};

struct Node* insert(struct Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
  
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
  
    /* return the (unchanged) node pointer */
    return node;
}

  
// A utility function to do 
// inorder traversal of BST
void inorder(struct Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}


// delation of BST 
Node* findLastLeft(Node* node)
{
    while(node->left!=NULL){
        node = node->left;
    }
    return node;
}

Node* deletion(Node* root, int data)
{
    if(root == NULL)
        return root;
    
    if(root->key > data)
        root->left = deletion(root->left, data);
    else if(root->key < data)
        root->right = deletion(root->right, data);
    else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }  
        Node* temp = findLastLeft(root->right);
        root->key = temp->key;
        root->right = deletion(root->right, temp->key);
    }
            
    return root;
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);

    root = deletion(root, 20);
cout << endl;
    inorder(root);

    return 0;
}