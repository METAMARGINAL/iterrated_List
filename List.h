#pragma once
#include <string>
#include <sstream>
using namespace std;

template<typename T>
class iteratedList
{
    iteratedList* next;
    T data;
    int number;

    void updateNum(iteratedList* head) {
        iteratedList* updateTemp = head;
        int count = 0;
        while (updateTemp != nullptr) {
            updateTemp->number = count;
            count++;
            updateTemp = updateTemp->next;
        }
    }
public:
    iteratedList() : next(nullptr), number(0), data(T()) {}

    iteratedList(T nw) : next(nullptr), number(0), data(nw) {}

    void addElem(iteratedList*& head, T _nw, int num) {
        if (head == nullptr) {
            head = new iteratedList(_nw);
            head->number = 0;
            return;
        }
        iteratedList* temp = head;
        while (temp->next != nullptr && temp->number != num) {
            temp = temp->next;
        }
        if (temp->number == num) {
            iteratedList* nw = new iteratedList(_nw);
            nw->next = temp->next;
            temp->next = nw;
            updateNum(this);
       }
    }

    void addListIn(iteratedList*& head, iteratedList*& newL, int ind) {
        if (isEmpty(head)) {
            head = newL;
            return;
        }

        iteratedList* tmp = head;

        while (tmp != nullptr) {
            if (tmp->number == ind) {
                iteratedList* tmpSave = tmp->next;

                tmp->next = newL;

                iteratedList* last = newL;
                while (last->next != nullptr) {
                    last = last->next;
                }

                last->next = tmpSave;

                break; 
            }
            tmp = tmp->next;
        }

        updateNum(head);
    }

    bool isEmpty(iteratedList* head) const {
        return (head == nullptr);
    }

    void removeElem(iteratedList*& head, int num) {
        if (isEmpty(head)) {
            return;
        }

        iteratedList* tmp = head;
        while (tmp->next != nullptr && tmp->next->number != num)
        {
            tmp = tmp->next;
        }

        if (tmp->next->number == num)
        {
            iteratedList* del = tmp->next;
            tmp->next = tmp->next->next;
            delete del;
            del = nullptr;
            updateNum(head);
        }
    }

    void RemoveList(iteratedList*& head) {
        while (!isEmpty(head))
        {
            removeElem(head, 0);
        }
    }

    void removeInterval(iteratedList*& head, int b, int e) {
        iteratedList* tmp = head;
        iteratedList* prev = nullptr;

        while (tmp != nullptr) {
            if (tmp->number >= b && tmp->number <= e) {
                if (prev != nullptr) {
                    prev->next = tmp->next;
                }
                else {
                    head = tmp->next;
                }
                iteratedList* toDel = tmp;
                tmp = tmp->next;
                delete toDel;
                toDel = nullptr;
            }
            else {
                prev = tmp;
                tmp = tmp->next;
            }
        }

        updateNum(head);
    }

    string ToStringList(iteratedList*& head) {
        string res = "";
        if (isEmpty(head)) {
            return res;
        }
        iteratedList* tmp = head;
        while (tmp != nullptr) {
            stringstream ss;
            ss << tmp->data;  
            res += ss.str();
            res += " [" + to_string(tmp->number) + "]"; 
            res += "\n";
            tmp = tmp->next;
        }
        return res;
    }

    void PrintList(iteratedList*& head) {
        if (isEmpty(head)) {
            return;
        }
        iteratedList* tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data;
            cout << "[" << tmp->number << "]" << endl;
            tmp = tmp->next;
        }
    }

    bool search(iteratedList*& head, T _data) {
        iteratedList* tmp = head;
        while (tmp != nullptr) {
            if (tmp->data == _data) {
                cout << tmp->number;
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    bool searchListInList(iteratedList*& head, iteratedList*& subList) {
        if (subList == nullptr) return true;  
        if (head == nullptr) return false;  

        iteratedList* tmp = head;
        while (tmp != nullptr) {
            iteratedList* current = tmp;
            iteratedList* subTmp = subList;

            while (current != nullptr && subTmp != nullptr) {
                if (current->data != subTmp->data) {
                    break;  
                }
                current = current->next;
                subTmp = subTmp->next;
            }

            if (subTmp == nullptr) {
                return true;
            }

            tmp = tmp->next;  
        }

        return false; 
    }

    void replaceAll(iteratedList*& head, T _data, T _newData) {
        iteratedList* tmp = head;
        while (tmp != nullptr) {
            if (tmp->data == _data) {
                tmp->data = _newData;
            }
            tmp = tmp->next;
        }
    }

    void association(iteratedList*& head, iteratedList*& newL) {
        iteratedList* tmp = newL;
        while (tmp != nullptr) {
            if (!search(head, tmp->data)) {
                int lastIndex = GetLastInd(head);
                addElem(head, tmp->data, lastIndex);
            }
            tmp = tmp->next;  
        }
        updateNum(head);
    }

    void intersection(iteratedList*& head, iteratedList*& newL) {
        if (head == nullptr || newL == nullptr) {
            return;  
        }

        iteratedList* tmp = head;
        iteratedList* prev = nullptr;  
        while (tmp != nullptr) {          
            if (!search(newL, tmp->data)) {             
                iteratedList* toDelete = tmp;
                if (prev == nullptr) {                  
                    head = tmp->next;
                }
                else {
                    prev->next = tmp->next;
                }
                tmp = tmp->next;
                delete toDelete;
            }
            else {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        updateNum(head);
    }

    int GetLastInd(iteratedList*& head) {
        if (isEmpty(head)) {
            return 0;
        }
        iteratedList* tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        return tmp->number;
    }
};

