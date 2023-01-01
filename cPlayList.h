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
	// @ ���� ������ �迭
	//cSchedule* list;
	cSchedule* list;
	// @ ���� �� ����
	int sCount = 0;

	// @ ���� index number
	vector<int> v;

	// @ ī�װ� ������, ī�װ� ��
	string* categoryData = nullptr;
	int categoryNum = 0;

	// @ Data Files	:: ���� ���� ���
	string dataSchedule = "data.txt";
	string dataCategory = "dataCategory.txt";
public:
	
	cPlayList();
	~cPlayList();

	// @ 1) ���� �߰�
	void addSchedule();

	// @ 2) ���� ����
	void removeSchedule();

	// @ 3) ���� Ȯ��
	void checkSchedule();

	// @ 4) ���� ����
	void editSchedule();

	// @ ó�� ������ ���� �̸� �Է½� ����Ȯ�� ����ó�� �Լ�
	void isRightexit(string name);
	void isRightexit_over1();

	// @ 5) ī�װ� ����
	void mCategory();

	// @ 6) ����

	// @ Schedule ������ �б� �� �����ϱ�
	bool readData(string filename);
	bool saveData(string filename);

	// @ ī�װ� ������ ����
	bool makeCategory();

	// @ ȯ�� Set
	void getSetting();

	// @ play �Լ�
	void playList();

	// @ showMenu
	int showMenu();

	void load_Listfile(string  FileList[100][6], int& size_row);


	string category[20] = { "" }; //ī�װ� �迭 ����(�������� 20��)
	int categorySize = 0;

	string FileList[100][6] = { "" };
	int size_row = 0;
};