// stekforТП.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
int f=0;
class Node
{   public:
	int n; //данные
  Node *pred; // указатель на предыдущий элемент
};

class stek
{ 
    public:
	stek() 
	{
		top=NULL; 
	}
	Node *top; // указатель на верхний элемент
    void push (int i); //ф-ия добавления элемента
    void pop (); // извлечение элемента
	void finde(); // поиск элемента
	void del(); // удаление элемента
};

void stek :: push (int i)
{
	Node* newnod=new Node; // создаем элемент 
	newnod->n=i;// присваиваем значение элементам 
	f++; // увеличиваем значение счетчика
	newnod->pred=top;// присваиваем старую вершину
	top=newnod;// присваиваем новому элементу новую вершину
}

void stek :: pop ()
{
	Node*tek=top; // создаем текущий указатель и приравниваем его к вершине
	while (tek!=NULL) // пробегаем по стеку и выводим элементы на экран
	{
		cout << tek->n << endl;
    tek=tek->pred;
	}
} 

void stek :: finde()
{
	int z;
	const int sz=30;
	int m[sz];
	Node*tek=top;
	
	
	while (tek!=NULL) // ставим в соответствие элементам массив
	{
		for (int i=0; i<f; i++)
		 m[i]=tek->n;
		 tek=tek->pred;
	}
	
	cout << "nomer elementa s kontsa";
	cin >> z;
	cout << "\n";
	cout << m[z]; // вводим номер массива и получаем его значение

}
void stek :: del()
{
	int z;
	int a=0;
	cout << "nomer elementa s kontsa dla udaleniya";
	cin >> z;
	cout << "\n";
	const int sz=30;
	int m[sz];
	Node*tek=top;
	
	// ищем элементы по принципу, описанному выше, перенастраиваем указатели, что бы стек сохранился и удалыем элемент 
	while (tek!=NULL)
	{
		for (int i=0; i<f; i++)
		 m[i]=tek->n;
		 tek=tek->pred;
	}
	while (tek!=NULL)
	{
		if (a==0)
		{	
			tek=tek->pred;
			a=m[z]-tek->n;
		}
	delete tek;
	}
}
	int main ()
{ // заполняем стек и выполняем функции
	stek st1;
	while (true)
	{char c; //int n,m;
	cout << "input y/n" << endl;
	cin >>c;
	if (c=='y')
	{
	int g;
	cout << "Number of elements:";
	cin >> g;
	for (int i=0; i<g; i++)
	{
	   int r;
		cout<< "Enter elem:";
		cin>>r;
		st1.push(r);
	}
}
else {
st1.pop();
cout << "\n\n";
st1.finde();
break;}
}
system("PAUSE");
return 0;
}