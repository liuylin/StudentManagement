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
		cout << "Ҫ����¼����(Y/N)";
		cin >> flag;
		if (toupper(flag) == 'Y')
		{
			if (toupper(flag) == 'N')
			{
				break;
			}
			else
			{
				cout << "�����������������: ";
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
		cout << " ѧ��  ����  �Ա�  ����  Ӣ��  ��ѧ  ����  ��ѧ  ����	ƽʱ�ɼ�  ����\n";
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
	cout << "��������Ҫ���ҵ�ѧ������:";
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
		cout << "��Ǹ�����޴���!" << endl;
	else
	{
		cout << " --------------------------------------------------------------------\n";
		cout << " ѧ��  ����  �Ա�  ����  Ӣ��  ��ѧ  ����  ��ѧ  ����	ƽʱ�ɼ�  ����\n";
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
	cout << "��������Ҫ�޸ĵ�ѧ������: ";
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
		cout << "�Բ���û����Ҫ�޸ĵ�ѧ��" << endl;
	else
	{
		cout << "�������޸ĺ��ѧ��ѧ��: ";
		cin >> stu[t].number;
		cout << "�������޸ĺ��ѧ������: ";
		cin >> stu[t].name;
		cout << "�������޸ĺ��ѧ���Ա�: ";
		cin >> stu[t].sex;
		cout << "�������޸ĺ�����ĳɼ�: ";
		cin >> stu[t].score[0];
		cout << "�������޸ĺ��Ӣ��ɼ�: ";
		cin >> stu[t].score[1];
		cout << "�������޸ĺ����ѧ�ɼ�: ";
		cin >> stu[t].score[2];
		cout << "�������޸ĺ������ɼ�: ";
		cin >> stu[t].score[3];
		cout << "�������޸ĺ�Ļ�ѧ�ɼ�: ";
		cin >> stu[t].score[4];
		cout << "�������޸ĺ������ɼ�: ";
		cin >> stu[t].score[5];
		cout << "�������޸ĺ��ƽʱ�ɼ�: ";
		cin >> stu[t].score[6];
		stu[t].total = stu[t].score[0] + stu[t].score[2] + stu[t].score[3] + stu[t].score[4] + stu[t].score[5];
		stu[t].average = stu[t].total / 6;
		stu[t].last = (int)(stu[t].score[6] * 0.3 + stu[t].average*0.7);
		cout << "�޸ĳɹ� !" << endl;
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
		cout << "��������Ҫɾ����ѧ������: ";
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
			cout << "��Ҫɾ����ѧ��������!";
		cout << "����Ҫ����ɾ����(Y/N)" << endl;
		cin >> c;
		if (toupper(c) != 'Y' &&toupper(c) != 'N')
		{
			cout << "�������! ֻ������Y��N" << endl;
			cin >> c;
		}
	} while (toupper(c) == 'Y');
	getchar();
}

void student::save()
{
	char filename1[20];
	cout << "�������ļ���: ";
	cin >> filename1;
	ofstream fout(filename1, ios::app);
	if (!fout)cout << "�ļ����ܴ�!" << endl;
	else
	{
		for (int i = 0; i<n; i++)
			fout << ' ' << stu[i].number << ' ' << stu[i].name << ' ' << stu[i].sex << ' '
			<< stu[i].score[0] << ' ' << stu[i].score[1] << ' ' << stu[i].score[2] << ' ' << stu[i].score[3] << ' ' << stu[i].score[4]
			<< ' ' << stu[i].score[5] << ' ' << stu[i].score[6] << ' ' << stu[i].total << ' ' << stu[i].average << ' ' << stu[i].last;
		cout << "����ɹ�!" << endl;
	}
	fout.close();
	getchar();
}

//��ȡ�ļ���
void student::load()
{
	char filename2[20];
	cout << "��������Ҫ��ȡ���ļ���: ";
	cin >> filename2;
	ifstream fin(filename2, ios::in);
	if (!fin)cout << "�ļ����ܴ�!" << endl;
	else
	{
		for (int i = 0;; i++, n = i - 1)
		{
			if (fin.eof())break;
			fin >> stu[i].number >> stu[i].name >> stu[i].sex
				>> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3] >> stu[i].score[4]
				>> stu[i].score[5] >> stu[i].score[6] >> stu[i].total >> stu[i].average >> stu[i].last;
		}
		cout << "�ļ���ȡ�ɹ�!" << endl;
	}
	fin.close();
	getchar();
}

//����=  ��Ϊ�Զ������͵ķ�����Ҫ����
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

//����<<
ostream &operator << (ostream & scout, student &s2)
{
	cout << setw(5) << s2.number << setw(6) << s2.name << setw(6) << s2.sex << setw(6) << s2.score[0]
		<< setw(6) << s2.score[1] << setw(6) << s2.score[2] << setw(6) << s2.score[3] << setw(6) << s2.score[4]
		<< setw(6) << s2.score[5] << setw(7) << s2.score[6] << setw(9) << s2.last << '\n';
	return scout;
}

//����>>
istream & operator >> (istream & scin, student &s1)
{
	cout << '\n';
	cout << "ѧ��: ";
	scin >> s1.number;
	cout << "����: ";
	scin >> s1.name;
	cout << "�Ա�: ";
	scin >> s1.sex;
	cout << "����: ";
	scin >> s1.score[0];
	cout << "Ӣ��: ";
	scin >> s1.score[1];
	cout << "��ѧ: ";
	scin >> s1.score[2];
	cout << "����: ";
	scin >> s1.score[3];
	cout << "��ѧ: ";
	scin >> s1.score[4];
	cout << "����: ";
	scin >> s1.score[5];
	cout << "ƽʱ�ɼ�: ";
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
	cout << "\n\t\t\t  ��ѧ���ɼ�����ϵͳ���˵���" << endl;
	cout << "\n\t\t1.ѧ���ɼ�¼��\t\t\t2.���ѧ���ɼ�" << endl;
	cout << "\t\t3.��ѯѧ���ɼ�\t\t\t4.�޸�ѧ���ɼ�" << endl;
	cout << "\t\t5.ɾ��ѧ���ɼ�\t\t\t6.���ݴ����ļ�" << endl;
	cout << "\t\t7.�ļ���������\t\t\t0.�˳�ϵͳ" << endl;
	cout << "\n\t  *************************************************************" << endl;
	cout << "\n������������ɵĲ���: ";
}

int main()
{
	char dbuffer[9];
	char tbuffer[9];
	_strdate(dbuffer);
	_strtime(tbuffer);
	cout << "\n\n\t      =========>>��ӭ���������Ƽ���ѧѧ������ϵͳ<<=========\n" << endl;
	printf("\t\t\t ��ǰʱ��Ϊ: %s \t%s ", dbuffer, tbuffer);
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