#pragma once
#include<string>
#include<iostream>

using namespace std;

class SpriteStone;
//������
class Monster
{
public:
	Monster(int level = 1, const string& category="δ֪");
	SpriteStone getValue() const;//��ȡ���޼�ֵ
	int getPower() const;//��ȡ����ս����

	friend ostream& operator<<(ostream& os, const Monster& monster);
	friend bool operator==(const Monster& one, const Monster other);

private:
	string category;//��������
	int level;//���޵ȼ�(1-9��)
};

ostream& operator<<(ostream& os, const Monster& monster);
bool operator==(const Monster& one, const Monster other);