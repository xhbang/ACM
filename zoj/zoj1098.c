#include <stdio.h>
#include <memory.h>

enum INS{STA,LDA,BEQ,NOP,DEC,INC,JMP,HLT};
unsigned char memory[33];
unsigned char pc;
unsigned char ac;

void run(){
	int i;
	while(1){
		switch(memory[pc]>>5){
			case STA:
				memory[memory[pc]&0x1f]=ac;
				pc=++pc&0x1f;
				break;
			case LDA:
				ac=memory[memory[pc]&0x1f];
				pc=++pc&0x1f;
				break;
			case BEQ:
				if(ac==0)
					pc=memory[pc]&0x1f;
				else
					pc=++pc&0x1f;
				break;	
			case NOP:
				pc=++pc&0x1f;
				break;
			case DEC:
				ac--;
				pc=++pc&0x1f;
				break;
			case INC:
				ac++;
				pc=++pc&0x1f;
				break;
			case JMP:
				pc=memory[pc]&0x1f;
				break;
			case HLT:
				for(i=7;i>=0;i--)
					//i++!!
					printf("%d",(ac>>i)&1);
				printf("\n");
				return;
		}
	}	
}

void test(){
	int i,j;
	for(i=0;i<=31;i++){
		if(memory[i]>>5==HLT)
			break;
		printf("%d %d\n",memory[i]>>5,i);
	}
}
int main(){
	int i,j;
	char t[32][9];
	while(scanf("%s",t[0])!=EOF){
		for(i=1;i<32;i++)
			scanf("%s",t[i]);
		/*
		for(i=0;i<32;i++)
			printf("read in %s\n",t[i]);
			*/
		memset(memory,0,sizeof(memory));
//		printf("1 stop\n");
	   	for(i=0;i<32;i++){
			for(j=0;j<8;j++){
			memory[i]=(memory[i]<<1)|(t[i][j]-'0');
			//printf("%d stop\n",j);
			//printf("%c ,ok ",t[i][j]);
			}
			//printf("%d\n",memory[i]);
			//printf("%d\n",i);
		}
		pc=0x0;
		ac=0x0;
		run();
		//test();
	}
	return 0;
}
