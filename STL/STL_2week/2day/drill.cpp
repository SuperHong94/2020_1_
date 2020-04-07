#include <iostream>
#include <memory>
using namespace std;

class Dog {
	int n;
public:
	Dog() { cout <<this <<" ����" << endl; }
	~Dog() { cout<<this << "�Ҹ�" << endl; }
	void show() {
		cout << "Dog�Դϴٸ�" << endl;
	}
};


int main()
{
	{
		auto dog = make_unique<Dog>();
	}

	//����2
	auto dogs = make_unique<Dog[]>(5);  
	//�Ǵ� �Ʒ��Ͱ���
	unique_ptr<Dog[]> dogs2{ new Dog[3] };
	
	Dog* p = new Dog[10];
	delete p;
}

//���� 1
/*unique_ptr<Dog> dogs{ new Dog[3] };
�� �κ��� �ذ��ؾ� �ȴ�.
�̹����� �Ҹ��� dogs�� ����Ű�� ù�ּҸ� ���� �����ϱ⶧���� �׷���. 
�׷��� �� ù�ּҸ� ���� ������ų��?
���� �ڵ��� <>���� ���� Dog�� �Ǿ��ִ�. ������ �Ǿ �Ҹ꿡�� ������ �߻��Ѵ�.
�Ҹ��ڿ��� �޸� ����Ÿ���� �迭�� �ƴ� �����Ͱ� ����Ű���ִ� �ּҷ� �˰� �ֱ⿡ �߻��Ѵ�. ����
<>���� <Dog[]>�̷��� �迭�̶�� �˷��־�� �Ѵ�.
��ġ Dog* p=new Dog[10]�� delete[] Dog�� �����ϴ°��� �ƴ϶� delete�θ� �����ϴ°Ͱ� ����ϴ�.
*/


