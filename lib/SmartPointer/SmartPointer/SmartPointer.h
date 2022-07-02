#pragma once

template<typename Type>
class SmartPointer {
public:

	explicit SmartPointer() noexcept = default;
	explicit SmartPointer(Type* Object) noexcept;
	
	Type* operator ->();
	Type* operator  *();

	~SmartPointer();

private:

	SmartPointer<Type>& operator = (const SmartPointer<Type>* other);
	SmartPointer(const SmartPointer<Type>& other);
	Type* My_Object;

};