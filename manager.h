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

	//�˵�����
	virtual  void opermenu();
	//����˺�
	void daaperson();
	//�鿴�˺�
	void showperson();
	//�鿴������Ϣ
	void showcomputer();

	//���ԤԼ��¼
	void cleanfile();

	//����ظ�  ����1 ѧ��/ְ����  ����2 �������
	bool checkrepeat(int id, int type);

	//��ʼ������
	void initVector();

	//ѧ������
	vector<student> vstu;

	//��ʦ����
	vector<teacher> vtea;
	//������Ϣ
	vector<Computerroom>vcom;
};
