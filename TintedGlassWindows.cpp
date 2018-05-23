#include<bits/stdc++.h>
using namespace std;
long t, n;
class pane{
	public:
		long x1,x2,y1,y2, tlong;
		pane(long x1, long y1, long x2, long y2, long tlong){
			this->x1 = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
			this->tlong = tlong;
		}
		~pane(){}
};
bool left_edge(pane *a, pane *b){
	return a->x1 > b->x1;
}
bool right_edge(pane *a, pane *b){
	return a->x2 > b->x2;
}
bool top_edge(pane *a, pane *b){						
	return a->y1 < b->y1;
}
bool bot_edge(pane *a, pane *b){
	return a->y2 < b->y2;
}
int main(){
	cin >> n;
	cin >> t;
	priority_queue< pane*, vector<pane*>, function<bool(pane*,pane*)>> l_edge(left_edge);			//left and right edges are removable
	priority_queue< pane*, vector<pane*>, function<bool(pane*,pane*)>> r_edge(right_edge);
	vector<pane*> t_edge;																			//top and bottom edges are not
	vector<pane*> b_edge;
	for(long i = 0; i < n; i++){
		long x1,y1,x2,y2,tlong;
		cin >> x1 >> y1 >> x2 >> y2 >> tlong;
		pane *new_window = new pane(x1,y1,x2,y2,tlong);
		l_edge.push(new_window);
		r_edge.push(new_window);
		t_edge.push_back(new_window);
		b_edge.push_back(new_window);
	}
	sort(t_edge.begin(), t_edge.end(), top_edge);
	sort(b_edge.begin(), b_edge.end(), bot_edge);
	long h1, h2;																						//first and second critical polongs
	h2 = l_edge.top()->x1;
	l_edge.pop();
	long long area = 0;
	while(r_edge.size() > 0){
		h1 = h2;
		if(l_edge.size() > 0 && l_edge.top()->x1 < r_edge.top()->x2){
			h2 = l_edge.top()->x1;
			l_edge.pop();
		} 
		else{
			h2 = r_edge.top()->x2;
			r_edge.pop();
		}
		long v1, v2, sub_tlong=0;
		vector<pane*> tt_edge(t_edge);
		vector<pane*> bb_edge(b_edge);															//very much like in java arraylist copy
		//init tlong and v2
		v2 = tt_edge.at(0)->y1;
		if(tt_edge.at(0)->x1 <= h1 && tt_edge.at(0)->x2 >= h2)
			sub_tlong += tt_edge.at(0)->tlong;
		tt_edge.erase(tt_edge.begin()+0);
		//loop
		while(bb_edge.size() > 0){
			v1 = v2;
			if(tt_edge.size() > 0 && tt_edge.at(0)->y1 < bb_edge.at(0)->y2){
				v2 = tt_edge.at(0)->y1;
				if(sub_tlong >= t)
					area += abs((h1-h2)*(v1-v2));
				if(tt_edge.at(0)->x1 <= h1 && tt_edge.at(0)->x2 >= h2)
					sub_tlong += tt_edge.at(0)->tlong;
				tt_edge.erase(tt_edge.begin()+0);
			}
			else{
				v2 = bb_edge.at(0)->y2;
				if(sub_tlong >= t)
					area += abs((h1-h2)*(v1-v2));
				if(bb_edge.at(0)->x1 <= h1 && bb_edge.at(0)->x2 >= h2)
					sub_tlong -= bb_edge.at(0)->tlong;												//after we are done with this glass window then we subtract the tlong from total tlong
				bb_edge.erase(bb_edge.begin()+0);
			}
		}
	}
	cout<<area<<endl;
	return 0;
}