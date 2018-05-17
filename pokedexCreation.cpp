#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Global DexCreation(Global source) //creates the pokedex
{
	
	ifstream file;
	file.open("textFiles/pokemon.txt");

	string line;

	if(file.is_open())
	{
		int count = 0;
		
		int index = 0, pokes = 0;
		Pokemon newPokemon;
		while(getline(file,line))
			{
				if(!line.find("["))
				{
					size_t fix= line.find("[");
					string output = line.substr(fix+1);
					output.pop_back();
					newPokemon.dexID = stoi(output);
				}
				if(!line.find("Name="))
				{
					size_t fix= line.find("=");
					string output = line.substr(fix+1);
					newPokemon.name = output;
				}
				if(!line.find("InternalName="))
				{
					size_t fix= line.find("=");
					string output = line.substr(fix+1);
					newPokemon.nameInternal = output;
				}
				if(!line.find("Type1="))
				{
					size_t fix= line.find("=");
					string output = line.substr(fix+1);
					newPokemon.type1 = output;
				}
				if(!line.find("Type2="))
				{
					size_t fix= line.find("=");
					string output = line.substr(fix+1);
					newPokemon.type2 = output;
				}
				if(!line.find("BaseStats="))
				{
					size_t fix= line.find("=");
					string output = line.substr(fix+1);
					stringstream iss;
					iss <<output;
					string data;
					int countN = 0;
					while(getline(iss,data,','))//assign the basestats for the pokemon
					{
						if(countN == 0)
						{
							newPokemon.stats.hpB = stoi(data);
						}
						if(countN == 1)
						{
							newPokemon.stats.attackB = stoi(data);
						}
						if(countN == 2)
						{
							newPokemon.stats.defenseB = stoi(data);
						}
						if(countN == 3)
						{
							newPokemon.stats.spAttackB = stoi(data);
						}
						if(countN == 4)
						{
							newPokemon.stats.spDefenseB = stoi(data);
						}
						if(countN == 5)
						{
							newPokemon.stats.speedB = stoi(data);
						}
						countN++;		
					}
				}
				if(!line.find("Moves="))
				{
					size_t fix= line.find("=");
					string output = line.substr(fix+1);
					stringstream iss;
					iss <<output;
					string data;
					int moveIndex=0, levelIndex=0, countN = 0;
					while(getline(iss,data,','))
					{
						if(countN%2==0) //level data
						{
							newPokemon.learnMoveLvl[levelIndex] = stoi(data);
							levelIndex++;

						}
						else //move data
						{
							newPokemon.learnMoveMove[moveIndex] = data;
							moveIndex++;
						}
						countN++;
					}

				}
				if(!line.find("Pokedex="))
				{
					size_t fix= line.find("=");
					string output = line.substr(fix+1);
					newPokemon.pokeDex = output;
				}
				if(!line.find("Evolutions="))
				{
					size_t fix= line.find("=");
					string output = line.substr(fix+1);
					stringstream iss;
					iss <<output;
					string data;
					int countN = 0;
					while(getline(iss,data,','))
					{
						if(countN ==0) //evolution
						{
							newPokemon.evolution = data;
						}
						if(countN ==1) //type
						{
							newPokemon.evolveType = data;
						}
						if(countN == 2) //lvl
						{
							newPokemon.evolveLvl = data;
						}
						countN++;
					}
				}
				
				if(!line.find("#--")) //create a new slot 
				{
					source.pokeDex[index] = newPokemon;
					index++;
					Pokemon newPokemon;
				}

			}
			
			
			

	}
	return source;
	

}