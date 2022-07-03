#include "ScopedPointer.h"

template<typename Type>
ScopedPointer<Type>::ScopedPointer(Type* object) noexcept : My_Object(object) {
	
}


template<typename Type>
ScopedPointer<Type>::~ScopedPointer() {
	delete this->ScopedPointer<Type>::My_Object;
}


template<typename Type>
Type* ScopedPointer<Type>::operator ->() { return this->My_Object; }


template<typename Type>
Type* ScopedPointer<Type>::operator *() { return this->*My_Object; }


template<typename Type>
ScopedPointer<Type>::operator bool() { return ScopedPointer<Type>::My_Object != nullptr ? true : false; }
	
