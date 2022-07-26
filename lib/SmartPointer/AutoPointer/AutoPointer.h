#pragma once
#include <iostream>
#include "..\ISmartPointer.h"


template<typename Type, typename Mode = ptr_deleter::Deleter<Type>>
class AutoPointer 
{
	using type = typename std::remove_extent<Type>::type;
	using deleter = Mode;

public:

	explicit AutoPointer() = default;
	explicit AutoPointer(type* object) noexcept;
	AutoPointer(AutoPointer<Type>& other);

	AutoPointer<Type>& operator = (AutoPointer<Type>& other);
	AutoPointer<Type>& operator = (type* object);

	type* operator-> ();
	type* operator* ();

	operator bool();

	~AutoPointer();

private:
	
	type* m_ptr = nullptr;
	deleter _deleter;
	
};
