#pragma once
class Character
{
private:
	int hp, max_hp;
	int basic_dmg;
	int basic_defensive;

public:
	// init class
	Character(int HP, int basic_DMG, int basic_DEFENSIVE);

	// getter
	int get_hp() const;
	int get_max_hp() const;
	int get_basic_dmg() const;
	int get_basic_defensive() const;

	// setter
	void set_hp(int Amount);
	void set_max_hp(int Amount);
	void set_basic_dmg(int Amount);
	void set_basic_defensive(int Amount);

	//methods
};

