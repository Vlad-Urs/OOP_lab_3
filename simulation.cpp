#include <iostream>
#include <cstdlib>
#include "big_classes.h"
#include "hardware.h"
using namespace std;




class Pirates: public OuterStuff{
    public:

    int speed;
    int shield_rating;
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