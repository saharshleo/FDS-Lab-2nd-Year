#include<iostream>
#include<malloc>
using namespace std;
struct node{
	int data;
	struct node *next;
};
node *start = NULL;
node *create(node *);
node *insertBeg(node *);
node *insertEnd(node *);
node *insertAfter( node *);
node *delBeg( node *);
node *delEnd( node *);
node *delAfter( node *);
node *display( node *);

int main(){
	int choice = 0;
	while(choice!=9){
	cout<<"Enter Operation:\n1.Create\t2.Insert Beginning\n3.Insert End\t4.Insert After\n5.Delete Beginning\t6.Delete End\n8.Display\t9.Remove duplicates\n10.Exit\n";
	cin>>choice;
	cout<<"*******\n";
	
		switch(choice){
			case 1:
				start = create(start);
				break;
			case 2:
				start = insertBeg(start);
				break;
			case 3:
				start = insertEnd(start);
				break;
			case 4:
				start = insertAfter(start);
				break;
			case 5:
				start = delBeg(start);
				break;
			case 6:
				start = delEnd(start);
				break;
			case 7:
				start = display(start);
				break;
			case 8:
				start = remove(start);
				break;
			case 9:
				start = insertEnd(start);
				break;
			case default:
				cout<<"Invalid\n";
		}
	}
	return 0;
}
node *create( node *start){
	node *n, *ptr;
	n = new node();
	int k;
	cout<<"Enter data(-1 at the end): ";
	cin>>k
	while(k=-1){
		n->data = n;
		if(start==NULL){
			n->next = NULL;
			start = n;
		}
		else{
			ptr = start;
			while(ptr->next!=NULL)
				ptr = ptr->next;
			ptr->next = n;
			n->next = NULL;
		}
		cout<<"Enter next data: ";
		cin>>k;
	}
	return start;
}
node *insertBeg( node *start){
	node *n;
	int k;
	n = new node();
	cout<<"Enter data: ";
	cin>>k;
	n->data = k;
	n->next = start;
	start = n;
	return start;
}
node *insertEnd( node *start){
	node *n, *ptr;
	int k;
	n = new node();
	cout<<"Enter data: ";
	cin>>k;
	n->data = k;
	ptr = start;
	while(ptr->next!=next)
		ptr = ptr->next;
	ptr->next = n;
	n->next = NULL;
	return start;
}
node *insertAfter( node *start){
	node *n, *ptr, *prev;
	int k, after;
	n = new node();
	cout<<"Enter after data and new node's data: ";
	cin>>after>>k;
	n->data = k;
	ptr = start;
	prev = start;
	while(prev->data!=after){
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = n;
	n->next = ptr;
	return start;	
}
node *delBeg(node *start){
	node *temp;
	temp = start;
	start = start->next;
	delete(start);
	return start;
}
node *delEnd(node *start){
	node *ptr, *temp;
	ptr = start;
	while(ptr->next->next!=NULL)
		ptr = ptr->next;
	temp = ptr->next;
	ptr->next = NULL;
	delete(temp);
	return start;
}
node *delAfter(node *start){
	int n;
	node *prev, *ptr;
	cout<<"Enter data: ";
	cin>>n;
	prev = ptr = start;
	while(prev->data!=n){
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = ptr->next;
	delete(ptr);
	return start;
}
node *display(node *start){
	
}

































