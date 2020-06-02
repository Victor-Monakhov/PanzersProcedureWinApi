#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<windows.h>

// кнопки
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72
#define KEY_ENTER 13
#define KEY_DELETE 83
#define KEY_SPACE 32
#define KEY_BACKSPACE 8
#define KEY_ESCAPE 27

// карта
#define ARR_WIDTH 1350
#define ARR_HEIGHT 950
#define WIDTH 950
#define HEIGHT 550
#define BARRIER 200
// полигон

#define WID_HEIG 800
#define TOP_Y 30
#define LEFT_X 50
// ПДД
#define WALL 1
#define PLAYER 2
#define ENEMY_TOP 3
#define ROAD_END 4
#define ALLY_ROAD_END 5
#define ENEMY_ROAD_END 6
#define RED_BASE 7
#define BLUE_BASE 8
#define ENEMY_BOT 9
#define ALLY 10
//база данных
#define MAXSIZE 14

using namespace std;

struct Profile {
	char name[MAXSIZE] = "\0";
	short code = 0;
};

struct PANZER {
	char name[MAXSIZE] = "\0";
	char model[2] = "1";
	short health = 20;
	short armor = 20;
	short speed = 10;
	short shotPower = 1;
	short commandPoints = 4;
	short superAbility = 0;
	short battles = 0;
	short wins = 0;
	short defeat = 0;
	short code = 0;
};
struct ENEMY {
	char name[MAXSIZE] = "\0";
	char model[2] = "1";
	short health = 20;
	short armor = 20;
	short speed = 10;
	short shotPower = 1;
	short superAbility = 0;
};

