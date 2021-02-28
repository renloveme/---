#pragma once
#include<iostream>
using namespace std;
#include<string>


//身份抽象基类
class identityy {
public:
	//操作菜单 纯虚函数
	virtual  void opermenu() = 0;

	string mname;
	string mpwd;
};