#include "Header.h"

PANZER* game(HWND screen, HDC hdc, PANZER *panzer, ENEMY enemyTop, ENEMY enemyBot, ENEMY allyBot, short number, short size) {
	HBITMAP playerPicture[4] = { 0,0,0,0 };
	HBITMAP enemyTopPicture[4] = { 0,0,0,0 };
	HBITMAP enemyBotPicture[4] = { 0,0,0,0 };
	HBITMAP allyBotPicture[4] = { 0,0,0,0 };
	playerPicture[4] = loadPanzerSkin(panzer, playerPicture, number);
	enemyTopPicture[4] = loadEnemySkin(enemyTop, enemyTopPicture);
	enemyBotPicture[4] = loadEnemySkin(enemyBot, enemyBotPicture);
	allyBotPicture[4] = loadEnemySkin(allyBot, allyBotPicture);
	COORD startFieldCoord = { 0,0 };
	COORD deathShotCoord = { 325,585 };
	COORD playerMenuCoord = { 70, 595 };
	COORD allyBotMenuCoord = { 630, 595 };
	COORD redBaseCoords = { 60, 260 };
	COORD blueBaseCoords = { 830, 260 };
	COORD playerCoords = { 60, 90 };
	COORD enemyTopCoords = { 830, 90 };
	COORD enemyBotCoords = { 830, 440 };
	COORD allyBotCoords = { 60, 440 };
	COORD tempPlayerCoords = { 60, 90 };
	COORD tempEnemyTopCoords = { 830,90 };
	COORD tempEnemyBotCoords = { 830,440 };
	COORD tempAllyBotCoords = { 60,440 };
	COORD playerDead = playerCoords;
	COORD enemyTopDead = enemyTopCoords;
	COORD enemyBotDead = enemyBotCoords;
	COORD allyBotDead = allyBotCoords;
	COORD playerPerimCoords[200] = { 60, 90 };
	COORD enemyTopPerimCoords[200] = { 830,90 };
	COORD enemyBotPerimCoords[200] = { 830,440 };
	COORD allyBotPerimCoords[200] = { 60, 440 };
	bool turn1 = true, turn2 = true, turn3 = true, gameOver = false;
	short redBaseHealth = 200, blueBaseHealth = 200; //здоровье баз
	short respawnEnemyTopTime = 0, respawnEnemyBotTime = 0, respawnPlayerTime = 0, respawnAllyBotTime = 0; // время возрождения
	short enemyTopBullet = 1, enemyBotBullet = 1, playerBullet = 1, allyBotBullet = 1, redBaseBullet = 1, blueBaseBullet = 1; // пули
	short enemyTopHealth = enemyTop.health, enemyBotHealth = enemyBot.health, playerHealth = panzer[number].health, allyBotHealth = allyBot.health; // здоровье танков
	short enemyTopArmor = enemyTop.armor, enemyBotArmor = enemyBot.armor, playerArmor = panzer[number].armor, allyBotArmor = allyBot.armor; //броня танков
	short turnEnemyTop = 0, turnEnemyBot = 0, turnPlayer = 0, turnAllyBot = 0;// поворот
	short **field = new short*[ARR_HEIGHT];
	long counter = 0;
	short time = 0, random = rand()%5 + 1;
	backField(field);
	while (!gameOver) {
		counter++;
		if (counter % 12 == 0) {
			time = counter / 12;
		}
		if (counter % 240 == 0) {
			random = rand() % 5 + 1;
		}
			playerPerimCoords[200] = panzerPerimCoord(playerCoords, playerPerimCoords);
			//
			//заполняем массивы танков
			backNull(field, tempPlayerCoords);
			backNull(field, tempEnemyTopCoords);
			backNull(field, tempEnemyBotCoords);
			backNull(field, tempAllyBotCoords);
			backRespawn(field);
			backPlayer(field, playerCoords);
			backEnemyTop(field, enemyTopCoords);
			backEnemyBot(field, enemyBotCoords);
			backAllyBot(field, allyBotCoords);
			tempPlayerCoords = playerCoords;
			tempEnemyTopCoords = enemyTopCoords;
			tempEnemyBotCoords = enemyBotCoords;
			tempAllyBotCoords = allyBotCoords;
			//
			//рисуем карту
			paintPictures(startFieldCoord, screen, map, hdc);
			paintPanzerMenu(hdc, panzer, allyBot, number, playerHealth, playerArmor, allyBotHealth, allyBotArmor, time);
			paintUnit(playerMenuCoord, screen, playerPicture[0], playerPicture[1], playerPicture[2], playerPicture[3], hdc, turnPlayer);
			paintUnit(allyBotMenuCoord, screen, allyBotPicture[0], allyBotPicture[1], allyBotPicture[2], allyBotPicture[3], hdc, turnAllyBot);
			//
			//верхний враг
			if (enemyTopHealth <= 0 && respawnEnemyTopTime == 0) {
				enemyTopDead = enemyTopCoords;
				turnEnemyTop = 0;
				enemyTopCoords = { 830, 90 };
			}
			if (enemyTopHealth > 0) {
				paintHealthRightTeam(enemyTopCoords, screen, hdc, enemyTop, turnEnemyTop, enemyTopHealth, enemyTopArmor);
				if (playerHealth > 0 && random == 2) { // бот враг начинает охоту
					enemyHunterTop(playerCoords, &turnEnemyTop, &enemyTopCoords.X, &enemyTopCoords.Y, enemyTopPerimCoords, field, turn1, enemyTop.speed);
				}
				else if(playerHealth <= 0 && random == 2){
					enemyHunterTop(redBaseCoords, &turnEnemyTop, &enemyTopCoords.X, &enemyTopCoords.Y, enemyTopPerimCoords, field, turn1, enemyTop.speed);
				}
				if (allyBotHealth > 0 && random == 1) { // бот враг начинает охоту
					enemyHunterTop(allyBotCoords, &turnEnemyTop, &enemyTopCoords.X, &enemyTopCoords.Y, enemyTopPerimCoords, field, turn1, enemyTop.speed);
				}
				else if(allyBotHealth <= 0 && random == 1) {
					enemyHunterTop(redBaseCoords, &turnEnemyTop, &enemyTopCoords.X, &enemyTopCoords.Y, enemyTopPerimCoords, field, turn1, enemyTop.speed);
				}
				if (random == 3 || random == 4 || random == 5) { // бот враг начинает охоту
					enemyHunterTop(redBaseCoords, &turnEnemyTop, &enemyTopCoords.X, &enemyTopCoords.Y, enemyTopPerimCoords, field, turn1, enemyTop.speed);
				}
			}
			else {
				++respawnEnemyTopTime;
				paintPictures(enemyTopDead, screen, deathBlue, hdc);
				if (respawnEnemyTopTime % 3 && respawnEnemyTopTime <= 30) {
					paintPictures({ enemyTopDead.X + 12, enemyTopDead.Y + 12 }, screen, boom3, hdc);
				}
				if (respawnEnemyTopTime == 100) {
					enemyTopArmor = enemyTop.armor;
					enemyTopHealth = enemyTop.health;
					enemyTopCoords = { 830, 90 };
					respawnEnemyTopTime = 0;
				}
			}
			//
			//нижний враг
			if (enemyBotHealth <= 0 && respawnEnemyBotTime == 0) {
				enemyBotDead = enemyBotCoords;
				turnEnemyBot = 0;
				enemyBotCoords = { 830, 440 };
			}
			if (enemyBotHealth > 0) {
				paintHealthRightTeam(enemyBotCoords, screen, hdc, enemyBot, turnEnemyBot, enemyBotHealth, enemyBotArmor);
				if (allyBotHealth > 0 && random == 3) {// бот враг начинает охоту
					enemyHunterBot(allyBotCoords, &turnEnemyBot, &enemyBotCoords.X, &enemyBotCoords.Y, enemyBotPerimCoords, field, turn2, enemyBot.speed);
				}
				else if (allyBotHealth <= 0 && random == 3) {
					enemyHunterBot(redBaseCoords, &turnEnemyBot, &enemyBotCoords.X, &enemyBotCoords.Y, enemyBotPerimCoords, field, turn2, enemyBot.speed);
				}
				if (random == 2 || random == 4 || random == 5) {// бот враг начинает охоту
					enemyHunterBot(redBaseCoords, &turnEnemyBot, &enemyBotCoords.X, &enemyBotCoords.Y, enemyBotPerimCoords, field, turn2, enemyBot.speed);
				}
				if (playerHealth > 0 && random == 1) {// бот враг начинает охоту
					enemyHunterBot(playerCoords, &turnEnemyBot, &enemyBotCoords.X, &enemyBotCoords.Y, enemyBotPerimCoords, field, turn2, enemyBot.speed);
				}
				else if (playerHealth <= 0 && random == 1) {
					enemyHunterBot(redBaseCoords, &turnEnemyBot, &enemyBotCoords.X, &enemyBotCoords.Y, enemyBotPerimCoords, field, turn2, enemyBot.speed);
				}
			}
			else {
				++respawnEnemyBotTime;
				paintPictures(enemyBotDead, screen, deathBlue, hdc);
				if (respawnEnemyBotTime % 3 && respawnEnemyBotTime <= 30) {
					paintPictures({ enemyBotDead.X + 12, enemyBotDead.Y + 12 }, screen, boom3, hdc);
				}
				if (respawnEnemyBotTime == 100) {
					enemyBotArmor = enemyBot.armor;
					enemyBotHealth = enemyBot.health;
					enemyBotCoords = { 830, 440 };
					respawnEnemyBotTime = 0;
				}
			}
			//
			//союзник
			if (allyBotHealth <= 0 && respawnAllyBotTime == 0) {
				allyBotDead = allyBotCoords;
				turnAllyBot = 0;
				allyBotCoords = { 60, 440 };
			}
			if (allyBotHealth > 0) {
				paintHealthLeftTeam(allyBotCoords, screen, hdc, nullptr, allyBot,  NULL, turnAllyBot, allyBotHealth, allyBotArmor);
				if ((enemyBotHealth > 0 && random == 1) || (enemyBotHealth > 0 && random == 2)) {// бот союзник начинает охоту
					allyHunterBot(enemyBotCoords, &turnAllyBot, &allyBotCoords.X, &allyBotCoords.Y, allyBotPerimCoords, field, turn3, allyBot.speed);
				}
				else if ((enemyBotHealth <= 0 && random == 1) || (enemyBotHealth <= 0 && random == 2)) {
					allyHunterBot(blueBaseCoords, &turnAllyBot, &allyBotCoords.X, &allyBotCoords.Y, allyBotPerimCoords, field, turn3, allyBot.speed);
				}
				if ((enemyTopHealth > 0 && random == 3) || (enemyTopHealth > 0 && random == 4)) {// бот союзник начинает охоту
					allyHunterBot(enemyTopCoords, &turnAllyBot, &allyBotCoords.X, &allyBotCoords.Y, allyBotPerimCoords, field, turn3, allyBot.speed);
				}
				else if ((enemyTopHealth <= 0 && random == 3) || (enemyTopHealth <= 0 && random == 4)) {
					allyHunterBot(blueBaseCoords, &turnAllyBot, &allyBotCoords.X, &allyBotCoords.Y, allyBotPerimCoords, field, turn3, allyBot.speed);
				}
				if (random == 5) {// бот союзник начинает охоту
					allyHunterBot(blueBaseCoords, &turnAllyBot, &allyBotCoords.X, &allyBotCoords.Y, allyBotPerimCoords, field, turn3, allyBot.speed);
				}
			}
			else {
				++respawnAllyBotTime;
				paintPictures(allyBotDead, screen, deathRed, hdc);
				if (respawnAllyBotTime % 3 && respawnAllyBotTime <= 30) {
					paintPictures({ allyBotDead.X + 12, allyBotDead.Y + 12 }, screen, boom2, hdc);
				}
				if (respawnAllyBotTime == 100) {
					allyBotArmor = allyBot.armor;
					allyBotHealth = allyBot.health;
					allyBotCoords = { 60, 440 };
					respawnAllyBotTime = 0;
				}
			}
			/*if (enemyBotHealth <= 0 && allyBotHealth > 0) {
				if (enemyTopHealth <= 0) {
					allyHunterBot(blueBaseCoords, &turnAllyBot, &allyBotCoords.X, &allyBotCoords.Y, allyBotPerimCoords, field, turn3, allyBot.speed);
				}
				else {
					allyHunterTop(enemyTopCoords, &turnAllyBot, &allyBotCoords.X, &allyBotCoords.Y, allyBotPerimCoords, field, turn3, allyBot.speed);
				}
			}*/
			//
			//игрок
			if (playerHealth <= 0 && respawnPlayerTime == 0) {
				playerDead = playerCoords;
				turnPlayer = 0;
				playerCoords = { 60, 90 };
			}
			if (playerHealth > 0) {
				paintHealthLeftTeam(playerCoords, screen, hdc, panzer, allyBot, number, turnPlayer, playerHealth, playerArmor);
			}
			else {
				++respawnPlayerTime;
				paintPictures(playerDead, screen, deathRed, hdc);
				if (respawnPlayerTime % 3 && respawnPlayerTime <= 30) {
					paintPictures({ playerDead.X + 12, playerDead.Y + 12 }, screen, boom2, hdc);
				}
				if (respawnPlayerTime == 100) {
					playerArmor = panzer[number].armor;
					playerHealth = panzer[number].health;
					playerCoords = { 60, 90 };
					respawnPlayerTime = 0;
				}
			}
			//
			//рисуем рисунки
			paintUnit(enemyTopCoords, screen, enemyTopPicture[0], enemyTopPicture[1], enemyTopPicture[2], enemyTopPicture[3], hdc, turnEnemyTop);
			paintUnit(enemyBotCoords, screen, enemyBotPicture[0], enemyBotPicture[1], enemyBotPicture[2], enemyBotPicture[3], hdc, turnEnemyBot);
			paintUnit(playerCoords, screen, playerPicture[0], playerPicture[1], playerPicture[2], playerPicture[3], hdc, turnPlayer);
			paintUnit(allyBotCoords, screen, allyBotPicture[0], allyBotPicture[1], allyBotPicture[2], allyBotPicture[3], hdc, turnAllyBot);
			paintBasesHealth(screen, hdc, redBaseHealth, blueBaseHealth);
			//
			//верхний враг стреляет
			if (enemyTopHealth > 0) {
				if ((enemyTopCoords.X - playerCoords.X < 200 && enemyTopCoords.Y - playerCoords.Y < 50 && playerHealth > 0) ||
					(enemyTopCoords.Y - playerCoords.Y < 200 && enemyTopCoords.X - playerCoords.X < 50 && playerHealth > 0) ||
					(enemyTopCoords.X - allyBotCoords.X < 200 && enemyTopCoords.Y - allyBotCoords.Y < 50 && allyBotHealth > 0) ||
					(enemyTopCoords.Y - allyBotCoords.Y < 200 && enemyTopCoords.X - allyBotCoords.X < 50 && allyBotHealth > 0) ||
					(enemyTopCoords.X - redBaseCoords.X < 250 && enemyTopCoords.Y - redBaseCoords.Y < 50)) {
					commonEnemyShot(screen, hdc, enemyTopCoords, turnEnemyTop, enemyTopBullet, field, playerHealth, redBaseHealth, allyBotHealth, playerArmor, allyBotArmor, enemyTop.shotPower);
					enemyTopBullet++;
					if (enemyTopBullet > 10) { enemyTopBullet = 1; }
				}
			}
			//
			//нижний враг стреляет
			if (enemyBotHealth > 0) {
				if ((enemyBotCoords.X - allyBotCoords.X < 200 && enemyBotCoords.Y - allyBotCoords.Y < 50 && allyBotHealth > 0) ||
					(enemyBotCoords.Y - allyBotCoords.Y < 200 && enemyBotCoords.X - allyBotCoords.X < 50 && allyBotHealth > 0) ||
					(enemyBotCoords.X - playerCoords.X < 200 && enemyBotCoords.Y - playerCoords.Y < 50 && playerHealth > 0) ||
					(enemyBotCoords.Y - playerCoords.Y < 200 && enemyBotCoords.X - playerCoords.X < 50 && playerHealth > 0) ||
					(enemyBotCoords.X - redBaseCoords.X < 250 && enemyBotCoords.Y - redBaseCoords.Y < 50)) {
					commonEnemyShot(screen, hdc, enemyBotCoords, turnEnemyBot, enemyBotBullet, field, playerHealth, redBaseHealth, allyBotHealth, playerArmor, allyBotArmor, enemyBot.shotPower);
					enemyBotBullet++;
					if (enemyBotBullet > 10) { enemyBotBullet = 1; }
				}
			}
			//
			//союзник стреляет
			if (allyBotHealth > 0) {
				if ((enemyBotCoords.X - allyBotCoords.X < 200 && enemyBotCoords.Y - allyBotCoords.Y < 50 && enemyBotHealth > 0) ||
					(enemyBotCoords.Y - allyBotCoords.Y < 200 && enemyBotCoords.X - allyBotCoords.X < 50 && enemyBotHealth > 0) ||
					(enemyTopCoords.X - allyBotCoords.X < 200 && enemyTopCoords.Y - allyBotCoords.Y < 50 && enemyTopHealth > 0) ||
					(enemyTopCoords.Y - allyBotCoords.Y < 200 && enemyTopCoords.X - allyBotCoords.X < 50 && enemyTopHealth > 0) ||
					(blueBaseCoords.X - allyBotCoords.X < 250 && blueBaseCoords.Y - allyBotCoords.Y < 50)) {
					commonPanzerShot(screen, hdc, allyBotCoords, turnAllyBot, allyBotBullet, field, enemyTopHealth, blueBaseHealth, enemyBotHealth, enemyBotArmor, enemyTopArmor, allyBot.shotPower);
					allyBotBullet++;
					if (allyBotBullet > 10) { allyBotBullet = 1; }
				}
			}
			//
			//синяя база стреляет
			if ((blueBaseCoords.X - allyBotCoords.X < 250 && blueBaseCoords.Y - allyBotCoords.Y < 50) ||
				(blueBaseCoords.Y - allyBotCoords.Y < 250 && blueBaseCoords.X - allyBotCoords.X < 50) ||
				(blueBaseCoords.X - playerCoords.X < 250 && blueBaseCoords.Y - playerCoords.Y < 50) ||
				(blueBaseCoords.Y - playerCoords.Y < 250 && blueBaseCoords.X - playerCoords.X < 50)) {
				commonEnemyShot(screen, hdc, blueBaseCoords, 0, blueBaseBullet, field, playerHealth, redBaseHealth, allyBotHealth, playerArmor, allyBotArmor, 3);
				commonEnemyShot(screen, hdc, { 830, 240 }, 0, blueBaseBullet, field, playerHealth, redBaseHealth, allyBotHealth, playerArmor, allyBotArmor, 3);
				commonEnemyShot(screen, hdc, { 830, 280 }, 0, blueBaseBullet, field, playerHealth, redBaseHealth, allyBotHealth, playerArmor, allyBotArmor, 3);
				blueBaseBullet++;
				if (blueBaseBullet > 10) { blueBaseBullet = 1; }
			}
			//
			//красная база стреляет
			if ((enemyBotCoords.X - redBaseCoords.X < 250 && enemyBotCoords.Y - redBaseCoords.Y < 50) ||
				(enemyBotCoords.Y - redBaseCoords.Y < 250 && enemyBotCoords.X - redBaseCoords.X < 50) ||
				(enemyTopCoords.X - redBaseCoords.X < 250 && enemyTopCoords.Y - redBaseCoords.Y < 50) ||
				(enemyTopCoords.Y - redBaseCoords.Y < 250 && enemyTopCoords.X - redBaseCoords.X < 50)) {
				commonPanzerShot(screen, hdc, redBaseCoords, 0, redBaseBullet, field, enemyTopHealth, blueBaseHealth, enemyBotHealth, enemyBotArmor, enemyTopArmor, 3);
				commonPanzerShot(screen, hdc, { 60, 240 }, 0, redBaseBullet, field, enemyTopHealth, blueBaseHealth, enemyBotHealth, enemyBotArmor, enemyTopArmor, 3);
				commonPanzerShot(screen, hdc, { 60, 280 }, 0, redBaseBullet, field, enemyTopHealth, blueBaseHealth, enemyBotHealth, enemyBotArmor, enemyTopArmor, 3);
				redBaseBullet++;
				if (redBaseBullet > 10) { redBaseBullet = 1; }
			}
			if (redBaseHealth <= 0) { 
				gameOver = true;
			}
			if (blueBaseHealth <= 0) {
				gameOver = true;
				panzer[number].wins++;
				panzer[number].battles++;
				panzer[number].commandPoints++;
				winGame(screen, hdc);
			}
			playerControl(screen, hdc, playerCoords, playerPerimCoords, panzer, field, turnPlayer, playerHealth, playerBullet, enemyTopHealth, enemyBotHealth, blueBaseHealth, enemyBotArmor, enemyTopArmor, panzer[number].speed, gameOver, size, number);	
			if (gameOver == true && blueBaseHealth > 0) {
				panzer[number].defeat++;
				panzer[number].battles++;
				failGame(screen, hdc);
			}
			Sleep(80);
		}
	for (int i = 0; i < ARR_HEIGHT; i++) {
		delete[] field[i];
	}
	delete[] field;
	return panzer;
}