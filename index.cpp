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
	int hello = 7;
	Pokemon pokemon;
	
	main = CreateMoveList(main);
	main = DexCreation(main);
	main.SetExpRanges();
	pokemon = CreatePokemon(121, 15, main);
	pokemon.PrintPokemonInfo();
	//cout<<pikachu.learnMoveLvl[14]<<endl;
	//cout<<main.moveList[0].nameInternal<<endl;
	




	
	return 0;
} 