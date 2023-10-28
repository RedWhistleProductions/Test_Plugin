/**********************************
* Bananas Game Engine (TM)        *
* Copyright (C) Billy Snyder 2015 *
**********************************/

#ifndef NAMEDLIST_H
#define NAMEDLIST_H

#include <string>
#include <iostream>

#include "Base_List.h"


//Template implementation must be in the header file
template<class T>class NamedList:public Base_List
{
public:
    NamedList<T>(void);
    ~NamedList();

    /*********************************************************
    *  Functions for Adding and removing Data from the List  *
    *********************************************************/
    void AddNode();
    void AddNode(std::string Name);
    void AddNode(T Data);
    void AddNode(std::string Name, T Data);
    void operator+=(T Data);// Simplified way of using AddNode(T Data);
    void Remove();
    /*****************************************
    *	Pop() calls Out() and then Remove()  *
	*****************************************/
	T Pop();
    T Pop(int N);

    /*****************************************
    *   Functions for navigating the list    *
    *****************************************/

    void Next();
    void Back();
    void GoTo(int N);//Goes to the nth Node in the list
    bool Find(std::string Name);//returns true if Name is found
	void Last();
  	T* operator[](int N);
    T* operator[](std::string Name);

    /********************************************
    *	Functions for moving data in the List   *
    ********************************************/
    void Display();
    void MoveUp();
    void MoveDown();
	void Swap(int a, int b);
	void Swap(std::string a, std::string b);
    /*
        Functions for Data Output
    */

    T Out();//Return the Value of the Current Node
    T Out(int N);//Return the Value of the Nth Node

    //Returns the address of Value in the Nth Node
    T* GetAddress(int N);
    //Returns the address of Value in Named node
    T* GetAddress(std::string Name);

	struct Node
    {
    	std::string Name;
        T Value;
        Node *NextNode;
        Node *BackNode;
    };

    Node *Start;//The first Node for circular linking
    Node *Current;//The Current Node to be used


};
#endif

#ifndef NAMED_LIST_CPP_INCLUDED
#define NAMED_LIST_CPP_INCLUDED

template < class T >NamedList<T>::NamedList(void)
{
	Base_List::Looped = true;
    Start = 0;
    Current = 0;
    Base_List::Nodes = 0;
    Base_List::CurrentNode = 0;
    Base_List::CurrentName = "";
}

template < class T >void NamedList<T>::Display()
{
	GoTo(1);
	for(int i = 0; i<= Nodes; i++){
		std::cout << CurrentName << std::endl;
		Next();
	}
}

template < class T >bool NamedList<T>::Find(std::string Name)
{
	if(Nodes < 1 )return false;
	bool Done = false;
	if(Nodes < 2 or Current->Name == Name){
			Done = true;
	}
	else GoTo(1);

	while(Done == false)
	{
		if(Current->Name == Name)Done = true;
		else if(CurrentNode == Nodes)Done = true;
		else Next();
	}
	CurrentName = Current->Name;
	if(Current->Name == Name)return true;
	else return false;

}

template < class T >void NamedList<T>::Last()
{
	GoTo(Nodes);
}

template < class T >void NamedList<T>::Swap(int a, int b){
	GoTo(a);
	T A = Out();
	std::string Name_A = Current->Name;

	GoTo(b);
	T B = Out();
	std::string Name_B = Current->Name;

	Current->Value = A;
	Current->Name = Name_A;

	GoTo(a);
	Current->Value = B;
	Current->Name = Name_B;
	CurrentName = Current->Name;
}

template < class T >void NamedList<T>::MoveUp()
{
    Node *Temp = Current;
    //Extract the Current Node and seal the gap
    Current->BackNode->NextNode = Current->NextNode;
    Current->NextNode->BackNode = Current->BackNode;

    Back();

    Current->BackNode->NextNode = Temp;
    Temp->BackNode = Current->BackNode;
    Temp->NextNode = Current;
    Current->BackNode = Temp;
    Temp = Current;
    CurrentName = Current->Name;
}

template < class T >void NamedList<T>::MoveDown()
{
    Node *Temp = Current;
    //Extract the Current Node and seal the gap
    Current->BackNode->NextNode = Current->NextNode;
    Current->NextNode->BackNode = Current->BackNode;

    //Next is done twice here because the insert code puts temp infront of the current variable
    Next();
    Next();

    Current->BackNode->NextNode = Temp;
    Temp->BackNode = Current->BackNode;
    Temp->NextNode = Current;
    Current->BackNode = Temp;
    Temp = Current;
    CurrentName = Current->Name;
}

template < class T >NamedList<T>::~NamedList()
{
    if(Nodes > 0)
    {
        //Start at the end
        if(Nodes >1)GoTo(Nodes+1);
        while(Current != Start)
        {
            Remove();
        }
        Current->BackNode = 0;
        Current->NextNode = 0;
        Start = 0;
        delete Current;
    }
}

