#pragma once
#include "ScopedPointer.h"

template<typename Type>
void scoped_ptr_helper::Handler<Type>::delete_ptr(Type* ptr) {
	delete ptr;
}

template<typename Type>
void scoped_ptr_helper::Handler<Type[]>::delete_ptr(Type* ptr) {
	delete[] ptr;
}

template<typename Type, typename Mode>
ScopedPointer<Type, Mode>::ScopedPointer(type* object) noexcept : m_ptr(object) {
	object = nullptr;
}

template<typename Type, typename Mode>
ScopedPointer<Type, Mode>::~ScopedPointer() {
	if(m_ptr != nullptr) _handler.delete_ptr(m_ptr);
}


template<typename Type, typename Mode>
typename ScopedPointer<Type,Mode>::type* ScopedPointer<Type, Mode>::operator ->() { 
	return this->m_ptr;
}


template<typename Type, typename Mode>
typename ScopedPointer<Type, Mode>::type* ScopedPointer<Type, Mode>::operator *() {
	return this->*m_ptr;
}


template<typename Type, typename Mode>
ScopedPointer<Type, Mode>::operator bool() {
	return m_ptr != nullptr ? true : false;
}
	
