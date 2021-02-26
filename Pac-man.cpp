//-------------------------------------------------------------------------------------
// Привет, меня зовут Егор и это моя первая програма написаная на С++ если не считать
// "Hello word". Некоторым стала интересна эта простая игра, её можно 
// дорабатывать\разширять\полностью переписать но костяк логики останиться.
//
// С уважением Бодак Егор, Укр.
//-------------------------------------------------------------------------------------
// Hi, my name is Egor and this is my first program written in C ++ except
// "Hello word". Some people became interested in this simple game, you can
// modify \ expand \ completely rewrite but the core of the logic remains.
//
// Yours faithfully Bodak Yegor, Ukr.
//------------------------------------------------------------------------------------

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Logik.h"
using namespace std;

int main(int argc, char** argv) {
	Seting();
	while (!gameOver) { // Цикл работы програмы  
		Graf();
		Oper();
		Logik();
		//Bot();
	}
	return 0;
}
