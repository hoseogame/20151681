#include"GameSchedule.h"
#include <iostream>
using namespace std;
typedef int(*GS)();

int main(){
	GS gs;
	while (1){
		int choice;
		cout << "�δ��� �����ҰŸ� 1, ��Ʈ���� ���� �ҰŸ� 2, ������ ������ 0�� ��������." << endl;
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
