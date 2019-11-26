#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "Model.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

Model::Model(){
	time = 0;
	
	pokemon_ptrs[0] = new Pokemon(string("Pikachu"), 1, 'P', 2, Point2D (5,1));
	pokemon_ptrs[1] = new Pokemon(string("Bulbasaur"), 2, 'P', 1, Point2D (10,1));
	center_ptrs[0] = new PokemonCenter(1, 1, 100, Point2D (1,20));
	center_ptrs[1] = new PokemonCenter(2, 2, 200, Point2D (10,20));
	gym_ptrs[0] = new PokemonGym();
	gym_ptrs[1] = new PokemonGym(10, 1, 1.0, 2, 1, Point2D (5,5));
	
	object_ptrs[0] = pokemon_ptrs[0];
	object_ptrs[1] = pokemon_ptrs[1];
	object_ptrs[2] = center_ptrs[0];
	object_ptrs[3] = center_ptrs[1];
	object_ptrs[4] = gym_ptrs[0];
	object_ptrs[5] = gym_ptrs[1];
	
	num_objects = 6;
	num_pokemon = 2;
	num_centers = 2;
	num_gyms = 2;
	
	cout << "Model default constructed" << endl;
}

Model::~Model(){
	for (int i = 0; i < 5; i++){
		delete object_ptrs[i];
	}
	
	cout << "GameObject destrcuted" << endl;
}

Pokemon* Model::GetPokemonPtr(int id){
	return pokemon_ptrs[id-1];
}

PokemonCenter* Model::GetPokemonCenterPtr(int id){
	return center_ptrs[id-1];
}

PokemonGym* Model::GetPokemonGymPtr(int id){
	return gym_ptrs[id-1];
}


bool Model::Update(){
	time++;
	bool tempStore = false;
	for (int i = 0; i < 5; i++){
		object_ptrs[i] -> Update();
		if(object_ptrs[i] -> Update()){
			tempStore = true;
		}
	}
	
	if((gym_ptrs[0] -> IsBeaten()) && (gym_ptrs[1] -> IsBeaten())){
		cout << "GAME OVER: You Win! All Pokemon Gyms beaten!" << endl;
		exit(EXIT_SUCCESS);
	}
	
	if((pokemon_ptrs[0] -> isExhausted()) && (pokemon_ptrs[1] -> isExhausted())){
		cout << "GAME OVER: You  lose! All of your Pokemon are tired!" << endl; 
		exit(EXIT_FAILURE);
	}
	
	return tempStore;
}
//void Display(View& view)

void Model::ShowStatus(){
	for(int i = 0; i < 5; i++){
		//object_ptrs[i] -> ShowStatus();
	}
}

int Model::getTime(){
	return time;
}