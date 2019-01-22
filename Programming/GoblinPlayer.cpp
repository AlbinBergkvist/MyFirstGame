// This awesome game was created by me Albin!

#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
using namespace std;
void ClearScreen();
void CombatEndTurn();
void CombatTitle();
void Introduction(int &StoryChoice);
int EnterAnyNumber(int &StoryChoice);
void SlaveKeeperReward1(int &StoryChoice, int &Ad, int &Armor);






class weapon{
    public:
    string Name;
    int WeaponDamage;
    void WeaponSwitch(int &Ad, int WeaponDamage, int &CurrentWeaponDamage, string &CurrentWeaponName, string &WeaponName){
   Ad = WeaponDamage - CurrentWeaponDamage + Ad;
   CurrentWeaponDamage = WeaponDamage;
   CurrentWeaponName = WeaponName;
    }
};

class dagger : public weapon{
    public:
    string WeaponName = "Dagger";
    int WeaponDamage = 2;
 
};

class axe : public weapon{
    public:
    string WeaponName = "Axe";
    int WeaponDamage = 4;
   //Axe.WeaponSwitch(Hero.Ad, Axe.WeaponDamage, Hero.CurrentWeaponDamage, Hero.CurrentWeaponName, Axe.WeaponName);
};




class shield{
    public:
    string Name;
    int ShieldArmor;

    shield(int ShieldArmor){ 
        
        
        this->ShieldArmor = ShieldArmor;
    }
};




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

    hero() : organism(100, 0, 10){
        Name = "Hero";}
    
    int Strength = 1;
    int Agility = 1;
    int Stamina = 1;
    int Intelligence = 1;

    int CurrentWeaponDamage = 0;
    string CurrentWeaponName = "Fists"; 
    int MaxHp = Hp;
    int PotionHealing = 5;

    int AdDamageTaken(int EnemyAd){
        Hp = Hp + Armor - EnemyAd;
    }

    void CombatOptions(){
        cout << "\n\n\n\nWhat will you do? \n\n 1: Attack \n 2: Search in your Inventory\n 3: Run\n\n";
    }

    string CheckAlive(){
        if (Hp <= 0){
            cout << "GameOver \n You lost all your health";
            return "Dead";
        } else{
            return "Alive"; }
    };

    int CombatHeroTurn(int &PlayerMove, int &StoryChoice){
        
        cin >> PlayerMove;
        if (PlayerMove ==1){
            ClearScreen();
            CombatTitle();
            cout << "You attack";
        } else if (PlayerMove ==2){
            ClearScreen();
            CombatTitle();
           HeroInventory(StoryChoice, InventorySlot);
        }else{
            ClearScreen();
            CombatTitle();
            cout << "You flinched and did not do anything\n(Wrong input)\n\n";
        }
    }

    int InventorySlot[10] = {5, 1};
    void HeroInventory(int &StoryChoice, int InventorySlot[]){
        cout << "---INVENTORY---\n\n\n";
        cout << "1. Health potions: " << InventorySlot[0];
        cout << "\n2. Scroll of fireball" << InventorySlot[1];
        EnterAnyNumber(StoryChoice);
        ClearScreen();
        CombatTitle();

        if (StoryChoice == 1 && InventorySlot[0] > 0){
            if (MaxHp >= Hp + PotionHealing){
                cout << "You healed\n\n";
                Hp = Hp + PotionHealing;
                InventorySlot[0] = InventorySlot[0] - 1;
                }else{
                    Hp = MaxHp;
                    cout << "You healed\n\n";
                    InventorySlot[0] = InventorySlot[0] - 1;
                }
        }else if (StoryChoice == 1){
            cout << "You searched for health potions when u had none left\n\n";
        }else if (StoryChoice == 2){
            cout << " You cast a fireball\n\n";
        }
    }


   void Training(int &StoryChoice){
    int TrainingPoints = 5;
    
    while(TrainingPoints>0){
    cout << "Training points available: " << TrainingPoints << "\n\n";
    TrainingInterface();
    EnterAnyNumber(StoryChoice);
    switch (StoryChoice){
    case 1:
        ClearScreen();

        cout << "Training ur strength\n\n";
        TrainingPoints = TrainingPoints - 1;
        Strength ++;
        Ad ++;
        break;
    
    case 2:
        ClearScreen();
       cout << "Training agility\n\n";
       TrainingPoints = TrainingPoints - 1;
       Agility++;
       break;

    case 3:
         ClearScreen();
       cout << "Training Stamina\n\n";
       TrainingPoints = TrainingPoints - 1;
       Stamina++;
       MaxHp = MaxHp + 4;
       break;

    case 4:
        ClearScreen();
        cout << "Training Intelligence\n\n";
        TrainingPoints = TrainingPoints - 1;
        Intelligence++;
        break;

    case 5:
        ClearScreen();
        cout << "You rest and eat mcdonalds to regain ur hp\n\n";
        TrainingPoints = TrainingPoints - 1;
        Hp = MaxHp;
    };
    }
    ClearScreen();
        };

    void TrainingInterface(){
        cout << "---Hero Attributes---\n\n\n";
        cout << "1: Strength " << Strength << "  (increases the physical damage you deal)" << endl; 
        cout << "2: Agility "  << Agility << "   (icreases the chance of dodging an attack)" << endl;
        cout << "3: Stamina " << Stamina << "   (icreases your max Hp)" << endl;
        cout << "4: Intelligence " << Intelligence << "   (Increases your magic power and potion effectivness)" << endl;
        cout << "5: Rest " << " (Heal up to full Hp)" << endl;
    };
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

    int CombatOrcTurn(int &PlayerMove, hero &Hero, int OrcDescision){
        if (PlayerMove == 1){
            cout << " and deal " << Hero.Ad - Armor << " damage!\n\n"; 
            AdDamageTaken(Hero.Ad);}


        // Orc´s turn to dish out the pain :)
        if ((OrcDescision - Hero.Agility) > 90){ // critical strike
            Hero.AdDamageTaken(Ad*2);
            cout << "The " << Name << " hits you for " << Ad*2 - Hero.Armor << " critical damage!\n\n";}
        else if ((OrcDescision  - Hero.Agility) > 50){ //Normal Attack
            Hero.AdDamageTaken(Ad);
            cout << "The " << Name << " hits you for " << Ad - Hero.Armor << " damage!\n\n";}
        else{ // Attack miss
            cout << "The " << Name << " misses\n\n";
        }
    }
};

