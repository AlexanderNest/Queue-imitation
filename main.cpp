#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
#include "windows.h"


//теория массового обслуживания matburo
using namespace std;

double random(){
	double min = 0.0;
	double max = 1.0;
    return (double)(rand())/RAND_MAX*(max - min) + min;
}

bool come(double alpha){
	/*
		alpha - человек в секунду
		1 за 45 сек - 0.02222
		1 за 20 сек -  0.05
	*/
	
	double P;
	P = alpha / exp(alpha);
	
	return P >= random();
}

bool left(double alpha){
	/*
		alpha - человек в секунду
		1 за 45 сек - 0.02222
		1 за 20 сек -  0.05
	*/
	
	
	double P;
	P = alpha / exp(alpha);
	
	return P >= random();
}

void windowsInfo(bool *windows, int count, int people){
	
	system("cls");
	
	for (int i = 0; i < count; i++){
		cout << "window" << i << " - " << windows[i] << endl;
	}
	
	cout << "\nawaiting - " << people;
}

int main(){
	int count = 200; // людей в очереди
	int windows = 20; // количество окон для приема людей
	double PPSLeft = 0.1;
	double PPSCome = 0.202;
	
	bool *win = new bool[windows];
	
	for (int i = 0; i < windows; i++){
		win[i] = false;
	} 
	
	while (1){
		for (int i = 0; i < windows; i++){
			if (count > 0){
				if (!win[i]){
					win[i] = 1;
					count--;
				}
			}
			
			if (win[i] == 1){
				if (left(PPSLeft)){
						win[i] = 0;
					}
				
			}
		}
		if (come(PPSCome)){
			count++;
		}
		
		windowsInfo(win, windows, count);
		Sleep(1000);
	}
}
