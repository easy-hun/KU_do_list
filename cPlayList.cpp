// ****** cPlayList.cpp ******
#include "cPlayList.h"
#include< cstdlib >
#include<cstdio>
cPlayList::cPlayList()
{
	this->list = new cSchedule[100];
}


cPlayList::~cPlayList()
{
	// 메모리 반환 :: 일정
	if (this->list != nullptr) {
		delete[] this->list;
		this->list = nullptr;
	}

	// 메모리 반환 :: 카테고리
	if (this->categoryData != nullptr) {
		delete[] this->categoryData;
		this->categoryData = nullptr;
	}
}

void cPlayList::addSchedule()
{
	if (sCount < 100) {
		list[sCount++].makeSchedule(category, categorySize,size_row, FileList);
	}
	else {
		cout << ">> 일정을 더 이상 추가할 수 없습니다.\n";
		_getch();
	}
}

void create_Listfile(string FileList[100][6], int size_row);
void create_Categoryfile(string *category, int categorySize);
void load_Categoryfile(string *category, int& categorySize);
void cPlayList::removeSchedule()
{
	list[sCount--].deleteSchedule(size_row, FileList);
	// @@@
//
//	string name;
//	int temp[100] = {}, count = 0, t;
//	bool check = true;
//
//re:;
//	system("cls");
//	if (!check) cin.clear(); cin.ignore(INT_MAX, '\n');
//	cout << "삭제할 일정의 이름을 입력하세요 >> ";
//	getline(cin, name);
//	if (!isRightSchedule(name)) {
//		check = false;
//		_getch();
//		goto re;
//	}
//	for (size_t i = 0; i < sCount; i++) {
//		if (list[i].getsName().compare(name) == 0) {
//			temp[count++] = i;
//		}
//	}
//re2:;
//	if (!check) cin.clear(); cin.ignore(INT_MAX, '\n');
//	if (count == 0) {
//		cout << "해당하는 이름의 일정이 없습니다.\n";
//		_getch();
//		return;
//	}
//	else if (count) {
//	re3:;
//		char c;
//		cout << "해당 일정을 삭제하시겠습니까? (y/n) >> ";
//		cin >> c;
//		if (cin.fail()) {
//			cout << "올바른 입력을 다시 해주세요.\n";
//			check = false;
//			_getch();
//			goto re3;
//		}
//		else if (c == 'n') {
//			cout << "메인 메뉴로 다시 돌아갑니다.\n";
//			_getch();
//			return;
//		}
//		else if (c == 'y') {
//			for (size_t i = temp[0]; i < sCount-1; i++) {
//				
//			}
//			cout << "일정을 삭제합니다.\n";
//			_getch();
//		}
//	}
}

