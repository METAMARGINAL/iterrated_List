#pragma once
#include <iostream>
#include "List.h"
#include <string>

class Person {
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void print() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }

    bool operator==(const Person& p) const {
        return name == p.name && age == p.age;
    }

    bool operator!=(const Person& p) const {
        return !operator==(p);
    }
};