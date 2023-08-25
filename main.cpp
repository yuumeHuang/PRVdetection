#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <cstring> 

void swap(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
} 

void swapi(int* a,int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
} 

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

int main(){
	int *a1 = new int[200000];
	memset(a1,0,sizeof(int)*200001);
	int *t1 = new int[200000];
	memset(t1,0,sizeof(int)*200001);
	int *c1 = new int[200000];
	memset(c1,0,sizeof(int)*200001);
	int *g1 = new int[200000];
	memset(g1,0,sizeof(int)*200001);
	int *q1 = new int[200000];
	memset(q1,0,sizeof(int)*200001);
	int *a2 = new int[200000];
	memset(a2,0,sizeof(int)*200001);
	int *t2 = new int[200000];
	memset(t2,0,sizeof(int)*200001);
	int *c2 = new int[200000];
	memset(c2,0,sizeof(int)*200001);
	int *g2 = new int[200000];
	memset(g2,0,sizeof(int)*200001);
	int *q2 = new int[200000];
	memset(q2,0,sizeof(int)*200001);
	char *bs = new char[200000];
	memset(bs,0,sizeof(char)*200001);
	char *bs2 = new char[200000];
	memset(bs2,0,sizeof(char)*200001);
	FILE *tp1;
	tp1 = fopen("type1","r");
	FILE *tp2;
	tp2 = fopen("type2","r");
	FILE *xl;
	xl = fopen("1.fa","r");
	FILE *outfile;
	outfile = fopen("cout.tsv","w");
	FILE *bupaixu;
	bupaixu = fopen("cbub.txt","w");	
	char a[11];
	char b[61];
	char list1[18][11];
	char list2[49][11];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(list1,0,sizeof(list1));
	memset(list2,0,sizeof(list2));
	int *score = new int[199860];
	int *place = new int[199860];
	int *conti = new int[199860];
	int *contii = new int[199860];
	for(int i = 1;i < 18;i++){
		fscanf(tp1,"%s",list1[i]);
	}
	for(int i = 1;i < 49;i++){
		fscanf(tp2,"%s",list2[i]);
	}
	for(int i = 1;i < 68;i++){
		fscanf(xl,"%s",a);
		if (strstr(list1[1],a) != NULL){
			for(int j = 1;j < 3332;j++){
				fscanf(xl,"%s",b);
				for(int k=0;k<60;k++){
					if (b[k] == 'a')
                    	a1[(j-1)*60+k]++;
                	if (b[k] == 't')
                    	t1[(j-1)*60+k]++;
                	if (b[k] == 'c')
                    	c1[(j-1)*60+k]++;
                	if (b[k] == 'g')
                    	g1[(j-1)*60+k]++;
                	if (b[k] == '-')
                    	q1[(j-1)*60+k]++;
                    bs[(j-1)*60+k] = b[k];
				}	
			}
		}
		else if (strstr(list2[1],a) != NULL){
			for(int j = 1;j < 3332;j++){
				fscanf(xl,"%s",b);
				for(int k=0;k<60;k++){
					if (b[k] == 'a')
                    	a2[(j-1)*60+k]++;
                	if (b[k] == 't')
                    	t2[(j-1)*60+k]++;
                	if (b[k] == 'c')
                    	c2[(j-1)*60+k]++;
                	if (b[k] == 'g')
                    	g2[(j-1)*60+k]++;
                	if (b[k] == '-')
                    	q2[(j-1)*60+k]++;
                    bs2[(j-1)*60+k] = b[k];
				}
			}
		}
		else{
			for(int j = 1;j < 3332;j++){
				fscanf(xl,"%s",b);
			}
		}
	}
	for(int i = 0;i < 199859;i++){
		score[i] = 0;
		score[i] = (a1[i]*48-a2[i]*17)*(a1[i]*48-a2[i]*17)+(t1[i]*48-t2[i]*17)*(t1[i]*48-t2[i]*17)+(c1[i]*48-c2[i]*17)*(c1[i]*48-c2[i]*17)+(g1[i]*48-g2[i]*17)*(g1[i]*48-g2[i]*17)+(q1[i]*48-q2[i]*17)*(q1[i]*48-q2[i]*17);
		place[i] = i+1;
		//printf("now calculating place %d\n",i);
	}
	for(int i=0;i<199859;i++){
		fprintf(bupaixu,"%d\t%d\n",place[i],score[i]);
	}
	
	heapsort(score,place,199859);
	
	conti[199859] = 1;
	contii[199859] = 1;
	fprintf(outfile,"place\tscore\tContinuous variation base\tbase in type1\tbase in type2\n");
	for(int i=199858;i>=0;i--){
		conti[i] = 1;
		contii[i] = 1;
		if(place[i]-place[i+1] == 1) conti[i] = conti[i+1]+1;
		if(place[i]-place[i+1] <= 3) contii[i] = contii[i+1]+1;
		fprintf(outfile,"%d\t%d\t%d\t%c\t%c\n",place[i],score[i],conti[i],bs[place[i]],bs2[place[i]]);
	}
	fclose(outfile);
	return 0;
}
