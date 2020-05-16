#include "Monster.h"
#include"SpriteStone.h"

#define MONSTER_LEVEL_FACTOR 1200

Monster::Monster(int level, const string& category)
{
	this->level = level;
	this->category = category;
}

SpriteStone Monster::getValue() const
{
	int stoneCount[] = { 100,200,500,1000,2000,
		5000,10000,20000,100000 };
	int count = stoneCount[level - 1];
	return SpriteStone(count,SpriteStoneLevel::PRIMARY_LEVEL);
}

int Monster::getPower() const
{
	int ret = level * MONSTER_LEVEL_FACTOR;
	return ret;
}

ostream& operator<<(ostream& os, const Monster& monster)
{
	os << monster.level << "¼¶" << monster.category << "ÑýÊÞ";
	return os;
}

bool operator==(const Monster& one, const Monster other)
{
	if(one.category==other.category && 
		one.level == other.level){
			return true;
		}

	return false;
}
