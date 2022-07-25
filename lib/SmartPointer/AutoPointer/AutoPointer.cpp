#pragma once
#include "AutoPointer.h"



template<typename Type>
void auto_ptr_helper::Handler<Type>::delete_ptr(Type* ptr) {
	delete ptr;
}

template<typename Type>
void auto_ptr_helper::Handler<Type[]>::delete_ptr(Type* ptr) {
	delete[] ptr;
}

template<typename Type, typename Mode>
AutoPointer<Type, Mode>::AutoPointer(type* object) noexcept : m_ptr(object) {
	object = nullptr;
}

template<typename Type, typename Mode>
AutoPointer<Type, Mode>::AutoPointer(AutoPointer<Type>& other) {
	this->m_ptr = other.m_ptr;
	other.m_ptr = nullptr;
}


template<typename Type, typename Mode>
AutoPointer<Type, Mode>::~AutoPointer() {
	if (m_ptr != nullptr) _handler.delete_ptr(m_ptr);
}

template<typename Type, typename Mode>
AutoPointer<Type>& AutoPointer<Type, Mode>::operator = (AutoPointer<Type>& other) {
	this->m_ptr = other.m_ptr;
	other.m_ptr = nullptr;
	return *this;
}

template<typename Type, typename Mode>
AutoPointer<Type>& AutoPointer<Type, Mode>::operator = (AutoPointer<Type, Mode>::type* object) {
	_handler.delete_ptr(m_ptr);
	this->m_ptr = object;
	object = nullptr;	
	return *this;
}


template<typename Type, typename Mode>
AutoPointer<Type, Mode>::operator bool() { 
	return AutoPointer<Type>::My_Object != nullptr ? true : false;
}

template<typename Type, typename Mode>
typename AutoPointer<Type, Mode>::type* AutoPointer<Type, Mode>::operator-> () {
	return this->m_ptr;
}

template<typename Type, typename Mode>
typename AutoPointer<Type, Mode>::type* AutoPointer<Type, Mode>::operator* () {
	return this->*m_ptr;
}