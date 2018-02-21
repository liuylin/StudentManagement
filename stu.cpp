#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>
using namespace std;

class student
{
private:
	char name[20];
	char sex[10];
	int number;
	int score[7];
	int total;
	int average;
	int last;
public:
	student();
	void add();
	void output();
	void find();
	void modify();
	void deleted();
	void save();
	void load();
	student & operator=(student & T);
	friend istream & operator >> (istream & scin, student &s1);
	friend ostream & operator << (ostream & scout, student &s2);
};

student stu[200];
int n = 0;
void student::add()
{
	char flag = 'Y';
	while (toupper(flag) == 'Y')
	{
		cin >> stu[n];
		n++;
		cout << "要继续录入吗？(Y/N)";
		cin >> flag;
		if (toupper(flag) == 'Y')
		{
			if (toupper(flag) == 'N')
			{
				break;
			}
			else
			{
				cout << "输入错误，请重新输入: ";
				cin >> flag;
			}
		}
	}
}

void student::output()
{
	if (n != 0)
	{
		cout << " --------------------------------------------------------------------\n";
		cout << " 学号  姓名  性别  语文  英语  数学  物理  化学  生物	平时成绩  总评\n";
		cout << " --------------------------------------------------------------------\n";
		for (int t = 0; t<n; t++)
		{
			cout << stu[t];
		}
	}
	getchar();
}

void student::find()
{
	int f3 = 0;
	char n1[20];
	student temp;
	cout << '\n';
	cout << "请输入您要查找的学生姓名:";
	cin >> n1;
	for (int j = 0; j<n; j++)
	{
		if (strcmp(stu[j].name, n1) == 0)
		{
			temp = stu[j];
			f3 = 1;
		}
	}
	if (f3 == 0)
		cout << "抱歉，查无此生!" << endl;
	else
	{
		cout << " --------------------------------------------------------------------\n";
		cout << " 学号  姓名  性别  语文  英语  数学  物理  化学  生物	平时成绩  总评\n";
		cout << " --------------------------------------------------------------------\n";
		cout << setw(5) << temp.number << setw(6) << temp.name << setw(6) << temp.sex << setw(6) << temp.score[0]
			<< setw(6) << temp.score[1] << setw(6) << temp.score[2] << setw(6) << temp.score[3] << setw(6) << temp.score[4]
			<< setw(6) << temp.score[5] << setw(6) << temp.score[6] << setw(9) << temp.last << endl;
	}
	getchar();
}

void student::modify()
{
	int f4 = 0;
	int t;
	char n2[50];
	cout << '\n';
	cout << "请输入您要修改的学生姓名: ";
	cin >> n2;
	for (int j = 0; j<n; j++)
	{
		if (strcmp(stu[j].name, n2) == 0)
		{
			t = j;
			f4 = 1;
		}
	}
	if (f4 == 0)
		cout << "对不起，没有您要修改的学生" << endl;
	else
	{
		cout << "请输入修改后的学生学号: ";
		cin >> stu[t].number;
		cout << "请输入修改后的学生姓名: ";
		cin >> stu[t].name;
		cout << "请输入修改后的学生性别: ";
		cin >> stu[t].sex;
		cout << "请输入修改后的语文成绩: ";
		cin >> stu[t].score[0];
		cout << "请输入修改后的英语成绩: ";
		cin >> stu[t].score[1];
		cout << "请输入修改后的数学成绩: ";
		cin >> stu[t].score[2];
		cout << "请输入修改后的物理成绩: ";
		cin >> stu[t].score[3];
		cout << "请输入修改后的化学成绩: ";
		cin >> stu[t].score[4];
		cout << "请输入修改后的生物成绩: ";
		cin >> stu[t].score[5];
		cout << "请输入修改后的平时成绩: ";
		cin >> stu[t].score[6];
		stu[t].total = stu[t].score[0] + stu[t].score[2] + stu[t].score[3] + stu[t].score[4] + stu[t].score[5];
		stu[t].average = stu[t].total / 6;
		stu[t].last = (int)(stu[t].score[6] * 0.3 + stu[t].average*0.7);
		cout << "修改成功 !" << endl;
	}
	getchar();
}

void student::deleted()
{
	char n3[20];
	bool f5 = 0;
	char c;
	do
	{
		cout << '\n';
		cout << "请输入您要删除的学生姓名: ";
		cin >> n3;
		for (int i = 0; i<n; i++)
		{
			if (strcmp(n3, stu[i].name) == 0)
			{
				f5 = 1;
				n--;
				do
				{
					stu[i] = stu[i + 1];
					i++;
				} while (i <= n);
			}
		}
		if (f5 == 0)
			cout << "您要删除的学生不存在!";
		cout << "请问要继续删除吗？(Y/N)" << endl;
		cin >> c;
		if (toupper(c) != 'Y' &&toupper(c) != 'N')
		{
			cout << "输入错误! 只能输入Y或N" << endl;
			cin >> c;
		}
	} while (toupper(c) == 'Y');
	getchar();
}

