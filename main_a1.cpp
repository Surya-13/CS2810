#include<bits/stdc++.h>
#include"BTech.h"
#include"DD.h"	
using namespace std;
bool sortbycgpa(Btech b1,Btech b2){
	return b1.cgpa>b2.cgpa;
}
int main(){
	int n,m,h;
	cin>>n>>m>>h;
	int nbt,ndd;
	srand(time(0));
	nbt = rand()%n;
	ndd = n - nbt;
	vector<Faculty>f;
	vector<Btech>b;
	vector<DD>d;
	vector<guides>g;
	for(int i=1;i<=m;i++){
		string s = "Prof_A";// + to_string(i);
		bool x = (rand()%2)==0;\
		if(x){
			g.push_back(i-1);
		}
		Faculty f1(s,x);
		f.push_back(f1);
	}
	/*for(int i=0;i<f.size();i++){
		cout<<f[i].what;
	}*/
	for(int i=0;i<nbt;i++){
		//b.push_back(Btech(i+1,to_string(rand()%h+1),f[rand()%m],((float)(rand()%1000))/100));
		b.push_back(Btech(i+1,"aas",f[rand()%m],((1.0)*(rand()%1000))/100));
	}
	for(int i=0;i<ndd;i++){
		//d.push_back(DD(i+1,to_string(rand()%h+1),f[rand()%m],((float)(rand()%1000))/100));
		d.push_back(DD(i+1,"aaf",f[rand()%m],((1.0)*(rand()%1000))/100));
	}
	sort(b.begin(),b.end(),sortbycgpa);
	for(int i=0;i<g.size();i++){
		b[2*i].btpguide = Faculty[g[i]];
		b[2*i +1].bptguide = Faculty[g[i]];
	}
	for(int i=0;i<b.size();i++){
		cout<<b[i].cgpa<<" ";
	}
	return 0;
}