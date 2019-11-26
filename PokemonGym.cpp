#include "PokemonGym.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
//default constructor
//code is G, default values are 10,1,1.0,2
PokemonGym::PokemonGym(){
	display_code = 'G';
	state = NOT_BEATEN;
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1.0;
	experience_points_per_training_unit = 2;
	cout << "PokemonGym default constructed" << endl;
}
//CHECK DEFAULT MEMBER VARS
//checked! all works - set up a pokemon gym with input values
PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, 
					   double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc){
						   
	id_num = in_id;
	display_code = 'G';
	state = NOT_BEATEN;
	max_number_of_training_units = max_training_units;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = stamina_cost;
	dollar_cost_per_training_unit = dollar_cost;
	experience_points_per_training_unit = exp_points_per_unit;
	location = in_loc;
	//rest of member vars to default
	cout << "PokemonGym constrcuted" << endl;
}
//return dollar cost for training operation
double PokemonGym::GetDollarCost(unsigned int unit_qty){
	return unit_qty * dollar_cost_per_training_unit;
}
//return stamina cost for training operation
unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty){
	return unit_qty * stamina_cost_per_training_unit;
}
//return number of training points the gym has left
unsigned int PokemonGym::GetNumTrainingRemaining(){
	return num_training_units_remaining;
}

//can I afford to train there? based on budget
bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina){
	if ((GetDollarCost(unit_qty) <= budget) && (GetStaminaCost(unit_qty) <= stamina)){
		return true;
	}else{
		return false;
	}
}

//train pokemon 
unsigned int PokemonGym::TrainPokemon(unsigned int training_units){
	//if the gym has more training points than requested
	//subtract points from gym and add experience points
	if(num_training_units_remaining <= training_units){
		num_training_units_remaining -= training_units;
		return training_units * experience_points_per_training_unit;
	}else{
		//if the gym is going to run out of points, just use whats left
		return num_training_units_remaining * experience_points_per_training_unit;
		num_training_units_remaining = 0;
	}
}
//CHECK
//checked and works!
//checks if gym has been beaten or not - returns true one time as requested
bool PokemonGym::Update(){
	if((num_training_units_remaining == 0) && (state != BEATEN)){
		state = BEATEN;
		display_code = 'g';
		cout << display_code << " " << id_num << " has been beaten." << endl;
		return true;
	}else{
		return false;
	}
}
//if theres no more training units, the gym has been beaten
bool PokemonGym::IsBeaten(){
	if(num_training_units_remaining == 0){
		return true;
	}else{
		return false;
	}
}
//output hte status of a pokemon gym - useful for debugging
void PokemonGym::ShowStatus(){
	cout << "Pokemon Gym Status: " << endl;
	Building::ShowStatus();
	cout << "Max number of training units: " << max_number_of_training_units << endl;
	cout << "Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
	cout << "Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
	cout << "Experience points per training unit: " << experience_points_per_training_unit << endl;
	cout << num_training_units_remaining << " training unit(s) are remaining for this gym." << endl;
}
//destructor that doesnt actually do anything except print that stuff was destructed
PokemonGym::~PokemonGym(){
	cout << "PokemonGym destructed" << endl;
}