template < class T >void NamedList<T>::AddNode()
{
    if(Nodes == 0)//if this is the first Node in the NamedList
    {
        Start = new Node;
        Start->BackNode = Start;
        Start->NextNode = Start;
        Current = Start;
        Nodes = 1;
        CurrentNode = 1;
        CurrentName = Current->Name;
    }
    else if(Nodes >= 1)
    {
        //Ensure new Node is added to the end
        Current = Start->BackNode;
		CurrentNode = Nodes;

        //Make the Current Node point to a new Node
        Current->NextNode = new Node;

        //Make the New node point back
        Current->NextNode->BackNode = Current;

        //Make the new Node the Current Node
        Current = Current->NextNode;

        //Link the new node to the Start Node
        Current->NextNode = Start;
        //Link the Start node back to the new Node
        Start->BackNode = Current;
        Nodes++;
        CurrentNode++;
        CurrentName = Current->Name;
    }
    else{
		std::cout << "Error negative number of nodes in Named List" << std::endl;
    }


}

template < class T >void NamedList<T>::AddNode(T Data)
{
    AddNode();
    Current->Value = Data;
    CurrentName = Current->Name;
}

template < class T >void NamedList<T>::AddNode(std::string Name, T Data)
{
	AddNode(Data);
	Current->Name = Name;
	CurrentName = Current->Name;
}

template < class T >void NamedList<T>::AddNode(std::string Name){
	AddNode();
	Current->Name = Name;
	CurrentName = Current->Name;
}


template < class T >void NamedList<T>::Next()
{
    if(Nodes > 1)//Make sure there is a next Node
    {
        if(Looped)
        {
            //Increment the index
            CurrentNode++;
            //Move to the next Node
            Current = Current->NextNode;
            //if you moved to the Start Node make the index 1
            if(Current == Start)CurrentNode = 1;
        }
        else
        {
            if(Current != Start->BackNode)
            {
                //Increment the index
                CurrentNode++;
                //Move to the next Node
                Current = Current->NextNode;
            }

        }
    }
    CurrentName = Current->Name;
}

template < class T >void NamedList<T>::Back()
{
    if(Nodes > 1)//Make Sure there is a Node to go back to
    {
        if(Looped)
        {
            //Decremnet the index
            CurrentNode--;
            //Move back one
            Current = Current->BackNode;
            //if you move past the first Node set the index to the end
            if(Current == Start->BackNode)CurrentNode = Nodes;
        }
        else
        {
            if(Current != Start)
            {
                //Decrement the index
                CurrentNode--;
                //Move back one
                Current = Current->BackNode;
            }
        }
    }
    CurrentName = Current->Name;
}

template < class T >void NamedList<T>::operator+=(T Data)
{
    AddNode(Data);
    CurrentName = Current->Name;
}

template < class T >T NamedList<T>::Out()
{
    return Current->Value;
}

template < class T >T NamedList<T>::Out(int n)
{
    GoTo(n);
    return Out();
}
template <class T>T NamedList<T>::Pop(int n){
	GoTo(n);
	return Pop();
}

template <class T>T NamedList<T>::Pop(){
    T ReturnValue = Out();
    Remove();
	return ReturnValue;
}

template <class T>void NamedList<T>::Remove()
{
    Node *Temporary = Current;
    if(Nodes > 1)
    {
        Current->NextNode->BackNode = Current->BackNode;
        Current->BackNode->NextNode = Current->NextNode;
        Nodes--;
        if(Current == Start){
	        Start = Start->NextNode;
        }

        Current = Current->NextNode;
    }
    else if(Nodes == 1)
    {
    	Start = nullptr;
        Current->BackNode = nullptr;
        Current->NextNode = nullptr;
        Current = nullptr;
        CurrentNode = 0;
        Nodes = 0;
    }

    Temporary->BackNode = nullptr;
    Temporary->NextNode = nullptr;
    Temporary->Name = "";
    delete Temporary;
    //CurrentName = Current->Name;
}

template <class T>void NamedList<T>::GoTo(int N)
{
    //Speacial Cases

    //If N is to high goto the last Node
    if( (N >= Nodes) && (Nodes > 0) )//|| (N < 0 && Nodes > 0))
    {
        Current = Start->BackNode;
        CurrentNode = Nodes;
    }

    //If N is 0 or negative goto Start
    if(N <= 1 && Nodes > 0)
    {
        Current = Start;
        CurrentNode = 1;
    }

    //Normal cases
    if(N < CurrentNode && N > 1)
    {
        for(; N < CurrentNode; Back());
    }
    if(N > CurrentNode && N < Nodes)
    {
        for(; N > CurrentNode; Next());
    }
    
	if(Nodes >0) CurrentName = Current->Name;
}

template <class T>T* NamedList<T>::GetAddress(int N)
{
    GoTo(N);
    return &Current->Value;
}

template <class T>T* NamedList<T>::GetAddress(std::string Name){
	Find(Name);
	return &Current->Value;
}

template <class T>T* NamedList<T>::operator[](int N){
	GoTo(N);
	return &Current->Value;
}

template <class T>T* NamedList<T>::operator[](std::string Name){
	Find(Name);
	return &Current->Value;
}

#endif // NAMEDLIST_H
