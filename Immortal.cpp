#include<windows.h>
#include "Immortal.h"
#include"SpriteStone.h"
#include"Monster.h"

#define IMMORTAL_LEVEL_FACTOR 1000
#define SPRITE_STONE_FACTOR 0.2
#define MONSTER_FACTOR 0.5

Immortal::Immortal(const char* name, const char* menPai, ImmortalLevel level)
{
	this->name = name;
	this->menPai = menPai;
	this->level = level;
	this->alive = true;
}

void Immortal::mining()
{
	cout << "�ڿ��С���" << endl;
	Sleep(100);
	cout << "�ڿ�ɹ�,������ʯ����100" << endl;
	system("cls");
	stones.push_back(SpriteStone(100, SpriteStoneLevel::PRIMARY_LEVEL));
}

bool Immortal::trade()
{
	if (!alive) {
		return false;
	}

	SpriteStone stone;
	for (int i = 0; i < monsters.size(); i++) {
		stone=stone+monsters[i].getValue();
	}

	stones.push_back(stone);
	monsters.erase(monsters.begin(), monsters.end());
	return true;
}

bool Immortal::trade(const Monster& monster)
{
	if (!alive) {
		return false;
	}

	if (!handMonster(monster)) {
		cout << name << "û��" << monster << endl;
		return false;
	}

	SpriteStone stone = monster.getValue();
	stones.push_back(stone);
	removeMonster(monster);
	
	return true;
}

bool Immortal::trade(Immortal& other, const Monster& monster)
{
	if (!alive || !other.alive) {
		return false;
	}

	if (!other.handMonster(monster)) {
		cout << other.name << "û��" << monster << endl;
	}

	SpriteStone stone;
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}

	if (stone >= monster.getValue()) {
		SpriteStone valueStone = monster.getValue();
		stone = stone - valueStone;
		stones.clear();
		stones.push_back(stone);

		monsters.push_back(monster);
		other.removeMonster(monster);
		other.stones.push_back(valueStone);
		return true;
	}
	else {
		cout << "��Ǹ" << name << "����ʯ������" << monster << endl;
		return false;
	}

	return false;
}

bool Immortal::trade(const Monster& monsterSource, Immortal& other, const Monster& monsterDest)
{
	if (!alive || !other.alive) {
		return false;
	}

	if (monsterSource == monsterDest ||
		!handMonster(monsterSource) ||
		!other.handMonster(monsterDest) ||
		!(monsterSource.getValue()>=monsterDest.getValue())){
		cout << "����������,���ܶһ�" << endl;
		return false;
	}

	this->removeMonster(monsterSource);
	other.removeMonster(monsterDest);

	this->monsters.push_back(monsterDest);
	other.monsters.push_back(monsterSource);

	return true;
}

bool Immortal::trade(const Monster& monster, Immortal& other)
{
	if (!alive || !other.alive) {
		return false;
	}

	if (!handMonster(monster)) {
		cout << name << "û��" << monster << endl;
		return false;
	}

	SpriteStone otherStone;
	for (int i = 0; i < other.stones.size(); i++) {
		otherStone = otherStone + other.stones[i];
	}

	if (!(otherStone >= monster.getValue())) {
		cout << other.name << "����ʯ����" << endl;
		return false;
	}

	otherStone = otherStone - monster.getValue();
	other.stones.clear();
	other.stones.push_back(otherStone);
	other.monsters.push_back(monster);

	this->removeMonster(monster);
	this->stones.push_back(monster.getValue());
	
	return true;
}

string Immortal::getName()
{
	return name;
}

int Immortal::getPower() const
{
	//����ս����(��������ս��)
	int ret = ((int)level + 1)* IMMORTAL_LEVEL_FACTOR;

	//��ʯ����ս��
	SpriteStone stone;
	for (int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}
	ret += stone.getCount()* SPRITE_STONE_FACTOR;

	//��������ս��
	for (int i = 0; i < monsters.size(); i++) {
		ret+=monsters[i].getPower()* MONSTER_FACTOR;
	}

	return ret;
}

void Immortal::dead()
{
	alive = false;
	stones.erase(stones.begin(), stones.end());
	monsters.erase(monsters.begin(), monsters.end());
}

void Immortal::fight(const Monster& monster)
{
	int selfPower = getPower();
	int monsterPower = monster.getPower();

	if (selfPower > monsterPower) {
		monsters.push_back(monster);
	}
	else if(selfPower < monsterPower){
		dead();
	}

}

bool Immortal::handMonster(const Monster& monster)
{
	for (int i = 0; i < monsters.size(); i++) {
		if (monster == monsters[i]) {
			return true;
		}
	}

	return false;
}

bool Immortal::removeMonster(const Monster& monster)
{
	vector<Monster>::iterator it = monsters.begin();

	while (it != monsters.end()) {
		if (*it == monster) {
			it=monsters.erase(it);
			return true;
		}
		else {
			it++;
		}
	}

	return false;
}

ostream& operator<<(ostream& os, const Immortal& immortal)
{
	os << "[������]" << immortal.name
		<< (immortal.alive ? "[����]" : "[����]")
		<< "\t����:" << immortal.menPai
		<< "\t����:" << immortal.level ;
	SpriteStone stone;
	for (int i = 0; i < immortal.stones.size(); i++) {
		stone = stone + immortal.stones[i];
	}
	os << "\t��ʯ(�ۺ�Ϊ������ʯ):" << stone;

	os << "\t����:";
	if (immortal.monsters.size() == 0) {
		os << "��";
	}
	else {
		for (int i=0; i< immortal.monsters.size(); i++) {
			os << immortal.monsters[i] << " ";
		}
	}

	return os;
}

ostream& operator<<(ostream& os, const ImmortalLevel level)
{
	switch (level) {
	case ImmortalLevel::LIAN_QI:
		os << "������";
		break;
	case ImmortalLevel::ZHU_JI:
		os << "������";
		break;
	case ImmortalLevel::JIE_DAN:
		os << "�ᵤ��";
		break;
	case ImmortalLevel::YUAN_YING:
		os << "ԪӤ��";
		break;
	case ImmortalLevel::HUA_SHEN:
		os << "������";
		break;
	case ImmortalLevel::LIAN_XV:
		os << "������";
		break;
	case ImmortalLevel::HE_TI:
		os << "����";
		break;
	case ImmortalLevel::DA_CHENG:
		os << "�����";
		break;
	case ImmortalLevel::DU_JIE:
		os << "�ɽ���";
		break;
	default:
		os << "δ֪";
		break;
	}

	return os;
}
