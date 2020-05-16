#include<iostream>
#include"SpriteStone.h"
#include"Monster.h"
#include"Immortal.h"

void testSpriteStone() {
	SpriteStone stone(100, SpriteStoneLevel::ADVANCED_LEVEL);
	cout << stone << endl;
}

void testMonster() {
	Monster monster(5, "����");
	cout << monster << endl;
	cout << monster.getValue() << endl;
}

void testImmortal() {
	string ret(100, '-');
	Immortal nn("��", "����", ImmortalLevel::LIAN_XV);
	Immortal mm("�α���", "����", ImmortalLevel::YUAN_YING);
	cout<< nn<<endl;
	cout << mm << endl;
	for (int i = 0; i < 20; i++) {
		mm.mining();
	}
	cout << nn << endl;

	Monster monster(3, "С����");
	nn.fight(monster);
	cout << "����" << monster << "֮��" << endl;
	cout << nn << endl;

	Monster zhu1(3, "����");
	mm.fight(zhu1);
	Monster zhu2(4, "����");
	mm.fight(zhu2);

	Monster monster1(4, "������");
	nn.fight(monster1);
	Monster monster3(5, "������");
	nn.fight(monster3);

	cout << ret << endl;
	if (nn.trade(mm, zhu1)) {
		cout << nn.getName() << "������" << mm.getName() << "��" << zhu1 << endl;
	}
	cout << nn << endl;
	cout << mm << endl;

	cout << ret << endl;
	if (nn.trade(monster1, mm, zhu2)) {
		cout << nn.getName() << "��" << monster1 << "������" << mm.getName() << "��" << zhu2 << endl;
	}
	cout << nn << endl;
	cout << mm << endl;

	cout << ret << endl;
	if (nn.trade(monster3, mm)) {
		cout << nn.getName() << "��" << monster3 << "������" << mm.getName() << endl;
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