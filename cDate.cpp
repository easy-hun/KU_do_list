// ****** cDate.cpp ******
#include "cDate.h"



cDate::cDate()
{
}


cDate::~cDate()
{
}

void cDate::printNow()
{
	bool isOn = true;
	srand((unsigned)time(NULL));

	time_t t;
	char* str;

	while (isOn) {
		time(&t);
		str = ctime(&t);
		cout << "현재 시간 : " << str;
		Sleep(1000);
		system("cls");
	}
}

void cDate::readDate()
{
	int sel = -1;
re:;

	{
	system("cls");
	sel = -1;

	cout << "=== 일정 추가 ===\n\n";
	cout << " -> 단발성입니까? (맞으면 0, 아니면 1을 입력) : ";
	cin >> sel;
	
	if (sel == 0)
		this->sType = 0;
	else if (sel == 1) {
		cout << " -> 반복되는 일정입니까? (맞으면 0, 아니면 1을 입력) : ";
		cin >> sel;

		if (sel == 0) {
			cout << "  [1] 매년 같은 월 반복 / [2] 매월 같은 날 반복 / [3] 매주 같은 요일 반복\n";
			cout << "* 반복 유형을 선택하세요 : ";
			cin >> sel;
			switch (sel)
			{
			case 1: { // 매년 같은 월
				cout << "* 매 년 반복할 월을 선택하세요 : ";
				cin >> sel;
				if (sel < 1 || sel>12)
					goto re;
				this->repeatAnnual = sel;
				break;
			}
			case 2: { // 매월 같은 날
				cout << "* 매 월 반복할 날짜를 선택하세요 (최대 28일) : ";
				cin >> sel;
				if (sel < 1 || sel>28)
					goto re;
				this->repeatMonthly = sel;
				break;
			}
			case 3: { // 매주 같은 요일
				cout << "* 매 주 반복할 요일을 선택하세요 (1=일요일, 7=월요일) : ";
				cin >> sel;
				if (sel < 1 || sel>7)
					goto re;
				this->repeatWeekly = sel;
				break;
			}
			default:
				goto re;
			}
		}
		else if (sel == 1)
			this->sType = 1;
		else
			goto re;
	}
	else
		goto re;
}
	
re2:;
	switch (sType)
	{
	case 0: {	// 단발성 일정
		cout << " [일정 시각 입력] ex) 2022 10 03 06 41 00\n -> ";
		cin >> eYear >> eMonth >> eDay >> eHour >> eMin >> eSec;
		applyLeafYear(eYear);
		/*
		< 예외처리 요소들 >
		- 그냥 함수 하나 만드는 게 편할 지도 . . .

		1. 2020년~2030년 사이
		2. 1~12월 사이
		3. 윤년에 따른 m[i]체크
		4. 시간 0~23, 분초 0~59
		*/
		
		//goto re2;
		break;
	}
	case 1: {	// 기간한정 일정
		cout << " [일정 시작 시각 입력] ex) 2022 10 3 11 0 0\n -> ";
		cin >> sYear >> sMonth >> sDay >> sHour >> sMin >> sSec;
		cout << " [종료 종료 시각 입력] ex) 2023 10 4 17 30 0\n -> ";
		cin >> eYear >> eMonth >> eDay >> eHour >> eMin >> eSec;
		// 예외처리구문
		break;
	}
	case 2: {	// 반복성 일정 : 매년 같은 월
		
	}
	case 3: {	// 반복성 일정 : 매년 같은 일

	}
	case 4: {	// 반복성 일정 : 매주 같은 요일
		
		/* 
		예외처리구문
		1. 2020년~2030년
		2. 1~12월
		3. 윤년에 따른 m[i]체크
		4. 시간 0~23, 분초 0~59
		5. repeated 종류에 따른 예외처리는 이미 했슴
		*/
		break;
	}
	}

}

void cDate::applyLeafYear(const int& year)
{
	// isLeafYear UPDATE
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		this->isLeafYear = true;
	else
		this->isLeafYear = false;

	// Day/Month UPDATE
	int m[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	m[1] = isLeafYear ? 29 : 28;
	this->daysofMonth = m;
	// cout << m[1];
}
