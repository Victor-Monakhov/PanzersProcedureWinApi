#include "Header.h"

//
//создание профиля +
Profile* createNewProfile(HWND screen, HDC hdc, Profile *profile, short &size) {
	if (size > 0) {
		profile = resizeProfile(profile, size, size + 1, 0);
	}
	else {
		profile = new Profile[1];
		size++;
	}
	RECT rect = { 520, 150, 840, 230 };
	bool loop = true, cancel = false, busy = false;
	short i = 0;
	profile[size - 1].code = 0;
	for (short j = 0; j < size - 1; j++) {
		if (profile[size - 1].code == profile[j].code) {
			profile[size - 1].code++;
			j = -1;
		}	
	}
	while (loop) {
		paintPictures({ 0,0 }, screen, deskProfileName, hdc);
		paintStartMenu(screen, hdc);
		HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		SelectObject(hdc, newFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 520, 60, "ВВЕДИТЕ ИМЯ:", strlen("ВВЕДИТЕ ИМЯ:"));
		wrighter(screen, rect, hdc, newFont, profile[size - 1].name, i, loop, cancel);
		if (cancel == true) {
			profile = resizeProfile(profile, size, size - 1, size);
		}
		profile[size - 1].name[0] = toupper(profile[size - 1].name[0]);
		for (short j = 0; j < size - 1; j++) {
			if (strcmp(profile[j].name, profile[size - 1].name) == 0) {
				HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
				SelectObject(hdc, brushGrey);
				Rectangle(hdc, 500, 250, 900, 330);
				DeleteObject(brushGrey);
				SetTextColor(hdc, RGB(255, 0, 0));
				TextOutA(hdc, 520, 260, "имя занято", strlen("имя занято"));
				busy = true;
				loop = true;
			}
		}
		DeleteObject(newFont);
		paintBorder(hdc, { 500, 50 });
		Sleep(100);
	}
	return profile;
}
//
//демонстрация всех профилей +
void showProfiles(HWND screen, HDC hdc, Profile *profile, short size, short length, bool showSearch) {
	paintStartMenu(screen, hdc);
	COORD temp = { 500, 150 };
	short length2 = size;
	HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	if (size > 5) {
		SelectObject(hdc, brushGrey);
		Ellipse(hdc, 650, 650, 670, 670);
		Ellipse(hdc, 690, 650, 710, 670);
		Ellipse(hdc, 730, 650, 750, 670);
		DeleteObject(brushGrey);
	}
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	if (showSearch == true) {
		TextOutA(hdc, 520, 60, "ПОИСК:", strlen("ПОИСК:"));
	}
	if (size > 5) {
		length2 = length + 5;
	}
	for (short i = length; i < length2; i++) {
		TextOutA(hdc, temp.X + 10, temp.Y + 10, profile[i].name, strlen(profile[i].name));
		if (temp.Y < 550) {
			temp.Y += 100;
		}	
	}
	DeleteObject(newFont);
}
//
//поиск профиля +
Profile *searchProfile(HWND screen, HDC hdc, Profile *profile, short size, short &tempSize) {
	bool loop = true, cancel = false;
	short i = 0;
	char tempProf[MAXSIZE] = "\0";
	while (loop) {
		paintPictures({ 0,0 }, screen, deskProfileUniversal, hdc);
		paintStartMenu(screen, hdc);
		showProfiles(screen, hdc, profile, size, 0, false);
		paintBorder(hdc, { 500, 50 });
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		wrighter(screen, { 520,60,900,130 }, hdc, newFont, tempProf, i, loop, cancel);
		if (cancel == true) {
			strcpy(tempProf, "\0");
		}
		Sleep(100);
	}
	short k = 0;
	char *p;
	tempSize = size;
	Profile *tempProfile = new Profile [tempSize];
	for (short j = 0; j < size; j++) {
		strcpy(tempProfile[j].name, profile[j].name);
		tempProfile[j].code = profile[j].code;
	}
	for (short j = 0; j < tempSize; ++j) {
		p = strstr(tempProfile[j].name, tempProf);
		if (p == nullptr) {
			tempProfile = resizeProfile(tempProfile, tempSize, tempSize - 1, j+1);
			--j;
		}
	}
	return tempProfile;
}
//
//удаление профиля
Profile* deleteProfile(HWND screen, HDC hdc, COORD secondMenuCoord, Profile *profile, short &size) {
	if (size > 0) {
		bool escape = false;
		while (!escape) {
			short number = 0;
			number = menuProfile(screen, hdc, secondMenuCoord, profile, showProfiles, size + 1, size, escape);
			if (number == 0) {
				Profile* tempProfile;
				short tempSize = 0;
				escape = false;
				tempProfile = searchProfile(screen, hdc, profile, size, tempSize);
				number = menuProfile(screen, hdc, secondMenuCoord, tempProfile, showProfiles, tempSize + 1, tempSize, escape);
				if (number == 0) { continue; }
				if (number > 0 && size > 0 && escape == false) {
					for (int i = 0; i < size; i++) {
						if (strcmp(profile[i].name, tempProfile[number - 1].name) == 0) {
							savePanzersAfterDelete(profile[i].code);
							profile = resizeProfile(profile, size, size - 1, i + 1);
							number = 0;
							break;
						}
						if (size <= 0) {
							escape = true;
						}
					}
				}
			}
			if (number > 0 && size > 0 && escape == false) {
				savePanzersAfterDelete(profile[number - 1].code);
				profile = resizeProfile(profile, size, size - 1, number);
			}
			if (size <= 0) {
				escape = true;
			}
		}
	}
	return profile;
}
//
//выбор профиля
Profile* enterProfile(HWND screen, HDC hdc, COORD secondMenuCoord, Profile *profile, short &size) {
	if (size > 0) {
		bool escape = false;
		while (!escape) {
			short number = 0;
			number = menuProfile(screen, hdc, secondMenuCoord, profile, showProfiles, size + 1, size, escape);
			if (number == 0) {
				Profile* tempProfile;
				short tempSize = 0;
				escape = false;
				tempProfile = searchProfile(screen, hdc, profile, size, tempSize);
				number = menuProfile(screen, hdc, secondMenuCoord, tempProfile, showProfiles, tempSize + 1, tempSize, escape);
				if (number == 0) { continue; }
				if (number > 0 && size > 0 && escape == false) {
					for (int i = 0; i < size; i++) {
						if (strcmp(profile[i].name, tempProfile[number - 1].name) == 0) {
							profileMain(screen, hdc, profile, profile[i].code);
							number = 0;
							break;
						}
						if (size <= 0) {
							escape = true;
						}
					}
				}
			}
			if (number > 0 && size > 0 && escape == false) {
				profileMain(screen, hdc, profile, profile[number-1].code);
			}
			if (size <= 0) {
				escape = true;
			}
		}
	}
	return profile;
}
//
//имя профиля
Profile* profileName(HWND screen, HDC hdc, COORD secondMenuCoord, Profile *profile, short &size) {
	if (size > 0) {
		bool escape = false;
		while (!escape) {
			short number = 0;
			number = menuProfile(screen, hdc, secondMenuCoord, profile, showProfiles, size + 1, size, escape);
			if (number == 0) {
				Profile* tempProfile;
				short tempSize = 0;
				escape = false;
				tempProfile = searchProfile(screen, hdc, profile, size, tempSize);
				number = menuProfile(screen, hdc, secondMenuCoord, tempProfile, showProfiles, tempSize + 1, tempSize, escape);
				if (number == 0) { continue; }
				if (number > 0 && size > 0 && escape == false) {
					for (int i = 0; i < size; i++) {
						if (strcmp(profile[i].name, tempProfile[number - 1].name) == 0) {
							profile = changeProfileName(screen, hdc, profile, size, i);
							number = 0;
							break;
						}
						if (size <= 0) {
							escape = true;
						}
					}
				}
			}
			if (number > 0 && size > 0 && escape == false) {
				profile = changeProfileName(screen, hdc, profile, size, number - 1);
			}
			if (size <= 0) {
				escape = true;
			}
		}
	}
	return profile;
}
//
//смена имени профиля
Profile* changeProfileName(HWND screen, HDC hdc, Profile *profile, short &size, short number) {
	RECT rect = { 520, 150, 840, 230 };
	bool loop = true, cancel = false, busy = false;
	char tempName[MAXSIZE];
	strcpy(tempName, profile[number].name);
	short i = 0;
	while (loop) {
		paintPictures({ 0,0 }, screen, deskProfileUniversal, hdc);
		paintStartMenu(screen, hdc);
		HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, 500, 50, 900, 130);
		Rectangle(hdc, 500, 150, 900, 230);
		DeleteObject(brushGrey);
		SelectObject(hdc, newFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 520, 60, "НОВОЕ ИМЯ:", strlen("НОВОЕ ИМЯ:"));
		wrighter(screen, rect, hdc, newFont, profile[number].name, i, loop, cancel);
		if (cancel == true) {
			strcpy(profile[number].name, tempName);
		}
		profile[number].name[0] = toupper(profile[number].name[0]);
		for (short j = 0; j < size; j++) {
			if (strcmp(profile[j].name, profile[number].name) == 0 && j != number) {
				HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
				SelectObject(hdc, brushGrey);
				Rectangle(hdc, 500, 250, 900, 330);
				DeleteObject(brushGrey);
				SetTextColor(hdc, RGB(255, 0, 0));
				TextOutA(hdc, 520, 260, "профиль занят", strlen("профиль занят"));
				busy = true;
				loop = true;
			}
		}
		DeleteObject(newFont);
		paintBorder(hdc, { 500, 50 });
		Sleep(100);
	}
	return profile;
}
//
//сортировка профилей
Profile* sortProfilesName(Profile *profile, short size) {
	for (short i = 0; i < size; i++) {
		for (short j = i + 1; j < size; j++) {
			if (strcmp(profile[i].name, profile[j].name) > 0) {
				swap(profile[i].name, profile[j].name);
				swap(profile[i].code, profile[j].code);
			}
		}
	}
	return profile;
}
//
//сохранение профилей
void saveProfiles(Profile* profile, short size) {
	fstream memmoryProfiles;
	memmoryProfiles.open("memmoryProfiles.txt", ios::out);
	for (short i = 0; i < size; i++) {
		memmoryProfiles <<profile[i];
		if (i < size - 1) { memmoryProfiles << endl; }
	}
	memmoryProfiles.close();
}
//
//инициализация профилей
Profile* initProfiles(Profile* profile, short &size) {
	fstream memmoryProfiles;
	memmoryProfiles.open("memmoryProfiles.txt", ios::in);
	//memmoryProfiles.seekg(11, ios::beg);
	while (!memmoryProfiles.eof() && memmoryProfiles.is_open()) {
		if (size > 0) {
			profile = resizeProfile(profile, size, size + 1, 0);
		}
		else {
			profile = new Profile[1];
			size++;
		}
		memmoryProfiles >> profile[size - 1];
		if (strlen(profile[size - 1].name) < 2) {
			profile = resizeProfile(profile, size, size - 1, size);
		}
	}
	memmoryProfiles.close();
	return profile;
}
//
//главная функция базы профиля
void profileMain(HWND screen, HDC hdc, Profile *profile, short element) {
	short size = 0;
	bool work = true;
	PANZER *panzer = nullptr;
	panzer = initPanzers(panzer, size, element);
	COORD firstMenuCoord = { 50,250 };
	COORD secondMenuCoord = { 50,420 };
	COORD thirdMenuCoord = { 500,10 };
	COORD y = { 0,0 };
	while (work) {
		y = menuStandart2(screen, hdc, firstMenuCoord, deskProfileMenu, paintProfileMenu);
		if (y.X == 50 && y.Y == 250){
			panzer = play(screen, hdc, panzer, size);
			if (size > 0) {
				savePanzers(panzer, size, element);
			}
			continue;
		}
		if (y.X == 500 && y.Y == 250) {
			panzer = myPanzers(screen, hdc, secondMenuCoord, thirdMenuCoord, panzer, profile, size, element);
			continue;
		}
		if (y.X == 50 && y.Y == 600) {
			bool loop = true;
			while (loop) {
				paintPictures({ 0,0 }, screen, deskStatistics, hdc);
				paintBorder(hdc, { 285, 560 });
				paintStatistics(screen, hdc, panzer, size);
				if (_kbhit()) {
					short key = _getch();
					if (key == KEY_ENTER) {
						loop = false;
					}
				}
				Sleep(300);
			}
			continue;
		}
		if (y.X == 500 && y.Y == 600) {
			work = false;
			delete[]panzer;
			continue;
		}
	}
	//saveProfiles(profile, size);
}
//
//демонстрация всех танков
void showPanzers(HWND screen, HDC hdc, PANZER *panzer, short size, short length, bool showSearch) {
	paintMyPanzers(screen, hdc);
	COORD temp = { 490, 100 };
	short length2 = size;
	HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, brushGrey);
	if (size > 5) {
		Ellipse(hdc, 650, 560, 670, 580);
		Ellipse(hdc, 690, 560, 710, 580);
		Ellipse(hdc, 730, 560, 750, 580);
	}
	DeleteObject(brushGrey);
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	if (showSearch == true) {
		TextOutA(hdc, 510, 20, "ПОИСК:", strlen("ПОИСК:"));
	}
	if (size > 5) {
		length2 = length + 5;
	}
	for (short i = length; i < length2; i++) {
		TextOutA(hdc, temp.X + 10, temp.Y + 10, panzer[i].name, strlen(panzer[i].name));
		if (temp.Y < 460) {
			temp.Y += 90;
		}
	}
	DeleteObject(newFont);
}
void showPanzers2(HWND screen, HDC hdc, PANZER *panzer, short size, short length, bool showSearch) {
	paintEnemyPower(screen, hdc);
	COORD temp = { 500, 250 };
	short length2 = size;
	HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, brushGrey);
	if (size > 5) {
		Ellipse(hdc, 650, 650, 670, 670);
		Ellipse(hdc, 690, 650, 710, 670);
		Ellipse(hdc, 730, 650, 750, 670);
	}
	DeleteObject(brushGrey);
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 520, 60, "ВЫБОР ТАНКА:", strlen("ВЫБОР ТАНКА"));
	SetTextColor(hdc, RGB(255, 255, 255));
	if (showSearch == true) {
		TextOutA(hdc, 520, 160, "ПОИСК:", strlen("ПОИСК:"));
	}
	if (size > 4) {
		length2 = length + 4;
	}
	for (short i = length; i < length2; i++) {
		TextOutA(hdc, temp.X + 10, temp.Y + 10, panzer[i].name, strlen(panzer[i].name));
		if (temp.Y < 550) {
			temp.Y += 100;
		}
	}
	DeleteObject(newFont);
}
//
//создание танка-----------------------------------------------------------------------------//
PANZER *panzerCreater(HWND screen, HDC hdc, PANZER *panzer, Profile *profile, short &size, bool newPanzer, short number, short element) {
	short step;
	if (newPanzer == true) {
		if (size > 0) {
			panzer = resizePanzer(panzer, size, size + 1, 0);
		}
		else {
			panzer = new PANZER[1];
			size++;
		}
		panzer[size - 1].code = element;
		step = 0;
	}
	else {
		step = 2;
	}
	while (step < 6) {
		switch (step) {
		case 0: {
			panzer = panzerName(screen, hdc, panzer, size, step);
			break;
		}
		case 1: {
			panzer = panzerModel(screen, hdc, panzer, size, step);
			break;
		}
		case 2: {
			panzer = panzerHealth(screen, hdc, panzer, size, step, newPanzer, number);
			break;
		}
		case 3: {
			panzer = panzerArmor(screen, hdc, panzer, size, step, newPanzer, number);
			break;
		}
		case 4: {
			panzer = panzerSpeed(screen, hdc, panzer, size, step, newPanzer, number);
			break;
		}
		case 5: {
			panzer = panzerPower(screen, hdc, panzer, size, step, newPanzer, number);
			break;
		}
		}
	}
	return panzer;
}
//
//название танка+
PANZER *panzerName(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step) {
	RECT rect = { 510, 100, 900, 180 };
	bool loop = true, cancel = false, busy = false;
	short i = 0;
	while (loop) {
		paintPictures({ 0,0 }, screen, deskPanzerNameModel, hdc);
		paintMyPanzers(screen, hdc);
		paintPanzerNameModel(hdc);
		paintBorder(hdc, { 500, 10 });
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		SelectObject(hdc, newFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		wrighter(screen, rect, hdc, newFont, panzer[size - 1].name, i, loop, cancel);
		if (cancel == true) {
			panzer = resizePanzer(panzer, size, size - 1, size);
			step = 5000;
		}
		panzer[size - 1].name[0] = toupper(panzer[size - 1].name[0]);
		for (short j = 0; j < size - 1; j++) {
			if (strcmp(panzer[j].name, panzer[size - 1].name) == 0) {
				HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
				SelectObject(hdc, brushGrey);
				Rectangle(hdc, 490, 190, 910, 270);
				DeleteObject(brushGrey);
				SetTextColor(hdc, RGB(255, 0, 0));
				TextOutA(hdc, 510, 190, "название занято", strlen("название занято"));
				DeleteObject(newFont);
				busy = true;
				loop = true;
			}
		}
		DeleteObject(newFont);
		Sleep(100);
	}
	++step;
	return panzer;
}
//
//модель танка+
PANZER *panzerModel(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step) {
	HBITMAP picture = greenPanzer3;
	bool loop = true, next = false;
	COORD border = { 500, 280 };
	while (loop) {
		short tempM = atoi(panzer[size - 1].model);
		paintPictures({ 0,0 }, screen, deskPanzerNameModel, hdc);
		paintMyPanzers(screen, hdc);
		paintPanzerNameModel(hdc);
		paintBorder(hdc, border);
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		SelectObject(hdc, newFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 510, 110, panzer[size - 1].name, strlen(panzer[size - 1].name));
		TextOutA(hdc, 685, 380, panzer[size - 1].model, strlen(panzer[size - 1].model));
		short key = 0;
		paintPictures({ 220, 180 }, screen, picture, hdc);
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case KEY_RIGHT: {
				if (border.Y == 280) {
					tempM++;
					if (tempM > 5) { tempM = 1; }
					_itoa(tempM, panzer[size - 1].model, 10);
					TextOutA(hdc, 840, 380, ">>>", strlen(">>>"));
				}
				break;
			}
			case KEY_LEFT: {
				if (border.Y == 280) {
					tempM--;
					if (tempM < 1) { tempM = 5; }
					_itoa(tempM, panzer[size - 1].model, 10);
					TextOutA(hdc, 510, 380, "<<<", strlen("<<<"));
				}
				break;
			}
			case KEY_ESCAPE: {
				if (next) {
					border = { 500, 280 };
					next = false;
					continue;
				}
				loop = false;
				--step;
				break;
			}
			case KEY_ENTER: {
				if (!next) {
					border = { 500, 460 };
					next = true;
					continue;
				}
				loop = false;
				++step;
				break;
			}
			}
		}
		switch (tempM) {
		case 1: {picture = greenPanzer3; break; }
		case 2: {picture = brownPanzer1; break; }
		case 3: {picture = whitePanzer3; break; }
		case 4: {picture = yellowPanzer3; break; }
		case 5: {picture = greyPanzer3; break; }
		}
		DeleteObject(newFont);
		Sleep(100);
	}
	return panzer;
}
//
//здоровье танка+
PANZER *panzerHealth(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step, bool newPanzer, short number) {
	if (newPanzer == true) {
		number = size - 1;
	}
	HBITMAP picture[4];
	bool loop = true;
	picture[4] = loadPanzerSkin(panzer, picture, number);
	while (loop) {
		paintPictures({ 0,0 }, screen, deskPanzerCharacteristics, hdc);
		paintPictures({ 220, 180 }, screen, picture[3], hdc);
		paintPanzerCharacteristics(hdc, panzer, number);
		paintMyPanzers(screen, hdc);
		paintBorder(hdc, { 500, 100 });
		short key = 0;
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case KEY_RIGHT: {
				if (panzer[number].commandPoints > 0 && panzer[number].health < 100) {
					panzer[number].health += 20;
					panzer[number].commandPoints -= 1;
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOutA(hdc, 870, 110, ">>", strlen(">>"));
				}
				break;
			}
			case KEY_LEFT: {
				if (panzer[number].health > 20) {
					panzer[number].health -= 20;
					panzer[number].commandPoints += 1;
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOutA(hdc, 500, 110, "<<", strlen("<<"));
				}
				break;
			}
			case KEY_ESCAPE: {
				loop = false;
				if (newPanzer == false) {
					step = 5000;
				}
				--step;
				break;
			}
			case KEY_DOWN: {
				loop = false;
				++step;
				break;
			}
			case KEY_ENTER: {
				loop = false;
				step = 5000;
				break;
			}
			}
		}
		Sleep(200);
	}
	return panzer;
}
//
//броня танка+
PANZER *panzerArmor(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step, bool newPanzer, short number) {
	if (newPanzer == true) {
		number = size - 1;
	}
	HBITMAP picture[4];
	bool loop = true;
	picture[4] = loadPanzerSkin(panzer, picture, number);
	while (loop) {
		paintPictures({ 0,0 }, screen, deskPanzerCharacteristics, hdc);
		paintMyPanzers(screen, hdc);
		paintPanzerCharacteristics(hdc, panzer, number);
		paintPictures({ 220, 180 }, screen, picture[3], hdc);
		paintBorder(hdc, { 500, 190 });
		short key = 0;
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case KEY_RIGHT: {
				if (panzer[number].armor < 100 && panzer[number].commandPoints > 0) {
					panzer[number].armor += 20;
					panzer[number].commandPoints -= 1;
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOutA(hdc, 870, 200, ">>", strlen(">>"));
				}
				break;
			}
			case KEY_LEFT: {
				if (panzer[number].armor > 20) {
					panzer[number].armor -= 20;
					panzer[number].commandPoints += 1;
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOutA(hdc, 500, 200, "<<", strlen("<<"));
				}
				break;
			}
			case KEY_UP: {
				loop = false;
				--step;
				break;
			}
			case KEY_DOWN: {
				loop = false;
				++step;
				break;
			}
			case KEY_ESCAPE: {
				loop = false;
				if (newPanzer == false) {
					step = 5000;
				}
				step -= 2;
				break;
			}
			case KEY_ENTER: {
				loop = false;
				step = 5000;
				break;
			}
			}
		}
		Sleep(200);
	}
	return panzer;
}
//
//скорость танка+
PANZER *panzerSpeed(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step, bool newPanzer, short number) {
	if (newPanzer == true) {
		number = size - 1;
	}
	HBITMAP picture[4];
	bool loop = true;
	picture[4] = loadPanzerSkin(panzer, picture, number);
	while (loop) {
		paintPictures({ 0,0 }, screen, deskPanzerCharacteristics, hdc);
		paintMyPanzers(screen, hdc);
		paintPanzerCharacteristics(hdc, panzer, number);
		paintPictures({ 220, 180 }, screen, picture[3], hdc);
		paintBorder(hdc, { 500, 280 });
		short key = 0;
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case KEY_RIGHT: {
				if (panzer[number].speed < 22 && panzer[number].commandPoints > 0) {
					panzer[number].speed += 3;
					panzer[number].commandPoints -= 1;
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOutA(hdc, 870, 290, ">>", strlen(">>"));
				}
				break;
			}
			case KEY_LEFT: {
				if (panzer[number].speed > 10) {
					panzer[number].speed -= 3;
					panzer[number].commandPoints += 1;
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOutA(hdc, 500, 290, "<<", strlen("<<"));
				}
				break;
			}
			case KEY_ESCAPE: {
				loop = false;
				if (newPanzer == false) {
					step = 5000;
				}
				step -= 3;
				break;
			}
			case KEY_ENTER: {
				loop = false;
				step = 5000;
				break;
			}
			case KEY_DOWN: {
				loop = false;
				++step;
				break;
			}
			case KEY_UP: {
				loop = false;
				--step;
				break;
			}
			}
		}
		Sleep(200);
	}
	return panzer;
}
//
//сила выстрела танка +
PANZER *panzerPower(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step, bool newPanzer, short number) {
	if (newPanzer == true) {
		number = size - 1;
	}
	HBITMAP picture[4];
	bool loop = true;
	picture[4] = loadPanzerSkin(panzer, picture, number);
	while (loop) {
		paintPictures({ 0,0 }, screen, deskPanzerCharacteristics, hdc);
		paintMyPanzers(screen, hdc);
		paintPanzerCharacteristics(hdc, panzer, number);
		paintPictures({ 220, 180 }, screen, picture[3], hdc);
		paintBorder(hdc, { 500, 370 });
		short key = 0;
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case KEY_RIGHT: {
				if (panzer[number].shotPower < 5 && panzer[number].commandPoints>0) {
					panzer[number].shotPower += 1;
					panzer[number].commandPoints -= 1;
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOutA(hdc, 870, 380, ">>", strlen(">>"));
				}
				break;
			}
			case KEY_LEFT: {
				if (panzer[number].shotPower > 1) {
					panzer[number].shotPower -= 1;
					panzer[number].commandPoints += 1;
					SetTextColor(hdc, RGB(255, 255, 255));
					TextOutA(hdc, 500, 380, "<<", strlen("<<"));
				}
				break;
			}
			case KEY_UP: {
				loop = false;
				--step;
				break;
			}
			case KEY_ENTER: {
				loop = false;
				step = 5000;
				break;
			}
			case KEY_ESCAPE: {
				loop = false;
				if (newPanzer == false) {
					step = 5000;
				}
				step -= 4;
				break;
			}
			}
		}
	//	DeleteObject(newFont);
		Sleep(200);
	}
	return panzer;
}
//
//таланты-------------------------------------------------------------------------------------//
//
//поиск танка+
PANZER *searchPanzer(HWND screen, HDC hdc, PANZER *panzer, short size, short &tempSize) {
	bool loop = true, cancel = false;
	short i = 0;
	char tempP[MAXSIZE] = "\0";
	while (loop) {
		paintPictures({ 0,0 }, screen, deskPanzerCharacteristics, hdc);
		paintMyPanzers(screen, hdc);
		showPanzers(screen, hdc, panzer, size, 0, false);
		paintBorder(hdc, { 500, 10 });
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		wrighter(screen, { 510,20,900,90 }, hdc, newFont, tempP, i, loop, cancel);
		if (cancel == true) {
			strcpy(tempP, "\0");
		}
		Sleep(100);
	}
	short k = 0;
	char *p;
	tempSize = size;
	PANZER *tempPanzer = new PANZER[tempSize];
	for (short j = 0; j < size; j++) {
		strcpy(tempPanzer[j].name, panzer[j].name);
		strcpy(tempPanzer[j].model, panzer[j].model);
		tempPanzer[j].health = panzer[j].health;
		tempPanzer[j].armor = panzer[j].armor;
		tempPanzer[j].speed = panzer[j].speed;
		tempPanzer[j].shotPower = panzer[j].shotPower;
		tempPanzer[j].commandPoints = panzer[j].commandPoints;
		tempPanzer[j].superAbility = panzer[j].superAbility;
		tempPanzer[j].battles = panzer[j].battles;
		tempPanzer[j].wins = panzer[j].wins;
		tempPanzer[j].defeat = panzer[j].defeat;
		tempPanzer[j].code = panzer[j].code;
	}
	for (short j = 0; j < tempSize; ++j) {
		p = strstr(tempPanzer[j].name, tempP);
		if (p == nullptr) {
			tempPanzer = resizePanzer(tempPanzer, tempSize, tempSize - 1, j + 1);
			--j;
		}
	}
	return tempPanzer;
}
PANZER *searchPanzer2(HWND screen, HDC hdc, PANZER *panzer, short size, short &tempSize) {
	bool loop = true, cancel = false;
	short i = 0;
	char tempP[MAXSIZE] = "\0";
	while (loop) {
		paintPictures({ 0,0 }, screen, deskProfileUniversalTwo, hdc);
		paintEnemyPower(screen, hdc);
		showPanzers2(screen, hdc, panzer, size, 0, false);
		paintBorder(hdc, { 500, 150 });
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		wrighter(screen, { 520,160,900,230 }, hdc, newFont, tempP, i, loop, cancel);
		if (cancel == true) {
			strcpy(tempP, "\0");
		}
		Sleep(100);
	}
	short k = 0;
	char *p;
	tempSize = size;
	PANZER *tempPanzer = new PANZER[tempSize];
	for (short j = 0; j < size; j++) {
		strcpy(tempPanzer[j].name, panzer[j].name);
		strcpy(tempPanzer[j].model, panzer[j].model);
		tempPanzer[j].health = panzer[j].health;
		tempPanzer[j].armor = panzer[j].armor;
		tempPanzer[j].speed = panzer[j].speed;
		tempPanzer[j].shotPower = panzer[j].shotPower;
		tempPanzer[j].commandPoints = panzer[j].commandPoints;
		tempPanzer[j].superAbility = panzer[j].superAbility;
		tempPanzer[j].battles = panzer[j].battles;
		tempPanzer[j].wins = panzer[j].wins;
		tempPanzer[j].defeat = panzer[j].defeat;
		tempPanzer[j].code = panzer[j].code;
	}
	for (short j = 0; j < tempSize; ++j) {
		p = strstr(tempPanzer[j].name, tempP);
		if (p == nullptr) {
			tempPanzer = resizePanzer(tempPanzer, tempSize, tempSize - 1, j + 1);
			--j;
		}
	}
	return tempPanzer;
}
//
//раздел мои танки +
PANZER *myPanzers(HWND screen, HDC hdc, COORD secondMenuCoord, COORD thirdMenuCoord, PANZER *panzer, Profile *profile, short &size, short element) {
	bool loop = true;
	while (loop) {
		short number;
		number = menuStandart(screen, hdc, secondMenuCoord, deskPoligonMenu, paintMyPanzers, 3, 90);
		switch (number) {
		case 420: {
			if (size > 0) {
				panzer = enterPoligon(screen, hdc, thirdMenuCoord, panzer, size);
				savePanzers(panzer, size, element);
			}
			break;
		}
		case 510: {
			panzer = panzerCreater(screen, hdc, panzer, profile, size, true, 0, element);
			panzer = sortPanzersName(panzer, size);
			if (size > 0) {
				savePanzers(panzer, size, element);
			}
			break;
		}
		case 600: {
			if (size > 0) {
				panzer = deletePanzer(screen, hdc, thirdMenuCoord, panzer, size);
				savePanzers(panzer, size, element);
			}
			break;
		}
		case 500: {loop = false; }
		}
	}
	return panzer;
}
//
//вход в полигон
PANZER *enterPoligon(HWND screen, HDC hdc, COORD thirdMenuCoord, PANZER *panzer, short &size) {
	bool escape = false;
	if (size > 0) {
		while (!escape) {
			short number;
			number = menuPanzers(screen, hdc, thirdMenuCoord, panzer, showPanzers, size + 1, size, escape);
			if (number == 0) {
				PANZER* tempPanzer;
				short tempSize = 0;
				escape = false;
				tempPanzer = searchPanzer(screen, hdc, panzer, size, tempSize);
				number = menuPanzers(screen, hdc, thirdMenuCoord, tempPanzer, showPanzers, tempSize + 1, tempSize, escape);
				if (number == 0) { continue; }
				if (number > 0 && size > 0 && escape == false) {
					for (int i = 0; i < size; i++) {
						if (strcmp(panzer[i].name, tempPanzer[number - 1].name) == 0) {
							poligon(screen, hdc, panzer, i, size);
							number = 0;
							break;
						}
						if (size <= 0) {
							escape = true;
						}
					}
				}
			}
			if (number > 0 && size > 0 && escape == false) {
				poligon(screen, hdc, panzer, number - 1, size);
			}
			if (size <= 0) {
				escape = true;
			}
		}
	}
	return panzer;
}
//
//удаление танка
PANZER *deletePanzer(HWND screen, HDC hdc, COORD thirdMenuCoord, PANZER *panzer, short &size) {
	bool escape = false;
	if (size > 0) {
		while (!escape) {
		short number;
		number = menuPanzers(screen, hdc, thirdMenuCoord, panzer, showPanzers, size + 1, size, escape);
		if (number == 0) {
			PANZER* tempPanzer;
			short tempSize = 0;
			escape = false;
			tempPanzer = searchPanzer(screen, hdc, panzer, size, tempSize);
			number = menuPanzers(screen, hdc, thirdMenuCoord, tempPanzer, showPanzers, tempSize + 1, tempSize, escape);
			if (number == 0) { continue; }
				if (number > 0 && size > 0 && escape == false) {
					for (int i = 0; i < size; i++) {
						if (strcmp(panzer[i].name, tempPanzer[number - 1].name) == 0) {
							panzer = resizePanzer(panzer, size, size - 1, i + 1);
							number = 0;
							break;
						}
						if (size <= 0) {
							escape = true;
						}
					}
				}
			}
			if (number > 0 && size > 0 && escape == false) {
				panzer = resizePanzer(panzer, size, size - 1, number);
			}
			if (size <= 0) {
				escape = true;
			}
		}
	}
	return panzer;
}
//
//полигон
void poligon(HWND screen, HDC hdc, PANZER *panzer, short number, short size) {
	ENEMY temp;
	HBITMAP picture[4] = { 0,0,0,0 };
	picture[4] = loadPanzerSkin(panzer, picture, number);
	COORD firstMenuCoord = {500, 10};
	COORD playerCoords = { 220, 180 };
	COORD tempPlayerCoords = { 220, 180 };
	COORD playerPerimCoords[200] = { 220, 180 };
	short turnPlayer = 3, playerHealth = panzer[number].health, playerArmor = panzer[number].armor, playerBullet = 1;
	short enemyTopHealth = 0, enemyBotHealth = 0, blueBaseHealth = 0, enemyBotArmor = 0, enemyTopArmor = 0;
	short **field = new short*[WID_HEIG + TOP_Y];
	poligonField(field);
	bool loop = true;
	while (loop) {
		playerPerimCoords[200] = panzerPerimCoord(playerCoords, playerPerimCoords);
		backNull(field, tempPlayerCoords);
		backPlayer(field, playerCoords);
		tempPlayerCoords = playerCoords;
		paintPictures({ 0,0 }, screen, deskPanzerMenu, hdc);
		paintUnit(playerCoords, screen, picture[0], picture[1], picture[2], picture[3], hdc, turnPlayer);
		paintHealthLeftTeam(playerCoords, screen, hdc, panzer, temp, number, turnPlayer, panzer[number].health, panzer[number].armor);
		paintMyPanzers(screen, hdc);
		paintPoligonMenu(hdc, panzer, number);
		paintBorder(hdc, { 500, 460 });
		playerControl(screen, hdc, playerCoords, playerPerimCoords, panzer, field, turnPlayer, playerHealth, playerBullet,
			enemyTopHealth, enemyBotHealth, blueBaseHealth, enemyBotArmor, enemyTopArmor, panzer[number].speed, loop, size, number);
		Sleep(80);
	}
}
//
//вход в сражение
PANZER *enterFight(HWND screen, HDC hdc, PANZER *panzer, ENEMY enemyTop, ENEMY enemyBot, ENEMY allyBot, short &size) {
	bool escape = false;
	if (size > 0) {
		while (!escape) {
			short number;
			number = menuPanzers2(screen, hdc, { 500, 150 }, panzer, showPanzers2, size + 1, size, escape);
			if (number == 0) {
				PANZER* tempPanzer;
				short tempSize = 0;
				escape = false;
				tempPanzer = searchPanzer2(screen, hdc, panzer, size, tempSize);
				number = menuPanzers2(screen, hdc, { 500, 150 }, tempPanzer, showPanzers2, tempSize + 1, tempSize, escape);
				if (number == 0) { continue; }
				if (number > 0 && size > 0 && escape == false) {
					for (int i = 0; i < size; i++) {
						if (strcmp(panzer[i].name, tempPanzer[number - 1].name) == 0) {
							panzer = game(screen, hdc, panzer,enemyTop, enemyBot, allyBot, i, size);
							number = 0;
							break;
						}
						if (size <= 0) {
							escape = true;
						}
					}
				}
			}
			if (number > 0 && size > 0 && escape == false) {
				panzer = game(screen, hdc, panzer, enemyTop, enemyBot,allyBot, number - 1, size);
			}
			if (size <= 0) {
				escape = true;
			}
		}
	}
	return panzer;
}
//
//раздел играть
PANZER *play(HWND screen, HDC hdc, PANZER *panzer, short size) {
	ENEMY enemyTop, enemyBot, allyBot;
	bool loop = true;
	while (loop) {
		if (size > 0) {
			short y;
			y = menuStandart(screen, hdc, { 50,150 }, startDeskTwo, paintEnemyPower, 5, 100);
			switch (y) {
			case 150: {
				strcpy(enemyTop.name, "СЛАБЫЙ 1");
				strcpy(enemyTop.model, shortToChar(rand() % 2 + 1));
				enemyTop.health = 60;
				enemyTop.armor = 40;
				enemyTop.speed = 10;
				enemyTop.shotPower = 2;
				enemyTop.superAbility = 0;
				strcpy(enemyBot.name, "СЛАБЫЙ 2");
				strcpy(enemyBot.model, shortToChar(rand() % 2 + 1));
				enemyBot.health = 60;
				enemyBot.armor = 40;
				enemyBot.speed = 10;
				enemyBot.shotPower = 2;
				enemyBot.superAbility = 0;
				strcpy(allyBot.name, "СОЮЗНИК");
				strcpy(allyBot.model, shortToChar(rand() % 3 + 3));
				allyBot.health = 60;
				allyBot.armor = 40;
				allyBot.speed = 10;
				allyBot.shotPower = 2;
				allyBot.superAbility = 0;
				panzer = enterFight(screen, hdc, panzer, enemyTop, enemyBot, allyBot, size);
				break;
			}
			case 250: {
				strcpy(enemyTop.name, "СРЕНИЙ 1");
				strcpy(enemyTop.model, shortToChar(rand() % 2 + 1));
				enemyTop.health = 60;
				enemyTop.armor = 60;
				enemyTop.speed = 13;
				enemyTop.shotPower = 3;
				enemyTop.superAbility = 0;
				strcpy(enemyBot.name, "СРЕДНИЙ 2");
				strcpy(enemyBot.model, shortToChar(rand() % 2 + 1));
				enemyBot.health = 60;
				enemyBot.armor = 60;
				enemyBot.speed = 13;
				enemyBot.shotPower = 3;
				enemyBot.superAbility = 0;
				strcpy(allyBot.name, "СОЮЗНИК");
				strcpy(allyBot.model, shortToChar(rand() % 3 + 3));
				allyBot.health = 60;
				allyBot.armor = 60;
				allyBot.speed = 13;
				allyBot.shotPower = 3;
				allyBot.superAbility = 0;
				panzer = enterFight(screen, hdc, panzer, enemyTop, enemyBot, allyBot, size);
				break;
			}
			case 350: {
				strcpy(enemyTop.name, "СИЛЬНЫЙ 1");
				strcpy(enemyTop.model, shortToChar(rand() % 2 + 1));
				enemyTop.health = 80;
				enemyTop.armor = 80;
				enemyTop.speed = 16;
				enemyTop.shotPower = 4;
				enemyTop.superAbility = 0;
				strcpy(enemyBot.name, "СИЛЬНЫЙ 2");
				strcpy(enemyBot.model, shortToChar(rand() % 2 + 1));
				enemyBot.health = 80;
				enemyBot.armor = 80;
				enemyBot.speed = 16;
				enemyBot.shotPower = 4;
				enemyBot.superAbility = 0;
				strcpy(allyBot.name, "СОЮЗНИК");
				strcpy(allyBot.model, shortToChar(rand() % 3 + 3));
				allyBot.health = 80;
				allyBot.armor = 80;
				allyBot.speed = 16;
				allyBot.shotPower = 4;
				allyBot.superAbility = 0;
				panzer = enterFight(screen, hdc, panzer, enemyTop, enemyBot, allyBot, size);
				break;
			}
			case 450: {
				strcpy(enemyTop.name, "ОЧЕНЬ СИЛЬНЫЙ 1");
				strcpy(enemyTop.model, shortToChar(rand() % 2 + 1));
				enemyTop.health = 100;
				enemyTop.armor = 100;
				enemyTop.speed = 19;
				enemyTop.shotPower = 5;
				enemyTop.superAbility = 0;
				strcpy(enemyBot.name, "ОЧЕНЬ СИЛЬНЫЙ 2");
				strcpy(enemyBot.model, shortToChar(rand() % 2 + 1));
				enemyBot.health = 100;
				enemyBot.armor = 100;
				enemyBot.speed = 19;
				enemyBot.shotPower = 5;
				enemyBot.superAbility = 0;
				strcpy(allyBot.name, "СОЮЗНИК");
				strcpy(allyBot.model, shortToChar(rand() % 3 + 3));
				allyBot.health = 100;
				allyBot.armor = 100;
				allyBot.speed = 19;
				allyBot.shotPower = 5;
				allyBot.superAbility = 0;
				panzer = enterFight(screen, hdc, panzer, enemyTop, enemyBot, allyBot, size);
				break;
			}
			case 550: {
				loop = false;
				break;
			}
			}

		}
		else {
			bool loop1 = true;
			while (loop) {
				paintPictures({ 0,0 }, screen, deskError, hdc);
				errorMessage(hdc);
				if (_kbhit()) {
					short key = _getch();
					if (key == KEY_ENTER) { loop1 = false; loop = false; }
				}
				Sleep(200);
			}
		}
	}
	return panzer;
}
//
//сортировка танков
PANZER* sortPanzersName(PANZER *panzer, short size) {
	for (short i = 0; i < size; i++) {
		for (short j = i + 1; j < size; j++) {
			if (strcmp(panzer[i].name, panzer[j].name) > 0) {
				swap(panzer[i].name, panzer[j].name);
				swap(panzer[i].model, panzer[j].model);
				swap(panzer[i].health, panzer[j].health);
				swap(panzer[i].armor, panzer[j].armor);
				swap(panzer[i].speed, panzer[j].speed);
				swap(panzer[i].shotPower, panzer[j].shotPower);
				swap(panzer[i].commandPoints, panzer[j].commandPoints);
				swap(panzer[i].superAbility, panzer[j].superAbility);
				swap(panzer[i].battles, panzer[j].battles);
				swap(panzer[i].wins, panzer[j].wins);
				swap(panzer[i].defeat, panzer[j].defeat);
				swap(panzer[i].code, panzer[j].code);
			}
		}
	}
	return panzer;
}
//
//сохранение танков
void savePanzers(PANZER* panzer, short size, short element) {
	short tempSize = 0, counter = 0 , j = 0, counter2 = 0;
	PANZER *temp = nullptr;
	fstream memoryPanzers;
	memoryPanzers.open("memmoryPanzers.txt", ios::in);
	while (!memoryPanzers.eof() && memoryPanzers.is_open()) {
		if (tempSize > 0) {
			temp = resizePanzer(temp, tempSize, tempSize + 1, 0);
		}
		else {
			temp = new PANZER[1];
			tempSize++;
		}
		memoryPanzers >> temp[tempSize - 1];
		if (strlen(temp[tempSize - 1].name) < 2) {
			temp = resizePanzer(temp, tempSize, tempSize - 1, tempSize);
		}
		if (temp[j].code == element && size > 0) {
			counter++;
		}
		j++;
	}
	if (counter < size) {
		for (short i = counter; i < size; i++) {
			if (tempSize > 0) {
				temp = resizePanzer(temp, tempSize, tempSize + 1, 0);
			}
			else {
				temp = new PANZER[1];
				tempSize++;
			}
			temp[tempSize - 1] = panzer[i];
		}
	}
	if (size <= counter) {
		for (short i = 0; i < tempSize; i++) {
			bool del = true;
			if (temp[i].code == element) {
				for (short k = 0; k < size; k++) {
					if (strcmp(temp[i].name, panzer[k].name) == 0) {
						del = false;
						break;
					}
				}
				if (del == true && tempSize > 0) {
					temp = resizePanzer(temp, tempSize, tempSize - 1, i + 1);
					--i;
				}
				else{
					temp[i] = panzer[counter2];
					counter2++;
				}
			}
		}
	}
	memoryPanzers.close();
	memoryPanzers.open("memmoryPanzers.txt", ios::out);
	for (short i = 0; i < tempSize; i++) {
		memoryPanzers << temp[i];
		if (i < tempSize - 1) { memoryPanzers << endl; }
	}
	memoryPanzers.close();
	delete[]temp;
}
//
//инициализация танков
PANZER* initPanzers(PANZER* panzer, short &size, short element) {
	short tempSize = 0;
	PANZER *temp = nullptr;
	fstream memoryPanzers;
	memoryPanzers.open("memmoryPanzers.txt", ios::in);
	while (!memoryPanzers.eof() && memoryPanzers.is_open()) {
		if (tempSize > 0) {
			temp = resizePanzer(temp, tempSize, tempSize + 1, 0);
		}
		else {
			temp = new PANZER[1];
			tempSize++;
		}
		memoryPanzers >> temp[tempSize - 1];
		if (strlen(temp[tempSize - 1].name) < 2) {
			temp = resizePanzer(temp, tempSize, tempSize - 1, tempSize);
		}
	}
	for (short i = 0; i < tempSize; i++) {
		if (temp[i].code == element) {
			if (size > 0) {
				panzer = resizePanzer(panzer, size, size + 1, 0);
			}
			else {
				panzer = new PANZER[1];
				size++;
			}
			panzer[size - 1] = temp[i];
		}
	}
	memoryPanzers.close();
	delete[]temp;
	return panzer;
}
//
//пересохранение танков в случае удаления профиля
void savePanzersAfterDelete(short element) {
	short tempSize = 0, counter2 = 0;
	PANZER *temp = nullptr;
	fstream memoryPanzers;
	memoryPanzers.open("memmoryPanzers.txt", ios::in);
	while (!memoryPanzers.eof() && memoryPanzers.is_open()) {
		if (tempSize > 0) {
			temp = resizePanzer(temp, tempSize, tempSize + 1, 0);
		}
		else {
			temp = new PANZER[1];
			tempSize++;
		}
		memoryPanzers >> temp[tempSize - 1];
		if (strlen(temp[tempSize - 1].name) < 2) {
			temp = resizePanzer(temp, tempSize, tempSize - 1, tempSize);
		}
	}
	for (short i = 0; i < tempSize; i++) {
		if (temp[i].code == element) {
			temp = resizePanzer(temp, tempSize, tempSize - 1, i + 1);
			--i;
		}
	}
	memoryPanzers.close();
	memoryPanzers.open("memmoryPanzers.txt", ios::out);
	for (short i = 0; i < tempSize; i++) {
		memoryPanzers << temp[i];
		if (i < tempSize - 1) { memoryPanzers << endl; }
	}
	memoryPanzers.close();
	delete[]temp;
}

