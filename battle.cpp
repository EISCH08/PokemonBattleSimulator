#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;




Pokemon CreatePokemon(int ID, int level, Pokemon pokedex[], Move moveList[], int slow[], int medFast[], int medSlow[], int fast[])//creates a pokemon based off of the pokedex id
{
	Pokemon newPokemon = pokedex[ID-1]; //get the right index related to pokedex #
	newPokemon.stats.level = level;
	newPokemon.SetIVs();
	newPokemon.SetStats();
	newPokemon.SetExp(source.slow, source.medFast, source.medSlow, source.fast);
	newPokemon.AssignMoves(moveList);

	return newPokemon;
}


double EffectivenessCalc(string moveType, Pokemon pokemon)
{
	string type1 = pokemon.type1;
	string type2 = pokemon.type2;
	string superEffective, notVeryEffective,immune;

	//calculates the effectiveness of each type to the pokemon its attacking
	if(moveType == "NORMAL")
	{
		superEffective = "";
		notVeryEffective ="ROCK, STEEL";
		immune = "GHOST";
	}
	if(moveType == "FIGHTING")
	{
		superEffective = "NORMAL, STEEL, ROCK, ICE, DARK";
		notVeryEffective ="FLYING, POISON, BUG, PSYCHIC, FAIRY";
		immune = "GHOST";
	}
	if(moveType == "FLYING")
	{
		superEffective = "FIGHTING, BUG, GRASS";
		notVeryEffective ="ROCK, STEEL,ELECTRIC";
		immune = "";
	}
	if(moveType == "POISON")
	{
		superEffective = "GRASS, FAIRY";
		notVeryEffective ="POISON,ROCK,GROUND,GHOST";
		immune = "STEEL";
	}
	if(moveType == "GROUND")
	{
		superEffective = "POISON,FIRE,ROCK,STEEL,ELECTRIC";
		notVeryEffective ="BUG,GRASS";
		immune = "FLYING";
	}
	if(moveType == "GRASS")
	{
		superEffective = "GROUND,ROCK,WATER";
		notVeryEffective ="BUG,DRAGON,FIRE,FLYING,GRASS, POISON,STEEL";
		immune = "";
	}
	if(moveType == "FIRE")
	{
		superEffective = "BUG,GRASS,STEEL,ICE";
		notVeryEffective ="FIRE,ROCK,WATER,DRAGON";
		immune = "";
	}
	if(moveType == "WATER")
	{
		superEffective = "FIRE,GROUND,ROCK";
		notVeryEffective ="GRASS,WATER,DRAGON";
		immune = "";
	}
	if(moveType == "BUG")
	{
		superEffective = "PSYCHIC,GRASS,DARK";
		notVeryEffective ="FIRE,FIGHTING,FLYING,GHOST,POISON,STEEL,FAIRY";
		immune = "";
	}
	if(moveType == "ELECTRIC")
	{
		superEffective = "FLYING, WATER";
		notVeryEffective ="DRAGON,ELECTRIC,GRASS";
		immune = "GROUND";
	}
	if(moveType == "ROCK")
	{
		superEffective = "BUG,FIRE,FLYING,ICE";
		notVeryEffective ="FIGHTING,GROUND,STEEL";
		immune = "";
	}
	if(moveType == "DARK")
	{
		superEffective = "PSYCHIC,GHOST";
		notVeryEffective ="DARK,FAIRY,FIGHTING";
		immune = "";
	}
	if(moveType == "FAIRY")
	{
		superEffective = "DARK,DRAGON,FIGHTING";
		notVeryEffective ="FIRE,POISON,STEEL";
		immune = "";
	}
	if(moveType == "STEEL")
	{
		superEffective = "FAIRY,ICE,ROCK";
		notVeryEffective ="ELECTRIC,FIRE,STEEL,WATER";
		immune = "";
	}
	if(moveType == "DRAGON")
	{
		superEffective = "DRAGON";
		notVeryEffective ="STEEL";
		immune = "FAIRY";
	}
	if(moveType == "GHOST")
	{
		superEffective = "GHOST,PSYCHIC";
		notVeryEffective ="DARK";
		immune = "NORMAL";
	}
	if(moveType == "ICE")
	{
		superEffective = "DRAGON,FLYING,GRASS,GROUND";
		notVeryEffective ="FIRE,ICE,STEEL,WATER";
		immune = "";
	}
	if(moveType == "PSYCHIC")
	{
		superEffective = "FIGHTING,POISON";
		notVeryEffective ="PSYCHIC,STEEL";
		immune = "DARK";
	}

	double effectiveness =1.0;
	//check to see if pokemons types are effected by the move

	if(!superEffective.find(type1) || !superEffective.find(type2))
	{
		
		if(superEffective.find(type1)!=string::npos && superEffective.find(type2)!=string::npos)//both types are super effective
		{
			effectiveness*=4;
		}
		else
		{
			effectiveness*=2;
		}
	}
	if(notVeryEffective.find(type1)!=string::npos || notVeryEffective.find(type2)!=string::npos)
	{
		if(notVeryEffective.find(type1)!=string::npos && notVeryEffective.find(type2)!=string::npos)//both types are super effective
		{
			effectiveness*=.25;
		}
		else
		{
			effectiveness*=.5;
		}
	}
	if(immune.find(type1)!=string::npos || immune.find(type2)!=string::npos)
	{
		effectiveness =0;
	}
	return effectiveness;

}
double STABCalc(string moveType, Pokemon pokemon)
{
	if(pokemon.type1 == moveType || pokemon.type2 == moveType)
	{
		return 1.5;
	}
	else
	{
		return 1;
	}
}



