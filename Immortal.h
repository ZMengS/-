#pragma once
#include<string>
#include<vector>
#include<iostream>

using namespace std;

enum class ImmortalLevel {
	LIAN_QI,//������
	ZHU_JI,//������
	JIE_DAN,//�ᵤ��
	YUAN_YING,//ԪӤ��
	HUA_SHEN,//������
	LIAN_XV,//������
	HE_TI,//������
	DA_CHENG,//�����
	DU_JIE,//�ɽ���
	LEVEL_COUNT,//�����ȼ���
};

class SpriteStone;
class Monster;

//��������
class Immortal
{
public:
	Immortal(const char* name, const char* menPai,
		ImmortalLevel level);

	//�:
	void mining();//�ڿ�
	bool trade();//����(������������)
	bool trade(const Monster& monster);//(�����ƶ�����)
	bool trade(Immortal& other, const Monster& monster);//(����ʯ������˵�����)
	bool trade(const Monster& monsterSource, Immortal& other,
		const Monster& monsterDest);//���Լ�ָ�������޻�����ָ��������
	bool trade(const Monster& monster, Immortal& other);//���Լ���������������

	string getName();

	//��ȡս��
	int getPower()const;

	//����������
	void dead();

	//��������
	void fight(const Monster& monster);

	friend ostream& operator<<(ostream& os, const Immortal& immortal);
	friend ostream& operator<<(ostream& os, const ImmortalLevel level);

private:
	string name;
	string menPai;
	ImmortalLevel level;//�����߼���
	vector<SpriteStone>stones;//��ʯ�ʲ�
	vector<Monster>monsters;//�����ʲ�
	bool alive;//����״̬

	bool handMonster(const Monster& monster);//�Ƿ����������
	bool removeMonster(const Monster& monster);//�Ƴ�ָ��������
};

ostream& operator<<(ostream& os, const Immortal& immortal);
ostream& operator<<(ostream& os, const ImmortalLevel level);

