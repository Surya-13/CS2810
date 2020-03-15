//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 04-02-2020         **
// SUBMISSION DEADLINE: 05-02-2020   **
//*************************************

#include<bits/stdc++.h>
#define ll long long int                                                // ll = long long int
using namespace std;

class Complex{
  private:
    double real;
    double img;
  public:
    Complex(){}
    Complex(double real, double img){
        this->real = real;
        this->img = img;
    }
    Complex add(Complex c1,Complex c2);
    Complex sub(Complex c1,Complex c2);
    Complex mult(Complex c1,Complex c2);
    double get_real(){return this->real;}                           // Get the real part of the complex number
    double get_img(){return this->img;}                             // Get the imaginary part of the complex number
    void print(Complex cc);                                         // Print the complex number
    ~Complex(){}
};

class Rational:public Complex{
  private:
    int num;
    int den;
  public:
    Rational(int num,int den){
        this->num = num;
        this->den = den;
    }
    Complex get_complex(Rational r);                                // Function to convert the passed rational number into a complex number
    Rational get_rational(Complex c);                               // Function to convert the passed complex number into a rational number
    int get_num(){return this->num;}                                // Get the numerator of the rational number
    int get_den(){return this->den;}                                // Get the denominator of the rational number
    void reduce();                                                  // Reduce the given rational number
    void print(Complex c);                                          // Print the rational number
    ~Rational(){}
};

class Natural:public Complex{
  private:
    int num;
  public:
    Natural(int num){
        this->num=num;
    }
    ll inverse(int n,int m);                                         // Find the inverse modulo 1000000007 for the given number
    int is_prime(int n);                                             // Check prime for the given number
    ~Natural(){}
};

Complex Complex::add(Complex c1,Complex c2){
    Complex c(c1.get_real() + c2.get_real() , c1.get_img() + c2.get_img());
    return c;
}
Complex Complex::sub(Complex c1,Complex c2){
    Complex c(c1.get_real() - c2.get_real() , c1.get_img() - c2.get_img());
    return c;
}
Complex Complex::mult(Complex c1,Complex c2){
    double a,b,c,d;
    a = c1.get_real();
    b = c1.get_img();
    c = c2.get_real();
    d = c2.get_img();
    Complex x(a*c - b*d , a*d + b*c);                        // (a+i*b)*(c+i*d) = (a*c - b*d) + (a*d + b*c)*i
    return x;
}
void Complex::print(Complex cc){
    cout<<cc.get_real()<<" "<<cc.get_img()<<endl;
}
Complex Rational::get_complex(Rational r){
    double d = (double)r.get_num()/(double)r.get_den();
    Complex c(d,0);
    return c;
}
Rational Rational::get_rational(Complex c){
    int x = c.get_real();
    Rational r(x,1);
    return r;
}
void Rational::print(Complex c){
    double d = (double)c.get_real();
    cout<<d<<endl;
}
int gcd(int a, int b){
    if (a == 0) 
        return b; 
    return gcd(b%a, a);                                     // Using Euclid's method of finding the GCD.                                      
} 
void Rational::reduce(){
    int x = gcd(this->get_num(),this->get_den());
    int a = (int)this->get_num()/x;
    int b = (int)this->get_den()/x;
    if(a*b>0){
        cout<<abs(a)<<" "<<abs(b)<<endl;                      // Print such that if number is negative then the first number
    }                                                         // to be printed is negative.                                 
    else{
        cout<<"-"<<abs(a)<<" "<<abs(b)<<endl;            
    }
}
ll power(int x, unsigned int y, unsigned int m){
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m;                              // If the number m is prime then using Fermats little theorem
    p = (p * p) % m;                                          // we have pow(a,-1) = pow(a,m-2) (mod m)  
    return (y%2 == 0)? p : (x * p) % m;                       // https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
} 
ll Natural::inverse(int n,int m){
  return power(n,m-2,m);
}
int Natural::is_prime(int n){ 
    if (n <= 1) 
        return 0; 
    if (n <= 3) 
        return 1;                                             // Check prime
    if (n % 2 == 0 || n % 3 == 0)                             // https://www.geeksforgeeks.org/c-program-to-check-prime-number/
        return 0; 
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return 0; 
    return 1; 
    
}
int main(){
    int m = pow(10,9) + 7;                                   // m = 1000000007
    cout.precision(3);                                       // Set the precision to be 3
    cout<<fixed;
    int n,t1,t2;
    double d1,d2;
    string s1,s2;
    cin>>n;
    while(n){
        n--;
        cin>>s1>>s2;
        if(s1 == "complex"){
            if(s2 == "add"){
                        cin>>d1>>d2;
                        Complex c1(d1,d2);
                        cin>>d1>>d2;
                        Complex c2(d1,d2);
                        Complex c = c1.add(c1,c2);
                        c.print(c);
            }
            if(s2 == "sub"){
                        cin>>d1>>d2;
                        Complex c1(d1,d2);
                        cin>>d1>>d2;
                        Complex c2(d1,d2);
                        Complex c = c1.sub(c1,c2);
                        c.print(c);
            }
            if(s2 == "mult"){
                        cin>>d1>>d2;
                        Complex c1(d1,d2);
                        cin>>d1>>d2;
                        Complex c2(d1,d2);
                        Complex c = c1.mult(c1,c2);
                        c.print(c);
            }
        }
        if(s1 == "rational"){
            if(s2 == "add"){
                        cin>>t1>>t2;
                        Rational r1(t1,t2);
                        cin>>t1>>t2;
                        Rational r2(t1,t2);
                        Complex c = r1.add(r1.get_complex(r1),r2.get_complex(r2));
                        r1.print(c);
            }
            if(s2 == "sub"){
                        cin>>t1>>t2;
                        Rational r1(t1,t2);
                        cin>>t1>>t2;
                        Rational r2(t1,t2);
                        Complex c = r1.sub(r1.get_complex(r1),r2.get_complex(r2));
                        r1.print(c);
            }
            if(s2 == "mult"){
                        cin>>t1>>t2;
                        Rational r1(t1,t2);
                        cin>>t1>>t2;
                        Rational r2(t1,t2);
                        Complex c = r1.mult(r1.get_complex(r1),r2.get_complex(r2));
                        r1.print(c);
            }
            if(s2 == "reduce"){
                        cin>>t1>>t2;
                        Rational r1(t1,t2);
                        r1.reduce();
            }
        }
        if(s1 == "natural"){
            if(s2 == "isprime"){
                cin>>t1;
                Natural n(t1);
                cout<<n.is_prime(t1)<<endl;
            }
            if(s2 == "inverse"){
                cin>>t1;
                Natural n(t1);
                cout<<n.inverse(t1,m)<<endl;
            }
        }
                
    }
    
    return 0;
}