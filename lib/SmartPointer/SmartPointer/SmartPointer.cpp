#include "SmartPointer.h"

template<typename Type>
SmartPointer<Type>::SmartPointer(Type* Object) noexcept : My_Object(Object) {
	
}


template<typename Type>
SmartPointer<Type>::~SmartPointer() {
	delete this->SmartPointer<Type>::My_Object;
}


template<typename Type>
Type* SmartPointer<Type>::operator ->() { return this->My_Object; }


template<typename Type>
Type* SmartPointer<Type>::operator *() { return this->*My_Object; }

