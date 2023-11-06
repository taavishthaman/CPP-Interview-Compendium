#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node * left;
    Node * right;
    Node(int data) {
        this->data = data;
    }
};

Node * buildTree() {
    int d;
    cin>>d;
    if(d == -1) {
        return NULL;
    }
    
    Node * n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    
    return n;
}

void preorder(Node * root) {
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void levelOrderPrint(Node * root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();
        
        if(f == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout<<f->data<<" ";
            if(f->left != NULL) {
                q.push(f->left);
            }
            if(f->right != NULL) {
                q.push(f->right);
            }
        }
    }
}

Node * levelorderBuild() {
    int d;
    cin>>d;
    Node * root = new Node(d);
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node * f = q.front();
        q.pop();
        int d1, d2;
        cin>>d1>>d2;
        
        if(d1 != -1) {
            f->left = new Node(d1);
            q.push(f->left);
        }
        if(d2 != -1) {
            f->right = new Node(d2);
            q.push(f->right);
        }
    }
    
    return root;
}

int height(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

int diameter(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    return max({D1, D2, D3});
}

class HDPair {
public:
    int height;
    int diameter;
};

HDPair diameterOpt(Node * root) {
    HDPair p;
    if(root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }
    
    HDPair leftP = diameterOpt(root->left);
    HDPair rightP = diameterOpt(root->right);
    p.height = max(leftP.height, rightP.height) + 1;
    int D1 = leftP.height+rightP.height;
    int D2 = leftP.diameter;
    int D3 = rightP.diameter;
    p.diameter = max({D1, D2, D3});
    
    return p;
}

int replaceWithDescendantSum(Node * root) {
    if(root == NULL) {
        return 0;
    }
    
    if(root->left == NULL && root->right == NULL) {
        return root->data; 
    }  
    
    int LS = replaceWithDescendantSum(root->left);
    int RS = replaceWithDescendantSum(root->right);
    int temp = root->data;
    root->data = LS + RS;
    
    return root->data + temp;
}

class Pair {
public:
    int inc;
    int exc;
};

Pair maxSubsetSum(Node * root) {
    Pair p;
    if(root == NULL) {
        p.inc = p.exc = 0;
        return p;
    }
    
    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);
    
    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc, left.exc) + max(right.inc, right.exc);
    
    return p;
}

int main() {
    //Preorder: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
    //Levelorder: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
    // Node * root = buildTree();
    // preorder(root);
    // cout<<endl;
    // levelOrderPrint(root);
    
    Node * root = levelorderBuild();
    levelOrderPrint(root);
    // cout<<height(root)<<endl;
    // cout<<diameter(root)<<endl;
    // cout<<diameterOpt(root).diameter<<endl;
    // replaceWithDescendantSum(root);
    // levelOrderPrint(root);
    Pair p = maxSubsetSum(root);
    cout<<max(p.inc, p.exc)<<endl;
}