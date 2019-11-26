#include "Pokemon.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Vector2D.h"
#include "Point2D.h"

#include <iostream>
#include <string>
#include <cmath>
#include "stdlib.h"
#include "time.h"

using namespace std;

Pokemon::Pokemon(){
	speed = 5;
	display_code = 'P';
	cout << "Pokemon default constructed" << endl;
}

Pokemon::Pokemon(char in_code){
	speed = 5;
	state = STOPPED;
	display_code = in_code;
	cout << "Pokemon constructed" << endl;
}
//CHECK THIS ONE
Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc){
	speed = in_speed;
	name = in_name;
	id_num = in_id;
	display_code = in_code;
	location = in_loc;
	cout << "Pokemon is constructed" << endl;
}
void Pokemon::StartMoving(Point2D dest){
	SetupDestination(dest);
	if(GetDistanceBetween(location,dest) == 0){
		cout << display_code << id_num << ": I'm already there. See?" << endl;
	}else if(isExhausted() == true){
		cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
	}else{
		cout << display_code << id_num << ": On my way." << endl;
		state = MOVING;
	}
}

void Pokemon::StartMovingToCenter(PokemonCenter* center){
	
	SetupDestination(center -> GetLocation());
	
	if(isExhausted() == true){
		cout << display_code << id_num << " I am exhausted so I cant move to recover stamina..." << endl;
	}else if((GetDistanceBetween(location,center->GetLocation())) == 0){
		cout << display_code << id_num << " I am already at the Pokemon Center!" << endl;
	}else{
		cout << display_code << id_num << " on my way to center " << center -> GetId() << endl;
		state = MOVING_TO_CENTER;
	}
}

void Pokemon::StartMovingToGym(PokemonGym* gym){
	SetupDestination(gym -> GetLocation());
	if(isExhausted() == true){
		cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the gym..." << endl;
	}else if((GetDistanceBetween(location,(gym->GetLocation()))) == 0){
		cout << display_code << id_num << ": I am already at the Pokemon Gym!" << endl;
	}else{

		cout << display_code << id_num << ": on my way to gym " << gym -> GetId() << endl;
		//state = MOVING_TO_GYM;
	}
}

void Pokemon::StartTraining(unsigned int num_training_units){
	if(isExhausted() == true){
		cout << display_code << id_num << ": I am exhausted so no more training for me..." << endl;
	}else if(is_in_gym == false){
		cout << display_code << id_num << ": I can only train in a Pokemon Gym!" << endl;
	}else if(current_gym -> IsBeaten()){
		cout << display_code << id_num << ": Cannot train! This Pokemon Gym is already Beaten!" << endl;
	}else if((current_gym -> IsAbleToTrain(num_training_units, pokemon_dollars, stamina)) == false){
		cout << display_code << id_num << ": Not enough stamina and/or money for training." << endl;
	}else{
		cout << display_code << ": Started to train at Pokemon Gym" << 
							current_gym -> GetId() << " with " << num_training_units << " training units" << endl;
		state = TRAINING_IN_GYM;
		if(num_training_units > (current_gym -> GetNumTrainingRemaining())){
			training_units_to_buy = current_gym -> GetNumTrainingRemaining();
		}else{
			training_units_to_buy = num_training_units;
		}
	}
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points){
	if((current_center -> GetNumStaminaPointsRemaining()) < 1){
		cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center!" << endl;
	}else if(is_in_center == false){
		cout << display_code << id_num << ": Cannot recover! I can only recover stamina at a Pokemon Center!" << endl;
	}else if((current_center -> CanAffordStaminaPoints(num_stamina_points , pokemon_dollars)) == false){
		cout << display_code << id_num << ": Not enough money to recover stamina" << endl;
	}else{
	state = RECOVERING_STAMINA;
	cout << display_code << id_num << ": Started recovering " << num_stamina_points << " stamina point(s) at Pokemon Center " 
								<< current_center -> GetId() << endl;
	if(num_stamina_points > (current_center -> GetNumStaminaPointsRemaining())){
			stamina_units_to_buy = current_center -> GetNumStaminaPointsRemaining();
		}else{
			stamina_units_to_buy = num_stamina_points;
		} 							
	
	}
}

