#include<iostream>

struct node{
  int val;
  struct node* left;
  struct node* right;
};

node* createNode(int val){
  node* temp = new node;
  temp->val = val;
  temp->left= NULL;
  temp->right = NULL;
  return temp;
}

node* insert(node* root,int val){
  if(root == NULL){
    return createNode(val);
  }
  if(val < root->val){
    root->left = insert(root->left,val);}
  else{
    root->right = insert(root->right,val);
  }

  return root;
  
}
//print tree
void printTree(node* root){
  if(root != NULL){

    std::cout<<" "<<root->val<<" "<<std::endl;
    printTree(root->left);
    printTree(root->right);
  }
}
//find the preorder successor
node* minValueNode(node* root){
  //leftmode node
  node* current = root;
  while(current && current->left != NULL){
    current = current->left;
  }
  
  return current;
}
//deleting a node
node* delNode(node* root,int val){
  if(root == NULL){
    return root;
  }
  //find the node to del

  if(val < root->val){
    root->left = delNode(root->left,val);
  }else if(val > root->val){
    root->right = delNode(root->right,val);
  }else{
    //if one node empty
    if(root->left == NULL){
      node* temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      node* temp = root->left;
      free(root);
      return temp;
    }
    //if two node active

    struct node* temp = minValueNode(root->right);

    root->val = temp->val;

    root->right = delNode(root->right,temp->val);
  }

  return root;
}
int main(){
  node* root = createNode(8);
  root = insert(root,3);
  root = insert(root,10);
  root = insert(root,1);
  root = insert(root,6);
  root = insert(root,14);
  root = insert(root,4);
  root = insert(root,7);

  printTree(root);

  node* val = minValueNode(root);
  std::cout<<"Min val: "<<val->val<<std::endl;
  /*
  root = delNode(root,4);
  printTree(root);

  std::cout<<"Del 7: "<<std::endl;
  root = delNode(root,7);
  printTree(root);
  */
  
  std::cout<<"Del 3: "<<std::endl;
  root = delNode(root,3);
  printTree(root);
  
  return 0;
}
