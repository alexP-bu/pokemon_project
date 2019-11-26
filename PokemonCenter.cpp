#include "PokemonCenter.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

PokemonCenter::PokemonCenter(){
	display_code = 'C';
	stamina_capacity = 100;
	num_stamina_points_remaining = stamina_capacity;
	dollar_cost_per_stamina_point = 5;
	state = STAMINA_POINTS_AVAILABLE;
	cout << "PokemonCenter default constructed" << endl;
}
//CHECK DEFAULT VARS
PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc){
	id_num = in_id;
	display_code = 'C';
	location = in_loc;
	dollar_cost_per_stamina_point = stamina_cost;
	stamina_capacity = stamina_cap;
	num_stamina_points_remaining = stamina_capacity;
	state = STAMINA_POINTS_AVAILABLE;
	cout << "PokemonCenter constructed" << endl;
}

//functions
bool PokemonCenter::HasStaminaPoints(){
	if (num_stamina_points_remaining > 0){
		return true;
	}else{
		return false;
	}
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining(){
	return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget){
	int cost = GetDollarCost(stamina_points);
	if (cost > budget){
		return false;
	}else{
		return true;
	}
}
	
double PokemonCenter::GetDollarCost(unsigned int stamina_points){
	return stamina_points * dollar_cost_per_stamina_point;
}
	
	
unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed){
	if (num_stamina_points_remaining > points_needed){
		num_stamina_points_remaining -= points_needed;
		return points_needed;
	}else{
		return num_stamina_points_remaining;
		num_stamina_points_remaining = 0;
	}
}
//CHECK
bool PokemonCenter::Update(){
	if((num_stamina_points_remaining == 0) && (state != NO_STAMINA_POINTS_AVAILABLE)){
		state = NO_STAMINA_POINTS_AVAILABLE;
		display_code = 'c';
		cout << "PokemonCenter " << id_num << " has ran out of stamina points." << endl;
		return true;
	}else{
		return false;
	}
}

void PokemonCenter::ShowStatus(){
	cout << "Pokemon Center Status: " << endl;
	Building::ShowStatus();
	cout << "Pokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
	cout << "Pokemon Center " << id_num << " has " << num_stamina_points_remaining << " stamina points remaining." << endl;
}

PokemonCenter::~PokemonCenter(){
	cout << "Pokemon center destructed" << endl;
}