// ****** team15_main.cpp ******
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cSchedule.h"
#include "team15_main.h"

using namespace std;

// @ 세팅
bool getSetting() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	srand((unsigned)time(NULL));
	// @ 이후 color 설정 등등 필요한 초기 설정

	return true;
}

// @ 실행
void play() {
	getSetting();

	cSchedule* s;
	s = new cSchedule[100];
	
	//s[0].printNow();

	delete[] s;
	s = nullptr;
}

int main() {

	play();

	return 0;
}

/*
***** 특이케이스 1번 일정 편집&삭제 *****

=> 삭제할 일정 이름을 입력하세요 : 축구

1. 축구 ( 단발 2022 06 22 )
2. 축구 ( 반복 2022 08 20 , 15 00 00 )
3. 축구 ( 기간제 2022 10 08 ~ 2022 10 10 )

삭제할 번호를 선택하세요 : 

*/




/*
<문제점>

1. 년수가 긴 일정의 경우, 따로따로 isLeafYear를 구하는 걸 만들어야 하나?


*/