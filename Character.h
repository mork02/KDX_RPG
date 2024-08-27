#pragma once
class Character
{
private:
	int hp, max_hp;
	int basic_dmg;
	int defensive, extra_defensive;

public:
	// init class
	Character(int HP, int basic_DMG, int DEFENSIVE, int extra_DEFENSIVE);

	// getter
	int get_hp();
	int get_max_hp();
	int get_basic_dmg();
	int get_defensive();
	int get_extra_defensive();

	// setter
	void set_hp(int Amount);
	void set_max_hp(int Amount);
	void set_basic_dmg(int Amount);
	void set_defensive(int Amount);
	void set_extra_defensive(int Amount);

	//methods
	bool check_death();
};

