// ****** cSchedule.cpp ******
#include "cSchedule.h"



cSchedule::cSchedule()
{
}


cSchedule::~cSchedule()
{
	// @ filesave 구문

	// @ 동적 할당한 메모리 반환
	if (this->categoryData != nullptr) {
		delete[] this->categoryData;
		this->categoryData = nullptr;
	}
}

cSchedule::cSchedule(string sName)
{
	this->sName = sName;
	
}

int cSchedule::showMenu()
{
	int sel = -1;

	return sel;
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