void cPlayList::editSchedule()
{
	string name;
	int temp[100] = {}, count = 0;
	bool check = true;
re:;
	system("cls");
	if (!check) cin.clear(); cin.ignore(INT_MAX, '\n');
	cout << "편집할 일정의 이름을 입력하세요 >> ";
	getline(cin, name);
	if (!isRightSchedule(name)) {
		check = false;
		_getch();
		goto re;
	}
	for (size_t i = 0; i < sCount; i++) {
		if (list[i].getsName().compare(name) == 0) {
			temp[count++] = i;
		}
	}
re2:;
	if (!check) cin.clear(); cin.ignore(INT_MAX, '\n');

	if (count == 0) {		// 사용자 입력 이름의 일정이 없을 경우
		cout << ">> 해당하는 이름의 일정이 없습니다. 일정 편집을 종료합니다.\n";
		_getch();
		return;
	}
	else if (count == 1) {	// 사용자 입력 이름의 일정이 유일할 경우
		int sel;
		int t = temp[0];
		if (list[t].getsType() == 4) {	// 반복성 x
			cout << "일정의 편집할 내용을 선택하세요 1)이름 2)날짜 및 시각 3)카테고리 4) 반복기능 5)일정 완료 여부 >> ";
			cin >> sel;
			if (!cin) {
				cout << ">> 올바른 입력을 해주세요.\n";
				check = false;
				_getch();
				goto re2;
			}
			else if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4 || sel == 5)) {
				cout << ">> 1에서 5 사이의 값을 입력해주세요.\n";
				check = false;
				_getch();
				goto re2;
			}
			else {
				switch (sel) {
				case 1: {	// 이름 편집
					cout << "수정할 일정 이름을 입력해주세요 >> ";
					string name;
					cin.ignore(INT_MAX, '\n');
					getline(cin, name);
					if (!isRightSchedule(name)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsName(name);
					
					cout << "일정 이름이 " << list[t].getsName() << "으로 변경되었습니다.";					
					break;
				}
				case 2: {	// 날짜 및 시각 편집
					cout << "변경할 일정의 시작 날짜 및 시각을 입력해주세요 [ex) 2022 12 03 00 30] >> ";

					// $ NEW
					cin.ignore(INT_MAX, '\n');
					string sTime;
					getline(cin, sTime);
					if (!list[t].isRightTimeString(true, sTime)) {
						check = false;
						_getch();
						goto re2;
					}
					/*int year, month, day, hour, min;
					cin >> year >> month >> day >> hour >> min;
					if (!isRightSchedule(true, year, month, day, hour, min)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsTime(year, month, day, hour, min);*/

					cout << "변경할 일정의 마감 날짜 및 시각을 입력해주세요 [ex) 2023 02 03 00 30] >> ";

					string eTime;
					getline(cin, eTime);
					if (!list[t].isRightTimeString(false, eTime)) {
						check = false;
						_getch();
						goto re2;
					}
					/*cin >> year >> month >> day >> hour >> min;
					if (!isRightSchedule(false, year, month, day, hour, min)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].seteTime(year, month, day, hour, min);*/
					cout << "일정의 날짜 및 시각 편집이 완료되었습니다.\n";
					
					break;
				}
				case 3: {	// 카테고리 편집
					duplicate = false;
					cout << "<카테고리 편집>" << endl;
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << endl;
					while (1) {
						cout << "해당 일정의 변경하고 싶은 카테고리 번호를 입력해주세요.(모든 기호 사용 제외)>>";
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "잘못 입력하셨습니다.\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize) {
							cout << "범위 사이의 숫자만 입력해주세요 >>\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else {
							break;
						}
					}
					cout << list[t].getsCategory() << " -> " << category[categoryNum - 1];
					for (int i = 0; i < categorySize; i++) {
						if (list[t].getsCategory() == category[categoryNum - 1]) {
							duplicate = true;
							break;
						}
					}
					cout << endl;
					if (duplicate == false) {
						list[t].setsCategory(category[categoryNum - 1]);
						cout << "변경되었습니다.";
					}
					else {
						cout << "사전에 있는 카테고리 입니다.\n" << endl;
						duplicate = false;
					}
					_getch();
					break;
				}
				case 4: {	// 반복 기능
					int a;
					cout << "반복 타입을 선택해주세요. [1=연반복, 2=월반복, 3=주반복, 4=반복없음] >> ";
					cin >> a;
					if (cin.fail()) {
						cout << "올바른 입력을 해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(a == 1 || a == 2 || a == 3 || a == 4)) {
						cout << "1과 4 사이의 숫자만 입력해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						list[t].setsType(a);
						if (a == 4) {
							int year, month, day, hour, min;
						re3:;
							cout << "일정의 마감 시간을 입력해주세요 [ex) 2024 12 10 00 00] >> ";
							// $ NEW
							cin.ignore(INT_MAX, '\n');
							string eTime;
							getline(cin, eTime);
							if (!list[t].isRightTimeString(false, eTime)) {
								check = false;
								_getch();
								goto re3;
							}
							/*cin >> year >> month >> day >> hour >> min;
							if (!list[t].isRightSchedule(false, year, month, day, hour, min)) {
								check = false;
								_getch();
								goto re3;
							}*/
						}
					}
					list[t].setRepeat(list[t].getsType(), list[t]);
					
					cout << "일정의 반복 여부 편집이 완료되었습니다.";
					_getch();
					break;
				}
				case 5: {	// 일정 완료 여부
					cout << "일정 완료 여부를 입력해주세요 [0:false, 1:true] >> ";
					int s;
					cin >> s;
					if (cin.fail()) {
						cout << "올바른 입력을 다시 해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(s == 0 || s == 1)) {
						cout << "0 또는 1을 입력 해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						if (s == 1) {
							list[t].setIsDone(true);
							FileList[t][3] = "1";
							cout << "일정 완료 여부를 true로 변경합니다.\n";
						}
						else {
							list[t].setIsDone(false);
							FileList[t][3] = "0";
							cout << "일정 완료 여부를 false로 변경합니다.\n";
						}
						_getch();
					}
					break;
				}
				}
			}
		}
		else {	// 반복성 일정, type= 1 || 2 || 3
			cout << "일정의 편집할 내용을 선택하세요 1)이름 2)날짜 및 시각 3)카테고리 4)반복기능 >> ";
			cin >> sel;
			if (!cin) {
				cout << ">> 올바른 입력을 해주세요.\n";
				check = false;
				_getch();
				goto re2;
			}
			else if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4)) {
				cout << ">> 1에서 4 사이의 값을 입력해주세요.\n";
				check = false;
				_getch();
				goto re2;
			}
			else {
				switch (sel) {
				case 1: {	// 이름 편집
					cout << "수정할 일정 이름을 입력해주세요 >> ";
					string name;
					cin.ignore(INT_MAX, '\n');
					getline(cin, name);
					if (!isRightSchedule(name)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsName(name);
					
					cout << "일정 이름이 " << list[t].getsName() << "으로 변경되었습니다.";
					break;
				}
				case 2: {	// 날짜 및 시각 편집
					cout << "변경할 일정의 시작 날짜 및 시각을 입력해주세요 [ex) 2022 02 03 00 30] >> ";
					// $ NEW
					cin.ignore(INT_MAX, '\n');
					string sTime;
					getline(cin, sTime);
					if (!list[t].isRightTimeString(true, sTime)) {
						check = false;
						_getch();
						goto re2;
					}
					/*int year, month, day, hour, min;
					cin >> year >> month >> day >> hour >> min;
					if (!isRightSchedule(true, year, month, day, hour, min)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsTime(year, month, day, hour, min);*/
					cout << "일정의 날짜 및 시각 편집이 완료되었습니다.\n";
					_getch();
					break;
				}
				case 3: {	// 카테고리 편집
					duplicate = false;
					cout << "<카테고리 편집>" << endl;
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << endl;
					while (1) {
						cout << "해당 일정의 변경하고 싶은 카테고리 번호를 입력해주세요.(모든 기호 사용 제외)>>";
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "잘못 입력하셨습니다.\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize) {
							cout << "범위 사이의 숫자만 입력해주세요 >>\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else {
							break;
						}
					}
					cout << list[t].getsCategory() << " -> " << category[categoryNum - 1];
					for (int i = 0; i < categorySize; i++) {
						if (list[t].getsCategory() == category[categoryNum - 1]) {
							duplicate = true;
							break;
						}
					}
					cout << endl;
					if (duplicate == false) {
						list[t].setsCategory(category[categoryNum - 1]);
						cout << "변경되었습니다.";
					}
					else {
						cout << "사전에 있는 카테고리 입니다.\n" << endl;
						duplicate = false;
					}
					_getch();
					break;
				}
				case 4: {	// 반복여부
					int a;
					cout << "반복 타입을 선택해주세요. [1=연반복, 2=월반복, 3=주반복, 4=반복없음] >> ";
					cin >> a;
					if (cin.fail()) {
						cout << "올바른 입력을 해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(a == 1 || a == 2 || a == 3 || a == 4)) {
						cout << "1과 4 사이의 숫자만 입력해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						list[t].setsType(a);
						
						if (a == 4) {
							string eTime;
							//int year, month, day, hour, min;
						re4:;
							cout << "일정의 마감 날짜 및 시각을 입력해주세요 [ex) 2024 12 10 00 00] >> ";
							cin.ignore(INT_MAX, '\n');
							getline(cin, eTime);
							if (!list[t].isRightTimeString(false, eTime)) {
								check = false;
								_getch();
								goto re4;
							}
							/*cin >> year >> month >> day >> hour >> min;
							if (!list[t].isRightSchedule(false, year, month, day, hour, min)) {
								check = false;
								_getch();
								goto re4;
							}*/

							cout << "일정의 반복 여부 편집이 완료되었습니다.\n";
							_getch();
						}
					}
					list[t].setRepeat(list[t].getsType(), list[t]);
					
					break;
				}
				}
			}
		}
		for (size_t i = 0; i < sCount; i++) {
			this->FileList[i][0] = list[i].getsName();
			this->FileList[i][1] = list[i].getsCategory();
			this->FileList[i][2] = to_string(list[i].getsType());
			this->FileList[i][3] = to_string(list[i].getsIsDone());
			if (list[i].getsType() != 4) {
				this->FileList[i][4] = to_string(list[i].getsYear()) + " "
					+ to_string(list[i].getsMonth()) + " "
					+ to_string(list[i].getsDay()) + " "
					+ to_string(list[i].getsHour()) + " "
					+ to_string(list[i].getsMin());
				this->FileList[i][5] = "";
			}
			else {
				this->FileList[i][4] = to_string(list[i].getsYear()) + " "
					+ to_string(list[i].getsMonth()) + " "
					+ to_string(list[i].getsDay()) + " "
					+ to_string(list[i].getsHour()) + " "
					+ to_string(list[i].getsMin());
				this->FileList[i][5] = to_string(list[i].geteYear()) + " "
					+ to_string(list[i].geteMonth()) + " "
					+ to_string(list[i].geteDay()) + " "
					+ to_string(list[i].geteHour()) + " "
					+ to_string(list[i].geteMin());
			}
		}
	}
	else {					// 사용자 입력 이름의 일정이 여러 개인 경우
		int sel, t;
		for (size_t i = 0; i < count; i++) {
			cout << i + 1 << ") " << list[temp[i]].getsName()
				<< "\n - 시작 날짜 : " << list[temp[i]].getsYear() << "년 "
				<< list[temp[i]].getsMonth() << "월 "
				<< list[temp[i]].getsDay() << "일\n"
				<< " - 반복 타입 : ";
			if (list[temp[i]].getsType() == 1) {
				cout << "연반복, 매 년 " << list[temp[i]].getrAnnual().first
					<< "월 " << list[temp[i]].getrAnnual().second << "일\n";
			}
			else if (list[temp[i]].getsType() == 2) {
				cout << "월반복, 매 월 " << list[temp[i]].getrMonthly() << "일\n";
			}
			else if (list[temp[i]].getsType() == 3) {
				cout << "주반복, 매 " << list[temp[i]].getDayW(list[temp[i]].getrWeekly()) << "\n";
			}
			else if (list[temp[i]].getsType() == 4) {
				cout << " 없음\n - 마감 날짜 : " << list[temp[i]].geteYear() << "년 "
					<< list[temp[i]].geteMonth() << "월 "
					<< list[temp[i]].geteDay() << "일\n";
			}
		}
		cout << "편집할 일정의 번호를 입력해주세요 : ";
		cin >> sel;
		if (!cin) {
			cout << ">> 올바른 입력을 해주세요.\n";
			check = false;
			_getch();
			goto re2;
		}
		else if (sel<1 || sel>count) {
			cout << ">> 1에서 " << count << "사이의 값을 입력해주세요.\n";
			check = false;
			_getch();
			goto re2;
		}
		else {
		ree:;
			if (!check) cin.clear(); cin.ignore(INT_MAX, '\n');
			cout << "편집할 일정의 번호가 " << sel << "이 맞습니까? (y/n) >> ";
			char c;
			cin >> c;
			if (cin.fail()) {
				cout << "올바른 입력을 다시 해주세요.\n";
				check = false;
				_getch();
				goto ree;
			}
			if (c == 'y')
				t = sel - 1;
			else if (c == 'n') {
				cout << "일정 편집 메뉴로 돌아갑니다.\n";
				_getch();
				goto re2;
			}
			else {
				cout << "올바른 입력을 다시 해주세요.\n";
				check = false;
				_getch();
				goto ree;
			}
		}

		if (list[t].getsType() == 4) {	// 반복성 x
			cout << "일정의 편집할 내용을 선택하세요 1)이름 2)날짜 및 시각 3)카테고리 4) 반복기능 5)일정 완료 여부 >> ";
			cin >> sel;
			if (!cin) {
				cout << ">> 올바른 입력을 해주세요.\n";
				check = false;
				_getch();
				goto re2;
			}
			else if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4 || sel == 5)) {
				cout << ">> 1에서 5 사이의 값을 입력해주세요.\n";
				check = false;
				_getch();
				goto re2;
			}
			else {
				switch (sel) {
				case 1: {	// 이름 편집
					cout << "수정할 일정 이름을 입력해주세요 >> ";
					string name, back = list[t].getsName();
					cin.ignore(INT_MAX, '\n');
					getline(cin, name);
					if (!isRightSchedule(name)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsName(name);
					
					cout << "일정 이름이 " << back << "에서 " << list[t].getsName() << "으로 변경되었습니다.";
					_getch();
					break;
				}
				case 2: {	// 날짜 및 시각 편집
					cout << "변경할 일정의 시작 날짜 및 시각을 입력해주세요 [ex) 2022 12 20 00 30] >> ";
					// $ NEW
					cin.ignore(INT_MAX, '\n');
					string sTime, eTime;
					getline(cin, sTime);
					if (!list[t].isRightTimeString(true, sTime)) {
						check = false;
						_getch();
						goto re2;
					}
					cout << "변경할 일정의 마감 날짜 및 시각을 입력해주세요 [ex) 2023 02 20 03 30] >> ";
					getline(cin, eTime);
					if (!list[t].isRightTimeString(false, eTime)) {
						check = false;
						_getch();
						goto re2;
					}
					/*int year, month, day, hour, min;
					cin >> year >> month >> day >> hour >> min;
					if (!isRightSchedule(true, year, month, day, hour, min)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsTime(year, month, day, hour, min);
					cout << "변경할 일정의 마감 날짜 및 시각을 입력해주세요 [ex) 2022 02 03 00 30] >> ";
					cin >> year >> month >> day >> hour >> min;
					if (!isRightSchedule(false, year, month, day, hour, min)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].seteTime(year, month, day, hour, min);*/
					cout << "일정의 날짜 및 시각 편집을 완료했습니다.\n";
					_getch();
					break;
				}
				case 3: {	// 카테고리 편집
					duplicate = false;
					cout << "<카테고리 편집>" << endl;
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << endl;
					while (1) {
						cout << "해당 일정의 변경하고 싶은 카테고리 번호를 입력해주세요.(모든 기호 사용 제외)>>";
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "잘못 입력하셨습니다.\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize) {
							cout << "범위 사이의 숫자만 입력해주세요 >>\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else {
							break;
						}
					}
					cout << list[t].getsCategory() << " -> " << category[categoryNum - 1];
					for (int i = 0; i < categorySize; i++) {
						if (list[t].getsCategory() == category[categoryNum - 1]) {
							duplicate = true;
							break;
						}
					}
					cout << endl;
					if (duplicate == false) {
						list[t].setsCategory(category[categoryNum - 1]);
						cout << "변경되었습니다.";
					}
					else {
						cout << "사전에 있는 카테고리 입니다.\n" << endl;
						duplicate = false;
					}
					_getch();
					break;
				}
				case 4: {	// 반복 기능
					int a;
					cout << "반복 타입을 선택해주세요. [1=연반복, 2=월반복, 3=주반복, 4=반복없음] >> ";
					cin >> a;
					if (cin.fail()) {
						cout << "올바른 입력을 해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(a == 1 || a == 2 || a == 3 || a == 4)) {
						cout << "1과 4 사이의 숫자만 입력해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						list[t].setsType(a);
						if (a == 4) {
							int year, month, day, hour, min;
						re5:;
							cout << "일정의 마감 날짜 및 시각을 입력해주세요 [ex) 2024 12 10 00 00] >> ";
							// $ NEW
							cin.ignore(INT_MAX, '\n');
							string eTime;
							getline(cin, eTime);
							if (!list[t].isRightTimeString(false, eTime)) {
								check = false;
								_getch();
								goto re5;
							}
							/*cin >> year >> month >> day >> hour >> min;
							if (!list[t].isRightSchedule(false, year, month, day, hour, min)) {
								check = false;
								_getch();
								goto re5;
							}*/
						}
					}
					list[t].setRepeat(list[t].getsType(), list[t]);
				
					cout << "일정의 반복 타입 편집을 완료했습니다.\n";
					_getch();
					break;
				}
				case 5: {	// 일정 완료 여부
					cout << "일정 완료 여부를 입력해주세요 [0:false, 1:true] >> ";
					int s;
					cin >> s;
					if (cin.fail()) {
						cout << "올바른 입력을 다시 해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(s == 0 || s == 1)) {
						cout << "0 또는 1을 입력 해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						if (s == 1) {
							list[t].setIsDone(true);

							cout << "일정 완료 여부를 true로 변경합니다.\n";
							_getch();
						}
						else {
							list[t].setIsDone(false);

							cout << "일정 완료 여부를 false로 변경합니다.\n";
							_getch();
						}
					}
					break;
				}
				}
			}
		}
		else {	// 반복성 일정, type= 1 || 2 || 3
			cout << "일정의 편집할 내용을 선택하세요 1)이름 2)날짜 및 시각 3)카테고리 4)반복기능 >> ";
			cin >> sel;
			if (!cin) {
				cout << ">> 올바른 입력을 해주세요.\n";
				check = false;
				_getch();
				goto re2;
			}
			else if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4)) {
				cout << ">> 1에서 4 사이의 값을 입력해주세요.\n";
				check = false;
				_getch();
				goto re2;
			}
			else {
				switch (sel) {
				case 1: {	// 이름 편집
					cout << "수정할 일정 이름을 입력해주세요 >> ";
					string name, n = list[t].getsName();
					cin.ignore(INT_MAX, '\n');
					getline(cin, name);
					if (!isRightSchedule(name)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsName(name);

					cout << "일정 이름이 " << n << "에서 " << list[t].getsName() << "으로 변경되었습니다.";
					_getch();
					break;
				}
				case 2: {	// 날짜 및 시각 편집
					cout << "변경할 일정의 시작 날짜 및 시각을 입력해주세요 [ex) 2022 12 20 00 30] >> ";
					// $ NEW
					cin.ignore(INT_MAX, '\n');
					string sTime;
					getline(cin, sTime);
					if (!list[t].isRightTimeString(true, sTime)) {
						check = false;
						_getch();
						goto re2;
					}
					/*int year, month, day, hour, min;
					cin >> year >> month >> day >> hour >> min;
					if (!isRightSchedule(true, year, month, day, hour, min)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsTime(year, month, day, hour, min);*/
					cout << "일정의 날짜 및 시각 편집을 완료했습니다.\n";
					_getch();
					break;
				}
				case 3: {	// 카테고리 편집
					duplicate = false;
					cout << "<카테고리 편집>" << endl;
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << endl;
					while (1) {
						cout << "해당 일정의 변경하고 싶은 카테고리 번호를 입력해주세요.(모든 기호 사용 제외)>>";
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "잘못 입력하셨습니다.\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize) {
							cout << "범위 사이의 숫자만 입력해주세요 >>\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else {
							break;
						}
					}
					cout << list[t].getsCategory() << " -> " << category[categoryNum - 1];
					for (int i = 0; i < categorySize; i++) {
						if (list[t].getsCategory() == category[categoryNum - 1]) {
							duplicate = true;
							break;
						}
					}
					cout << endl;
					if (duplicate == false) {
						list[t].setsCategory(category[categoryNum - 1]);
						cout << "변경되었습니다.";
					}
					else {
						cout << "사전에 있는 카테고리 입니다.\n" << endl;
						duplicate = false;
					}
					_getch();
					break;
				}
				case 4: {	// 반복여부
					int a;
					cout << "반복 타입을 선택해주세요. [1=연반복, 2=월반복, 3=주반복, 4=반복없음] >> ";
					cin >> a;
					if (cin.fail()) {
						cout << "올바른 입력을 해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(a == 1 || a == 2 || a == 3 || a == 4)) {
						cout << "1과 4 사이의 숫자만 입력해주세요.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						list[t].setsType(a);
						if (a == 4) {
							int year, month, day, hour, min;
						re6:;
							cout << "일정의 마감 시간을 입력해주세요 [ex) 2024 12 10 00 00] >> ";
							// $ NEW
							cin.ignore(INT_MAX, '\n');
							string eTime;
							getline(cin, eTime);
							if (!list[t].isRightTimeString(false, eTime)) {
								check = false;
								_getch();
								goto re6;
							}
							/*cin >> year >> month >> day >> hour >> min;
							if (!list[t].isRightSchedule(false, year, month, day, hour, min)) {
								check = false;
								_getch();
								goto re6;
							}*/
						}
					}
					list[t].setRepeat(list[t].getsType(), list[t]);
					cout << "일정의 반복 여부 편집을 완료했습니다.\n";

					for (size_t i = 0; i < sCount; i++) {
						this->FileList[i][0] = list[i].getsName();
						this->FileList[i][1] = list[i].getsCategory();
						this->FileList[i][2] = list[i].getsType();
						this->FileList[i][3] = list[i].getsIsDone();
						if (list[i].getsType() != 4) {
							this->FileList[i][4] = to_string(list[i].getsYear()) + " "
								+ to_string(list[i].getsMonth()) + " "
								+ to_string(list[i].getsDay()) + " "
								+ to_string(list[i].getsHour()) + " "
								+ to_string(list[i].getsMin());
							this->FileList[i][5] = "";
						}
						else {
							this->FileList[i][4] = to_string(list[i].getsYear()) + " "
								+ to_string(list[i].getsMonth()) + " "
								+ to_string(list[i].getsDay()) + " "
								+ to_string(list[i].getsHour()) + " "
								+ to_string(list[i].getsMin());
							this->FileList[i][5] = to_string(list[i].geteYear()) + " "
								+ to_string(list[i].geteMonth()) + " "
								+ to_string(list[i].geteDay()) + " "
								+ to_string(list[i].geteHour()) + " "
								+ to_string(list[i].geteMin());
						}
					}

					_getch();
					break;
				}
				}
			}
		}
	}
	for (size_t i = 0; i < sCount; i++) {
		this->FileList[i][0] = list[i].getsName();
		this->FileList[i][1] = list[i].getsCategory();
		this->FileList[i][2] = to_string(list[i].getsType());
		this->FileList[i][3] = to_string(list[i].getsIsDone());
		if (list[i].getsType() != 4) {
			this->FileList[i][4] = to_string(list[i].getsYear()) + " "
				+ to_string(list[i].getsMonth()) + " "
				+ to_string(list[i].getsDay()) + " "
				+ to_string(list[i].getsHour()) + " "
				+ to_string(list[i].getsMin());
			this->FileList[i][5] = "";
		}
		else {
			this->FileList[i][4] = to_string(list[i].getsYear()) + " "
				+ to_string(list[i].getsMonth()) + " "
				+ to_string(list[i].getsDay()) + " "
				+ to_string(list[i].getsHour()) + " "
				+ to_string(list[i].getsMin());
			this->FileList[i][5] = to_string(list[i].geteYear()) + " "
				+ to_string(list[i].geteMonth()) + " "
				+ to_string(list[i].geteDay()) + " "
				+ to_string(list[i].geteHour()) + " "
				+ to_string(list[i].geteMin());
		}
	}
}

