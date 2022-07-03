#pragma once

template<typename Type>
class AutoPointer {

public:

	explicit AutoPointer() = default;
	explicit AutoPointer(Type* object) noexcept;
	explicit AutoPointer(const int size) noexcept;
	explicit AutoPointer(Type* object, const int count) noexcept;

	AutoPointer(AutoPointer<Type>& other);

	AutoPointer<Type>& operator = (AutoPointer<Type>& other);
	AutoPointer<Type>& operator = (const Type* object);

	Type* operator ->();
	Type* operator  *();
	operator bool();

	~AutoPointer();

private:
	
	void delete_my_Object();

	static int ThisCopy;
	int ArrayCount = 0;

	bool IsArray = false;
	Type* My_Object = nullptr;
	
};

