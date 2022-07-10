#pragma once
#include "AutoPointer.h"

template<typename Type>
AutoPointer<Type>::AutoPointer(Type* object) noexcept : My_Object(object) {
	object = nullptr;
}


template<typename Type>
AutoPointer<Type>::AutoPointer(AutoPointer<Type>& other) {
	this->My_Object = other.My_Object;
	other.My_Object = nullptr;
}

template<typename Type>
AutoPointer<Type>::~AutoPointer() {
	delete My_Object;
}

template<typename Type>
AutoPointer<Type>& AutoPointer<Type>::operator = (AutoPointer<Type>& other) {
	delete My_Object;
	My_Object = other.My_Object;
	other.My_Object = nullptr;
	return *this;
}

template<typename Type>
AutoPointer<Type>& AutoPointer<Type>::operator = (const Type* object) {
	delete My_Object;
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



template<typename Type, size_t size>
AutoPointer<Type[size]>::AutoPointer(int size) noexcept : My_Object(new Type[size]), ArrayCount(size)
{

}

template<typename Type, size_t size>
AutoPointer<Type[size]>::~AutoPointer() { if(My_Object != nullptr) delete[] My_Object; }
	
