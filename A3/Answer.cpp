//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 27-01-2020         **
// SUBMISSION DEADLINE: 29-01-2020   **
//*************************************

#include<bits/stdc++.h>
using namespace std;

class Polynomial{
    private:
                                                      // Make a private array storing the coefficients of the polynomial
    double coeff[30]={0};                             // corresponding to the power of x.
                                                      // Using 30 as a higher value of the length of the array
    public:
    Polynomial operator + (Polynomial b){
        Polynomial& a = *this;
        for(int ii=0;ii<30;ii++){                    // Using operator overloading to define + as addition of 2 polynomials
            a.get()[ii] += b.get()[ii];
        }
        return a;
    }
    Polynomial operator - (Polynomial b){
        Polynomial& a = *this;
        for(int ii=0;ii<30;ii++){                    // Using operator overloading to define - as subtraction of 2 polynomials
            a.get()[ii] -= b.get()[ii];
        }
        return a;
    }
    Polynomial operator * (Polynomial b){
        Polynomial& a = *this;
        double final_array[30]={0};
        for(int i=0;i<15;i++){
            for(int j=0;j<15;j++){                 // Using operator overloading to define * as multiplication of 2 polynomials
                final_array[i+j] += a.get()[i]*b.get()[j];
            }
        }
        for(int i=0;i<30;i++){
            coeff[i]=final_array[i];               // Changing the array of the *this object.
        }
        return a;
    }
    double eval(double* d,double val);              // To evaluate the polynomial at x = val
    double* get();                                  // To get the coefficients array
    void print();                                   // To print the polynomial according to the question.

};
double* Polynomial::get(){
    return this->coeff;                             // To get the coefficients array
}
double Polynomial::eval(double* d,double val){
    double sum=0;
    for(int i=0;i<30;i++){
        sum+= d[i]*(pow(val,i));                    // To evaluate the polynomial at x = val   
    }           
    return sum;
}
void Polynomial::print(){
    Polynomial a = *this;
    int count=0;
    for(int i=0;i<30;i++){
        if(coeff[i]==0){
            continue;
        }
        else if(coeff[i]<0){
            if(count==0){
                cout<<coeff[i]<<"x^"<<i;                    // Printing the polynomail according to the question.
                count+=1;
            }
            else{
                cout<<" - "<<fabs(coeff[i])<<"x^"<<i;
            }
        }
        else if(coeff[i]>0){
            if(count==0){
                cout<<coeff[i]<<"x^"<<i;
                count+=1;
            }
            else{
                cout<<" + "<<fabs(coeff[i])<<"x^"<<i;
            }
        }
    }
    cout<<endl;
}
int main(){
    cout.precision(3);                         // Changes the precision value of cout accordingly
    cout<<fixed;                               // Fixes those changes for every instance of cout
    int n,m,t1;
    double t2;
    char x;
    cin>>n;
    while(n){
        n--;
        cin>>x;
        switch(x){
            case 'a':{
                cin>>m;
                Polynomial a;
                for(int i=0;i<m;i++){
                    cin>>t1>>t2;
                    a.get()[t1]+=t2;
                }
                cin>>m;
                Polynomial b;
                for(int i=0;i<m;i++){
                    cin>>t1>>t2;
                    b.get()[t1]+=t2;
                }
                a = a+b;
                a.print();
                break;
            }
            case 's':{
                cin>>m;
                Polynomial a;
                for(int i=0;i<m;i++){
                    cin>>t1>>t2;
                    a.get()[t1]+=t2;
                }
                cin>>m;
                Polynomial b;
                for(int i=0;i<m;i++){
                    cin>>t1>>t2;
                    b.get()[t1]+=t2;
                }
                a = a-b;
                a.print();
                break;
            }
            case 'm':{
                cin>>m;
                Polynomial a;
                for(int i=0;i<m;i++){
                    cin>>t1>>t2;
                    a.get()[t1]+=t2;
                }
                cin>>m;
                Polynomial b;
                for(int i=0;i<m;i++){
                    cin>>t1>>t2;
                    b.get()[t1]+=t2;
                }
                a = a*b;
                a.print();
                break;
            }
            case 'e':{
                cin>>m;
                Polynomial a;
                for(int i=0;i<m;i++){
                    cin>>t1>>t2;
                    a.get()[t1]=t2;
                }
                cin>>t2;
                cout<<a.eval(a.get(),t2);
                cout<<endl;
                break;
            }
        }
    }
    
    
    return 0;
}
