#include "tou.h"

C_Ui_Display Ui_Display;

int DeBug_Input(void)
{
	int in = 0;
	cin >> in;
	if (in > 4){
		if (in == 1000) {
			return in;
		}
		else {
			cout << "别乱输" << endl;
			in = DeBug_Input();
			return in;
		}
	}
	else{
		return in;
	}
}
bool DeBug_Input(int a)
{
	int in = a;
	if (in == 0) {
		cout << "我劝你不要没有数据就读取" << endl;
		return FALSE;
	}
	else {
		return TRUE;
	}
}

void LeapYear_com(void)
{
	int year = 0;
	Ui_Display.InputYear();
	cin >> year;

	if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0 && year == 1000)
	{
		Ui_Display.YearRun(year);
		LeapYear_com();
	}
	else if (year != 1000)
	{
		Ui_Display.YearPin(year);
		LeapYear_com();
	}
	else {/*退出*/};
}

void Guess_Numbers(void)
{
	srand(time(0));
	int max_ra = 100, ra = (rand() % max_ra) + 1;
	int input = 0, temp_loop = GUESSNUM;

	do {
		Ui_Display.GuessNumInput();
		cin >> input;

		if (input > ra){
			Ui_Display.GuessNumBig(temp_loop);
		}
		else if (input < ra){
			Ui_Display.GuessNumSmall(temp_loop);
		}
		else {
			Ui_Display.GuessNumEnd();
		}
		temp_loop--;
	} while (temp_loop);
	Ui_Display.GuessNumMaren(ra);
}

void Avrage(void)
{
	vector<double> svve;
	double input = 0;
	int loopnum = 0;
	bool loop_cmd = TRUE;

	do {
		Ui_Display.AverageInput(loopnum);
		cin >> input;

		if (input == 1000) {
			loop_cmd = FALSE;
		}
		else {
			svve.push_back(input);
		}
		input = 0;
		loopnum++;
	} while (loop_cmd);

	sort(svve.begin(), svve.end());
	svve.erase(svve.begin());
	svve.pop_back();


	int size = svve.size();
	double temp = 0, out = 0;

	for (auto i = 0; i < size; i++) {
		temp += svve[i];
	}
	out = temp / size;
	Ui_Display.AverageOut(out);
}

vector<string> Enter_BookData(void)
{
	vector<string> out;
	char enter[ENTERDATA_MAX] = {},c;

	int loop_num = 0;
	bool loop_ctrl = TRUE;

	Ui_Display.InputBook();
	while (loop_ctrl)
	{
		enter[loop_num] = cin.get();

		if (enter[loop_num] == ' ' || enter[loop_num] == '\n') {
			out.push_back(enter);

			if (enter[loop_num] == '\n') {
				loop_ctrl = FALSE;
			}
			else {
				loop_num = 0;
				memset(enter, 0, sizeof(enter));
			}
		}
		else {
			loop_num++;
		}
	}
	return out;
}

void Svve_BookData(BookLby* svve, vector<string> out)
{
	int s_loop_num = out.size() / TOTALCLASSDATA_MAX;
	int s_loop_dan = out.size() % TOTALCLASSDATA_MAX;
	int s_enterloop_num = 0, s_enter_num = 0;

	bool s_loop_ctrl = DeBug_Input(s_loop_num);
	if (!s_loop_dan && s_loop_ctrl)
	{
		do {
			svve[s_enter_num].author.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			svve[s_enter_num].publishing_house.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			svve[s_enter_num].publication_date.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			svve[s_enter_num].translators.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			svve[s_enter_num].price.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			s_enter_num++;
			s_loop_num--;
		} while (s_loop_num);
	}
	else if (s_loop_dan)
	{
		do {
			svve[s_enter_num].author.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			svve[s_enter_num].publishing_house.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			svve[s_enter_num].publication_date.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			svve[s_enter_num].translators.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			svve[s_enter_num].price.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			s_enter_num++;
			s_loop_num--;
		} while (s_loop_num);

		svve[s_enter_num].author.push_back(out[s_enterloop_num]);
		s_enterloop_num++;
		s_loop_dan--;
		if (s_loop_dan != 0) {
			svve[s_enter_num].publishing_house.push_back(out[s_enterloop_num]);
			s_enterloop_num++;
			s_loop_dan--;
			if (s_loop_dan != 0) {
				svve[s_enter_num].publication_date.push_back(out[s_enterloop_num]);
				s_enterloop_num++;
				s_loop_dan--;
				if (s_loop_dan != 0) {
					svve[s_enter_num].translators.push_back(out[s_enterloop_num]);
					s_enterloop_num++;
					s_loop_dan--;
					if (s_loop_dan != 0) {
						svve[s_enter_num].price.push_back(out[s_enterloop_num]);
						s_enterloop_num++;
						s_loop_dan--;
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

void Copy_BookData(BookLby* svve, int size, BookLby* input)
{
	int loop_num = size / TOTALCLASSDATA_MAX;
	int loop_dan = size % TOTALCLASSDATA_MAX;
	int enterloop_num = 0, enter_num = 0;

	if (!loop_dan)
	{
		do {
			svve[enter_num] = BookLby();
			svve[enter_num].author.push_back(input[enter_num].author[enterloop_num]);
			svve[enter_num].publishing_house.push_back(input[enter_num].author[enterloop_num]);
			svve[enter_num].publication_date.push_back(input[enter_num].author[enterloop_num]);
			svve[enter_num].translators.push_back(input[enter_num].author[enterloop_num]);
			svve[enter_num].price.push_back(input[enter_num].author[enterloop_num]);
			enter_num++;
			loop_num--;
		} while (loop_num);
	}
	else if (loop_dan)
	{
		do {
			svve[enter_num] = BookLby();
			svve[enter_num].author.push_back(input[enter_num].author[enterloop_num]);
			svve[enter_num].publishing_house.push_back(input[enter_num].author[enterloop_num]);
			svve[enter_num].publication_date.push_back(input[enter_num].author[enterloop_num]);
			svve[enter_num].translators.push_back(input[enter_num].author[enterloop_num]);
			svve[enter_num].price.push_back(input[enter_num].author[enterloop_num]);
			enter_num++;
			loop_num--;
		} while (loop_num);

		svve[enter_num] = BookLby();
		svve[enter_num].author.push_back(input[enter_num].author[enterloop_num]);
		loop_dan--;
		if (loop_dan != 0) {
			svve[enter_num].publishing_house.push_back(input[enter_num].author[enterloop_num]);
			loop_dan--;
			if (loop_dan != 0) {
				svve[enter_num].publication_date.push_back(input[enter_num].author[enterloop_num]);
				loop_dan--;
				if (loop_dan != 0) {
					svve[enter_num].translators.push_back(input[enter_num].author[enterloop_num]);
					loop_dan--;
					if (loop_dan != 0) {
						svve[enter_num].price.push_back(input[enter_num].author[enterloop_num]);
						loop_dan--;
						if (loop_dan != 0) {

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




