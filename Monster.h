#pragma once
#include<string>
#include<iostream>

using namespace std;

class SpriteStone;
//妖兽类
class Monster
{
public:
	Monster(int level = 1, const string& category="未知");
	SpriteStone getValue() const;//获取妖兽价值
	int getPower() const;//获取妖兽战斗力

	friend ostream& operator<<(ostream& os, const Monster& monster);
	friend bool operator==(const Monster& one, const Monster other);

private:
	string category;//妖兽种类
	int level;//妖兽等级(1-9级)
};

ostream& operator<<(ostream& os, const Monster& monster);
bool operator==(const Monster& one, const Monster other);