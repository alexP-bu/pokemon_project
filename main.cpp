#include "Model.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "GameCommand.h"

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(){
	//MODEL THE GAME
	Model Model1;
	//setup inputcommand 
	char inputCommand = ' ';
	//LOGO
    cout << "                              ,'\                            ";
cout << "    _.----.        ____         ,'  _\   ___    ___     ____     ";
cout << "_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.  ";
cout << "\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  | ";
cout << " \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  | ";
cout << "   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | ";
cout << "    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     | ";
cout << "     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    | ";
cout << "      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   | ";
cout << "       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   | ";
cout << "        \_.-'       |__|    `-._ |              '-.|     '-.| |   | ";
cout << "                               `'                            '-._| ";
cout << "                                                                   " ;                               
	while(inputCommand != 'q'){
		
		Model1.ShowStatus();
		
		cout << "Current time: " << Model1.getTime() << endl;
		
		cout << "Enter a command!" << endl;
		cout << "Commands include: m,g,c,s,r,t,v,x,q" << endl;
		cin >> inputCommand;
		handleInput(inputCommand, Model1);
		
	}
	cout << "Program has exited! Thanks for playing." << endl;
	return 0;
}