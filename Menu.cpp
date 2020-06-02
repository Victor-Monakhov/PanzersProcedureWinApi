#include "Header.h"

void showcursor(bool flag)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(consoleHandle, &info);
	info.bVisible = flag;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void setCursorPosition(COORD coord)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout.flush();
	SetConsoleCursorPosition(hOut, coord);
}

short menuStandart(HWND screen, HDC hdc, COORD firstMenuCoord, HBITMAP picture, void(*pointer)(HWND screen, HDC hdc), short items, short step) {
	COORD tempStartCoord = firstMenuCoord;
	bool loop = true;
	char button;
	while (loop) {
		paintPictures({ 0,0 }, screen, picture, hdc);
		pointer(screen, hdc);
		paintBorder(hdc, firstMenuCoord);
		if (_kbhit()) {
			button = _getch();
			switch (button) {
			case KEY_UP: {
				if (firstMenuCoord.X == 50) {
					firstMenuCoord.Y -= step;
				}
				if (firstMenuCoord.Y < tempStartCoord.Y) {
					firstMenuCoord.Y = firstMenuCoord.Y + (step * items);
				}
				break;
			}
			case KEY_DOWN: {
				if (firstMenuCoord.X == 50) {
					firstMenuCoord.Y += step;
				}
				if (firstMenuCoord.Y > tempStartCoord.Y + (step * (items -1))) {
					firstMenuCoord.Y = tempStartCoord.Y;
				}
				break;
			}
			case KEY_RIGHT: {
				if (firstMenuCoord.X == 500 && firstMenuCoord.Y == 600) {
					firstMenuCoord = { 50, 600 };
				}
				if (firstMenuCoord.X == 50 && firstMenuCoord.Y == 600) {
					firstMenuCoord = { 500, 600 };
				}
				break;
			}
			case KEY_LEFT: {
				if (firstMenuCoord.X == 50 && firstMenuCoord.Y == 600) {
					firstMenuCoord = { 500, 600 };
				}
				if (firstMenuCoord.X == 500 && firstMenuCoord.Y == 600) {
					firstMenuCoord = { 50, 600 };
				}
				break;
			}
			case KEY_ENTER: {loop = false; break; }
			default: break;
			}
		}
		Sleep(100);
	}
	if (firstMenuCoord.X == 50){
		return firstMenuCoord.Y;
	}
	else {
		return firstMenuCoord.X;
	}
}
short menuProfile(HWND screen, HDC hdc, COORD firstMenuCoord, Profile *profile, void(*pointer)(HWND screen, HDC hdc, Profile *profile, short size, short length, bool showSearch), short items, short size, bool &escape) {
	bool loop = true;
	char button;
	short i = 0;
	while (loop && size > 0) {
		paintPictures({ 0,0 }, screen, deskProfileUniversal, hdc);
		if (i < 6) {
			pointer(screen, hdc, profile, size, 0, true);
		}
		else {
			pointer(screen, hdc, profile, size, i - 5, true);
		}
		paintBorder(hdc, firstMenuCoord);
		if (_kbhit()) {
			button = _getch();
			switch (button) {
			case KEY_UP: {
				i--;
				firstMenuCoord.Y -= 100;
				if (i < 0) {
					firstMenuCoord.Y = firstMenuCoord.Y + (100 * items);
					i = items - 1;
				}
				if (i >= 5) {
					firstMenuCoord.Y = 550;
				}
				break;
			}
			case KEY_DOWN: {
				i++;
				firstMenuCoord.Y += 100;
				if (i > items - 1) {
					firstMenuCoord.Y = 50;
					i = 0;
				}
				if (i > 5) {
					firstMenuCoord.Y = 550;
				}
				break;
			}
			case KEY_ESCAPE: {loop = false; escape = true;  return -50000;  }
			case KEY_ENTER: {loop = false; break; }
			default: break;
			}
		}
		Sleep(100);
	}
	return i;
}
COORD menuStandart2(HWND screen, HDC hdc, COORD firstMenuCoord, HBITMAP picture, void(*pointer)(HWND screen, HDC hdc)) {
	bool loop = true;
	char button;
	while (loop) {
		paintPictures({ 0,0 }, screen, picture, hdc);
		pointer(screen, hdc);
		paintBorder(hdc, firstMenuCoord);
		if (_kbhit()) {
			button = _getch();
			switch (button) {
			case KEY_UP: {
				firstMenuCoord.Y -= 350;
				if (firstMenuCoord.Y < 250) {
					firstMenuCoord.Y = 600;
				}
				break;
			}
			case KEY_DOWN: {
				firstMenuCoord.Y += 350;
				if (firstMenuCoord.Y > 600) {
					firstMenuCoord.Y = 250;
				}
				break;
			}
			case KEY_RIGHT: {
				firstMenuCoord.X += 450;
				if (firstMenuCoord.X > 500) {
					firstMenuCoord.X = 50;
				}
				break;
			}
			case KEY_LEFT: {
				firstMenuCoord.X -= 450;
				if (firstMenuCoord.X < 50) {
					firstMenuCoord.X = 500;
				}
				break;
			}
			case KEY_ENTER: {loop = false; break; }
			default: break;
			}
		}
		Sleep(100);
	}
	return firstMenuCoord;
}
short menuPanzers(HWND screen, HDC hdc, COORD firstMenuCoord, PANZER *panzer, void(*pointer)(HWND screen, HDC hdc, PANZER *panzer, short size, short length, bool showSearch), short items, short size, bool &escape) {
	bool loop = true;
	char button;
	short i = 0;
	HBITMAP picture = NULL;
	while (loop && size > 0) {
		short tempM = atoi(panzer[i - 1].model);
		switch (tempM) {
		case 1: {picture = greenPanzer3; break; }
		case 2: {picture = brownPanzer1; break; }
		case 3: {picture = whitePanzer3; break; }
		case 4: {picture = yellowPanzer3; break; }
		case 5: {picture = greyPanzer3; break; }
		}
		paintPictures({ 0,0 }, screen, deskPanzerCharacteristics, hdc);
		if (i < 6) {
			pointer(screen, hdc, panzer, size, 0, true);
		}
		else {
			pointer(screen, hdc, panzer, size, i - 5, true);
		}
		if (i > 0) {
			paintPictures({ 220,180 }, screen, picture, hdc);
		}
		paintBorder(hdc, firstMenuCoord);
		if (_kbhit()) {
			button = _getch();
			switch (button) {
			case KEY_UP: {
				i--;
				firstMenuCoord.Y -= 90;
				if (i < 0) {
					firstMenuCoord.Y = firstMenuCoord.Y + (90 * items);
					i = items - 1;
				}
				if (i >= 5) {
					firstMenuCoord.Y = 460;
				}
				break;
			}
			case KEY_DOWN: {
				i++;
				firstMenuCoord.Y += 90;
				if (i > items - 1) {
					firstMenuCoord.Y = 10;
					i = 0;
				}
				if (i > 5) {
					firstMenuCoord.Y = 460;
				}
				break;
			}
			case KEY_ESCAPE: {loop = false; escape = true;  return 5000;  }
			case KEY_ENTER: {loop = false; break; }
			default: break;
			}
		}
		Sleep(100);
	}
	return i;
}
short menuPanzers2(HWND screen, HDC hdc, COORD firstMenuCoord, PANZER *panzer, void(*pointer)(HWND screen, HDC hdc, PANZER *panzer, short size, short length, bool showSearch), short items, short size, bool &escape) {
	bool loop = true;
	char button;
	short i = 0;
	HBITMAP picture = NULL;
	while (loop && size > 0) {
		short tempM = atoi(panzer[i - 1].model);
		switch (tempM) {
		case 1: {picture = greenPanzer3; break; }
		case 2: {picture = brownPanzer1; break; }
		case 3: {picture = whitePanzer3; break; }
		case 4: {picture = yellowPanzer3; break; }
		case 5: {picture = greyPanzer3; break; }
		}
		paintPictures({ 0,0 }, screen, deskProfileUniversalTwo, hdc);
		if (i < 4) {
			pointer(screen, hdc, panzer, size, 0, true);
		}
		else {
			pointer(screen, hdc, panzer, size, i - 4, true);
		}
		paintBorder(hdc, firstMenuCoord);
		if (_kbhit()) {
			button = _getch();
			switch (button) {
			case KEY_UP: {
				i--;
				firstMenuCoord.Y -= 100;
				if (i < 0) {
					firstMenuCoord.Y = firstMenuCoord.Y + (100 * items);
					i = items - 1;
				}
				if (i >= 4) {
					firstMenuCoord.Y = 550;
				}
				break;
			}
			case KEY_DOWN: {
				i++;
				firstMenuCoord.Y += 100;
				if (i > items - 1) {
					firstMenuCoord.Y = 150;
					i = 0;
				}
				if (i > 4) {
					firstMenuCoord.Y = 550;
				}
				break;
			}
			case KEY_ESCAPE: {loop = false; escape = true;  return 5000;  }
			case KEY_ENTER: {loop = false; break; }
			default: break;
			}
		}
		Sleep(100);
	}
	return i;
}
void wrighter(HWND screen, RECT rect, HDC hdc, HFONT font, char text[MAXSIZE], short &i, bool &loop, bool &cancel) {
	SelectObject(hdc, font);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	DrawTextA(hdc, text, strlen(text), &rect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	DeleteObject(font);
	if (_kbhit()) {
		char symbol = _getch();
		switch (symbol) {
		case KEY_UP: {break; }
		case KEY_DOWN: {break; }
		case KEY_LEFT: {break; }
		case KEY_RIGHT: {break; }
		case KEY_SPACE: {break; }
		case KEY_BACKSPACE: {
			i--;
			if (i < 0) {
				i = 0;
			}
			text[i] = '\0';
			break;
		}
		case KEY_ENTER: { if (strlen(text) > 1) { loop = false; }  break; }
		case KEY_ESCAPE: {cancel = true; loop = false; break; }
		default: {
			text[i] = symbol;
			text[i + 1] = '\0';
			i++;
			if (i > 12) {
				i = 12;
			}
			break;
		}
		}
	}
}

Profile* resizeProfile(Profile* profile, short &size, short size_n, short num){
	Profile* tempProfile;
	tempProfile = new Profile[size_n];
	short k = 0, min = size;
	for (int i = 0; i < min; i++)
		if (i != num - 1) {
			strcpy(tempProfile[k].name, profile[i].name);
			tempProfile[k++].code = profile[i].code;
		}
	size = size_n;
	delete[] profile;
	return tempProfile;
}

PANZER* resizePanzer(PANZER* panzer, short &size, short size_n, short num) {
	PANZER* tempPanzer;
	tempPanzer = new PANZER[size_n];
	short k = 0, min = size;
	for (int i = 0; i < min; i++)
		if (i != num - 1) {
			strcpy(tempPanzer[k].name, panzer[i].name);
			strcpy(tempPanzer[k].model, panzer[i].model);
			tempPanzer[k].health = panzer[i].health;
			tempPanzer[k].armor = panzer[i].armor;
			tempPanzer[k].speed = panzer[i].speed;
			tempPanzer[k].shotPower = panzer[i].shotPower;
			tempPanzer[k].commandPoints = panzer[i].commandPoints;
			tempPanzer[k].superAbility = panzer[i].superAbility;
			tempPanzer[k].battles = panzer[i].battles;
			tempPanzer[k].wins = panzer[i].wins;
			tempPanzer[k].defeat = panzer[i].defeat;
			tempPanzer[k++].code = panzer[i].code;
		}
	size = size_n;
	delete[] panzer;
	return tempPanzer;
}

char* shortToChar(short digit) {
	char *temp = new char[10];
	_itoa(digit, temp, 10);
	return temp;
}

short healthArmorBalancer(short healthArmor, short left) {
	short tempLeft = left;
	switch (healthArmor) {
	case 20: {
		tempLeft = left * 2.5;
		break;
	}
	case 40: {
		tempLeft = left * 1.25;
		break;
	}
	case 60: {
		tempLeft = left * 0.8;
		break;
	}
	case 80: {
		tempLeft = left * 0.625;
		break;
	}
	case 100: {
		tempLeft = left / 2;
		break;
	}
	}
	return tempLeft;
}
short healthArmorBalancer2(short healthArmor, short left) {
	short tempLeft = left;
	switch (healthArmor) {
	case 20: {
		tempLeft = left * 10;
		break;
	}
	case 40: {
		tempLeft = left * 5;
		break;
	}
	case 60: {
		tempLeft = left * 3.33;
		break;
	}
	case 80: {
		tempLeft = left * 2.5;
		break;
	}
	case 100: {
		tempLeft = left * 2;
		break;
	}
	}
	return tempLeft;
}
//
//загрузка модели танка в игру
HBITMAP loadPanzerSkin(PANZER *panzer, HBITMAP picture[4], short number) {
	short tempM = atoi(panzer[number].model);
	switch (tempM) {
	case 1: {
		picture[0] = greenPanzer0;
		picture[1] = greenPanzer1;
		picture[2] = greenPanzer2;
		picture[3] = greenPanzer3;
		break;
	}
	case 2: {
		picture[0] = brownPanzer2;
		picture[1] = brownPanzer3;
		picture[2] = brownPanzer0;
		picture[3] = brownPanzer1;
		break;
	}
	case 3: {
		picture[0] = whitePanzer0;
		picture[1] = whitePanzer1;
		picture[2] = whitePanzer2;
		picture[3] = whitePanzer3;
		break;
	}
	case 4: {
		picture[0] = yellowPanzer0;
		picture[1] = yellowPanzer1;
		picture[2] = yellowPanzer2;
		picture[3] = yellowPanzer3;

		break;
	}
	case 5: {
		picture[0] = greyPanzer0;
		picture[1] = greyPanzer1;
		picture[2] = greyPanzer2;
		picture[3] = greyPanzer3;
		break;
	}
	}
	return picture[4];
}

HBITMAP loadEnemySkin(ENEMY enemy, HBITMAP picture[4]) {
	short tempM = atoi(enemy.model);
	switch (tempM) {
	case 1: {
		picture[0] = brownPanzer0;
		picture[1] = brownPanzer1;
		picture[2] = brownPanzer2;
		picture[3] = brownPanzer3;
		break;
	}
	
	case 2: {
		picture[0] = greyPanzer2;
		picture[1] = greyPanzer3;
		picture[2] = greyPanzer0;
		picture[3] = greyPanzer1;
		break;
	}
	case 3: {
		picture[0] = greenPanzer0;
		picture[1] = greenPanzer1;
		picture[2] = greenPanzer2;
		picture[3] = greenPanzer3;
		break;
	}
	case 4: {
		picture[0] = whitePanzer0;
		picture[1] = whitePanzer1;
		picture[2] = whitePanzer2;
		picture[3] = whitePanzer3;
		break;
	}
	case 5: {
		picture[0] = yellowPanzer0;
		picture[1] = yellowPanzer1;
		picture[2] = yellowPanzer2;
		picture[3] = yellowPanzer3;
		break;
	}
	}
	return picture[4];
}
//
//пергрузка операторов для профилей
ostream& operator<<(ostream& os, Profile& profile) {
	os << profile.name << " " << profile.code;
	return os;
}
istream& operator >> (istream& is, Profile& profile) {
	is >> profile.name >> profile.code;
	return is;
}
//
//перегрузка операторов для танков
ostream& operator<<(ostream& os, PANZER& panzer) {
	os << panzer.code << " " << panzer.name << " " << panzer.model << " " << panzer.health << " " << panzer.armor << " " << panzer.speed << " " <<
		panzer.shotPower << " " << panzer.commandPoints << " " << panzer.superAbility << " " << panzer.battles << " " <<
		panzer.wins << " " << panzer.defeat;
	return os;
}

istream& operator >> (istream& is, PANZER& panzer) {
	is >> panzer.code >> panzer.name >> panzer.model >> panzer.health >> panzer.armor >> panzer.speed >> panzer.shotPower >>
		panzer.commandPoints >> panzer.superAbility >> panzer.battles >> panzer.wins >> panzer.defeat;
	return is;
}