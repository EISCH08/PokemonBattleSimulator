#include <iostream>
#include "pokemon.h"
#include "pokedexCreation.cpp"
#include "moves.cpp"
#include "battle.cpp"
#include <string>

using namespace std;



int main(int argc, char const *argv[])
{	
	Global main;
	Pokemon pokemon1;
	Pokemon pokemon2;
	Trainer userTrainer;
	Trainer opponentTrainer;
	main = CreateMoveList(main);
	main = DexCreation(main);
	
	
	//pokemon1 = CreatePokemon(6, 36, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
	for(int i =0; i<4; i++)
	{
		int id = rand() %150 + 1;
		int id2 = rand() % 150 +1;
		Pokemon newPoke;
		newPoke = CreatePokemon(id2, 36, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
		userTrainer = AssignTrainerPokemon(newPoke, userTrainer);
		Pokemon newPoke2;
		newPoke2 = CreatePokemon(id, 36, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
		opponentTrainer = AssignTrainerPokemon(newPoke2, opponentTrainer);
	}
	// pokemon2 = CreatePokemon(9, 36, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
	// // pokemon1.PrintPokemonInfo();
	// // pokemon2.PrintPokemonInfo();
	cout<<userTrainer.NumberOfPokemon()<<endl;
	Battle(userTrainer,opponentTrainer);

	return 0;
} 