#pragma once

#include "Pair.h"

void WriteAFile(int Lenght) 
{
	ofstream F1("F1.txt");

	if (!F1.is_open())
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
	ifstream F1("F1.txt");

	if (!F1.is_open())
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
	ifstream F1("F1.txt");
	ofstream Temp("temp.txt");

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
	ifstream F1("F1.txt");
	ofstream Temp("temp.txt");

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

	ifstream F1("F1.txt");
	ofstream Temp("temp.txt");

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
