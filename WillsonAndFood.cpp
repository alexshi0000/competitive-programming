#include<bits/stdc++.h>
using namespace std;
class block{
	public:
		int energy, dist;
		block(int energy, int dist){
			this->energy = energy;
			this->dist = dist;
		}
		~block(){}
};
struct functor{
	bool operator ()(block *a, block *b){
		return a->dist < b->dist;
	}
};
int main(){
	int f,n;
	cin >> f;
	map<string, int> food;
	for(int i = 0; i < f; i++){
		string s;
		int e;
		cin >> s >> e;
		food.insert(make_pair(s,e));
	}
	vector<block*> map;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		int d;
		cin >> s >> d;
		map.push_back(new block(food[s],d));
	}
	functor fnc;
	sort(map.begin(), map.end(), fnc);
	/*for(int i = 0; i < map.size(); i++)//debug
		cout << "energy: " << map.at(i)->energy << " dist: " << map.at(i)->dist << endl;*/
	int energy = 0;
	int food_amt = 0;		//amt of food eaten
	for(int i = 0; i < (int)map.size(); i++){
		int j = i;
		if(i > 0)
			energy -= map.at(i)->dist - map.at(i-1)->dist;
		else if(map.at(i)->dist > 0)
			break;
		if(energy < 0)
			break;
		for(; j < (int)map.size() && map.at(i)->dist == map.at(j)->dist; j++){
			energy += map.at(j)->energy;
			food_amt++;
			i = j;
		}
		if(energy <= 0)
			break;
	}
	cout << food_amt << endl;
	//cout << energy << endl;
	return 0;
}