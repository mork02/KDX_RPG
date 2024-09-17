#pragma once
#include <iostream>
#include "entitie.h"

enum class Zone 
{
	FIRST_ZONE,
	SECOND_ZONE,
	THIRD_ZONE,
	FOURTH_ZONE,
	FIFTH_ZONE	
};

class NPC : public Entitie
{
private:
	std::string name;
	Zone zone;


public:
	NPC(std::string name, int hp, int basic_dmg, int basic_defensive, Zone zone);

	// getter
	std::string get_name();
	Zone get_zone();

};

