#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *left, *right;
		Node(int data){
			this->data = data;
			left = right = NULL;
		}
};
int height(Node *root){
	if(root==NULL) return 0;
	int l = height(root->left);
	int r = height(root->right);
	return (l>r?l:r)+1;
}

int main(){
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
	cout<<"Height : "<<height(root)<<endl;
	return 0;
}
