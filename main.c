#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "heapsort/heapsort.h"

int main( int argc, char *argv[] ){
	if ( argc != 7){
		printf("incorrect args\n");
		return 1;
	}
	int type1num = atoi(argv[4]);
	int type2num = atoi(argv[5]);
	int dnalength = atoi(argv[6]);
	printf("%s %s %s %d %d %d\n",argv[1],argv[2],argv[3],type1num,type2num,dnalength);
	int arraylength = dnalength + 100;
	int *a1 = (int*)malloc(sizeof(int)*arraylength);
	int *t1 = (int*)malloc(sizeof(int)*arraylength);
	int *c1 = (int*)malloc(sizeof(int)*arraylength);
	int *g1 = (int*)malloc(sizeof(int)*arraylength);
	int *a2 = (int*)malloc(sizeof(int)*arraylength);
	int *t2 = (int*)malloc(sizeof(int)*arraylength);
	int *c2 = (int*)malloc(sizeof(int)*arraylength);
	int *g2 = (int*)malloc(sizeof(int)*arraylength);
	int *q1 = (int*)malloc(sizeof(int)*arraylength);
	int *q2 = (int*)malloc(sizeof(int)*arraylength);
	char *bs = (char*)malloc(sizeof(char)*arraylength);
	char *bs2 = (char*)malloc(sizeof(char)*arraylength);
	FILE *tp1;
	tp1 = fopen(argv[2],"r");
	FILE *tp2;
	tp2 = fopen(argv[3],"r");
	FILE *xl;
	xl = fopen(argv[1],"r");
	FILE *outfile;
	outfile = fopen("cout.tsv","w");
	//FILE *bupaixu;
	//bupaixu = fopen("cbub.txt","w");	
	char a[11];
	char b[61];
	char list1[18][11];
	char list2[49][11];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(list1,0,sizeof(list1));
	memset(list2,0,sizeof(list2));
	int *score = (int*)malloc(sizeof(int)*(dnalength + 1));
	int *place = (int*)malloc(sizeof(int)*(dnalength + 1));
	int *conti = (int*)malloc(sizeof(int)*(dnalength + 1));
	int *contii = (int*)malloc(sizeof(int)*(dnalength + 1));
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
	for(int i = 0;i < dnalength;i++){
		score[i] = 0;
		score[i] = (a1[i]*48-a2[i]*17)*(a1[i]*48-a2[i]*17)+(t1[i]*48-t2[i]*17)*(t1[i]*48-t2[i]*17)+(c1[i]*48-c2[i]*17)*(c1[i]*48-c2[i]*17)+(g1[i]*48-g2[i]*17)*(g1[i]*48-g2[i]*17)+(q1[i]*48-q2[i]*17)*(q1[i]*48-q2[i]*17);
		place[i] = i+1;
			}
	//for(int i=0;i<dnalength;i++){
	//	fprintf(bupaixu,"%d\t%d\n",place[i],score[i]);
	//}
	
	heapsort(score,place,dnalength);
	
	conti[dnalength] = 1;
	contii[dnalength] = 1;
	fprintf(outfile,"place\tscore\tContinuous variation base\tbase in type1\tbase in type2\n");
	for(int i=dnalength-1;i>=0;i--){
		conti[i] = 1;
		contii[i] = 1;
		if(place[i]-place[i+1] == 1) conti[i] = conti[i+1]+1;
		if(place[i]-place[i+1] <= 3) contii[i] = contii[i+1]+1;
		fprintf(outfile,"%d\t%d\t%d\t%c\t%c\n",place[i],score[i],conti[i],bs[place[i]],bs2[place[i]]);
	}
	fclose(outfile);
	return 0;
}
