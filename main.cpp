#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

//����� ������� � ������������ ����������� ���������
class QueuePriority
{
	double* Wait;//���� ��� �������� ������
	int* Pri;//���������
	int MaxQueueLength;//������������ ������ �������
	int QueueLength;//������� ������ �������

public:
	//����������� c �����������
	QueuePriority(int m);
	//����������
	~QueuePriority();
	//����� ���������� ��������
	void Add(double c, int p);
	//����� ���������� ��������
	int Extract();
	//����� ������� �������
	void Clear();
	//����� �������� ������� �� �������
	bool IsEmpty();
	//����� �������� ������� �� ������������
	bool IsFull();
	//����� ����������� �������� ���-�� ��������� � �������
	int GetCount();
	//����� ������ ���� �������
	void Show();
};

int main()
{
	system("chcp 1251");
	system("cls");
	srand((unsigned int)time(nullptr));

	//�������� �������   
	QueuePriority QUP(25);
	//���������� ����� ��������� ���������� ������� �� ��������� ����������� � ����� �� 5 �������� ����� ������� ���������� ���������
	for (int i = 0; i < 5; i++)
	{
		QUP.Add(rand() % 100 * 1.1, rand() % 12);
	}

	QUP.Show();
	QUP.Extract();
	cout << "����� ���������� ������������� ��������." << endl;
	cout << endl;
	QUP.Show();
	cout << endl;
	QUP.Add(rand() % 100 * 1.1, rand() % 12);
	QUP.Show();
}
//����������� c �����������
QueuePriority::QueuePriority(int m)
{

	MaxQueueLength = m;//�������� ������������ ������ �������
	Wait = new double[MaxQueueLength];//�������� ������ ��� �������� ��������� �������
	Pri = new int[MaxQueueLength];//��������� �� ������������� ������
	QueueLength = 0;//���������� ������� �����
}
//����������
QueuePriority::~QueuePriority()
{
	//������������ ���������� ������
	if (Wait)
	{
		delete[] Wait;
		Wait = nullptr;
		Pri = 0;
		MaxQueueLength = 0;
		QueueLength = 0;
	}
}
//����� ���������� ��������
void QueuePriority::Add(double c, int p)
{
	//���� � ������� ���� ��������� �����, ��������� ����� �������, ����������� ��������� �  ����������� ���������� ��������� 
	if (!IsFull())
	{
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}
//�����  ���������� ��������
int QueuePriority::Extract()
{
	//���� � ������� ���� ��������, �� ���������� ���, � �������� ��������� ��������� � �������� �������   
	if (!IsEmpty())
	{
		int max_pri = Pri[0];//����� ������������ ������� - ������� 
		int pos_max_pri = 0;// ������������ ������ = 0 
		//� ����� ���� ���������        
		for (int i = 1; i < QueueLength; i++)
			//���� �������� ����� ������������ �������,�� � max_pri ����������� ��� ��������,� � pos_max_pri ��� ������          
			if (max_pri < Pri[i])
			{
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		//����������� ������������ �������       
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];
		//�������� ��� �������� � �� �����������       
		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;//��������� ���������� ���������
		return temp1;//������� ������������ �������� 
	}
	else return -1;
}
//����� ������� �������
void QueuePriority::Clear()
{
	QueueLength = 0;// �������� ������� ����� �������
}
//����� �������� ������� �� �������
bool QueuePriority::IsEmpty()
{
	//������� �����, ����� � ������� ����� ����� ����
	return QueueLength == 0;
}
//����� �������� ������� �� ������������
bool QueuePriority::IsFull()
{
	//������� ���������, ����� � ������� ����� ����� ������������ �����
	return QueueLength == MaxQueueLength;
}
//����� ����������� �������� ���-�� ��������� � �������
int QueuePriority::GetCount()
{
	return QueueLength;
}
//����� ������ ���� �������
void QueuePriority::Show()
{
	for (int i = 0; i < QueueLength; i++)
	{
		cout << "�������: " << Wait[i] << "\t" << "���������: " << Pri[i] << "\n\n";
	}
	cout << endl;
}