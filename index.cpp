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
	
	main = CreateMoveList(main);
	main = DexCreation(main);
	
	
	//pokemon1 = CreatePokemon(6, 36, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
	for(int i =0; i<6; i++)
	{
		int id = rand() %150 + 1;
		Pokemon newPoke;
		newPoke = CreatePokemon(id, 36, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
		userTrainer = AssignTrainerPokemon(newPoke, userTrainer);
	}
	userTrainer.PrintTrainerInfo();
	// pokemon2 = CreatePokemon(9, 36, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
	// // pokemon1.PrintPokemonInfo();
	// // pokemon2.PrintPokemonInfo();
	// Battle(pokemon1,pokemon2);

	return 0;
} 