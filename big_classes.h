#pragma once
#include <iostream>
using namespace std;
class Object{
    public:

    int id;
};

class Hardware: public Object{
    public:

    int condition=100;
    int RepairTime;
};

class Humans: public Object{
    public:

    int skill;
    int numbers;
    int hapiness=100;
    int health=100;
};

class OuterStuff: public Object{
    public:

    int distance;
};
