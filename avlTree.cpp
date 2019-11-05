#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *left, *right;
};
node *newNode(int data){
	node *Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return Node;
}
node *insert(node *root,int data){
	if(root==NULL){
		return newNode(data);
	}
	if(data<=root->data){
		root->left = insert(root->left, data);
	}
	else{
		root->right = insert(root->right, data);
	}
	return root;
}
void print_inorder(node *root){
	if(root!=NULL){
		print_inorder(root->left);
		cout<<root->data<<" ";
		print_inorder(root->right);
	}
}
int main(){
	node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);
	print_inorder(root);
	cout<<endl;
	return 0;
}
