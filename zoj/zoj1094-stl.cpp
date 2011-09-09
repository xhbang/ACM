#include <iostream>
#include <map>
#include <stack>
using namespace std;

struct node{
	int rows;
	int cols;
};

int main(){
	int i,n;
	string exp;
	node a,b;
	char name;
	map<char,node> matrix;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>name;
		cin>>matrix[name].rows>>matrix[name].cols;
	}
	while(cin>>exp){
		int count=0;
		int i;
		stack<node> array;
		for(i=0;i<exp.size();i++){
			if(exp[i]=='(')
				continue;
			if(exp[i]==')'){
				node b=array.top();
				array.pop();
				node a=array.top();
				array.pop();
				if(a.cols!=b.rows){
					//cout<<"a   "<<a.cols<<"b   "<<b.rows<<endl;
					cout<<"error"<<endl;
					break;	
				}
				count+=a.rows*a.cols*b.cols;
				node t={a.rows,b.cols};
				array.push(t);
			}else{
				array.push(matrix[exp[i]]);
			}
		}
		if(i==exp.size())
			cout<<count<<endl;
	}
	return 0;
}
