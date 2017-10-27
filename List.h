//List.h
#ifndef NEO_LIST_H
#define NEO_LIST_H

#include <stdlib.h>
#include <iostream>
#include <string>
#include <map>

namespace AtTools {
    template <class IDType, class Type, class InheritedType = Type>
    class List {
        //Attributes
        protected:
            bool State;
            int InputResponse, Size;
            Type *First, *Last;
            std::map<IDType, Type*> Map;
            std::string Name;
        //Access Methods
        public:
            List();
            ~List();
            Type *operator[](IDType);
            Type *operator[](InheritedType*);
            Type *GetFirst();
            int GetInputResponse();
            Type *GetLast();
            std::string GetName();
            int GetSize();
            bool IsEnabled();
        //Process Methods
        public:
            void Clear();
            void MoveToLast(Type *Item);
            Type *NewItem(IDType ID);
            bool RemoveItem(Type *Item);
            void RenameList(std::string Name, std::string NewName);
            void SetName(std::string Name);
            void SetInputResponse(int InputResponse);
            void SetState(bool State);
            void SwapItems(Type *One, Type *Two);
            void Who();
    };

    template <class IDType, class Type, class InheritedType>
    Type *List<IDType, Type, InheritedType>::operator[](IDType ID) {
        return Map[ID];
    }

    template <class IDType, class Type, class InheritedType>
    Type *List<IDType, Type, InheritedType>::operator[](InheritedType *Target) {
        Type *Find = NULL;

        if (Target) {
            IDType ID = Target->GetID();
            if (Map[ID] == Target) Find = Map[ID];
        }

        return Find;
    }

    template <class IDType, class Type, class InheritedType>
    void List<IDType, Type, InheritedType>::Clear() {
        while (Last) RemoveItem(Last);
        Map.clear();
    }

    template <class IDType, class Type, class InheritedType>
    Type *List<IDType, Type, InheritedType>::GetFirst() {
        return First;
    }

    template <class IDType, class Type, class InheritedType>
    int List<IDType, Type, InheritedType>::GetInputResponse() {
        return InputResponse;
    }

    template <class IDType, class Type, class InheritedType>
    Type *List<IDType, Type, InheritedType>::GetLast() {
        return Last;
    }

    template <class IDType, class Type, class InheritedType>
    std::string List<IDType, Type, InheritedType>::GetName() {
        return Name;
    }

    template <class IDType, class Type, class InheritedType>
    int List<IDType, Type, InheritedType>::GetSize() {
        return Size;
    }

    template <class IDType, class Type, class InheritedType>
    bool List<IDType, Type, InheritedType>::IsEnabled() {
        return State;
    }

    template <class IDType, class Type, class InheritedType>
    List<IDType, Type, InheritedType>::List() {
        State = true;
        First = NULL;
        Last = NULL;
        InputResponse = 1;
        Size = 0;
        Name = "UnnamedList";
    }

    template <class IDType, class Type, class InheritedType>
    void List<IDType, Type, InheritedType>::MoveToLast(Type *Item) {
        if (Last != Item) {
            Type *Previous = Item->Previous;
            Type *Next = Item->Next;

            if (Previous || Next) {
                Last->Next = Item;
                Last->Next->Previous = Last;
                Last = Last->Next;
                Last->Next = NULL;

                if (Next) Next->Previous = Previous; else Last = Previous;
                if (Previous) Previous->Next = Next; else First = Next;
            } else std::cerr << "(AtTools/List.h) MoveToLast(): Target item has no previous or next element." << std::endl;
        }
    }

    template <class IDType, class Type, class InheritedType>
    Type *List<IDType, Type, InheritedType>::NewItem(IDType ID) {
        Type *Item = NULL;

        if (!Map[ID]) {
            if (First == NULL) {
                First = new Type;
                Last = First;
                Last->Next = NULL;
                Last->Previous = NULL;
            } else {
                Last->Next = new Type;
                Last->Next->Previous = Last;
                Last = Last->Next;
                Last->Next = NULL;
            }

            if (Last) {
                Size++;
                Item = Last;
                Map[ID] = Last;
            } else std::cerr << "(AtTools/List.h) NewItem(): Could not create new item." << std::endl;
        }

        return Item;
    }

    template <class IDType, class Type, class InheritedType>
    bool List<IDType, Type, InheritedType>::RemoveItem(Type *Item) {
        bool RemoveItem = false;

        if (Item) {
            Type *Previous = Item->Previous;
            Type *Next = Item->Next;

            if (Item == First) {
                First = NULL;
                if (Next) {
                    First = Next;
                    Next->Previous = NULL;
                } else Last = NULL;
            } else if (Item == Last) {
                Previous->Next = NULL;
                Last = Previous;
            } else {
                if (Previous) Previous->Next = Next;
                if (Next) Next->Previous = Previous;
            }

            IDType ID = Item->GetID();
            Map.erase(ID);

            delete Item;
            Size -= 1;
            RemoveItem = true;
        } else std::cerr << "(AtTools/List.h) RemoveItem(): Target item is NULL." << std::endl;

        return RemoveItem;
    }

    template <class IDType, class Type, class InheritedType>
    void List<IDType, Type, InheritedType>::SetName(std::string Name) {
        this->Name = Name;
    }

    template <class IDType, class Type, class InheritedType>
    void List<IDType, Type, InheritedType>::SetInputResponse(int InputResponse) {
        this->InputResponse = InputResponse;
    }

    template <class IDType, class Type, class InheritedType>
    void List<IDType, Type, InheritedType>::SetState(bool State) {
        this->State = State;
    }

    template <class IDType, class Type, class InheritedType>
    void List<IDType, Type, InheritedType>::SwapItems(Type *One, Type *Two) {
        Type *OnePrevious, *OneNext;

        OnePrevious = One->Previous;
        OneNext = One->Next;

        //One -> Two
        if (Two->Previous != One) One->Previous = Two->Previous; else One->Previous = Two;
        if (Two->Previous && Two->Previous != One) Two->Previous->Next = One;
        if (Two->Next && Two->Next != One) Two->Next->Previous = One;
        if (Two->Next != One) One->Next = Two->Next; else One->Next = Two;

        //Two -> One
        if (OnePrevious != Two) Two->Previous = OnePrevious; else Two->Previous = One;
        if (OneNext && OneNext != Two) OneNext->Previous = Two;
        if (OnePrevious && OnePrevious != Two) OnePrevious->Next = Two;
        if (OneNext != Two) Two->Next = OneNext; else Two->Next = One;

        //First - Last fix
        if (!One->Next) Last = One;
        if (!One->Previous) First = One;
        if (!Two->Next) Last = Two;
        if (!Two->Previous) First = Two;
    }

    template <class IDType, class Type, class InheritedType>
    void List<IDType, Type, InheritedType>::Who() {
        std::cout << "[" << Name << "] (" << Size << " items)" << std::endl;
        Type *Item = First;
        while (Item) {
            Item->Who();
            Item = Item->Next;
        }
    }

    template <class IDType, class Type, class InheritedType>
    List<IDType, Type, InheritedType>::~List() {
        State = false;
        Size = InputResponse = 0;
        Clear();
    }
}

#endif
