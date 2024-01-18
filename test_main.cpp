#include "tou.h"

int main()
{
	vector<string> temp_bookdata;
	BookLby* PBookData = {};
	int bookdata_size = 0;

	int loop_fun = 0;
	do{
		loop_fun = DeBug_Input();

		if (loop_fun == 1) {
			LeapYear_com();
		}
		else if (loop_fun == 2) {
			Guess_Numbers();
		}
		else if (loop_fun == 3) {

		}
		else if (loop_fun == 4) {
			Avrage();
		}
		else {
			loop_fun = 1000;
		}
	} while (loop_fun != 1000);

	return 0;
}