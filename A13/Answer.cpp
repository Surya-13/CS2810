//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 21-04-2020         **
// SUBMISSION DEADLINE: 22-04-2020   **
//*************************************

#include<bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);                                           // Fast Input-Output.
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='H'){
                vec.push_back(make_pair(i,j));                                  // Store the indices of the hospitals in the city.
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){                                                   // For every position i,j find the minimum distance from all   
            int min = 1000000;                                                  // the cities.
            for(auto x:vec){
                int dst = abs(i-x.first) + abs(j-x.second);
                if(min>dst){
                    min=dst;
                }
            }
            cout<<min<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