int  completePercent(string FileList[100][6], int row_size);
void cPlayList::checkSchedule()
{
	system("cls");
	int year, month;
	bool check = true;
re:;
	if (!check) cin.clear(); cin.ignore(INT_MAX, '\n');
	cout << "확인하실 일정의 연도와 월을 입력해주세요 [ex) 2022 12] >> ";
	cin >> year >> month;
	if (!isRightSchedule(year, month)) {
		check = false;
		_getch();
		goto re;
	}
	cout << "====================================\n"
		<< '\t' << year << "년 " << month << "월 일정\n"
		<< "====================================\n";
	int count = 1;

	bool isLeaf;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		isLeaf = true;
	else
		isLeaf = false;
	int m[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	m[1] = isLeaf ? 29 : 28;

	// 여기서부터 반복성 / 반복x 나눠서 생각해서 다시 코드 짜보자.
	// sType을 기준으로 해야할 듯, getDayOfWeek 함수 다시 건드려야함
	for (size_t i = 0; i < sCount; i++) {
		int type = list[i].getsType();
		switch (type) {
		case 1: {	// 연 반복
			if (list[i].getsYear() <= year) {
				if (list[i].getsMonth() == month) {
					cout << " [" << count++ << "] " << list[i].getsName() << "\n";
					cout << "  - 카테고리 : " << list[i].getsCategory() << endl;
					cout << "  - 날짜 : " << year << "년 " << month << "월 ";
					if (list[i].getrAnnual().second > m[month - 1]) {
						cout << m[month - 1] << "일\n";
					}
					else {
						cout << list[i].getrAnnual().second << "일\n";
					}
					cout << "  - 매 년 " << month << "월 " << list[i].getrAnnual().second << "일 반복 일정\n";
				}
			}
			break;
		}
		case 2: {	// 월 반복
			if (list[i].getsYear() == year) {
				if (list[i].getsMonth() <= month) {
					cout << " [" << count++ << "] " << list[i].getsName() << "\n";
					cout << "  - 카테고리 : " << list[i].getsCategory() << endl;
					cout << "  - 날짜 : " << year << "년 " << month << "월 ";
					if (list[i].getrMonthly() > m[month - 1]) {
						cout << m[month - 1] << "일\n";
					}
					else {
						cout << list[i].getrMonthly() << "일\n";
					}
					cout << "  - 매 월 " << list[i].getrMonthly() << "일 반복 일정\n";
				}
			}
			else if (list[i].getsYear() < year) {
				cout << " [" << count++ << "] " << list[i].getsName() << "\n";
				cout << "  - 카테고리 : " << list[i].getsCategory() << endl;
				cout << "  - 날짜 : " << year << "년 " << month << "월 ";
				if (list[i].getrMonthly() > m[month - 1]) {
					cout << m[month - 1] << "일\n";
				}
				else {
					cout << list[i].getrMonthly() << "일\n";
				}
				cout << "  - 매 월 " << list[i].getrMonthly() << "일 반복 일정\n";
			}
			break;
		}
		case 3: {	// 주 반복
			if (list[i].getsYear() == year) {
				if (list[i].getsMonth() <= month) {
					cout << " [" << count++ << "] " << list[i].getsName() << "\n";
					cout << "  - 카테고리 : " << list[i].getsCategory() << endl;
					cout << "  - 날짜 : " << year << "년 " << month << "월";
					for (size_t j = 1; j <= m[month - 1]; j++) {
						if (getDayOfWeek(year, month, j) == list[i].getrWeekly()) {
							cout << " " << j;
						}
					}
					cout << "일\n  - 매 주 " << getDayW(list[i].getrWeekly()) << " 반복 일정\n";
				}
			}
			else if (list[i].getsYear() < year) {
				cout << " [" << count++ << "] " << list[i].getsName() << "\n";
				cout << "  - 카테고리 : " << list[i].getsCategory() << endl;
				cout << "  - 날짜 : " << year << "년 " << month << "월";
				for (size_t j = 1; j <= m[month - 1]; j++) {
					if (getDayOfWeek(year, month, j) == list[i].getrWeekly()) {
						cout << " " << j;
					}
				}
				cout << "일\n  - 매 주 " << getDayW(list[i].getrWeekly()) << " 반복 일정\n";
			}
			break;
		}
		case 4: {	// 반복x, 마감일정 포함
			int sy = list[i].getsYear();	// 시작 연도
			int sm = list[i].getsMonth();	// 시작 월
			int ey = list[i].geteYear();	// 마감 연도
			int em = list[i].geteMonth();	// 마감 월
			if (sy <= year && ey >= year) {
				if (sy == year) {
					if (sm <= month) {
						cout << " [" << count++ << "] " << list[i].getsName() << "\n";
						cout << "  - 카테고리 : " << list[i].getsCategory() << endl;
						cout << "  - 시작 날짜 : " << sy << "년 " << sm << "월" << list[i].getsDay() << "일\n";
						cout << "  - 마감 날짜 : " << ey << "년 " << em << "월" << list[i].geteDay() << "일\n";
					}
				}
				else if (ey == year) {
					if (em >= month) {
						cout << " [" << count++ << "] " << list[i].getsName() << "\n";
						cout << "  - 카테고리 : " << list[i].getsCategory() << endl;
						cout << "  - 시작 날짜 : " << sy << "년 " << sm << "월" << list[i].getsDay() << "일\n";
						cout << "  - 마감 날짜 : " << ey << "년 " << em << "월" << list[i].geteDay() << "일\n";
					}
				}
				else {
					cout << " [" << count++ << "] " << list[i].getsName() << "\n";
					cout << "  - 카테고리 : " << list[i].getsCategory() << endl;
					cout << "  - 시작 날짜 : " << sy << "년 " << sm << "월" << list[i].getsDay() << "일\n";
					cout << "  - 마감 날짜 : " << ey << "년 " << em << "월" << list[i].geteDay() << "일\n";
				}
			}
			break;
		}
		}
	}
	if (count == 1)
		cout << " - 해당 연월에 일정이 없습니다.\n";
	_getch();
}

bool cPlayList::readData(string filename)
{


	return false;
}

bool cPlayList::saveData(string filename)
{
	return false;
}

void cPlayList::mCategory() {
	manageCategory(category, categorySize,FileList,size_row);
}

bool cPlayList::makeCategory()
{
	string fileName = "categoryData.txt";
	ifstream fin(fileName);

	// @ 파일 열기 실패 시 예외처리
	if (!fin.is_open()) {
		cerr << "[Error] categoryData.txt 파일을 열 수 없습니다. 경로를 확인해주세요.\n";
		_getch();
		return false;
	}

	fin >> this->categoryNum;
	this->categoryData = new string[this->categoryNum];

	for (size_t i = 0; i < this->categoryNum; i++)
		fin >> this->categoryData[i];

	return true;
}

void cPlayList::getSetting()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	srand((unsigned)time(NULL));
	// @ 이후 color 설정 등등 필요한 초기 설정
}


