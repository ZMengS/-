#pragma once
#include <string>
#include<iostream>

using namespace std;

enum class SpriteStoneLevel{
	PRIMARY_LEVEL,//初级灵石
	MIDDLE_LEVEL,//中级灵石
	ADVANCED_LEVEL,//高级灵石
	LEVEL_COUNT,//灵石等级数量
};

//灵石类
class SpriteStone
{
public:
	SpriteStone(int count=0, 
		SpriteStoneLevel level= SpriteStoneLevel::PRIMARY_LEVEL);
	string str()const;
	int getCount();

	friend ostream& operator<<(ostream& os, const SpriteStone& stone);
	SpriteStone operator+(const SpriteStone& stone);
	SpriteStone operator-(const SpriteStone& stone);
	bool operator>=(const SpriteStone& stone);

private:
	int count;//灵石数目
	SpriteStoneLevel level;//灵石的等级
};

ostream& operator<<(ostream& os, const SpriteStone& stone);