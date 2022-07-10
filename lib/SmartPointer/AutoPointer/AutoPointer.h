#pragma once
#include <iostream>

template<typename Type>
class AutoPointer 
{
	//static_assert(!std::is_array<Type>::value);
public:

	explicit AutoPointer() = default;
	explicit AutoPointer(Type* object) noexcept;
	AutoPointer(AutoPointer<Type>& other);


	AutoPointer<Type>& operator = (AutoPointer<Type>& other);
	AutoPointer<Type>& operator = (const Type* object);

	Type* operator ->();
	Type* operator  *();

	operator bool();

	~AutoPointer();

private:
	
	Type* My_Object = nullptr;
	
};


template<typename Type, size_t size>
class AutoPointer<Type[size]> 
{
public:
	
	explicit AutoPointer() = default;
	explicit AutoPointer(int size) noexcept;
	AutoPointer(AutoPointer<Type[size]>& other);


	AutoPointer<Type[size]>& operator = (AutoPointer<Type[size]>& other);
	AutoPointer<Type[size]>& operator = (const Type* object);

	operator bool();

	~AutoPointer();

private:

	int ArrayCount = 0;
	Type* My_Object = nullptr;
};


