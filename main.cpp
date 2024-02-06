#include <iostream>

class People
{
private:
	std::string _fullName;
public:
	//инициализация имени
	People() : _fullName("Unknown") {}

	People(const std::string& name) : _fullName(name) {}

	//конструктор копирования
	People(const People& other) : _fullName(other._fullName) {}

	std::string getFullName() const //возврат полного имени
	{
		return _fullName;
	}
};

class Apartament
{
private:
	People* _residents;
	int _capacity; //вместимость квартиры
	int _counter; //текущее количество жильцов
public:
	//конструктор по умолчанию
	Apartament() : _capacity(0), _counter(0), _residents(nullptr) {}

	Apartament(int capacity) : _capacity(capacity), _counter(0)
	{
		_residents = new People[capacity];
	}

	//конструктор копирования
	Apartament(const Apartament& other) : _capacity(other._capacity), _counter(other._counter) 
	{
		_residents = new People[_capacity];
		for (int i = 0; i < _counter; i++) 
		{
			_residents[i] = other._residents[i];
		}
	}

	void addResident(const People& person) //добавление новых жильцов в квартиру
	{ 
		if (_counter < _capacity) 
		{
			_residents[_counter++] = person;
			std::cout << person.getFullName() << " теперь жилец." << std::endl;
		}
	}

};

class House
{
private:
	Apartament* _apartaments; 
	int _numApartaments; //количество квартир в доме
public:
	House(int numApartments, int apartmentCapacity) : _numApartaments(numApartments) 
	{
		_apartaments = new Apartament[numApartments];
		for (int i = 0; i < numApartments; ++i) 
		{
			_apartaments[i] = Apartament(apartmentCapacity);
		}
	}
	//копирования к
	House(const House& other) : _numApartaments(other._numApartaments) 
	{
		_apartaments = new Apartament[_numApartaments];
		for (int i = 0; i < _numApartaments; ++i) 
		{
			_apartaments[i] = other._apartaments[i];
		}
	}

	void addResident(const People& person, int apartmentIndex) 
	{
		if (apartmentIndex >= 0 && apartmentIndex < _numApartaments) 
		{
			_apartaments[apartmentIndex].addResident(person);
			std::cout << person.getFullName() << " заселилися в квартиру N" << apartmentIndex  << std::endl;
		}
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	House hHouse(3, 2);

	People person1("Полина К.");
	People person2("Александр Ф.");
	People person3("Карина Н.");
	People person4("Татьяна Л.");
	People person5("Руслан Б.");

	// Добавляем жильцов в квартиры
	hHouse.addResident(person1, 0);
	hHouse.addResident(person2, 0);
	hHouse.addResident(person3, 2);
	hHouse.addResident(person4, 2);
	hHouse.addResident(person5, 1);

	return 0;
}