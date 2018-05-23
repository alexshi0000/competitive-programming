#include <stdio.h>
#include <fstream>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

int xpos,ypos;
int width, height, cwidth, cheight;

bool safe(int y, int x, int map[]){
	if(y < 0 || y >= height)  return false;
	if(x < 0 || x >= width)   return false;
	if(map[y*width + x] == 1) return false;
	return true;
}

int search(int y, int x, int map[], int steps){
	if(steps == 0){
		xpos = x;
		ypos = y;
		return 0;
	}
	map[y*width + x] = 1;
	//print(map);
	if(safe(y,x+1,map) && !safe(y-1,x,map)){
		search(y,x+1,map,steps-1);
		return 0;
	}
	if(safe(y+1,x,map) && !safe(y,x+1,map)){
		search(y+1,x,map,steps-1);
		return 0;
	}
	if(safe(y,x-1,map) && !safe(y+1,x,map)){
		search(y,x-1,map,steps-1);
		return 0;
	}
	if(safe(y-1,x,map) && !safe(y,x-1,map)){
		search(y-1,x,map,steps-1);
		return 0;
	}
	xpos = x;
	ypos = y;
	return 0;
}

int main(){
	int steps;
	cin >> width;
	cin >> height;
	cin >> cwidth;
	cin >> cheight;
	cin >> steps;
	int map[height*width];
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			map[i*width + j] = 0; 
			if(i < cheight || i > height-1-cheight){
				if(j < cwidth || width-1-cwidth < j) map[i*width + j] = 1;
			}
		}
	}
	search(0,cwidth,map,steps);
	cout << xpos+1 << endl;
	cout << ypos+1 << endl;
	return 0;
}