class slave : public monster{
        public:
            slave() : monster(5, 0, 1){
                Name = "Slave";
            }
    int CombatSlaveTurn(int &PlayerMove, hero &Hero, int SlaveDescision){
           if (PlayerMove == 1){
            cout << " and deal " << Hero.Ad - Armor << " damage!\n\n"; 
            AdDamageTaken(Hero.Ad);}


        // Slave's turn to dish out the pain :)
        if ((SlaveDescision  - Hero.Agility)> 90){ // critical strike
            Hero.AdDamageTaken(Ad*2);
            cout << "The " << Name << " hits you for " << Ad*2 - Hero.Armor << " critical damage!\n\n";}
        else if ((SlaveDescision  - Hero.Agility) > 50){ //Normal Attack
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
dagger Dagger;
axe Axe;
default_random_engine randomGenerator(time(NULL));
uniform_int_distribution<int> Random100(1,100);
Random100(randomGenerator);


///////////////////////////////////////////////////// introduction text.
Introduction(StoryChoice); // flyttat in alla clearscreen funktioner och enter any number i introduction funktionen
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////


while(Hero.Hp > 0 && Orc.Hp > 0){ //Första Fight med Orc och en "check alive" innuti while funktionen, Detta är modellen för alla future fights! (exkluderat tilläggs grejer)
CombatTitle();
Hero.CombatInterface();
Orc.CombatInterface();
Hero.CombatOptions();
Hero.CombatHeroTurn(PlayerMove, StoryChoice);
Orc.CombatOrcTurn(PlayerMove, Hero, Random100(randomGenerator));
CombatEndTurn();
if (Hero.CheckAlive()== "Dead"){
    return 0;}
}




cout << "\n\nYou won the fight versus the orc \n";
EnterAnyNumber(StoryChoice);



SlaveKeeperReward1(StoryChoice, Hero.Ad, Hero.Armor); // fixat så att clearscreen funktionerna finns inuti Reward funktionen för att göra mindre text i main funktionen


while(Hero.Hp > 0 && Slave.Hp > 0){ //Första Fight med Slave efter reward system, far att titta att Rewarded har lagt till.
CombatTitle();
Hero.CombatInterface();
Slave.CombatInterface();
Hero.CombatOptions();
Hero.CombatHeroTurn(PlayerMove, StoryChoice);
Slave.CombatSlaveTurn(PlayerMove, Hero, Random100(randomGenerator));
CombatEndTurn();
if (Hero.CheckAlive()== "Dead"){
    return 0;}
}


cout << "\n\nYou won the fight versus the slave \n";
EnterAnyNumber(StoryChoice);
ClearScreen();
Hero.Training(StoryChoice);

cout  << Hero.MaxHp;



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



void Introduction(int &StoryChoice){
ClearScreen();
cout << "Welcome to xxxGenericGameTitlexxx! \n\n\n This game is a text adventure, which means you will continue the story by responding to the game with text or numbers.\n\n";
cout << "You were once a free man living with your family in a village far away from here.\nThen the army of Noxus demanded tributes for the new arena-championships, not in gold but in men.\n";
cout << "Being an old war veteran from the pantheon regiment, you knew that there is no arguing with Noxus and also that there would probably be no returning back.\n";
cout << "You made a deal with the general to turn yourself in if it meant that they would not continue to bother village in the future, which the general smirked and agreed to.\n";
cout << "Fast forward to present and here you are in a prison cell next to creatures you have never seen in your life before, you dont even know how long you have been here\n\n\n";
EnterAnyNumber(StoryChoice);
ClearScreen();
};



int EnterAnyNumber(int &StoryChoice){
cout << "\n\nEnter any number";
cin >> StoryChoice;
return StoryChoice;
};


void SlaveKeeperReward1(int &StoryChoice, int &Ad, int &Armor){ // test på hur reward system kommer att se ut.
    ClearScreen();
    cout << "The slave keeper acknowledges your potential and gives you two options. \nHe either gives you a shortsword, or a piece of armor \n1: Shortsword(+1Ad) \n2: Armorpiece(+1Armor)\n";
EnterAnyNumber(StoryChoice);
    if (StoryChoice == 1){
        Ad = Ad + 1;
         ClearScreen();
        cout << "\nYou chose the shortsword!\n";
    } else if (StoryChoice == 2){
              Armor = Armor + 1;
               ClearScreen();
        cout << "\nYou chose the armorpiece!\n";  
    } else {
        ClearScreen();
        cout << "The slave keeper gets tired of your nonesense and decides to give the reward to another gladiator";
    }
    EnterAnyNumber(StoryChoice);
    ClearScreen();
};