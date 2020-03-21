//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 25-02-2020         **
// SUBMISSION DEADLINE: 26-02-2020   **
//*************************************

// https://www.geeksforgeeks.org/ordered-set-gnu-i-pbds/
// I am using the data structure ordered-set which does all operations on O(logn) also keeping track of the rank of each element.

#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<student, null_type,sort_student, rb_tree_tag,tree_order_statistics_node_update> // Set of Students.
#define order_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>          // Set of integers(skill values).

order_set sk;                   // Set of skill values.
class student{
  private:
    int id;
    int m1,m2,m3,m4,m5;
    int skill;
  public:
    student(){
        int id,m1,m2,m3,m4,m5,skill;
        cin>>id>>m1>>m2>>m3>>m4>>m5>>skill;
        this->id = id;sk.insert(skill);                                             // Store the skill in the ordered set.                   
        this->m1 = m1; this->m2 = m2; this->m3 = m3; this->m4 = m4;
        this->m5 = m5; this->skill = skill;
    }
    int get_m1()const{return this->m1;}
    int get_m2()const{return this->m2;}
    int get_m3()const{return this->m3;}
    int get_m4()const{return this->m4;}
    int get_m5()const{return this->m5;}
    int get_id()const{return this->id;}
    int get_skill()const{return this->skill;}
};
// Comparator made as a functor to help make comparisions between elements of type students. Specific to this question.
class sort_student{                                                                    
    public:
    bool operator() (const student& x,const student& y) const {
        if(x.get_m1()!=y.get_m1()){return x.get_m1()>y.get_m1();}
        else{
            if(x.get_m2()!=y.get_m2()){return x.get_m2()>y.get_m2();}
            else{
                if(x.get_m3()!=y.get_m3()){return x.get_m3()>y.get_m3();}
                else{
                    if(x.get_m4()!=y.get_m4()){return x.get_m4()>y.get_m4();}
                    else{
                        if(x.get_m5()!=y.get_m5()){return x.get_m5()>y.get_m5();}
                    }
                }
            }
        }
        return false;
  }
};
int main(){
    string line;
    cin>>line;                      // First take input even if NULL.
    ordered_set setofstud;          // Set of students.
    // Storing the students in a map with ID being the student ID, To access the student with a specific ID in O(1).
    map<int,student> mp;            
    while(!cin.eof()){
        if(line == "ADD"){
            student s;
            mp.insert(pair<int,student>(s.get_id(),s));
            setofstud.insert(s);
        }
        else if(line == "FIND"){
            int x,y,j=0;
            cin>>x>>y;
            // Use the order_of_key inbuilt function to get rank of an element.
            j = setofstud.order_of_key(mp[x]) - setofstud.order_of_key(mp[y]);   
            cout<<abs(j)<<endl;
        }
        else if(line == "COUNT"){
            int id,count,diff;
            cin>>id>>diff;
            count = 0;
            int skill;
            // Find returns iterator to the element passed in the set.
            skill = setofstud.find(mp[id])->get_skill();
            // Skill value diff > d => all elements - the ones with skill value diff < d
            // Which is {all studentsd - ( students with skill < skill_of_that_student + d - students with skill > skill_of_that_student - d)}
            count = mp.size() - sk.order_of_key(skill+diff) + sk.order_of_key(skill-diff);
            cout<<count<<endl;
        }
        else if(line == "PRINT"){
            for(auto x: setofstud){
                cout<<x.get_id()<<" ";
            }
            cout<<endl;
        }
        cin>>line;
    }
    return 0;
}
