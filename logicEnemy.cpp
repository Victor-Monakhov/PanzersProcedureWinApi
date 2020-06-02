#include "Header.h"

//мозги правого бота верх
void enemyHunterTop(COORD panzerCoords, short* turnPanzer, short* X, short* Y, COORD panzerPerimCoords[200],short **field, bool &turn, short speed) {
	panzerPerimCoords[200] = panzerPerimCoord({*X,*Y}, panzerPerimCoords);
	if (turn == false && *turnPanzer == 0) { *turnPanzer = 3; }
	else if (turn == false) { *turnPanzer -= 1; }
	switch (*turnPanzer) {
	case 0: {
		turn = true;
		if (*X > panzerCoords.X) {
			if (*X > panzerCoords.X + 190 || *Y > panzerCoords.Y + 30 || *Y < panzerCoords.Y - 30) {
				*X -= speed;
					for (short cnt = 0; cnt < 200; cnt++) {
						if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 9 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 10 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 5) {
							*X += speed;
							if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X -speed - 1] == 1 ||
								field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X -speed - 1] == 9 ||
								field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X -speed- 1] == 4 ||
								field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 5) {
								*turnPanzer += 1;
								*Y -= speed;
								for (short cnt1 = 0; cnt1 < 200; cnt1++) {
									turn = false;
									if (field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 1 ||
										field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 2 ||
										field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 9 ||
										field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 10 ||
										field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 4 ||
										field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 5) {
										turn = true;
										*Y += speed;
										break;
									}
								}
							}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer += 1;
		}
		break;
	}
	case 1: {
		turn = true;
		if (*Y > panzerCoords.Y) {
			if (*Y > panzerCoords.Y + 190 || *X > panzerCoords.X + 30 || *X < panzerCoords.X - 30) {
				*Y -= speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 10 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 5) {
						*Y += speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 5){
							*turnPanzer += 1;
							*X += speed;
							for (short cnt = 0; cnt < 200; cnt++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed+1] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 10 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 5) {
									turn = true;
									*X -= speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer += 1;
		}
		break;
	}
	case 2: {
		turn = true;
		if (*X < panzerCoords.X) {
			if (*X < panzerCoords.X - 190 || *Y > panzerCoords.Y + 30 || *Y < panzerCoords.Y - 30) {
				*X += speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed+1] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 10 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 5) {
						*X -= speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 9 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 5) {
							*turnPanzer += 1;
							*Y += speed;
							for (short cnt = 0; cnt < 200; cnt++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 10 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 5) {
									turn = true;
									*Y -= speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer += 1;
		}
		break;
	}
	case 3: {
		turn = true;
		if (*Y < panzerCoords.Y) {
			if (*Y < panzerCoords.Y - 190 || *X > panzerCoords.X + 30 || *X < panzerCoords.X - 30) {
				*Y += speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 10 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 5) {
						*Y -= speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 5) {
							*turnPanzer += 1;
							*X -= speed;
							for (short cnt = 0; cnt < 200; cnt++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X -speed - 1] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 10 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 5) {
									turn = true;
									*X += speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer += 1;
		}
		break;
	}
	}
	if (*turnPanzer > 3) { *turnPanzer = 0; }
}
//
//мозги правого бота низ
void enemyHunterBot(COORD panzerCoords, short* turnPanzer, short* X, short* Y, COORD panzerPerimCoords[200], short **field, bool &turn, short speed) {
	panzerPerimCoords[200] = panzerPerimCoord({ *X,*Y }, panzerPerimCoords);
	if (turn == false && *turnPanzer == 3) { *turnPanzer = 0; }
	else if (turn == false) { *turnPanzer += 1; }
	switch (*turnPanzer) {
	case 0: {
		turn = true;
		if (*X > panzerCoords.X) {
			if (*X > panzerCoords.X + 190 || *Y > panzerCoords.Y + 30 || *Y < panzerCoords.Y - 30) {
				*X -= speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 10 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 5) {
						*X += speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 3 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 5) {
							*turnPanzer -= 1;
							*Y += speed;
							for (short cnt1 = 0; cnt1 < 200; cnt1++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 10 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 5) {
									turn = true;
									*Y -= speed;
									break;
								}
							}
						}
					break;
					}
				}
			}
		}
		else {
			*turnPanzer -= 1;
		}
		break;
	}
	case 1: {
		turn = true;
		if (*Y > panzerCoords.Y) {
			if (*Y > panzerCoords.Y + 190 || *X > panzerCoords.X + 30 || *X < panzerCoords.X - 30) {
				*Y -= speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 10 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 5) {
						*Y += speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 5) {
							*turnPanzer -= 1;
							*X -= speed;
							for (short cnt1 = 0; cnt1 < 200; cnt1++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 10 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 5) {
									turn = true;
									*X += speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer -= 1;
		}
		break;
	}
	case 2: {
		turn = true;
		if (*X < panzerCoords.X) {
			if (*X < panzerCoords.X - 190 || *Y > panzerCoords.Y + 30 || *Y < panzerCoords.Y - 30) {
				*X += speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 10 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 5) {
						*X -= speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 3 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 5) {
							*turnPanzer -= 1;
							*Y -= speed;
							for (short cnt1 = 0; cnt1 < 200; cnt1++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 10 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 5) {
									turn = true;
									*Y += speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer -= 1;
		}
		break;
	}
	case 3: {
		turn = true;
		if (*Y < panzerCoords.Y) {
			if (*Y < panzerCoords.Y - 190 || *X > panzerCoords.X + 30 || *X < panzerCoords.X - 30){
				*Y += speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y + speed +1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 10 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 5) {
						*Y -= speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 5) {
							*turnPanzer -= 1;
							*X += speed;
							for (short cnt1 = 0; cnt1 < 200; cnt1++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 10 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 5) {
									turn = true;
									*X -= speed;
								break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer -= 1;
		}
		break;
	}
	}
	if (*turnPanzer < 0) { *turnPanzer = 3; }
}
//
//мозги левого бота верх
void allyHunterTop(COORD panzerCoords, short* turnPanzer, short* X, short* Y, COORD panzerPerimCoords[200], short **field, bool &turn, short speed) {
	panzerPerimCoords[200] = panzerPerimCoord({ *X,*Y }, panzerPerimCoords);
	if (turn == false && *turnPanzer == 3) { *turnPanzer = 0; }
	else if (turn == false) { *turnPanzer += 1; }
	switch (*turnPanzer) {
	case 0: {
		turn = true;
		if (*X < panzerCoords.X) {
			if (*X < panzerCoords.X - 140 || *Y > panzerCoords.Y + 10 || *Y < panzerCoords.Y - 10) {
				*X += speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 6) {
						*X -= speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 6) {
							*turnPanzer -= 1;
							*Y -= speed;
							for (short cnt1 = 0; cnt1 < 200; cnt1++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y - speed - 1][BARRIER + panzerPerimCoords[cnt1].X] == 6) {
									turn = true;
									*Y += speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer -= 1;
		}
		break;
	}
	case 1: {
		turn = true;
		if (*Y < panzerCoords.Y) {
			if (*Y < panzerCoords.Y - 140 || *X > panzerCoords.X + 10 || *X < panzerCoords.X - 10) {
				*Y += speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y + speed+1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
						*Y -= speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
							*turnPanzer -= 1;
							*X += speed;
							for (short cnt1 = 0; cnt1 < 200; cnt1++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X + speed + 1] == 6) {
									turn = true;
									*X -= speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer -= 1;
		}
		break;
	}
	case 2: {
		turn = true;
		if (*X > panzerCoords.X) {
			if (*X > panzerCoords.X + 190 || *Y > panzerCoords.Y + 10 || *Y < panzerCoords.Y - 10) {
				*X -= speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 6) {
						*X += speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 6) {
							*turnPanzer -= 1;
							*Y += speed;
							for (short cnt1 = 0; cnt1 < 200; cnt1++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y + speed + 1][BARRIER + panzerPerimCoords[cnt1].X] == 6) {
									turn = true;
									*Y -= speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer -= 1;
		}
		break;
	}
	case 3: {
		turn = true;
		if (*Y > panzerCoords.Y) {
			if (*Y > panzerCoords.Y + 190 || *X > panzerCoords.X + 10 || *X < panzerCoords.X - 10) {
				*Y -= speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
						*Y += speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
							*turnPanzer -= 1;
							*X -= speed;
							for (short cnt1 = 0; cnt1 < 200; cnt1++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt1].Y][BARRIER + panzerPerimCoords[cnt1].X - speed - 1] == 6) {
									turn = true;
									*X += speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer -= 1;
		}
		break;
	}
	}
	if (*turnPanzer < 0) { *turnPanzer = 3; }
}
//
//мозги левого бота низ
void allyHunterBot(COORD panzerCoords, short* turnPanzer, short* X, short* Y, COORD panzerPerimCoords[200], short **field, bool &turn, short speed) {
	panzerPerimCoords[200] = panzerPerimCoord({ *X,*Y }, panzerPerimCoords);
	if (turn == false && *turnPanzer == 0) { *turnPanzer = 3; }
	else if (turn == false) { *turnPanzer -= 1; }
	switch (*turnPanzer) {
	case 0: {
		turn = true;
		if (*X < panzerCoords.X) {
			if (*X < panzerCoords.X - 190 || *Y > panzerCoords.Y + 30 || *Y < panzerCoords.Y - 30) {
				*X += speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 6) {
						*X -= speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 6) {
							*turnPanzer += 1;
							*Y += speed;
							for (short cnt = 0; cnt < 200; cnt++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
									turn = true;
									*Y -= speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer += 1;
		}
		break;
	}
	case 1: {
		turn = true;
		if (*Y < panzerCoords.Y) {
			if (*Y < panzerCoords.Y - 190 || *X > panzerCoords.X + 30 || *X < panzerCoords.X - 30) {
				*Y += speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y + speed+1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
						*Y -= speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y + speed + 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
							*turnPanzer += 1;
							*X -= speed;
							for (short cnt = 0; cnt < 200; cnt++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 6) {
									turn = true;
									*X += speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer += 1;
		}
		break;
	}
	case 2: {
		turn = true;
		if (*X > panzerCoords.X) {
			if (*X > panzerCoords.X + 190 || *Y > panzerCoords.Y + 30 || *Y < panzerCoords.Y - 30) {
				*X -= speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 6) {
						*X += speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X - speed - 1] == 6) {
							*turnPanzer += 1;
							*Y -= speed;
							for (short cnt = 0; cnt < 200; cnt++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
									turn = true;
									*Y += speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer += 1;
		}
		break;
	}
	case 3: {
		turn = true;
		if (*Y > panzerCoords.Y) {
			if (*Y > panzerCoords.Y + 190 || *X > panzerCoords.X + 30 || *X < panzerCoords.X - 30) {
				*Y -= speed;
				for (short cnt = 0; cnt < 200; cnt++) {
					if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 3 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 9 ||
						field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
						*Y += speed;
						if (field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 1 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 2 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 4 ||
							field[BARRIER + panzerPerimCoords[cnt].Y - speed - 1][BARRIER + panzerPerimCoords[cnt].X] == 6) {
							*turnPanzer += 1;
							*X += speed;
							for (short cnt = 0; cnt < 200; cnt++) {
								turn = false;
								if (field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 1 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 2 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 3 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 4 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 9 ||
									field[BARRIER + panzerPerimCoords[cnt].Y][BARRIER + panzerPerimCoords[cnt].X + speed + 1] == 6) {
									turn = true;
									*X -= speed;
									break;
								}
							}
						}
						break;
					}
				}
			}
		}
		else {
			*turnPanzer += 1;
		}
		break;
	}
	}
	if (*turnPanzer > 3) { *turnPanzer = 0; }
}
//логика стрельбы бота
void commonEnemyShot(HWND screen, HDC hdc, COORD enemyCoords, short turnEnemy, short &bullet,
	short** field, short &playerHealth, short &redBaseHealth, short &allyBotHealth,
	short &playerArmor, short &allyBotArmor, short power) {
	switch (turnEnemy) {
	case 0: {
		COORD shotCoord = enemyCoords;
		if ((bullet / 2 == 1 && enemyCoords.X != 830 && enemyCoords.Y != 250) ||
			(bullet / 2 == 1 && enemyCoords.X != 830 && enemyCoords.Y != 230) ||
			(bullet / 2 == 1 && enemyCoords.X != 830 && enemyCoords.Y != 270)) {
			paintPictures({ enemyCoords.X - 30, enemyCoords.Y + 12 }, screen, shotFire2, hdc);
		}
		shotCoord.X -= 20 * bullet;
		paintPictures({ shotCoord.X, shotCoord.Y + 24 }, screen, shot0, hdc);
		if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 1 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 2 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 10 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 7) {
			paintPictures({ shotCoord.X, shotCoord.Y + 12 }, screen, boom, hdc);
			bullet = 1;
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 2) {
				playerArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 2 && playerArmor <= 0) {
					playerHealth -= power;
					playerArmor = 0;
				}
			}
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 10) {
				allyBotArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 10 && allyBotArmor <= 0) {
					allyBotHealth -= power;
					allyBotArmor = 0;
				}
			}
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X] == 7) {
				redBaseHealth -= power;
			}
		}
		break;
	}
	case 1: {
		COORD shotCoord = enemyCoords;
		if (bullet / 2 == 1) {
			paintPictures({ enemyCoords.X + 12, enemyCoords.Y - 30}, screen, shotFire3, hdc);
		}
		shotCoord.Y -= 20 * bullet;
		paintPictures({ shotCoord.X + 24, shotCoord.Y }, screen, shot1, hdc);
		if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 1 ||
			field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 2 ||
			field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 10 ||
			field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 7) {
				paintPictures({ shotCoord.X + 12, shotCoord.Y }, screen, boom, hdc);
			bullet = 1;
			if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 2) {
				playerArmor -= (power+2);
				if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 2 && playerArmor <= 0) {
					playerHealth -= power;
					playerArmor = 0;
				}
			}
			if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 10) {
				allyBotArmor -= (power+2);
				if (field[BARRIER + shotCoord.Y][BARRIER + shotCoord.X + 24] == 10 && allyBotArmor <= 0) {
					allyBotHealth -= power;
					allyBotArmor = 0;
				}
			}
		}
		break;
	}
	case 2: {
		COORD shotCoord = enemyCoords;
		if (bullet / 2 == 1) {
			paintPictures({ enemyCoords.X + 50, enemyCoords.Y + 12 }, screen, shotFire0, hdc);
		}
		shotCoord.X += 20 * bullet;
		paintPictures({ shotCoord.X + 50, shotCoord.Y + 24 }, screen, shot0, hdc);
		if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 1 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 2 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 10 ||
			field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 7) {
			paintPictures({ shotCoord.X + 50, shotCoord.Y + 12 }, screen, boom, hdc);
			bullet = 1;
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 2) {
				playerArmor -= (power+2);
				if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 2 && playerArmor <= 0) {
					playerHealth -= power;
					playerArmor = 0;
				}
			}
			if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 10) {
				allyBotArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 24][BARRIER + shotCoord.X + 50] == 10 && allyBotArmor <= 0) {
					allyBotHealth -= power;
					allyBotArmor = 0;
				}
			}
		}
		break;
	}
	case 3: {
		COORD shotCoord = enemyCoords;
		if (bullet / 2 == 1) {
			paintPictures({ enemyCoords.X + 12, enemyCoords.Y + 50 }, screen, shotFire1, hdc);
		}
		shotCoord.Y += 20 * bullet;
		paintPictures({ shotCoord.X + 24, shotCoord.Y + 50 }, screen, shot1, hdc);
		if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 1 ||
			field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 2 ||
			field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 10 ||
			field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 7) {
			paintPictures({ shotCoord.X + 12, shotCoord.Y + 50 }, screen, boom, hdc);
			bullet = 1;
			if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 2) {
				playerArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 2 && playerArmor <= 0) {
					playerHealth -= power;
					playerArmor = 0;
				}
			}
			if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 10) {
				allyBotArmor -= (power + 2);
				if (field[BARRIER + shotCoord.Y + 50][BARRIER + shotCoord.X + 24] == 10 && allyBotArmor <= 0) {
					allyBotHealth -= power;
					allyBotArmor = 0;
				}
			}
		}
		break;
	}
	}           
}