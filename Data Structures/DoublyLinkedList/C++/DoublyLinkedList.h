#pragma once
#ifndef INCLUDED_LINKEDLIST_H
#define INCLUDED_LINKEDLIST_H

#include <string>

class LinkedList {
private:
   struct Element {
      int cod;
      Element* next;
      Element* prev;

      Element(): cod(0), next(nullptr), prev(nullptr) {}
      Element(int c): cod(c), next(nullptr), prev(nullptr) {}

      int getCod() { return cod; }
      void setCod(int c) { cod= c; }
   };
   std::string name;
   Element* first;
   Element* last;
   int size;

   // returns the element at index when index is valid or nullptr otherwise
   Element* seekIndex(int index);

public:
   ~LinkedList() { if (size > 0) deleteAllElements(); }
   LinkedList(std::string n) { 
      name= n; 
      size= 0; 
      first= last= nullptr; 
   }

   void addEnd(int value);
   void addBeggin(int value);
   bool addIndex(int cod, int index);

   void deleteAllElements();
   bool deleteElement(int index);

   void orderByCode();

   int getSize() { return size; }

   Element* getLast(){ return last; }
   Element* getFirst(){ return first; }

   bool setElement(int cod, int index);
   std::string getName() { return name; }

   std::string listAll();
   std::string listAllReverse();

   void concatenateList(LinkedList&);
};

#endif // INCLUDED_LINKEDLIST_H
