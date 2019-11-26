#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"

using namespace std;

class GameObject{
	//protected members
	protected:
	Point2D location;
	int id_num;
	char display_code;
	char state;
	//public members
	public:
	//PURE VIRTUAL FUCTIONS
	virtual bool ShouldBeVisible() = 0;
	virtual bool Update() = 0;
	//VIRTUAL FUNCTIONS
	virtual void ShowStatus();
	//constructors
	GameObject();
	GameObject(char);
	GameObject(Point2D, int, char);
	virtual ~GameObject();
	//functions
	Point2D GetLocation();
	int GetId();
	char GetState();
	//for view
	void DrawSelf(char*);
};

#endif