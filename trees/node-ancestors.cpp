#include <iostream>
#include <stack>

using namespace std;

class BstNode {
  public:
  int data;
  BstNode *left;
  BstNode *right;
  BstNode(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }  
};


class Tree {
  public:
  BstNode *root;
  Tree() {
    root = NULL;
  }
  void insert(int d) {
    BstNode *newNode = new BstNode(d);
    //cout<<newNode->data<<endl;
    if(root == NULL) {
      root = newNode;
      return;
    }
    BstNode *temp = root;
    int flag = 1;
    while(flag) {
      if(d > temp->data) {
        if(temp->right != NULL)
          temp = temp->right;
        else {
          temp->right = newNode;
          flag = 0;
        }
      }
      else if(d < temp->data) {
        if(temp->left != NULL)
          temp = temp->left;
        else {
          temp->left = newNode;
          flag = 0;
        }
      }
      else 
        flag = 0;
    }
  }
};

int storeAncestor(int f, BstNode* root, stack<int> *s) {
  if(root == NULL)
    return 0;
  int ans;
  s->push(root->data);
  if(root->data == f)
    return 1;
  ans = storeAncestor(f, root->left, s);
  if(ans == 1)
    return 1;
  if(ans == -1)
    s->pop();
  ans = storeAncestor(f, root->right, s);
  if(ans == 1)
    return 1;
  if(ans == -1)
    s->pop();
  return -1;
}

int main() {
  Tree t;
  t.insert(10);
  t.insert(5);
  t.insert(12);
  t.insert(4);
  t.insert(7);
  t.insert(2);
  t.insert(3);
  t.insert(13);
  t.insert(14);
  t.insert(6);
  t.insert(9);
  t.insert(11);
  t.insert(15);

  //get ancestor
  stack<int> *s = new stack<int>();
  storeAncestor(15, t.root, s);
  //display ancestor stack
  while(!s->empty()) {
    cout<<s->top()<<endl;
    s->pop();
  }
  return 0;
}
