#include <iostream>
#include <Windows.h>
#include <time.h>
#include "win10.h"
#include <conio.h>	//getch(), kbhit()
#include <fstream>
#define SIZE_POL 16
using namespace std;
void generation();
void preobraz();
void print();
void control();
void buf_cpy();
bool move_prov();
void contr_up(int y, int x);
void contr_down(int x, int y);
void contr_right(int y, int x);
void contr_left(int y, int x);
void init(int x, int y);
void clear();
void gameover();
bool menu();
void Top5();
void defaultSettings();
void InfoAboutCreator();
void set_contr(char& up, char& down, char& left, char& right, char control[11][31], int row_con, int column_con);
void TopShow();
void Save();
void clear_int(int mas[4][4]);
void buf_cpy_3();
void Save();
void Load();

bool move_pl = true, gameov = false, enter = false;

char filename[8] = "pos.txt";
char filename2[15] = "score_save.txt";
char filename3[13] = "top_name.txt";
char filename4[7] = "kl.txt";

char buf_1[5], buf_2[5], buf_3[5], buf_4[5], buf_5[5], buf_6[5], buf_7[5], buf_8[5],
buf_9[5], buf_10[5], buf_11[5], buf_12[5], buf_13[5], buf_14[5], buf_15[5], buf_16[5];
char buf_score[7];
char buf_top1_name[16], buf_top2_name[16], buf_top3_name[16], buf_top4_name[16], buf_top5_name[16];
char buf_top1_score[8], buf_top2_score[8], buf_top3_score[8], buf_top4_score[8], buf_top5_score[8];
char buf_top1_kl[8], buf_top2_kl[8], buf_top3_kl[8], buf_top4_kl[8], buf_top5_kl[8], buf_1kl[8];

char top1[16], top2[16], top3[16], top4[16], top5[16], nickname[16];

const int row_ = 4, column_ = 4;
int pole_rab[row_][column_], i = 0, kl = 0;
int pole_rab_buf[row_][column_], buf_score_ = 0, score = 0, pole_rab_buf2[row_][column_], pole_rab_buf3[row_][column_], pole_rab_buf4[row_][column_];

int top1_score = 0, top2_score = 0, top3_score = 0, top4_score = 0, top5_score = 0,
top1_kl = 0, top2_kl = 0, top3_kl = 0, top4_kl = 0, top5_kl = 0;

char up = 72, down = 80;
char le = 75, ri = 77;
const int row_save = 9, column_save = 19;
char save_menu[row_save][column_save] = {
	"$$$$$$$$$$$$$",
	"$           $",
	"$   SAVED   $",
	"$           $",
	"$$$$$$$$$$$$$"
};
char download_menu[row_save][column_save] = {
	"$$$$$$$$$$$$$$$$$$",
	"$                $",
	"$   DOWNLOADED   $",
	"$                $",
	"$$$$$$$$$$$$$$$$$$"
};
const int row_settings = 9, column_settings = 33;
char settings_menu[row_settings][column_settings] = {
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
	"$                           $",
	"$   DEFAULT SETTING IS SET  $",
	"$                           $",
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
};
const int row_top = 9, column_top = 38;
char Top[row_top][column_top] = {
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
	"$                         $  Score  $",
	"$ Top 1:                  $         $",
	"$ Top 2:                  $         $",
	"$ Top 3:                  $         $",
	"$ Top 4:                  $         $",
	"$ Top 5:                  $         $",
	"$                         $         $",
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
};
const int row_con = 13, column_con = 31;
char help[row_con][column_con]
{
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$",
	"$ CONTROL:                $",
	"$ Go to up press:      ↑  $",
	"$ Go to down press:    ↓  $",
	"$ Go to left press:    ←  $",
	"$ Go to right press:   →  $",
	"$ MISSION:                $",
	"$ Get 2048 in one of      $",
	"$ the square              $",
	"$                         $",
	"$ Press SPACE to return   $",
	"$ last position           $",
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$"
};
char control_[row_con][column_con]
{
	"$$$$$$$$$$$$$$$",
	"$ CONTROL:    $",
	"$             $",
	"$ Up:    > ↑  $",
	"$ Down:    ↓  $",
	"$ Left:    ←  $",
	"$ Right:   →  $",
	"$             $",
	"$$$$$$$$$$$$$$$"
};
char infoAboutCreator[row_con][column_con]
{
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$",
	"$                         $",
	"$ Game: 2048              $",
	"$ Name: Alisher           $",
	"$ Group: SEP-181          $",
	"$ Age: 15                 $",
	"$ Teacher: Kasenov Zhanat $",
	"$                         $",
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$",
};
const int row = 20, column = 30;
char pole[row][column] = {
	"#####################",
	"# SOCRE:     0      #",
	"#####################",
	"#    #    #    #    #",
	"#    #    #    #    #",
	"#####################",
	"#    #    #    #    #",
	"#    #    #    #    #",
	"#####################",
	"#    #    #    #    #",
	"#    #    #    #    #",
	"#####################",
	"#    #    #    #    #",
	"#    #    #    #    #",
	"#####################",
	"#             ↑     #",
	"#CONTROL:   ←   →   #",
	"#             ↓     #",
	"#####################",
};
const int row_menu = 14, column_menu = 31;
char glmenu[row_menu][column_menu]
{
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
	"$                           $",
	"$ > New game                $",
	"$   Continue                $",
	"$   Set control             $",
	"$   Save                    $",
	"$   Load                    $",
	"$   Top 5 list              $",
	"$   Help (F1)               $",
	"$   Info about creator      $",
	"$   Default contr settings  $",
	"$   Exit (ESC)              $",
	"$                           $",
	"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$",
};
direct KeyToDirect(int key)
{
	if (key == up)
	{
		return direct::dir_up;
	}
	else if (key == down)
	{
		return direct::dir_down;
	}
	else if (key == le)
	{
		return direct::dir_left;
	}
	else if (key == ri)
	{
		return direct::dir_right;
	}
}
void main()
{
	start();
	srand(time(0));
	enter = menu();
	do
	{
		if (enter)
		{
			if (!gameov)
			{
				clear();
				control();
				print();
				gameover();
			}
			else
			{
				SetPos(32, 1);
				gameov = false;
				move_pl = true;
				Top5();
				system("cls");
				enter = menu();
			}
		}
		else
		{
			system("cls");
			SetPos(8, 1);
			cout << "Good bye..." << endl;
			break;
		}
	} while (true);
	system("pause>>nul");
}

