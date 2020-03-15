//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 11-02-2020         **
// SUBMISSION DEADLINE: 12-02-2020   **
//*************************************

#include<bits/stdc++.h>
#define ll long long int
using namespace std;


class Polynomial{
    private:
                                                      // Make a private array storing the coefficients of the polynomial
    ll coeff[1001]={0};                             // corresponding to the power of x.
                                                      // Using 1001 as a higher value of the length of the array
    public:
    Polynomial operator + (Polynomial b){
        Polynomial& a = *this;
        for(int ii=0;ii<=1000;ii++){                    // Using operator overloading to define + as addition of 2 polynomials
            a.get()[ii] += b.get()[ii];
        }
        return a;
    }
    Polynomial operator - (Polynomial b){
        Polynomial& a = *this;
        for(int ii=0;ii<=1000;ii++){                    // Using operator overloading to define - as subtraction of 2 polynomials
            a.get()[ii] -= b.get()[ii];
        }
        return a;
    }
    Polynomial operator * (Polynomial b){
        Polynomial& a = *this;
        ll final_array[2002]={0};
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=1000;j++){                 // Using operator overloading to define * as multiplication of 2 polynomials
                final_array[i+j] += a.get()[i]*b.get()[j];
            }
        }
        for(int i=0;i<=1000;i++){
            coeff[i]=final_array[i];               // Changing the array of the *this object.
        }
        return a;
    }
    ll* get();                                  // To get the coefficients array
    void print();                                   // To print the polynomial according to the question.

};
template<class t>                               // Creating a templated Stack
class Stack{
    private:
        vector<t>vec;                           // Implemented using a vector of type t.
        ll size;                                // Store the size of the stack.
    public:
        Stack(){size=0;}
        ~Stack(){}
        void push(t val);
        t pop();
        t top();
        ll get_size(){return size;}
};

template<class t>
void Stack<t>::push(t val){
    size++;
    vec.push_back(val);
}

template<class t>
t Stack<t>::pop(){
    t x = vec.back();
    vec.pop_back();
    size--;
    return x;
}    

template<class t>
t Stack<t>::top(){
    return vec.back();
}   

bool is_operator(string line){
    return line=="(" || line==")" || line=="+" || line=="-" || line=="*";
}
int prec(string c){
    if(c=="*"){
        return 1;
    }                                                // Operator Precedence:- * > +/- .
    else if(c=="+" || c=="-"){                          
        return 0;
    }
    return -1;
}
ll* Polynomial::get(){
    return this->coeff;                             // To get the coefficients array
}
void Polynomial::print(){
    Polynomial a = *this;
    int count=0;
    for(int i=0;i<=1000;i++){
        if(coeff[i]==0){
            continue;
        }
        else if(coeff[i]<0){
            if(count==0){
                cout<<coeff[i]<<"x^"<<i;                    // Printing the polynomail according to the question.
                count+=1;
            }
            else{
                cout<<" - "<<-1*coeff[i]<<"x^"<<i;
            }
        }
        else if(coeff[i]>0){
            if(count==0){
                cout<<coeff[i]<<"x^"<<i;
                count+=1;
            }
            else{
                cout<<" + "<<coeff[i]<<"x^"<<i;
            }
        }
    }
    cout<<endl;
}



void takeIntInput() {

    std::string line, token;
    std::cin.ignore();
    std::getline(std::cin, line);
    std::stringstream ss(line);
    vector<ll> vll;                              // To store the elements i.e, integers in this case.
    ll count=0;
    Stack<string> stc;                           // Temporary stack for operators.
    vector<string> fin;                          // Vector to store the postfix expression with indices in place of the elements.
    while(ss >> token) {
        if(!is_operator(token)){
            vll.push_back(stoll(token));
            fin.push_back(std::to_string(count));
            count++;
        }
        else{
            if(token=="*" || token=="+" || token=="-"){
                while( stc.get_size()!=0 && prec(token)<=prec(stc.top())){   // Take into account the operator precedence.
                    string x = stc.top();
                    stc.pop();
                    fin.push_back(x);
                }
            }
            stc.push(token);
            if( stc.get_size()!=0 && stc.top()==")"){
                stc.pop();
                while( stc.get_size()!=0 && stc.top()!="("){            // Creating Postfix 
                    fin.push_back(stc.top());
                    stc.pop();
                }
                stc.pop();
            }
        }
    }
    while(stc.get_size()!=0){
        fin.push_back(stc.top());
        stc.pop();
    }
    Stack<ll> stl;                                      // To evaluate Postfix.
    int x = fin.size();
    for(int i=0;i<x;i++){
        if(fin[i]=="+"){
            ll x1 = stl.pop();
            ll x2 = stl.pop();
            stl.push(x1 + x2);
        }
        else if(fin[i]=="-"){
            ll x1 = stl.pop();
            ll x2 = stl.pop();
            stl.push(x2 - x1);
        }
        else if(fin[i]=="*"){
            ll x1 = stl.pop();
            ll x2 = stl.pop();
            stl.push(x1 * x2);
        }
        else{
            stl.push(vll[stoll(fin[i])]);
        }
    }
    cout<<stl.top()<<endl;
}

void takePolyInput() {
    int num;
    std::cin >> num;
    std::string line;
    std::cin.ignore();
    vector<Polynomial> vll;                                   // To store objects of type Polynomial.
    ll count=0;
    Stack<string> stc;                                        // Temporary stack for the operations.
    vector<string> fin;                                       // To store the postfix expression.
    for(int i = 0; i < num; i++) {
        std::getline(std::cin, line);
        if(line.size() == 1) {
            string token = line;
            if(token=="*" || token=="+" || token=="-"){
                while( stc.get_size()>=1 && prec(token)<=prec(stc.top())){
                    string x = stc.top();
                    stc.pop();
                    fin.push_back(x);
                }
            }
            stc.push(token);
            if( stc.get_size()!=0 && stc.top()==")"){
                stc.pop();
                while( stc.get_size()!=0 && stc.top()!="("){
                    fin.push_back(stc.top());
                    stc.pop();
                }
                stc.pop();
            } 
        }
        else {
            std::stringstream ss(line);
            int exponent;
            long long coeff;
            Polynomial p;
            while(ss >> exponent, ss >> coeff) {
                p.get()[exponent]+=coeff;
            }
            vll.push_back(p);
            fin.push_back(std::to_string(count));
            count++;

        }
    }
    while(stc.get_size()!=0){
        fin.push_back(stc.top());
        stc.pop();
    }
    Stack<Polynomial> stl;
    int x = fin.size();
    for(int i=0;i<x;i++){
        if(fin[i]=="+"){
            Polynomial x1 = stl.pop();
            Polynomial x2 = stl.pop();
            stl.push(x1 + x2);
        }
        else if(fin[i]=="-"){
            Polynomial x1 = stl.pop();
            Polynomial x2 = stl.pop();
            stl.push(x2 - x1);
        }
        else if(fin[i]=="*"){
            Polynomial x1 = stl.pop();
            Polynomial x2 = stl.pop();
            stl.push(x1 * x2);
        }
        else{
            stl.push(vll[stoll(fin[i])]);
        }
    }
    stl.top().print();
}


int main(){
    int n;
    cin>>n;
    string s;
    while(n){
        n--;
        cin>>s;
        if(s=="int"){
            takeIntInput();
        }
        if(s=="poly"){
            takePolyInput();
        }
    }
 return 0;   
}
