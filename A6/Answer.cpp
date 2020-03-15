//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 17-02-2020         **
// SUBMISSION DEADLINE: 19-02-2020   **
//*************************************

#include<bits/stdc++.h>
using namespace std;
class student{
  private:
    string name;
    int rollno;
    int p_marks,c_marks,m_marks;
    double avg_score;
  public:
    student(string name, int rollno, int p_marks, int c_marks, int m_marks){
        this->name = name;
        this->rollno = rollno;
        this->p_marks = p_marks;
        this->c_marks = c_marks;
        this->m_marks = m_marks;
        avg_score = 1.0*(p_marks + c_marks + m_marks)/3;                // Find Avg.
    }
    double get_avgscore(){return avg_score;}
    int get_rollno(){return rollno;}
    string get_name(){return name;}
    void print(){
        cout<<name<<" "<<rollno<<" "<<p_marks<<" "<<c_marks<<" "<<m_marks<<endl;                            // 1st print function.
    }
    void printf(){
        cout<<name<<" "<<rollno<<" "<<p_marks<<" "<<c_marks<<" "<<m_marks<<" "<<avg_score<<endl;            // 2nd print function.
    }
};
class classroom{
  public:
    vector<student*>stdvec;                                     // Store pointers to all the students.
};

class operation1{
  private:
    int rollno;
  public:                                                       // Functor defined to check if roll number of the student matched with that
    operation1(int rollno){this->rollno=rollno;}                // of the input.
    bool operator()(student* s){
        if(s->get_rollno()==rollno){
            s->print();
            return true;
        }
        return false;
    }
};

class operation2{
  private:
    string name;
  public:                                                       // Functor defined to check if name of the student matched with that of the
    operation2(string name){this->name = name;}                 // input, and then print that student info.
    bool operator()(student* s){
        if(s->get_name()==name){
            s->print();
            return true;
        }
        return false;
    }
};

class operation3{
  public:
    void operator()(student* s){                                // Functor to just print the student being passed.
        s->printf();
    }
};

class operation4{
  private:
    string name;
  public:
    operation4(string name){this->name = name;}                 // Functor defined to check if name of the student matched with that of the
    bool operator()(student* s){                                // input.
        if(s->get_name()==name){
            return true;
        }
        return false;
    }
};


bool check1(student* s1,student* s2){
    return s1->get_rollno()<s2->get_rollno();                   // Custom comparator.
}

bool check2(student* s1,student* s2){
    if(s1->get_avgscore()>s2->get_avgscore()){
        return true;
    }                                                           // Custom comparator.
    else if(s1->get_avgscore()==s2->get_avgscore()){
        return s1->get_rollno()<s2->get_rollno();
    }
    return false;
}

int main() {
    cout.precision(4);
    cout<<fixed;
    int n;
    cin>>n;
    classroom c;
    while(n){
        n--;
        string name;
        int rollno, p_marks, c_marks, m_marks;
        cin>>name>>rollno>>p_marks>>c_marks>>m_marks;
        student* stud = new student(name, rollno, p_marks, c_marks, m_marks);
        c.stdvec.push_back(stud);
    }
    int x;
    cin>>x;
    switch(x){
        case 1:{
            int y;
            cin>>y;
            vector<student*>::iterator it=find_if(c.stdvec.begin(),c.stdvec.end(),operation1(y)); 
            if(it==c.stdvec.end()){
                cout<<"Invalid Entry"<<endl;
            }
        }
            break;
        case 2:{
            string y;
            cin>>y;
            sort(c.stdvec.begin(),c.stdvec.end(),check1);
            vector<student*>::iterator it=find_if(c.stdvec.begin(),c.stdvec.end(),operation4(y)); 
            if(it==c.stdvec.end()){
                cout<<"Invalid Entry"<<endl;
            }
            else{
                for_each(c.stdvec.begin(),c.stdvec.end(),operation2(y));
            }
            break;
        }
        case 3:
            sort(c.stdvec.begin(),c.stdvec.end(),check2);
            for_each(c.stdvec.begin(),c.stdvec.end(),operation3());
            break;
    }
    return 0;
}