void TopShow()
{
	int i = 0, x = 8, y = 2;
	while (top1[i] != '\0')
	{
		Top[y][x] = top1[i];
		i++;
		x++;
	}
	i = 0, x = 8, y = 3;
	while (top2[i] != '\0')
	{
		Top[y][x] = top2[i];
		i++;
		x++;
	}
	i = 0, x = 8, y = 4;
	while (top3[i] != '\0')
	{
		Top[y][x] = top3[i];
		i++;
		x++;
	}
	i = 0, x = 8, y = 5;
	while (top4[i] != '\0')
	{
		Top[y][x] = top4[i];
		i++;
		x++;
	}
	i = 0, x = 8, y = 6;
	while (top5[i] != '\0')
	{
		Top[y][x] = top5[i];
		i++;
		x++;
	}
	x = 34, y = 2;
	int bufscore = top1_score;
	while (bufscore != 0)
	{
		Top[y][x] = (bufscore % 10) + 48;
		x--;
		bufscore /= 10;
	}
	x = 34, y = 3;
	bufscore = top2_score;
	while (bufscore != 0)
	{
		Top[y][x] = (bufscore % 10) + 48;
		x--;
		bufscore /= 10;
	}
	x = 34, y = 4;
	bufscore = top3_score;
	while (bufscore != 0)
	{
		Top[y][x] = (bufscore % 10) + 48;
		x--;
		bufscore /= 10;
	}
	x = 34, y = 5;
	bufscore = top4_score;
	while (bufscore != 0)
	{
		Top[y][x] = (bufscore % 10) + 48;
		x--;
		bufscore /= 10;
	}
	x = 34, y = 6;
	bufscore = top5_score;
	while (bufscore != 0)
	{
		Top[y][x] = (bufscore % 10) + 48;
		x--;
		bufscore /= 10;
	}
}
void InfoAboutCreator()
{
	system("cls");
	do
	{
		if (kbhit())
		{
			int key = _getch();
			if (key == 27)
			{
				break;
			}
		}
		for (int i = 0; i < row_con; i++)
		{
			SetPos(8, 1 + i);
			for (int j = 0; j < column_con; j++)
			{
				if (infoAboutCreator[i][j] == '$') { SetColor(0xA); cout << char(177); }
				else cout << infoAboutCreator[i][j];
			}
		}
	} while (true);
}
void set_contr(char& up, char& down, char& left, char& right, char control[11][31], int row_con, int column_con)
{
	int poscontrX = 8, poscontrY = 5;
	int poscurX = 9, poscurY = 3;
	do
	{
		if (kbhit())
		{
			int con = _getch();
			if (con == 80 && poscurY > 2 && poscurY < 6)
			{
				control[poscurY][poscurX] = ' ';
				poscurY++;
				control[poscurY][poscurX] = '>';
			}
			if (con == 72 && poscurY > 3 && poscurY <= 6)
			{
				control[poscurY][poscurX] = ' ';
				poscurY--;
				control[poscurY][poscurX] = '>';
			}
			if (con == 13 && poscurY == 3)
			{
				system("cls");
				SetPos(poscontrX, poscontrY);
				cout << "Enter UP key: ";
				cin >> up; cin.ignore();
				control[3][11] = up;
				system("cls");
			}
			if (con == 13 && poscurY == 4)
			{
				system("cls");
				SetPos(poscontrX, poscontrY);
				cout << "Enter DOWN key: ";
				cin >> down; cin.ignore();
				control[4][11] = down;
				system("cls");
			}
			if (con == 13 && poscurY == 5)
			{
				system("cls");
				SetPos(poscontrX, poscontrY);
				cout << "Enter LEFT key: ";
				cin >> left; cin.ignore();
				control[5][11] = left;
				system("cls");
			}
			if (con == 13 && poscurY == 6)
			{
				system("cls");
				SetPos(poscontrX, poscontrY);
				cout << "Enter RIGTH key: ";
				cin >> right; cin.ignore();
				control[6][11] = right;
				system("cls");
			}
			if (con == 27)
			{
				break;
			}
		}
		/*
		72 - вверх
		80 - вниз
		75 - влево
		77 - вправо
		*/
		for (int i = 0; i < row_con; i++)
		{
			SetPos(poscontrX, poscontrY + i);
			for (int j = 0; j < column_con; j++)
			{
				if (control_[i][j + 1] == '>')
				{
					while (control[i][j] != '$')
					{
						SetColor(0xC);
						cout << control[i][j];
						j++;
					}
					j--;
				}
				else if (control[i][j] == '$') { SetColor(0xA); cout << char(176); }
				else cout << control[i][j];
			}
		}
	} while (true);

}
void Top5()
{
	SetColor(0xA);
	SetPos(31, 1);
	cout << "Game over!" << endl;
	SetPos(31, 2);
	cout << "Your score: " << score << endl;
	SetPos(31, 3);
	cout << "Enter your nick: ";
	cin.getline(nickname, 16);
	if (score > top1_score)
	{
		top5_score = top4_score;
		top4_score = top3_score;
		top3_score = top2_score;
		top2_score = top1_score;

		strcpy(top5, top4);
		strcpy(top4, top3);
		strcpy(top3, top2);
		strcpy(top2, top1);

		top5_kl = top4_kl;
		top4_kl = top3_kl;
		top3_kl = top2_kl;
		top2_kl = top1_kl;

		top1_score = score;
		top1_kl = kl;
		strcpy(top1, nickname);
	}
	else if (score > top2_score)
	{
		top5_score = top4_score;
		top4_score = top3_score;
		top3_score = top2_score;

		strcpy(top5, top4);
		strcpy(top4, top3);
		strcpy(top3, top2);

		top5_kl = top4_kl;
		top4_kl = top3_kl;
		top3_kl = top2_kl;

		top2_score = score;
		top2_kl = kl;
		strcpy(top2, nickname);
	}
	else if (score > top3_score)
	{
		top5_score = top4_score;
		top4_score = top3_score;

		strcpy(top5, top4);
		strcpy(top4, top3);

		top5_kl = top4_kl;
		top4_kl = top3_kl;

		top3_score = score;
		top3_kl = kl;
		strcpy(top3, nickname);
	}
	else if (score > top4_score)
	{
		top5_score = top4_score;

		strcpy(top5, top4);

		top5_kl = top4_kl;

		top4_score = score;
		top4_kl = kl;
		strcpy(top4, nickname);
	}
	else if (score > top5_score)
	{
		top5_score = score;
		top5_kl = kl;
		strcpy(top5, nickname);
	}
	if (score == top1_score)
	{
		if (kl > top1_kl)
		{
			top5_score = top4_score;
			top4_score = top3_score;
			top3_score = top2_score;
			top2_score = top1_score;

			strcpy(top5, top4);
			strcpy(top4, top3);
			strcpy(top3, top2);
			strcpy(top2, top1);

			top5_kl = top4_kl;
			top4_kl = top3_kl;
			top3_kl = top2_kl;
			top2_kl = top1_kl;

			top1_score = score;
			top1_kl = kl;
			strcpy(top1, nickname);
		}
	}
	if (score == top2_score)
	{
		if (kl > top2_kl)
		{
			top5_score = top4_score;
			top4_score = top3_score;
			top3_score = top2_score;

			strcpy(top5, top4);
			strcpy(top4, top3);
			strcpy(top3, top2);

			top5_kl = top4_kl;
			top4_kl = top3_kl;
			top3_kl = top2_kl;

			top2_score = score;
			top2_kl = kl;
			strcpy(top2, nickname);
		}
	}
	if (score == top3_score)
	{
		if (kl > top3_kl)
		{
			top5_score = top4_score;
			top4_score = top3_score;

			strcpy(top5, top4);
			strcpy(top4, top3);

			top5_kl = top4_kl;
			top4_kl = top3_kl;

			top3_score = score;
			top3_kl = kl;
			strcpy(top3, nickname);
		}
	}
	if (score == top4_score)
	{
		if (kl > top4_kl)
		{
			top5_score = top4_score;

			strcpy(top5, top4);

			top5_kl = top4_kl;

			top4_score = score;
			top4_kl = kl;
			strcpy(top4, nickname);
		}
	}
	if (score == top5_score)
	{
		if (kl > top5_kl)
		{
			top5_score = score;
			top5_kl = kl;
			strcpy(top5, nickname);
		}
	}
	kl = 0;
	clear_int(pole_rab);
	clear_int(pole_rab_buf);
	clear_int(pole_rab_buf2);
	clear_int(pole_rab_buf3);
	clear_int(pole_rab_buf4);
}
void defaultSettings()
{
	up = 72, down = 80, le = 75, ri = 77;
}
bool menu()
{
	int posX = 2, posY = 2, menuX = 8, menuY = 1;
	do
	{
		if (kbhit())
		{
			int key = _getch();
			if (key == 72 && posY >= 1)
			{
				glmenu[posY][posX] = ' ';
				posY--;
				glmenu[posY][posX] = '>';
				if (posY == 1)
				{
					glmenu[posY][posX] = ' ';
					posY = 11;
					glmenu[posY][posX] = '>';
				}
			}
			else if (key == 80 && posY <= 12)
			{
				glmenu[posY][posX] = ' ';
				posY++;
				glmenu[posY][posX] = '>';
				if (posY == 12)
				{
					glmenu[posY][posX] = ' ';
					posY = 2;
					glmenu[posY][posX] = '>';
				}
			}
			if (key == 13 && posY == 2)
			{
				posX = 2, posY = 2;
				glmenu[2][2] = ' ';
				glmenu[2][2] = '>';
				i = 0;
				clear_int(pole_rab);
				clear_int(pole_rab_buf);
				clear_int(pole_rab_buf2);
				clear_int(pole_rab_buf3);
				clear_int(pole_rab_buf4);
				generation();
				generation();
				return true;
			}
			if ((key == 13 && posY == 11) || key == 27)
			{
				return false;
			}
			if (key == 13 && posY == 3 && i > 0)
			{
				posX = 2, posY = 2;
				glmenu[3][2] = ' ';
				glmenu[2][2] = '>';
				return true;
			}
			if (key == 13 && posY == 4)
			{
				posX = 2, posY = 2;
				glmenu[4][2] = ' ';
				glmenu[2][2] = '>';
				system("cls");
				set_contr(up, down, le, ri, control_, row_con, column_con);
			}
			if (key == 13 && posY == 9)
			{
				posX = 2, posY = 2;
				glmenu[9][2] = ' ';
				glmenu[2][2] = '>';
				InfoAboutCreator();
			}
			if (key == 13 && posY == 10)
			{
				system("cls");
				for (int i = 0; i < row_settings; i++)
				{
					SetPos(8, 1 + i);
					for (int j = 0; j < column_settings; j++)
					{
						if (settings_menu[i][j] == '$') { SetColor(0xA); cout << char(177); }
						else cout << settings_menu[i][j];
					}
				}
				Sleep(800);
				posX = 2, posY = 2;
				glmenu[10][2] = ' ';
				glmenu[2][2] = '>';
				defaultSettings();
				system("cls");
			}
			if (key == 13 && posY == 5)
			{
				system("cls");
				for (int i = 0; i < row_save; i++)
				{
					SetPos(8, 1 + i);
					for (int j = 0; j < column_save; j++)
					{
						if (save_menu[i][j] == '$') { SetColor(0xA); cout << char(177); }
						else cout << save_menu[i][j];
					}
				}
				Sleep(800);
				posX = 2, posY = 2;
				glmenu[5][2] = ' ';
				glmenu[2][2] = '>';
				Save();
			}
			if (key == 13 && posY == 7)
			{
				posX = 2, posY = 2;
				glmenu[7][2] = ' ';
				glmenu[2][2] = '>';
				system("cls");
				TopShow();
				do
				{
					if (kbhit())
					{
						int key = _getch();
						if (key == 27)
						{
							system("cls");
							break;
						}
					}
					for (int i = 0; i < row_top; i++)
					{
						SetPos(8, 1 + i);
						for (int j = 0; j < column_top; j++)
						{
							if (Top[i][j] == '$') { SetColor(0xA); cout << char(177); }
							else cout << Top[i][j];
						}
					}
				} while (true);
			}
			if (key == 13 && posY == 6)
			{
				system("cls");
				for (int i = 0; i < row_save; i++)
				{
					SetPos(8, 1 + i);
					for (int j = 0; j < column_save; j++)
					{
						if (download_menu[i][j] == '$') { SetColor(0xA); cout << char(177); }
						else cout << download_menu[i][j];
					}
				}
				Sleep(800);
				posX = 2, posY = 2;
				glmenu[6][2] = ' ';
				glmenu[2][2] = '>';
				clear();
				clear_int(pole_rab);
				clear_int(pole_rab_buf);
				clear_int(pole_rab_buf2);
				clear_int(pole_rab_buf3);
				clear_int(pole_rab_buf4);
				Load();
				for (int i = 0; i < row_; i++)
				{
					for (int j = 0; j < column_; j++)
					{
						if (pole_rab[i][j] != 0)
						{
							i = 1;
							return true;
						}
					}
				}
				//preobraz();
				//return true;
			}
			if (key == 13 && posY == 8)
			{
				system("cls");
				while (true)
				{
					for (int i = 0; i < row_con; i++)
					{
						SetPos(8, 1 + i);
						for (int j = 0; j < column_con; j++)
						{
							if (help[i][j] == '$') { cout << char(176); }
							else if (i == 2 && j == 23) {
								help[i][j] = up;
								cout << help[i][j];
							}
							else if (i == 3 && j == 23) {
								help[i][j] = down;
								cout << help[i][j];
							}
							else if (i == 4 && j == 23) {
								help[i][j] = le;
								cout << help[i][j];
							}
							else if (i == 5 && j == 23) {
								help[i][j] = ri;
								cout << help[i][j];
							}
							else cout << help[i][j];
						}
						cout << endl;
					}
					if (kbhit())
					{
						int exit = _getch();
						if (exit == 27)
							break;
					}
				}
			}
		}
		for (int i = 0; i < row_menu; i++)
		{
			SetPos(menuX, menuY + i);
			for (int j = 0; j < column_menu; j++)
			{
				if (glmenu[i][j + 1] == '>')
				{
					while (glmenu[i][j] != '$')
					{
						SetColor(0xC);
						cout << glmenu[i][j];
						j++;
					}
					j--;
				}
				else if (glmenu[i][j] == '$') { SetColor(0xA); cout << char(177); }
				else cout << glmenu[i][j];
			}
		}
	} while (true);
}
void gameover()
{
	if ((pole_rab[0][0] != pole_rab[0][1] && pole_rab[0][0] != pole_rab[1][0] && pole_rab[0][1] != pole_rab[0][2] && pole_rab[0][1] != pole_rab[1][1] &&
		pole_rab[0][2] != pole_rab[0][3] && pole_rab[0][2] != pole_rab[1][2] && pole_rab[0][3] != pole_rab[1][3] &&

		pole_rab[1][0] != pole_rab[1][1] && pole_rab[1][0] != pole_rab[2][0] && pole_rab[1][1] != pole_rab[1][2] && pole_rab[1][1] != pole_rab[2][1] &&
		pole_rab[1][2] != pole_rab[1][3] && pole_rab[1][2] != pole_rab[2][2] && pole_rab[1][3] != pole_rab[2][3] &&

		pole_rab[2][0] != pole_rab[2][1] && pole_rab[2][0] != pole_rab[3][0] && pole_rab[2][1] != pole_rab[2][2] && pole_rab[2][1] != pole_rab[3][1] &&
		pole_rab[2][2] != pole_rab[2][3] && pole_rab[2][2] != pole_rab[3][2] && pole_rab[2][3] != pole_rab[3][3] &&

		pole_rab[3][0] != pole_rab[3][1] && pole_rab[3][1] != pole_rab[3][2] && pole_rab[3][2] != pole_rab[3][3] &&

		pole_rab[0][0] != 0 && pole_rab[0][1] != 0 && pole_rab[0][2] != 0 && pole_rab[0][3] != 0 &&
		pole_rab[1][0] != 0 && pole_rab[1][1] != 0 && pole_rab[1][2] != 0 && pole_rab[1][3] != 0 &&
		pole_rab[2][0] != 0 && pole_rab[2][1] != 0 && pole_rab[2][2] != 0 && pole_rab[2][3] != 0 &&
		pole_rab[3][0] != 0 && pole_rab[3][1] != 0 && pole_rab[3][2] != 0 && pole_rab[3][3] != 0) ||

		(pole_rab[0][0] == 2048 || pole_rab[0][1] == 2048 || pole_rab[0][2] == 2048 || pole_rab[0][3] == 2048 ||
			pole_rab[1][0] == 2048 || pole_rab[1][1] == 2048 || pole_rab[1][2] == 2048 || pole_rab[1][3] == 2048 ||
			pole_rab[2][0] == 2048 || pole_rab[2][1] == 2048 || pole_rab[2][2] == 2048 || pole_rab[2][3] == 2048 ||
			pole_rab[3][0] == 2048 || pole_rab[3][1] == 2048 || pole_rab[3][2] == 2048 || pole_rab[3][3] == 2048))
	{
		gameov = true;
	}
}
void init(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		pole[y][x] = ' ';
		x--;
	}
}
void clear_int(int mas[4][4])
{
	for (int i = 0; i < row_; i++)
	{
		for (int j = 0; j < column_; j++)
		{
			mas[i][j] = 0;
		}
	}
	score = 0;
}
void clear()
{
	init(4, 3);
	init(9, 3);
	init(14, 3);
	init(19, 3);
	init(4, 6);
	init(9, 6);
	init(14, 6);
	init(19, 6);
	init(4, 9);
	init(9, 9);
	init(14, 9);
	init(19, 9);
	init(4, 12);
	init(9, 12);
	init(14, 12);
	init(19, 12);
}
void contr_up(int y, int x)
{
	if (pole_rab[y][x] != 0 && pole_rab[y - 1][x] == 0)
	{
		pole_rab[y - 1][x] = pole_rab[y][x];
		pole_rab[y][x] = 0;
	}
	else if (pole_rab[y][x] != 0 && pole_rab[y][x] == pole_rab[y - 1][x])
	{
		pole_rab[y - 1][x] += pole_rab[y][x];
		score += pole_rab[y - 1][x];
		pole_rab[y][x] = 0;
	}
}
void contr_down(int y, int x)
{
	if (pole_rab[y][x] != 0 && pole_rab[y + 1][x] == 0)
	{
		pole_rab[y + 1][x] = pole_rab[y][x];
		pole_rab[y][x] = 0;
	}
	else if (pole_rab[y][x] != 0 && pole_rab[y][x] == pole_rab[y + 1][x])
	{
		pole_rab[y + 1][x] += pole_rab[y][x];
		score += pole_rab[y + 1][x];
		pole_rab[y][x] = 0;
	}
}
void contr_left(int y, int x)
{
	if (pole_rab[y][x] != 0 && pole_rab[y][x - 1] == 0)
	{
		pole_rab[y][x - 1] = pole_rab[y][x];
		pole_rab[y][x] = 0;
	}
	else if (pole_rab[y][x] != 0 && pole_rab[y][x] == pole_rab[y][x - 1])
	{
		pole_rab[y][x - 1] += pole_rab[y][x];
		score += pole_rab[y][x - 1];
		pole_rab[y][x] = 0;
	}
}
void contr_right(int y, int x)
{
	if (pole_rab[y][x] != 0 && pole_rab[y][x + 1] == 0)
	{
		pole_rab[y][x + 1] = pole_rab[y][x];
		pole_rab[y][x] = 0;
	}
	else if (pole_rab[y][x] != 0 && pole_rab[y][x] == pole_rab[y][x + 1])
	{
		pole_rab[y][x + 1] += pole_rab[y][x];
		score += pole_rab[y][x + 1];
		pole_rab[y][x] = 0;
	}
}
void buf_cpy_3()
{
	for (int i = 0; i < row_ * column_; i++)
	{
		pole_rab_buf3[0][i] = pole_rab[0][i];
	}
}
void buf_cpy()
{
	buf_score_ = score;
	for (int i = 0; i < row_ * column_; i++)
	{
		pole_rab_buf[0][i] = pole_rab[0][i];
	}
}
bool move_prov()
{
	if (pole_rab[0][0] != pole_rab_buf3[0][0] || pole_rab[0][1] != pole_rab_buf3[0][1] || pole_rab[0][2] != pole_rab_buf3[0][2] || pole_rab[0][3] != pole_rab_buf3[0][3] ||
		pole_rab[1][0] != pole_rab_buf3[1][0] || pole_rab[1][1] != pole_rab_buf3[1][1] || pole_rab[1][2] != pole_rab_buf3[1][2] || pole_rab[1][3] != pole_rab_buf3[1][3] ||
		pole_rab[2][0] != pole_rab_buf3[2][0] || pole_rab[2][1] != pole_rab_buf3[2][1] || pole_rab[2][2] != pole_rab_buf3[2][2] || pole_rab[2][3] != pole_rab_buf3[2][3] ||
		pole_rab[3][0] != pole_rab_buf3[3][0] || pole_rab[3][1] != pole_rab_buf3[3][1] || pole_rab[3][2] != pole_rab_buf3[3][2] || pole_rab[3][3] != pole_rab_buf3[3][3]) {
		return true;
	}
	else
	{
		return false;
	}
}
void generation()
{
	int size_mas = 0;
	for (int i = 0; i < SIZE_POL; i++)
	{
		if (pole_rab[0][i] == 0)
		{
			size_mas++;
		}
	}
	int* mas = new int[size_mas], j = 0;
	for (int i = 0; i < SIZE_POL; i++)
	{
		if (pole_rab[0][i] == 0)
		{
			switch (i + 1)
			{
			case 1:
				mas[j] = 1;
				j++;
				break;
			case 2:
				mas[j] = 2;
				j++;
				break;
			case 3:
				mas[j] = 3;
				j++;
				break;
			case 4:
				mas[j] = 4;
				j++;
				break;
			case 5:
				mas[j] = 5;
				j++;
				break;
			case 6:
				mas[j] = 6;
				j++;
				break;
			case 7:
				mas[j] = 7;
				j++;
				break;
			case 8:
				mas[j] = 8;
				j++;
				break;
			case 9:
				mas[j] = 9;
				j++;
				break;
			case 10:
				mas[j] = 10;
				j++;
				break;
			case 11:
				mas[j] = 11;
				j++;
				break;
			case 12:
				mas[j] = 12;
				j++;
				break;
			case 13:
				mas[j] = 13;
				j++;
				break;
			case 14:
				mas[j] = 14;
				j++;
				break;
			case 15:
				mas[j] = 15;
				j++;
				break;
			case 16:
				mas[j] = 16;
				break;
			}
		}
	}
	int pos = 0;
	pos = rand() % size_mas;
	if (j != 0)
	{
		switch (mas[pos])
		{
		case 1:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][0] = 2;
				break;
			case 9:
				pole_rab[0][0] = 4;
				break;
			}
			break;
		}
		case 2:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][1] = 2;
				break;
			case 9:
				pole_rab[0][1] = 4;
				break;
			}
			break;
		}
		case 3:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][2] = 2;
				break;
			case 9:
				pole_rab[0][2] = 4;
				break;
			}
			break;
		}
		case 4:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][3] = 2;
				break;
			case 9:
				pole_rab[0][3] = 4;
				break;
			}
			break;
		}
		case 5:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][4] = 2;
				break;
			case 9:
				pole_rab[0][4] = 4;
				break;
			}
			break;
		}
		case 6:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][5] = 2;
				break;
			case 9:
				pole_rab[0][5] = 4;
				break;
			}
			break;
		}
		case 7:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][6] = 2;
				break;
			case 9:
				pole_rab[0][6] = 4;
				break;
			}
			break;
		}
		case 8:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][7] = 2;
				break;
			case 9:
				pole_rab[0][7] = 4;
				break;
			}
			break;
		}

		case 9:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][8] = 2;
				break;
			case 9:
				pole_rab[0][8] = 4;
				break;
			}
			break;
		}
		case 10:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][9] = 2;
				break;
			case 9:
				pole_rab[0][9] = 4;
				break;
			}
			break;
		}
		case 11:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][10] = 2;
				break;
			case 9:
				pole_rab[0][10] = 4;
				break;
			}
			break;
		}
		case 12:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][11] = 2;
				break;
			case 9:
				pole_rab[0][11] = 4;
				break;
			}
			break;
		}
		case 13:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][12] = 2;
				break;
			case 9:
				pole_rab[0][12] = 4;
				break;
			}
			break;
		}
		case 14:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][13] = 2;
				break;
			case 9:
				pole_rab[0][13] = 4;
				break;
			}
			break;
		}
		case 15:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][14] = 2;
				break;
			case 9:
				pole_rab[0][14] = 4;
				break;
			}
			break;
		}
		case 16:
		{
			int znach = rand() % (9 - 0 + 1) + 0;
			switch (znach)
			{
			case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			case 8:
				pole_rab[0][15] = 2;
				break;
			case 9:
				pole_rab[0][15] = 4;
				break;
			}
			break;
		}
		}
	}
	delete[] mas;
}
void preobraz()
{
	for (int i = 0; i < row_; i++)
	{
		for (int j = 0; j < column_; j++)
		{
			pole_rab_buf2[i][j] = pole_rab[i][j];
		}
	}
	int x = 4, y = 3;
	x = 4, y = 3;
	while (pole_rab_buf2[0][0] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][0] % 10) + 48;
		pole_rab_buf2[0][0] /= 10;
		x--;
	}
	x = 9, y = 3;
	while (pole_rab_buf2[0][1] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][1] % 10) + 48;
		pole_rab_buf2[0][1] /= 10;
		x--;
	}
	x = 14, y = 3;
	while (pole_rab_buf2[0][2] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][2] % 10) + 48;
		pole_rab_buf2[0][2] /= 10;
		x--;
	}
	x = 19, y = 3;
	while (pole_rab_buf2[0][3] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][3] % 10) + 48;
		pole_rab_buf2[0][3] /= 10;
		x--;
	}

	x = 4, y = 6;
	while (pole_rab_buf2[0][4] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][4] % 10) + 48;
		pole_rab_buf2[0][4] /= 10;
		x--;
	}
	x = 9, y = 6;
	while (pole_rab_buf2[0][5] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][5] % 10) + 48;
		pole_rab_buf2[0][5] /= 10;
		x--;
	}
	x = 14, y = 6;
	while (pole_rab_buf2[0][6] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][6] % 10) + 48;
		pole_rab_buf2[0][6] /= 10;
		x--;
	}
	x = 19, y = 6;
	while (pole_rab_buf2[0][7] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][7] % 10) + 48;
		pole_rab_buf2[0][7] /= 10;
		x--;
	}

	x = 4, y = 9;
	while (pole_rab_buf2[0][8] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][8] % 10) + 48;
		pole_rab_buf2[0][8] /= 10;
		x--;
	}
	x = 9, y = 9;
	while (pole_rab_buf2[0][9] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][9] % 10) + 48;
		pole_rab_buf2[0][9] /= 10;
		x--;
	}
	x = 14, y = 9;
	while (pole_rab_buf2[0][10] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][10] % 10) + 48;
		pole_rab_buf2[0][10] /= 10;
		x--;
	}
	x = 19, y = 9;
	while (pole_rab_buf2[0][11] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][11] % 10) + 48;
		pole_rab_buf2[0][11] /= 10;
		x--;
	}

	x = 4, y = 12;
	while (pole_rab_buf2[0][12] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][12] % 10) + 48;
		pole_rab_buf2[0][12] /= 10;
		x--;
	}
	x = 9, y = 12;
	while (pole_rab_buf2[0][13] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][13] % 10) + 48;
		pole_rab_buf2[0][13] /= 10;
		x--;
	}
	x = 14, y = 12;
	while (pole_rab_buf2[0][14] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][14] % 10) + 48;
		pole_rab_buf2[0][14] /= 10;
		x--;
	}
	x = 19, y = 12;
	while (pole_rab_buf2[0][15] != 0)
	{
		pole[y][x] = (pole_rab_buf2[0][15] % 10) + 48;
		pole_rab_buf2[0][15] /= 10;
		x--;
	}

	if (pole_rab[0][0] == 0)
	{
		x = 4, y = 3;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][1] == 0) {
		x = 9, y = 3;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][2] == 0) {
		x = 14, y = 3;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][3] == 0) {
		x = 19, y = 3;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][4] == 0) {
		x = 4, y = 6;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][5] == 0) {
		x = 9, y = 6;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][6] == 0) {
		x = 14, y = 6;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][7] == 0) {
		x = 19, y = 6;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][8] == 0) {
		x = 4, y = 9;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][9] == 0) {
		x = 9, y = 9;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][10] == 0) {
		x = 14, y = 9;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][11] == 0) {
		x = 19, y = 9;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][12] == 0) {
		x = 4, y = 12;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][13] == 0) {
		x = 9, y = 12;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][14] == 0) {
		x = 14, y = 12;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
	if (pole_rab[0][15] == 0) {
		x = 19, y = 12;
		while (pole[y][x] != '#')
		{
			pole[y][x] = ' ';
			x--;
		}
	}
}
void print()
{
	preobraz();
	int bufscore = score;
	int x = 13, y = 1;
	if (score != 0)
	{
		while (bufscore != 0)
		{
			pole[y][x] = bufscore % 10 + 48;
			x--;
			bufscore /= 10;
		}
	}
	else
	{
		int x = 9, y = 1;
		while (x != 13)
		{
			pole[y][x] = ' ';
			x++;
		}
		pole[1][13] = '0';
	}
	int posX = 8, posY = 1;
	for (int i = 0; i < row; i++)
	{
		SetPos(posX, posY + i);
		for (int j = 0; j < column; j++)
		{
			if (pole[i][j] == '2' && pole[i][j - 1] == ' ' && pole[i][j - 2] == ' ' && pole[i][j - 3] == ' ')
			{
				while (pole[i][j] != '#')
				{
					SetColor(0xF);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '4' && pole[i][j - 1] == ' ' && pole[i][j - 2] == ' ' && pole[i][j - 3] == ' ' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0x8);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '8' && pole[i][j - 1] == ' ' && pole[i][j - 2] == ' ' && pole[i][j - 3] == ' ' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0xE);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '1' && pole[i][j + 1] == '6' && pole[i][j - 1] == ' ' && pole[i][j - 2] == ' ' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0xB);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '3' && pole[i][j + 1] == '2' && pole[i][j - 1] == ' ' && pole[i][j - 2] == ' ' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0x9);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '6' && pole[i][j + 1] == '4' && pole[i][j - 1] == ' ' && pole[i][j - 2] == ' ' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0xC);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '1' && pole[i][j + 1] == '2' && pole[i][j + 2] == '8' && pole[i][j - 1] == ' ' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0xD);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '2' && pole[i][j + 1] == '5' && pole[i][j + 2] == '6' && pole[i][j - 1] == ' ' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0x3);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '5' && pole[i][j + 1] == '1' && pole[i][j + 2] == '2' && pole[i][j - 1] == ' ' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0x1);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '1' && pole[i][j + 1] == '0' && pole[i][j + 2] == '2' && pole[i][j + 3] == '4' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0x4);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '2' && pole[i][j + 1] == '0' && pole[i][j + 2] == '4' && pole[i][j + 3] == '8' && i != 1)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0x5);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (i == 1 && j == 9)
			{
				while (pole[i][j] != '#')
				{
					SetColor(0x4);
					cout << pole[i][j];
					j++;
				}
				j--;
			}
			else if (pole[i][j] == '#') { SetColor(0xA); cout << char(177); }
			else cout << pole[i][j];
		}
	}
	/*for (int i = 0; i < row_; i++)
	{
	SetPos(32, 1 + i);
	for (int j = 0; j < column_; j++)
	{
	cout << pole_rab[i][j];
	}
	}
	for (int i = 0; i < row_; i++)
	{
	SetPos(48, 1 + i);
	for (int j = 0; j < column_; j++)
	{
	cout << pole_rab_buf[i][j];
	}
	}*/
}
void control()
{
	if (kbhit())
	{
		direct d;
		int key = _getch();
		d = KeyToDirect(key);
		if (key == 27)
		{
			i++;
			system("cls");
			enter = menu();
		}
		if (key == 13)
		{
			gameov = true;
		}
		if (key == 32)
		{
			score = buf_score_;
			for (int i = 0; i < row_; i++)
			{
				for (int j = 0; j < column_; j++)
				{
					pole_rab[i][j] = pole_rab_buf[i][j];
				}
			}
		}
		/*if (key == 32)
		{
		gameov = true;
		}*/
		if (d == direct::dir_up)
		{
			buf_cpy_3();
			buf_cpy();
			kl++;
			for (int i = 0; i < 3; i++)
			{
				contr_up(1, 0);
				contr_up(1, 1);
				contr_up(1, 2);
				contr_up(1, 3);
				contr_up(2, 0);
				contr_up(2, 1);
				contr_up(2, 2);
				contr_up(2, 3);
				contr_up(3, 0);
				contr_up(3, 1);
				contr_up(3, 2);
				contr_up(3, 3);
			}
			move_pl = move_prov();
			//cout << move_pl;
			if (move_pl)
			{
				generation();
			}
		}
		else if (d == direct::dir_down)
		{
			buf_cpy_3();
			buf_cpy();
			kl++;
			for (int i = 0; i < 3; i++)
			{
				contr_down(2, 3);
				contr_down(2, 2);
				contr_down(2, 1);
				contr_down(2, 0);
				contr_down(1, 3);
				contr_down(1, 2);
				contr_down(1, 1);
				contr_down(1, 0);
				contr_down(0, 3);
				contr_down(0, 2);
				contr_down(0, 1);
				contr_down(0, 0);
			}
			move_pl = move_prov();
			if (move_pl)
			{
				generation();
			}
		}
		else if (d == direct::dir_left)
		{
			buf_cpy_3();
			buf_cpy();
			kl++;
			for (int i = 0; i < 3; i++)
			{
				contr_left(0, 1);
				contr_left(0, 2);
				contr_left(0, 3);
				contr_left(1, 1);
				contr_left(1, 2);
				contr_left(1, 3);
				contr_left(2, 1);
				contr_left(2, 2);
				contr_left(2, 3);
				contr_left(3, 1);
				contr_left(3, 2);
				contr_left(3, 3);
			}
			move_pl = move_prov();
			if (move_pl)
			{
				generation();
			}
		}
		else if (d == direct::dir_right)
		{
			buf_cpy_3();
			buf_cpy();
			kl++;
			for (int i = 0; i < 3; i++)
			{
				contr_right(3, 2);
				contr_right(2, 2);
				contr_right(1, 2);
				contr_right(0, 2);
				contr_right(3, 1);
				contr_right(2, 1);
				contr_right(1, 1);
				contr_right(0, 1);
				contr_right(3, 0);
				contr_right(2, 0);
				contr_right(1, 0);
				contr_right(0, 0);
			}
			move_pl = move_prov();
			if (move_pl)
			{
				generation();
			}
		}
	}
}
void Save()
{
	ofstream file_pos(filename);
	if (file_pos.is_open())
	{
		for (int i = 0; i < row_; i++)
		{
			for (int j = 0; j < column_; j++)
			{
				pole_rab_buf4[i][j] = pole_rab[i][j];
			}
		}
		for (int i = 0; pole_rab_buf4[0][0] != 0; i++)
		{
			buf_1[i] = (pole_rab_buf4[0][0] % 10) + 48;
			pole_rab_buf4[0][0] /= 10;
		}
		file_pos << buf_1 << endl;
		for (int i = 0; pole_rab_buf4[0][1] != 0; i++)
		{
			buf_2[i] = (pole_rab_buf4[0][1] % 10) + 48;
			pole_rab_buf4[0][1] /= 10;
		}
		file_pos << buf_2 << endl;
		for (int i = 0; pole_rab_buf4[0][2] != 0; i++)
		{
			buf_3[i] = (pole_rab_buf4[0][2] % 10) + 48;
			pole_rab_buf4[0][2] /= 10;
		}
		file_pos << buf_3 << endl;
		for (int i = 0; pole_rab_buf4[0][3] != 0; i++)
		{
			buf_4[i] = (pole_rab_buf4[0][3] % 10) + 48;
			pole_rab_buf4[0][3] /= 10;
		}
		file_pos << buf_4 << endl;

		for (int i = 0; pole_rab_buf4[0][4] != 0; i++)
		{
			buf_5[i] = (pole_rab_buf4[0][4] % 10) + 48;
			pole_rab_buf4[0][4] /= 10;
		}
		file_pos << buf_5 << endl;
		for (int i = 0; pole_rab_buf4[0][5] != 0; i++)
		{
			buf_6[i] = (pole_rab_buf4[0][5] % 10) + 48;
			pole_rab_buf4[0][5] /= 10;
		}
		file_pos << buf_6 << endl;
		for (int i = 0; pole_rab_buf4[0][6] != 0; i++)
		{
			buf_7[i] = (pole_rab_buf4[0][6] % 10) + 48;
			pole_rab_buf4[0][6] /= 10;
		}
		file_pos << buf_7 << endl;
		for (int i = 0; pole_rab_buf4[0][7] != 0; i++)
		{
			buf_8[i] = (pole_rab_buf4[0][7] % 10) + 48;
			pole_rab_buf4[0][7] /= 10;
		}
		file_pos << buf_8 << endl;

		for (int i = 0; pole_rab_buf4[0][8] != 0; i++)
		{
			buf_9[i] = (pole_rab_buf4[0][8] % 10) + 48;
			pole_rab_buf4[0][8] /= 10;
		}
		file_pos << buf_9 << endl;
		for (int i = 0; pole_rab_buf4[0][9] != 0; i++)
		{
			buf_10[i] = (pole_rab_buf4[0][9] % 10) + 48;
			pole_rab_buf4[0][9] /= 10;
		}
		file_pos << buf_10 << endl;
		for (int i = 0; pole_rab_buf4[0][10] != 0; i++)
		{
			buf_11[i] = (pole_rab_buf4[0][10] % 10) + 48;
			pole_rab_buf4[0][10] /= 10;
		}
		file_pos << buf_11 << endl;
		for (int i = 0; pole_rab_buf4[0][11] != 0; i++)
		{
			buf_12[i] = (pole_rab_buf4[0][11] % 10) + 48;
			pole_rab_buf4[0][11] /= 10;
		}
		file_pos << buf_12 << endl;

		for (int i = 0; pole_rab_buf4[0][12] != 0; i++)
		{
			buf_13[i] = (pole_rab_buf4[0][12] % 10) + 48;
			pole_rab_buf4[0][12] /= 10;
		}
		file_pos << buf_13 << endl;
		for (int i = 0; pole_rab_buf4[0][13] != 0; i++)
		{
			buf_14[i] = (pole_rab_buf4[0][13] % 10) + 48;
			pole_rab_buf4[0][13] /= 10;
		}
		file_pos << buf_14 << endl;
		for (int i = 0; pole_rab_buf4[0][14] != 0; i++)
		{
			buf_15[i] = (pole_rab_buf4[0][14] % 10) + 48;
			pole_rab_buf4[0][14] /= 10;
		}
		file_pos << buf_15 << endl;
		for (int i = 0; pole_rab_buf4[0][15] != 0; i++)
		{
			buf_16[i] = (pole_rab_buf4[0][15] % 10) + 48;
			pole_rab_buf4[0][15] /= 10;
		}
		file_pos << buf_16 << endl;
		file_pos.close();
	}
	ofstream file_score(filename2);
	if (file_score.is_open())
	{
		int buf_s = score;
		for (int i = 0; buf_s != 0; i++)
		{
			buf_score[i] = (buf_s % 10) + 48;
			buf_s /= 10;
		}
		file_score << buf_score << endl;
		buf_s = top1_score;
		for (int i = 0; buf_s != 0; i++)
		{
			buf_top1_score[i] = (buf_s % 10) + 48;
			buf_s /= 10;
		}
		file_score << buf_top1_score << endl;
		buf_s = top2_score;
		for (int i = 0; buf_s != 0; i++)
		{
			buf_top2_score[i] = (buf_s % 10) + 48;
			buf_s /= 10;
		}
		file_score << buf_top2_score << endl;
		buf_s = top3_score;
		for (int i = 0; buf_s != 0; i++)
		{
			buf_top3_score[i] = (buf_s % 10) + 48;
			buf_s /= 10;
		}
		file_score << buf_top3_score << endl;
		buf_s = top4_score;
		for (int i = 0; buf_s != 0; i++)
		{
			buf_top4_score[i] = (buf_s % 10) + 48;
			buf_s /= 10;
		}
		file_score << buf_top4_score << endl;
		buf_s = top5_score;
		for (int i = 0; buf_s != 0; i++)
		{
			buf_top5_score[i] = (buf_s % 10) + 48;
			buf_s /= 10;
		}
		file_score << buf_top5_score;
		file_score.close();
	}
	ofstream file_name(filename3);
	if (file_name.is_open())
	{
		file_name << top1 << endl;
		file_name << top2 << endl;
		file_name << top3 << endl;
		file_name << top4 << endl;
		file_name << top5 << endl;
		file_name.close();
	}
	ofstream file_kl(filename4);
	if (file_kl.is_open())
	{
		int buf_kl;
		buf_kl = kl;
		for (int i = 0; buf_kl != 0; i++)
		{
			buf_1kl[i] = (buf_kl % 10) + 48;
			buf_kl /= 10;
		}
		file_kl << buf_1kl << endl;
		buf_kl = top1_kl;
		for (int i = 0; buf_kl != 0; i++)
		{
			buf_top1_kl[i] = (buf_kl % 10) + 48;
			buf_kl /= 10;
		}
		file_kl << buf_top1_kl << endl;
		buf_kl = top2_kl;
		for (int i = 0; buf_kl != 0; i++)
		{
			buf_top2_kl[i] = (buf_kl % 10) + 48;
			buf_kl /= 10;
		}
		file_kl << buf_top2_kl << endl;
		buf_kl = top3_kl;
		for (int i = 0; buf_kl != 0; i++)
		{
			buf_top3_kl[i] = (buf_kl % 10) + 48;
			buf_kl /= 10;
		}
		file_kl << buf_top3_kl << endl;
		buf_kl = top4_kl;
		for (int i = 0; buf_kl != 0; i++)
		{
			buf_top4_kl[i] = (buf_kl % 10) + 48;
			buf_kl /= 10;
		}
		file_kl << buf_top4_kl << endl;
		buf_kl = top5_kl;
		for (int i = 0; buf_kl != 0; i++)
		{
			buf_top5_kl[i] = (buf_kl % 10) + 48;
			buf_kl /= 10;
		}
		file_kl << buf_top5_kl << endl;
		file_kl.close();
	}
}
void Load()
{
	ifstream file_pos(filename);
	if (file_pos.is_open())
	{
		file_pos.getline(buf_1, 5);
		pole_rab[0][0] = 0;
		for (int i = 0; buf_1[i] != '\0'; i++)
		{
			pole_rab[0][0] += (buf_1[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_2, 5);
		pole_rab[0][1] = 0;
		for (int i = 0; buf_2[i] != '\0'; i++)
		{
			pole_rab[0][1] += (buf_2[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_3, 5);
		pole_rab[0][2] = 0;
		for (int i = 0; buf_3[i] != '\0'; i++)
		{
			pole_rab[0][2] += (buf_3[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_4, 5);
		pole_rab[0][3] = 0;
		for (int i = 0; buf_4[i] != '\0'; i++)
		{
			pole_rab[0][3] += (buf_4[i] - 48) * pow(10, i);
		}

		file_pos.getline(buf_5, 5);
		pole_rab[0][4] = 0;
		for (int i = 0; buf_5[i] != '\0'; i++)
		{
			pole_rab[0][4] += (buf_5[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_6, 5);
		pole_rab[0][5] = 0;
		for (int i = 0; buf_6[i] != '\0'; i++)
		{
			pole_rab[0][5] += (buf_6[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_7, 5);
		pole_rab[0][6] = 0;
		for (int i = 0; buf_7[i] != '\0'; i++)
		{
			pole_rab[0][6] += (buf_7[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_8, 5);
		pole_rab[0][7] = 0;
		for (int i = 0; buf_8[i] != '\0'; i++)
		{
			pole_rab[0][7] += (buf_8[i] - 48) * pow(10, i);
		}


		file_pos.getline(buf_9, 5);
		pole_rab[0][8] = 0;
		for (int i = 0; buf_9[i] != '\0'; i++)
		{
			pole_rab[0][8] += (buf_9[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_10, 5);
		pole_rab[0][9] = 0;
		for (int i = 0; buf_10[i] != '\0'; i++)
		{
			pole_rab[0][9] += (buf_10[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_11, 5);
		pole_rab[0][10] = 0;
		for (int i = 0; buf_11[i] != '\0'; i++)
		{
			pole_rab[0][10] += (buf_11[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_12, 5);
		pole_rab[0][11] = 0;
		for (int i = 0; buf_12[i] != '\0'; i++)
		{
			pole_rab[0][11] += (buf_12[i] - 48) * pow(10, i);
		}

		file_pos.getline(buf_13, 5);
		pole_rab[0][12] = 0;
		for (int i = 0; buf_13[i] != '\0'; i++)
		{
			pole_rab[0][12] += (buf_13[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_14, 5);
		pole_rab[0][13] = 0;
		for (int i = 0; buf_14[i] != '\0'; i++)
		{
			pole_rab[0][13] += (buf_14[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_15, 5);
		pole_rab[0][14] = 0;
		for (int i = 0; buf_15[i] != '\0'; i++)
		{
			pole_rab[0][14] += (buf_15[i] - 48) * pow(10, i);
		}
		file_pos.getline(buf_16, 5);
		pole_rab[0][15] = 0;
		for (int i = 0; buf_16[i] != '\0'; i++)
		{
			pole_rab[0][15] += (buf_16[i] - 48) * pow(10, i);
		}
		file_pos.close();
	}
	ifstream file_score(filename2);
	if (file_score.is_open())
	{
		file_score.getline(buf_score, 7);
		score = 0;
		for (int i = 0; buf_score[i] != '\0'; i++)
		{
			score += (buf_score[i] - 48) * pow(10, i);
		}
		file_score.getline(buf_top1_score, 7);
		top1_score = 0;
		for (int i = 0; buf_top1_score[i] != '\0'; i++)
		{
			top1_score += (buf_top1_score[i] - 48) * pow(10, i);
		}
		file_score.getline(buf_top2_score, 7);
		top2_score = 0;
		for (int i = 0; buf_top2_score[i] != '\0'; i++)
		{
			top2_score += (buf_top2_score[i] - 48) * pow(10, i);
		}
		file_score.getline(buf_top3_score, 7);
		top3_score = 0;
		for (int i = 0; buf_top3_score[i] != '\0'; i++)
		{
			top3_score += (buf_top3_score[i] - 48) * pow(10, i);
		}
		file_score.getline(buf_top4_score, 7);
		top4_score = 0;
		for (int i = 0; buf_top4_score[i] != '\0'; i++)
		{
			top4_score += (buf_top4_score[i] - 48) * pow(10, i);
		}
		file_score.getline(buf_top5_score, 7);
		top5_score = 0;
		for (int i = 0; buf_top5_score[i] != '\0'; i++)
		{
			top5_score += (buf_top5_score[i] - 48) * pow(10, i);
		}
		file_score.close();
	}
	ifstream file_name(filename3);
	if (file_name.is_open())
	{
		file_name >> top1;
		file_name >> top2;
		file_name >> top3;
		file_name >> top4;
		file_name >> top5;
		file_name.close();
	}
	ifstream file_kl(filename4);
	if (file_kl.is_open())
	{
		file_kl.getline(buf_top1_kl, 8);
		top1_kl = 0;
		for (int i = 0; buf_top1_kl[i] != '\0'; i++)
		{
			top1_kl += (buf_top1_kl[i] - 48) * pow(10, i);
		}
		file_kl.getline(buf_top2_kl, 8);
		top2_kl = 0;
		for (int i = 0; buf_top2_kl[i] != '\0'; i++)
		{
			top2_kl += (buf_top2_kl[i] - 48) * pow(10, i);
		}
		file_kl.getline(buf_top3_kl, 8);
		top3_kl = 0;
		for (int i = 0; buf_top3_kl[i] != '\0'; i++)
		{
			top3_kl += (buf_top3_kl[i] - 48) * pow(10, i);
		}
		file_kl.getline(buf_top4_kl, 8);
		top4_kl = 0;
		for (int i = 0; buf_top4_kl[i] != '\0'; i++)
		{
			top4_kl += (buf_top4_kl[i] - 48) * pow(10, i);
		}
		file_kl.getline(buf_top5_kl, 8);
		top5_kl = 0;
		for (int i = 0; buf_top5_kl[i] != '\0'; i++)
		{
			top5_kl += (buf_top5_kl[i] - 48) * pow(10, i);
		}
		file_kl.close();
	}
}