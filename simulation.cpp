#include <iostream>
#include <cstdlib>
using namespace std;

void green(){
	cout << "\033[0;32m";
}

void red(){
	cout << "\033[1;31m";
}

void blue(){
    cout << "\033[0;34m";
}

void white(){
	cout << "\033[0;37m";
}

void yellow(){
	cout << "\033[0;33m";
}

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

class Pirates: public OuterStuff{
    public:

    int speed;
    int shield_rating;
};

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

    int shoot(Pirates pirate_ship){

        return 0;
    }
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
            out << "the passengers have grown restless";
        }
        else if(hapiness<20){
            red();
            cout << "the passengers have begun to revolt\n";
        }
    }
};

class Station: public OuterStuff{
    public:

    string name;
    int oxygen;
    int food;

};

float mood(int a, int b, int c, int d){
    return (a+b+c+d)/4;
}

int main(){
    
    Reactor MainReactor;
    Shield MainShield;
    LifeSuport systemLS;
    Hull MainHull;

    Engine EngineOne;
    EngineOne.id=1;
    Engine EngineTwo;
    EngineTwo.id=2;
    Engine EngineThree;
    EngineThree.id=3;
    Engine EngineFour;
    EngineFour.id=4;

    Engineers EngineerCore;
    EngineerCore.numbers=20;
    Medical MedicalCore;
    MedicalCore.numbers=15;
    Crew CrewCore;
    CrewCore.numbers=10;
    Security SecurityCore;
    SecurityCore.numbers=50;
    Passengers PassengersCore;
    PassengersCore.numbers=200;


    int days=100+clock()%50+clock()%50;
    int i;
    int aux, GeneralMood;

    for(i=0;i<days;i++){
        system("clear");
        cout << "DAYS REMAINING " << days-i;
        cout << "\n\n";
        
        MainReactor.state();
        cout << "\n";
        EngineOne.state();
        EngineTwo.state();
        EngineThree.state();
        EngineFour.state();
        cout << "\n";
        MainHull.state();
        cout << "\n";
        MainShield.state();
        cout << "\n";
        systemLS.state();
        cout << "\n";

        GeneralMood=mood(EngineerCore.hapiness,MedicalCore.hapiness,CrewCore.hapiness,PassengersCore.hapiness);
        if(GeneralMood>75){ 
            green();
            cout << "mood on the ship is great\n";
        }
        else if (GeneralMood>40){
            white();
            cout << "mood on the ship satisfactory\n";
        }
        else if (GeneralMood>30){
            yellow();
            cout << "mood on the ship has become to decline\n";
        }
        else{
            red();
            cout << "mood on the ship is abysmal\n";
        }
        cout << "\n";

        EngineerCore.state();
        MedicalCore.state();
        CrewCore.state();
        PassengersCore.state();

        white();
        cout << "continue n number of days, input n: ";
        cin >> aux;
        i+=aux-1;

        if(clock()%2) MainReactor.condition-=aux;
        if(clock()%2) EngineOne.condition-=aux;
        if(clock()%2) EngineTwo.condition-=aux;
        if(clock()%2) EngineThree.condition-=aux;
        if(clock()%2) EngineFour.condition-=aux;
        if(clock()%2) systemLS.oxygen-=aux/2;
        if(clock()%2) systemLS.food-=aux/2;

        if(clock()%2) EngineerCore.hapiness-=aux/2;
        if(clock()%3) EngineerCore.health-=aux;
        if(clock()%2) MedicalCore.hapiness-=aux/2;
        if(clock()%2) CrewCore.hapiness-=aux;
        if(clock()%2) PassengersCore.hapiness-=aux/2;
    }

    green();
    cout << "\nTHE SHIP HAS ARRIVED!\n";

    return 0;
}