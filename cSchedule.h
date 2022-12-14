// ****** cSchedule.h ******
#pragma once
#include "cDate.h"
#include <vector>
#include <fstream>

class cSchedule :
	public cDate
{
private:
	// @ 일정 이름 및 카테고리명
	string sName;
	string sCategory;
	string sRepeat;


	// @ 일정의 타입
	int sType = 0;
	/*
	 - sType = 1	::  반복성  일정 (매 년 같은 월일)
	 - sType = 2	::  반복성  일정 (매 월 같은 일)
	 - sType = 3	::  반복성  일정 (매 주 같은 요일)
	 - sType = 4	::	기간성  일정 (반복 X)
	*/

	// @ 반복 주기
	pair<int, int> rAnnual = { 0,0 };	// 연반복
	int rMontly = 0;
	int rWeekly = 0;

	// @ 스케줄 완료 여부
	bool sIsDone = false;

public:
	// @ 생성자s
	cSchedule();
	~cSchedule();

	bool duplicate = false;
	int categoryNum = 3;

	// @ 일정 추가
	void makeSchedule(string* category, int& categorySize, int& size_row,string FileList[100][6]);
	void manageCategory(string* category, int& categorySize,string FileList[100][6],int& size_row);
	string s = "";

	// @ 일정 삭제
	void deleteSchedule(int& size_row, string FileList[100][6]);
	bool isSign(string str);

	// @ 일정 편집
	void edit_Schedule();
	// @ 일정 편집 예외처리 함수 
	int showmenu_edit();

	// @ 일정 예외처리 함수
	// bool isRightSchedule(); : ProtoType, Override needed
	bool isRightSchedule(string name);
	bool isRightSchedule(int type);
	bool isRightSchedule(int year, int month);
	bool isRightSchedule(bool isS, int year, int month, int day, int hour, int min);

	bool isRightTimeString(bool isStart, string time);
	bool transTimeToInt(bool isStart, string time);
	// @ get methods
	string getsName() const;
	string getsCategory() const;
	int getsType() const;
	pair<int, int> getrAnnual() const;
	int getrMonthly() const;
	int getrWeekly() const;
	string getDayW(int weekly) const;

	// @ set methods
	void setsName(const string& name);
	void setRepeat(const int& type, const cSchedule& _list);
	void setIsDone(const bool& is);
	void setsType(const int& type);
	void setsCategory(const string& category);
	void setsRepeat(const string& list);

	//파일내용 저장리스트
	
	string CategoryList[100];

	int getsIsDone() const;
	

};
