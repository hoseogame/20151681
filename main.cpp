#include"GameSchedule.h"
#include <iostream>
using namespace std;
typedef int(*GS)();

int main(){
	GS gs;
	while (1){
		int choice;
		cout << "두더지 게임할거면 1, 테트리스 게임 할거면 2, 나가고 싶으면 0을 누르세요." << endl;
		cin >> choice;
		if (choice == 0)
			break;
		switch (choice){
		case 1:
			gs = D;
			break;
		case 2:
			gs = T;
		}
		gs();
	}
}
