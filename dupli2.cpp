#include<iostream>

using namespace std;
struct node{
	int data;
	struct node *next;
};
node *start = NULL;

node *create( node *start){
	node *n, *ptr;   
	int k;
	cout<<"Enter data(-1 at the end): ";
	cin>>k;
	while(k!=-1){
		n = new node();
		n->data = k;
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
		cin>>k;
	}
	return start;
}

int main(){
	node *ptr1, *ptr2;
	cout<<"Create link list*****\n";
	start = create(start);
	cout<<"Original list*****\n";
	ptr1 = start;
	while(ptr1!=NULL){
		cout<<ptr1->data<<" ";
		ptr1 = ptr1->next;
	}
	cout<<endl;
	//cout<<start->data<<endl;
	cout<<"After removing Duplicates*****\n";
	ptr1 = start;
	while(ptr1->next!=NULL){
		ptr2 = ptr1;
		while(ptr2->next!=NULL){
			if(ptr1->data == ptr2->next->data){
				ptr2->next = ptr2->next->next;	
			}
			else
				ptr2 = ptr2->next;
			
		}
		if (ptr1->next!=NULL)ptr1 = ptr1->next;
	}
	ptr1 = start;
	while(ptr1!=NULL){
		cout<<ptr1->data<<" ";
		ptr1 = ptr1->next;
	}
	cout<<endl;
	return 0;
}











