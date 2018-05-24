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
	
	pokemon1 = CreatePokemon(6, 15, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
	pokemon2 = CreatePokemon(9, 15, main.pokedex, main.moveList, main.slow, main.medFast, main.medSlow, main.fast);
	pokemon1.PrintPokemonInfo();
	pokemon2.PrintPokemonInfo();
	hello = DamageCalc(pokemon2,pokemon2.moves[0], pokemon1);
	cout<<hello<<endl;
	//cout<<pikachu.learnMoveLvl[14]<<endl;
	//cout<<main.moveList[0].nameInternal<<endl;
	




	
	return 0;
} 