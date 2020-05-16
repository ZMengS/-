#include<sstream>
#include "SpriteStone.h"

SpriteStone::SpriteStone(int count, SpriteStoneLevel level)
{
	this->count = count;
	this->level = level;
}

string SpriteStone::str() const
{
	stringstream ret;
	ret << count << "块";
	
	switch (level) {
	case SpriteStoneLevel::PRIMARY_LEVEL:
		ret << "初阶灵石";
		break;
	case SpriteStoneLevel::MIDDLE_LEVEL:
		ret << "中阶灵石";
		break;
	case SpriteStoneLevel::ADVANCED_LEVEL:
		ret << "高阶灵石";
		break;
	default:
		ret << "未知灵石";
		break;
	}

	return ret.str();
}

int SpriteStone::getCount()
{
	return count;
}

SpriteStone SpriteStone::operator+(const SpriteStone& stone)
{
	int sum = 0;//初阶灵石的数目
	if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum += stone.count;
	}
	else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum += stone.count * 10;
	}
	else if (stone.level == SpriteStoneLevel::ADVANCED_LEVEL) {
		sum += stone.count * 100;
	}

	if (this->level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum += this->count;
	}
	else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum += this->count * 10;
	}
	else if (this->level == SpriteStoneLevel::ADVANCED_LEVEL) {
		sum += this->count * 100;
	}

	return SpriteStone(sum,SpriteStoneLevel::PRIMARY_LEVEL);
}

SpriteStone SpriteStone::operator-(const SpriteStone& stone)
{
	int sum = 0;
	if (this->level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum = this->count;
	}
	else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum = this->count * 10;
	}
	else if (this->level == SpriteStoneLevel::ADVANCED_LEVEL) {
		sum = this->count * 100;
	}

	int sum1 = 0;
	if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum1 = stone.count;
	}
	else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum1 = stone.count * 10;
	}
	else if (stone.level == SpriteStoneLevel::ADVANCED_LEVEL) {
		sum1 = stone.count * 100;
	}

	int ret = sum - sum1;
	return SpriteStone(ret, SpriteStoneLevel::PRIMARY_LEVEL);;
}

bool SpriteStone::operator>=(const SpriteStone& stone)
{
	int sum = 0;
	if (this->level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum = this->count;
	}
	else if (this->level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum = this->count * 10;
	}
	else if (this->level == SpriteStoneLevel::ADVANCED_LEVEL) {
		sum = this->count * 100;
	}

	int sum1 = 0;
	if (stone.level == SpriteStoneLevel::PRIMARY_LEVEL) {
		sum1 = stone.count;
	}
	else if (stone.level == SpriteStoneLevel::MIDDLE_LEVEL) {
		sum1 = stone.count * 10;
	}
	else if (stone.level == SpriteStoneLevel::ADVANCED_LEVEL) {
		sum1 =stone.count * 100;
	}

	return sum >= sum1;
}

ostream& operator<<(ostream& os, const SpriteStone& stone)
{
	os << stone.str();
	return os;
}
