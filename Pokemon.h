#ifndef POKEMON_H
#define POKEMON_H

#include <string>

#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Point2D.h"
#include "Vector2D.h"

using namespace std;

enum PokemonStates {
	STOPPED = 0,
	MOVING = 1,
	EXHAUSTED = 2,
	IN_GYM = 3,
	IN_CENTER = 4,
	MOVING_TO_GYM = 5,
	MOVING_TO_CENTER = 6,
	TRAINING_IN_GYM = 7,
	RECOVERING_STAMINA = 8
};


class Pokemon : public GameObject{
	protected: 
	//protected members
	bool UpdateLocation();
	void SetupDestination(Point2D);
	//private members
	private:
	
	double speed;
	bool is_in_gym = false;
	bool is_in_center = false;
	unsigned int stamina = 20;
	unsigned int experience_points = 0;
	double pokemon_dollars = 0;
	unsigned int training_units_to_buy = 0;
	unsigned int stamina_units_to_buy = 0;
	string name;
	PokemonCenter* current_center = NULL;
	PokemonGym* current_gym = NULL;
	Point2D destination;
	Vector2D delta;
	//public members
	public:
	//constructors
	Pokemon();
	Pokemon(char);
	Pokemon(string, int, char, unsigned int, Point2D);
	virtual ~Pokemon();
	//functions
	void StartMoving(Point2D);
	void StartMovingToCenter(PokemonCenter*);
	void StartMovingToGym(PokemonGym*);
	void StartTraining(unsigned int);
	void StartRecoveringStamina(unsigned int);
	void Stop();
	bool isExhausted();
	bool ShouldBeVisible();
	void ShowStatus();
	bool Update();
	
	//MY OWN FUNCTION TO GET NAME
	string getName();
	
};
//function to get $
double GetRandomAmountOfPokemonDollars();

#endif