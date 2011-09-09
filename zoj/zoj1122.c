include <stdio.h>
int main()
{
    int Starthour,Startminute,Finalhour,Finalminute,Sminute,Fminute;
	int pass_times;
	printf("Program 3 by team X\n");
	printf("Initial time  Final time  Passes\n");
	while (scanf("%d%d%d%d",&Starthour,&Startminute,&Finalhour,&Finalminute)!=EOF){
		 Sminute=(Starthour)*60+Startminute;
		 Fminute=(Finalhour)*60+Finalminute;
		 int a=(Fminute*11)/720;
		 int b=(Sminute*11)/720;
		 pass_times=a-b;
		 //pass_times=(Fminute*11)/720-(Sminute*11)/720
		 if (Sminute>Fminute)
			 pass_times=pass_times+11;
		 printf("       %02d:%02d",Starthour,Startminute);
		 if (pass_times>9)
			 printf("       %02d:%02d      %d\n",Finalhour,Finalminute,pass_times);
		 else
		 printf("       %02d:%02d       %d\n",Finalhour,Finalminute,pass_times);
	}
	printf("End of program 3 by team X\n");
	return 0;
}
