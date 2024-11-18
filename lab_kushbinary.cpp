
#include <iostream>
#include <queue> // Include queue header
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to create a binary tree
void Tree_create(Node* root) {
    int first, second;
    queue<Node*> q;

    q.push(root); // Start with the root node
    while (!q.empty()) {
        Node* temp = q.front(); // Get the front node
        q.pop();

        cout << "Enter the left value of " << temp->data << " (-1 for no child): ";
        cin >> first;
        if (first != -1) { // Check for valid input
            temp->left = new Node(first);
            q.push(temp->left);
        }

        cout << "Enter the right value of " << temp->data << " (-1 for no child): ";
        cin >> second;
        if (second != -1) { // Check for valid input
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
}

void InOrder(Node*root){
    
    if(root==NULL){
        return ;
    }

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);

}
void size(Node*root,int &n){
     if(root==NULL){
        return ;
    }

    InOrder(root->left);
    n++;
    InOrder(root->right);

}

int main() {
    int k;
    cout << "Enter root value: ";
    cin >> k;

    Node* root = new Node(k); // Create root node
    Tree_create(root); // Create the tree

    InOrder(root);
    cout<<endl;
      
    int count=0;
    size(root,count);
    cout<<"The size of Tree is : "<<count;



    return 0;
}