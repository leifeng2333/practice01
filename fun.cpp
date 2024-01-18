#include "tou.h"

int DeBug_Fun(int mode)
{
	int fun = 0;
	do {
		fun = FunJudg_Display(mode);
		if (fun > mode) {
			cout << "别乱输" << endl;
		}
		else if (fun == 1000) {
			break;
		}
	} while (!(fun <= 4));
	return fun;
}


int FunJudg_Display(int mode)
{
	int fun_funjudg = 0;
	if (mode == 5)
	{
		cout << "================================================================================" << endl
			<< "输入你想使用的功能\n1.闰年判断\n2.猜数字小游戏\n3.书籍\n4.求平均数" << endl
			<< "================================================================================" << endl;
		cin >> fun_funjudg;
	}
	else if (mode == 4)
	{
		cout << "================================================================================" << endl
			<< "1.输入书籍信息\n2.读取书籍信息\n3.清空书籍信息\n4.退回上一级" << endl
			<< "================================================================================" << endl;
		cin >> fun_funjudg;
	}
	else if (mode == 20)
	{
		cout << "输入书籍数据（请按作者，出版社，出版日期，翻译，价格的顺序输入。以空格隔开）" << endl;
	}
	else
	{
		throw "FunJudg()参数错误";
	}
	return fun_funjudg;
}

void LeapYear_Judg(void)
{
	int year = 0;
	do {
		cout << "输入年份（输入1000退出）：";
		cin >> year;
		if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0 && year == 1000) {
			cout << year << " 是闰年" << endl;
		}
		else if(year != 1000){
			cout << year << " 是平年" << endl;
		}
		else { break; }
	} while (year != 1000);
}

void GuessNumbers(void)
{
	srand(time(0));
	int max_ra = 100, ra = (rand() % max_ra) + 1;
	int guessnum = 0;
	int temp_loop = GUESSNUM;

	do {
		cout << "你猜是：";
		cin >> guessnum;

		if (guessnum > ra) {
			cout << "大了,还有" << temp_loop - 1 << "次机会";
		}
		else if (guessnum < ra) {
			cout << "小了,还有" << temp_loop - 1 << "次机会";
		}
		else {
			cout << "恭喜你猜对了！";
		}
		temp_loop--;
	} while (temp_loop);
	cout << "SB答案是" << ra;
}


void Average(void)
{
	double temp_enter = 0;
	int temp_loopnum = 0;
	vector<double> svve;
	bool temp_loop_cmdwhile = TRUE;

	do
	{
		cout << "输入第 " << temp_loopnum + 1 << "个数(输入1000结束输入)" << endl;
		cin >> temp_enter;

		if (temp_enter == 1000) {
			temp_loop_cmdwhile = FALSE;
		}
		else {
			svve.push_back(temp_enter);
		}
		temp_enter = 0;
		temp_loopnum++;
	} while (temp_loop_cmdwhile);

	sort(svve.begin(), svve.end());  //排序
	svve.erase(svve.begin());  
	svve.pop_back();     //删除最大和最小项
	
	double total_size = svve.size();
	double temp_data = 0;
	double average = 0;
	for (int i = 0; i < total_size; i++)
	{
		temp_data += svve[i];
	}
	average = temp_data / total_size;
	cout << "平均数是：" << average << endl;
}






