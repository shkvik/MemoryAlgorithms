#pragma once
#include <iostream>

namespace scoped_ptr_helper
{
	template<typename Type>
	struct Handler {
		void delete_ptr(Type* ptr);
	};

	template<typename Type>
	struct Handler<Type[]> {
		void delete_ptr(Type* ptr);
	};

}

template<typename Type, typename Mode = scoped_ptr_helper::Handler<Type>>
class ScopedPointer {

	using type = typename std::remove_extent<Type>::type;
	using handler = Mode;

public:

	explicit ScopedPointer() noexcept = default;
	explicit ScopedPointer(type* Object) noexcept;
	
	type* operator ->();
	type* operator  *();
		  operator bool();

	~ScopedPointer();

private:
	
	ScopedPointer<Type,Mode>& operator = (const ScopedPointer<Type,Mode>* other);
	ScopedPointer(const ScopedPointer<Type>& other);

	handler _handler;
	type* m_ptr = nullptr;

};