#pragma once
#include <iostream>


namespace auto_ptr_helper
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


template<typename Type, typename Mode = auto_ptr_helper::Handler<Type>>
class AutoPointer 
{
	using type = typename std::remove_extent<Type>::type;
	using handler = Mode;

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
	handler _handler;
	
};
