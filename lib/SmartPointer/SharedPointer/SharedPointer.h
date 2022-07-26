#pragma once 
#include <iostream>
#include "..\ISmartPointer.h"


template<typename Type, typename Mode = ptr_deleter::Deleter<Type>>
class SharedPointer {

	using type = typename std::remove_extent<Type>::type;
	using handler = Mode;

public:
	explicit SharedPointer() noexcept = default;
	explicit SharedPointer(type* object) noexcept;
	explicit SharedPointer(const SharedPointer<Type, Mode>& other) noexcept;


	type* operator-> ();
	type* operator* ();
	SharedPointer<Type, Mode>& operator= (SharedPointer<Type, Mode>& other);

	operator bool();


	size_t GetPtrCount() noexcept;
	

	~SharedPointer();

private:

	static int ptr_count = 0;
	handler _deleter;
	type* m_ptr = nullptr;
};

