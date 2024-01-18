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
	vector<string> price;            //价格
	vector<string> translators;      //翻译者
	vector<string> author;           //作者
	vector<string> publication_date; //出版日期
	vector<string> publishing_house; //出版社
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
			<< "输入你想使用的功能\n1.闰年判断\n2.猜数字小游戏\n3.书籍\n4.求平均数" << endl
			<< "================================================================================" << endl;
	}

	void BookMenu(void) const
	{
		cout << "================================================================================" << endl
			<< "1.输入书籍信息\n2.读取书籍信息\n3.清空书籍信息\n4.退回上一级" << endl
			<< "================================================================================" << endl;
	}

	void InputBook(void) const
	{
		cout << "输入书籍数据（请按作者，出版社，出版日期，翻译，价格的顺序输入。以空格隔开）" << endl;
	}

	void InputYear(void) const
	{
		cout << "输入年份（输入1000退出）：";
	}

	void YearRun(int year) const
	{
		cout << year << " 是闰年" << endl;
	}

	void YearPin(int year) const
	{
		cout << year << " 是平年" << endl;
	}

	void GuessNumInput(void) const
	{
		cout << "你猜是：";
	}

	void GuessNumBig(int opp) const
	{
		cout << "大了,还有" << opp - 1 << "次机会";
	}

	void GuessNumSmall(int opp) const
	{
		cout << "小了,还有" << opp - 1 << "次机会";
	}

	void GuessNumEnd(void) const
	{
		cout << "恭喜你猜对了！";
	}

	void GuessNumMaren(int ra) const
	{
		cout << "SB答案是" << ra;
	}

	void AverageInput(int opp) const
	{
		cout << "输入第 " << opp + 1 << "个数(输入1000结束输入)" << endl;
	}

	void AverageOut(double opp) const
	{
		cout << "平均数是：" << opp << endl;
	}

	void ybb(void) const
	{
		cout << "我建议你多输入几个" << endl;
	}

	void BookClear(void) const
	{
		cout << "类内存以释放，指针放空" << endl;
	}

	void Booklby(BookLby* PBookData, int data_size)
	{
		int temp_judgment = data_size / TOTALCLASSDATA_MAX;
		int temp_num = data_size % TOTALCLASSDATA_MAX;

		bool debug = DeBug_Input(temp_judgment);

		if (temp_judgment == 1 && temp_num == 0 && debug)
		{
			cout << "书籍信息:" << endl
				<< "作者：" << PBookData[0].author[0] << endl
				<< "出版社：" << PBookData[0].publishing_house[0] << endl
				<< "出版日期：" << PBookData[0].publication_date[0] << endl
				<< "翻译：" << PBookData[0].translators[0] << endl
				<< "价格：" << PBookData[0].price[0] << endl;
		}
		else if (debug)
		{
			int temp_loopnum = 0;
			do {
				cout << "书籍信息" << temp_loopnum + 1 << ":" << endl
					<< "作者：" << PBookData[0].author[temp_loopnum] << endl
					<< "出版社：" << PBookData[0].publishing_house[temp_loopnum] << endl
					<< "出版日期：" << PBookData[0].publication_date[temp_loopnum] << endl
					<< "出版日期：" << PBookData[0].publication_date[temp_loopnum] << endl
					<< "价格：" << PBookData[0].price[temp_loopnum] << endl;
				temp_loopnum++;
			} while (!(temp_judgment == temp_loopnum));

			cout << "书籍信息" << temp_loopnum + 1 << ":" << endl;
			if (temp_num != 0) {
				cout << "作者：" << PBookData[0].author[temp_loopnum] << endl;
				temp_num--;
				if (temp_num != 0) {
					cout << "出版社：" << PBookData[0].publishing_house[temp_loopnum] << endl;
					temp_num--;
					if (temp_num != 0) {
						cout << "出版日期：" << PBookData[0].publication_date[temp_loopnum] << endl;
						temp_num--;
						if (temp_num != 0) {
							cout << "翻译：" << PBookData[0].translators[temp_loopnum] << endl;
							temp_num--;
							if (temp_num != 0) {
								cout << "价格：" << PBookData[0].price[temp_loopnum] << endl;
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
		else{/*退出*/ }

	}
};