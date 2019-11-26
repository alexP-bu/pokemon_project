#include "GameCommand.h"
#include "Model.h"
#include "Pokemon.h"

using namespace std;
//file for handling input as well as functions to do stuff

//move pokemon
void DoMoveCommand(Model& model, int pokemon_id, Point2D p1){
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id)) -> getName() << " to " << p1 << endl;
	model.GetPokemonPtr(pokemon_id) -> StartMoving(p1);
}
//move to center given id
void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id){
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id)) -> getName() << " to center " << center_id << endl;
	model.GetPokemonPtr(pokemon_id) -> StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
}
//move to gym given id
void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id){
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id)) -> getName() << " to gym " << gym_id << endl;
	model.GetPokemonPtr(pokemon_id) -> Pokemon::StartMovingToGym(model.GetPokemonGymPtr(gym_id));
}
//stop whatever pokemon is doing
void DoStopCommand(Model& model, int pokemon_id){
	cout << "Stopping " << (model.GetPokemonPtr(pokemon_id)) -> getName() << endl;
	model.GetPokemonPtr(pokemon_id) -> Stop();
}
//train pokemon in gym
void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units){
	cout << "Training " << (model.GetPokemonPtr(pokemon_id)) -> getName() << endl;
	model.GetPokemonPtr(pokemon_id) -> Pokemon::StartTraining(training_units);
}
//recover in center
void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points){
	cout << "Recovering " << stamina_points << " for " << (model.GetPokemonPtr(pokemon_id)) -> getName() << endl;
	model.GetPokemonPtr(pokemon_id) -> StartRecoveringStamina(stamina_points);
	
}
//function for handling usr input
void handleInput(char inputCommand, Model& Model1){
	//if they quit the program
	if(inputCommand == 'q'){
			cout << "Thanks for playing!" << endl;
			cout << "Thanks for playing!" << endl;
			cout << "Thanks for playing!" << endl;
			cout << "Thanks for playing!" << endl;
			cout << "Thanks for playing!" << endl;
			exit(0);
	//move command
	}else if(inputCommand == 'm'){
			
			int id;
			int x;
			int y;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id;
			cout << "Enter x value: " << endl;
			cin >> x;
			cout << "Enter y value: " << endl;
			cin >> y;
			Point2D Coordinate(x,y);
			
			DoMoveCommand(Model1, id, Coordinate);
	//move to gym command	
	}else if(inputCommand == 'g'){
			
			int id1;
			int id2;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id1;
			cout << "Enter Gym ID: " << endl;
			cin >> id2;
			
			DoMoveToGymCommand(Model1, id1, id2);
			
	//move to center command	
	}else if(inputCommand == 'c'){
			
			int id1; 
			int id2;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id1;
			cout << "Enter Center ID: " << endl;
			cin >> id2;
			
			DoMoveToCenterCommand(Model1, id1, id2);

	//stop command		
	}else if(inputCommand == 's'){
			
			int id;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id;
			
			DoStopCommand(Model1, id);
			
	//recover pokemon command		
	}else if(inputCommand == 'r'){
			
			int id1;
			int id2;
			unsigned int stamina_points;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id1;
			cout << "Enter stamina points to recover: " << endl;
			cin >> stamina_points;
			
			DoRecoverInCenterCommand(Model1, id1, stamina_points);
	//train command		
	}else if(inputCommand == 't'){
			
			int id1;
			int id2;
			int unit_amount;
			
			cout << "Enter Pokemon ID: " << endl;
			cin >> id1;
			cout << "Enter training units: " << endl;
			cin >> unit_amount;
			
			DoTrainInGymCommand(Model1, id1, unit_amount);

	//advance one step command		
	}else if(inputCommand == 'v'){
		
			cout << "Advancing one time step...." << endl;
			Model1.Update();

	//run 5 ticks or until Update returns true		
	}else if(inputCommand == 'x'){
		int counter = 0;
		cout << "Running.... " << endl;
		while((!(Model1.Update())) || (counter == 5)){
			Model1.Update();
			counter++;
		}
			
	}else{
			cout << "Error! Invalid code entered!" << endl;
	}
}

//functions for view
//void DoGoCommand(Model& model, View& view){
	
//void DoRunCommand(Model& model, View& view){
