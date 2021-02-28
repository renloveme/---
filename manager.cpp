#include"manager.h"

Manager::Manager() {

}
Manager::Manager(string name, string pwd) {
	this->mname = name;
	this->mpwd = pwd;
	
	//��ʼ������ ��ȡ�������ļ�����ʦ��ѧ����Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	Computerroom com;
	while (ifs >> com.mcomid&&ifs >> com.mmaxnum) {
		vcom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << vcom.size() << endl;
}

//�˵�����
void Manager::opermenu() {
	cout << "��ӭ����Ա��" << this->mname << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����˺�
void Manager::daaperson() {
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string filename;  //�����ļ���
	string tip;  //id��
	string errortip;  //�ظ�������ʾ
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		//ѧ��
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip= "ѧ���ظ�������������";
	}
	else {
		filename = TEACHER_FILE;
		tip = "������ְ�����:";
		errortip = "ְ�����ظ�������������";

	}
	//����׷�ӵķ�ʽд�ļ�
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
	
	
	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close(); 
	//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
	this->initVector();
}
void printstudent(student &s) {
	cout << "ѧ�ţ� " << s.mid << " ������ " << s.mname << " ���룺" << s.mpwd << endl;
}
void printteacher(teacher &t) {
	cout<<"ְ���ţ�"<<t.menpid<< " ������ " << t.mname << " ���룺" << t.mpwd << endl;
}
//�鿴�˺�
void Manager::showperson() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;

	cin >> select;
	if (select == 1) {
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vstu.begin(), vstu.end(), printstudent);
	}
	else {
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vtea.begin(), vtea.end(), printteacher);
	}
	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::showcomputer() {
	cout << "������Ϣ���£� " << endl;
	for (vector<Computerroom>::iterator it = vcom.begin(); it != vcom.end(); it++) {
		
			cout << "������ţ� " << it->mcomid << " ������������� " << it->mmaxnum << endl;
		
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanfile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector() {
	//�������
	vstu.clear();
	vtea.clear();
	//��ȡ��Ϣ  ��ʦ ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	student s;
	while (ifs >> s.mid&& ifs >> s.mname&& ifs >> s.mpwd) {
		vstu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vstu.size() << endl;
	ifs.close();

	
	
	ifs.open(TEACHER_FILE, ios::in);

	teacher t;
	while (ifs >> t.menpid&& ifs >> t.mname&& ifs >> t.mpwd) {
		vtea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vtea.size() << endl;
	ifs.close();
}

//����ظ�  ����1 ѧ��/ְ����  ����2 �������
bool Manager::checkrepeat(int id, int type) {
	if (type == 1) {
		//���ѧ��
		for (vector<student>::iterator it = vstu.begin(); it != vstu.end(); it++) {
			if (id == it->mid) {
				return true;
			}
		}
	}
	else {
		//�����ʦ
		for (vector<teacher>::iterator it = vtea.begin(); it != vtea.end(); it++) {
			if (id == it->menpid) {
				return true;
			}
		}
	}
	return false;
}
