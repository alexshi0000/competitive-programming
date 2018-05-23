#include <bits/stdc++.h>
using namespace std;

class node{
	public:
		int x, y, d;
		node(){ 
			x = 0;
			y = 0;
			d = 0;
		}
		~node(){

		}
};

bool safe(int x, int y, vector < vector <node*> > *board){
	if(x < 8 && y < 8 && x > -1 && y > -1){
		return true;
	}
	return false;
}

int bfs(int x0, int y0, int x1, int y1, vector < vector <node*> > *board){
	vector <node*> queue;
	(*board)[y0][x0] -> d = 0;
	queue.insert(queue.begin(),(*board)[y0][x0]);
	while(queue.size() > 0){
		node *focus = queue.back();
		queue.pop_back();
		if(focus-> x == x1 && focus -> y == y1) 
			return focus -> d;
		int y,x;
		y = focus -> y;
		x = focus -> x;
		if( safe(y+2, x+1, board)){
			(*board)[y+2][x+1] -> d = focus -> d + 1;
			queue.insert(queue.begin(),(*board)[y+2][x+1]);
		}
		if(safe(y+1, x+2, board)){
			(*board)[y+1][x+2] -> d = focus -> d + 1;
			queue.insert(queue.begin(),(*board)[y+1][x+2]);
		}

		if(safe(y-2, x-1, board)){
			(*board)[y-2][x-1] -> d = focus -> d + 1;
			queue.insert(queue.begin(),(*board)[y-2][x-1]);
		}
		if(safe(y-1, x-2, board)){
			(*board)[y-1][x-2] -> d = focus -> d + 1;
			queue.insert(queue.begin(),(*board)[y-1][x-2]);
		}

		if(safe(y-2, x+1, board)){
			(*board)[y-2][x+1] -> d = focus -> d + 1;
			queue.insert(queue.begin(),(*board)[y-2][x+1]);
		}
		if(safe(y-1, x+2, board)){
			(*board)[y-1][x+2] -> d = focus -> d + 1;
			queue.insert(queue.begin(),(*board)[y-1][x+2]);
		}

		if(safe(y+2, x-1, board)){
			(*board)[y+2][x-1] -> d = focus -> d + 1;
			queue.insert(queue.begin(),(*board)[y+2][x-1]);
		}
		if(safe(y+1, x-2, board)){
			(*board)[y+1][x-2] -> d = focus -> d + 1;
			queue.insert(queue.begin(),(*board)[y+1][x-2]);
		}
	}
	return -1;
}	

int main(){
	vector < vector <node*> > board (8, vector <node*>(8, nullptr));
 	for(int i = 0; i < 8; i++){
 		for(int j = 0; j < 8; j++){
 			board[i][j] = new node();
 			board[i][j] -> y = i;
 			board[i][j] -> x = j;
 			board[i][j] -> d = 0;
 		}
 	}
 	int x0,y0,x1,y1;
 	cin >> x0 >> y0;
 	cin >> x1 >> y1;
 	cout << bfs(x0-1,y0-1,x1-1,y1-1,&board) << endl;
 	return 0;
}