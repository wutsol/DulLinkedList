#include <iostream>
#include "linkeslist.h"
using namespace std;

int main()
{
	//int e=1;
	LinkedList<int> intLinkedList;
	LinkedList<int> pa, pb, pc;
	//intLinkedList.InputList(5);
	//intLinkedList.CreateList(5);
	//intLinkedList.InsertList(2, 9);
	//intLinkedList.DeleteList(2, e);
	//intLinkedList.Getelem_byID(2, e);
	//intLinkedList.Getelem_bykey(2, e);
	//intLinkedList.OutputList();
	//cout << e;
	pa.InputList(4);
	pb.InputList(4);
	pc.MergeList(pa, pb);
	pc.OutputList();
	//intLinkedList.InputList(5);
	//intLinkedList.InsertDul(2, e);
	//intLinkedList.DeleteDul(2, e);
	//intLinkedList.OutputList();
	//cout << e << endl;
	system("pause");
	return 0;
}