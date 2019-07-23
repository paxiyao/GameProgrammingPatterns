// ����ģʽ����һ�����󻯵ķ�������
// ����: ��(jump), ��(move)��������ͬ����Ϊ
// �������: ����������ͬ�ĺ����ӿڶ�Ӧ������Ϊ
// �������: �������������������ж��󻯣���װ���࣬���̳�Command,�ŵ�Command��excute����ȥִ�о���Ķ���
// ����ģʽһ��������Ϸ�İ�ť����꣬���̵Ƚ���

#include<vector>

#include "jumpCommand.h"
#include "moveCommand.h"

const int count = 5;

int main()
{
	std::vector<Command*> cVector;
	int curCommandIdx = 0;	// ��ǰ�����±�

	// ��ɫ
	Unit* unit = new Unit();

	for (unsigned int i = 0; i < count; i++)
	{
		cVector.push_back(new JumpCommand(unit, i, i));
		cVector[i]->execute();
		curCommandIdx = i;
	}

	// ����4��
	curCommandIdx = curCommandIdx - 4;
	if (curCommandIdx < 0) // �������4������ӵ�һ����ʼ
		curCommandIdx = 0;
	while (curCommandIdx < count)
		cVector[curCommandIdx++]->execute();

	// ����1��
	cVector[cVector.size() - 1]->undo();
	cVector.pop_back();

	system("pause");

	return 0;
}
