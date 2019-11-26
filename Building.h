#ifndef BUILDING_H
#define BUILDING_H

#include "Point2D.h"
#include "GameObject.h"

using namespace std;

class Building : public GameObject{
	//private members
	private:
	unsigned int pokemon_count = 0;
	//public members
	public: 
	//constructors
	Building();
	Building(char, int, Point2D);
	//functions
	void AddOnePokemon();
	void RemoveOnePokemon();
	void ShowStatus();
	bool ShouldBeVisible();
};



#endif