void Pokemon::Stop(){
	state = STOPPED;
	cout << display_code << id_num << ": Stopping..." << endl;
}

bool Pokemon::isExhausted(){
	if(stamina == 0){
		return true;
	}else{
		return false;
	}
}

bool Pokemon::ShouldBeVisible(){
	if(isExhausted() == true){
		return false;
	}else{
		return true;
	}
}
//REFER TO BEHAVE PART
void Pokemon::ShowStatus(){
	
	cout << name << " status: " << endl;
	GameObject::ShowStatus();
	
	switch(state){
		case 0:{
			cout << name << " is currently stopped" << endl;
			break;
		}case 1:{
			cout << name << " is currently moving at a speed of " << speed << " to destination " << destination.x << "," << destination.y 
				 << " in steps of " << delta << "." << endl;
				 break;
		}case 2:{
			cout << name << " is currently exhausted" << endl;
			break;
		}case 3:{
			cout << name << " is currently inside Pokemon Gym " << current_gym -> GetId() << endl;
			break;
		}case 4:{
			cout << name << " is currently inside Pokemon Center " << current_center -> GetId() << endl;
			break;
		}case 5:{
			cout << name << " is currently moving to Pokemon Gym" << current_gym -> GetId() << " at a speed of " << speed 
				 << " in steps of " << delta << "." << endl;
				 break;
		}case 6:{
			cout << name << " is currently moving to Pokemon Center" << current_center -> GetId() << " at a speed of " << speed 
				 << " in steps of " << delta << "." << endl;
				 break;
		}case 7:{
			cout << name << " is currently training in Pokemon Gym" << current_gym -> GetId() << endl;
			break;
		}case 8:{
			cout << name << " is currently recovering in Pokemon Center" << current_center -> GetId() << endl;
			break;
		}
	}
}
//REFER TO BEHAVE PART 
bool Pokemon::Update(){
	switch(state){
		case 0:{
			return false;
			ShowStatus();
			break;
		}case 1:{
			if(UpdateLocation() == true){
				state = 0;
				return true;
			}else{
				return false;
			}
			ShowStatus();
			break;
		}case 2: {
			return false;
		}case 3:{
			return false;
		}case 4:{
			return false;
		}case 5:{
			if(UpdateLocation() == true){
				state = 3;
				return true;
			}else{
				return false;
			}
			ShowStatus();
		}case 6:{
			if(UpdateLocation() == true){
				state = 4;
				return false;
			}else{
				return true;
			}
			break;
		}case 7:{
			int expGained = experience_points;
			
			stamina == current_gym -> GetStaminaCost(training_units_to_buy);
			pokemon_dollars -= current_gym -> GetDollarCost(training_units_to_buy);
			experience_points += current_gym -> TrainPokemon(training_units_to_buy);
			expGained = experience_points - expGained;
			
			cout << name << " completed " << training_units_to_buy << " training units!" << endl;
			cout << name << " gained " << expGained << " experience points!" << endl;
			
			state = 3;
			return true;
			ShowStatus();
			break;
		}case 8:{
			
		}
		
		cout << "Stamina: " << stamina << endl;
		cout << "Pokemon Dollars: " << pokemon_dollars << endl;
		cout << "Experience Points: " << experience_points << endl;
	}
	
}
//REFER TO MOVES
bool Pokemon::UpdateLocation(){
	if(((location.x - destination.x) <= 1) && ((location.y - destination.y) <= 1)){
		cout << display_code << " " << id_num << ": I'm there!" << endl;
		location = destination;
		return true;
	}else{
		pokemon_dollars = GetRandomAmountOfPokemonDollars();
		stamina--;
		location.x = location.x + delta.x;
		location.y = location.y + delta.y;
		cout << display_code << id_num << " step...";
		return false;
	}
	return false;
}
//REFER TO MOVES delta = (destination - location) * (speed/ GetDistanceBetween(destination, location))
void Pokemon::SetupDestination(Point2D dest){
	destination = dest;
	delta = (dest - location) * (speed / GetDistanceBetween(dest, location));
}

double GetRandomAmountOfPokemonDollars(){
	srand (time(NULL));
	return rand() % 3;
}

Pokemon::~Pokemon(){
	cout << "Pokemon destructed" << endl;
}

string Pokemon::getName(){
	return name;
}













































