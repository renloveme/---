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

	//�˵�����
	virtual  void opermenu() ;

	//����ԤԼ
	void applyorder();
	//�鿴����ԤԼ
	void showmyorder();
	//�鿴����ԤԼ
	void showallorder();
	//ȡ��ԤԼ
	void cancelorder();
	//ѧ��ѧ��
	int mid;
	//��������
	vector<Computerroom> vcom;
};