//зеленый танк
static HBITMAP greenPanzer0 = (HBITMAP)LoadImage(NULL, TEXT("images/0new.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP greenPanzer1 = (HBITMAP)LoadImage(NULL, TEXT("images/1new.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP greenPanzer2 = (HBITMAP)LoadImage(NULL, TEXT("images/2new.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP greenPanzer3 = (HBITMAP)LoadImage(NULL, TEXT("images/3new.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
//коричневый танк
static HBITMAP brownPanzer0 = (HBITMAP)LoadImage(NULL, TEXT("images/enemy0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP brownPanzer1 = (HBITMAP)LoadImage(NULL, TEXT("images/enemy1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP brownPanzer2 = (HBITMAP)LoadImage(NULL, TEXT("images/enemy_2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP brownPanzer3 = (HBITMAP)LoadImage(NULL, TEXT("images/enemy3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
//белый танк
static HBITMAP whitePanzer0 = (HBITMAP)LoadImage(NULL, TEXT("images/white0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP whitePanzer1 = (HBITMAP)LoadImage(NULL, TEXT("images/white1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP whitePanzer2 = (HBITMAP)LoadImage(NULL, TEXT("images/white2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP whitePanzer3 = (HBITMAP)LoadImage(NULL, TEXT("images/white3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
//желтый танк
static HBITMAP yellowPanzer0 = (HBITMAP)LoadImage(NULL, TEXT("images/yellow_0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP yellowPanzer1 = (HBITMAP)LoadImage(NULL, TEXT("images/yellow1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP yellowPanzer2 = (HBITMAP)LoadImage(NULL, TEXT("images/yellow2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP yellowPanzer3 = (HBITMAP)LoadImage(NULL, TEXT("images/yellow3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
//серый танк
static HBITMAP greyPanzer0 = (HBITMAP)LoadImage(NULL, TEXT("images/grey0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP greyPanzer1 = (HBITMAP)LoadImage(NULL, TEXT("images/grey1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP greyPanzer2 = (HBITMAP)LoadImage(NULL, TEXT("images/grey2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP greyPanzer3 = (HBITMAP)LoadImage(NULL, TEXT("images/grey3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
// игровые мелочи
static HBITMAP map = (HBITMAP)LoadImage(NULL, TEXT("images/mapNew.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP shot0 = (HBITMAP)LoadImage(NULL, TEXT("images/shot0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP shot1 = (HBITMAP)LoadImage(NULL, TEXT("images/shot1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP shotFire0 = (HBITMAP)LoadImage(NULL, TEXT("images/shotFire0.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP shotFire1 = (HBITMAP)LoadImage(NULL, TEXT("images/shotFire1.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP shotFire2 = (HBITMAP)LoadImage(NULL, TEXT("images/shotFire2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP shotFire3 = (HBITMAP)LoadImage(NULL, TEXT("images/shotFire3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP boom = (HBITMAP)LoadImage(NULL, TEXT("images/boom.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP boom2 = (HBITMAP)LoadImage(NULL, TEXT("images/boom2.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP boom3 = (HBITMAP)LoadImage(NULL, TEXT("images/boom3.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deathRed = (HBITMAP)LoadImage(NULL, TEXT("images/deathRed.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deathBlue = (HBITMAP)LoadImage(NULL, TEXT("images/deathBlue.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

// desk
static HBITMAP startDesk = (HBITMAP)LoadImage(NULL, TEXT("images/startDesk.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskProfileName = (HBITMAP)LoadImage(NULL, TEXT("images/deskProfileName.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskProfileUniversal = (HBITMAP)LoadImage(NULL, TEXT("images/deskProfileUniversal.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskProfileMenu = (HBITMAP)LoadImage(NULL, TEXT("images/deskProfileMenu.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskPoligonMenu = (HBITMAP)LoadImage(NULL, TEXT("images/deskPoligonMenu.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskPanzerNameModel = (HBITMAP)LoadImage(NULL, TEXT("images/deskPanzerNameModel.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskPanzerCharacteristics = (HBITMAP)LoadImage(NULL, TEXT("images/deskPanzerCharacteristics.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskPanzerMenu = (HBITMAP)LoadImage(NULL, TEXT("images/deskPanzerMenu.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskError = (HBITMAP)LoadImage(NULL, TEXT("images/errorMessage.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP startDeskTwo = (HBITMAP)LoadImage(NULL, TEXT("images/startDeskTwo.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskProfileUniversalTwo = (HBITMAP)LoadImage(NULL, TEXT("images/deskProfileUniversalTwo.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskStatistics = (HBITMAP)LoadImage(NULL, TEXT("images/deskStatistics.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskEscape = (HBITMAP)LoadImage(NULL, TEXT("images/deskEscape.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
static HBITMAP deskWin = (HBITMAP)LoadImage(NULL, TEXT("images/deskWin.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
//
//
//Game
PANZER* game(HWND screen, HDC hdc, PANZER *panzer, ENEMY enemyTop, ENEMY enemyBot, ENEMY allyBot, short number, short size);
//
//Menu
void showcursor(bool);
void setCursorPosition(COORD);
short menuStandart(HWND screen, HDC hdc, COORD firstMenuCoord, HBITMAP picture, void(*pointer)(HWND screen, HDC hdc), short items, short step);
short menuProfile(HWND screen, HDC hdc, COORD firstMenuCoord, Profile *profile, void(*pointer)(HWND screen, HDC hdc, Profile *profile, short size, short length, bool showSearch), short items, short size, bool &escape);
void wrighter(HWND screen, RECT rect, HDC hdc, HFONT font, char text[MAXSIZE], short &i, bool &loop, bool &cancel);
Profile* resizeProfile(Profile* profile, short &size, short size_n, short num);
COORD menuStandart2(HWND screen, HDC hdc, COORD firstMenuCoord, HBITMAP picture, void(*pointer)(HWND screen, HDC hdc));
short menuPanzers(HWND screen, HDC hdc, COORD firstMenuCoord, PANZER *panzer, void(*pointer)(HWND screen, HDC hdc, PANZER *panzer, short size, short length, bool showSearch), short items, short size, bool &escape);
PANZER* resizePanzer(PANZER* panzer, short &size, short size_n, short num);
char* shortToChar(short digit);
short healthArmorBalancer(short healthArmor, short left);
short healthArmorBalancer2(short healthArmor, short left);
HBITMAP loadPanzerSkin(PANZER *panzer, HBITMAP picture[4], short number);
HBITMAP loadEnemySkin(ENEMY enemy, HBITMAP picture[4]);
short menuPanzers2(HWND screen, HDC hdc, COORD firstMenuCoord, PANZER *panzer, void(*pointer)(HWND screen, HDC hdc, PANZER *panzer, short size, short length, bool showSearch), short items, short size, bool &escape);
ostream& operator<<(ostream& os, Profile& profile);
istream& operator >> (istream& is, Profile& profile);
ostream& operator<<(ostream& os, PANZER& panzer);
istream& operator >> (istream& is, PANZER& panzer);
//
//Paint
void paintPictures(COORD, HWND, HBITMAP, HDC);
void paintHealthLeftTeam(COORD, HWND, HDC, PANZER *panzer, ENEMY allyBot, short number, short, short, short);
void paintHealthRightTeam(COORD, HWND, HDC, ENEMY enemy, short, short, short panzerArmor);
void paintUnit(COORD, HWND, HBITMAP, HBITMAP, HBITMAP, HBITMAP, HDC, short);
void paintBasesHealth(HWND screen, HDC hdc, short redBaseHealth, short blueBaseHealth);
void paintPanzerMenu(HDC hdc, PANZER *panzer, ENEMY allyBot, short number, short playerHealth, short playerArmor, short allyBotHealth, short allyBotArmor, short &time);
void paintStartMenu(HWND screen, HDC hdc);
void paintBorder(HDC hdc, COORD coord);
void paintProfileMenu(HWND screen, HDC hdc);
void paintMyPanzers(HWND screen, HDC hdc);
void paintPanzerNameModel(HDC hdc);
void paintPanzerCharacteristics(HDC hdc, PANZER *panzer, short number);
void paintPoligonMenu(HDC hdc, PANZER *panzer, short number);
void errorMessage(HDC hdc);
void paintEnemyPower(HWND screen, HDC hdc);
void showPanzers2(HWND screen, HDC hdc, PANZER *panzer, short size, short length, bool showSearch);
void paintStatistics(HWND screen, HDC hdc, PANZER *panzer, short size);
COORD escapeGame(HWND screen, HDC hdc, PANZER *panzer, short number);
void winGame(HWND screen, HDC hdc);
void failGame(HWND screen, HDC hdc);
//
//Field
void backField(short**);
COORD panzerPerimCoord(COORD, COORD[200]);
void backPlayer(short**, COORD);
void backEnemyTop(short**, COORD);
void backEnemyBot(short**field, COORD currentEnemyCoords);
void backAllyBot(short**field, COORD currentEnemyCoords);
void backNull(short**, COORD);
void backRespawn(short**);
void poligonField(short **field);
//
//player
void playerControl(HWND, HDC, COORD&, COORD[200], PANZER *panzer, short**, short&, short, short &, short &, short &, short &, short &enemyBotArmor, short &enemyTopArmor, short speed, bool &exit, short size, short number);
void commonPanzerShot(HWND, HDC, COORD, short, short&, short**, short&, short&, short&, short&, short&, short power);
//
//enemy
void enemyHunterBot(COORD playerCoords, short* turnEnemy, short* X, short* Y, COORD panzerPerimCoords[200], short **field, bool &turn, short speed);
void allyHunterTop(COORD panzerCoords, short* turnPanzer, short* X, short* Y, COORD panzerPerimCoords[200], short **field, bool &turn, short speed);
void allyHunterBot(COORD panzerCoords, short* turnPanzer, short* X, short* Y, COORD panzerPerimCoords[200], short **field, bool &turn, short speed);
void enemyHunterTop(COORD panzerCoords, short* turnPanzer, short* X, short* Y, COORD panzerPerimCoords[200], short **field, bool &turn, short speed);
void commonEnemyShot(HWND screen, HDC hdc, COORD enemyCoords, short turnEnemy, short &bullet,
	short** field, short &playerHealth, short &redBaseHealth, short &allyBotHealth,
	short &playerArmor, short &allyBotArmor, short power);
//
//baseDataFunc
Profile* createNewProfile(HWND screen, HDC hdc, Profile*, short&);
void showProfiles(HWND screen, HDC hdc, Profile *profile, short size, short length, bool showSearch);
Profile* searchProfile(HWND screen, HDC hdc, Profile *profile, short size, short &tempSize);
Profile* deleteProfile(HWND screen, HDC hdc, COORD secondMenuCoord, Profile *profile, short &size);
Profile* enterProfile(HWND screen, HDC hdc, COORD secondMenuCoord, Profile *profile, short &size);
Profile* changeProfileName(HWND screen, HDC hdc, Profile *profile, short &size, short number);
Profile* profileName(HWND screen, HDC hdc, COORD secondMenuCoord, Profile *profile, short &size);
Profile* sortProfilesName(Profile *profile, short size);
void saveProfiles(Profile* profile, short size);
Profile* initProfiles(Profile* profile, short &size);
void profileMain(HWND screen, HDC hdc, Profile *profile, short element);
void showPanzers(HWND screen, HDC hdc, PANZER *panzer, short size, short length, bool showSearch);
PANZER *panzerCreater(HWND screen, HDC hdc, PANZER *panzer, Profile *profile, short &size, bool newPanzer, short number, short element);
PANZER *searchPanzer(HWND screen, HDC hdc, PANZER *profile, short size, short &tempSize);
PANZER *myPanzers(HWND screen, HDC hdc, COORD secondMenuCoord, COORD thirdMenuCoord, PANZER *panzer, Profile *profile, short &size, short element);
PANZER *deletePanzer(HWND screen, HDC hdc, COORD thirdMenuCoord, PANZER *panzer, short &size);
PANZER *enterPoligon(HWND screen, HDC hdc, COORD thirdMenuCoord, PANZER *panzer, short &size);
PANZER *panzerName(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step);
PANZER *panzerModel(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step);
PANZER *panzerHealth(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step, bool newPanzer, short number);
PANZER *panzerArmor(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step, bool newPanzer, short number);
PANZER *panzerSpeed(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step, bool newPanzer, short number);
PANZER *panzerPower(HWND screen, HDC hdc, PANZER *panzer, short &size, short &step, bool newPanzer, short number);
void poligon(HWND screen, HDC hdc, PANZER *panzer, short number, short size);
PANZER *searchPanzer2(HWND screen, HDC hdc, PANZER *panzer, short size, short &tempSize);
PANZER *enterFight(HWND screen, HDC hdc, PANZER *panzer, ENEMY enemyTop, ENEMY enemyBot, ENEMY allyBot, short &size);
PANZER *play(HWND screen, HDC hdc, PANZER *panzer, short size);
PANZER* sortPanzersName(PANZER *panzer, short size);
void savePanzers(PANZER* panzer, short size, short element);
PANZER* initPanzers(PANZER* panzer, short &size, short element);
void savePanzersAfterDelete(short element);
