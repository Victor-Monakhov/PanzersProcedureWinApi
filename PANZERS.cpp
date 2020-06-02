#include "Header.h"


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	showcursor(false);
	srand(time(NULL));
	system("title TAHKÈ");
	system("mode con cols=135 lines=57");
	HWND screen = GetConsoleWindow();
	HDC hdc = GetDC(screen);
	short size = 0, y;
	bool work = true;
	Profile *profile = nullptr;
	profile = initProfiles(profile, size);
	COORD firstMenuCoord = { 50,50 };
	COORD secondMenuCoord = { 500,50 };
	while (work) {
		y = menuStandart(screen, hdc, firstMenuCoord, startDesk, paintStartMenu, 5, 100);
		switch (y) {
		case 50:{
			profile = createNewProfile(screen, hdc, profile, size);
			profile = sortProfilesName(profile, size);
			saveProfiles(profile, size);
			break;
		}
		case 150: {
			profile = enterProfile(screen, hdc, secondMenuCoord, profile, size);
			break;
		}
		case 250: {
			profile = deleteProfile(screen, hdc, secondMenuCoord, profile, size);
			saveProfiles(profile, size);
			break;
		}
		case 350: {
			profile = profileName(screen, hdc, secondMenuCoord, profile, size);
			profile = sortProfilesName(profile, size);
			saveProfiles(profile, size);
			break;
		}
		case 450: {
			work = false;
			break;
		}
		default: {break; }
		}
	}
	//saveProfiles(profile, size);
	return 0;
}
