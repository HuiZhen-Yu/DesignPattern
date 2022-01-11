#include <iostream>
#include <string>
#include "Flyweight.hpp"

using namespace std;

/*
 * ��Ԫģʽ(Flyweight): ���ù�������Ч��֧�ִ���ϸ���ȵĶ���
 * ��Ԫģʽ���Ա�������ǳ�������Ŀ������ڳ�������У���ʱ����Ҫ���ɴ���ϸ���ȵ���ʵ������ʾ���ݡ�
 * ����ܷ�����Щʵ�����˼�������������϶�����ͬ�ģ���ʱ���ܹ�����ȵļ�����Ҫʵ���������������
 * ����ܰ���Щ�����Ƶ���ʵ�������棬�ڷ�������ʱ�����Ǵ��ݽ������Ϳ���ͨ���������ȵļ��ٵ���ʵ������Ŀ��
 * 
 * Ӧ�ã����һ��Ӧ�ó���ʹ���˴����Ķ��󣬶���������Щ��������˺ܴ�Ĵ洢����ʱ��Ӧ�ÿ���ʹ�ã�
 *       ���о��Ƕ���Ĵ����״̬�����ⲿ״̬�����ɾ��������ⲿ״̬����ô�Ϳ�������Խ��ٵĹ������ȡ���ܶ�����󣬴�ʱ�����ù���ģʽ��
 */

int main(int argc, char **argv)
{
    int extrinsic = 22;
    FlyweightFactory *f = new FlyweightFactory();
    Flyweight *fx = f->GetFlyweight("X");
    fx->Operation(--extrinsic);

    Flyweight *fy = f->GetFlyweight("Y");
    fx->Operation(--extrinsic);

    Flyweight *fz = f->GetFlyweight("Z");
    fx->Operation(--extrinsic);

    Flyweight *uf = new UnsharedConcreteFlyweight();
    uf->Operation(--extrinsic);

    delete fx;
    delete fy;
    delete fz;
    delete uf;
    system("pause");
    return 0;
}