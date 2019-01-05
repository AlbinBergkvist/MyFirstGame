#include <iostream>
#include <cmath>

using namespace std;

// Nu kan du skriva bara Combat istället för struct Combat
typedef struct Combat Combat; 
// New struct Combat
struct Combat {
  int yourhp;
  int enemyhp;
};


void combatinterface (int lives,string name,int enemyhp,string enemyname, int ad,int enemydamage){
 cout << ",_________________________________," <<                   			    ",_________________________________," << endl;
 cout << "|" << name <<"                                " <<          				            "|" << enemyname <<    "           " << endl;
 cout << "| HP" << lives <<   "                             " << 					"| HP" << enemyhp <<   "           " << endl;
 cout << "| AD" << ad <<                    "                    | " << enemydamage << endl;
 cout << "|_________________________________" << 									"|_________________________________" << endl;
}


void combatoptions (){
															cout << "1. Attack" << endl;
															cout << "2. Bandage wounds" << endl;
															cout << "3. Block incoming damage?" << endl;
															cout << "4. Focus energy "
}





Combat combatresults (int playermove,int enemyhp,int ad,int lives,int enemydamage,string enemyname){
	cin >> playermove;
	Combat result;												
																switch(playermove){
																	case 1 : enemyhp -= ad;
																		     lives -= enemydamage;
                                 									cout << "you hit the enemy" << endl;
																	cout << "-----------------" << endl;
																
																	result.yourhp = lives;
																	result.enemyhp = enemyhp;
																	return result;
																									break;
																									
																	case 2 : lives += 2;
																			lives -= enemydamage;
																			
																	result.yourhp = lives;
																	result.enemyhp = enemyhp;
																	
																			return result;
																							break;
																	case 3 : cout << "You succesfully blocked " << enemyname << "'s attack" << endl;
																	break;
																	}
}





void clear() {

    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}






// Koden för att avsluta spelet om du har förlågt hp efter combat
//if (lives <=0){
//	cout << "You lost all health" << endl;
//	cout << "GamesOver";
//return 0;
//}





int main() 
{

string enemyname;

int lives = 5;
string name;
int ad = 1;
int enemydamage;












cout << "---------------------" << endl;
cout << "hello traveler welcome to the game" << endl;
cout <<"What is your name?" << endl;



getline (cin, name);

cout << "---------------------" << endl;
cout << name << " what a fine name" << endl;
cout << "In this game to continue the story you have 3 options. 1,2 or 3" << endl;
cout << " The inkeeper will give you a quest's and tasks for you to do and it's up to you to decide if you are up for it" << endl;
cout << "Do you understand? " << endl;


cout << " 1. yes" <<endl;
cout << " 2. maybe" <<endl;
cout << " 3. no " <<endl;
cout << "---------------------" << endl;



int answer;
cin >> answer;

if (answer == 1){
cout << " Good" << endl;

}else if (answer ==2) {
	cout << "Dont worry you will learn as you play" << endl;
}


else if (answer == 3)
{
	cout << "Nevermind then I thought you were smarter than this" << endl;
	cout << "GAMEOVER";
	return 0;
}

cout << "You continue to talk with the inkeeper" << endl;
cout << "1. Be friendly" << endl;
cout << "2. mock the inkeeper" << endl;
cout << "3. Fight the inkeeper" << endl;
cout << "---------------------" << endl;
cin >> answer;

if (answer == 1){
	cout << " You continue to banter with the man who gives you another round on the house " << endl;
}	else if (answer ==2){
	cout << "The inkeeper hits you in the head with glass " << endl;
	lives -= 1;
	cout << " you have" << lives << " lives left";
} 	else if (answer ==3){
	cout << "you are no match for the inkeeper who throws you out of the building" << endl;
	cout << "GAMEOVER";
	return 0;
}
cout << "-------------------------" << endl;
cout << " After a while of talking with the inkeeper a disguised man makes his way through the door " << endl;
cout << " He makes it very clear he wants to fight" << endl;



cout << "1. Confront the man " << endl;
cout << "2. Mind your own business" << endl;

// Första Fight encounter med två if-statements i varandra, borde testa switch statements


enemyname = "Disguised Man";
int enemyhp = 3;
int playermove;
enemydamage = 1;

cin >> answer;
if (answer == 1){
	cout << " You decide to teach the man some manners " << endl;
while(enemyhp&&lives > 0){
	    
		combatinterface(lives,name,enemyhp,enemyname,ad,enemydamage);
		cout << "1. Attack" << endl;
		cout << "2. idk yet" << endl;
		cin >> playermove;
								if (playermove == 1){
									enemyhp -= ad;
									lives -= enemydamage;
                                 cout << "You hit the enemy" << endl;
								 cout << "-----------------" << endl;


								}


}



}	else if (answer ==2){
	cout << " You continue to drink while hearing another man arguing with the disguised man" << endl;

}
	
// Funktion för att titta om ditt hp är 0 lr mindre, eftersom combaten avslutas när antingen ditt eller enemy hp är <= 0
// man kan inte sätta return 0 i funktionen lr något som får spelet att avslutas? så jag skriver bara ut den här koden efter varje combat.
if (lives <=0){
	cout << "You lost all health" << endl;
	cout << "GamesOver";
return 0;
}

clear();











	cout << "Suddenly a cat jumps up and looks at the food you are eating with big begging eyes " << endl;
	cout << "You who have waited the whole week for this meal, will you share it with this creature? " << endl;
	cout << "1. Yes" << endl;
	cout << "2. no" << endl;
int option;
cin >> option;

     // Första switch-statements, kommer nog antagligen få använda samma sätt dock i combaten med två i varandra


	switch(option){
		case 1 : cout << "You throw the cat a bite of your chicken hoping it will satisfy him" << endl;

		break;
		case 2 : cout << "The cat walks away searching for a kindhearted person to feed him" << endl;
				
		break;
	}

// Min idee är att man skriver statsen för varje encounter innan lr så gör man statsen ibörjan med olika namn, men om man gör det innan varje encounter så 
// kan man återanvända funktionen för combat utan att behöva ändra i den.

cout << " On the way home from the bar you get ambushed by a goblin that threatens you with a knife demanding all your gold" << endl;
cout << "1. Fight for your money" << endl;
cout << "2. idk yet" << endl;
enemyhp = 3;
enemyname = "Goblin";
enemydamage = 1;

cin >> option;


	switch(option){
		case 1 : cout << "You swat the knife out of the goblins hand and you two get into a fistfight GachiGasm" << endl;

											while(enemyhp&&lives > 0){
												
												combatinterface(lives,name,enemyhp,enemyname,ad);
												combatoptions();
												Combat result = combatresults(playermove,enemyhp,ad,lives,enemydamage,enemyname);
												lives = result.yourhp;
												enemyhp = result.enemyhp;
//Lyckades få allt i combaten att bli functions O.O dock så fungerar inte combaten, functionen verkar inte ändra på siffrorna.
//Jag tror det kan vara för att man "ger" 3:e fucnktionen värderna från utanför funktionen och då räknas de som konstanter? tex lives.
}


		break;
		case 2 : cout << "alternativ 2";
		break;
	}

if (lives <=0){
	cout << "You lost all health" << endl;
	cout << "GamesOver";
return 0;
}



	cout << "You beat the goblin and he runs away into the shadows" << endl;
	cout << "You see something shiny on the ground and quickly realize that he left his Dagger behind" << endl;
	cout << "1. Pick it up" << endl;
	cout << "2. Leave it be" << endl;

















	return 0;
}