#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
//---------------------Функции и Прототипы---------------------------------------

class Abonents
{
private:
public:

	string data;
	double telephone;

	void GetTelephone()
	{
		string temp;
		for (int i = 0; i < 10; i++)
		{
			if (data[i] > 47 && data[i] < 58)
			{
				temp += data[i];
			}
		}
		telephone = stod(temp);
	}

};

void Sort(vector<Abonents> & abonent, int num_str)
{

	for (int i = 0; i < num_str; i++) {
		for (int j = 0; j < num_str; j++) {
			if (abonent[j].telephone > abonent[j + 1].telephone)
			{

				Abonents temp = abonent[j]; // создали дополнительную переменную

				abonent[j] = abonent[j + 1]; // меняем местами

				abonent[j + 1] = temp; // значения элементов

			}
		}
	}

}

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------САМА ПРОГА-------------------------------------

	 //----- ОТКРЫТИЕ И НАЧАЛА РАБОТЫ С ВХОДНЫМ ФАЙЛОМ----------------------------------------------------

	vector<Abonents> abonent;
	abonent.push_back(Abonents());
	int num_str = 0;


	string file_name;    // "InFile2.txt";

	cout << "Введите имя файла: ";

	cin >> file_name;

	ifstream fin;

	fin.open(file_name);

	if (!fin.is_open())                                            // проверяем ( если файл НЕ открыт , то: )
	{
		cout << "Ошибка открытия файла! ( ВХОДНОГО )" << endl;
	}

	else                                                          // Если ОТКРЫТ , то тут уже сама прога :

	{

		cout << "Файл открыт корректно! ( ВХОДНОЙ )" << endl;

		//----------------------------------------------------------------------------------------------

		char ch;                                                  // перем. для посимвольного считывания

		while (!fin.eof())
		{
			ch = '\0';                                            // затираем прошлое считываение

			fin.get(ch);                                          // берем первый символ ( в каждом цикле следующий)

			cout << ch;                       // ОТЛАДКА : выводим взятые символы ( убеждаемся, что взяли не криво )

		   // --------------------- !!! ЛОГИКА !!! ----------------------------------------------------
			
			if (ch == '\n')
			{
				abonent.push_back(Abonents());
				num_str++;
			}
			else
			{
				abonent[num_str].data += ch;
			}

		}

	}

	cout << endl;

	for (int i = 0; i <= num_str; i++)
	{
		abonent[i].GetTelephone();
	}

	fin.close();

	Sort(abonent, num_str);

	//---- ОТКРЫТИЕ И ЗАПИСЬ ВЫХОДНОГО ФАЙЛА ------------------------------------------------------------

	

	ofstream fout;
	//cout << "\n Введите название выходного файла: ";
	//cin >> file_name;
	fout.open(file_name);

	if (!fout.is_open())
	{
		cout << "Ошибка открытия ВЫХОДНОГО файла! " << endl;
	}
	else
	{
		cout << "Файл открыт корректно ! (ВЫХОДНОЙ) " << endl;

		for (int i = 0; i <= num_str; i++)
		{
			fout << abonent[i].data ;
			if (i != num_str)
			{
				fout << "\n";
			}
		}


	}

	fout.close();
	system("pause");
	return 0;
}
