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

	//�˵�����
	virtual  void opermenu();
	//�鿴����ԤԼ
	void showallorder();

	//���ԤԼ
	void vailorder();



	int menpid;
};