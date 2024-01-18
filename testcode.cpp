#include "tou.h"

int main()     //输入`会进入无限循环
{
	C_Ui_Display Ui_Display;
	int bookloopnum = 0;
	int* Pbookloopnum = &bookloopnum;
	char c;

	vector<string> temp_bookdata;
	BookLby* Book_Data = nullptr;

	int loop_bookmenu = 0;
	do {
		Ui_Display.BookMenu();
		loop_bookmenu = DeBug_Input();
		
		if (loop_bookmenu == 1){
			while ((c = getchar()) != '\n' && c != EOF);

			temp_bookdata = Enter_BookData();
			int size = (temp_bookdata.size() / TOTALCLASSDATA_MAX) + 1;
			BookLby* Temp_bookData = new BookLby[size];
			Svve_BookData(Temp_bookData, temp_bookdata);

			BookLby Temp_Svvebookdata = *Book_Data;
			Book_Data = new BookLby[size];
			Copy_BookData(Book_Data, temp_bookdata.size(), Temp_bookData);

			delete[] Temp_bookData;
		}
		else if (loop_bookmenu == 2)
		{

		}
		else if (loop_bookmenu == 3)
		{

		}
		else if (loop_bookmenu == 4)
		{

		}








	} while (loop_bookmenu != 1000);




}