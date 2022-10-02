// ****** cSchedule.h ******
#pragma once
#include "cUser.h"

class cSchedule :
	public cUser
{
private:
	// @ 카테고리 데이터, 카테고리 수
	string* categoryData = nullptr;
	int categoryNum;

	// @ 스케줄 이름
	string sName;
	
	// @ 스케줄 타입
	int sType;

	// @ 스케줄 완료 여부
	bool sIsDone = false;
public:
	// @ 생성자s
	cSchedule();
	~cSchedule();
	cSchedule(string sName);

	// @ 메뉴 출력
	int showMenu();

	// @ 카테고리 데이터 생성
	bool makeCategory();

	// @ Schedule 데이터 읽기 및 저장하기
	bool readData(string filename);
	bool saveData(string filename);
};

