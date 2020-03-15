//*************************************
// NAME: B.V.S.SUDHEENDRA            **
// ROLL NO: CS18B006                 **
// DATE FINISHED: 20-01-2020         **
// SUBMISSION DEADLINE: 22-01-2020   **
//*************************************

#include<bits/stdc++.h>
using namespace std;

#define x1 Inventory::vec1
#define x2 Pen::vec2                          //Making a short-hand notation for the following static array variables
#define x3 Pencil::vec3

class Inventory{
    private:
    int id;
    float price;
    string manufact;
    string type;
    
    public:
    static vector<Inventory> vec1;
    Inventory(int id,float price,string manfac,string type){
        this->id = id;
        this->price=price;                              //Constructor
        this->manufact=manfac;  
        this->type=type;
    }
    ~Inventory(){}
    int getid();
    float getPrice();
    string getManufacturer();
    string getType();
};
vector<Inventory> Inventory::vec1;                         //Declaring the static array outisde the class


class Pen{
    private:
    int id;
    float width;
    string colour;
    string style;
    
    public:
    static vector<Pen> vec2;
    Pen(int id,float width,string colour,string style){
        this->id = id;
        this->width = width;                                  //Constructor
        this->colour = colour;
        this->style = style;
    }
    ~Pen(){}
    int getid();
    float getwidth();
    string getcolour();
    string getstyle();
};
vector<Pen> Pen::vec2;                         //Declaring the static array outisde the class


class Pencil{
    private:
    int id;
    float width;
    string Hardness_mark;
    string point_size;
    
    public:
    static vector<Pencil> vec3;
    Pencil(int id,float width,string Hardness_mark,string point_size){
        this->id = id;
        this->width = width;                                   //Constructor
        this->Hardness_mark = Hardness_mark;
        this->point_size = point_size;
    }
    ~Pencil(){}
    int getid();
    float getwidth();
    string getHardness_mark();
    string getpoint_size();
};
vector<Pencil> Pencil::vec3;                         //Declaring the static array outisde the class


int Inventory::getid(){
    return this->id;
}
float Inventory::getPrice(){                         //Implementation of the class Inventory methods
    return this->price;
}                                                      
string Inventory::getManufacturer(){
    return this->manufact;
}
string Inventory::getType(){
    return this->type;
}


int Pen::getid(){
    return this->id;
}
float Pen::getwidth(){                         //Implementation of the class Pen methods
    return this->width;
}
string Pen::getcolour(){
    return this->colour;
}
string Pen::getstyle(){
    return this->style;
}


int Pencil::getid(){
    return this->id;
}
float Pencil::getwidth(){                         //Implementation of the class Pencil methods
    return this->width;
}
string Pencil::getHardness_mark(){
    return this->Hardness_mark;
}
string Pencil::getpoint_size(){
    return this->point_size;
}


bool check1(Inventory v1,Inventory v2){
    return v1.getid()<v2.getid();
}
bool check2(Pen v1,Pen v2){                        //Bool functions to sort the vector according to the id.
    return v1.getid()<v2.getid();
}
bool check3(Pencil v1,Pencil v2){
    return v1.getid()<v2.getid();
}

void delete_class(int id){
    for(auto ii = x1.begin();ii!=x1.end();ii++){
        if((*ii).getid()==id){                         //Erase from the Inventory array
            x1.erase(ii);
            ii--;                                // VERY IMP: Decrement the iterator after deleting the elements
        }
    }
    for(auto ii = x2.begin();ii!=x2.end();ii++){
        if((*ii).getid()==id){                         //Erase from the Pen array
            x2.erase(ii);
            ii--;                                // VERY IMP: Decrement the iterator after deleting the elements
        }
    }
    for(auto ii = x3.begin();ii!=x3.end();ii++){
        if((*ii).getid()==id){                         //Erase from the Pencil array
            x3.erase(ii);
            ii--;                                // VERY IMP: Decrement the iterator after deleting the elements
        }
    }
}
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        char x;int id;float val;string s1;string s2;
        cin>>x;
        switch(x){
            case 'a':{
                cin>>id>>val>>s1>>s2;
                Inventory Inv(id,val,s1,s2);
                Inventory::vec1.push_back(Inv);
                break;
            }               
            case 'b':{
                cin>>id>>val>>s1>>s2;
                Pen New_pen(id,val,s1,s2);
                Pen::vec2.push_back(New_pen);
                break;
            }               
            case 'c':{
                cin>>id>>val>>s1>>s2;
                Pencil New_pencil(id,val,s1,s2);
                Pencil::vec3.push_back(New_pencil);
                break; 
            } 
            case 'd':{
                cin>>id;
                delete_class(id);
                break;
            }  
            case 'p':
                sort(x1.begin(),x1.end(),check1);
                for(int ii=0;ii<x1.size();ii++){
                    cout<<x1[ii].getid()<<" "<<x1[ii].getPrice()<<" "<<x1[ii].getManufacturer()<<" "<<x1[ii].getType();
                cout<<endl;
                }
                break;
            case 'q':
                sort(x2.begin(),x2.end(),check2);
                for(int ii=0;ii<x2.size();ii++){
                    cout<<x2[ii].getid()<<" "<<x2[ii].getwidth()<<" "<<x2[ii].getcolour()<<" "<<x2[ii].getstyle();
                    cout<<endl;
                }
                break;
            case 'r':
                sort(x3.begin(),x3.end(),check3);
                for(int ii=0;ii<x3.size();ii++){
                    cout<<x3[ii].getid()<<" "<<x3[ii].getwidth()<<" "<<x3[ii].getHardness_mark()<<" "<<x3[ii].getpoint_size();
                    cout<<endl;
                }
                break;
        }
        
    }
    return 0;
}
