#include <iostream>

//�ڿ��� �Ҵ��ϴ� Ŭ����
//���� 1 , 2
class Model
{
public:
	static int cnt;
	Model();
	Model(size_t);
	Model(const Model&);
	Model(Model&&);
	Model& operator=(const Model&);
	Model& operator=(Model&&);
	~Model();

private:
	int id;
	char* data;
	size_t size;   //unsinged int 
};


Model::Model() :data(nullptr),size{ 0 }
{
	id = cnt++;
	std::cout << "����!  " << id<< '\n';
}
Model::Model(size_t n) :size{ n }
{
	id = cnt++;
	data = new char[n];
	std::cout << "data �Ҵ� ����!  " << id << '\n';
}
Model::Model(const Model& other):size(other.size)
{
	id = cnt++;
	data = new char[size];
	memcpy(data, other.data, size);
	std::cout << "���� ���� " << id << "  " << &other << '\n';
}
Model& Model::operator=(const Model& x)
{
	size = x.size;
	data = new char[size];
	memcpy(data, x.data, size);
	std::cout << "���� �Ҵ� " << id << "  " << '\n';

	return *this;
}
Model& Model::operator=( Model&& x)
{
	size = x.size;
	data = x.data;
	x.data = nullptr;
	x.size = 0;
	std::cout << "�̵��Ҵ� �Ҵ� " << id << "  "<< '\n';

	return *this;
}
Model::Model(Model&& other):data{nullptr},size(other.size)
{
	id = cnt++;
	data = other.data;
	other.data = nullptr;
	other.size = 0;
	std::cout << "�̵� ������  " << id << '\n';
}
Model::~Model()
{
	std::cout << "\n�Ҹ�" << "  " << id << '\n';
	if (data != NULL) {
		std::cout << "data ����" << '\n';
		delete[] data;
	}
	else
		std::cout << "data�� ����" << '\n';
}

int Model::cnt = 0;
int main()
{
	// Model a;
	// Model b;
	//Model c;
	////c = b;
	////std::move(b);

	//���� 3~5
	/*Model a;
	Model b{ 1000 };
	Model c = b;
	a = c;*/

	//����6
	//Model a[10];

	//����7~8
	//Model a[10];
	Model a{ 1000 };
	Model b = std::move(a);
	Model c;
	c = std::move(a);

}