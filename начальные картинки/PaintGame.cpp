#include "Header.h"

PAINTSTRUCT ps;
BITMAP bitmap;
LONG width, height;
HDC hdcPicture;
HBRUSH brushRed, brushYellow, brushGrey, brushBlue, brushDarkGrey;
//
// �������� ��������
//void paintPictures( COORD pictureCoords, HWND screen, HBITMAP hBit, HDC hdc) {
//	hdcPicture = BeginPaint(screen, &ps);
//	GetObject(hBit, sizeof(bitmap), &bitmap);
//	width = bitmap.bmWidth;
//	height = bitmap.bmHeight;
//	hdcPicture = CreateCompatibleDC(hdc);
//	SelectObject(hdcPicture, hBit);
//	BitBlt(hdc, pictureCoords.X, pictureCoords.Y, width, height, hdcPicture, 0, 0, SRCCOPY);
//	DeleteDC(hdcPicture);
//	hdcPicture = NULL;
//	EndPaint(screen, &ps);
//}
void paintPictures(COORD pictureCoords, HWND screen, HBITMAP hBit, HDC hdc) {
	hdc = CreateCompatibleDC(hdc);
	GetObject(hBit, sizeof(bitmap), &bitmap);
	width = bitmap.bmWidth;
	height = bitmap.bmHeight;
	InvalidateRect(screen,NULL, FALSE);
	hdcPicture = BeginPaint(screen, &ps);
	SelectObject(hdc, hBit);
	BitBlt(hdcPicture, pictureCoords.X, pictureCoords.Y, width, height, hdc, 0, 0, SRCCOPY);
	EndPaint(screen, &ps);
	DeleteDC(hdc);
	DeleteDC(hdcPicture);
}
//
//������ �����
void paintUnit(COORD unitCoords, HWND screen, HBITMAP hBit0, HBITMAP hBit1, HBITMAP hBit2, HBITMAP hBit3, HDC hdc, short turnPanzer) {
	if (turnPanzer == 0) {
		paintPictures(unitCoords, screen, hBit0, hdc);
	}
	else if (turnPanzer == 1) {
		paintPictures(unitCoords, screen, hBit1, hdc);
	}
	else if (turnPanzer == 2) {
		paintPictures(unitCoords, screen, hBit2, hdc);
	}
	else if (turnPanzer == 3) {
		paintPictures(unitCoords, screen, hBit3, hdc);
	}
}
//
//������ �������� � ����� ����� �������
void paintHealthLeftTeam(COORD currentPanzerCoord, HWND screen, HDC hdc, PANZER *panzer, ENEMY allyBot, short number, short turnPanzer, short leftHealth, short leftArmor) { 
	short tempHealth;
	short tempArmor;
	if (panzer != nullptr) {
		tempHealth = healthArmorBalancer(panzer[number].health, leftHealth);
		tempArmor = healthArmorBalancer(panzer[number].armor, leftArmor);
	}
	else{
		tempHealth = healthArmorBalancer(allyBot.health, leftHealth);
		tempArmor = healthArmorBalancer(allyBot.armor, leftArmor);
	}
	switch (turnPanzer) {
	case 0: {
		brushYellow = CreateSolidBrush(RGB(255, 255, 0));
		brushRed = CreateSolidBrush(RGB(255, 0, 0));
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		SelectObject(hdc, brushYellow);
		Rectangle(hdc, currentPanzerCoord.X - 20, currentPanzerCoord.Y + 50 - tempArmor, currentPanzerCoord.X - 15, currentPanzerCoord.Y + 50);
		DeleteObject(brushYellow);
		SelectObject(hdc, brushRed);
		Rectangle(hdc, currentPanzerCoord.X - 15, currentPanzerCoord.Y + 50 - tempHealth, currentPanzerCoord.X - 10, currentPanzerCoord.Y + 50);
		DeleteObject(brushRed);
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, currentPanzerCoord.X - 15, currentPanzerCoord.Y, currentPanzerCoord.X - 10, currentPanzerCoord.Y + 50 - tempHealth);
		Rectangle(hdc, currentPanzerCoord.X - 20, currentPanzerCoord.Y, currentPanzerCoord.X - 15, currentPanzerCoord.Y + 50 - tempArmor);
		DeleteObject(brushGrey);
		break;
	}
	case 1: {
		brushYellow = CreateSolidBrush(RGB(255, 255, 0));
		brushRed = CreateSolidBrush(RGB(255, 0, 0));
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		SelectObject(hdc, brushYellow);
		Rectangle(hdc, currentPanzerCoord.X + 50 - tempArmor, currentPanzerCoord.Y - 20, currentPanzerCoord.X + 50, currentPanzerCoord.Y - 15);
		DeleteObject(brushYellow);
		SelectObject(hdc, brushRed);
		Rectangle(hdc, currentPanzerCoord.X + 50 - tempHealth, currentPanzerCoord.Y - 15, currentPanzerCoord.X + 50, currentPanzerCoord.Y - 10);
		DeleteObject(brushRed);
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, currentPanzerCoord.X, currentPanzerCoord.Y - 15, currentPanzerCoord.X + 50 - tempHealth, currentPanzerCoord.Y - 10);
		Rectangle(hdc, currentPanzerCoord.X, currentPanzerCoord.Y - 20, currentPanzerCoord.X + 50 - tempArmor, currentPanzerCoord.Y - 15);
		DeleteObject(brushGrey);
		break;
	}
	case 2: {
		brushYellow = CreateSolidBrush(RGB(255, 255, 0));
		brushRed = CreateSolidBrush(RGB(255, 0, 0));
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		SelectObject(hdc, brushYellow);
		Rectangle(hdc, currentPanzerCoord.X + 70, currentPanzerCoord.Y + 50 - tempArmor, currentPanzerCoord.X + 65, currentPanzerCoord.Y + 50);
		DeleteObject(brushYellow);
		SelectObject(hdc, brushRed);
		Rectangle(hdc, currentPanzerCoord.X + 65, currentPanzerCoord.Y + 50 - tempHealth, currentPanzerCoord.X + 60, currentPanzerCoord.Y + 50);
		DeleteObject(brushRed);
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, currentPanzerCoord.X + 65, currentPanzerCoord.Y, currentPanzerCoord.X + 60, currentPanzerCoord.Y + 50 - tempHealth);
		Rectangle(hdc, currentPanzerCoord.X + 70, currentPanzerCoord.Y, currentPanzerCoord.X + 65, currentPanzerCoord.Y + 50 - tempArmor);
		DeleteObject(brushGrey);
		break;
	}
	case 3: {
		brushYellow = CreateSolidBrush(RGB(255, 255, 0));
		brushRed = CreateSolidBrush(RGB(255, 0, 0));
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		SelectObject(hdc, brushYellow);
		Rectangle(hdc, currentPanzerCoord.X + 50 - tempArmor, currentPanzerCoord.Y + 70, currentPanzerCoord.X + 50, currentPanzerCoord.Y + 65);
		DeleteObject(brushYellow);
		SelectObject(hdc, brushRed);
		Rectangle(hdc, currentPanzerCoord.X + 50 - tempHealth, currentPanzerCoord.Y + 65, currentPanzerCoord.X + 50, currentPanzerCoord.Y + 60);
		DeleteObject(brushRed);
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, currentPanzerCoord.X, currentPanzerCoord.Y + 65, currentPanzerCoord.X + 50 - tempHealth, currentPanzerCoord.Y + 60);
		Rectangle(hdc, currentPanzerCoord.X, currentPanzerCoord.Y + 70, currentPanzerCoord.X + 50 - tempArmor, currentPanzerCoord.Y + 65);
		DeleteObject(brushGrey);
		break;
	}
	}
}
//
//������ �������� � ����� ������ �������
void paintHealthRightTeam(COORD currentPanzerCoord, HWND screen, HDC hdc, ENEMY enemy, short turnPanzer, short rightHealth, short rightArmor) {
	short tempHealth;
	short tempArmor;
	tempHealth = healthArmorBalancer(enemy.health, rightHealth);
	tempArmor = healthArmorBalancer(enemy.armor, rightArmor);
	switch (turnPanzer) {
	case 0: {
		brushYellow = CreateSolidBrush(RGB(255, 255, 0));
		brushBlue = CreateSolidBrush(RGB(10, 60, 200));
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		SelectObject(hdc, brushYellow);
		Rectangle(hdc, currentPanzerCoord.X + 70, currentPanzerCoord.Y + 50 - tempArmor, currentPanzerCoord.X + 65, currentPanzerCoord.Y + 50);
		DeleteObject(brushYellow);
		SelectObject(hdc, brushBlue);
		Rectangle(hdc, currentPanzerCoord.X + 65, currentPanzerCoord.Y + 50 - tempHealth, currentPanzerCoord.X + 60, currentPanzerCoord.Y + 50);
		DeleteObject(brushBlue);
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, currentPanzerCoord.X + 65, currentPanzerCoord.Y, currentPanzerCoord.X + 60, currentPanzerCoord.Y + 50 - tempHealth);
		Rectangle(hdc, currentPanzerCoord.X + 70, currentPanzerCoord.Y, currentPanzerCoord.X + 65, currentPanzerCoord.Y + 50 - tempArmor);
		DeleteObject(brushGrey);
		break;
	}
	case 1: {
		brushYellow = CreateSolidBrush(RGB(255, 255, 0));
		brushBlue = CreateSolidBrush(RGB(10, 60, 200));
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		SelectObject(hdc, brushYellow);
		Rectangle(hdc, currentPanzerCoord.X + 50 - tempArmor, currentPanzerCoord.Y + 70, currentPanzerCoord.X + 50, currentPanzerCoord.Y + 65);
		DeleteObject(brushYellow);
		SelectObject(hdc, brushBlue);
		Rectangle(hdc, currentPanzerCoord.X + 50 - tempHealth, currentPanzerCoord.Y + 65, currentPanzerCoord.X + 50, currentPanzerCoord.Y + 60);
		DeleteObject(brushBlue);
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, currentPanzerCoord.X, currentPanzerCoord.Y + 65, currentPanzerCoord.X + 50 - tempHealth, currentPanzerCoord.Y + 60);
		Rectangle(hdc, currentPanzerCoord.X, currentPanzerCoord.Y + 70, currentPanzerCoord.X + 50 - tempArmor, currentPanzerCoord.Y + 65);
		DeleteObject(brushGrey);
		break;
	}
	case 2: {
		brushYellow = CreateSolidBrush(RGB(255, 255, 0));
		brushBlue = CreateSolidBrush(RGB(10, 60, 200));
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		SelectObject(hdc, brushYellow);
		Rectangle(hdc, currentPanzerCoord.X - 20, currentPanzerCoord.Y + 50 - tempArmor, currentPanzerCoord.X - 15, currentPanzerCoord.Y + 50);
		DeleteObject(brushYellow);
		SelectObject(hdc, brushBlue);
		Rectangle(hdc, currentPanzerCoord.X - 15, currentPanzerCoord.Y + 50 - tempHealth, currentPanzerCoord.X - 10, currentPanzerCoord.Y + 50);
		DeleteObject(brushBlue);
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, currentPanzerCoord.X - 15, currentPanzerCoord.Y, currentPanzerCoord.X - 10, currentPanzerCoord.Y + 50 - tempHealth);
		Rectangle(hdc, currentPanzerCoord.X - 20, currentPanzerCoord.Y, currentPanzerCoord.X - 15, currentPanzerCoord.Y + 50 - tempArmor);
		DeleteObject(brushGrey);
		break;
	}
	case 3: {
		brushYellow = CreateSolidBrush(RGB(255, 255, 0));
		brushBlue = CreateSolidBrush(RGB(10, 60, 200));
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		SelectObject(hdc, brushYellow);
		Rectangle(hdc, currentPanzerCoord.X + 50 - tempArmor, currentPanzerCoord.Y - 20, currentPanzerCoord.X + 50, currentPanzerCoord.Y - 15);
		DeleteObject(brushYellow);
		SelectObject(hdc, brushBlue);
		Rectangle(hdc, currentPanzerCoord.X + 50 - tempHealth, currentPanzerCoord.Y - 15, currentPanzerCoord.X + 50, currentPanzerCoord.Y - 10);
		DeleteObject(brushBlue);
		SelectObject(hdc, brushGrey);
		Rectangle(hdc, currentPanzerCoord.X, currentPanzerCoord.Y - 15, currentPanzerCoord.X + 50 - tempHealth, currentPanzerCoord.Y - 10);
		Rectangle(hdc, currentPanzerCoord.X, currentPanzerCoord.Y - 20, currentPanzerCoord.X + 50 - tempArmor, currentPanzerCoord.Y - 15);
		DeleteObject(brushGrey);
		break;
	}
	}
}
//
//������ �������� ���
void paintBasesHealth(HWND screen, HDC hdc, short redBaseHealth, short blueBaseHealth) {
	brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	SelectObject(hdc, brushRed);
	SelectObject(hdc, brushGrey);
	Rectangle(hdc, 10, 175, 20, 375 - redBaseHealth);
	Rectangle(hdc, 930, 175, 940, 375 - blueBaseHealth);
	DeleteObject(brushGrey);
}
//
//������� ����
void paintPanzerMenu(HDC hdc, PANZER *panzer, ENEMY allyBot, short number, short playerHealth, short playerArmor, short allyBotHealth, short allyBotArmor, short &time) {
	brushDarkGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT bigFont = CreateFontA(90, 30, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	short tempPlayerHealth, tempPlayerArmor, tempAllyBotHealth, tempAllyBotArmor;
	tempPlayerHealth = healthArmorBalancer2(panzer[number].health, playerHealth);
	tempPlayerArmor = healthArmorBalancer2(panzer[number].armor, playerArmor);
	tempAllyBotHealth = healthArmorBalancer2(allyBot.health, allyBotHealth);
	tempAllyBotArmor = healthArmorBalancer2(allyBot.armor, allyBotArmor);
	tempPlayerArmor = (146 + tempPlayerArmor < 150) ? 4 : tempPlayerArmor;
	tempPlayerHealth = (146 + tempPlayerHealth < 152) ? 6 : tempPlayerHealth;
	tempAllyBotHealth = (710 + tempAllyBotHealth < 712) ? 2 : tempAllyBotHealth;
	SelectObject(hdc, brushDarkGrey);
	Rectangle(hdc, 146 + tempPlayerArmor, 600, 346 , 619);
	Rectangle(hdc, 710 + tempAllyBotArmor, 600, 910, 619);
	Rectangle(hdc, 146 + tempPlayerHealth, 620, 346, 641);
	Rectangle(hdc, 710 + tempAllyBotHealth, 620, 910, 641);
	DeleteObject(brushDarkGrey);
	SelectObject(hdc, bigFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	if (time < 10) {
		TextOutA(hdc, 410, 580, "000", strlen("000"));
		TextOutA(hdc, 510, 580, shortToChar(time), strlen(shortToChar(time)));
	}
	else if (time < 100) {
		TextOutA(hdc, 410, 580, "00", strlen("00"));
		TextOutA(hdc, 480, 580, shortToChar(time), strlen(shortToChar(time)));
	}
	else if (time < 1000) {
		TextOutA(hdc, 410, 580, "0", strlen("0"));
		TextOutA(hdc, 450, 580, shortToChar(time), strlen(shortToChar(time)));
	}
	else {
		TextOutA(hdc, 420, 580, shortToChar(time), strlen(shortToChar(time)));
	}
	DeleteObject(bigFont);
}
//
// ��������� ���� +
void paintStartMenu(HWND screen, HDC hdc) {
	brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 60, 60, "����� �������", strlen("����� �������"));
	TextOutA(hdc, 60, 160, "����� �������", strlen("����� �������"));
	TextOutA(hdc, 60, 260, "������� �������", strlen("������� �������"));
	TextOutA(hdc, 60, 360, "��� �������", strlen("��� �������"));
	TextOutA(hdc, 60, 460, "�����", strlen("�����"));
	DeleteObject(newFont);
}
//
//����� ����
void paintBorder(HDC hdc, COORD coord) {
	HBRUSH brushGreen = CreateSolidBrush(RGB(0, 255, 0));
	SelectObject(hdc, brushGreen);
	Rectangle(hdc, coord.X - 10, coord.Y - 10, coord.X + 410, coord.Y);
	Rectangle(hdc, coord.X - 10, coord.Y + 80, coord.X + 410, coord.Y + 90);
	Rectangle(hdc, coord.X - 10, coord.Y, coord.X, coord.Y + 80);
	Rectangle(hdc, coord.X + 400, coord.Y, coord.X + 410, coord.Y + 80);
	DeleteObject(brushGreen);
}
//
//���� ������� +
void paintProfileMenu(HWND screen, HDC hdc) {
	brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 180, 260, "������", strlen("������"));
	TextOutA(hdc, 580, 260, "��� �����", strlen("��� �����"));
	TextOutA(hdc, 130, 610, "����������", strlen("����������"));
	TextOutA(hdc, 640, 610, "�����", strlen("�����"));
	DeleteObject(newFont);
}
//
//���� ��� ����� +
void paintMyPanzers(HWND screen, HDC hdc) {
		brushGrey = CreateSolidBrush(RGB(60, 50, 50));
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		SelectObject(hdc, newFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 150, 430, "�������", strlen("�������"));
		TextOutA(hdc, 70, 520, "������� ����", strlen("������� ����"));
		TextOutA(hdc, 70, 610, "������� ����", strlen("������� ����"));
		TextOutA(hdc, 640, 610, "�����", strlen("�����"));
		DeleteObject(newFont);
}
//
//���� �����, ������ ����� +
void paintPanzerNameModel(HDC hdc) {
	HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 510, 20, "�������� �����:", strlen("�������� �����:"));
	TextOutA(hdc, 510, 290, "������ �����:", strlen("������ �����:"));
	TextOutA(hdc, 510, 470, "��������������", strlen("��������������"));
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 510, 380, "<<<", strlen("<<<"));
	TextOutA(hdc, 840, 380, ">>>", strlen(">>>"));
	DeleteObject(newFont);
}
//
//���� ������������� ����� +
void paintPanzerCharacteristics(HDC hdc, PANZER *panzer, short number) {
	HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 510, 20, "���� ��������:", strlen("���� ��������:"));
	TextOutA(hdc, 540, 110, "��������:", strlen("��������:"));
	TextOutA(hdc, 800, 110, "/100", strlen("/100"));
	TextOutA(hdc, 540, 200, "�����:", strlen("�����:"));
	TextOutA(hdc, 800, 200, "/100", strlen("/100"));
	TextOutA(hdc, 540, 290, "��������:", strlen("��������:"));
	TextOutA(hdc, 800, 290, "/22", strlen("/22"));
	TextOutA(hdc, 540, 380, "����:", strlen("����:"));
	TextOutA(hdc, 800, 380, "/5", strlen("/5"));
	TextOutA(hdc, 630, 470, "������", strlen("������"));
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 500, 110, "<<", strlen("<<"));
	TextOutA(hdc, 500, 200, "<<", strlen("<<"));
	TextOutA(hdc, 500, 290, "<<", strlen("<<"));
	TextOutA(hdc, 500, 380, "<<", strlen("<<"));
	TextOutA(hdc, 870, 110, ">>", strlen(">>"));
	TextOutA(hdc, 870, 200, ">>", strlen(">>"));
	TextOutA(hdc, 870, 290, ">>", strlen(">>"));
	TextOutA(hdc, 870, 380, ">>", strlen(">>"));
	TextOutA(hdc, 840, 20, shortToChar(panzer[number].commandPoints), strlen(shortToChar(panzer[number].commandPoints)));
	TextOutA(hdc, 750, 110, shortToChar(panzer[number].health), strlen(shortToChar(panzer[number].health)));
	TextOutA(hdc, 750, 200, shortToChar(panzer[number].armor), strlen(shortToChar(panzer[number].armor)));
	TextOutA(hdc, 750, 290, shortToChar(panzer[number].speed), strlen(shortToChar(panzer[number].speed)));
	TextOutA(hdc, 750, 380, shortToChar(panzer[number].shotPower), strlen(shortToChar(panzer[number].shotPower)));
	DeleteObject(newFont);
}
//
//���� ��������+
void paintPoligonMenu(HDC hdc, PANZER *panzer, short number) {
	HBRUSH brushGrey = CreateSolidBrush(RGB(60, 50, 50));
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	HFONT font = CreateFontA(40, 12, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, font);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 510, 20, "����", strlen("����"));
	TextOutA(hdc, 510, 60, "��������", strlen("��������"));
	TextOutA(hdc, 510, 100, "�����", strlen("�����"));
	TextOutA(hdc, 510, 140, "��������", strlen("��������"));
	TextOutA(hdc, 510, 180, "����", strlen("����"));
	TextOutA(hdc, 510, 220, "������", strlen("������"));
	TextOutA(hdc, 510, 260, "��������", strlen("��������"));
	TextOutA(hdc, 510, 300, "�����", strlen("�����"));
	TextOutA(hdc, 510, 340, "���������", strlen("���������"));
	TextOutA(hdc, 510, 380, "���� ��������", strlen("���� ��������"));
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 710, 20, panzer[number].name, strlen(panzer[number].name));
	TextOutA(hdc, 710, 60, shortToChar(panzer[number].health), strlen(shortToChar(panzer[number].health)));
	TextOutA(hdc, 710, 100, shortToChar(panzer[number].armor), strlen(shortToChar(panzer[number].armor)));
	TextOutA(hdc, 710, 140, shortToChar(panzer[number].speed), strlen(shortToChar(panzer[number].speed)));
	TextOutA(hdc, 710, 180, shortToChar(panzer[number].shotPower), strlen(shortToChar(panzer[number].shotPower)));
	TextOutA(hdc, 710, 220, shortToChar(panzer[number].superAbility), strlen(shortToChar(panzer[number].superAbility)));
	TextOutA(hdc, 710, 260, shortToChar(panzer[number].battles), strlen(shortToChar(panzer[number].battles)));
	TextOutA(hdc, 710, 300, shortToChar(panzer[number].wins), strlen(shortToChar(panzer[number].wins)));
	TextOutA(hdc, 710, 340, shortToChar(panzer[number].defeat), strlen(shortToChar(panzer[number].defeat)));
	TextOutA(hdc, 710, 380, shortToChar(panzer[number].commandPoints), strlen(shortToChar(panzer[number].commandPoints)));
	DeleteObject(font);
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 510, 470, "�������� ����", strlen("�������� ����"));
	DeleteObject(newFont);
}
//
//������ ��� ����
void errorMessage(HDC hdc) {
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 340, 150, "� ��� ��� �����!", strlen("� ��� ��� �����!"));
	TextOutA(hdc, 300, 210, "�������� ���� ��� ��", strlen("�������� ���� ��� ��"));
	TextOutA(hdc, 370, 270, "������ ����", strlen("������ ����"));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 410, 400, "�����", strlen("�����"));
	DeleteObject(newFont);
	paintBorder(hdc, { 276, 393 });
}
//
//��������� ���������
void paintEnemyPower(HWND screen, HDC hdc) {
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 60, 60, "����", strlen("����"));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 60, 160, "������", strlen("������"));
	TextOutA(hdc, 60, 260, "�������", strlen("�������"));
	TextOutA(hdc, 60, 360, "�������", strlen("�������"));
	TextOutA(hdc, 60, 460, "����� �������", strlen("����� �������"));
	TextOutA(hdc, 60, 560, "�����", strlen("�����"));
	DeleteObject(newFont);
}
//
//������ ����������
void paintStatistics(HWND screen, HDC hdc, PANZER *panzer, short size) {
	HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	HFONT font = CreateFontA(40, 12, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
	SelectObject(hdc, font);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 0, 0));
	TextOutA(hdc, 60, 40, "�", strlen("�"));
	TextOutA(hdc, 65, 105, "1", strlen("1"));
	TextOutA(hdc, 65, 170, "2", strlen("2"));
	TextOutA(hdc, 65, 235, "3", strlen("3"));
	TextOutA(hdc, 65, 300, "4", strlen("4"));
	TextOutA(hdc, 65, 365, "5", strlen("5"));
	TextOutA(hdc, 65, 430, "6", strlen("6"));
	TextOutA(hdc, 65, 495, "7", strlen("7"));
	TextOutA(hdc, 105, 40, "����", strlen("����"));
	TextOutA(hdc, 350, 40, "�����", strlen("�����"));
	TextOutA(hdc, 485, 40, "���������", strlen("���������"));
	TextOutA(hdc, 700, 40, "��������", strlen("��������"));
	SetTextColor(hdc, RGB(255, 255, 255));
	for (short i = 0; i < size; i++) {
		for (short j = i + 1; j < size; j++) {
			if (panzer[i].wins < panzer[j].wins) {
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
	short y = 105, barrier = 0;
	barrier = (size < 7) ? size : 7;
	for (short i = 0; i < barrier; i++) {
		TextOutA(hdc, 105, y, panzer[i].name, strlen(panzer[i].name));
		TextOutA(hdc, 400, y, shortToChar(panzer[i].wins), strlen(shortToChar(panzer[i].wins)));
		TextOutA(hdc, 590, y, shortToChar(panzer[i].defeat), strlen(shortToChar(panzer[i].defeat)));
		TextOutA(hdc, 800, y, shortToChar(panzer[i].battles), strlen(shortToChar(panzer[i].battles)));
		y+=65;
	}
	DeleteObject(font);
	SelectObject(hdc, newFont);
	SetBkColor(hdc, RGB(60, 50, 50));
	SetTextColor(hdc, RGB(255, 255, 255));
	TextOutA(hdc, 430, 570, "�����", strlen("�����"));
	DeleteObject(newFont);
}
//
//������ ������
COORD escapeGame(HWND screen, HDC hdc, PANZER *panzer, short number) {
	bool loop = true;
	COORD coord = { 60, 560 };
	while (loop) {
		paintPictures({ 0,0 }, screen, deskEscape, hdc);
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		HFONT font = CreateFontA(40, 12, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		SelectObject(hdc, font);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 70, 110, "����", strlen("����"));
		TextOutA(hdc, 70, 150, "��������", strlen("��������"));
		TextOutA(hdc, 70, 190, "�����", strlen("�����"));
		TextOutA(hdc, 70, 230, "��������", strlen("��������"));
		TextOutA(hdc, 70, 270, "����", strlen("����"));
		TextOutA(hdc, 70, 310, "������", strlen("������"));
		TextOutA(hdc, 70, 350, "��������", strlen("��������"));
		TextOutA(hdc, 70, 390, "�����", strlen("�����"));
		TextOutA(hdc, 70, 430, "���������", strlen("���������"));
		TextOutA(hdc, 70, 470, "���� ��������", strlen("���� ��������"));
		TextOutA(hdc, 550, 110, "����������", strlen("����������"));
		TextOutA(hdc, 510, 150, "�����", strlen("�����"));
		TextOutA(hdc, 510, 190, "������", strlen("������"));
		TextOutA(hdc, 510, 230, "�����", strlen("�����"));
		TextOutA(hdc, 510, 270, "����", strlen("����"));
		TextOutA(hdc, 510, 310, "�������", strlen("�������"));
		TextOutA(hdc, 510, 350, "�����", strlen("�����"));
		TextOutA(hdc, 510, 390, "�����", strlen("�����"));
		SetTextColor(hdc, RGB(255, 0, 0));
		TextOutA(hdc, 150, 50, "����� �� ���� �������� � ���������!", strlen("����� �� ���� �������� � ���������!"));
		TextOutA(hdc, 300, 110, panzer[number].name, strlen(panzer[number].name));
		TextOutA(hdc, 300, 150, shortToChar(panzer[number].health), strlen(shortToChar(panzer[number].health)));
		TextOutA(hdc, 300, 190, shortToChar(panzer[number].armor), strlen(shortToChar(panzer[number].armor)));
		TextOutA(hdc, 300, 230, shortToChar(panzer[number].speed), strlen(shortToChar(panzer[number].speed)));
		TextOutA(hdc, 300, 270, shortToChar(panzer[number].shotPower), strlen(shortToChar(panzer[number].shotPower)));
		TextOutA(hdc, 300, 310, shortToChar(panzer[number].superAbility), strlen(shortToChar(panzer[number].superAbility)));
		TextOutA(hdc, 300, 350, shortToChar(panzer[number].battles), strlen(shortToChar(panzer[number].battles)));
		TextOutA(hdc, 300, 390, shortToChar(panzer[number].wins), strlen(shortToChar(panzer[number].wins)));
		TextOutA(hdc, 300, 430, shortToChar(panzer[number].defeat), strlen(shortToChar(panzer[number].defeat)));
		TextOutA(hdc, 300, 470, shortToChar(panzer[number].commandPoints), strlen(shortToChar(panzer[number].commandPoints)));
		TextOutA(hdc, 730, 150, "A", strlen("A"));
		TextOutA(hdc, 730, 190, "D", strlen("D"));
		TextOutA(hdc, 730, 230, "W", strlen("W"));
		TextOutA(hdc, 730, 270, "S", strlen("S"));
		TextOutA(hdc, 730, 310, "E", strlen("E"));
		TextOutA(hdc, 730, 350, "SPACE", strlen("SPACE"));
		TextOutA(hdc, 730, 390, "ESC", strlen("ESC"));
		DeleteObject(font);
		SelectObject(hdc, newFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 130, 570, "����������", strlen("����������"));
		TextOutA(hdc, 620, 570, "�����", strlen("�����"));
		DeleteObject(newFont);
		paintBorder(hdc, coord);
		if (_kbhit()) {
			short key = _getch();
			switch (key) {
			case KEY_RIGHT: {
				coord = { 485, 560 };
				break;
			}
			case KEY_LEFT: {
				coord = { 60, 560 };
				break;
			}
			case KEY_ENTER: {
				loop = false;
			}
			}
		}
		Sleep(200);
	}
	return coord;
}
//
//����� ����������
void winGame(HWND screen, HDC hdc) {
	bool loop = true;
	while (loop) {
		paintPictures({ 0,0 }, screen, deskWin, hdc);
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		HFONT font = CreateFontA(80, 20, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		HFONT bigFont = CreateFontA(120, 23, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		SelectObject(hdc, newFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 350, 570, "����������", strlen("����������"));
		DeleteObject(newFont);
		SelectObject(hdc, font);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 260, 300, "���� �������� + 1", strlen("���� �������� + 1"));
		TextOutA(hdc, 350, 200, "�������", strlen("�������"));
		DeleteObject(font);
		SelectObject(hdc,bigFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 0, 0));
		TextOutA(hdc, 80, 70, "���! ����������� ������!", strlen("���! ����������� ������!"));
		DeleteObject(bigFont);
		paintBorder(hdc, {285, 560});
		if (_kbhit()) {
			short key = _getch();
			loop = (key == KEY_ENTER) ? false : true;
		}
		Sleep(300);
	}
}
//
//����� ���������
void failGame(HWND screen, HDC hdc) {
	bool loop = true;
	while (loop) {
		paintPictures({ 0,0 }, screen, deskWin, hdc);
		HFONT newFont = CreateFontA(60, 15, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		HFONT font = CreateFontA(80, 20, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		HFONT bigFont = CreateFontA(120, 23, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Palatino Linotype");
		SelectObject(hdc, newFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 350, 570, "����������", strlen("����������"));
		DeleteObject(newFont);
		SelectObject(hdc, font);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 255, 255));
		TextOutA(hdc, 260, 300, "��� ���� ������!", strlen("��� ���� ������!"));
		TextOutA(hdc, 150, 200, "� ��������� ���������", strlen("� ��������� ���������"));
		DeleteObject(font);
		SelectObject(hdc, bigFont);
		SetBkColor(hdc, RGB(60, 50, 50));
		SetTextColor(hdc, RGB(255, 0, 0));
		TextOutA(hdc, 200, 70, "� ���! ���������!", strlen("� ���! ���������!"));
		DeleteObject(bigFont);
		paintBorder(hdc, { 285, 560 });
		if (_kbhit()) {
			short key = _getch();
			loop = (key == KEY_ENTER) ? false : true;
		}
		Sleep(300);
	}
}

