#pragma once
#include <iostream>




template<typename Type>
struct Handler {
	void delete_ptr (Type* ptr);
};

template<typename Type>
struct Handler<Type[]> {
	void delete_ptr (Type* ptr);
};



template<typename Type, typename Mode = Handler<Type>>
class AutoPointer 
{

public:

	using type = typename std::remove_extent<Type>::type;
	using handler = Mode;

	explicit AutoPointer() = default;
	explicit AutoPointer(type* object) noexcept;
	AutoPointer(AutoPointer<Type>& other);

	AutoPointer<Type>& operator = (AutoPointer<Type>& other);
	AutoPointer<Type>& operator = (type* object);

	type* operator-> () { return this->m_ptr; };
	type* operator* () { return this->*m_ptr; };

	operator bool();

	~AutoPointer();

private:
	
	type* m_ptr = nullptr;
	handler _handler;
	
};
