#include "Header.h"

//прорисовка массива поля
void backField(short**field) {
	for (int i = 0; i < ARR_HEIGHT; i++) {
		field[i] = new short[ARR_WIDTH];
		for (int j = 0; j < ARR_WIDTH; j++) {
			field[i][j] = 0;
		}
	}
	for (int i = BARRIER + 6, k = BARRIER + HEIGHT + 14; i > 22, k < ARR_HEIGHT - 2; i--, k++) { // верхние, нижние границы
		for (int j = 0; j < ARR_WIDTH; j++) {
			field[i][j] = 1;
			field[k][j] = 1;
		}
	}
	for (int i = BARRIER + 160; i < BARRIER + 418; i++) { //територия красной, синей баз
		for (int j = 0, k = ARR_WIDTH - BARRIER - 148; j < BARRIER + 148, k < ARR_WIDTH; j++, k++) {
			field[i][j] = 1;
			field[i][k] = 1;
		}
	}
	for (int i = BARRIER + 190; i < BARRIER + 390; i++) { // красная, синяя базы
		for (int j = 0, k = ARR_WIDTH - BARRIER - 110; j < BARRIER + 110, k < ARR_WIDTH; j++, k++) {
			field[i][j] = 7;
			field[i][k] = 8;
		}
	}
	for (int i = BARRIER + 190; i < BARRIER + 390; i++) { // красная, синяя базы (порог)
		for (int j = BARRIER + 110, k = ARR_WIDTH - BARRIER - 148; j < BARRIER + 148, k < ARR_WIDTH - BARRIER - 110; j++, k++) {
			field[i][j] = 4;
			field[i][k] = 4;
		}
	}
	for (int i = 0; i < ARR_HEIGHT; i++) { // левая, правая границы
		for (int j = 0, k = ARR_WIDTH - BARRIER - 50; j < BARRIER + 50, k < ARR_WIDTH; j++, k++) {
			field[i][j] = 1;
			field[i][k] = 1;
		}
	}
	for (int i = BARRIER + 65, k = ARR_HEIGHT - BARRIER - 35; i > 30 , k < ARR_HEIGHT; i--, k++) { // угловые выступы
		for (int j = 0, c = ARR_WIDTH - BARRIER - 150; j < BARRIER + 150, c < ARR_WIDTH; j++, c++) {
			field[i][j] = 1;
			field[i][c] = 1;
			field[k][j] = 1;
			field[k][c] = 1;
		}
	}
	for (int i = BARRIER + 110, k = BARRIER + 335; i < BARRIER + 240, k < BARRIER + 465; i++, k++) { // центральные клумбы
		for (int j = BARRIER + 250, c = BARRIER + 525; j < BARRIER + 425, c < BARRIER + 700; j++, c++) {
			field[i][j] = 1;
			field[i][c] = 1;
			field[k][j] = 1;
			field[k][c] = 1;
		}
	}
}
//
//фиксируются координаты по периметру танка
COORD panzerPerimCoord(COORD startPanzerCoord, COORD panzerPerimCoords[200]) {
	panzerPerimCoords[0].X = startPanzerCoord.X;
	panzerPerimCoords[0].Y = startPanzerCoord.Y;
	for (int i = 1; i < 50; i++) {
		panzerPerimCoords[i].X = panzerPerimCoords[i - 1].X + 1;
		panzerPerimCoords[i].Y = startPanzerCoord.Y;
	}
	for (int i = 50; i < 100; i++) {
		panzerPerimCoords[i].X = panzerPerimCoords[i - 1].X;
		panzerPerimCoords[i].Y = panzerPerimCoords[i - 1].Y + 1;
	}
	for (int i = 100; i < 150; i++) {
		panzerPerimCoords[i].X = panzerPerimCoords[i - 1].X - 1;
		panzerPerimCoords[i].Y = panzerPerimCoords[i - 1].Y;
	}
	for (int i = 150; i < 200; i++) {
		panzerPerimCoords[i].X = panzerPerimCoords[i - 1].X;
		panzerPerimCoords[i].Y = panzerPerimCoords[i - 1].Y - 1;
	}
	return panzerPerimCoords[200];
}
//
//заполнение массивов танков
void backPlayer(short**field, COORD currentPlayerCoords) {
	for (int i = BARRIER + currentPlayerCoords.X; i < BARRIER + currentPlayerCoords.X + 50; i++) {
		for (int j = BARRIER + currentPlayerCoords.Y; j < BARRIER + currentPlayerCoords.Y + 50; j++) {
			field[j][i] = 2;
		}
	}
}
void backEnemyTop(short**field, COORD currentEnemyCoords) {
	for (int i = BARRIER + currentEnemyCoords.X; i < BARRIER + currentEnemyCoords.X + 50; i++) {
		for (int j = BARRIER + currentEnemyCoords.Y; j < BARRIER + currentEnemyCoords.Y + 50; j++) {
			field[j][i] = 3;
		}
	}
}
void backEnemyBot(short**field, COORD currentEnemyCoords) {
	for (int i = BARRIER + currentEnemyCoords.X; i < BARRIER + currentEnemyCoords.X + 50; i++) {
		for (int j = BARRIER + currentEnemyCoords.Y; j < BARRIER + currentEnemyCoords.Y + 50; j++) {
			field[j][i] = 9;
		}
	}
}
void backAllyBot(short**field, COORD currentAllyCoords) {
	for (int i = BARRIER + currentAllyCoords.X; i < BARRIER + currentAllyCoords.X + 50; i++) {
		for (int j = BARRIER + currentAllyCoords.Y; j < BARRIER + currentAllyCoords.Y + 50; j++) {
			field[j][i] = 10;
		}
	}
}
void backNull(short**field, COORD currentUnitCoords) {
	for (int i = BARRIER + currentUnitCoords.X; i < BARRIER + currentUnitCoords.X + 50; i++) {
		for (int j = BARRIER + currentUnitCoords.Y; j < BARRIER + currentUnitCoords.Y + 50; j++) {
			field[j][i] = 0;
		}
	}
}
//
//обновление массива места возрождения
void backRespawn(short**field) {
	for (int i = BARRIER + 60, k = BARRIER + 420; i < BARRIER + 160, k < ARR_HEIGHT - BARRIER - 30; i++, k++) {
		for (int j = BARRIER + 50, c = ARR_WIDTH - BARRIER - 145; j < BARRIER + 145, c < ARR_WIDTH - BARRIER - 50; j++, c++) {
			field[i][j] = 5;
			field[i][c] = 6;
			field[k][j] = 5;
			field[k][c] = 6;
		}
	}
}
//
//массив поля полигона
void poligonField(short **field) {
	for (int i = 0; i < WID_HEIG + TOP_Y; i++) {
		field[i] = new short[WID_HEIG + LEFT_X];
		for (int j = 0; j < WID_HEIG + LEFT_X; j++) {
			field[i][j] = 0;
		}
	}
	for (int i = BARRIER + TOP_Y + 35, k = WID_HEIG + TOP_Y - BARRIER - 60; i > 0, k < WID_HEIG + TOP_Y; i--, k++) { // верхние, нижние границы
		for (int j = 0; j < WID_HEIG + LEFT_X; j++) {
			field[i][j] = 1;
			field[k][j] = 1;
		}
	}
	for (int i = 0; i < WID_HEIG + TOP_Y; i++) { // левая, правая границы
		for (int j = BARRIER + LEFT_X + 45, k = WID_HEIG + LEFT_X - BARRIER - 50; j > LEFT_X+5, k < WID_HEIG + LEFT_X; j--, k++) {
			field[i][j] = 1;
			field[i][k] = 1;
		}
	}
}

