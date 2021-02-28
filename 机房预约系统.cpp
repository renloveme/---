#include<iostream>
using namespace std;
#include"identifyy.h"
#include"globafile.h"
#include <fstream>
#include <string>
#include"student.h"
#include"teacher.h"
#include"manager.h"



//进入学生子菜单界面
void studentmenu(identityy* &stud) {
	while (true) {
		//调用学生子菜单
		stud->opermenu();
		student*stu = (student*)stud;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyorder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showmyorder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showallorder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelorder();
		}
		else {
			delete stud;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}

}
//进入教师子菜单界面
void teachermenu(identityy* &teac) {
	while (true)
	{
		//教师菜单
		teac->opermenu();

		teacher* tea = (teacher*)teac;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showallorder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->vailorder();
		}
		else
		{
			delete teac;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}
//进入管理员子菜单界面
void managermenu(identityy* &manager) {
	while (true) {
		//调用管理员子菜单
		manager->opermenu();

		//将父类指针转为子类指针，调用子类里其它接口
		Manager * man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)   //添加账号
		{
			cout << "添加账号" << endl;
			man->daaperson();
		}
		else if(select==2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showperson();

		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showcomputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanfile();
		}
		else {
			delete manager;  //销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能  参数1 操作文件名 参数2操作身份类型
void loginin(string filename,int type) {

	//父类指针，用于z指向子类对象
	identityy *person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);

	//判断文件s是否存在
	if(!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id=0;
	string name;
	string pwd;

	if (type == 1)	//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) //教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生登录验证
		int fid;   //从文件中读取id号
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			//与用户输入的信息做对比
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "学生登录验证成功" << endl;
				system("pause");
				system("cls");
				person = new student(id, name, pwd);
				//进入学生身份的子菜单
				studentmenu(person);
				
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		int fid;   //从文件中读取id号
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (fid == id && fname == name && fpwd == pwd) {
				cout << "教师登录验证成功" << endl;
				system("pause");
				system("cls");
				person = new teacher(id, name, pwd);
				//进入教师子菜单
				teachermenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{

		//管理员登录验证
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd) {
			if (fname == name && fpwd == pwd) {
				cout << "管理员登录验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员子菜单
				managermenu(person);

				return;
			}
		}

	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;

}


int main() {
	
	int select = 0;

	while (true)
	{

		cout << "=================  欢迎来到机房预约系统  ================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1:  //学生身份
			loginin(STUDENT_FILE,1);
			break;
		case 2:  //老师身份
			loginin(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			loginin(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");

		}
	}
	system("pause");
	return 0;
}