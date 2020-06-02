#include "Header.h"

//управление танком
void playerControl(HWND screen, HDC hdc, COORD &playerCoords, COORD playerPerimCoords[200], PANZER *panzer, short **field,
	short &turnPlayer, short playerHealth, short &playerBullet, short &enemyTopHealth, short &enemyBotHealth,
	short &blueBaseHealth, short &enemyBotArmor, short &enemyTopArmor, short speed, bool &exit, short size, short number){
	short key = 1, contin = 0;
	if (playerHealth > 0) {
		if (_kbhit())
		{
			key = (int)_getch();
			switch (key) {
			case 246:
			case 'w':
			case (KEY_UP):
				turnPlayer = 3;
				for (short i = speed; i > 0; i--) {
					playerCoords.Y -= i;
					bool collision = false;
					for (short cnt = 0; cnt < 200; cnt++) {
						if (field[BARRIER + playerPerimCoords[cnt].Y - i - 1][BARRIER + playerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + playerPerimCoords[cnt].Y - i - 1][BARRIER + playerPerimCoords[cnt].X] == 3 ||
							field[BARRIER + playerPerimCoords[cnt].Y - i - 1][BARRIER + playerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + playerPerimCoords[cnt].Y - i - 1][BARRIER + playerPerimCoords[cnt].X] == 9 ||
							field[BARRIER + playerPerimCoords[cnt].Y - i - 1][BARRIER + playerPerimCoords[cnt].X] == 10 ||
							field[BARRIER + playerPerimCoords[cnt].Y - i - 1][BARRIER + playerPerimCoords[cnt].X] == 6) {
							playerCoords.Y += i;
							collision = true;
							break;
						}
					}
					if (collision == false) {
						break;
					}
				}
				break;
			case 179:
			case 's':
			case (KEY_DOWN):
				turnPlayer = 1;
				for (short i = speed; i > 0; i--) {
					playerCoords.Y += i;
					bool collision = false;
					for (short cnt = 0; cnt < 200; cnt++) {
						if (field[BARRIER + playerPerimCoords[cnt].Y + i + 1][BARRIER + playerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + playerPerimCoords[cnt].Y + i + 1][BARRIER + playerPerimCoords[cnt].X] == 3 ||
							field[BARRIER + playerPerimCoords[cnt].Y + i + 1][BARRIER + playerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + playerPerimCoords[cnt].Y + i + 1][BARRIER + playerPerimCoords[cnt].X] == 9 ||
							field[BARRIER + playerPerimCoords[cnt].Y + i + 1][BARRIER + playerPerimCoords[cnt].X] == 10 ||
							field[BARRIER + playerPerimCoords[cnt].Y + i + 1][BARRIER + playerPerimCoords[cnt].X] == 6) {
							playerCoords.Y -= i;
							collision = true;
							break;
						}
					}
					if (collision == false) {
						break;
					}
				}
				break;
			case 244:
			case 'a':
			case (KEY_LEFT): {
				turnPlayer = 2;
				for (short i = speed; i > 0; i--) {
					playerCoords.X -= i;
					bool collision = false;
					for (short cnt = 0; cnt < 200; cnt++) {
						if (field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X - i - 1] == 1 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X - i - 1] == 3 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X - i - 1] == 4 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X - i - 1] == 9 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X - i - 1] == 10 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X - i - 1] == 6) {
							playerCoords.X += i;
							collision = true;
							break;
						}
					}
					if (collision == false) {
						break;
					}
				}
				break;
			}
			case 226:
			case 'd':
			case (KEY_RIGHT): {
				turnPlayer = 0;
				for (short i = speed; i > 0; i--) {
					playerCoords.X += i;
					bool collision = false;
					for (short cnt = 0; cnt < 200; cnt++) {
						if (field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X + i + 1] == 1 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X + i + 1] == 3 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X + i + 1] == 4 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X + i + 1] == 9 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X + i + 1] == 10 ||
							field[BARRIER + playerPerimCoords[cnt].Y][BARRIER + playerPerimCoords[cnt].X + i + 1] == 6) {
							playerCoords.X -= i;
							collision = true;
							break;
						}
					}
					if (collision == false) {
						break;
					}
				}
				break;
			}
			case 243:
			case 'e':{
				commonPanzerShot(screen, hdc, playerCoords, turnPlayer, playerBullet, field, enemyTopHealth, blueBaseHealth,
					enemyBotHealth, enemyBotArmor, enemyTopArmor, panzer[number].shotPower);
				playerBullet++;
				if (playerBullet > 10) { playerBullet = 1; }
			break;
			}
			case KEY_SPACE: {
				bool loop = true;
				while (loop) {
					short key = _getch();
					if (key == KEY_SPACE) {
						loop = false;
					}
				}
				break;
			}
			case KEY_ESCAPE: {
				if(exit == true){ exit = false; }
				else {
					COORD coord = escapeGame(screen, hdc, panzer, number);
					exit = (coord.X == 60) ? false : true;
				}
				break;
			}
			case KEY_ENTER: {
				if (exit == true) {
					panzer = panzerCreater(screen, hdc, panzer, nullptr, size, false, number, 0);
				}
				break;
			}
			}
		}
	}
}
//
//логика стрельбы игрока
void commonPanzerShot(HWND screen, HDC hdc, COORD panzerCoords, short turnPanzer, short &bullet, short** field,
	short &enemyTopHealth, short &blueBaseHealth, short &enemyBotHealth, short &enemyBotArmor, short &enemyTopArmor, short power) {
	switch (turnPanzer) {
	case 0: {
		COORD shotCoord = panzerCoords;
		if ((bullet / 2 == 1 && panzerCoords.X != 60 && panzerCoords.Y != 250) ||
			(bullet / 2 == 1 && panzerCoords.X != 60 && panzerCoords.Y != 230) ||
			(bullet / 2 == 1 && panzerCoords.X != 60 && panzerCoords.Y != 270)) {
			paintPictures({ panzerCoords.X + 50, panzerCoords.Y + 12 }, screen, shotFire0, hdc);
		}
		shotCoord.X += 20 * bullet;
		paintPictures({ shotCoord.X + 50, shotCoord.Y + 24 }, screen, shot0, hdc);
		if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 1 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 3 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 9 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 8) {
			paintPictures({ shotCoord.X + 50, shotCoord.Y + 12 }, screen, boom, hdc);
			bullet = 1;
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 3) {
				enemyTopArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 3 && enemyTopArmor <= 0) {
					enemyTopHealth -= power;
					enemyTopArmor = 0;
				}
			}
			
		if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 8) {
			blueBaseHealth -= power;
		}
		if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 9) {
			enemyBotArmor -= (power + 2);
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 9 && enemyBotArmor <= 0) {
				enemyBotHealth -= power;
				enemyBotArmor = 0;
			}
		}
		}
		break;
	}
	case 1: {
		COORD shotCoord = panzerCoords;
		if (bullet / 2 == 1) {
			paintPictures({ panzerCoords.X + 12, panzerCoords.Y + 50 }, screen, shotFire1, hdc);
		}
		shotCoord.Y += 20 * bullet;
		paintPictures({ shotCoord.X + 24, shotCoord.Y + 50 }, screen, shot1, hdc);
		if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 1 ||
			field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 3 ||
			field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 9 ||
			field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 8) {
			paintPictures({ shotCoord.X + 12, shotCoord.Y + 50 }, screen, boom, hdc);
			bullet = 1;
			if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 3) {
				enemyTopArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 3 && enemyTopArmor <= 0) {
					enemyTopHealth -= power;
					enemyTopArmor = 0;
				}
			}
			if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 9) {
				enemyBotArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 9 && enemyBotArmor <= 0) {
					enemyBotHealth -= power;
					enemyBotArmor = 0;
				}
			}
		}
		break;
	}
	case 2: {
		COORD shotCoord = panzerCoords;
		if (bullet / 2 == 1) {
			paintPictures({ panzerCoords.X - 30, panzerCoords.Y + 12 }, screen, shotFire2, hdc);
		}
		shotCoord.X -= 20 * bullet;
		paintPictures({ shotCoord.X, shotCoord.Y + 24 }, screen, shot0, hdc);
		if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 1 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 3 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 9 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 8) {
			paintPictures({ shotCoord.X, shotCoord.Y + 12 }, screen, boom, hdc);
			bullet = 1;
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 3) {
				enemyTopArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 3 && enemyTopArmor <= 0) {
					enemyTopHealth -= power;
					enemyTopArmor = 0;
				}
			}
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 9) {
				enemyBotArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 9 && enemyBotArmor <= 0) {
					enemyBotHealth -= power;
					enemyBotArmor = 0;
				}
			}
		}
		break;
	}
	case 3: {
		COORD shotCoord = panzerCoords;
		if (bullet / 2 == 1) {
			paintPictures({ panzerCoords.X + 12, panzerCoords.Y - 30 }, screen, shotFire3, hdc);
		}
		shotCoord.Y -= 20 * bullet;
		paintPictures({ shotCoord.X + 24, shotCoord.Y }, screen, shot1, hdc);
		if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 1 ||
			field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 3 ||
			field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 9 ||
			field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 8) {
			paintPictures({ shotCoord.X + 12, shotCoord.Y }, screen, boom, hdc);
			bullet = 1;
			if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 3) {
				enemyTopArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 3 && enemyTopArmor <= 0) {
					enemyTopHealth -= power;
					enemyTopArmor = 0;
				}
			}
			if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 9) {
				enemyBotArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 9 && enemyBotArmor <= 0) {
					enemyBotHealth -= power;
					enemyBotArmor = 0;
				}
			}
		}
		break;
	}
	}
}