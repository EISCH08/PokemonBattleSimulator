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
	double hello = 7;
	Pokemon pokemon1;
	Pokemon pokemon2;
	
	main = CreateMoveList(main);
	main = DexCreation(main);
	
	pokemon1 = CreatePokemon(6, 35, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
	pokemon2 = CreatePokemon(1, 30, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
	// for(int i=0; i<4; i++)
	// {
	// 	cout<<DamageCalc(pokemon1,pokemon1.moves[i], pokemon2)<<endl;
	// }
	//pokemon1.PrintPokemonInfo();
	//pokemon2.PrintPokemonInfo();
	Battle(pokemon1,pokemon2);

	return 0;
} 