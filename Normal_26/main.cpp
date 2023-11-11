#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
//---------------------������� � ���������---------------------------------------

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

				Abonents temp = abonent[j]; // ������� �������������� ����������

				abonent[j] = abonent[j + 1]; // ������ �������

				abonent[j + 1] = temp; // �������� ���������

			}
		}
	}

}

//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	 //----- �������� � ������ ������ � ������� ������----------------------------------------------------

	vector<Abonents> abonent;
	abonent.push_back(Abonents());
	int num_str = 0;


	string file_name;    // "InFile2.txt";

	cout << "������� ��� �����: ";

	cin >> file_name;

	ifstream fin;

	fin.open(file_name);

	if (!fin.is_open())                                            // ��������� ( ���� ���� �� ������ , ��: )
	{
		cout << "������ �������� �����! ( �������� )" << endl;
	}

	else                                                          // ���� ������ , �� ��� ��� ���� ����� :

	{

		cout << "���� ������ ���������! ( ������� )" << endl;

		//----------------------------------------------------------------------------------------------

		char ch;                                                  // �����. ��� ������������� ����������

		while (!fin.eof())
		{
			ch = '\0';                                            // �������� ������� �����������

			fin.get(ch);                                          // ����� ������ ������ ( � ������ ����� ���������)

			cout << ch;                       // ������� : ������� ������ ������� ( ����������, ��� ����� �� ����� )

		   // --------------------- !!! ������ !!! ----------------------------------------------------
			
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

	//---- �������� � ������ ��������� ����� ------------------------------------------------------------

	

	ofstream fout;
	//cout << "\n ������� �������� ��������� �����: ";
	//cin >> file_name;
	fout.open(file_name);

	if (!fout.is_open())
	{
		cout << "������ �������� ��������� �����! " << endl;
	}
	else
	{
		cout << "���� ������ ��������� ! (��������) " << endl;

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
