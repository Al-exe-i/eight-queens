#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "time.h"
using namespace std;

void allocateField(int field[8][8]);
void displayField();
void placeQueen(int i, int j);
void removeQueen(int i, int j);
void solve(int i);
void saveResult(char *filename);
bool checkMainDiags();

int field[8][8];
int totalSolves = 0;



int _tmain()
{
	setlocale(LC_ALL, "Russian");
	allocateField(field);
	int time = clock();
	solve(7);
	time = clock() - time;
	cout << "Всего найдено решений: " << totalSolves << endl;
	cout << "Затрачено времени: " << time << " мс" << endl;
	cout << "Хотите открыть файл с решениями? (Y - да ; N - нет)";
	char question;
	cin >> question;
	if (question == 'Y' || question == 'y')
	{
		system("start result.txt");
	}
	system("pause");
}

void allocateField(int field[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			field[i][j] = 0;
		}
	}
}

void displayField()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (field[i][j] == -1)
			{
				cout <<"Q ";
			}
			else
			{
				cout << "0 ";
			}
			//cout << field[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}



void placeQueen(int i, int j)
{
	for (int x = 0; x < 8; x++)
	{
		field[x][j]++;
		field[i][x]++;
		if (i + j - x >= 0 && i + j - x < 8)
		{
			field[i + j - x][x]++;//нисходящая диагональ (слева направо)
		}
		if (i - j + x >= 0 && i - j + x < 8)
		{
			field[i - j + x][x]++;//восходящая диагональ (слева направо)
		}
	}
	field[i][j] = -1;
}

void removeQueen(int i, int j)
{
	for (int x = 0; x < 8; x++)
	{
		field[x][j]--;
		field[i][x]--;
		if (i + j - x >= 0 && i + j - x < 8)
		{
			field[i + j - x][x]--;
		}
		if (i - j + x >= 0 && i - j + x < 8)
		{
			field[i - j + x][x]--;
		}
	}
	field[i][j] = 0;
}

void solve(int i)
{
	for (int j = 7; j >= 0; j--)
	{
		if (field[i][j] == 0)
		{
			placeQueen(i, j);
			if (i == 0)
			{
				if(!checkMainDiags())
				{
					totalSolves++;
					saveResult("Result.txt");
				}
			}
			else
			{
				solve(i - 1);
			}
			removeQueen(i, j);
		}
	}
}

void saveResult(char *filename)
{
	ofstream file;
	file.open(filename, ios::app);
	if (!file.is_open())
	{
		cout << "Не могу открыть файл!" << endl;
	}
	else
	{
		file << totalSolves << ") " << endl;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j  < 8; j ++)
			{
				if (field[i][j] == -1)
				{
					file <<"Q ";
				}
				else
				{
					file << "0 ";
				}
			}
			file << endl;
		}
		file << endl;
	}
	file.close();
}


bool checkMainDiags()
{
	int i = 0;
	int j = 0;
	for (int x = 0; x < 8; x++)
	{
		if (i - j + x >= 0 && i - j + x < 8)
		{
			if(field[i - j + x][x] == -1)
			{
				return true;
				break;
			}
		}
	}
	i = 0;
	j = 7;
	for (int x = 0; x < 8; x++)
	{
		if (i + j - x >= 0 && i + j - x < 8)
		{
			if(field[i + j - x][x] == -1)
			{
				return true;
				break;
			}
		}
	}
	return false;
}