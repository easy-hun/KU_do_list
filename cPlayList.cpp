#include "cPlayList.h"


cPlayList::cPlayList()
{
	this->list = new cSchedule[100];
	
	// +a ) 일정 및 카테고리 Data 구문 By file 입력
}


cPlayList::~cPlayList()
{
	delete[] list;
	list = nullptr;
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
	while (sel != 6) {
		sel = showMenu();
		switch (sel) {
		case 1: {
			makeSchedule();
			break;
		}
		case 2: {
			printf("2. 일정삭제");
			break;
		}
		case 3: {
			printf("3. 일정확인");
			break;
		}
		case 4: {
			printf("4. 일정편집");
			break;
		}
		case 5: {
			printf("5. 카테고리 관리");
			break;
		}
		case 6: {
			printf("6. 종료");
			break;
		}
		}
	}
}

int cPlayList::showMenu()
{
	int sel;
re:;

	system("cls");
	cout << "1) 일정 추가 2) 일정 삭제 3) 일정 확인 4) 일정 편집 5) 카테고리 관리 6) 종료\n"
		<< "\n메뉴 번호를 입력해주세요 >> ";
	cin >> sel;

	if ((typeid(sel) != typeid(int)) || sel < 1 || sel>6) {
		cout << "입력을 다시 입력해주세요.\n";
		sel = -1;
		_getch();
		goto re;
	}

	return sel;
}
