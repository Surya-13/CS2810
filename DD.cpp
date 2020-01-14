#include<bits/stdc++.h>
#include"DD.h"	
using namespace std;

string DD::getHostel(){
	return hostel;
}
Faculty DD::getFacad(){
	return facad;
}
void DD::changeHostel(string s){
	this->hostel = s;
}
void DD::setDDPGuide(Faculty f){
	this->facad = f;
}
Faculty DD::getDDPGuide(){
	return ddpguide;
}
Faculty DD::getTASupervisor(){
	return TAsupe;
}
void DD::setTASupervisor(Faculty f){
	this->TAsupe = f;
}
