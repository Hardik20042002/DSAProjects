#include<iostream>
#include<cmath>
using namespace std;
bool safeplace(int board[][9],int i,int j,int n,int no){
	for(int k=0;k<n;k++){
		if(board[i][k]==no){
			return false;
		}
		if(board[k][j]==no){
			return false;
		}
	}
	int n1=pow(n,0.5);
	int si=(i/n1)*n1,sj=(j/n1)*n1;
	for(int k=si;k<si+n1;k++){
		for(int l=sj;l<sj+n1;l++){
			if(board[k][l]==no){
				return false;
			}
		}
	}
	return true;
}
bool sudokusolver(int board[9][9],int i,int j,int n){
	if(i==n){
		for(int i=0;i<n;i++){
			for(int i=0;i<n;i++){
				cout<<"|_";
			}
			cout<<"|"<<endl;
			for(j=0;j<n;j++){
				cout<<"|"<<cboard[i][j];
			}
			cout<<"|"<<endl;
		}
		return true;
	}
	if(j==n){
		return sudokusolver(board,i+1,0,n);
	}
	if(board[i][j]!=0){
		return sudokusolver(board,i,j+1,n);
	}
	for(int no=1;no<=n;no++){
		if(safeplace(board,i,j,n,no)){
			board[i][j]=no;
			bool restsolve=sudokusolver(board,i,j+1,n);
			if(restsolve){
				return true;
			}
			board[i][j]=0;/*0 means we have to fill them(by default)*/
		}
	}
	return false;
}
int main(){
	/*int board[][9]={{5,3,0,0,7,0,0,0,0},
					{6,0,0,1,9,5,0,0,0},
					{0,9,8,0,0,0,0,6,0},
					{8,0,0,0,6,0,0,0,3},
					{4,0,0,8,0,3,0,0,1},
					{7,0,0,0,2,0,0,0,6},
					{0,6,0,0,0,0,2,8,0},
					{0,0,0,4,1,9,0,0,5},
					{0,0,0,0,8,0,0,7,9}};*/
	int board[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>board[i][j];
		}
	}
	sudokusolver(board,0,0,9);
	for(int i=0;i<9;i++){
		cout<<"|_";
	}
	cout<<"|"<<endl;
	return 0;
}