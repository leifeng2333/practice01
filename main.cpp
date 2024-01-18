#include "tou.h"

int main()
{
	vector<string> temp_data;
	BookLby* PBookData = {};
	int data_size = 0;

	int fun = 0;
	do
	{
		fun = DeBug_Fun(FUN_MENU);
		if (fun == 1) { 
			LeapYear_Judg();
		}
		else if (fun == 2) {
			GuessNumbers();
		}
		else if (fun == 3) {
			int menu = 0;
			do
			{
				int menu = DeBug_Fun(FUN_BOOK);
				if (menu == 1) {
					char c;
					while ((c = getchar()) != '\n');

					temp_data = BookDataDis();
					data_size = temp_data.size();
					PBookData = new BookLby[data_size];
					SvveBookData(temp_data, PBookData);
				}
				else if (menu == 2) {

					if (PBookData == NULL) {
						cout << "请先输入数据" << endl;
					}
					else {
						Display_Booklby(PBookData, data_size);
					}
				}
				else if (menu == 3) {
					delete[] PBookData; //释放内存
					PBookData = {};  //指针指向NULL防止上面判断失误
				}
				else if (menu == 4) {
					menu = 1000;
				}
			} while (menu != 1000);
		}
		else if (fun == 4) {
			Average();
		}
		else if (fun == 5) {
			fun = 1000;
		}

	} while (fun != 1000);
	
	


	return 0;
}
