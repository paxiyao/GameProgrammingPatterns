// �¼�(��Ϣ)����:���а������ȳ���˳��洢һϵ��֪ͨ�����󡣷���֪ͨ�������ŶӲ����ء�Ȼ�������������Ժ��ʱ�䴦�������е��
//				  �������ֱ�Ӵ�����·�ɵ���ط����⽫��̬�غ�tim�еķ��ͷ�����շ�����

// ʹ��ʱ��:
// �����ֻ�뽫������Ϣ��������Ϣ�ķ����߽����ô��Observer��Command������ģʽ���Ը��ٵĸ����Դ���������⡣ֻ�е����뼰ʱ����ĳЩ����ʱ������Ҫ���С�
// �Ҽ�����ÿһ�¶��ᵽ����һ�㣬��ֵ��ǿ���������Ի����������������԰Ѽ򵥵���һ�ֱ������Դ��
// ����Ϊ�����ƺ����Ĺ�ϵ����һЩ����A������һ����B��һЩ������A�����������Ȼ��ʽ�ǽ������Ƹ�B��
// ���ͬʱ��B�������������Ȼ�����������������ڵķ���ʱ�佫�����롣��һ����һ��pushģ�ͣ���һ����һ��pullģ��ʱ������֮����Ҫһ��������������Ƕ������ṩ�ģ����򵥵Ľ���ģʽ�������ṩ�ġ�
// ���н�����Ȩ����������ȡ�Ĵ��롪�����շ������ӳٴ������ۺ��������ȫ�������ǡ����Ƕ���ͨ���ӷ��ͷ�������߿���Ȩ��ʵ����һ�㡣���ͷ��������ľ�����������׳�һ�����󣬲�ϣ���õ���õĽ������ʹ�ö����ڷ��ͷ���Ҫ��Ӧʱ��̫���ʡ�

// ʹ��һ����β������������ʵ��:ѭ������
// û�ж�̬���䡣
// û���ڴ濪���Ĳ�����Ϣ��ָ�롣
// �����Ѻõ������ڴ�ʹ��

// ���߳�
// ������к������⡣ʹ��ͬ����ƵAPI���κ���ΪplaySound()���̶߳��Ǵ���������̡߳���ͨ������������Ҫ�ġ�
// �ڽ���Ķ��Ӳ���ϣ��������������оƬ������Ҫ��ֹһ���̡߳��������ַ����������߳�֮��ַ����룬��һ�������Ĳ����ǽ���Ϸ��ÿ�����ƶ����Լ����߳��ϡ�����Ƶ����Ⱦ��AI�ȵȡ�
// ֱ�ߴ���һ��ֻ����һ�����������С������ʹ���̣߳���ʹʹ�õ�ǰ���е��첽���ı�̣���õķ���Ҳ����һ�����ı���æµ����ֻ��CPU������һС���֡�
// ����������Աͨ�������ǵ�Ӧ�ó���ָ�ɶ�������Ľ������ֲ���һ�㡣��ʹ�ò���ϵͳ�����ڲ�ͬ���ں��ϲ������������ǡ���Ϸ��������һ����һ�Ľ��̣������̻߳��Ǻ��а����ġ�
// ���������Ѿ����������ؼ�����:
// ���������Ĵ����벥�������Ĵ����ǽ���ġ�
// ������һ����������������֮����б��顣
// �����Ǵӳ�������ಿ�ַ�װ�����ġ�
// ʣ�µĹ�������ʹ�޸Ķ��� - playSound()��update()�ķ����̰߳�ȫ��ͨ�����һ��дһЩ����Ĵ�����ʵ����һ�㣬������������һ��������ϵ�ṹ���飬�����Ҳ��������κ��ض�API���������Ƶ�ϸ���С�
// �ڸ߲㣬������Ҫ���ľ���ȷ�����в��Ტ�����޸ġ�����playSound()ֻ�����ٵĹ�������������ֻ���伸���ֶΡ����������������������������ܳ�ʱ�䡣
// ��update()�У����ǵȴ�һ�����������������Ķ������������ǾͲ�������CPU���ڣ�ֱ����һ��������Ҫ������

#include "audio.h"

int main()
{
	Audio::init();
	Audio::playSound(1, 1);

	return 0;
}