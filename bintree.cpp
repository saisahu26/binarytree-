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

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int data) {
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
root->right = deleteNode(root->right, temp->data);
}
return root;
}

bool search(Node* root, int data) {
  if (root == NULL)
    return false;
  if (root->data == data)
    return true;
  if (data < root->data)
    return search(root->left, data);
  return search(root->right, data);
}

void printInOrder(Node* root) {
  if (root != NULL) {
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
  }
}

void printTree(Node* root, int space) {
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
  root = new Node;
  root->data = 10;
  int searchNum;
  while (true) {
    // Node* root = NULL;
  char type;
  cin >> type;
  
  if (type == 'a') {
  int enterlength;
  cin >> enterlength;
  cout << "How many numbers do you want to enter?" << endl;
  // Example usage
  // root = new Node;
  // root->data = 10;
  // root = insert(root, 10);
  int enter;
  for(int i = 0; i < enterlength; i++) {
    cin >> enter;
    insert(root, enter);

  }
  /*  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);*/
   cout << "Inorder traversal of the binary search tree: ";
  printInOrder(root);
  cout << endl;
  // printInOrder(root);
  // cout << endl;
  printTree(root, 0);
  }
  // cout << "Inorder traversal of the binary search tree: ";
  // printInOrder(root);
  // cout << endl;
  
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
   // cout << "Inorder traversal after deleting 20: ";
   // printInOrder(root);
   // cout << endl;
    printTree(root, 0);
  }
  // printInOrder(root);
  // cout << endl;

  cout << "Visual representation of the binary search tree:\n";
  // printTree(root, 0);
  }
  return 0;
}