double DamageCalc(Pokemon attPoke, Move move, Pokemon defPoke)
{
	int level = attPoke.stats.level;
	int power = move.power;
	int attack = attPoke.stats.attack;
	int spAttack = attPoke.stats.spAttack;
	int defense = defPoke.stats.defense;
	int spDefense = defPoke.stats.spDefense;
	int rainy=1, sunny=1, critical=1, burned=1;
	double type =1, modifier =1, STAB=1, random = (((rand() % 15) +85)),damage;
	random =random /100;
	STAB = STABCalc(move.type, attPoke);
	type = EffectivenessCalc(move.type, defPoke);
	modifier = rainy * sunny * critical * burned * STAB * type;
	// cout<<power<<endl;
	// cout<<STAB<<endl;
	// cout<<random<<endl;
	// cout<<type<<endl;

	if(move.category == 0) //physical move
	{
		damage = ((2*level)/5)+2;
		damage = damage * power * (attack/defense);
		damage = (damage /50)+2;
		damage = damage * modifier;
		damage = ceil(damage);
	}
	if(move.category == 1) //special move
	{
		damage = ((2*level)/5)+2;
		damage = damage * power * (spAttack/spDefense);
		damage = (damage /50)+2;
		damage = damage * modifier;
		damage = ceil(damage);
	}
	if(move.category == 2) //self move
	{
		damage =0;
	}
	return damage;
}


Move OpponentBattleAI(Pokemon pokemon1, Pokemon pokemon2, string trainerClass,int turn)//the AI on determining what the AI does in battle
{
	//fill
}

void BattleUI(Pokemon pokemon1, Pokemon pokemon2,int pageState) //prints the UI for the battle
{
	cout<<pokemon2.nameInternal<<" Lv"<<pokemon2.stats.level<<endl<<"HP:"<<pokemon2.stats.hpCur<<"/"<<pokemon2.stats.hp<<endl; 
	cout<<endl<<endl<<endl;

	cout<<"					"<<pokemon1.nameInternal<<" Lv"<<pokemon1.stats.level<<endl<<"					HP:"<<pokemon1.stats.hpCur<<"/"<<pokemon1.stats.hp<<endl<<endl;
	bool mainBattlePage = false, fightPage =false,pokemonPage =false, bagPage =false, runText = false;
	if(pageState ==0) //mainBattlePage
	{
	
		mainBattlePage = true;

	}
	if(pageState ==1) //fightPage
	{
	
		fightPage = true;

	}
	if(pageState ==2) //PokemonPage
	{
		pokemonPage =true;

	}
	if(pageState ==3) //BagPage
	{
		bagPage = true;

	}
	if(pageState ==4) //RunText
	{
		runText = true;
	}

	
	if(mainBattlePage)
	{
		cout<<"What will "<<pokemon1.nameInternal<<" do?"<<endl;
		cout<<"1:FIGHT 			2:BAG"<<endl<<"3:POKEMON  		    4:RUN"<<endl;
	}
	else if(fightPage) //list all of the party pokemon
	{
		cout<<"				MOVES"<<endl;
		cout<<"1:"<<pokemon1.moves[0].nameInternal<<" PP: "<<pokemon1.moves[0].ppCur<<"/"<<pokemon1.moves[0].pp<<"  TYPE/"<<pokemon1.moves[0].type<<endl;
		cout<<"2:"<<pokemon1.moves[1].nameInternal<<" PP: "<<pokemon1.moves[1].ppCur<<"/"<<pokemon1.moves[1].pp<<"  TYPE/"<<pokemon1.moves[1].type<<endl;
		cout<<"3:"<<pokemon1.moves[2].nameInternal<<" PP: "<<pokemon1.moves[2].ppCur<<"/"<<pokemon1.moves[2].pp<<"  TYPE/"<<pokemon1.moves[2].type<<endl;
		cout<<"4:"<<pokemon1.moves[3].nameInternal<<" PP: "<<pokemon1.moves[3].ppCur<<"/"<<pokemon1.moves[3].pp<<"  TYPE/"<<pokemon1.moves[3].type<<endl;
		cout<<"5:BACK"<<endl;


	}
	else if(pokemonPage) //list all of the party pokemon
	{
		cout<<"Work in progress"<<endl;
	}
	else if(bagPage) //list all of the party pokemon
	{
		cout<<"Work in progress"<<endl;
	}
	
}