void cPlayList::playList()
{
	int sel = 0;
	int user = 0;
	bool none = false;
	string q = "";
	load_Listfile(FileList, size_row);
	load_Categoryfile(category, categorySize);
	while (sel != 6) {
		sel = showMenu();
		srand((unsigned)time(NULL));
		
		switch (sel) {
		case 1: {
			addSchedule();
			break;
		}
		case 2: {
			removeSchedule();
			break;
		}
		case 3: {
			printf("3. 일정확인\n");
			while (1) {
				cout << "1) 시간별 정렬 2) 카테고리별 정렬 3) 일정 실행 척도 계산"<< endl;
				cout << "\n 메뉴 번호를 입력해주세요 >>";
				cin >> user;
				if (!user) {
					cout << "숫자만 입력하세요 >>";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				else if (user < 1 || user >3) {
					cout << "1~4 사이의 숫자만 입력해주세요 >>";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				else if (user == 1)
				{
					checkSchedule();
					break;
				}
				else if(user==2){
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << categorySize + 1 << ". X";
					cout << endl;
					cout << "정렬하고 싶은 카테고리 번호를 입력해주세요(모든 기호 사용 제외)>>";
					while (1) {
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "숫자만 입력하세요 >>\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize+1) {
							cout << "범위 사이의 숫자만 입력해주세요 >>\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum == categorySize+1) {
							for (int i = 0; i < size_row; i++) {
								if (FileList[i][1] == "X") {
									string s = "";
									int j;
									s = "";
									if (FileList[i][2] != "4") { // 1,2,3
										for (j = 0; j < 4; j++)
										{
											s += FileList[i][j] + "/";
										}
									}
									else { // 4
										for (j = 0; j < 5; j++)
										{
											s += FileList[i][j] + "/";
										}
									}
									s += FileList[i][j];// / 마지막 사용 안하려고
									cout << s << endl;
									none = true;
								}
							}
							break;
						}
						else {
							for (int i = 0; i < size_row; i++) {
								if (FileList[i][1] == category[categoryNum - 1]) {
									string s = "";
									int j;
									s = "";
									if (FileList[i][2] != "4") { // 1,2,3
										for (j = 0; j < 4; j++)
										{
											s += FileList[i][j] + "/";
										}
									}
									else { // 4
										for (j = 0; j < 5; j++)
										{
											s += FileList[i][j] + "/";
										}
									}
									s += FileList[i][j];// / 마지막 사용 안하려고
									cout << s << endl;
									none = true;
								}
							}
							break;
						}
					}
					if (none == false) {
						cout << "\n해당 카테고리의 일정이 없습니다." << endl;
					}
					break;
				}
				else {
					int result = completePercent(FileList, size_row);
						cout << "당신의 일정 실행 척도는 " << result << "% 입니다." << endl;
					break;
				}
			}
			_getch();
			break;
		}
		case 4: {
			printf("4. 일정편집");
			editSchedule();
			break;
		}
		case 5: {
			mCategory();
			break;
		}
		case 6: {
			printf("6. 종료");
			create_Listfile(FileList, size_row);
			create_Categoryfile(category, categorySize);
			break;
		}
		}
	}
}

int  completePercent(string FileList[100][6],int row_size) {
	float cnt=0;
	for (int i = 0; i < row_size; i++) {
		if (FileList[i][3] == "1") {
			cnt++;
		}
	}
	return (int)(cnt / row_size * 100);
}
// 파일 입력 함수
void create_Listfile(string FileList[100][6], int size_row)
{
	ofstream writeFileList;
	writeFileList.open("KU_do_list.txt", ios::out | ios::trunc); // 파일 열고 열 때 초기화
	if (writeFileList.fail()) // 일정 파일 열기 실패
	{
		std::cout << "KU_do_list.txt 파일을 열 수 없습니다." << endl;
	}
	writeFileList << size_row;
	writeFileList << '\n';
	string s = "";
	int j;
	for (int i = 0; i < size_row; i++)
	{
		s = "";

		if (FileList[i][2] != "4") { // 3
			for (j = 0; j < 4; j++)
			{
				s += FileList[i][j] + "/";
			}
		}
		else { // 4
			for (j = 0; j < 5; j++)
			{
				s += FileList[i][j] + "/";
			}
		}
		s += FileList[i][j];// / 마지막 사용 안하려고
		writeFileList << s;
		writeFileList << '\n';
	}

	writeFileList.close();
}

// 카테고리 입력 함수
void create_Categoryfile(string *category, int categorySize)
{
	ofstream writeCategoryList;
	writeCategoryList.open("KU_do_list_category.txt", ios::out | ios::trunc); // 파일 열고 열 때 초기화
	if (writeCategoryList.fail()) // 일정 파일 열기 실패
	{
		std::cout << "KU_do_list_category.txt 파일을 열 수 없습니다." << endl;
	}
	writeCategoryList << categorySize;
	writeCategoryList << '\n';
	string s = "";
	int j;
	for (int i = 0; i < categorySize; i++)
	{
		s = category[i];
		writeCategoryList << s;
		writeCategoryList << '\n';
	}

	writeCategoryList.close();
}

// 파일에서 불러오기
void cPlayList::load_Listfile(string FileList[100][6],int& size_row)
{
	string name; // 이름
	string category; //카테고리
	string iterative; //반복성 여부 0 or 1
	string stime; // 시작 시간
	string etime; // 종료 시간
	string complete; // 완료 여부 0 or 1
	int ai = 0;
	string size;
	ifstream readFileList;

	readFileList.open("KU_do_list.txt"); // 일정 파일 열기
	if (!readFileList) // 일정 파일 열기 실패
	{
		cerr << "KU_do_list.txt 파일을 열 수 없습니다." << endl;
		exit(1);
	}

	if (readFileList.is_open())
	{
		getline(readFileList, size, '\n');
		if (size == "")
		{
			size = "0";
		}
		else
		{
			size_row = stoi(size);

		}
		
		sCount = size_row;
		while (ai < size_row) // 일정 파일 끝까지 읽었는지 확인
		{
			//if (readFileList.eof())
				//break;
			getline(readFileList, name, '/');
			FileList[ai][0] = name;
			list[ai].setsName(name);
			std::cout << name << " " << FileList[ai][0] << endl;
			getline(readFileList, category, '/');
			FileList[ai][1] = category;
			list[ai].setsCategory(category);
			//std::cout << category << " " << all[ai][1] << endl;
			getline(readFileList, iterative, '/');
			FileList[ai][2] = iterative;
			//list[ai].setsRepeat(iterative);
			list[ai].setsType(stoi(iterative));
			//std::cout << iterative << " " << all[ai][2] << endl;
			if (iterative != "4")  // 종료날짜 없음
			{
				getline(readFileList, complete, '/');
				FileList[ai][3] = complete;
				bool a = stoi(complete) ? true : false;
				list[ai].setIsDone(a);
				//std::cout << complete << " " << all[ai][3] << endl;
				getline(readFileList, stime, '\n');
				FileList[ai][4] = stime;
				list[ai].transTimeToInt(true, stime);
				//std::cout << stime << " " << all[ai][4] << endl;
			}
			else // 종료날짜 있음
			{
				getline(readFileList, complete, '/');
				FileList[ai][3] = complete;
				bool a = stoi(complete) ? true : false;
				list[ai].setIsDone(a);
				//std::cout << complete << " " << all[ai][3] << endl;
				getline(readFileList, stime, '/');
				FileList[ai][4] = stime;
				list[ai].transTimeToInt(true, stime);
				//std::cout << stime << " " << all[ai][4] << endl;
				getline(readFileList, etime, '\n');
				FileList[ai][5] = etime;
				list[ai].transTimeToInt(false, etime);
				//std::cout << etime << " " << all[ai][5] << endl;

			}
			//if (readFileList.eof())
				//break;
			ai++;

		}
	}
	readFileList.close(); // 일정 파일 닫기
	this->sCount = ai;
}

// 카테고리 파일에서 불러오기
void load_Categoryfile(string *category, int& categorySize)
{
	
	ifstream readCategoryList;
	string size;
	int ai = 0;
	string cat;
	readCategoryList.open("KU_do_list_category.txt"); // 카테고리 파일 열기
	if (!readCategoryList) // 카테고리 파일 열기 실패
	{
		cerr << "KU_do_list_category.txt 파일을 열 수 없습니다." << endl;
		exit(1);
	}

	if (readCategoryList.is_open())
	{
		getline(readCategoryList, size, '\n');
		if (size == "")
		{
			size = "0";
		}
		else
		{
			categorySize = stoi(size);
		}
		
		while (ai < categorySize)
		{
			getline(readCategoryList, cat, '\n');
			category[ai] = cat;
			ai++;
		}
	}
	readCategoryList.close(); // 카테고리 파일 닫기
}


int cPlayList::showMenu()
{
	int sel;
re:;
	system("cls");
	cout << "1) 일정 추가  2) 일정 삭제  3) 일정 확인  4) 일정 편집  5) 카테고리 관리  6) 종료\n"
		<< "\n메뉴 번호를 입력해주세요 >> ";
	cin >> sel;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << ">> 올바른 입력 값을 다시 입력하세요.\n";
		_getch();
		goto re;
	}
	else if (sel < 1 || sel > 6) {
		cout << ">> 1에서 6 사이의 값을 입력해주세요.\n";
		_getch();
		goto re;
	}

	return sel;
}

