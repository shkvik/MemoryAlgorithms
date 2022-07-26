#pragma once

namespace ptr_deleter
{
	template<typename Type>
	struct Deleter final {
		void delete_ptr(Type* ptr);
	};

	template<typename Type>
	struct Deleter<Type[]> final {
		void delete_ptr(Type* ptr);
	};
}

template<typename Type>
void ptr_deleter::Deleter<Type>::delete_ptr(Type* ptr) {
	delete ptr;
}

template<typename Type>
void ptr_deleter::Deleter<Type[]>::delete_ptr(Type* ptr) {
	delete[] ptr;
}