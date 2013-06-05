// TPtree.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
using namespace std;


class tree
{
    int value;					//значение элемента
    tree *left, *right;			// указатели вправо и влево.
    static tree* create(int *begin, int *end, int *min, int *max)		//функция создания дерева.
    {
        int count=end-begin;											//проверка на пустоту
        if(count<0)														
            return 0;													
        int n=count/2;
        int *mid=begin+n;
        tree *t=new tree(*mid);											//создаем указатель на элемент типа "дерево"
        if(mid!=min)													// если элемент не равен минимальному, то отсылаем его налево.
        {
            t->left=create(begin, mid-1, min, max);
        }
        if(mid!=max)													// аналогично предыдущему.
        {
            t->right=create(mid+1, end, min, max);
        }
        return t;
    }
    void out(char* str)													// вывод элементов
    {
        if (left)														// если есть указатель на лево, то мы создаем строку.
        {
            char *s=new char[strlen(str)+3];
            strcpy(s, str);												//  опируем строку в переменную str
            strcat(s, "  ");											// добавляем в конец пробел, чтобы выводилось лучше.
            left->out(s);												// делаем рекурсию, чтобы в строке были все элементы.
            delete []s;													// удаляем из памяти, чтобы не занимать лишнего.
        }
        cout << str << value << endl;									// выводим, что получилось.
        if (right)														// функция по аналогии с выводом слева.
        {
            char *s=new char[strlen(str)+3];
            strcpy(s, str);
            strcat(s, "  ");
            right->out(s);
            delete []s;
        }
    }
public:
    tree(int val)												// начальная инициализация элементов дерева.
    {
        value=val;
        left=0;
        right=0;
    }
    static tree* create(int* begin, int* end)					// делаем функцию публичной.
    {
        return create(begin, end, begin, end);
    }
    void out()													// делаем вывод публичным
    {
        out("");
    }
};
int *array;
tree* tr;
/*void sort(int arr[], int len)					//функция сортировки для элементов.

{

    for(int i = 1; i < len; ++i)
      for(int j = 0; j < len - i; ++j)
            if (arr[j] > arr[j+1])
            {
                int n=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=n;
            }
}*/

int main()
{
    int len;
    cout<<"Enter the number of elements: ";
    cin>>len;
    array=new int[len];
    for(int i=0;i<len;i++)
    {
        cout<<"Enter the value of element #"<<i+1<<": ";
        cin>>array[i];
    }
   // sort(array, len);
    tr=tree::create(array, array+len-1);
    tr->out();
    getch();
    delete[] array;
	return 0;
}

