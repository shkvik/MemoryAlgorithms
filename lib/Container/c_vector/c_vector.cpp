#include "c_vector.h"
#include <cassert>

template<typename Type>
void custum::deleter<Type>::operator()(Type* ptr) {
	delete ptr;
}

template<typename Type>
void custum::deleter<Type[]>::operator()(Type* ptr) {
	delete[] ptr;
}


template<typename Type, typename mode>
custum::vector<Type, mode>::~vector() {

	for (size_t i = 0; i < m_size - 1; i++) {
		data[i].~Type();
	}
	delete[] data;
}



template<typename Type, typename mode>
void custum::vector<Type, mode>::push_back(type value) {
	if (m_size == m_capacity) {

		m_capacity = std::max(m_capacity * m_size + 1, static_cast<size_t>(2u));
		Type* temp = static_cast<Type*>(operator new(m_capacity * sizeof(Type)));

		try { for (size_t i = 0u; i < m_size; ++i) temp[i] = data[i]; }
		catch(...) { delete[] temp; throw; }
		delete[] data;

		data = temp;
		data[m_size++] = value;
	}
	else {

	}
}

template<typename Type, typename mode>
void custum::vector<Type, mode>::pop_back(type value) {
	
}

template<typename Type, typename mode>
typename custum::vector<Type, mode>::type custum::vector<Type, mode>::operator[] (const size_t number) const {
	assert(!(number >= m_size));
	return data[number];
}
