#include "libs.h"

class Reservoir
{
private:
	string _name, _type;
	float _volume, _area;
public:
	Reservoir() : _name("Unknown"), _type("Unknown"), _volume(0), _area(0) {}
	explicit Reservoir(const string& name, const string& type, float volume,
		float area) : _name(name), _type(type), _volume(volume), _area(area) {
	}
	Reservoir(const Reservoir& res1) : _name(res1._name), _type(res1._type), _volume(res1._volume), _area(res1._area) {}
	float volFunc(float max_depth) const
	{
		return _area * max_depth;
	}
	bool checkFunc(const Reservoir& res1) const
	{
		return _type == res1._type;
	}
	bool compFunc(const Reservoir& res1) const
	{
		if (_type == res1._type)
			return _area > res1._area;
		else
			return false;
	}
	void printFunc() const {
		cout << endl;
		cout << "Name: " << _name << endl;
		cout << "Type: " << _type << endl;
		cout << "Volume: " << _volume << endl;
		cout << "Area: " << _area << endl;
	}
	const string& getName() const { return _name; }
	const string& getType() const { return _type; }
	float getV() const { return _volume; }
	float getArea() const { return _area; }
	void setName(const string& name) { _name = name; }
	void setType(const string& type) { _type = type; }
	void setV(float volume) { _volume = volume; }
	void setArea(float area) { _area = area; }
	~Reservoir() = default;
};

class ResArray
{
private:
	Reservoir* reservoirs;
	int size;
public:
	ResArray() : reservoirs(nullptr), size(0) {}
	void addFunc(const Reservoir& res1)
	{
		Reservoir* newRes = new Reservoir[size + 1];
		for (int i = 0; i < size; i++) {
			*(newRes + i) = *(reservoirs + i);
		}
		newRes[size] = res1;
		delete[] reservoirs;
		reservoirs = newRes;
		++size;
	}
	void deleteFunc(int index) {
		if (index < 0 || index >= size) {
			cout << "Error occurred... Choose valid index..." << endl;
			return;
		}
		Reservoir* newRes= new Reservoir[size - 1];
		for (int i = 0, j = 0; i < size; i++) {
			if (i != index) {
				newRes[j++] = reservoirs[i];
			}
		}
		delete[] reservoirs;
		reservoirs = newRes;
		--size;
	}
	void printResFunc() const {
		for (int i = 0; i < size; i++)
			reservoirs[i].printFunc();
	}
	~ResArray() {
		delete[] reservoirs;
	}
};