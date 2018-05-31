#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct player{
	string name;
	int bombs = 20;
	int ships = 5;
};

bool P1Grid[5][5];
bool P2Grid[5][5];
player p1;
player p2;
int x_c;
int y_c;
string action1;
string action2;

void strike1(){
	cout << "X coordinate of attack: ";
	cin >> x_c;
	cout << "Y coordinate of attack: ";
	cin >> y_c;
    	if(P2Grid[x_c-1][y_c-1]){
        	P2Grid[x_c-1][y_c-1] = false;
        	cout << "Hit!\n";
        	p2.ships=p2.ships - 1;
    	}
    p1.bombs=p1.bombs - 1;
}

void strike2(){
	cout << "X coordinate of attack: ";
	cin >> x_c;
	cout << "Y coordinate of attack: ";
	cin >> y_c;
    	if(P1Grid[x_c-1][y_c-1]){
        	P1Grid[x_c-1][y_c-1] = false;
        	cout << "Hit!\n";
        	p1.ships=p1.ships - 1;
    	}
    p2.bombs=p2.bombs - 1;
}

int main(){
	cout << "What is your name, Player 1?\n";
	cin >> p1.name;
	cout << "What is your name, Player 2?\n";
	cin >> p2.name;
	cout << p1.name << ", enter 5 ship locations, x coordinate then y coordinate.\n";
    	for(int i=0; i<5; i++){
        	cout << "X coordinate: ";
        	cin >> x_c;
        	cout << "Y coordinate: ";
        	cin >> y_c;
        	P1Grid[x_c-1][y_c-1] = true;
    	}
    	    clrscr();
        	cout << p2.name << ", enter 5 ship locations, x coordinate then y coordinate.\n";
    	for(int j=0; j<5; j++){
        	cout << "X coordinate: ";
        	cin >> x_c;
        	cout << "Y coordinate: ";
        	cin >> y_c;
        	P2Grid[x_c-1][y_c-1] = true;
    	}
    	    clrscr();
	while(true){
    	cout << "Would " << p1.name << " like to strike or build bombs?\n";
    	cout << "Bombs: " << p1.bombs << "\n";
    	getline(cin, action1);
        	if(action1=="strike"){
            	strike1();
        	}
        	if(action1=="build"){
            	p1.bombs=p1.bombs + 1;
        	}
            	cout << "Would " << p2.name << " like to strike or build bombs?\n";
            	cout << "Bombs: " << p2.bombs << "\n";
            	getline(cin, action2);
                	if(action2=="strike"){
                    	strike2();
                	}
                    	if(action2=="build"){
                        	p2.bombs=p2.bombs + 1;	
                    	}
                	if(p1.ships==0){
                    	cout << p2.name << " wins!";
                    	return 0;   	
                	}
            	if(p2.ships==0){
                	cout << p1.name << " wins!";
                	return 0;
            	}
        	if(p1.bombs==0){
            	cout << p2.name << " wins!";
            	return 0;
        	}
    	if(p2.bombs==0){
        	cout << p1.name << " wins!";
        	return 0;
    	}  
    }
}
