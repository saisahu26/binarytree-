#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
//Node* root = NULL;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* root = NULL;

Node* createNode(int data) { //createNode takes in the head and data, see which side to put in the node
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) { //same as create node but the actual insertion process
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* minValueNode(Node* node) { //passes in the node to find left node
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) { //delete node takes in the node and the data and creates 
  if (root == NULL) {
    return root;
  }
  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  }
  else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
	    delete root;
	    return temp;
}
	else if (root->right == NULL) {
	  Node* temp = root->left;
	  delete root;
	  return temp;
  }
Node* temp = minValueNode(root->right);
root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);//recursion to cotinue walking and deleting 
}
return root;
}

bool search(Node* root, int data) {//search takes in the root and the data to walk thorugh and return a bool if true or false
  if (root == NULL)
    return false;
  if (root->data == data)
    return true;
  if (data < root->data)
    return search(root->left, data);
  return search(root->right, data);
}

void printInOrder(Node* root) { //this is for printing the numbers before and after the enter
  if (root != NULL) {
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
  }
}

void printTree(Node* root, int space) { //this is for printing the tree after enter and deletion 
  if (root == NULL)
    return;

  space += 10;

  printTree(root->right, space);
  cout << endl;
  for (int i = 10; i < space; i++)
    cout << " ";
  cout << root->data << "\n";

  printTree(root->left, space);
}

int main() {

  /*int rootval;
  cout << "what do you want as your root" << endl;
  cin >> rootval;
  root = insert(root, rootval);*/
  int searchNum;
  while (true) {
    if (root == NULL) {
      int rootval;
      cout << "enter a root" << endl;
      cin >> rootval;
      root = insert(root, rootval);
    }
    char type;
  cout << " type a(add), d(delete), s(search), q(quit)" << endl;
  cin >> type;
  
  if (type == 'a') {
     int enterlength;
     cout << "How many numbers do you want to enter?" << endl;
     cin >> enterlength;
     int enter;
     for(int i = 0; i < enterlength; i++) {
       cin >> enter;
       insert(root, enter);

     }
     cout << "Inorder traversal of the binary search tree: ";
     printInOrder(root);
     cout << endl;
     printTree(root, 0);
  }
  else if (type == 's') {
    cout << "What number do you want to search for? " << endl;
    cin >> searchNum;
    cout << "Searching: " << (search(root, searchNum) ? "Found" : "Not found") << endl;
  }
  else if (type == 'd') {
    int deleten;
    cout << "what number do you want to delete" << endl;
    cin >> deleten;
    root = deleteNode(root, deleten);
    printTree(root, 0);
  }
  else if (type == 'q') {
    break;

  }

  cout << "Visual representation of the binary search tree:\n";
  }
  return 0;
}

