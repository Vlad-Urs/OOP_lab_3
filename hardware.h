#include <iostream>
using namespace std;
#include "big_classes.h"
#include "colors.h"

class Reactor: public Hardware{
    public:

    int risk=0;

    void state(){
        if(risk > 90){
            red();
            cout << "the reactor has exploded\n";
        }
        else if(risk > 75){
            red();
            cout << "WARNING! the reactor is critically unstable\n";
        }
        else if(risk > 50){
            yellow();
            cout << "WARNING! the reactor is unstable\n";
        }
        else if(condition > 75){
            green();
            cout << "The reactor is in optimal condition\n";
            risk+=10;
        }
        else if(condition > 50){
            white();
            cout << "The reactor is in satisfactory condition\n";
            risk+=5;
        }
        else if(condition > 25){
            yellow();
            cout << "WARNING! the reactor is in dire need of repairs\n";
        }
        else if(condition <10){
            red();
            cout << "the reactor has stopped working\n";
        }
        else{
            red();
            cout << "WARNING! the reactor is in critical condition\n";
        }

    }
};

class Engine: public Hardware{
    public:


    void state(){
        if(condition > 75){
            green();
            cout << "Engine " << id << " is in optimal condition\n";
        }
        else if(condition > 50){
            white();
            cout << "Engine " << id << " is in satisfactory condition\n";
        }
        else if(condition > 25){
            yellow();
            cout << "Engine " << id << " is in dire need of repairs\n";
        }
        else if(condition < 10){
            red();
            cout << "Engine " << id << " has stopped working\n";
        }
        else{
            red();
            cout << "Engine " << id << " is in critical condition\n";
        }
    }

};

class Shield: public Hardware{
    public:

    void state(){
        white();
        cout << "the shield is at ";
        yellow();
        cout << condition;
        cout << "%\n";
        if(condition==0){
            red();
            cout << "The shield is off\n";
        }
    }
};

class Hull: public Hardware{
    public:

    void state(){
       if (condition > 70){
        green();
        cout << "The hull is good condition\n";
       }
       else if(condition > 35){
        yellow();
        cout << "The hull is in need of repairs\n";
       }
       else if(condition > 9){
        red();
        cout << "The hull has been breached\n";
       }
       else{
        red();
        cout << "The hull has ruptured\n";
       }
    }
};

class Gun: public Hardware{
    public:

    int accuracy;
    int damage;

};

class LifeSuport: public Hardware{
    public:

    int oxygen = 100;
    int food = 100;
    int lights = 100;

    void state(){
        white();
        cout << "oxygen recycling at ";
        yellow();
        cout << oxygen;
        cout << "%\n";
        if(oxygen<15){
            red();
            cout << "OXYGEN RECYCLING HAS HALTED\n";
        }

        white();
        cout << "food recycling at ";
        yellow();
        cout << food;
        cout << "%\n";
        if(oxygen<15){
            red();
            cout << "FOOD RECYCLING HAS HALTED\n";
        }
    }
};