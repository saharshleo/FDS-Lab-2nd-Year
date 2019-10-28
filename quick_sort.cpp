//#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int partition(int arr[], int p, int r){
	int pivot = arr[r];
	int i = p-1, j = p;
	while(i<=j && j<r){
		if(arr[j]<pivot){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		j++;
	}
	int temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return (i+1);
}
void quick_sort(int arr[], int p, int r){
	if(p<r){
		int q = partition(arr, p, r);
		quick_sort(arr, p, q-1);
		quick_sort(arr, q+1, r);
	}
}

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int r;
	cout<<"Enter number of elements: ";
	cin>>r;
	int arr[r];
	cout<<"Enter n integers:\n";
	for(int i=0;i<r;i++)
		cin>>arr[i];
	quick_sort(arr, 0, r-1);
	cout<<"After sorting\n";
	for(int i=0;i<r;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}

