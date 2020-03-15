#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class student{
public:
	vector<ll> marks;
	ll skill;
	static ll num_inversions;
	student(){
		marks.resize(5, 0);
		skill = 0;
	}

	bool operator <(student &s2){
		return this->skill < s2.skill;
	}

};
ll student::num_inversions;

bool cmp(const student &s1, const student &s2){
	return s1.marks < s2.marks;
}

vector<student> merge(vector<student> &vec1, vector<student> &vec2){
	ll ptr1 = 0, ptr2 = 0;
	vector<student> answer;
	ll sz1 = vec1.size(), sz2 = vec2.size();
	while((ptr1 < sz1) || (ptr2 < sz2)){
		if(ptr1 == sz1){
			answer.insert(answer.end(), vec2.begin() + ptr2, vec2.end());
			return answer;
		} else if(ptr2 == sz2){
			answer.insert(answer.end(), vec1.begin() + ptr1, vec1.end());
			return answer;
		} else{
			if(vec2[ptr2] < vec1[ptr1]){
				answer.push_back(vec2[ptr2]);
				ptr2++;
				student::num_inversions += (sz1 - ptr1);
			} else{
				answer.push_back(vec1[ptr1]);
				ptr1++;
			}
		}
	}
	return answer;
}

vector<student> merge_sort(vector<student> all_studs){
	if(all_studs.size() == 1){
		return all_studs;
	} else{
		ll sz = all_studs.size();
		ll half = sz/2;
		vector<student> half1(all_studs.begin(), all_studs.begin() + half), half2(all_studs.begin() + half, all_studs.end());
		all_studs.clear();

		half1 = merge_sort(half1);
		half2 = merge_sort(half2);
		vector<student> sorted = merge(half1, half2);
		
		half1.clear();
		half2.clear();
		
		return sorted;
	}
}



int main(){
	ll n; cin >> n;
	vector<student> all_studs(n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < 5;j++){
			cin >> all_studs[i].marks[j];
		}
		cin >> all_studs[i].skill;
	}

	// sort by decreasing rank
	sort(all_studs.begin(), all_studs.end(), cmp);
	// reverse(all_studs.begin(), all_studs.end());

	student::num_inversions = 0;

	vector<student> sorted = merge_sort(all_studs);

	cout << student::num_inversions << endl;
}