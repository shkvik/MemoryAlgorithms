#include <include.h>

using namespace std;

class ForTest {
public:


	ForTest() {
		Number++;
		hisNumber = Number;
		std::cout << "Call Constructor" << hisNumber << " \n";
		this->Array = new int[10]{ 0 };

		for (int i = 0; i < 9; i++) {
			Array[i] = i;
		}
	}

	ForTest(int check) : hisNumber(check) {
		std::cout << "Call Constructor" << hisNumber << " \n";
	}
	~ForTest() {
		delete[] Array;
		std::cout << "Call Destructor: " << hisNumber << " \n";
	}

	void ShowMyElem() {
		for (int i = 0; i < 9; i++) {
			cout << Array[i] << " \n";
		}
	}

	int* Array = nullptr;
	int Changeable;
	int hisNumber = 0;

	static uint64_t Number;
};

uint64_t ForTest::Number = 0;

int main(){
	LinearAllocator<ForTest> linear(4);
	LinearAllocator<ForTest> add(linear);

	add = linear;

	linear.PushOne(ForTest(5));
	linear.PushOne(ForTest(6));

	linear.ShowAllElements();

	

	linear.ClearAll();

	

	std::cout << "Hello World";

	for (int i = 0; i < 4; i++) {
		std::cout << linear.Area[i].hisNumber << "\n";
	}

	std::cout << linear.AllocateCount << "\n";
	std::cout << (linear.ReturnUsedElement() - 2)->hisNumber;

	linear.PushOne(ForTest(5));
	linear.PushOne(ForTest(6));



	return 0;
}