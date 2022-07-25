#pragma once
#include "SharedPointer.h"

template<typename Type>
void shared_ptr_helper::Handler<Type>::delete_ptr(Type* ptr) {
	delete ptr;
}

template<typename Type>
void shared_ptr_helper::Handler<Type[]>::delete_ptr(Type* ptr) {
	delete[] ptr;
}

template<typename Type, typename Mode>
SharedPointer<Type, Mode>::SharedPointer(type* object) noexcept : m_ptr(object) {
	SharedPointer<Type, Mode>::ptr_count++;
	object = nullptr;
}

template<typename Type, typename Mode>
SharedPointer<Type, Mode>::SharedPointer(const SharedPointer<Type, Mode>& other) noexcept : m_ptr(other.m_ptr) {
	SharedPointer<Type, Mode>::ptr_count++;
}

template<typename Type, typename Mode>
typename SharedPointer<Type, Mode>::type* SharedPointer<Type, Mode>::operator-> () {
	return this->m_ptr;
}

template<typename Type, typename Mode>
typename SharedPointer<Type, Mode>::type* SharedPointer<Type, Mode>::operator* () {
	return this->*m_ptr;
}

template<typename Type, typename Mode>
SharedPointer<Type, Mode>& SharedPointer<Type, Mode>::operator= (SharedPointer<Type, Mode>& other) {
	if (other.m_ptr != nullptr) {
		SharedPointer<Type, Mode>::ptr_count++;
		this->m_ptr = other.m_ptr;
	}
	else {
		throw std::runtime_error("invalid copy nullptr object");
	}
}

template<typename Type, typename Mode>
size_t SharedPointer<Type, Mode>::GetPtrCount() {
	return this->ptr_count;
}

template<typename Type, typename Mode>
SharedPointer<Type, Mode>::~SharedPointer() {
	if (m_ptr != nullptr) {
		_handler.delete_ptr(m_ptr);
	}
}

template<typename Type, typename Mode>
int SharedPointer<Type, Mode>::ptr_count = 0;
