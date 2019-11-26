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
	cout << R"(
                                  ,'\
    _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                `'                            '-._|
                                )"
            << '\n';
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