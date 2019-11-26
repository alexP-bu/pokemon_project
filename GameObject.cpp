#include "GameObject.h"

#include <iostream>
#include <string>
#include <cmath>
//default constructor for game objects
GameObject::GameObject(){
	display_code = ' ';
	id_num = 1;
	state = 0;
	
	cout << "Default GameObject constructed" << endl; 
}
//construct object given input
GameObject::GameObject(char in_code){
	display_code = in_code;
	id_num = 1;
	state = 0;
	
	cout << "GameObject constructed" << endl; 
}
//construct object given even more input
GameObject::GameObject(Point2D in_loc, int in_id, char in_code){
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	
	cout << "GameObject constructed" << endl;
}
//get location of an object
Point2D GameObject::GetLocation(){
	return location;
}
//get object id
int GameObject::GetId(){
	return id_num;
}
//get state of object
char GameObject::GetState(){
	return state;
}
//display info about object
void GameObject::ShowStatus(){
	cout << display_code << id_num << " at " << location << endl;
}
//destructor
GameObject::~GameObject(){
	cout << "GameObject destructed" << endl;
}
//for view
void GameObject::DrawSelf(char* ptr){
	*ptr = display_code;
}