#pragma once
#include "LinearAllocator.h"
#include <iostream>
#include <vector>
#include <string> 

template<typename Type>

LinearAllocator<Type>::LinearAllocator(int count) noexcept : Count(count), Area(new Type[count]), Used(Area), Start(Area)
{
	static_assert(!std::is_same<Type, void*>::value, "Type can't be a void*");
}

template<typename Type>
LinearAllocator<Type>::LinearAllocator(const LinearAllocator<Type>& other) noexcept {
	if (other.AllocateCount)
	{	
		this->LinearAllocator<Type>::Count = other.Count;
		this->LinearAllocator<Type>::Area = new Type[other.Count];
		this->LinearAllocator<Type>::AllocateCount = other.AllocateCount;

		for (int i = 0; i < other.Count;i++) {
			this->LinearAllocator<Type>::Area[i] = other.Area[i];
		}
	}

}

template<typename Type>
LinearAllocator<Type>& LinearAllocator<Type>::operator = (LinearAllocator<Type> other) {

	std::swap(this->LinearAllocator<Type>::Area, other.Area);
	std::swap(this->LinearAllocator<Type>::AllocateCount, other.AllocateCount);
	std::swap(this->LinearAllocator<Type>::Count, other.Count);

	for (int i = 0; i < other.Count; i++) { this->LinearAllocator<Type>::Area[i] = other.Area[i]; }
		
	return *this;
}


template<typename Type>
void LinearAllocator<Type>::PushOne(Type type) {

	if (LinearAllocator<Type>::AllocateCount < this->LinearAllocator<Type>::Count) {

		this->LinearAllocator<Type>::Used->~Type();
		this->LinearAllocator<Type>::Area[LinearAllocator<Type>::AllocateCount] = type;
		this->LinearAllocator<Type>::AllocateCount++;

		if (AllocateCount != this->Count) 
			this->LinearAllocator<Type>::Used = this->LinearAllocator<Type>::Used + 1;
	}
	else { throw std::runtime_error("I haven't place more");}
}



template<typename Type>
void LinearAllocator<Type>::PushOne(Type* type) {
	if (LinearAllocator<Type>::AllocateCount < this->LinearAllocator<Type>::Count) {

		this->LinearAllocator<Type>::Used->~Type();
		this->LinearAllocator<Type>::Area[LinearAllocator<Type>::AllocateCount] = *(type);
		this->LinearAllocator<Type>::AllocateCount++;

		if (AllocateCount != this->Count) 
			this->LinearAllocator<Type>::Used = this->LinearAllocator<Type>::Used + 1;
	}
	else { throw std::runtime_error("I haven't place more"); }
}


template<typename Type>
void LinearAllocator<Type>::PushArray(Type* type, size_t count) {

	if (count <= (this->LinearAllocator<Type>::Count - this->LinearAllocator<Type>::AllocateCount)) {
		for (int i = 0; i < count; i++) {
			this->LinearAllocator<Type>::Area[LinearAllocator<Type>::AllocateCount] = *(type);
			type++; LinearAllocator<Type>::AllocateCount++;
			
			if (LinearAllocator<Type>::AllocateCount != this->LinearAllocator<Type>::Count) 
				this->LinearAllocator<Type>::Used += 1;
		}
	}
}


template<typename Type>
Type * LinearAllocator<Type>::ReturnUsedElement() {
	return this->Used - 1;
}


template<typename Type>
void LinearAllocator<Type>::ClearLastOne() {
	Used->~Type();
	AllocateCount--;
}


template<typename Type>
void LinearAllocator<Type>::ClearAll() {
	delete[] this->LinearAllocator<Type>::Area;
	this->LinearAllocator<Type>::Area = nullptr;
	this->LinearAllocator<Type>::Area = new Type[this->LinearAllocator<Type>::AllocateCount];
	this->LinearAllocator<Type>::Used = this->LinearAllocator<Type>::Area;
}


template<typename Type>
LinearAllocator<Type>::~LinearAllocator() {
	delete[] this->LinearAllocator<Type>::Area;
}


template<typename Type>
Type* LinearAllocator<Type>::ReturnStartElement() {
	return this->LinearAllocator<Type>::Start;
}


template<typename Type>
void LinearAllocator<Type>::ShowAllElements() const {

	bool flag = ValidatePrintableType(*(Area));
	#if flag
	int countBuffer = LinearAllocator<Type>::Count;

	while (countBuffer--) {
		std::cout << LinearAllocator<Type>::Area[countBuffer] << " \n";
	}
	#endif
}


template<typename Type>
bool LinearAllocator<Type>::ValidatePrintableType(Type& type) const {
	
	int controllVal = 0;
	const int countTrue = 4;

	bool flags[countTrue]{
		typeid(type) == typeid(int),
		typeid(type) == typeid(char),
		typeid(type) == typeid(const char),
		typeid(type) == typeid(std::string),
	};

	for (int i = 0; i < countTrue; i++) {
		controllVal += (int)flags[i];
	}

	return controllVal > 0 ? true : false;
}


