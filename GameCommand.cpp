#include "GameCommand.h"
#include "Model.h"
#include "Pokemon.h"

using namespace std;

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1){
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id)) -> getName() << " to " << p1 << endl;
	model.GetPokemonPtr(pokemon_id) -> StartMoving(p1);
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id){
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id)) -> getName() << " to center " << center_id << endl;
	model.GetPokemonPtr(pokemon_id) -> StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id){
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id)) -> getName() << " to gym " << gym_id << endl;
	model.GetPokemonPtr(pokemon_id) -> Pokemon::StartMovingToGym(model.GetPokemonGymPtr(gym_id));
}

void DoStopCommand(Model& model, int pokemon_id){
	cout << "Stopping " << (model.GetPokemonPtr(pokemon_id)) -> getName() << endl;
	model.GetPokemonPtr(pokemon_id) -> Stop();
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units){
	cout << "Training " << (model.GetPokemonPtr(pokemon_id)) -> getName() << endl;
	model.GetPokemonPtr(pokemon_id) -> Pokemon::StartTraining(training_units);
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points){
	cout << "Recovering " << stamina_points << " for " << (model.GetPokemonPtr(pokemon_id)) -> getName() << endl;
	model.GetPokemonPtr(pokemon_id) -> StartRecoveringStamina(stamina_points);
	
}

void handleInput(char inputCommand, Model& Model1){
	
	if(inputCommand == 'q'){
			exit(0);
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
		
	}else if(inputCommand == 'g'){
			
			int id1;
			int id2;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id1;
			cout << "Enter Gym ID: " << endl;
			cin >> id2;
			
			DoMoveToGymCommand(Model1, id1, id2);
			
		
	}else if(inputCommand == 'c'){
			
			int id1; 
			int id2;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id1;
			cout << "Enter Center ID: " << endl;
			cin >> id2;
			
			DoMoveToCenterCommand(Model1, id1, id2);

			
	}else if(inputCommand == 's'){
			
			int id;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id;
			
			DoStopCommand(Model1, id);
			
			
	}else if(inputCommand == 'r'){
			
			int id1;
			int id2;
			unsigned int stamina_points;
			cout << "Enter Pokemon ID: " << endl;
			cin >> id1;
			cout << "Enter stamina points to recover: " << endl;
			cin >> stamina_points;
			
			DoRecoverInCenterCommand(Model1, id1, stamina_points);
			
	}else if(inputCommand == 't'){
			
			int id1;
			int id2;
			int unit_amount;
			
			cout << "Enter Pokemon ID: " << endl;
			cin >> id1;
			cout << "Enter training units: " << endl;
			cin >> unit_amount;
			
			DoTrainInGymCommand(Model1, id1, unit_amount);

			
	}else if(inputCommand == 'v'){
		
			cout << "Advancing one time step...." << endl;
			Model1.Update();

			
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

//void DoGoCommand(Model& model, View& view){
	
//void DoRunCommand(Model& model, View& view){
