#include<iostream>
using namespace std;
class Queue{
	public:
		int *arr, size, front, rear;
		Queue(int s)
		{
			size = s;
			front = rear = -1;
			arr = new int[s];
		}
		bool isEmpty()
		{
			return (front==-1 && rear==-1);
		}

		bool isFull()
		{
			return (rear==size-1);
		}
		int get_front()
		{
			if(isEmpty()){
				//cout<<"Empty front\n";
				return -1;
			}
			return arr[front];
		}
		void enqueue(int data)
		{
			if(isFull()){
				cout<<"queue full\n";
				return;
			}
			else if(isEmpty()){
				front = rear = 0;
				arr[rear] = data;
				return;
			}
			rear++;
			arr[rear] = data;
		}
		int dequeue()
		{
			if(isEmpty()){
				cout<<"no element\n";
				return -1;
			}
			else if(front==rear){
				int k = arr[front];
				front = rear = -1;
				return k;
			}
			int k = arr[front];
			front++;
			return k;
		}
		void print(){
			for(int i=front;i<=rear;i++)
				cout<<arr[front]<<" ";
			cout<<endl;
		}
};
struct node{
	int data;
	node *left;
	node *right;
};
node *start = NULL;
void levelOrder(node *start){
	Queue q;
	node *ptr;
	ptr = start;
	if(start==NULL){ 
		cout<<"empty tree\n";
		return;
	}
	else{
		q.enqueue(ptr->data);
	}
}
int main(){
	
	return 0;
}

