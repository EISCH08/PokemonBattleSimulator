#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void functionCodeEffect(Pokemon attPoke, Move move,Pokemon defPoke)
{
	//this function will be a lookup chart for each of the moves secondary effects
int random = rand()%100;
int function = move.functionCode;

	switch(function)
	{
		case 0x000:
		//do nothing
		case 0x001:
		//splash
		break;
		case 0x002:
		//struggle lose 1/4 of health
		attPoke.stats.hpCur -= attPoke.stats.hp/4;
		break;
		case 0x003:
		//puts target to sleep
		defPoke.status = "SLEEP";
		break;
		case 0x004:
		//drowsy
		defPoke.status = "DROWSY";
		break;
		case 0x005:
		//poisons tartget
		defPoke.status = "POISON";
		break;
		case 0x006:
		//badly poisons
		defPoke.status = "BADLY POISON";
		break;
		case 0x007:
		//paralyzes target
		defPoke.status = "PARALYZE";
		break;

		case 0x008:
		//thunder able to hit target in middle of bounce and paralyze
		break;

		case 0x009:
		//may paralyze the target and may cause to flinch
		if(random<=10)
		{
			defPoke.status = "PARALYZE";
		}
		else if(90<=random<=100)
		{
			defPoke.status = "FLINCH";
		}
		break;

		case 0x0A:
		//chance to burn
		if(random<=20)
		{
			defPoke.status = "BURN";
		}
		if(move.nameInternal=="WILL-O-WISP")
		{
			defPoke.status = "BURN";
		}
		break;

		case 0x0B:
		//may burn or flinch
		if(random<=10)
		{
			defPoke.status = "BURN";
		}
		else if(random>=90)
		{
			defPoke.status = "FLINCH";
		}
		break;

		case 0x00C:
		//freezes target
		if(random<=10)
		{
			defPoke.status = "FREEZE";
		}
		break;

		case 0x00D:
		//blizzard accuracy in the a hail storm
		break;

		case 0x00E:
		//may freeze and flinch
		if(random<=10)
		{
			defPoke.status = "FREEZE";
		}
		else if(random>=90)
		{
			defPoke.status = "FLINCH";
		}
		break;

		case 0x00F:
		//causes target to flinch
		if(random<=10)
		{
			defPoke.status = "FLINCH";
		}
		break;

		case 0x010:
		//chance to flinch and double damage for minimized
		if(defPoke.statusBattle = "MINIMIZED")
		{
			//figure out a way to deal double damage
		}
		if(random<=10)
		{
			defPoke.status = "FLINCH";
		}
		break;
		case 0x013:
		//confuses a target
		if(random<=10)
		{
			defPoke.status = "CONFUSE";

		}
		if(move.nameInternal == "CONFUSE RAY")
		{
			defPoke.status = "CONFUSE";
		}
		break;

		case 0x016:
		//causes target to attract
		defPoke.status = "ATTRACT";
		break;
		
		case 0x017:
		//tri attack
		if(random<=10)
		{
			defPoke.status = "BURN";
		}
		else if(10<random <=20)
		{
			defPoke.status = "PARALYZE";
		}
		else if(20<random<=30)
		{
			defPoke.status = "FREEZE";
		}
		break;

		case 0x018:
		case 0x019:
		//refresh and heal bell
		attPoke.status = "HEALTHY";
		break;


		default:
		break;


	}
}