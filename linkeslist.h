#pragma once
#ifndef  linkedlist_h
#define linkedlist_h
#define Status int
#define ERROR 0
#define OK 1
#include <iostream>
template <class T>
struct Elem
{
	T num, sco;
};
template <class T>
struct Node
{
	Elem<T> data;
	Node<T> *prior;
	Node<T> *next;
};
template <class T>
class LinkedList
{
private:
	Node<T> *head;
public:
	LinkedList();
	~LinkedList();
	Status InputList(int n);//正序
	void OutputList();
	Status CreateList(int n);//逆序
	Status InsertList(int i, T e);//单链表插入
	Status InsertDul(int i, T e);//双向链表插入
	Status DeleteList(int i, T &e);//单链表删除
	Status DeleteDul(int i, T &e);//双向链表删除，找到第i-1个位置
	Status Getelem_byID(int i, T &e);
	Status Getelem_bykey(T key, int &e);
	void MergeList(LinkedList &La, LinkedList &Lb);//合并
	Status count(int e);//计算循环链表中e的次数

};
template <class T>
LinkedList<T>::LinkedList()//构造
{
	head = new Node<T>;
	head->next = NULL;
}
template <class T>
LinkedList<T>::~LinkedList()//析构
{
	delete[] head;
}
template <class T>
Status LinkedList<T>::InputList(int n)//正序
{
	Node<T> *last, *p;
	last = head;
	for (int i = 0; i < n; i++)
	{
		p = new Node<T>;
		if (!p) return ERROR;
		cin >> p->data.num>>p->data.sco;
		last->next=p;
		p->prior = last;
		last = p;
	}
	last->next = NULL;
	//return OK;
}
template <class T>
Status LinkedList<T>::CreateList(int n)//逆序
{
	Node<T> *p;
	for (int i = n; i > 0; i--)
	{
		p = new Node<T>;
		if (!p) return ERROR;
		cin >> p->data.num>>p->data.sco;
		p->next = head->next;
		head->next = p;
	}
	return OK;
}
template <class T>
void LinkedList<T>::OutputList()//输出链表
{
	Node<T> *p;
	p = head->next;
	while (p)
	{
		cout << p->data.num<<","<<p->data.sco <<endl;
		p = p->next;
	}
}
template <class T>
Status LinkedList<T>::InsertList(int i, T e)//单链表插入
{
	Node<T> *p,*s;
	p = head;
	int j = 0;
	while (p->next!=head && j<i-1)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) return 0;
	s = new Node<T>;
	s->data.num = e;
	s->next = p->next;
	p->next = s;
	return 1;
}
template <class T>
Status LinkedList<T>::DeleteList(int i, T &e)//单链表删除
{
	Node<T> *p, *q;
	p = head;
	int j = 0;
	while (p -> next!=head && j < i - 1)
	{
		p = p -> next;
		j++;
	}
	if (!(p->next) || j < i - 1)
		return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data.num;
	delete[] q;
	return OK;
}
template <class T>
Status LinkedList<T>::Getelem_byID(int i, T &e)//已知下标返回值
{
	Node<T> *p;
	p = head;
	int j = 0;
	while (p&&j < i )
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)return ERROR;
	e = p->data.num;
	return OK;
}
template <class T>
Status LinkedList<T>::Getelem_bykey(T key, int &e)//已知值返回下标
{
	Node<T> *p;
	p = head->next;
	int j = 1;
	while (p && (p->data.num != key))
	{
		p = p->next;
		j++;
		if (!p) return 0;
	}
    e = j;
	return 1;
}
template <class T>
void LinkedList<T>::MergeList(LinkedList &La, LinkedList &Lb)//合并
{
	Node<T> *pa, *pb, *pc, *p;
	pa = La.head->next, pb = Lb.head->next, pc = head;
	while (pa&&pb)
	{
		if (pa->data.num <= pb->data.num) {
			p = new Node<T>(); p->data = pa->data;
			pc->next = p; pc = pc->next; pa = pa->next;
		}
		else
		{
			p = new Node<T>(); p->data = pb->data;
			pc->next = p; pc = pc->next; pb = pb->next;
		}
	}
	while(pa) {
		p = new Node<T>(); p->data = pa->data;
		pc->next = p; pc = pc->next; pa = pa->next;
	}
	while(pb) {
		p = new Node<T>(); p->data = pb->data;
		pc->next = p; pc = pc->next; pb = pb->next;
	}
	
}
template<class T>
Status LinkedList<T>::count(int e)//计算循环链表中e的次数
{
	int n = 0;
	Node<T> *p;
	p = head;
	while (p->next != head)
	{
		if (p->data.num == e)
		{
			n++;
			p = p->next;
		}
	}
	return (n);
}
template<class T>
Status LinkedList<T>::InsertDul(int i,T e)//双向链表插入，找到第i个位置
	{
	  Node<T> *p=head,*q;
	  int j = 0;
	  while (p&&j < i)
	  {
		  p = p->next;
		  j++;
	  }
	  if (!p || j > i) return ERROR;
	  q = new Node<T>;
	  q->data.num = e;
	  q->prior = p->prior;
	  p->prior->next = q;
	  q->next = p;
	  p->prior = q;
	  return OK;

	}
template<class T>
Status LinkedList<T>::DeleteDul(int i, T &e)//双向链表删除，找到第i-1个位置
{
	Node<T> *p=head,*q;
	int j = 0;
	while (p&&j < i-1)
	{
		p = p->next;
		j++;
	}
	if (!p || j >= i) return ERROR;
	q = p->next;
	e = q->data.num;
	p->next = q->next;
	q->next->prior = p;
	delete q;
	return OK;
}
#endif // ! linkedlist_h


