#pragma once
#include <iostream>
#include "..\ISmartPointer.h"


template<typename Type, typename Mode = ptr_deleter::Deleter<Type>>
class ScopedPointer {

	using type = typename std::remove_extent<Type>::type;
	using deleter = Mode;

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

	deleter _deleter;
	type* m_ptr = nullptr;

};