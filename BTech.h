#include<bits/stdc++.h>
#include"Faculty.h" 	
using namespace std;

typedef int RollNumber;

class Btech{
public:
	RollNumber r;
	Faculty facad;
	Faculty btpguide;
	string hostel;
	float cgpa;
	Btech(RollNumber r, string hostel, Faculty facad, float cgpa){
		this->r=r;this->hostel=hostel;this->facad=facad;this->cgpa=cgpa;
	}
	string getHostel();
	Faculty getFacad();
	void changeHostel(string s);
	Faculty getBTPGuide();
	void setBTPGuide(Faculty f);

};

	
