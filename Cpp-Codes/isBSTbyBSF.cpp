#include <iostream>
#include <queue>
using namespace std;

// class for single node of BST
struct TreeNode{
    public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // constructor
    TreeNode(int v){
        value = v;
        left = right = nullptr;
    }

    // destructor
    ~TreeNode(){
        delete left;
        delete right;
    }
};

// fun to check if given tree is BST or not, using BSF
bool isBST(TreeNode* root){
    // if root is null, not tree
    if(root == nullptr) return true;

    // queue needed for BSF
    queue<TreeNode*> q;
    q.push(root);   // First push root

    TreeNode* temp;

    // until queue not became empty
    while(!q.empty()){
        temp = q.front();
        q.pop();

        // if left is not null
        if(temp->left){
            // if left node has greater val then it's parent, not BST
            if(temp->left->value >= temp->value)
                return false;

            
            q.push(temp->left);
        }

        // if right is not nullptr
        if(temp->right){
            // if right node has lower val then it's parent, not BST
            if(temp->right->value <= temp->value)
                return false;

            q.push(temp->right);
        }
    }

    return true;
}

int main(){
    // Manually putting vals in tree
    TreeNode* root = new TreeNode(11);
    root->left      = new TreeNode(9);
    root->right     = new TreeNode(14);
    root->left->left  = new TreeNode(7);
    root->left->right = new TreeNode(10);

    cout << isBST(root) << endl;

    delete root;
    return 0;
}