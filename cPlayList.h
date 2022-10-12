#pragma once
#include "cSchedule.h"

class cPlayList
	:public cSchedule
{
private:
	// @ 일정 저장할 배열
	cSchedule* list;
	
	// @ 일정 개수
	int count = 0;

	// @ Data Files	:: 향후 수정 요망
	string dataSchedule = "data.txt";
	string dataCategory = "dataCategory.txt";
public:
	cPlayList();
	~cPlayList();

	// @ 환경 Set
	void getSetting();

	// @ play 함수
	void playList();

	// @ showMenu
	int showMenu();

};

