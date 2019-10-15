#include<iostream>
using namespace std;
class node  
{  
    public: 
    int data;  
    node* left, *right;  
};
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
    return(Node);  
}  
class Queue{
	public:
		int front, rear;
		node *arr[100];
		Queue(){
			front = -1;
			rear = -1;
		}
		bool isEmpty()
		{
			return (front==-1 && rear==-1);
		}
		bool isFull()
		{
			return (rear==99);
		}
		node* get_front()
		{
		
			return arr[front];
		}
		void enqueue(node *Node)
		{
			if(isFull()){
				cout<<"queue full\n";
				return;
			}
			else if(isEmpty()){
				front = rear = 0;
				arr[rear] = Node;
				return;
			}
			rear++;
			arr[rear] = Node;
		}
		void dequeue()
		{
			if(isEmpty()){
				cout<<"no element\n";
				return;
			}
			else if(front==rear){
				front = rear = -1;
				return;
			}
			front++;
		}
};
void printLevelOrder(node *root) 
{ 
    if (root == NULL)  return; 
  
    Queue q; 
    q.enqueue(root); 
  
    while (!q.isEmpty()) 
    { 
        node *Node = q.get_front(); 
        cout << Node->data << " "; 
        q.dequeue(); 
  
        if (Node->left != NULL) 
            q.enqueue(Node->left); 
  
        if (Node->right != NULL) 
            q.enqueue(Node->right); 
    } 
    cout<<endl;
} 
int main(){
	
	node *root = newNode(1); 
    	root->left = newNode(2); 
    	root->right = newNode(3); 
    	root->left->left = newNode(4); 
    	root->left->right = newNode(5); 
  
   	cout << "Level Order traversal of binary tree is \n"; 
    	printLevelOrder(root); 
    	return 0; 
}

