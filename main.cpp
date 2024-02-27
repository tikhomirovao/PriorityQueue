#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

//класс очередь с приоритетным исключением элементов
class QueuePriority
{
	double* Wait;//поле для хранения данных
	int* Pri;//приоритет
	int MaxQueueLength;//Максимальный размер очереди
	int QueueLength;//Текущий размер очереди

public:
	//конструктор c параметрами
	QueuePriority(int m);
	//деструктор
	~QueuePriority();
	//метод добавление элемента
	void Add(double c, int p);
	//метод извлечение элемента
	int Extract();
	//метод очистки очереди
	void Clear();
	//метод проверки очереди на пустоту
	bool IsEmpty();
	//метод проверки очереди на переполнение
	bool IsFull();
	//метод определения текущего кол-ва элементов в очереди
	int GetCount();
	//метод показа всей очереди
	void Show();
};

int main()
{
	system("chcp 1251");
	system("cls");
	srand((unsigned int)time(nullptr));

	//создание очереди   
	QueuePriority QUP(25);
	//заполнение части элементов случайными числами со случайным приоритетом в цикле до 5 элемента через функцию добавления элементов
	for (int i = 0; i < 5; i++)
	{
		QUP.Add(rand() % 100 * 1.1, rand() % 12);
	}

	QUP.Show();
	QUP.Extract();
	cout << "После исключения приоритетного элемента." << endl;
	cout << endl;
	QUP.Show();
	cout << endl;
	QUP.Add(rand() % 100 * 1.1, rand() % 12);
	QUP.Show();
}
//конструктор c параметрами
QueuePriority::QueuePriority(int m)
{

	MaxQueueLength = m;//передаем максимальный размер очереди
	Wait = new double[MaxQueueLength];//выделяем память для хранения элементов очереди
	Pri = new int[MaxQueueLength];//приоритет по максимальному номеру
	QueueLength = 0;//изначально очередь пуста
}
//деструктор
QueuePriority::~QueuePriority()
{
	//освобождение выделенной памяти
	if (Wait)
	{
		delete[] Wait;
		Wait = nullptr;
		Pri = 0;
		MaxQueueLength = 0;
		QueueLength = 0;
	}
}
//метод добавление элемента
void QueuePriority::Add(double c, int p)
{
	//Если в очереди есть свободное место, вставляем новый элемент, присваиваем приоритет и  увеличиваем количество элементов 
	if (!IsFull())
	{
		Wait[QueueLength] = c;
		Pri[QueueLength] = p;
		QueueLength++;
	}
}
//метод  извлечение элемента
int QueuePriority::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот, у которого наивысший приоритет и сдвигаем очередь   
	if (!IsEmpty())
	{
		int max_pri = Pri[0];//пусть приоритетный элемент - нулевой 
		int pos_max_pri = 0;// приоритетный индекс = 0 
		//в цикле ищем приоритет        
		for (int i = 1; i < QueueLength; i++)
			//если встречен более приоритетный элемент,то в max_pri присваеваем его значение,а в pos_max_pri его индекс          
			if (max_pri < Pri[i])
			{
				max_pri = Pri[i];
				pos_max_pri = i;
			}
		//вытаскиваем приоритетный элемент       
		int temp1 = Wait[pos_max_pri];
		int temp2 = Pri[pos_max_pri];
		//сдвинуть все элементы с их приоритетом       
		for (int i = pos_max_pri; i < QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			Pri[i] = Pri[i + 1];
		}
		QueueLength--;//уменьшаем количество элементов
		return temp1;//возврат извлеченного элемента 
	}
	else return -1;
}
//метод очистки очереди
void QueuePriority::Clear()
{
	QueueLength = 0;// обнуляем текущую длину очереди
}
//метод проверки очереди на пустоту
bool QueuePriority::IsEmpty()
{
	//очередь пуста, когда её текущая длина равна нулю
	return QueueLength == 0;
}
//метод проверки очереди на переполнение
bool QueuePriority::IsFull()
{
	//очередь заполнена, когда её текущая длина равна максимальной длине
	return QueueLength == MaxQueueLength;
}
//метод определения текущего кол-ва элементов в очереди
int QueuePriority::GetCount()
{
	return QueueLength;
}
//метод показа всей очереди
void QueuePriority::Show()
{
	for (int i = 0; i < QueueLength; i++)
	{
		cout << "Элемент: " << Wait[i] << "\t" << "Приоритет: " << Pri[i] << "\n\n";
	}
	cout << endl;
}