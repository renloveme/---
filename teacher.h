#pragma once
#include<iostream>
using namespace std;
#include"identifyy.h"
#include<string>
#include"order.h"
#include<vector>

class teacher :public identityy {
public:
	teacher();
	teacher(int empid, string name, string pwd);

	//菜单界面
	virtual  void opermenu();
	//查看所有预约
	void showallorder();

	//审核预约
	void vailorder();



	int menpid;
};