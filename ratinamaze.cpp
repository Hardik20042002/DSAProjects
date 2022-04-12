#include<iostream>
using namespace std;
int sol[10][10]={0};
bool ratinamaze(char maze[][5],int i,int j,int n,int m){
	if(i==n-1&&j==m-1){
		for(int i=0;i<n;i++){
			for(j=0;j<m;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		//return false;(to print all possible paths)
		return true;//(return 1st possible ans)
	}
	sol[i][j]=1;
	if(j+1<m&&maze[i][j+1]!='X'){
		bool rightpath=ratinamaze(maze,i,j+1,n,m);
		if(rightpath==true){
			return true;
		}
	}
	if(i+1<n&&maze[i+1][j]!='X'){
		bool downpath=ratinamaze(maze,i+1,j,n,m);
		if(downpath==true){
			return true;
		}
	}
	sol[i][j]=0;
	return false;
}
int main(){
	char maze[][5]={"0000","00XX","0000","XX00"};
	int n=4,m=4;
	ratinamaze(maze,0,0,n,m);
}