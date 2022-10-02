// ****** cUser.h ******
#pragma once
#include "cDate.h"

class cUser :
	public cDate
{

private:
	// @ User 이름
	string uName;

	// @ User 권한 On/Off
	bool isUser = false;

	// @ User ID 및 PW (추후 구현할 로그인 기능)
	string uId, uPw;

protected:
	// @ User ID 반환
	string getUserName();

public:
	cUser();
	~cUser();

};

