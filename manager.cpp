#include"manager.h"

Manager::Manager() {

}
Manager::Manager(string name, string pwd) {
	this->mname = name;
	this->mpwd = pwd;
	
	//初始化容器 获取到所有文件中老师、学生信息
	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	Computerroom com;
	while (ifs >> com.mcomid&&ifs >> com.mmaxnum) {
		vcom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << vcom.size() << endl;
}

//菜单界面
void Manager::opermenu() {
	cout << "欢迎管理员：" << this->mname << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//添加账号
void Manager::daaperson() {
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string filename;  //操作文件名
	string tip;  //id号
	string errortip;  //重复错误提示
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//学生
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip= "学号重复，请重新输入";
	}
	else {
		filename = TEACHER_FILE;
		tip = "请输入职工编号:";
		errortip = "职工号重复，请重新输入";

	}
	//利用追加的方式写文件
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		bool ret=checkrepeat(id, select);
		if (ret) {
			cout << errortip<<endl;
		}
		else {
			break;
		}
	}
	
	
	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close(); 
	//调用初始化容器接口，从新获取文件中的数据
	this->initVector();
}
void printstudent(student &s) {
	cout << "学号： " << s.mid << " 姓名： " << s.mname << " 密码：" << s.mpwd << endl;
}
void printteacher(teacher &t) {
	cout<<"职工号："<<t.menpid<< " 姓名： " << t.mname << " 密码：" << t.mpwd << endl;
}
//查看账号
void Manager::showperson() {
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;
	if (select == 1) {
		cout << "所有学生信息如下：" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);
	}
	else {
		cout << "所有老师信息如下：" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);
	}
	system("pause");
	system("cls");
}
//查看机房信息
void Manager::showcomputer() {
	cout << "机房信息如下： " << endl;
	for (vector<Computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++) {
		
			cout << "机房编号： " << it->mcomid << " 机房最大容量： " << it->mmaxnum << endl;
		
	}
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanfile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector() {
	//容器清空
	vstu.clear();
	vtea.clear();
	//读取信息  老师 学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	student s;
	while (ifs >> s.mid&& ifs >> s.mname&& ifs >> s.mpwd) {
		vstu.push_back(s);
	}
	cout << "当前学生数量为：" << vstu.size() << endl;
	ifs.close();

	
	
	ifs.open(TEACHER_FILE, ios::in);

	teacher t;
	while (ifs >> t.menpid&& ifs >> t.mname&& ifs >> t.mpwd) {
		vtea.push_back(t);
	}
	cout << "当前老师数量为：" << vtea.size() << endl;
	ifs.close();
}

//检测重复  参数1 学号/职工号  参数2 检测类型
bool Manager::checkrepeat(int id, int type) {
	if (type == 1) {
		//检测学生
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++) {
			if (id == it->mid) {
				return true;
			}
		}
	}
	else {
		//检测老师
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++) {
			if (id == it->menpid) {
				return true;
			}
		}
	}
	return false;
}
