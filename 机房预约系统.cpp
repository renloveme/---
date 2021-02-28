#include<iostream>
using namespace std;
#include"identifyy.h"
#include"globafile.h"
#include <fstream>
#include <string>
#include"student.h"
#include"teacher.h"
#include"manager.h"



//����ѧ���Ӳ˵�����
void studentmenu(identityy* &stud) {
	while (true) {
		//����ѧ���Ӳ˵�
		stud->opermenu();
		student*stu = (student*)stud;
		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyorder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showmyorder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showallorder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelorder();
		}
		else {
			delete stud;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}
//�����ʦ�Ӳ˵�����
void teachermenu(identityy* &teac) {
	while (true)
	{
		//��ʦ�˵�
		teac->opermenu();

		teacher* tea = (teacher*)teac;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showallorder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->vailorder();
		}
		else
		{
			delete teac;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//�������Ա�Ӳ˵�����
void managermenu(identityy* &manager) {
	while (true) {
		//���ù���Ա�Ӳ˵�
		manager->opermenu();

		//������ָ��תΪ����ָ�룬���������������ӿ�
		Manager * man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)   //����˺�
		{
			cout << "����˺�" << endl;
			man->daaperson();
		}
		else if(select==2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showperson();

		}
		else if (select == 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showcomputer();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanfile();
		}
		else {
			delete manager;  //���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����  ����1 �����ļ��� ����2�����������
void loginin(string filename,int type) {

	//����ָ�룬����zָ���������
	identityy *person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);

	//�ж��ļ�s�Ƿ����
	if(!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id=0;
	string name;
	string pwd;

	if (type == 1)	//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) //��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ����¼��֤
		int fid;   //���ļ��ж�ȡid��
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			//���û��������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "ѧ����¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentmenu(person);
				
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fid;   //���ļ��ж�ȡid��
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "��ʦ��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				teachermenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{

		//����Ա��¼��֤
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (fname == name && fpwd == pwd) {
				cout << "����Ա��¼��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managermenu(person);

				return;
			}
		}

	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;

}


int main() {
	
	int select = 0;

	while (true)
	{

		cout << "=================  ��ӭ��������ԤԼϵͳ  ================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�����û�ѡ��

		switch (select)
		{
		case 1:  //ѧ�����
			loginin(STUDENT_FILE,1);
			break;
		case 2:  //��ʦ���
			loginin(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			loginin(ADMIN_FILE, 3);
			break;
		case 0:  //�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");

		}
	}
	system("pause");
	return 0;
}