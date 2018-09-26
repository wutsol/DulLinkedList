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
	Status InputList(int n);//����
	void OutputList();
	Status CreateList(int n);//����
	Status InsertList(int i, T e);//����������
	Status InsertDul(int i, T e);//˫����������
	Status DeleteList(int i, T &e);//������ɾ��
	Status DeleteDul(int i, T &e);//˫������ɾ�����ҵ���i-1��λ��
	Status Getelem_byID(int i, T &e);
	Status Getelem_bykey(T key, int &e);
	void MergeList(LinkedList &La, LinkedList &Lb);//�ϲ�
	Status count(int e);//����ѭ��������e�Ĵ���

};
template <class T>
LinkedList<T>::LinkedList()//����
{
	head = new Node<T>;
	head->next = NULL;
}
template <class T>
LinkedList<T>::~LinkedList()//����
{
	delete[] head;
}
template <class T>
Status LinkedList<T>::InputList(int n)//����
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
Status LinkedList<T>::CreateList(int n)//����
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
void LinkedList<T>::OutputList()//�������
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
Status LinkedList<T>::InsertList(int i, T e)//����������
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
Status LinkedList<T>::DeleteList(int i, T &e)//������ɾ��
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
Status LinkedList<T>::Getelem_byID(int i, T &e)//��֪�±귵��ֵ
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
Status LinkedList<T>::Getelem_bykey(T key, int &e)//��ֵ֪�����±�
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
void LinkedList<T>::MergeList(LinkedList &La, LinkedList &Lb)//�ϲ�
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
Status LinkedList<T>::count(int e)//����ѭ��������e�Ĵ���
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
Status LinkedList<T>::InsertDul(int i,T e)//˫���������룬�ҵ���i��λ��
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
Status LinkedList<T>::DeleteDul(int i, T &e)//˫������ɾ�����ҵ���i-1��λ��
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

