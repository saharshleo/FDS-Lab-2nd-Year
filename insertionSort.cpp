#include<iostream>
using namespace std;
void insertionSort(int arr[], int n){
	for(int i=1;i<n;i++){
		int temp1 = arr[i];
		int j = i-1;
		while(arr[j]>temp1 && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp1;
	}
}

int main(){
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	insertionSort(arr, n);
	cout<<"After Sorting\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
