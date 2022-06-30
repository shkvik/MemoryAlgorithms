#pragma once

#include "..\IAllocator.h"

template<typename Type>
class LinearAllocator : public IAllocator <Type> {

public:
	
		
	explicit LinearAllocator(int count) noexcept;

	LinearAllocator(const LinearAllocator<Type>& other) noexcept;

	/* IAllocator Interface Access */
	void PushOne(Type type) override final;
	void PushArray(Type* type, size_t count) override final;
	void ClearLastOne() override final;
	void ClearAll() override final;

	/* LinearAllocator methods */
	void PushOne(Type* type);

	void ShowAllElements() const;


	Type* ReturnUsedElement();
	Type* ReturnStartElement();
	
	LinearAllocator<Type>& operator = (LinearAllocator<Type> other);

	~LinearAllocator();

	
	Type* Area = nullptr;
	int AllocateCount = 0;

private:

	int Count;
	

	
	Type* Start = nullptr;
	Type* End = nullptr;
	Type* Used = nullptr;
	
	bool ValidatePrintableType(Type& type) const;
};

