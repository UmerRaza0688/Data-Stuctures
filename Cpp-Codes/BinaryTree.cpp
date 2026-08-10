// Implementing Binary Search Tree (BST), and different methods on it
#include <iostream>
#include <queue>
using namespace std;

//declaring functions
class BST;
void printSpaces(int n);
void printTree(const BST &bst);

// class for single node of BST
class TreeNode{
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

// class for Binary Search Tree (BST)
class BST{
    private:
    TreeNode* root;
    
    // functions which use recursion in their logic, for them we will use a recursive helper 
    // functions. The public function will call it's corresponding private recursive one 

    // helper fun for preorder_DFS
    void preorder_DFS(TreeNode* node){
        cout << node->value << endl;

        if(node->left != nullptr)
            preorder_DFS(node->left);
        if(node->right != nullptr)
            preorder_DFS(node->right);
    }

    // helper fun for inorder_DFS
    void inorder_DFS(TreeNode* node){
        if(node->left != nullptr)
            inorder_DFS(node->left);

        cout << node->value << endl;

        if(node->right != nullptr)
            inorder_DFS(node->right);
    }

    // helper fun for postorder_DFS
    void postorder_DFS(TreeNode* node){
        if(node->left != nullptr)
            postorder_DFS(node->left);
        if(node->right != nullptr)
            postorder_DFS(node->right);   
    
        cout << node->value << endl;
    }

    // helper fun for GetHeight
    int GetHeight(TreeNode* node) const{
        if(node == nullptr) return 0;

        return 1 + max(GetHeight(node->left), GetHeight(node->right));
    }

    public:
    // constructor
    BST() { root = nullptr; }
    // destructor
    ~BST() { delete root; }

    // Different functions or methods of BST

    // functions for traversing through BST

    // Using Depth_First Search(DFS), based on recursion, three strategies
    // Root --> Left_Subtree --> Right_Subtree
    void preorder_DFS();
    // Left_Subtree --> Root --> Right_Subtree
    void inorder_DFS();
    // Left_Subtree --> Right_Subtree --> Root
    void postorder_DFS();

    // Using Breadth_First Search(BFS), without recursion
    void Breadth_First_Search();

    // Other operations on BST

