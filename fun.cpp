#include "tou.h"

int DeBug_Fun(int mode)
{
	int fun = 0;
	do {
		fun = FunJudg_Display(mode);
		if (fun > mode) {
			cout << "������" << endl;
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
			<< "��������ʹ�õĹ���\n1.�����ж�\n2.������С��Ϸ\n3.�鼮\n4.��ƽ����" << endl
			<< "================================================================================" << endl;
		cin >> fun_funjudg;
	}
	else if (mode == 4)
	{
		cout << "================================================================================" << endl
			<< "1.�����鼮��Ϣ\n2.��ȡ�鼮��Ϣ\n3.����鼮��Ϣ\n4.�˻���һ��" << endl
			<< "================================================================================" << endl;
		cin >> fun_funjudg;
	}
	else if (mode == 20)
	{
		cout << "�����鼮���ݣ��밴���ߣ������磬�������ڣ����룬�۸��˳�����롣�Կո������" << endl;
	}
	else
	{
		throw "FunJudg()��������";
	}
	return fun_funjudg;
}

void LeapYear_Judg(void)
{
	int year = 0;
	do {
		cout << "������ݣ�����1000�˳�����";
		cin >> year;
		if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0 && year == 1000) {
			cout << year << " ������" << endl;
		}
		else if(year != 1000){
			cout << year << " ��ƽ��" << endl;
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
		cout << "����ǣ�";
		cin >> guessnum;

		if (guessnum > ra) {
			cout << "����,����" << temp_loop - 1 << "�λ���";
		}
		else if (guessnum < ra) {
			cout << "С��,����" << temp_loop - 1 << "�λ���";
		}
		else {
			cout << "��ϲ��¶��ˣ�";
		}
		temp_loop--;
	} while (temp_loop);
	cout << "SB����" << ra;
}


void Average(void)
{
	double temp_enter = 0;
	int temp_loopnum = 0;
	vector<double> svve;
	bool temp_loop_cmdwhile = TRUE;

	do
	{
		cout << "����� " << temp_loopnum + 1 << "����(����1000��������)" << endl;
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

	sort(svve.begin(), svve.end());  //����
	svve.erase(svve.begin());  
	svve.pop_back();     //ɾ��������С��
	
	double total_size = svve.size();
	double temp_data = 0;
	double average = 0;
	for (int i = 0; i < total_size; i++)
	{
		temp_data += svve[i];
	}
	average = temp_data / total_size;
	cout << "ƽ�����ǣ�" << average << endl;
}






vector<string> BookDataDis(void)
{
	vector<string> data;  //���ڴ������
	char temp_enter[ENTERDATA_MAX] = {}, temp_data[ENTERDATA_MAX] = {}; //��ʱ�������ת������
	int temp_loop_ass = 0, temp_loop_cmd = 0;//���ڿ���ѭ��
	bool temp_loop_cmdwhile = TRUE;//���ڶ�ȡ���ַ�ʱ������ѭ��
	FunJudg_Display(FUN_ENTER);

	while (temp_loop_cmdwhile)//��ѭ��
	{
		temp_enter[temp_loop_cmd] = cin.get(); //����

		if (temp_enter[temp_loop_cmd] == ' ' || temp_enter[temp_loop_cmd] == '\n') //�ж��Ƿ��Ѿ���ȡ��һ�������ʻ��߽���
		{
			do {
				temp_data[temp_loop_ass] = temp_enter[temp_loop_ass];  //��ȡ���Ĵ��︳ֵ����ʱ�洢
				temp_loop_ass++;
			} while (temp_loop_cmd != temp_loop_ass); //��֮ǰ��ȡ�������Ա�
			data.push_back(temp_data); //��ֵ��data

			if (temp_enter[temp_loop_ass] == '\n') { //��������ѭ��
				temp_loop_cmdwhile = FALSE;
			}
			else {  //����������ʱ����
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
	int data_size = data.size(); //��ȡһ���м�������
	int temp_loopnum = data_size / TOTALCLASSDATA_MAX; //���㵥����Ҫѭ�����β��ܴ������
	int size_remainder = data_size % TOTALCLASSDATA_MAX;  //���ڼ������������Ҫ��ֵ����
	int temp_loop_classnum = 0, temp_loop_datanum = 0;  //���ڿ���ѭ��

	if (temp_loopnum == 0)
	{
		cout << "�ҽ���������뼸��" << endl;
	}
	else {/*NULL*/ };

	if (!size_remainder) //�ж��Ƿ���Ҫ������ֵ
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
		cout << "�鼮��Ϣ:" << endl
			<< "���ߣ�" << PBookData[0].author[0] << endl
			<< "�����磺" << PBookData[0].publishing_house[0] << endl
			<< "�������ڣ�" << PBookData[0].publication_date[0] << endl
			<< "���룺" << PBookData[0].translators[0] << endl
			<< "�۸�" << PBookData[0].price[0] << endl;
	}
	else
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

}