void cPlayList::isRightexit(string _name) {
	v.clear();
	vector<int>().swap(v);

	for (int i = 0; i <= 100; i++) {
		if (_name.compare(list[i].getsName()) == 0) {
			v.push_back(i);
		}
	}
}

void cPlayList::isRightexit_over1() { //2개 이상 일정 처리
	string name;
	int ch;

re_edit2:;
	system("cls");

	cin.clear(); cin.ignore(INT_MAX, '\n');

	for (int i = 0; i < v.size(); i++) {
		int index;
		index = v.at(i);
		cout << "일정 번호:" << index << "일정이름: " << list[index].getsName() << " 날짜 및 시각: " << list[index].getsYear() << list[index].getsMonth() << list[index].getsDay() << list[index].getsHour() << list[index].getsMin() << "\n" << endl;
	}

	cout << "편집할 일정의 이름이 중복됩니다." << "\n" << "출력된 일정 중, 해당하는 일정의 일정 번호를 입력해주세요! >> ";
	cin >> ch;
	if (cin.fail()) {
		cout << ">> 존재하지 않는 인덱스 입니다. 다시 입력해주세요.\n";
		//check = false;
		_getch();
		goto re_edit2;
	}

	for (int i = 0; i < v.size(); i++) {

		//std::string str = std::to_string(v.at(i));

		/*if(name.compare(str)==0){
		   v.push_back(stoi(name));
		}*/
		if (ch == v.at(i)) {
			v.push_back(ch);
		}
		else {
			cout << ">> 존재하지 않는 인덱스 입니다. 다시 입력해주세요.\n";
			//check = false;
			_getch();
			goto re_edit2;
		}
	}
}