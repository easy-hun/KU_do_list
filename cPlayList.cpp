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
	// �޸� ��ȯ :: ����
	if (this->list != nullptr) {
		delete[] this->list;
		this->list = nullptr;
	}

	// �޸� ��ȯ :: ī�װ�
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
		cout << ">> ������ �� �̻� �߰��� �� �����ϴ�.\n";
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
//	cout << "������ ������ �̸��� �Է��ϼ��� >> ";
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
//		cout << "�ش��ϴ� �̸��� ������ �����ϴ�.\n";
//		_getch();
//		return;
//	}
//	else if (count) {
//	re3:;
//		char c;
//		cout << "�ش� ������ �����Ͻðڽ��ϱ�? (y/n) >> ";
//		cin >> c;
//		if (cin.fail()) {
//			cout << "�ùٸ� �Է��� �ٽ� ���ּ���.\n";
//			check = false;
//			_getch();
//			goto re3;
//		}
//		else if (c == 'n') {
//			cout << "���� �޴��� �ٽ� ���ư��ϴ�.\n";
//			_getch();
//			return;
//		}
//		else if (c == 'y') {
//			for (size_t i = temp[0]; i < sCount-1; i++) {
//				
//			}
//			cout << "������ �����մϴ�.\n";
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
	cout << "������ ������ �̸��� �Է��ϼ��� >> ";
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

	if (count == 0) {		// ����� �Է� �̸��� ������ ���� ���
		cout << ">> �ش��ϴ� �̸��� ������ �����ϴ�. ���� ������ �����մϴ�.\n";
		_getch();
		return;
	}
	else if (count == 1) {	// ����� �Է� �̸��� ������ ������ ���
		int sel;
		int t = temp[0];
		if (list[t].getsType() == 4) {	// �ݺ��� x
			cout << "������ ������ ������ �����ϼ��� 1)�̸� 2)��¥ �� �ð� 3)ī�װ� 4) �ݺ���� 5)���� �Ϸ� ���� >> ";
			cin >> sel;
			if (!cin) {
				cout << ">> �ùٸ� �Է��� ���ּ���.\n";
				check = false;
				_getch();
				goto re2;
			}
			else if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4 || sel == 5)) {
				cout << ">> 1���� 5 ������ ���� �Է����ּ���.\n";
				check = false;
				_getch();
				goto re2;
			}
			else {
				switch (sel) {
				case 1: {	// �̸� ����
					cout << "������ ���� �̸��� �Է����ּ��� >> ";
					string name;
					cin.ignore(INT_MAX, '\n');
					getline(cin, name);
					if (!isRightSchedule(name)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsName(name);
					
					cout << "���� �̸��� " << list[t].getsName() << "���� ����Ǿ����ϴ�.";					
					break;
				}
				case 2: {	// ��¥ �� �ð� ����
					cout << "������ ������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2022 12 03 00 30] >> ";

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

					cout << "������ ������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2023 02 03 00 30] >> ";

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
					cout << "������ ��¥ �� �ð� ������ �Ϸ�Ǿ����ϴ�.\n";
					
					break;
				}
				case 3: {	// ī�װ� ����
					duplicate = false;
					cout << "<ī�װ� ����>" << endl;
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << endl;
					while (1) {
						cout << "�ش� ������ �����ϰ� ���� ī�װ� ��ȣ�� �Է����ּ���.(��� ��ȣ ��� ����)>>";
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "�߸� �Է��ϼ̽��ϴ�.\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize) {
							cout << "���� ������ ���ڸ� �Է����ּ��� >>\n";
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
						cout << "����Ǿ����ϴ�.";
					}
					else {
						cout << "������ �ִ� ī�װ� �Դϴ�.\n" << endl;
						duplicate = false;
					}
					_getch();
					break;
				}
				case 4: {	// �ݺ� ���
					int a;
					cout << "�ݺ� Ÿ���� �������ּ���. [1=���ݺ�, 2=���ݺ�, 3=�ֹݺ�, 4=�ݺ�����] >> ";
					cin >> a;
					if (cin.fail()) {
						cout << "�ùٸ� �Է��� ���ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(a == 1 || a == 2 || a == 3 || a == 4)) {
						cout << "1�� 4 ������ ���ڸ� �Է����ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						list[t].setsType(a);
						if (a == 4) {
							int year, month, day, hour, min;
						re3:;
							cout << "������ ���� �ð��� �Է����ּ��� [ex) 2024 12 10 00 00] >> ";
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
					
					cout << "������ �ݺ� ���� ������ �Ϸ�Ǿ����ϴ�.";
					_getch();
					break;
				}
				case 5: {	// ���� �Ϸ� ����
					cout << "���� �Ϸ� ���θ� �Է����ּ��� [0:false, 1:true] >> ";
					int s;
					cin >> s;
					if (cin.fail()) {
						cout << "�ùٸ� �Է��� �ٽ� ���ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(s == 0 || s == 1)) {
						cout << "0 �Ǵ� 1�� �Է� ���ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						if (s == 1) {
							list[t].setIsDone(true);
							FileList[t][3] = "1";
							cout << "���� �Ϸ� ���θ� true�� �����մϴ�.\n";
						}
						else {
							list[t].setIsDone(false);
							FileList[t][3] = "0";
							cout << "���� �Ϸ� ���θ� false�� �����մϴ�.\n";
						}
						_getch();
					}
					break;
				}
				}
			}
		}
		else {	// �ݺ��� ����, type= 1 || 2 || 3
			cout << "������ ������ ������ �����ϼ��� 1)�̸� 2)��¥ �� �ð� 3)ī�װ� 4)�ݺ���� >> ";
			cin >> sel;
			if (!cin) {
				cout << ">> �ùٸ� �Է��� ���ּ���.\n";
				check = false;
				_getch();
				goto re2;
			}
			else if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4)) {
				cout << ">> 1���� 4 ������ ���� �Է����ּ���.\n";
				check = false;
				_getch();
				goto re2;
			}
			else {
				switch (sel) {
				case 1: {	// �̸� ����
					cout << "������ ���� �̸��� �Է����ּ��� >> ";
					string name;
					cin.ignore(INT_MAX, '\n');
					getline(cin, name);
					if (!isRightSchedule(name)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsName(name);
					
					cout << "���� �̸��� " << list[t].getsName() << "���� ����Ǿ����ϴ�.";
					break;
				}
				case 2: {	// ��¥ �� �ð� ����
					cout << "������ ������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2022 02 03 00 30] >> ";
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
					cout << "������ ��¥ �� �ð� ������ �Ϸ�Ǿ����ϴ�.\n";
					_getch();
					break;
				}
				case 3: {	// ī�װ� ����
					duplicate = false;
					cout << "<ī�װ� ����>" << endl;
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << endl;
					while (1) {
						cout << "�ش� ������ �����ϰ� ���� ī�װ� ��ȣ�� �Է����ּ���.(��� ��ȣ ��� ����)>>";
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "�߸� �Է��ϼ̽��ϴ�.\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize) {
							cout << "���� ������ ���ڸ� �Է����ּ��� >>\n";
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
						cout << "����Ǿ����ϴ�.";
					}
					else {
						cout << "������ �ִ� ī�װ� �Դϴ�.\n" << endl;
						duplicate = false;
					}
					_getch();
					break;
				}
				case 4: {	// �ݺ�����
					int a;
					cout << "�ݺ� Ÿ���� �������ּ���. [1=���ݺ�, 2=���ݺ�, 3=�ֹݺ�, 4=�ݺ�����] >> ";
					cin >> a;
					if (cin.fail()) {
						cout << "�ùٸ� �Է��� ���ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(a == 1 || a == 2 || a == 3 || a == 4)) {
						cout << "1�� 4 ������ ���ڸ� �Է����ּ���.\n";
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
							cout << "������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2024 12 10 00 00] >> ";
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

							cout << "������ �ݺ� ���� ������ �Ϸ�Ǿ����ϴ�.\n";
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
	else {					// ����� �Է� �̸��� ������ ���� ���� ���
		int sel, t;
		for (size_t i = 0; i < count; i++) {
			cout << i + 1 << ") " << list[temp[i]].getsName()
				<< "\n - ���� ��¥ : " << list[temp[i]].getsYear() << "�� "
				<< list[temp[i]].getsMonth() << "�� "
				<< list[temp[i]].getsDay() << "��\n"
				<< " - �ݺ� Ÿ�� : ";
			if (list[temp[i]].getsType() == 1) {
				cout << "���ݺ�, �� �� " << list[temp[i]].getrAnnual().first
					<< "�� " << list[temp[i]].getrAnnual().second << "��\n";
			}
			else if (list[temp[i]].getsType() == 2) {
				cout << "���ݺ�, �� �� " << list[temp[i]].getrMonthly() << "��\n";
			}
			else if (list[temp[i]].getsType() == 3) {
				cout << "�ֹݺ�, �� " << list[temp[i]].getDayW(list[temp[i]].getrWeekly()) << "\n";
			}
			else if (list[temp[i]].getsType() == 4) {
				cout << " ����\n - ���� ��¥ : " << list[temp[i]].geteYear() << "�� "
					<< list[temp[i]].geteMonth() << "�� "
					<< list[temp[i]].geteDay() << "��\n";
			}
		}
		cout << "������ ������ ��ȣ�� �Է����ּ��� : ";
		cin >> sel;
		if (!cin) {
			cout << ">> �ùٸ� �Է��� ���ּ���.\n";
			check = false;
			_getch();
			goto re2;
		}
		else if (sel<1 || sel>count) {
			cout << ">> 1���� " << count << "������ ���� �Է����ּ���.\n";
			check = false;
			_getch();
			goto re2;
		}
		else {
		ree:;
			if (!check) cin.clear(); cin.ignore(INT_MAX, '\n');
			cout << "������ ������ ��ȣ�� " << sel << "�� �½��ϱ�? (y/n) >> ";
			char c;
			cin >> c;
			if (cin.fail()) {
				cout << "�ùٸ� �Է��� �ٽ� ���ּ���.\n";
				check = false;
				_getch();
				goto ree;
			}
			if (c == 'y')
				t = sel - 1;
			else if (c == 'n') {
				cout << "���� ���� �޴��� ���ư��ϴ�.\n";
				_getch();
				goto re2;
			}
			else {
				cout << "�ùٸ� �Է��� �ٽ� ���ּ���.\n";
				check = false;
				_getch();
				goto ree;
			}
		}

		if (list[t].getsType() == 4) {	// �ݺ��� x
			cout << "������ ������ ������ �����ϼ��� 1)�̸� 2)��¥ �� �ð� 3)ī�װ� 4) �ݺ���� 5)���� �Ϸ� ���� >> ";
			cin >> sel;
			if (!cin) {
				cout << ">> �ùٸ� �Է��� ���ּ���.\n";
				check = false;
				_getch();
				goto re2;
			}
			else if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4 || sel == 5)) {
				cout << ">> 1���� 5 ������ ���� �Է����ּ���.\n";
				check = false;
				_getch();
				goto re2;
			}
			else {
				switch (sel) {
				case 1: {	// �̸� ����
					cout << "������ ���� �̸��� �Է����ּ��� >> ";
					string name, back = list[t].getsName();
					cin.ignore(INT_MAX, '\n');
					getline(cin, name);
					if (!isRightSchedule(name)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsName(name);
					
					cout << "���� �̸��� " << back << "���� " << list[t].getsName() << "���� ����Ǿ����ϴ�.";
					_getch();
					break;
				}
				case 2: {	// ��¥ �� �ð� ����
					cout << "������ ������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2022 12 20 00 30] >> ";
					// $ NEW
					cin.ignore(INT_MAX, '\n');
					string sTime, eTime;
					getline(cin, sTime);
					if (!list[t].isRightTimeString(true, sTime)) {
						check = false;
						_getch();
						goto re2;
					}
					cout << "������ ������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2023 02 20 03 30] >> ";
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
					cout << "������ ������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2022 02 03 00 30] >> ";
					cin >> year >> month >> day >> hour >> min;
					if (!isRightSchedule(false, year, month, day, hour, min)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].seteTime(year, month, day, hour, min);*/
					cout << "������ ��¥ �� �ð� ������ �Ϸ��߽��ϴ�.\n";
					_getch();
					break;
				}
				case 3: {	// ī�װ� ����
					duplicate = false;
					cout << "<ī�װ� ����>" << endl;
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << endl;
					while (1) {
						cout << "�ش� ������ �����ϰ� ���� ī�װ� ��ȣ�� �Է����ּ���.(��� ��ȣ ��� ����)>>";
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "�߸� �Է��ϼ̽��ϴ�.\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize) {
							cout << "���� ������ ���ڸ� �Է����ּ��� >>\n";
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
						cout << "����Ǿ����ϴ�.";
					}
					else {
						cout << "������ �ִ� ī�װ� �Դϴ�.\n" << endl;
						duplicate = false;
					}
					_getch();
					break;
				}
				case 4: {	// �ݺ� ���
					int a;
					cout << "�ݺ� Ÿ���� �������ּ���. [1=���ݺ�, 2=���ݺ�, 3=�ֹݺ�, 4=�ݺ�����] >> ";
					cin >> a;
					if (cin.fail()) {
						cout << "�ùٸ� �Է��� ���ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(a == 1 || a == 2 || a == 3 || a == 4)) {
						cout << "1�� 4 ������ ���ڸ� �Է����ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						list[t].setsType(a);
						if (a == 4) {
							int year, month, day, hour, min;
						re5:;
							cout << "������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2024 12 10 00 00] >> ";
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
				
					cout << "������ �ݺ� Ÿ�� ������ �Ϸ��߽��ϴ�.\n";
					_getch();
					break;
				}
				case 5: {	// ���� �Ϸ� ����
					cout << "���� �Ϸ� ���θ� �Է����ּ��� [0:false, 1:true] >> ";
					int s;
					cin >> s;
					if (cin.fail()) {
						cout << "�ùٸ� �Է��� �ٽ� ���ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(s == 0 || s == 1)) {
						cout << "0 �Ǵ� 1�� �Է� ���ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						if (s == 1) {
							list[t].setIsDone(true);

							cout << "���� �Ϸ� ���θ� true�� �����մϴ�.\n";
							_getch();
						}
						else {
							list[t].setIsDone(false);

							cout << "���� �Ϸ� ���θ� false�� �����մϴ�.\n";
							_getch();
						}
					}
					break;
				}
				}
			}
		}
		else {	// �ݺ��� ����, type= 1 || 2 || 3
			cout << "������ ������ ������ �����ϼ��� 1)�̸� 2)��¥ �� �ð� 3)ī�װ� 4)�ݺ���� >> ";
			cin >> sel;
			if (!cin) {
				cout << ">> �ùٸ� �Է��� ���ּ���.\n";
				check = false;
				_getch();
				goto re2;
			}
			else if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4)) {
				cout << ">> 1���� 4 ������ ���� �Է����ּ���.\n";
				check = false;
				_getch();
				goto re2;
			}
			else {
				switch (sel) {
				case 1: {	// �̸� ����
					cout << "������ ���� �̸��� �Է����ּ��� >> ";
					string name, n = list[t].getsName();
					cin.ignore(INT_MAX, '\n');
					getline(cin, name);
					if (!isRightSchedule(name)) {
						check = false;
						_getch();
						goto re2;
					}
					list[t].setsName(name);

					cout << "���� �̸��� " << n << "���� " << list[t].getsName() << "���� ����Ǿ����ϴ�.";
					_getch();
					break;
				}
				case 2: {	// ��¥ �� �ð� ����
					cout << "������ ������ ���� ��¥ �� �ð��� �Է����ּ��� [ex) 2022 12 20 00 30] >> ";
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
					cout << "������ ��¥ �� �ð� ������ �Ϸ��߽��ϴ�.\n";
					_getch();
					break;
				}
				case 3: {	// ī�װ� ����
					duplicate = false;
					cout << "<ī�װ� ����>" << endl;
					for (int i = 0; i < categorySize; i++) {
						cout << i + 1 << ". " << category[i] << " ";
					}
					cout << endl;
					while (1) {
						cout << "�ش� ������ �����ϰ� ���� ī�װ� ��ȣ�� �Է����ּ���.(��� ��ȣ ��� ����)>>";
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "�߸� �Է��ϼ̽��ϴ�.\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize) {
							cout << "���� ������ ���ڸ� �Է����ּ��� >>\n";
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
						cout << "����Ǿ����ϴ�.";
					}
					else {
						cout << "������ �ִ� ī�װ� �Դϴ�.\n" << endl;
						duplicate = false;
					}
					_getch();
					break;
				}
				case 4: {	// �ݺ�����
					int a;
					cout << "�ݺ� Ÿ���� �������ּ���. [1=���ݺ�, 2=���ݺ�, 3=�ֹݺ�, 4=�ݺ�����] >> ";
					cin >> a;
					if (cin.fail()) {
						cout << "�ùٸ� �Է��� ���ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else if (!(a == 1 || a == 2 || a == 3 || a == 4)) {
						cout << "1�� 4 ������ ���ڸ� �Է����ּ���.\n";
						check = false;
						_getch();
						goto re2;
					}
					else {
						list[t].setsType(a);
						if (a == 4) {
							int year, month, day, hour, min;
						re6:;
							cout << "������ ���� �ð��� �Է����ּ��� [ex) 2024 12 10 00 00] >> ";
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
					cout << "������ �ݺ� ���� ������ �Ϸ��߽��ϴ�.\n";

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
	cout << "Ȯ���Ͻ� ������ ������ ���� �Է����ּ��� [ex) 2022 12] >> ";
	cin >> year >> month;
	if (!isRightSchedule(year, month)) {
		check = false;
		_getch();
		goto re;
	}
	cout << "====================================\n"
		<< '\t' << year << "�� " << month << "�� ����\n"
		<< "====================================\n";
	int count = 1;

	bool isLeaf;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		isLeaf = true;
	else
		isLeaf = false;
	int m[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	m[1] = isLeaf ? 29 : 28;

	// ���⼭���� �ݺ��� / �ݺ�x ������ �����ؼ� �ٽ� �ڵ� ¥����.
	// sType�� �������� �ؾ��� ��, getDayOfWeek �Լ� �ٽ� �ǵ������
	for (size_t i = 0; i < sCount; i++) {
		int type = list[i].getsType();
		switch (type) {
		case 1: {	// �� �ݺ�
			if (list[i].getsYear() <= year) {
				if (list[i].getsMonth() == month) {
					cout << " [" << count++ << "] " << list[i].getsName() << "\n";
					cout << "  - ī�װ� : " << list[i].getsCategory() << endl;
					cout << "  - ��¥ : " << year << "�� " << month << "�� ";
					if (list[i].getrAnnual().second > m[month - 1]) {
						cout << m[month - 1] << "��\n";
					}
					else {
						cout << list[i].getrAnnual().second << "��\n";
					}
					cout << "  - �� �� " << month << "�� " << list[i].getrAnnual().second << "�� �ݺ� ����\n";
				}
			}
			break;
		}
		case 2: {	// �� �ݺ�
			if (list[i].getsYear() == year) {
				if (list[i].getsMonth() <= month) {
					cout << " [" << count++ << "] " << list[i].getsName() << "\n";
					cout << "  - ī�װ� : " << list[i].getsCategory() << endl;
					cout << "  - ��¥ : " << year << "�� " << month << "�� ";
					if (list[i].getrMonthly() > m[month - 1]) {
						cout << m[month - 1] << "��\n";
					}
					else {
						cout << list[i].getrMonthly() << "��\n";
					}
					cout << "  - �� �� " << list[i].getrMonthly() << "�� �ݺ� ����\n";
				}
			}
			else if (list[i].getsYear() < year) {
				cout << " [" << count++ << "] " << list[i].getsName() << "\n";
				cout << "  - ī�װ� : " << list[i].getsCategory() << endl;
				cout << "  - ��¥ : " << year << "�� " << month << "�� ";
				if (list[i].getrMonthly() > m[month - 1]) {
					cout << m[month - 1] << "��\n";
				}
				else {
					cout << list[i].getrMonthly() << "��\n";
				}
				cout << "  - �� �� " << list[i].getrMonthly() << "�� �ݺ� ����\n";
			}
			break;
		}
		case 3: {	// �� �ݺ�
			if (list[i].getsYear() == year) {
				if (list[i].getsMonth() <= month) {
					cout << " [" << count++ << "] " << list[i].getsName() << "\n";
					cout << "  - ī�װ� : " << list[i].getsCategory() << endl;
					cout << "  - ��¥ : " << year << "�� " << month << "��";
					for (size_t j = 1; j <= m[month - 1]; j++) {
						if (getDayOfWeek(year, month, j) == list[i].getrWeekly()) {
							cout << " " << j;
						}
					}
					cout << "��\n  - �� �� " << getDayW(list[i].getrWeekly()) << " �ݺ� ����\n";
				}
			}
			else if (list[i].getsYear() < year) {
				cout << " [" << count++ << "] " << list[i].getsName() << "\n";
				cout << "  - ī�װ� : " << list[i].getsCategory() << endl;
				cout << "  - ��¥ : " << year << "�� " << month << "��";
				for (size_t j = 1; j <= m[month - 1]; j++) {
					if (getDayOfWeek(year, month, j) == list[i].getrWeekly()) {
						cout << " " << j;
					}
				}
				cout << "��\n  - �� �� " << getDayW(list[i].getrWeekly()) << " �ݺ� ����\n";
			}
			break;
		}
		case 4: {	// �ݺ�x, �������� ����
			int sy = list[i].getsYear();	// ���� ����
			int sm = list[i].getsMonth();	// ���� ��
			int ey = list[i].geteYear();	// ���� ����
			int em = list[i].geteMonth();	// ���� ��
			if (sy <= year && ey >= year) {
				if (sy == year) {
					if (sm <= month) {
						cout << " [" << count++ << "] " << list[i].getsName() << "\n";
						cout << "  - ī�װ� : " << list[i].getsCategory() << endl;
						cout << "  - ���� ��¥ : " << sy << "�� " << sm << "��" << list[i].getsDay() << "��\n";
						cout << "  - ���� ��¥ : " << ey << "�� " << em << "��" << list[i].geteDay() << "��\n";
					}
				}
				else if (ey == year) {
					if (em >= month) {
						cout << " [" << count++ << "] " << list[i].getsName() << "\n";
						cout << "  - ī�װ� : " << list[i].getsCategory() << endl;
						cout << "  - ���� ��¥ : " << sy << "�� " << sm << "��" << list[i].getsDay() << "��\n";
						cout << "  - ���� ��¥ : " << ey << "�� " << em << "��" << list[i].geteDay() << "��\n";
					}
				}
				else {
					cout << " [" << count++ << "] " << list[i].getsName() << "\n";
					cout << "  - ī�װ� : " << list[i].getsCategory() << endl;
					cout << "  - ���� ��¥ : " << sy << "�� " << sm << "��" << list[i].getsDay() << "��\n";
					cout << "  - ���� ��¥ : " << ey << "�� " << em << "��" << list[i].geteDay() << "��\n";
				}
			}
			break;
		}
		}
	}
	if (count == 1)
		cout << " - �ش� ������ ������ �����ϴ�.\n";
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

	// @ ���� ���� ���� �� ����ó��
	if (!fin.is_open()) {
		cerr << "[Error] categoryData.txt ������ �� �� �����ϴ�. ��θ� Ȯ�����ּ���.\n";
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
	// @ ���� color ���� ��� �ʿ��� �ʱ� ����
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
			printf("3. ����Ȯ��\n");
			while (1) {
				cout << "1) �ð��� ���� 2) ī�װ��� ���� 3) ���� ���� ô�� ���"<< endl;
				cout << "\n �޴� ��ȣ�� �Է����ּ��� >>";
				cin >> user;
				if (!user) {
					cout << "���ڸ� �Է��ϼ��� >>";
					cin.clear();
					cin.ignore(INT_MAX, '\n');
				}
				else if (user < 1 || user >3) {
					cout << "1~4 ������ ���ڸ� �Է����ּ��� >>";
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
					cout << "�����ϰ� ���� ī�װ� ��ȣ�� �Է����ּ���(��� ��ȣ ��� ����)>>";
					while (1) {
						cin >> categoryNum;
						if (!categoryNum) {
							cout << "���ڸ� �Է��ϼ��� >>\n";
							cin.clear();
							cin.ignore(INT_MAX, '\n');
						}
						else if (categoryNum < 1 || categoryNum >categorySize+1) {
							cout << "���� ������ ���ڸ� �Է����ּ��� >>\n";
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
									s += FileList[i][j];// / ������ ��� ���Ϸ���
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
									s += FileList[i][j];// / ������ ��� ���Ϸ���
									cout << s << endl;
									none = true;
								}
							}
							break;
						}
					}
					if (none == false) {
						cout << "\n�ش� ī�װ��� ������ �����ϴ�." << endl;
					}
					break;
				}
				else {
					int result = completePercent(FileList, size_row);
						cout << "����� ���� ���� ô���� " << result << "% �Դϴ�." << endl;
					break;
				}
			}
			_getch();
			break;
		}
		case 4: {
			printf("4. ��������");
			editSchedule();
			break;
		}
		case 5: {
			mCategory();
			break;
		}
		case 6: {
			printf("6. ����");
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
// ���� �Է� �Լ�
void create_Listfile(string FileList[100][6], int size_row)
{
	ofstream writeFileList;
	writeFileList.open("KU_do_list.txt", ios::out | ios::trunc); // ���� ���� �� �� �ʱ�ȭ
	if (writeFileList.fail()) // ���� ���� ���� ����
	{
		std::cout << "KU_do_list.txt ������ �� �� �����ϴ�." << endl;
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
		s += FileList[i][j];// / ������ ��� ���Ϸ���
		writeFileList << s;
		writeFileList << '\n';
	}

	writeFileList.close();
}

// ī�װ� �Է� �Լ�
void create_Categoryfile(string *category, int categorySize)
{
	ofstream writeCategoryList;
	writeCategoryList.open("KU_do_list_category.txt", ios::out | ios::trunc); // ���� ���� �� �� �ʱ�ȭ
	if (writeCategoryList.fail()) // ���� ���� ���� ����
	{
		std::cout << "KU_do_list_category.txt ������ �� �� �����ϴ�." << endl;
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

// ���Ͽ��� �ҷ�����
void cPlayList::load_Listfile(string FileList[100][6],int& size_row)
{
	string name; // �̸�
	string category; //ī�װ�
	string iterative; //�ݺ��� ���� 0 or 1
	string stime; // ���� �ð�
	string etime; // ���� �ð�
	string complete; // �Ϸ� ���� 0 or 1
	int ai = 0;
	string size;
	ifstream readFileList;

	readFileList.open("KU_do_list.txt"); // ���� ���� ����
	if (!readFileList) // ���� ���� ���� ����
	{
		cerr << "KU_do_list.txt ������ �� �� �����ϴ�." << endl;
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
		while (ai < size_row) // ���� ���� ������ �о����� Ȯ��
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
			if (iterative != "4")  // ���ᳯ¥ ����
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
			else // ���ᳯ¥ ����
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
	readFileList.close(); // ���� ���� �ݱ�
	this->sCount = ai;
}

// ī�װ� ���Ͽ��� �ҷ�����
void load_Categoryfile(string *category, int& categorySize)
{
	
	ifstream readCategoryList;
	string size;
	int ai = 0;
	string cat;
	readCategoryList.open("KU_do_list_category.txt"); // ī�װ� ���� ����
	if (!readCategoryList) // ī�װ� ���� ���� ����
	{
		cerr << "KU_do_list_category.txt ������ �� �� �����ϴ�." << endl;
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
	readCategoryList.close(); // ī�װ� ���� �ݱ�
}


int cPlayList::showMenu()
{
	int sel;
re:;
	system("cls");
	cout << "1) ���� �߰�  2) ���� ����  3) ���� Ȯ��  4) ���� ����  5) ī�װ� ����  6) ����\n"
		<< "\n�޴� ��ȣ�� �Է����ּ��� >> ";
	cin >> sel;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << ">> �ùٸ� �Է� ���� �ٽ� �Է��ϼ���.\n";
		_getch();
		goto re;
	}
	else if (sel < 1 || sel > 6) {
		cout << ">> 1���� 6 ������ ���� �Է����ּ���.\n";
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

void cPlayList::isRightexit_over1() { //2�� �̻� ���� ó��
	string name;
	int ch;

re_edit2:;
	system("cls");

	cin.clear(); cin.ignore(INT_MAX, '\n');

	for (int i = 0; i < v.size(); i++) {
		int index;
		index = v.at(i);
		cout << "���� ��ȣ:" << index << "�����̸�: " << list[index].getsName() << " ��¥ �� �ð�: " << list[index].getsYear() << list[index].getsMonth() << list[index].getsDay() << list[index].getsHour() << list[index].getsMin() << "\n" << endl;
	}

	cout << "������ ������ �̸��� �ߺ��˴ϴ�." << "\n" << "��µ� ���� ��, �ش��ϴ� ������ ���� ��ȣ�� �Է����ּ���! >> ";
	cin >> ch;
	if (cin.fail()) {
		cout << ">> �������� �ʴ� �ε��� �Դϴ�. �ٽ� �Է����ּ���.\n";
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
			cout << ">> �������� �ʴ� �ε��� �Դϴ�. �ٽ� �Է����ּ���.\n";
			//check = false;
			_getch();
			goto re_edit2;
		}
	}
}