#include<iostream>
#include"SpriteStone.h"
#include"Monster.h"
#include"Immortal.h"

void testSpriteStone() {
	SpriteStone stone(100, SpriteStoneLevel::ADVANCED_LEVEL);
	cout << stone << endl;
}

void testMonster() {
	Monster monster(5, "ÖíÖí");
	cout << monster << endl;
	cout << monster.getValue() << endl;
}

void testImmortal() {
	string ret(100, '-');
	Immortal nn("æ¤æ¤", "æ¤æ¤ÅÉ", ImmortalLevel::LIAN_XV);
	Immortal mm("ÃÎ±¦±´", "æ¤æ¤ÅÉ", ImmortalLevel::YUAN_YING);
	cout<< nn<<endl;
	cout << mm << endl;
	for (int i = 0; i < 20; i++) {
		mm.mining();
	}
	cout << nn << endl;

	Monster monster(3, "Ð¡ÏãÖí");
	nn.fight(monster);
	cout << "²¶»ñ" << monster << "Ö®ºó" << endl;
	cout << nn << endl;

	Monster zhu1(3, "ÖíÖí");
	mm.fight(zhu1);
	Monster zhu2(4, "ÖíÖí");
	mm.fight(zhu2);

	Monster monster1(4, "´óÏãÖí");
	nn.fight(monster1);
	Monster monster3(5, "ÖíÏãÏã");
	nn.fight(monster3);

	cout << ret << endl;
	if (nn.trade(mm, zhu1)) {
		cout << nn.getName() << "¹ºÂòÁË" << mm.getName() << "µÄ" << zhu1 << endl;
	}
	cout << nn << endl;
	cout << mm << endl;

	cout << ret << endl;
	if (nn.trade(monster1, mm, zhu2)) {
		cout << nn.getName() << "ÓÃ" << monster1 << "½»»»ÁË" << mm.getName() << "µÄ" << zhu2 << endl;
	}
	cout << nn << endl;
	cout << mm << endl;

	cout << ret << endl;
	if (nn.trade(monster3, mm)) {
		cout << nn.getName() << "°Ñ" << monster3 << "Âô¸øÁË" << mm.getName() << endl;
	}
	cout << nn << endl;
	cout << mm << endl;
}


int main(void) {
	testSpriteStone();
	testMonster();
	testImmortal();

	system("pause");
	return 0;
}