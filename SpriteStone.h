#pragma once
#include <string>
#include<iostream>

using namespace std;

enum class SpriteStoneLevel{
	PRIMARY_LEVEL,//������ʯ
	MIDDLE_LEVEL,//�м���ʯ
	ADVANCED_LEVEL,//�߼���ʯ
	LEVEL_COUNT,//��ʯ�ȼ�����
};

//��ʯ��
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
	int count;//��ʯ��Ŀ
	SpriteStoneLevel level;//��ʯ�ĵȼ�
};

ostream& operator<<(ostream& os, const SpriteStone& stone);