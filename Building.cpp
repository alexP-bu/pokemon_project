#include "Building.h"

#include <iostream>
#include <string>
#include <cmath>


using namespace std;
//default constructor for any building in the game
Building::Building(){
	display_code = 'B';
	cout << "Building default constructed" << endl;
}
//given input values make a building
Building::Building(char in_code, int in_Id, Point2D in_loc){
	display_code = in_code;
	id_num = in_Id;
	location = in_loc;
	state = 0;
	cout << "Building constructed" << endl;
}
//public member functions
//add pokemon to building
void Building::AddOnePokemon(){
	pokemon_count += 1;
}
//subtract pokemon from building
void Building::RemoveOnePokemon(){
	pokemon_count -= 1;
}
//display how many pokemon are in the building
void Building::ShowStatus(){
	if (pokemon_count > 1){
		cout << pokemon_count << " pokemon are in this building" << endl;
	}else{
	cout << pokemon_count << " pokemon is in this building" << endl;
	}
}
//buildings should alwyas be visible!
bool Building::ShouldBeVisible(){
	//buildings always visible
	return true;
}