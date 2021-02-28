#pragma once
#include<iostream>
using namespace std;
#include"identifyy.h"
#include<string>
#include<fstream>
#include"globafile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerroom.h"

class Manager :public identityy {
public:
	Manager();
	Manager(string name,string pwd);

	//菜单界面
	virtual  void opermenu();
	//添加账号
	void daaperson();
	//查看账号
	void showperson();
	//查看机房信息
	void showcomputer();

	//清空预约记录
	void cleanfile();

	//检测重复  参数1 学号/职工号  参数2 检测类型
	bool checkrepeat(int id, int type);

	//初始化容器
	void initVector();

	//学生容器
	vector<student> vstu;

	//教师容器
	vector<teacher> vtea;
	//机房信息
	vector<Computerroom>vcom;
};
