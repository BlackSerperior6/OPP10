#pragma once

#include "Pair.h"

void WriteAFile(int Lenght) 
{
	fstream F1("F1.txt", ios::out | ios::trunc); //ofstream

	if (!F1)
	{
		cout << "Не удалось открыть файл" << endl;
		return;
	}
	
	for (int i = 0; i < Lenght; i++)
	{
		Pair pair;
		cin >> pair;

		F1 << pair << endl;
	}

	F1.close();
}

void PrintAFile() 
{
	fstream F1("F1.txt", ios::in); //ifstream

	if (!F1)
	{
		cout << "Не удалось открыть файл" << endl;
		return;
	}

	Pair pair;

	while (F1 >> pair)
		cout << pair << endl;
}

void RemoveAllLesserPair(Pair& comparePair) 
{
	fstream F1("F1.txt", ios::in); //ifstream

	if (!F1)
	{
		cout << "Не удалось открыть файл" << endl;
		return;
	}

	fstream Temp("temp.txt", ios::out | ios::trunc); //ofstream

	Pair buffer;

	while (F1 >> buffer)
	{
		if (buffer >= comparePair)
			Temp << buffer << endl;
	}

	F1.close();
	Temp.close();

	remove("F1.txt");
	rename("temp.txt", "F1.txt");
}

void AddLToPairs(double L)
{
	fstream F1("F1.txt", ios::in); //ifstream

	if (!F1)
	{
		cout << "Не удалось открыть файл" << endl;
		return;
	}

	fstream Temp("temp.txt", ios::out | ios::trunc); //ofstream

	Pair buffer;

	while (F1 >> buffer)
	{
		buffer += L;

		Temp << buffer << endl;
	}
	
	F1.close();
	Temp.close();

	remove("F1.txt");
	rename("temp.txt", "F1.txt");
}

void AddKMorePairs(int position, int K)
{
	if (position <= 0 || K <= 0)
	{
		cout << "НЕПРАВИЛЬНО! Попробуй еще раз (номер и k должны быть >= 1)!" << endl;
		return;
	}

	fstream F1("F1.txt", ios::in); //ifstream

	if (!F1)
	{
		cout << "Не удалось открыть файл" << endl;
		return;
	}

	fstream Temp("temp.txt", ios::out | ios::trunc); //ofstream

	Pair buffer;

	int counter = 0;

	while (F1 >> buffer)
	{
		counter++;
		Temp << buffer << endl;

		if (counter == position)
		{
			for (int i = 0; i < K; i++)
			{
				Pair New_Pair;

				cin >> New_Pair;

				Temp << New_Pair << endl;
			}
		}
	}

	if (counter < position)
		cout << "Вы ввели слишком большую позицию. Такой в файле просто нет!" << endl;

	F1.close();
	Temp.close();

	remove("F1.txt");
	rename("temp.txt", "F1.txt");
}
