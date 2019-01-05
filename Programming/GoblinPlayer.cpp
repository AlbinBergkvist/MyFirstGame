#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;



class organism{
    public:
    string Name;
    int Ad;
    int Hp;
    int Armor;

organism(int Hp, int Armor, int Ad){ 
        
        this->Ad = Ad;
        this->Hp = Hp;
        this->Armor = Armor;
    }


    void CombatInterface(){
cout << "---------------------------------\n" << Name << "\nHp: " << Hp << "\n Armor " << Armor << "\n AD: " << Ad << "\n--------------------------------- \n";
    }
};



class hero : public organism{
    public:
    
    hero() : organism(10, 1, 3){
        Name = "Hero";
    }

    int AdDamageTaken(int EnemyAd){
        Hp = Hp + Armor - EnemyAd;
    }

    void CombatOptions(){
        cout << "\n\n\n\nWhat will you do? \n\n 1: Attack \n 2: taunt\n 3: Run\n\n";
    }

    int CombatHeroTurn(int &PlayerMove){
        
        cin >> PlayerMove;
        if (PlayerMove ==1){
            cout << "You Attack\n";
            
        } else if (PlayerMove ==2){

        }
    }
};

class monster : public organism{
    public:
    monster(int Hp, int Armor, int Ad) : organism(Hp, Armor, Ad){}
    void AdDamageTaken(int Ad){ // int AdDamageTaken(int &Hp, int Armor, int Ad)
        Hp = Hp + Armor - Ad;
    }


};


class orc : public monster{
        public:
            orc() : monster(10, 1, 2){
                Name = "Orc";
            }

    int CombatOrcTurn(int &PlayerMove, int HeroAd, hero &Hero, int OrcDescision){
        if (PlayerMove == 1){
            cout << "Ouf\n"; // Måste hitta ett bra sätt att göra så att "AdDamagetaken" funktionen kallas, går att göra 
            AdDamageTaken(HeroAd);}
        else if(PlayerMove == 2){
            cout << "You taunt the enemy";}

        // Orc´s turn to dish out the pain :)
        if (OrcDescision > 50){
            Hero.AdDamageTaken(Ad);
            cout << "The orc hits you for " << Ad << " damage!";}
        else{
            cout << "The orc misses";
        }
    }


    

};






int main(){
hero Hero;
orc Orc;
int PlayerMove;
default_random_engine randomGenerator(time(NULL));
uniform_int_distribution<int> Random100(1,100);
Random100(randomGenerator);
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

Hero.AdDamageTaken(2);


while(Hero.Hp > 0 && Orc.Hp > 0){
Hero.CombatInterface();
Orc.CombatInterface();
Hero.CombatOptions();
Hero.CombatHeroTurn(PlayerMove);
Orc.CombatOrcTurn(PlayerMove, Hero.Ad, Hero, Random100(randomGenerator));
}



return 0;
}




















