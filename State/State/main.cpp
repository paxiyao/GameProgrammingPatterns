// ״̬ģʽ: �������������ڲ�״̬����ʱ��������Ϊ
// 1.���ֻ��һ����ɫ���Բ���ʹ�þ�̬״̬����,����Ƶ���ͷźͿ����ڴ�,�Ӷ������ڴ���Ƭ
// 2.��״̬��װ����,���Խ���ͬ��״̬(��ɫ����״̬������״̬�����״̬��)��ȫ����
// 3.��ɫ��������enter��exit������ʵ�ֽ�ɫ������˳�ĳ��״̬ʱ����UI,��UI��״̬����,�ṹ������
// 4.���״̬��:��Щ�����������ֻʵ��һ�Σ�������״̬�¸���
// 5.��ʹ�������Զ��������԰��µ�״̬�ŵ�ջ���棬��ǰ״̬��Զ����ջ�������Ե���ջ����״̬����״̬�������������ͬʱ��һ��״̬����µ�ջ��״̬

#include "standState.h"

int main()
{
	Heroine* heroine = new Heroine(new StandState());
	heroine->handleInput(PRESS_DOWN);
	heroine->handleInput(PRESS_UP);

	delete heroine;

	system("pause");

	return 0;
}