#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
vector<string>v;
string key[10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void phonekeypad(char *in,int i,int j,char *out){
	if(in[i]=='\0'){
		out[j]='\0';
		v.push_back(out);
		return;
	}
	int index=in[i]-'0';
	for(int k=0;key[index][k]!='\0';k++){
		out[j]=key[index][k];
		phonekeypad(in,i+1,j+1,out);
	}
}
int main(){
	char in[100];
	cin.getline(in,100);
	char out[100];
	string s;
	cin>>s;
	phonekeypad(in,0,0,out);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<v.size();i++){
		if(v[i]==s){
			cout<<s<<" found"<<endl;
			break;
		}
		
	}
	return 0;
}
