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
	ret << count << "��";
	
	switch (level) {
	case SpriteStoneLevel::PRIMARY_LEVEL:
		ret << "������ʯ";
		break;
	case SpriteStoneLevel::MIDDLE_LEVEL:
		ret << "�н���ʯ";
		break;
	case SpriteStoneLevel::ADVANCED_LEVEL:
		ret << "�߽���ʯ";
		break;
	default:
		ret << "δ֪��ʯ";
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
	int sum = 0;//������ʯ����Ŀ
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