void Battle(Pokemon pokemon1, Pokemon pokemon2) //the battle environment (trainer battle atm)
{
	bool run = false,first =false; //trainer decides to run
	BattleUI(pokemon1,pokemon2,0);
	if(pokemon1.stats.speed > pokemon2.stats.speed) //decide which pokemon gets to move first
		{
			first = true;
		}
		else if(pokemon1.stats.speed < pokemon2.stats.speed)
		{
			first = false; //other pokemon moves first
		}
		else //speed tie
		{
			int chance = (rand() %10);
			if(chance<6)
			{
				first = true;
			}
			else
			{
				first = false;
			}
		}
		int userInput;
		cin>>userInput;
	while((pokemon1.stats.hpCur > 0 && pokemon2.stats.hpCur >0) && run !=true) //while both pokemon are alive
	{
		bool first = true; //user pokemone goes first
		

		switch(userInput)
		{
			case 1: //fight UI
			BattleUI(pokemon1,pokemon2,userInput);
			int moveNum;
			cin>>moveNum;
			switch(moveNum)
			{
				case 1:
				cout<<pokemon1.name<<" USED "<<pokemon1.moves[moveNum-1].nameInternal<<endl;
				pokemon2.stats.hpCur -= DamageCalc(pokemon1, pokemon1.moves[moveNum-1], pokemon2);
				break;

				case 2:
				cout<<pokemon1.name<<" USED "<<pokemon1.moves[moveNum-1].nameInternal<<endl;
				pokemon2.stats.hpCur -= DamageCalc(pokemon1, pokemon1.moves[moveNum-1], pokemon2);
				break;

				case 3: 
				cout<<pokemon1.name<<" USED "<<pokemon1.moves[moveNum-1].nameInternal<<endl;
				pokemon2.stats.hpCur -= DamageCalc(pokemon1, pokemon1.moves[moveNum-1], pokemon2);
				break;

				case 4:
				cout<<pokemon1.name<<" USED "<<pokemon1.moves[moveNum-1].nameInternal<<endl;
				pokemon2.stats.hpCur -= DamageCalc(pokemon1, pokemon1.moves[moveNum-1], pokemon2);
				break;
				case 5:
				BattleUI(pokemon1,pokemon2,0);
				cin>>userInput;
				default:
				cout<<"not a valid input"<<endl;
			}
			
			break;

			case 2: //pokemon page
			cout<<"Work in progress"<<endl;
			cin>>userInput;
			//BattleUI(pokemon1,pokemon2,userInput);
			break;

			case 3: //bag
			cout<<"Work in progress"<<endl;
			cin>>userInput;
			break;

			case 4: //run
			BattleUI(pokemon1,pokemon2,userInput);
			if(first)
			{
				run=true;
				break;
			}
			else
			{
				cout<<"failed to run away"<<endl;
			}
			break;

			default:
			cout<<"Not a valid option, please try again"<<endl;
		}
		
	}
	if(run)
	{
		cout<<"Successfully fled from battle"<<endl;
		return;
	}
	else
	{
		cout<<"FAINTED"<<endl;
		return;
	}
	
}