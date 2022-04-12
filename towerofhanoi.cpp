#include<iostream>
using namespace std;
void towerofhanoi(int n,char source,char helper,char destination){
	if(n==0){
		return;
	}
	towerofhanoi(n-1,source,destination,helper);
	cout<<"take the "<<n<<" disk from "<<source<<" to "<<destination<<endl;
	towerofhanoi(n-1,helper,source,destination);
}
int main(){
	int n=3;
	char a='A',b='B',c='C';
	towerofhanoi(n,a,b,c);
	return 0;
}