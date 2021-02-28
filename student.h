#pragma once
#include<iostream>
using namespace std;
#include"identifyy.h"
#include<string>
#include<fstream>
#include"globafile.h"
#include"computerroom.h"
#include<vector>
#include"teacher.h"
#include<algorithm>
#include"order.h"

class student:public identityy {
public:
	student();

	student(int id, string name, string pwd);

	//菜单界面
	virtual  void opermenu() ;

	//申请预约
	void applyorder();
	//查看自身预约
	void showmyorder();
	//查看所有预约
	void showallorder();
	//取消预约
	void cancelorder();
	//学生学号
	int mid;
	//机房容器
	vector<Computerroom> vcom;
};
