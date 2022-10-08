#include <iostream>
using namespace std;
#include "big_classes.h"
#include "colors.h"

class Engineers: public Humans{
    public:

    int BusyStatus;

    void state(){
        if(health<25){
            red();
            cout << "the engineers cannot work due to illness\n";
        }

        if(hapiness<20){
            red();
            cout << "the engineers have gone on strike\n";
        }
    }

};

class Medical: public Humans{
    public:

    void state(){
        if(hapiness<20){
            red();
            cout << "the medics have gone on strike\n";
        }
    }
};

class Crew: public Humans{
    public:

    void state(){
        if(health<25){
            red();
            cout << "the crew cannot work due to illness\n";
        }

        if(hapiness<20){
            red();
            cout << "the crew have gone on strike\n";
        }
    }
};

class Security: public Humans{
    public:

};

class Passengers: public Humans{
    public:

    void state(){
        if(health<25){
            red();
            cout << "the passengers are in very poor health\n";
        }

        if(hapiness>=20 && hapiness<50){
            yellow();
            cout << "the passengers have grown restless";
        }
        else if(hapiness<20){
            red();
            cout << "the passengers have begun to revolt\n";
        }
    }
};