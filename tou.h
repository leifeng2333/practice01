#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <algorithm>

#define ENTERDATA_MAX 50
#define CLASSDATA_MAX 50
#define TOTALCLASSDATA_MAX 5
#define GUESSNUM 5
#define FUN_BOOK 4
#define FUN_MENU 5
#define FUN_ENTER 20

using namespace std;

class BookLby
{
public:
	vector<string> price;            //�۸�
	vector<string> translators;      //������
	vector<string> author;           //����
	vector<string> publication_date; //��������
	vector<string> publishing_house; //������
};

int             DeBug_Input    (void);
bool            DeBug_Input    (int);
void            LeapYear_com   (void);
void            Guess_Numbers  (void);
void            Avrage         (void);
vector<string>  Enter_BookData (void);
void            Svve_BookData  (BookLby* svve, vector<string> out);
void            Copy_BookData  (BookLby* svve, int size, BookLby* input);
void            SP_SvveBookData(BookLby* svve, int* num);
class C_Ui_Display
{
private:
	int out = 0;

public:

	void SelectFeature(void) const
	{
		cout << "================================================================================" << endl
			<< "��������ʹ�õĹ���\n1.�����ж�\n2.������С��Ϸ\n3.�鼮\n4.��ƽ����" << endl
			<< "================================================================================" << endl;
	}

	void BookMenu(void) const
	{
		cout << "================================================================================" << endl
			<< "1.�����鼮��Ϣ\n2.��ȡ�鼮��Ϣ\n3.����鼮��Ϣ\n4.�˻���һ��" << endl
			<< "================================================================================" << endl;
	}

	void InputBook(void) const
	{
		cout << "�����鼮���ݣ��밴���ߣ������磬�������ڣ����룬�۸��˳�����롣�Կո������" << endl;
	}

	void InputYear(void) const
	{
		cout << "������ݣ�����1000�˳�����";
	}

	void YearRun(int year) const
	{
		cout << year << " ������" << endl;
	}

	void YearPin(int year) const
	{
		cout << year << " ��ƽ��" << endl;
	}

	void GuessNumInput(void) const
	{
		cout << "����ǣ�";
	}

	void GuessNumBig(int opp) const
	{
		cout << "����,����" << opp - 1 << "�λ���";
	}

	void GuessNumSmall(int opp) const
	{
		cout << "С��,����" << opp - 1 << "�λ���";
	}

	void GuessNumEnd(void) const
	{
		cout << "��ϲ��¶��ˣ�";
	}

	void GuessNumMaren(int ra) const
	{
		cout << "SB����" << ra;
	}

	void AverageInput(int opp) const
	{
		cout << "����� " << opp + 1 << "����(����1000��������)" << endl;
	}

	void AverageOut(double opp) const
	{
		cout << "ƽ�����ǣ�" << opp << endl;
	}

	void ybb(void) const
	{
		cout << "�ҽ���������뼸��" << endl;
	}

	void BookClear(void) const
	{
		cout << "���ڴ����ͷţ�ָ��ſ�" << endl;
	}

	void Booklby(BookLby* PBookData, int data_size)
	{
		int temp_judgment = data_size / TOTALCLASSDATA_MAX;
		int temp_num = data_size % TOTALCLASSDATA_MAX;

		bool debug = DeBug_Input(temp_judgment);

		if (temp_judgment == 1 && temp_num == 0 && debug)
		{
			cout << "�鼮��Ϣ:" << endl
				<< "���ߣ�" << PBookData[0].author[0] << endl
				<< "�����磺" << PBookData[0].publishing_house[0] << endl
				<< "�������ڣ�" << PBookData[0].publication_date[0] << endl
				<< "���룺" << PBookData[0].translators[0] << endl
				<< "�۸�" << PBookData[0].price[0] << endl;
		}
		else if (debug)
		{
			int temp_loopnum = 0;
			do {
				cout << "�鼮��Ϣ" << temp_loopnum + 1 << ":" << endl
					<< "���ߣ�" << PBookData[0].author[temp_loopnum] << endl
					<< "�����磺" << PBookData[0].publishing_house[temp_loopnum] << endl
					<< "�������ڣ�" << PBookData[0].publication_date[temp_loopnum] << endl
					<< "�������ڣ�" << PBookData[0].publication_date[temp_loopnum] << endl
					<< "�۸�" << PBookData[0].price[temp_loopnum] << endl;
				temp_loopnum++;
			} while (!(temp_judgment == temp_loopnum));

			cout << "�鼮��Ϣ" << temp_loopnum + 1 << ":" << endl;
			if (temp_num != 0) {
				cout << "���ߣ�" << PBookData[0].author[temp_loopnum] << endl;
				temp_num--;
				if (temp_num != 0) {
					cout << "�����磺" << PBookData[0].publishing_house[temp_loopnum] << endl;
					temp_num--;
					if (temp_num != 0) {
						cout << "�������ڣ�" << PBookData[0].publication_date[temp_loopnum] << endl;
						temp_num--;
						if (temp_num != 0) {
							cout << "���룺" << PBookData[0].translators[temp_loopnum] << endl;
							temp_num--;
							if (temp_num != 0) {
								cout << "�۸�" << PBookData[0].price[temp_loopnum] << endl;
								temp_num--;
							}
							else {/*NULL*/ };
						}
						else {/*NULL*/ };
					}
					else {/*NULL*/ };
				}
				else {/*NULL*/ };
			}
			else {/*NULL*/ };

		}
		else{/*�˳�*/ }

	}
};