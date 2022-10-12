// ****** cSchedule.cpp ******
#include "cSchedule.h"



cSchedule::cSchedule()
{
}


cSchedule::~cSchedule()
{
	// @ 동적 할당한 메모리 반환
	if (this->categoryData != nullptr) {
		delete[] this->categoryData;
		this->categoryData = nullptr;
	}
}

// getchar 함수 다시 공부 후 입력버퍼 비우기 해보자
void cSchedule::makeSchedule()
{
	int sel = -1;
	string name, category;

	while (1) {
	re:;
		system("cls");
		cout << "<일정 추가>\n\n";

		// 1. 일정 이름
		_getch();
		cout << "일정의 이름을 입력해주세요 >> ";
		while (getchar() != '\n') {
			cin >> name;
		}

		if (name.size() > 20) {
			cout << ">> 20자 이하로 입력해주세요.";
			system("pause");
			goto re;
		}
		else if (name.empty()) {
			cout << ">> 공백 입력 불가. 다시 입력해주세요.";
			system("pause");
			goto re;
		}
		else {
			this->sName = name;
		}

		// 2. 일정 카테고리
		cout << "일정의 카테고리를 입력해주세요 >> ";
		while (getchar() != '\n') {
			cin >> category;
		}
		/*	// 카테고리 확인 구문
		for (size_t i = 0; i < categoryNum; i++) {
			if (category.compare(categoryData[i])) {
				this->sCategory = category;
			}
			else {
				cout << ">> 해당 카테고리가 존재하지 않습니다.";
				system("pause");
				goto re;
			}
		}
		*/

		// 3. 일정 반복 기능
		cout << "일정의 반복 기능을 설정해주세요 1)연 반복 2)월 반복 3)요일 반복 4)반복 없음 >> ";
		while (getchar() != '\n') {
			cin >> sel;
		}
		if (!(sel == 1 || sel == 2 || sel == 3 || sel == 4)) {
			cout << ">> 올바른 입력을 해주세요.";
			system("pause");
			goto re;
		}
		else
			this->sType = sel;

		// 4. 시작 및 마감 날짜 입력
		cout << "일정의 시작 날짜 및 시각을 입력해주세요 [ex) 2022 02 03 00 30] >> ";
		while (getchar() != '\n') {
			cin >> sYear >> sMonth >> sDay >> sHour >> sMin;
		}
		// 예외처리 구문 삽입

		if (sel == 4) {
			cout << "일정의 마감 날짜 및 시각을 입력해주세요 [ex) 2022 02 07 15 30] >> ";
			while (getchar() != '\n') {
				cin >> eYear >> eMonth >> eDay >> eHour >> eMin;
			}
			// 예외처리 구문 삽입
		}
		else {
			// 시작 날짜 계산해서 반복 주기 설정하기
		}
		cout << "\n\"" << sName << "\" 일정 추가가 완료되었습니다.";
		_getch();
		break;
	}
}

bool cSchedule::makeCategory()
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

bool cSchedule::readData(string filename)
{
	return false;
}

bool cSchedule::saveData(string filename)
{
	return false;
}

// # 예외처리 함수 :: 일정 이름
int cSchedule::isRightSchedule(string name)
{
	return 0;
}

// # 예외처리 함수 :: 반복 타입
int cSchedule::isRightSchedule(int type)
{
	return 0;
}

// # 예외처리 함수 :: 일정 날짜 및 시각
int cSchedule::isRightSchedule(int year, int month, int day, int hour, int min)
{
	return 0;
}
