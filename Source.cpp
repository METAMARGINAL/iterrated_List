#include <iostream>
#include <string>
#include "List.h"
#include"Header.h"

using namespace std;

int main() {
    iteratedList<Person>* list = nullptr;
    list->addElem(list, Person("Alice", 30), list->GetLastInd(list));
    list->addElem(list, Person("Alice", 30), list->GetLastInd(list));
    list->addElem(list, Person("Alice", 30), list->GetLastInd(list));
    list->addElem(list, Person("Alice", 30), list->GetLastInd(list));
    list->addElem(list, Person("Alice", 30), list->GetLastInd(list));
    list->addElem(list, Person("Bob", 25), list->GetLastInd(list));
    list->addElem(list, Person("Charlie", 35), list->GetLastInd(list));
    list->addElem(list, Person("David", 40), list->GetLastInd(list));

    cout << "Main list:\n" << list->ToStringList(list) << endl;

    list->replaceAll(list, Person("Alice", 30), Person("TAPE", 1844));

    cout << "Main list:\n" << list->ToStringList(list) << endl;

    list->removeInterval(list, 1, 4);

    cout << "Main list:\n" << list->ToStringList(list) << endl;

    iteratedList<Person>* subList2 = nullptr;
    subList2->addElem(subList2, Person("Alice", 30), list->GetLastInd(subList2));
    subList2->addElem(subList2, Person("David", 40), list->GetLastInd(subList2));
    subList2->addElem(subList2, Person("LOLIK", 40), list->GetLastInd(subList2));

    cout << subList2->ToStringList(subList2) << endl;
    if (list->searchListInList(list, subList2)) {
        cout << "Sublist found!" << endl;
    }
    else {
        cout << "Sublist not found!" << endl;
    }

    list->intersection(list, subList2);
    cout<<"intersec   " << list->ToStringList(list) << endl;

    iteratedList<Person>* subList = nullptr;
    subList->addElem(subList, Person("Alice", 30), list->GetLastInd(subList));
    subList->addElem(subList, Person("David", 40), list->GetLastInd(subList));
    subList->addElem(subList, Person("LOLIK", 40), list->GetLastInd(subList));

    list->addListIn(list, subList, 0);
    cout << list->ToStringList(list) << endl;
    return 0;
}