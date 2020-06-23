#pragma once  
using namespace std;
#include <iostream>
#include <stddef.h>

template <class ItemType>
struct NodeType;

template <class ItemType>
class QueType
{
public:
	QueType();
	~QueType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	void Print(ItemType newItem); 
	bool SearchQ(int Target);
private:
	NodeType<ItemType>* qFront;
	NodeType<ItemType>* qRear;
};
//====================================

template <class ItemType>
struct NodeType
{
	ItemType info;
	NodeType* next;
};

template <class ItemType>
QueType<ItemType>::QueType()
{
	qFront = NULL;
	qRear = NULL;
}

template <class ItemType>
QueType<ItemType>::~QueType()
{
	MakeEmpty();
}

template <class ItemType>





void QueType<ItemType>::MakeEmpty()
{
	NodeType<ItemType>* tempPtr;

	while (qFront != NULL)
	{
		tempPtr = qFront;
		qFront = qFront->next;
		delete tempPtr;
	}
	qRear = NULL;
}

template <class ItemType>
bool QueType<ItemType>::IsFull() const
{
	NodeType<ItemType>* ptr;
	ptr = new NodeType<ItemType>;
	if (ptr == NULL)
		return true;
	else
	{
		delete ptr;
		return false;
	}
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty() const
{
	return (qFront == NULL);
}


template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
	NodeType<ItemType>* newNode;

	newNode = new NodeType<ItemType>;
	newNode->info = newItem;
	newNode->next = NULL;
	if (qRear == NULL)
		qFront = newNode;
	else
		qRear->next = newNode;
	qRear = newNode;
}

template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
	NodeType<ItemType>* tempPtr;

	tempPtr = qFront;
	item = qFront->info;
	qFront = qFront->next;
	if (qFront == NULL)
		qRear = NULL;
	delete tempPtr;
}
template <class ItemType>
void QueType<ItemType>::Print(ItemType item)
{
	NodeType<ItemType>* current = qFront; 
	while (current!= NULL)
	{
		cout << current->info << "  ";
		current = current->next;
	}



} 
template <class ItemType>
bool QueType<ItemType>::SearchQ(int Target)
{

	NodeType<ItemType>* temp = qFront; 
	while (temp != NULL)
	{

		if (temp->info == Target)
			return true;
		else
			temp = temp->next; 


	}

	return false;

}