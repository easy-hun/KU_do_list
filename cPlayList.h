// ****** cPlayList.h ******
#pragma once
#include "cSchedule.h"

#ifdef _MSC_VER
#define localtime_r(_time, _result) _localtime64_s(_result, _time)
#endif

class cPlayList
	:public cSchedule
{
private:
	// @ 일정 저장할 배열
	//cSchedule* list;
	cSchedule* list;
	// @ 일정 총 개수
	int sCount = 0;

	// @ 일정 index number
	vector<int> v;

	// @ 카테고리 데이터, 카테고리 수
	string* categoryData = nullptr;
	int categoryNum = 0;

	// @ Data Files	:: 향후 수정 요망
	string dataSchedule = "data.txt";
	string dataCategory = "dataCategory.txt";
public:
	
	cPlayList();
	~cPlayList();

	// @ 1) 일정 추가
	void addSchedule();

	// @ 2) 일정 삭제
	void removeSchedule();

	// @ 3) 일정 확인
	void checkSchedule();

	// @ 4) 일정 편집
	void editSchedule();

	// @ 처음 편집할 일정 이름 입력시 존재확인 예외처리 함수
	void isRightexit(string name);
	void isRightexit_over1();

	// @ 5) 카테고리 관리
	void mCategory();

	// @ 6) 종료

	// @ Schedule 데이터 읽기 및 저장하기
	bool readData(string filename);
	bool saveData(string filename);

	// @ 카테고리 데이터 생성
	bool makeCategory();

	// @ 환경 Set
	void getSetting();

	// @ play 함수
	void playList();

	// @ showMenu
	int showMenu();

	void load_Listfile(string  FileList[100][6], int& size_row);


	string category[20] = { "" }; //카테고리 배열 선언(개수제한 20개)
	int categorySize = 0;

	string FileList[100][6] = { "" };
	int size_row = 0;
};