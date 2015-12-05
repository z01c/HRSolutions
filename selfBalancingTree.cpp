/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int max(int a, int b)
{
    return (a > b)? a : b;
}

int height(node *N)
{
    if (N == NULL)
        return -1;
    return N->ht;
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->ht = max(height(y->left), height(y->right))+1;
    x->ht = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->ht = max(height(x->left), height(x->right))+1;
    y->ht = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node * insert(node * root,int val)
{
    if (!root) {
        node * newNode = new node;
        newNode->val = val;
        return newNode;
    }
    
    if (val < root->val)
        root->left = insert(root->left, val);
    if (val > root->val)
        root->right = insert(root->right, val);
    
    root->ht = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    
    // Left Left Case
    if (balance > 1 && val < root->left->val)
        return rightRotate(root);
 
    // Right Right Case
    if (balance < -1 && val > root->right->val)
        return leftRotate(root);
 
    // Left Right Case
    if (balance > 1 && val > root->left->val)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Left Case
    if (balance < -1 && val < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}