    // Inserting a node in BST
    void insert(int val);
    // Deleting a node in BST
    void remove(int val);
    // to check if node is leaf or not
    bool isLeaf(int val);
    // Searching a particular val in BST
    bool search(int val);
    // get height of BST
    int GetHeight();
    // a friend fun to print the BST
    friend void printTree(const BST& bst);
};
// ______________________________________BST Implementation Ended______________________________________


//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX---Functions In BST Class---XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// Different functions or methods of BST

// functions for traversing through BST

// Using Depth_First Search(DFS), based on recursion, three strategies
// Root --> Left_Subtree --> Right_Subtree
void BST::preorder_DFS(){ preorder_DFS(root); }

// Left_Subtree --> Root --> Right_Subtree
void BST::inorder_DFS(){ inorder_DFS(root); }

// Left_Subtree --> Right_Subtree --> Root
void BST::postorder_DFS(){ postorder_DFS(root); }

// Using Breadth_First Search(BFS), without recursion
void BST::Breadth_First_Search(){
    queue<TreeNode*> to_visit;
    to_visit.push(root);
    TreeNode* current;

    while(to_visit.size() != 0){
        current = to_visit.front();
        to_visit.pop();

        cout << current->value << endl;         // process the node

        if(current->left != nullptr)
            to_visit.push(current->left);
        if(current->right != nullptr)
            to_visit.push(current->right);
    }
}

// Get height of BST
int BST::GetHeight(){
    return GetHeight(root);
}

// Other operations on BST

// Inserting a node in BST
void BST::insert(int val){
    TreeNode* new_node = new TreeNode(val);

    // Edge case
    if(root == nullptr){
        root = new_node;
        return;
    }

    TreeNode* parent = root;        // this will follow the current node, but remain one step back
    TreeNode* current = root;       // this will help us to traverse through BST, 
                                    // we will insert new_node at current position

    // adding node
    while(current != nullptr){      // until we get a leaf node
        parent = current;

        if      (val < current->value)  current = current->left;
        else if (val > current->value)  current = current->right;
        else {
            cout << "In BST duplicates aren't allowed, change your value" << endl;
            delete new_node;
            return;
        }
    }

    // if all good, linking node
    if      (val < parent->value)   parent->left = new_node;
    else                            parent->right = new_node;   // for clarity: else if(val > parent->value)
                                                                //              parent->right = new_node     
}

// Deleting a node in BST
void BST::remove(int val){
    // if no tree
    if(root == nullptr) return;

    // The node which will traverse through tree
    TreeNode* current = root;
    // this node will stay one step behind the current node
    TreeNode* parent = nullptr;    

    // major case, if the root is the only node and it's the target
    if(root->left == nullptr && root->right == nullptr && root->value == val){
        delete root;
        root = nullptr;
        return;
    }

    // searching for the required node
    while(current != nullptr && current->value != val){
        parent = current;

        if      (val < current->value)      current = current->left;
        else if (val > current->value)      current = current->right;
    }

    if(current == nullptr) return;  // val not found

    // case 1: if leaf node
    if(isLeaf(current->value)){
        // break the link with leaf node
        if(parent->left == current){
            parent->left = nullptr;
        }
        if(parent->right == current){
            parent->right = nullptr;
        }

        delete current;     // delete the current node
        return;
    }

    // case 2: current node has one left child
    if(current->right == nullptr){              // if left exists, right must be null
        int leftVal = current->left->value;     // store val
        remove(current->left->value);           // remove curr->left by recursive call
        current->value = leftVal;               // replace val
        return;
    }

    // case 3: if current node has one right child
    if(current->left == nullptr){               // if right exists, left must be null
        int rightVal = current->right->value;   // store val
        remove(current->right->value);          // remove curr->right by recursive call
        current->value = rightVal;                 // replace val
        return;
    }

    // case 4: if current node has two children
    if(current->left != nullptr && current->right != nullptr){
        // find min node in right subtree, replace it, delete min node in subtree

        // find min node (most left node in right subtree)
        TreeNode* minNode = current->right;
        while(minNode->left != nullptr){
            minNode = minNode->left;
        }

        int minVal = minNode->value;    // store the val of minNode
        remove(minNode->value);         // first remove minNode from right subtree
                                        // (in case minNode has a right child, it'll be handled)
        current->value = minVal;        // now overwrite val of current node  
        return;
    }
}

// to check if node is leaf or not
bool BST::isLeaf(int val){
    TreeNode* current = root;

    // find the node
    while(current != nullptr){
        if      (val < current->value)  current = current->left;
        else if (val > current->value)  current = current->right;
        else break;     // value found 
    }   

    // if value is not in the BST 
    if (current == nullptr){
        cout << "Value not found in the BST" << endl;
        return false;
    }

    // return true if current node is leaf else false
    return (current->left == nullptr && current->right == nullptr);
}    

// Searching a particular val in BST
bool BST::search(int val){
    TreeNode* current = root;

    // find the node
    while(current != nullptr){
        if      (val < current->value)  current = current->left;
        else if (val > current->value)  current = current->right;
        else return true;   // value found
    }   

    // if value is not in the BST 
    return false;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

// _____________________________________Testing_____________________________________________
int main(){
    BST bst;

    bst.insert(11);
    bst.insert(14);
    bst.insert(12);
    bst.insert(19);
    bst.insert(9);
    bst.insert(7);
    bst.insert(10);
    bst.insert(24);
    bst.insert(15);

    printTree(bst);
    
    // cout << bst.GetHeight() << endl;

    // Depth First Search, 3 categories
    // bst.preorder_DFS();
    // bst.inorder_DFS();
    // bst.postorder_DFS();

    // bst.Breadth_First_Search();

    // cout << "Leaf node: " << bst.isLeaf(15) << endl;

    // check if node is in the BST or not
    // if(bst.search(1))
    //     cout << "This node is in the BST" << endl;
    // else
    //     cout << "Not Found!" << endl;

    // printTree(bst);
    // bst.remove(10);
    // printTree(bst);
    // bst.remove(19);
    // printTree(bst);
    // bst.remove(11);
    // printTree(bst);
    // bst.remove(14);
    // printTree(bst);

    return 0;
}
// --------------------------------- MAIN Ended -----------------------------------------------

























// ── global printTree function ─────────────────────────────────────────────────
void printSpaces(int n) {
    for (int i = 0; i < n; i++) cout << ' ';
}

void printTree(const BST &bst) {
    TreeNode* root = bst.root;               // accessible because of friend

    if (!root) { cout << "Empty BST.\n"; return; }

    int h = bst.GetHeight(root);

    vector<TreeNode*> current = { root };   // current level (nulls kept for alignment)

    for (int level = 0; level < h; level++) {
        int leading = (1 << (h - level - 1)) - 1;  // spaces before first node
        int gap     = (1 << (h - level))     - 1;  // spaces between nodes

        // ── print node values ─────────────────────────────────────────────────
        printSpaces(leading);
        for (int i = 0; i < (int)current.size(); i++) {
            if (i > 0) printSpaces(gap);
            cout << (current[i] ? to_string(current[i]->value) : " ");
        }
        cout << '\n';

        // ── print branch connectors ───────────────────────────────────────────
        if (level < h - 1) {
            printSpaces(leading - 1);
            for (int i = 0; i < (int)current.size(); i++) {
                if (i > 0) printSpaces(gap - 2);
                if (current[i]) {
                    cout << (current[i]->left  ? '/' : ' ');
                    cout << ' ';
                    cout << (current[i]->right ? '\\' : ' ');
                } else {
                    cout << "   ";
                }
            }
            cout << '\n';
        }

        // ── build next level ──────────────────────────────────────────────────
        vector<TreeNode*> next;
        for (auto node : current) {
            next.push_back(node ? node->left  : nullptr);
            next.push_back(node ? node->right : nullptr);
        }
        current = next;
    }
}