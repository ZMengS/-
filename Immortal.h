#pragma once
#include<string>
#include<vector>
#include<iostream>

using namespace std;

enum class ImmortalLevel {
	LIAN_QI,//练气期
	ZHU_JI,//筑基期
	JIE_DAN,//结丹期
	YUAN_YING,//元婴期
	HUA_SHEN,//化神期
	LIAN_XV,//练虚期
	HE_TI,//合体期
	DA_CHENG,//大成期
	DU_JIE,//渡劫期
	LEVEL_COUNT,//修炼等级数
};

class SpriteStone;
class Monster;

//修仙者类
class Immortal
{
public:
	Immortal(const char* name, const char* menPai,
		ImmortalLevel level);

	//活动:
	void mining();//挖矿
	bool trade();//交易(售卖所有妖兽)
	bool trade(const Monster& monster);//(售卖制定妖兽)
	bool trade(Immortal& other, const Monster& monster);//(用灵石购买别人的妖兽)
	bool trade(const Monster& monsterSource, Immortal& other,
		const Monster& monsterDest);//用自己指定的妖兽换别人指定的妖兽
	bool trade(const Monster& monster, Immortal& other);//把自己的妖兽卖给别人

	string getName();

	//获取战力
	int getPower()const;

	//修仙者死亡
	void dead();

	//捕获妖兽
	void fight(const Monster& monster);

	friend ostream& operator<<(ostream& os, const Immortal& immortal);
	friend ostream& operator<<(ostream& os, const ImmortalLevel level);

private:
	string name;
	string menPai;
	ImmortalLevel level;//修仙者级别
	vector<SpriteStone>stones;//灵石资产
	vector<Monster>monsters;//妖兽资产
	bool alive;//生死状态

	bool handMonster(const Monster& monster);//是否有这个妖兽
	bool removeMonster(const Monster& monster);//移除指定的妖兽
};

ostream& operator<<(ostream& os, const Immortal& immortal);
ostream& operator<<(ostream& os, const ImmortalLevel level);

