#include "../swap/swap.h"

void maxheap(int arr[],int arr1[],int start,int end){
	int father = start;
	int son = father * 2 + 1;
	while(son <= end){
		if( son + 1 <= end && (arr[son + 1] > arr[son] || (arr[son + 1] == arr[son] && arr1[son+1] < arr1[son])))
			son++;
		if(arr[father] > arr[son] || (arr[father] == arr[son] && arr1[father] < arr1[son]))
			return;
		swap(&arr[father],&arr[son]);
		swapi(&arr1[father],&arr1[son]);
		father = son;
		son = father * 2 + 1;
	}
}

void heapsort(int arr[],int arr1[],int len){
	int i;
	for(i = (len-1)/2 ;i >= 0;i--)
		maxheap(arr,arr1,i,len-1);
	for(i = len-1;i>0;i--){
		swap(&arr[i],&arr[0]);
		swapi(&arr1[i],&arr1[0]);
		maxheap(arr,arr1,0,i-1);
	}
}