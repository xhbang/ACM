#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
using namespace std;

int main(){
	map<string,string> dict;
	map<string,string>::iterator loc;
	string key,val;
	char en[11],mou[11];
	char line[25];
	while(1){
		gets(line);
		if(strlen(line)==0)
			break;
		sscanf(line,"%s%s",en,mou);
		key=mou;
		val=en;
		dict[key]=val;
	}
	while(cin>>line){
		loc=dict.find(line);
		if(loc!=dict.end())
			cout<<dict[line]<<endl;
		//use [] instead of ()
		else
			cout<<"eh"<<endl;
	}
	return 0;
}
