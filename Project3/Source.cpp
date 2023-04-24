#include <iostream>
using namespace std;
class Dog { // ��������� ����� Dog
public:
	friend class Human; // ������ ����� Dog ������������� ������ Human
	Dog() { // ����������� ����������� �� ���������
		cout << "Dog default Constructor\n";
	}
	~Dog() { // ����������� ����������
		cout << "Dog Destructor\n";
	}
private:
	void speak() { // ����������� ��������� �����
		cout << "Woof!\n";
	}
};
class Human { // ��������� ����� Human
public:
	Human() { // ����������� �� ���������
		age = 0;
		name = "default";
		population++;
		cout << "Human default Constructor\n";
	}
	Human(int age_, string name_) { // ����������� �� ���� ����������
		age = age_;
		name = name_;
		population++;
		cout << "Human age and name Constructor\n";
	}
	Human(const Human& h) { // ����������� �����������
		age = h.age;
		name = h.name;
		population++;
		cout << "Human copy Constructor\n";
	}
	~Human() { // ����������
		cout << "Human " << name << " Destructor\n";
		population--;
	}
	void set_age(int age_) { // ������ ��� ��������
		if (age_ > 0) {
			age = age_;
		}
	}
	void set_name(string name_) { // ������ ��� �����
		name = name_;
	}
	int get_age() { // ������ ��� ��������
		return age;
	}
	string get_name() { // ������ ��� �����
		return name;
	}
	static int get_population() { // ����������� ����� ������� � ����������� ����������
		return population;
	}
	void birthday() { // ����������� ������ ������
		this->age++;
		cout << "Happy birthday, " << this->name << "!\n";
	}
	void dog_speak(Dog& d) {
		cout << "Speak!\n";
		d.speak();
		cout << "Good boy!\n";
	}
private:
	static int population; // ����������� ���������� ������
	int age;
	string name;
};
int Human::population = 0; // ������������ ���������� ����������� ���������� ��� ������
int main()
{
	Human h1; // ������ ������� - ���������� ������,
	Human h2(30, "Ivan"); // ��������� ������ ������������
	Human h3 = h2;

	cout << "Total population is " << Human::get_population() << endl; // �������� ����������� �����
	h1.birthday(); // �������� ������ ��� ��������
	h2.birthday();
	h1.set_age(35);
	h1.set_name("Alexey");
	h1.birthday();
	cout << h1.get_name() << " is " << h1.get_age() << " years old!\n";
	cout << h2.get_name() << " is " << h2.get_age() << " years old!\n";
	cout << h3.get_name() << " is " << h3.get_age() << " years old!\n";
	Dog d; // ������ ������ ������ Dog
	h1.dog_speak(d); // �������� �����, ������� ������ � ��������� ����� ������ Dog
}