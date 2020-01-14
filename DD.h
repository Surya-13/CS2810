#include<bits/stdc++.h>	
#include"Faculty.h" 
using namespace std;

typedef int RollNumber;

class DD{
public:
	RollNumber r;
	Faculty facad;
	Faculty ddpguide;
	Faculty TAsupe;
	string hostel;
	float cgpa;
	DD(RollNumber r, string hostel, Faculty facad, float cgpa){
		this->r=r;this->hostel=hostel;this->facad=facad;this->cgpa=cgpa;
	}
	string getHostel();
	Faculty getFacad();
	void changeHostel(string s);
	Faculty getDDPGuide();
	void setDDPGuide(Faculty f);
	Faculty getTASupervisor();
	void setTASupervisor(Faculty f);
};


