#include<iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end){
	int size1 = mid-start+1, size2 = end-mid;
	int arr1[size1], arr2[size2];
	int i, j, k;
	for(i = 0;i < size1;i++)
		arr1[i] = arr[start+i];
	for(j = 0;j < size2;j++)
		arr2[j] = arr[mid+1+j];
	i = 0;
	j = 0;
	k = start;
	while(i<size1 && j<size2){
		if(arr1[i]<=arr2[j]){
			arr[k] = arr1[i];
			i++;
		}
		else{
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	while(i<size1)
		arr[k++] = arr1[i++];
	while(j<size2)
		arr[k++] = arr2[j++];
}
void mergeSort(int arr[], int start, int end){
	if(start<end){
		int mid = (start+end)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}
int main(){
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	mergeSort(arr, 0, n-1);
	cout<<"After Sorting\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
