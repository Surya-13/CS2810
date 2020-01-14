#include<bits/stdc++.h>
#include"BTech.h"
using namespace std;

string Btech::getHostel(){
	return hostel;
}
Faculty Btech::getFacad(){
	return facad;
}
void Btech::changeHostel(string s){
	this->hostel = s;
}
void Btech::setBTPGuide(Faculty f){
	this->facad = f;
}
Faculty Btech::getBTPGuide(){
	return btpguide;
}