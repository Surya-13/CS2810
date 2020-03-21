//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 20-03-2020         **
// SUBMISSION DEADLINE: 20-03-2020   **
//*************************************

#include<bits/stdc++.h>
using namespace std;

// Edge stores the vectices it is incident with and the type of that road.
class edge{
  private:
    int city1;
    int city2;
    int type;
  public:
    edge(int c1,int c2,int t){
        this->city1 = c1;
        this->city2 = c2;
        this->type = t;
    }
    int get_city1(){return this->city1;}
    int get_city2(){return this->city2;}
    int get_type(){return this->type;}
};

int sum = 0;                                                                // Sum stores the final Sum.
int ii = 0;                                                                 // ii keeps count of the number of connected components.
int jj = 0;                                                                 // jj is a temp variable to store the value of ii.
vector <vector <int> > vec(100000);                                          // Contains the vertices of connected components.
vector <vector <int> > temp_vec(100000);                                     // Another temp variable to store vec.
void get_components(vector<edge>temp,int* components){
    for(int i=0;i<temp.size();i++){
        int x = temp[i].get_city1();
        int y = temp[i].get_city2();
        if(components[x]==-1){                                              
            if(components[y]==-1){                                          // If both are -1, then x, y are both not present in any
                vec[ii].push_back(x);                                       // component, so create a new one and update the 
                vec[ii].push_back(y);                                       // corresponding variables.
                components[x]=ii;
                components[y]=ii;
                ii++;
            }
            else{                                                           // Add x into the component in which y is present.
                components[x]=components[y];
                vec[components[y]].push_back(x);
            }
        }
        else if(components[y]==-1){                                         // Add y in the component which contains x.
            components[y]=components[x];
            vec[components[x]].push_back(y);
        }
        else{
            if(components[x]==components[y]){                               // If both are already in the same component, then 
                sum++;                                                      // increment sum, and dont add this edge, since this 
                continue;                                                   // is already present.
            }
            else{
                if(vec[components[x]].size()<=vec[components[y]].size()){   // Merge Components.
                    int temp=components[x];                                 // Add the smaller of the components into the larger one.
                    for(auto j :vec[components[x]]){
                        components[j]=components[y];
                        vec[components[y]].push_back(j);
                    }
                    vec[temp].clear();                                      // Clear the smaller component.
                }
                else{
                    int temp=components[y];                                 // Add the smaller of the components into the larger one.
                    for(auto j:vec[components[y]]){
                        components[j]=components[x];
                        vec[components[x]].push_back(j);
    
                    }
                    vec[temp].clear();                                      // Clear the smaller component.
                }
            }
        }
    }
}
int check(int n){                                                           // Check if any component has all the vertices
    for(int i=0;i<n;i++){                                                   // which means all are connected.
        if(vec[i].size()==n){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,m;
    cin>>n>>m;  
    vector<edge>pass,cargo,both;                                            // Store the passenger, cargo, either roads seperately.
    int components[100000];
    int temp[100000];
    while(m){
        m--;
        int c1,c2,t;
        cin>>c1>>c2>>t;
        edge e(c1,c2,t);
        if(t==0){
            pass.push_back(e);
        }
        if(t==1){
            cargo.push_back(e);
        }
        if(t==2){
            both.push_back(e);
        }
    }
    memset(components,-1,100000);                                    // Initialize components to -1 i.e, all are in different components. 
    get_components(both,components);                                 // Add roads of type 2.      
    copy(components,components+n,temp);                              // Store the values of vec,ii,components in temp variables.
    copy(vec.begin(),vec.end(),temp_vec.begin());
    jj=ii;
    get_components(pass,components);                                 // Add roads of type 0.
    if(check(n)==0){                                                 // Check if all vertices are connected, if not then print -1, return.
        cout<<-1<<endl;
        return 0;
    }
    copy(temp,temp+n,components);
    copy(temp_vec.begin(),temp_vec.end(),vec.begin());               // Use the previous values stored in temporary variables.
    ii=jj;
    get_components(cargo,components);                                // Add roads of type 1.
    if(check(n)==0){                                                 // Check if all vertices are connected, if not then print -1, return.
        cout<<-1<<endl;
        return 0;
    }
    cout<<sum<<endl;                                                // Print sum.
    return 0;
}
