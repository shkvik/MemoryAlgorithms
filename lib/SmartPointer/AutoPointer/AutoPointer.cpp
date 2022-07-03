#pragma once
#include "AutoPointer.h"


template<typename Type>
int AutoPointer<Type>::ThisCopy = 0;


template<typename Type>
AutoPointer<Type>::AutoPointer(Type* object) noexcept : My_Object(object), IsArray(false)
{ object = nullptr; }
	

template<typename Type>
AutoPointer<Type>::AutoPointer(Type* object, const int count) noexcept : My_Object(object), ArrayCount(count),
IsArray(true) { object = nullptr; }
	

template<typename Type>
AutoPointer<Type>::AutoPointer(const int size) noexcept : My_Object(new Type[size]), ArrayCount(count),
IsArray(true) {}

	
template<typename Type>
AutoPointer<Type>::AutoPointer(AutoPointer<Type>& other) {
	if (other.IsArray) this->IsArray = true;

	this->My_Object = other.My_Object;
	AutoPointer<Type>::ThisCopy++;

	other.My_Object = nullptr;
	other.IsArray = false;
	other.ArrayCount = 0;
}


template<typename Type>
AutoPointer<Type>::~AutoPointer() {
	delete_my_Object();
}


template<typename Type>
AutoPointer<Type>& AutoPointer<Type>::operator = (AutoPointer<Type>& other) {
	if (other.IsArray) this->IsArray = true;

	delete_my_Object();

	this->My_Object = other.My_Object;
	AutoPointer<Type>::ThisCopy++;

	other.My_Object = nullptr;
	other.IsArray = false;
	other.ArrayCount = 0;

	return *this;
}


template<typename Type>
AutoPointer<Type>& AutoPointer<Type>::operator = (const Type* object) {
	if (IsArray) 
		throw std::runtime_error("You can't do this");

	delete_my_Object();

	this->My_Object = object;
	object = nullptr;

	return *this;
}


template<typename Type>
Type* AutoPointer<Type>::operator ->() { return this->My_Object; }


template<typename Type>
Type* AutoPointer<Type>::operator *() { return this->*My_Object; }


template<typename Type>
AutoPointer<Type>::operator bool() { return AutoPointer<Type>::My_Object != nullptr ? true : false; }


template<typename Type>
void AutoPointer<Type>::delete_my_Object() {
	if (this->My_Object != nullptr) {
		if (this->IsArray)  delete[] this->My_Object;
		else                delete   this->My_Object;
	}
}