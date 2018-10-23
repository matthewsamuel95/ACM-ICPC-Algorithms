#include "LinkedList.h"
#include <string>
#include <sstream>
#include <algorithm> //swap

LinkedList::Element* LinkedList::seekIndex(int index)
{
   if ((index < 0) || (index >= size))
      return nullptr;

   Element* a= first;
   for (int i= 0 ; i < index ; i++) 
      a= a->next;

   return a;
}

void LinkedList::addEnd(int cod)
{
   Element* e= new Element(cod);

   if (size != 0) {
      Element* a= last;
      a->next= e;
      e->prev= a;
   }
   else
      first= e;

   last= e;
   size++;
}

void LinkedList::addBeggin(int cod)
{
   Element* e= new Element(cod);

   if (size != 0) {
      Element* a= first;
      e->next= a;
      a->prev= e;
   }
   else
      last= e;

   first= e;
   size++;
}

bool LinkedList::addIndex(int cod, int index)
{
   Element* aIndex= nullptr;

   if (index <= 0) {
      addBeggin(cod);
      return true;
   }
   else if (index >= size) {
      addEnd(cod);
      return true;
   }
   else {
      aIndex= seekIndex(index);
      if (!aIndex)
         return false;
   }

   Element* e = new Element(cod);
   Element* aPrevious= aIndex->prev;
   e->next= aIndex;
   e->prev= aPrevious;
   aPrevious->next= e;

   size++;
   return true;
}

bool LinkedList::deleteElement(int index)
{
   Element* aIndex= seekIndex(index);

   if (!aIndex)
      return false;

   Element* aPrev= aIndex->prev;
   Element* aNext= aIndex->next;

   if (aPrev)
      aPrev->next= aNext;
   if (aNext)
      aNext->prev= aPrev;

   if (first == aIndex)
      first= aNext;
   if (last == aIndex)
      last= aPrev;

   delete aIndex;
   size--;

   return true;
}

void LinkedList::deleteAllElements()
{
   Element* a= first;

   while (a) {
      Element* e= a->next;
      delete a;
      a= e;
   }

   size= 0;
   first= last= nullptr;
}

bool LinkedList::setElement(int cod, int index)
{
   Element* aIndex= seekIndex(index);

   bool ok= (aIndex != nullptr);
   if (ok) 
      aIndex->cod= cod;

   return ok;
}

std::string LinkedList::listAll()
{
   int i= 0;
   std::ostringstream aux;

   for (Element* a= first ; a ; a= a->next) {
      aux << "Position: " << i++ << " --- Cod: " << a->cod;
      if (a->next)
         aux << "\n";
   }

   if (!size)
      aux << "Linked list is empty.";

   return aux.str();
}

std::string LinkedList::listAllReverse()
{
   Element* a= last;
   int i= size;
   std::ostringstream aux;

   while (a) {
      Element* e= a->prev;

      aux << "Position: " << --i << " --- Cod: " << a->cod;
      if (e)
         aux << "\n";

      a= e;
   }

   if (!size)
      aux << "Linked list is empty.";

   return aux.str();
}

void LinkedList::orderByCode()
{
   Element* b;
   Element* a= first;

   for (a= first ; a ; a= a->next) {
      for (b= a->next ; b ; b= b->next) {
         if (a->cod > b->cod) 
            std::swap(a->cod, b->cod);
      }
   }
}

void LinkedList::concatenateList(LinkedList& l1)
{
   if (last) 
      last->next= l1.first;
   if (l1.first)
      l1.first->prev= last;
   if (!first)
      first= l1.first;
   last= l1.last;

   size += l1.size;

   l1.size= 0;
   l1.first= l1.last = nullptr;
}