vector<string> BookDataDis(void)
{
	vector<string> data;  //用于传输给类
	char temp_enter[ENTERDATA_MAX] = {}, temp_data[ENTERDATA_MAX] = {}; //临时的输入和转存数组
	int temp_loop_ass = 0, temp_loop_cmd = 0;//用于控制循环
	bool temp_loop_cmdwhile = TRUE;//用于读取完字符时跳出主循环
	FunJudg_Display(FUN_ENTER);

	while (temp_loop_cmdwhile)//主循环
	{
		temp_enter[temp_loop_cmd] = cin.get(); //输入

		if (temp_enter[temp_loop_cmd] == ' ' || temp_enter[temp_loop_cmd] == '\n') //判断是否已经读取到一整个单词或者结束
		{
			do {
				temp_data[temp_loop_ass] = temp_enter[temp_loop_ass];  //读取到的词语赋值给临时存储
				temp_loop_ass++;
			} while (temp_loop_cmd != temp_loop_ass); //和之前读取的字数对比
			data.push_back(temp_data); //赋值给data

			if (temp_enter[temp_loop_ass] == '\n') { //用于跳出循环
				temp_loop_cmdwhile = FALSE;
			}
			else {  //用于重置临时数组
				temp_loop_ass = 0;
				temp_loop_cmd = 0;
				memset(temp_enter, 0, sizeof(temp_enter));
				memset(temp_data, 0, sizeof(temp_data));
			}
		}
		else {
			temp_loop_cmd++;
		}
	}
	return data;
}


void SvveBookData(vector<string> data, BookLby* PBookData)
{
	int data_size = data.size(); //获取一共有几个单词
	int temp_loopnum = data_size / TOTALCLASSDATA_MAX; //计算单词需要循环几次才能传输完成
	int size_remainder = data_size % TOTALCLASSDATA_MAX;  //用于计算出单独还需要赋值几次
	int temp_loop_classnum = 0, temp_loop_datanum = 0;  //用于控制循环

	if (temp_loopnum == 0)
	{
		cout << "我建议你多输入几个" << endl;
	}
	else {/*NULL*/ };

	if (!size_remainder) //判断是否需要单独赋值
	{
		do {
			PBookData[temp_loop_classnum].author.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			PBookData[temp_loop_classnum].publishing_house.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			PBookData[temp_loop_classnum].publication_date.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			PBookData[temp_loop_classnum].translators.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			PBookData[temp_loop_classnum].price.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			temp_loopnum--;
		} while (temp_loopnum);
	}
	else
	{
		do {
			PBookData[temp_loop_classnum].author.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			PBookData[temp_loop_classnum].publishing_house.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			PBookData[temp_loop_classnum].publication_date.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			PBookData[temp_loop_classnum].translators.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			PBookData[temp_loop_classnum].price.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			temp_loopnum--;
		} while (temp_loopnum);

		PBookData[temp_loop_classnum].author.push_back(data[temp_loop_datanum]);
		temp_loop_datanum++;
		size_remainder--;
		if (size_remainder != 0) {
			PBookData[temp_loop_classnum].publishing_house.push_back(data[temp_loop_datanum]);
			temp_loop_datanum++;
			size_remainder--;
			if (size_remainder != 0) {
				PBookData[temp_loop_classnum].publication_date.push_back(data[temp_loop_datanum]);
				temp_loop_datanum++;
				size_remainder--;
				if (size_remainder != 0) {
					PBookData[temp_loop_classnum].translators.push_back(data[temp_loop_datanum]);
					temp_loop_datanum++;
					size_remainder--;
					if (size_remainder != 0) {
						PBookData[temp_loop_classnum].price.push_back(data[temp_loop_datanum]);
						temp_loop_datanum++;
						size_remainder--;
					}
					else {/*NULL*/ };
				}
				else {/*NULL*/ };
			}
			else {/*NULL*/ };
		}
		else {/*NULL*/ };
	}
	
}


void Display_Booklby(BookLby* PBookData, int data_size)
{
	int temp_judgment = data_size / TOTALCLASSDATA_MAX;
	int temp_num = data_size % TOTALCLASSDATA_MAX;

	if (temp_judgment == 1 && temp_num == 0)
	{
		cout << "书籍信息:" << endl
			<< "作者：" << PBookData[0].author[0] << endl
			<< "出版社：" << PBookData[0].publishing_house[0] << endl
			<< "出版日期：" << PBookData[0].publication_date[0] << endl
			<< "翻译：" << PBookData[0].translators[0] << endl
			<< "价格：" << PBookData[0].price[0] << endl;
	}
	else
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

}