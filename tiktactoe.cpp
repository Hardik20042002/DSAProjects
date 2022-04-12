#include<iostream>
#include<cstring>
using namespace std;
int i=0;
int m=0;
pair<bool,char> wincheck(char matrix[3][4]){
	pair<bool,char>p;
	for(int i=0;i<3;i++){
		if(matrix[i][0]==matrix[i][1]&&matrix[i][1]==matrix[i][2]&&matrix[i][0]!='_'){
			p.first=true;
			p.second=matrix[i][0];
			return p;
		}
	}
	for(int i=0;i<3;i++){
		if(matrix[0][i]==matrix[1][i]&&matrix[1][i]==matrix[2][i]&&matrix[0][i]!='_'){
			p.first=true;
			p.second=matrix[0][i];
			return p;
		}
	}
	if(matrix[0][0]==matrix[1][1]&&matrix[1][1]==matrix[2][2]&&matrix[0][0]!='_'){
			p.first=true;
			p.second=matrix[0][0];
			return p;
	}
	if(matrix[0][2]==matrix[1][1]&&matrix[1][1]==matrix[2][0]&&matrix[2][0]!='_'){
			p.first=true;
			p.second=matrix[2][0];
			return p;
	}
	p.first=false;
	p.second='_';
	return p;
}
void insertinmatrix(int x,int y,char *symbols,char matrix[3][4]){
	if(i%2==0){
		matrix[x-1][y-1]=symbols[0];
	}
	else{
		matrix[x-1][y-1]=symbols[1];
	}
	i++;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	string a,b,s1,s2;
	cout<<"enter name of first player:"<<endl;
	cin>>a;
	cout<<"enter name of second player:"<<endl;
	cin>>b;
	int l,m;
	if(l>m){
		s1=a,s2=b;
	}
	else{
		s1=b,s2=a;
	}
	char symbols[2]={'O','x'};
	char matrix[3][4];
	memset(matrix,'_',sizeof(matrix));
	for(int i=0;i<3;i++){
		matrix[i][3]='\0';
	}
	cout<<s1<<" is assigned "<<symbols[0]<<" and first chance"<<endl;
	cout<<s2<<" is assigned "<<symbols[1]<<endl;
	int j=0;
	while(j!=9){
		int x,y;
		if(i%2==0){
		cout<<"enter the row number where "<<symbols[0]<<" is to be inserted: ";
		cin>>x;
		cout<<"enter the coloumn number where "<<symbols[0]<<" is to be inserted: ";
		cin>>y;
		}
		else{
		cout<<"enter the row number where "<<symbols[1]<<" is to be inserted: ";
		cin>>x;
		cout<<"enter the coloumn number where "<<symbols[1]<<" is to be inserted: ";
		cin>>y;
		}
		if(matrix[x-1][y-1]=='_'){
		insertinmatrix(x,y,symbols,matrix);
		}
		else{
		while(matrix[x-1][y-1]!='_'){
		if(i%2==0){
		cout<<"wrong position selected by "<<(m%2==0?s1:s2)<<" to insert "<<symbols[0]<<" so, try again"<<endl;
		cout<<"enter the row number where "<<symbols[0]<<" is to be inserted: ";
		cin>>x;
		cout<<"enter the coloumn number where "<<symbols[0]<<" is to be inserted: ";
		cin>>y;
		}
		else{
		cout<<"wrong position selected by "<<(m%2==0?s1:s2)<<" to insert "<<symbols[1]<<" so, try again"<<endl;
		cout<<"enter the row number where "<<symbols[1]<<" is to be inserted: ";
		cin>>x;
		cout<<"enter the coloumn number where "<<symbols[1]<<" is to be inserted: ";
		cin>>y;
		}
		}
		insertinmatrix(x,y,symbols,matrix);
		}
		pair<bool,char>ans=wincheck(matrix);
		if(ans.first==true){
			char ch=ans.second;
			if(m%2==0){
				cout<<s1<<" is the winner"<<endl;
				for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(ch=='x'){
					if(matrix[i][j]=='_'||matrix[i][j]=='O'){
						cout<<'_'<<" ";
					}
					else{
						cout<<'x'<<" ";
					}
				}
			else{
				if(matrix[i][j]=='_'||matrix[i][j]=='x'){
						cout<<'_'<<" ";
					}
					else{
						cout<<'O'<<" ";
					}
				}
			}
				cout<<endl;
			}
				break;
			}
			else{
				cout<<s2<<" is the winner"<<endl;
				for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					if(ch=='x'){
					if(matrix[i][j]=='_'||matrix[i][j]=='O'){
						cout<<'_'<<" ";
					}
					else{
						cout<<'x'<<" ";
					}
				}
			else{
				if(matrix[i][j]=='_'||matrix[i][j]=='x'){
						cout<<'_'<<" ";
					}
					else{
						cout<<'O'<<" ";
					}
				}
			}
			cout<<endl;
		}
			break;
		}
	}
		else{
			if(m==8){
				cout<<"game is tied"<<endl;
				break;
			}
		}
		m++;
		j++;
	}
	return 0;
}