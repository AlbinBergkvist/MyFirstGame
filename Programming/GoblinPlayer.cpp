// This awesome game was created by me Albin!

#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;
void ClearScreen();
void CombatEndTurn();
void CombatTitle();
void Introduction();
int EnterAnyNumber(int &StoryChoice);
void SlaveKeeperReward1(int &StoryChoice, int &Ad, int &Armor);

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

    hero() : organism(10, 1, 5){
        Name = "Hero";
    }

    int AdDamageTaken(int EnemyAd){
        Hp = Hp + Armor - EnemyAd;
    }

    void CombatOptions(){
        cout << "\n\n\n\nWhat will you do? \n\n 1: Attack \n 2: taunt\n 3: Run\n\n";
    }

    string CheckAlive(){
        if (Hp <= 0){
            cout << "GameOver \n You lost all your health";
            return "Dead";
        } else{
            return "Alive"; }
    };

    int CombatHeroTurn(int &PlayerMove){
        
        cin >> PlayerMove;
        if (PlayerMove ==1){
            ClearScreen();
            CombatTitle();
            cout << "You attack";
        } else if (PlayerMove ==2){
            ClearScreen();
            CombatTitle();

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
            orc() : monster(10, 1, 3){
                Name = "Orc";
            }

    int CombatOrcTurn(int &PlayerMove, int HeroAd, hero &Hero, int OrcDescision){
        if (PlayerMove == 1){
            cout << " and deal " << Hero.Ad - Armor << " damage!\n\n"; 
            AdDamageTaken(HeroAd);}
        else if(PlayerMove == 2){
            cout << "You taunt the enemy\n\n";}

        // Orc´s turn to dish out the pain :)
        if (OrcDescision > 90){ // critical strike
            Hero.AdDamageTaken(Ad*2);
            cout << "The " << Name << " hits you for " << Ad*2 - Hero.Armor << " critical damage!\n\n";}
        else if (OrcDescision > 50){ //Normal Attack
            Hero.AdDamageTaken(Ad);
            cout << "The " << Name << " hits you for " << Ad - Hero.Armor << " damage!\n\n";}
        else{ // Attack miss
            cout << "The " << Name << " misses\n\n";
        }
    }
};

class slave : public monster{
        public:
            slave() : monster(10, 0, 2){
                Name = "Slave";
            }
    int CombatSlaveTurn(int &PlayerMove, int HeroAd, hero &Hero, int SlaveDescision){
           if (PlayerMove == 1){
            cout << " and deal " << Hero.Ad - Armor << " damage!\n\n"; 
            AdDamageTaken(HeroAd);}
        else if(PlayerMove == 2){
            cout << "You taunt the enemy\n\n";}

        // Slave's turn to dish out the pain :)
        if (SlaveDescision > 90){ // critical strike
            Hero.AdDamageTaken(Ad*2);
            cout << "The " << Name << " hits you for " << Ad*2 - Hero.Armor << " critical damage!\n\n";}
        else if (SlaveDescision > 50){ //Normal Attack
            Hero.AdDamageTaken(Ad);
            cout << "The " << Name << " hit you for " << Ad - Hero.Armor << " damage!\n\n";}
        else{ // Attack miss
            cout << "The " << Name << " missed!\n\n";
        }
    }
};









































int main(){
hero Hero;
orc Orc;
orc Orc2;
slave Slave;
int PlayerMove;
int StoryChoice;
default_random_engine randomGenerator(time(NULL));
uniform_int_distribution<int> Random100(1,100);
Random100(randomGenerator);
///////////////////////////////////////////////////// flyta så texten hamnar i bottnen och introduction text
ClearScreen();
Introduction();
EnterAnyNumber(StoryChoice);
ClearScreen();

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


while(Hero.Hp > 0 && Orc.Hp > 0){ //Första testet med Orc
CombatTitle();
Hero.CombatInterface();
Orc.CombatInterface();
Hero.CombatOptions();
Hero.CombatHeroTurn(PlayerMove);
Orc.CombatOrcTurn(PlayerMove, Hero.Ad, Hero, Random100(randomGenerator));
CombatEndTurn();
}


if (Hero.CheckAlive()== "Dead"){
    return 0;}

cout << "\n\nYou won the fight versus the orc \n After a short while you continue your journey\n";
EnterAnyNumber(StoryChoice);

ClearScreen();

while(Hero.Hp > 0 && Slave.Hp > 0){ //Första testet med Slave efter att göra en paus med story choise
CombatTitle();
Hero.CombatInterface();
Slave.CombatInterface();
Hero.CombatOptions();
Hero.CombatHeroTurn(PlayerMove);
Slave.CombatSlaveTurn(PlayerMove, Hero.Ad, Hero, Random100(randomGenerator));
CombatEndTurn();
}



SlaveKeeperReward1(StoryChoice, Hero.Ad, Hero.Armor);



return 0;
}


























































































void CombatEndTurn(){
 cout << "After switching blows you and your opponent ready yourselves for the next move...\n\n";
};
void ClearScreen(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
};

void CombatTitle(){
    cout << " _____                    _             _   \n";
    cout << "|  ___|                  | |           | |  \n";
    cout << "| |      ___   _ __ ___  | |__    __ _ | |_ \n";
    cout << "| |     | _ | | '_ ` _   | '_ |  / _` || __|\n";
    cout << "| |___ | (_) || | | | | || |_)| | (_| || |_ \n";
    cout << "|_____| |___| |_| |_| |_||_.__/  -__,_||___|\n\n";
};



void Introduction(){
cout << "Welcome to xxxGenericGameTitlexxx! \n\n\n This game is a text adventure, which means you will continue the story by responding to the game with text or numbers.\n\n";
cout << "You were once a free man living with your family in a village far away from here.\n Then the army of Noxus demanded their selfimplemented taxes which your village could not afford\n";
cout << "being an old war veteran from the pantheon regiment, you knew that there is no arguing with Noxus without a cost.\n";
cout << " You made a deal with the general to turn yourself into a labourworker for noxus if it meant that they would not continue to bother village in the future, which the general smirked and agreed to.\n";
cout << "Fast forward to present and here you are in a prison cell next to creatures you have never seen in your life before, you dont even know how long you have been here\n\n\n";
};

int EnterAnyNumber(int &StoryChoice){
cout << "\n\nEnter any number";
cin >> StoryChoice;
return StoryChoice;
};


void SlaveKeeperReward1(int &StoryChoice, int &Ad, int &Armor){ // test på hur reward system kommer att se ut.
    
    cout << "The slave keeper acknowledges your potential and gives you two options. \nHe either gives you a shortsword, or a piece of armor \n1: Shortsword(+1Ad) \n2: Armorpiece(+1Armor)\n";
EnterAnyNumber(StoryChoice);
    if (StoryChoice == 1){
        Ad = Ad + 1;
        cout << "\nYou chose the shortsword!\n";
    } else if (StoryChoice == 2){
              Armor = Armor + 1;
        cout << "\nYou chose the armorpiece!\n";  
    }

};