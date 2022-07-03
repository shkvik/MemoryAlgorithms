#pragma once

template<typename Type>
class ScopedPointer {
public:

	explicit ScopedPointer() noexcept = default;
	explicit ScopedPointer(Type* Object) noexcept;
	
	Type* operator ->();
	Type* operator  *();
		  operator bool();

	~ScopedPointer();

private:
	
	ScopedPointer<Type>& operator = (const ScopedPointer<Type>* other);
	ScopedPointer(const ScopedPointer<Type>& other);

	Type* My_Object = nullptr;

};