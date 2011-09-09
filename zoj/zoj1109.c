#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100005

typedef struct Node{
	char mou[11],en[11];
}node;

int cmp(const void *a,const void *b){
	node * na=(node*) a;
	node * nb=(node*) b;
	return strcmp((*na).mou,(*nb).mou);
}

int main(){
	char word[11];
	node data[100050];
	char line[25];
	int n=0;
	while(gets(line)){
		if(strlen(line)==0){
			break;
		}
		sscanf(line,"%s%s",data[n].en,data[n].mou);
		n++;
	}
	qsort(data,n,sizeof(node),cmp);
	--n;
	while(gets(word)){
		int i=0,j=n,flag=0,m;
		while(i<=j){
			m=(i+j)/2;
			if(strcmp(data[m].mou,word)==0){
				flag=1;
				break;
			}
			if(strcmp(data[m].mou,word)>0){
				j=m-1;
				continue;
			}
			if(strcmp(data[m].mou,word)<0){
				i=m+1;
				continue;
			}
		}
		if(flag)
			printf("%s\n",data[m].en);
		else
			printf("eh\n");
	}
	return 0;
}
