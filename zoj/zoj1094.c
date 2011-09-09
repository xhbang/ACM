#include <stdio.h>

int pos;
int error;
int rows[26];
int cols[26];
char line[50];

typedef struct{
	int val;
	int row;
	int col;
}Node;

Node fun(){
	Node t,t1,t2;
	if(line[pos]=='('){
		pos++;
		t1=fun();
		t2=fun();
		pos++;
		if(t1.col!=t2.row)
			error=1;
		t.val=t1.val+t2.val+t1.row*t1.col*t2.col;
		t.row=t1.row;
		t.col=t2.col;
	}else{
		t.val=0;
		t.row=rows[line[pos]-'A'];
		t.col=cols[line[pos]-'A'];
		pos++;
		//do not forget!!!!!!!
	}
	return t;
}

int main(){
	int i;
	int n;
	char name;	
	int row,col;
	Node t;
	scanf("%d\n",&n);
	for(i=0;i<n;i++){
		scanf("%c%d%d\n",&name,&row,&col);
		rows[name-'A']=row;
		cols[name-'A']=col;
	}
	while(gets(line)){
		pos=error=0;
		t=fun();
		if(error)
			printf("error\n");
		else
			printf("%d\n",t.val);
	}
	return 0;
}