void student::save()
{
	char filename1[20];
	cout << "请输入文件名: ";
	cin >> filename1;
	ofstream fout(filename1, ios::app);
	if (!fout)cout << "文件不能打开!" << endl;
	else
	{
		for (int i = 0; i<n; i++)
			fout << ' ' << stu[i].number << ' ' << stu[i].name << ' ' << stu[i].sex << ' '
			<< stu[i].score[0] << ' ' << stu[i].score[1] << ' ' << stu[i].score[2] << ' ' << stu[i].score[3] << ' ' << stu[i].score[4]
			<< ' ' << stu[i].score[5] << ' ' << stu[i].score[6] << ' ' << stu[i].total << ' ' << stu[i].average << ' ' << stu[i].last;
		cout << "保存成功!" << endl;
	}
	fout.close();
	getchar();
}

//读取文件名
void student::load()
{
	char filename2[20];
	cout << "请输入您要读取的文件名: ";
	cin >> filename2;
	ifstream fin(filename2, ios::in);
	if (!fin)cout << "文件不能打开!" << endl;
	else
	{
		for (int i = 0;; i++, n = i - 1)
		{
			if (fin.eof())break;
			fin >> stu[i].number >> stu[i].name >> stu[i].sex
				>> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3] >> stu[i].score[4]
				>> stu[i].score[5] >> stu[i].score[6] >> stu[i].total >> stu[i].average >> stu[i].last;
		}
		cout << "文件读取成功!" << endl;
	}
	fin.close();
	getchar();
}

//重载=  因为自定义类型的符号需要重载
student & student::operator=(student & T)
{
	strcpy(name, T.name);
	strcpy(sex, T.sex);
	number = T.number;
	for (int i = 0; i<7; i++)
		score[i] = T.score[i];
	total = T.total;
	average = T.average;
	last = T.last;
	return (*this);
}

//重载<<
ostream &operator << (ostream & scout, student &s2)
{
	cout << setw(5) << s2.number << setw(6) << s2.name << setw(6) << s2.sex << setw(6) << s2.score[0]
		<< setw(6) << s2.score[1] << setw(6) << s2.score[2] << setw(6) << s2.score[3] << setw(6) << s2.score[4]
		<< setw(6) << s2.score[5] << setw(7) << s2.score[6] << setw(9) << s2.last << '\n';
	return scout;
}

//重载>>
istream & operator >> (istream & scin, student &s1)
{
	cout << '\n';
	cout << "学号: ";
	scin >> s1.number;
	cout << "姓名: ";
	scin >> s1.name;
	cout << "性别: ";
	scin >> s1.sex;
	cout << "语文: ";
	scin >> s1.score[0];
	cout << "英语: ";
	scin >> s1.score[1];
	cout << "数学: ";
	scin >> s1.score[2];
	cout << "物理: ";
	scin >> s1.score[3];
	cout << "化学: ";
	scin >> s1.score[4];
	cout << "生物: ";
	scin >> s1.score[5];
	cout << "平时成绩: ";
	scin >> s1.score[6];
	s1.total = s1.score[0] + s1.score[1] + s1.score[2] + s1.score[3] + s1.score[4] + s1.score[5];
	s1.average = s1.total / 6;
	s1.last = (int)(s1.score[6] * 0.3 + s1.average*0.7);
	return scin;
}

student::student()
{
	strcpy(name, " ");
	strcpy(sex, " ");
	number = 0;
	for (int i = 0; i<7; i++)score[i] = 0;
	total = 0;
	average = 0;
	last = 0;
}


void menu()
{
	cout << "\n\n\t  *************************************************************" << endl;
	cout << "\n\t\t\t  【学生成绩管理系统主菜单】" << endl;
	cout << "\n\t\t1.学生成绩录入\t\t\t2.浏览学生成绩" << endl;
	cout << "\t\t3.查询学生成绩\t\t\t4.修改学生成绩" << endl;
	cout << "\t\t5.删除学生成绩\t\t\t6.数据存入文件" << endl;
	cout << "\t\t7.文件读出数据\t\t\t0.退出系统" << endl;
	cout << "\n\t  *************************************************************" << endl;
	cout << "\n请输入您想完成的操作: ";
}

int main()
{
	char dbuffer[9];
	char tbuffer[9];
	_strdate(dbuffer);
	_strtime(tbuffer);
	cout << "\n\n\t      =========>>欢迎进入陕西科技大学学生管理系统<<=========\n" << endl;
	printf("\t\t\t 当前时间为: %s \t%s ", dbuffer, tbuffer);
	int choose;
	student s;
	do
	{
		menu();
		cin >> choose;
		switch (choose)
		{
		case 1: s.add(); break;
		case 2: s.output(); break;
		case 3: s.find(); break;
		case 4: s.modify(); break;
		case 5: s.deleted(); break;
		case 6: s.save(); break;
		case 7: s.load(); break;
		default: break;
		}
	} while (choose != 0);
	return 0;
}