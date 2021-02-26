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
using namespace std;

bool gameOver;
const int height = 12, width = 25;         // Длина и высота окна 12 19
int x, y, fruitX, fruitY, score;           // Кординаты змейки и фруктов 
enum eDirection { STOP = 0, W, S, A, D };  // Перечисления
eDirection dir;                            // Перемення перечислений
int gameOver_score = 0;                    // Очки проиграша 
int speed = 40;  //80                      // Скорость героя
int record = 0;                            // REVORD
int counter2 = 0, counter1 = 0;            // Псевдо перменые времени (используется для смены кадров)
int pologenna = 1;                         // Положения героя описаное цифрами
                                           // дальше в коде можно увидить как это работает

//---------------------------------------------------------------------------------------------------
//                         Настройка игры при запуске или её перезапуск
//---------------------------------------------------------------------------------------------------
void Seting() {                
	setlocale(LC_CTYPE, "");
	system("color e");        // Цвет окна
	gameOver = false;         // Начало цикла игры игру
	dir = STOP;               // Остановить движение

	x = height / 2 - 1;           // Поместить на центр 
	y = width / 2 - 1;

	fruitX = rand() % height; // Рандомное значения для фрукта
	fruitY = rand() % width - 2;
}

//----------------------------------------------------------------------------------------------------
//                     Функция смены параметров игры (добавлено недавно) НЕ ЗАКОНЧЕННА
//----------------------------------------------------------------------------------------------------

void GAME_seting() {
	bool exit;
	system("cls");
	cout <<   " _____________________________";
	cout << "\n|-------- SETING GAME --------|";
	cout << "\n|-----------------------------|";
	cout << "\n|1.The speed of the hero      |";
	cout << "\n|-----------------------------|";
	cout << "\n|2.Game them (color)          |";
	cout << "\n|-----------------------------|";
	cout << "\n|3.Record reset               |";
	cout << "\n|-----------------------------|";
	cout << "\n|4.Include a bot for testing  |";
	cout << "\n|(points will not be scored)  |";
	cout << "\n|-----------------------------|";
	cout << "\n|5.Exit seting                |";
	cout << "\n|_____________________________|";

	cout << "\n\n Enter the start number: ";
	cin >> exit;
	// тут должен был быть код =)
	system("color e");
}

//---------------------------------------------------------------------------------------------
//                                      Отрисовка игры
//---------------------------------------------------------------------------------------------

void Graf() {                  
	
	system("cls"); // Очищение 

	cout << "       PAC-MAN 1.1\n"; // ЛОГО
	for (int i = 0; i < width; i++) { // Верхняя граница
		cout << "#";
	}
	cout << "\n";

	for (int i = 0; i < height; i++) { // Тело
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 2)
				cout << "|"; //|
			if (i == x && j == y) {  // Печать героя 
				switch (pologenna) {
				case 1:
					if (counter1 % 2)
						cout << ">";
					else
						cout << "=";
					break;
				case 2:
					if (counter1 % 2)
						cout << "<";
					else
						cout << "=";
					break;
				case 3:
					if (counter1 % 2)
						cout << "A";
					else
						cout << "!";
					break;
				case 4:
					if (counter1 % 2)
						cout << "V";
					else
						cout << "!";
					break;
				}
			}
			else if (i == fruitX && j == fruitY) //Печать фрукта
				cout << "¤"; //¤
			else
				cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < width; i++) {  // Нижняя граница
		cout << "#";
	}

	cout << "\n\n\n  Score: " << score;
	cout << "\n  RECORD: " << record;
	cout << "\n  GameOver_score: " << gameOver_score;
	cout << "\n\n   W/8 - forward";
	cout << " S/5 - back";
	cout << "\n   A/4 - left";
	cout << " D/6 - right";
	cout << "\n        X/0 - exit";

	
	// Вывод кординат для нахождения багов 
		//cout <<"\n\n\nKORDINAT  X  Y: "<< x << " " << y << "\n";
		//cout << "KORDINAT FRUIT: "<< fruitX << " "<< fruitY;
		//cout << "\n time " << time ;
		//cout << "\n Pologenna " << pologenna;
	
	//-------------------------------------------------------------------------------------
	//                                    Частота кадров
	//-------------------------------------------------------------------------------------
	if (pologenna == 3 || pologenna == 4) {
		Sleep(speed* 2); 
	}
	else {
		Sleep(speed);
	}
	//-------------------------------------------------------------------------------------
	counter2++;
}

