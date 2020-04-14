//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 14-04-2020         **
// SUBMISSION DEADLINE: 15-04-2020   **
//*************************************

// Here i am using KMP algorithm to find the number of occourences of a string inside another string.
// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

ll search(string x,string y,int* lps){
    ll sum=0;                                           // To store the number of occourences.
    int ii=0;
    int jj=0;
    int n=x.length();
    int m=y.length();
    while(ii < n){
        if(y[jj] == x[ii]){
            ii++;
            jj++;
        }
        if(jj == m){
            sum++;
            jj = lps[jj-1];
        }
        else if(ii < n && y[jj] != x[ii]){
            if(jj != 0){
                jj = lps[jj - 1];
            } 
            else{
                ii++;   
            } 
        } 
    }
    return sum;
}

void get_lps(int m,string y,int* lps){
    int ii=0;
    lps[0]=0;
    for(int i = 1;i < m;){
        if(y[i] == y[ii]){
            lps[i] = ii+1;
            i++;ii++;
        }
        else{
            if(ii != 0){
                ii = lps[ii-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t){
        t--;
        string x,y;
        cin>>x>>y;
        int k,q;
        cin>>k>>q;
        int lps[y.length()];
        get_lps(y.length(),y,lps);
        ll ans = search(x,y,lps);
        if(ans >= k){
            cout<<"YES\n"<<ans<<endl;
        }
        else{
            cout<<"NO\n"<<ans<<endl;
        }
        ll change[100001]={0};
        for(int i=0;i<q;i++){
            int l,r,s;
            cin>>l>>r>>s;
            change[l-1]+=s;                              // In the change array, add s to the lth index, subtract s from the (r+1)th
            change[r]-=s;                                // index, for all the input l,r,s.                 
        }
        ll temp=0;
        for(int i=0;i<x.length();i++){
            temp+=change[i];                             // Now, the cummulative sum till the i'th index( including i ) will be the final 
            change[i]=temp;                              // change needed in the ith character of the string.
        }
        for(int i=0;i<x.length();i++){
            x[i]=char(65+(int(x[i])-65+change[i])%26);  // Get the final character.
            cout<<x[i];
        }
        cout<<endl;
        get_lps(y.length(),y,lps);
        ans = search(x,y,lps);
        if(ans >= k){
            cout<<"YES\n"<<ans<<endl;
        }
        else{
            cout<<"NO\n"<<ans<<endl;
        }
    }
    return 0;
}
