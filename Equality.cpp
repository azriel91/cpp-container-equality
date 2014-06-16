#include <cstdio>
#include <algorithm> // std::equal
#include <vector>

using namespace std;

class Object {
private:
	const int value;
public:
	Object(int _value) : value(_value) {}
	virtual ~Object() {}
	bool operator==(const Object& other) const { return this->value == other.value; }
};

template<typename T>
bool pointeesEqual(const T& one, const T& two) {
	return *one == *two;
}

int main(int argc, char const *argv[])
{
	const Object* const object0 = new Object(0);
	const Object* const object1 = new Object(0);
	printf("instanceEquals: %s\n", object0 == object1 ? "true" : "false");	// false
	printf("valueEquals: %s\n", *object0 == *object1 ? "true" : "false");	// true

	// put them into vectors
	vector<const Object*> v0;
	v0.push_back(object0);
	vector<const Object*> v1;
	v1.push_back(object1);
	printf("vectorEquals: %s\n", v0 == v1 ? "true" : "false");	// false

	// predicate comparison
	bool containerValuesEqual = std::equal(v0.begin(), v0.end(), v1.begin(), pointeesEqual<const Object*>);
	printf("containerValuesEqual: %s\n", containerValuesEqual ? "true" : "false");	// true

	return 0;
}
