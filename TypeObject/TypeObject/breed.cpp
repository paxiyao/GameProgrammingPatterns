#include "breed.h"
#include "monster.h"

Breed::Breed(Breed* parent, int health, const char* attack)
	:_health(health),
	 _attack(attack)
{
	//1.���������ʱ��һ��Ʒ���޸�Ϊ���ٸ��ǻ��ټ̳�ĳЩ���ԣ���ô�������ĺô�����ȷ�ġ���һ���棬����Ҫ������ڴ�(�����뱣��ָ���丸����ָ��)�������ٶȸ�����ÿ�β�������ʱ��������������̳�����
	//2.������ǿ�������һ��Ʒ�ֵ����Բ��ı䣬һ������Ľ���������ڹ���ʱӦ�ü̳С����Ϊ������ - ���¡�ί�У���Ϊ�����ڴ����̳�����ʱ���临�Ƶ�����������
	if (parent != NULL)
	{
		if (health == 0)
		{
			_health = parent->getHealth();
		}
		if (attack == NULL)
		{
			_attack = parent->getAttack();
		}
	}
}


// ʹ���Ͷ����������:���캯��
// ������������ӵ�еģ�����ֱ�ӽ���һ����������𴫵�����Ʒ�֡�
// �����ڴ����OOP������ʵ�����������ķ�ʽ�е��෴��������ͨ���������һ��հ��ڴ棬Ȼ������ࡣ
// �෴���������౾���ϵ��ù��캯���������������һ���µ�ʵ����
Monster* Breed::newMonster()
{
	return new Monster(*this);
}

int Breed::getHealth()
{
	return _health;
}

const char* Breed::getAttack()
{
	return _attack;
}