//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 10-03-2020         **
// SUBMISSION DEADLINE: 11-03-2020   **
//*************************************

#include<bits/stdc++.h>
using namespace std;

int mat[501][501];                                      // To store the bipartite graph in adjacency matrix form.
int num1;                                               // Rows represent Males, Columns Females.
int num2;                                               // num1 = No of males, num2 = No of females.
int arr[501];                                           // To store the females which should not be partnered with that male.
bool b[501];                                            // Visited bool array.
class coord{
  private:
    int age;
    char gender;
    int cgpa;
    string lang;
  public:
    coord(){
        int x1,x4;
        char x2;string x3;
        cin>>x1>>x2>>x3>>x4;
        this->age=x1;this->lang=x3;
        this->gender=x2;this->cgpa=x4;
    }
    int get_age(){return this->age;}
    int get_cgpa(){return this->cgpa;}
    char get_gender(){return this->gender;}
    string get_lang(){return this->lang;}
};
vector<coord*>vec1,vec2;                                // Vec1 stores Males, Vec2 the Females.
bool yes(coord c1,coord c2){                            // Function returns true if the c1, c2 should not clubbed together.
    if(abs(c1.get_age()-c2.get_age())>=3 || c1.get_lang()!=c2.get_lang() || c1.get_cgpa()==c2.get_cgpa()){
        return false;
    }
    return true;
}
bool func(int u){                                        // Returns True if the male u is matched to some female in the matching. 
    for (int v=0;v<num2;v++){                            // Go through the females.
        if (mat[u][v] && !b[v]){                         // If male and female are not compatible and that female isnt 
            b[v] = true;                                 // already matched with another male, then mark as visited.
            if (arr[v] < 0 || func(arr[v])){             // Check if the male who was already matched with this female can
                arr[v] = u;                              // find another female to be matched.
                return true; 
            } 
        } 
    } 
    return false; 
}
int get_ans(){
    // -1 implies initially no male and female are matched 
    // in the matching.
    for(int i=0;i<num2;i++){
        arr[i]=-1;
    }
    int sum=0;                                           // To store the length of the maximal matching.
    for(int i=0;i<num1;i++){
        for(int j=0;j<num2;j++){
            b[j]=0;                                      // Initialize visited to false;
        }
        if(func(i)){                                     // if male i is matched with a female, then increase sum.
            sum++;
        }
    }
    return sum;
}
void get_matrix(){
    for(int i=0;i<num1;i++){
        for(int j=0;j<num2;j++){
            if(yes(*vec1[i],*vec2[j])){
                mat[i][j]=1;                                // 1 if they are not compatible.
            }
            else{
                mat[i][j]=0;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t){
        t--;vec1.clear();vec2.clear();
        int n;
        cin>>n;
        while(n){
            n--;
            coord* c = new coord();
            if(c->get_gender()=='M'){
                vec1.push_back(c);                           // Store Males in vec1.
            }       
            else{
                vec2.push_back(c);                           // Store Females in vec2.
            }
        }
        num1=vec1.size();num2=vec2.size();
        get_matrix();                                        // Create the matrix.
        
        // Let the number of edges in the maximal matching be x, 
        // that means for every edge out of those x edges, we 
        // should only consider one of the nodes, i.e, 
        // either the male or the female which have an edge between them
        // in the maximal matching. So the required answer would be 
        // Total number of coordinators - x.
        cout<<num1+num2-get_ans()<<"\n";                     
    }    
    return 0;
}
