#include<iostream>
#include<string>
#include<fstream>
//#include<malloc>
using namespace std;
struct node{
	int data;
	struct node *next;
};
node *display(node *start){
	node *ptr;
	ptr = start;
	if(start==NULL) cout<<"EMPTY LINKLIST\n";
	else{
		while(ptr!=NULL){
			cout<<ptr->data<<" ";
			ptr = ptr->next;
		}
		cout<<endl;
	}
}

int main(){
	ifstream file;
	string line;
	file.open("studata.txt");
	getline(file, line);
	int n = stoi(line);
	node *arr[n];
	for(int i = 0;i<n;i++){
		
	}	
	file.close();
	return 0;
}
