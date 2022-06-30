#pragma once

template<typename Type>
class IAllocator {
public:
	virtual void PushOne(Type type) = 0;
	virtual void PushArray(Type * type, size_t count) = 0;
	virtual void ClearLastOne() = 0;
	virtual void ClearAll() = 0;
	virtual ~IAllocator() {}
};



