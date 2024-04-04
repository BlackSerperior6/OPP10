#include "file_work.h"

int main()
{
	system("chcp 1251");

	int lenght;
	do
	{
		cout << "Введите кол-во элементов в файле" << endl;
		cin >> lenght;
	} 
	while (lenght <= 0);

	WriteAFile(lenght);

	bool should_stop = false;

	while (!should_stop)
	{
		cout << endl << endl;
		cout << "1 - перезаписать файл\n2 - удалить все записи, меньше заданной пары\n3 - увеличить все записи на L\n4 - вставить после опеределенного номера k элементов\n5 - распечатать файл в консоль\n6 - закончить работу программы" << endl;

		int Choice;

		cin >> Choice;


		Pair comparePair;
		switch (Choice)
		{
		case 1:

			do
			{
				cout << "Введите кол-во элементов в файле!" << endl;
				cin >> lenght;
			} 
			while (lenght <= 0);

			WriteAFile(lenght);
			break;

		case 2:

			cout << "Введите пару, с которой будут сравниваться элементы файла!" << endl;

			cin >> comparePair;

			RemoveAllLesserPair(comparePair);
			break;

		case 3:
			cout << "Введите L!" << endl;

			double L;

			cin >> L;

			AddLToPairs(L);
			break;

		case 4:
			cout << "Введите номер и k!" << endl;

			int position;
			int k;

			cin >> position >> k;

			AddKMorePairs(position, k);
			break;

		case 5:

			PrintAFile();
			break;

		case 6:

			should_stop = true;
			break;

		default:
			cout << "Невалидное число!" << endl;
			break; 
		}
	}
}