//-----------------------------------------------------------------------------------------
//                                  Функция получения значине
//-----------------------------------------------------------------------------------------
void Oper() {       
    // Проверка нажатия клавиши
	if (_kbhit()) {          
		switch (_getch()) {
		case'a':
			dir = A;
			pologenna = 1;
			break;
		case'd':
			dir = D;
			pologenna = 2;
			break;
		case's':
			dir = S;
			pologenna = 3;
			break;
		case'w':
			dir = W;
			pologenna = 4;
			break;
		case'x':
			system("color 9");
			cout << "\n\n        EXIT!";
			Sleep(3000);
			gameOver = true;
		// цифровое управление
		case'4':
			dir = A;
			pologenna = 1;
			break;
		case'6':
			dir = D;
			pologenna = 2;
			break;
		case'5':
			dir = S;
			pologenna = 3;
			break;
		case'8':
			dir = W;
			pologenna = 4;
			break;
		case'0':
			system("color 9");
			cout << "\n\n        EXIT!";
			Sleep(3000);
			gameOver = true;
			break;
		//--------------- SETING -------------
		case'z':
			GAME_seting();
			break;

		}
	}
}

//---------------------------------------------------------------------------------------------
//                                         Логика
//---------------------------------------------------------------------------------------------
void Logik() {  // Логика работы программ
	switch (dir) {      // Смена направления
	case A:
		y--;
		break;
	case D:
		y++;
		break;
	case S:
		x++;
		break;
	case W:
		x--;
		break;
	}
	if (x == fruitX && y == fruitY) {   // Смена положения фрукта и очков
		score = score + 10;

		int minX = 0, maxX = height;
		int minY = 0, maxY = width - 2;

		maxX = maxX - minX;
		maxY = maxY - minY;

		fruitX = rand() % maxX;
		fruitY = rand() % maxY;
	}
	if (x == -1 || x == height || y == -1 || y == width - 2) { // Проверка на граници карты 
		system("color 4");
		score = 0;
		gameOver_score++;
		cout << "\n\n       GAME OVER!";
		Sleep(3000);
		Seting();
	}
	if (score > record) {         //Рекорд в игре
		system("color a");
		record = score;
	}
	if (counter2 == 1) {
		counter1++;
		counter2 = 0;
	}
	//-------------------------------------------------------------------------------------
	// Раньше у игры была только одна цель это набор очков и побитие своего рекорда, в даном
	// участке кода, а имено конец функции Логики я решил разнообразить игру графичискими 
	// увидомлениями на разных рекордах игры. Если кто-то дорабативает этот код он сможет 
	// продолжить разобразие на болие высоких рекордах.
	//
	// Previously, the game had only one goal, this is to gain points and break your record, 
	// in this a section of code, and specifically the end of the Logic function, I decided 
	// to diversify the game with graphical seeing at different records of the game. If someone 
	// modifies this code he can continue developing for more high records.
	//-------------------------------------------------------------------------------------
	if (record == 1000000000) {
		record += 10;
		system("cls color a");
		for (int i = 0; i < 20;i++) {
			for (int j = 0; j < 5;j++) {
				cout << "1000000000 ";
				Sleep(50);
			}
			cout << "\n";
		}
	}

}


//---------------------------------------------------------------------------------------
//                                      Bot  || Бот
//---------------------------------------------------------------------------------------
// Бот был добавлен в игру для бистрого теста на баги, алгоритм построин так что бы он 
// всегда выигрывал тоесть по отображению смерти можно увидеть роботоспособность игри
//
// The bot was added to the game for a quick test for bugs, the algorithm was built so 
// that it always won, that is, by displaying death, you can see the robotic nature of 
// the game
//---------------------------------------------------------------------------------------
void Bot() {
	if (x > fruitX) {
		x--;
		pologenna = 4;
	}
	if (x < fruitX) {
		x++;
		pologenna = 3;
	}
	if (x == fruitX) {

		if (y > fruitY) {
			y--;
			pologenna = 1;
		}

		if (y < fruitY) {
			y++;
			pologenna = 2;
		}
	}
}
