#include "c_vector.h"


template<typename Type>
void custum::deleter<Type>::operator()(Type* ptr) {
	delete ptr;
}

template<typename Type>
void custum::deleter<Type[]>::operator()(Type* ptr) {
	using namespace custom;
	delete[] ptr;
}

template<typename Type, typename mode>
void custum::vector<Type, mode>::push_back(Type* value) {
	if (m_size == m_capacity) {
		const size_t INITIAL_BUFFER_SIZE = 2u;
		m_capacity = std::max(m_capacity * 2, INITIAL_BUFFER_SIZE);

		Type* temp = static_cast<Type*>(operator new(m_capacity * sizeof(Type)));

		try {
			for (size_t i = 0u; i < m_size; ++i) {
				temp[i] = data[i];
			}
		}
		catch(...) {
			delete[] temp;
			throw;
		}

		delete[] data;
		data = temp;
	}

	data[m_size++] = value;
}
