#include <include.h>



using namespace std;

class ForTest {
public:


	ForTest(const ForTest& other) {

		std::cout << "Call copy Constructor" << hisNumber << " \n";

		CopyFlag = true;

		if (other.Array)       { this->Array = new int(*other.Array); }
		if (other.Changeable)  { this->Changeable = other.Changeable; }
		if (other.hisNumber)   { this->hisNumber = other.hisNumber; }
	}

	ForTest() {

		std::cout << "Call Constructor" << hisNumber << " \n";
		this->Array = new int[10];

		for (int i = 0; i < 9; i++) {
			Array[i] = i;
		}

	}

	ForTest(int check) : hisNumber(check) {
		this->Array = new int[10];

		for (int i = 0; i < 9; i++) {
			Array[i] = i;
		}
		std::cout << "Call Constructor" << hisNumber << " \n";
	}
	~ForTest() {
		delete[] Array;
		if (CopyFlag) {
			std::cout << "Call Copy Destructor: " << hisNumber << " \n";
		}
		else {
			std::cout << "Call Destructor: " << hisNumber << " \n";
		}
	}

	void ShowMyElem() {
		for (int i = 0; i < 9; i++) {
			cout << Array[i] << " \n";
		}
	}

	int* Array = nullptr;
	int Changeable;
	int hisNumber = 0;


	ForTest& operator = (const ForTest other) {
		if (other.Array)      { this->Array = new int(*other.Array); }
		if (other.Changeable) { this->Changeable = other.Changeable; }
		if (other.hisNumber)  { this->hisNumber = other.hisNumber;   }
		return *this;
	};


	bool CopyFlag = false;
};



int main(){

	LinearAllocator<ForTest> linear(4);
	
	linear.PushOne(ForTest(5));
	
	linear.PushOne(ForTest(6));
	linear.ShowAllElements();
	linear.ClearAll();

	std::cout << "Hello World";
	
	for (int i = 0; i < 4; i++) {
		std::cout << linear.Area[i].hisNumber << "\n";
	}
	
	std::cout << linear.AllocateCount << "\n";
	std::cout << linear.ReturnUsedElement()->hisNumber;

	linear.PushOne(ForTest(5));
	linear.PushOne(ForTest(6));

	linear.ClearLastOne();

	ScopedPointer<ForTest> empty_obj(new ForTest());
	ScopedPointer<ForTest> two_obj(new ForTest(2));

	if (!empty_obj) std::cout << empty_obj << " \n";
	
	AutoPointer<ForTest> auto_ptr_one(new ForTest);
	AutoPointer<ForTest> auto_ptr_two(new ForTest);

	auto_ptr_one = auto_ptr_two;


	AutoPointer<ForTest[]> auto_ptr_three(new ForTest[4]);
	AutoPointer<ForTest[]> auto_ptr_four(auto_ptr_three);

	auto_ptr_three = new ForTest[5];

	return 0;
}