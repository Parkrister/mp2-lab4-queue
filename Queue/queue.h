#pragma once

template <class T>
class TQueue {
	int MaxSize;
	int head;
	int tail;
	int DataCount;
	T* pMem;
public:
	TQueue(int s = 10) { // конструктор по умолчанию
		if (!s) {
			throw  0;
		}

		head = 0;
		tail = -1;
		DataCount = 0;
		MaxSize = s;
		pMem = new T[MaxSize];
	}

	TQueue(const TQueue<T>& q) { // конструктор копирования
		MaxSize = q.MaxSize;
		DataCount = q.DataCount;
		head = q.head;
		tail = q.tail;
		pMem = new T[MaxSize];
		for (int i = 0; i < MaxSize; i++) {
			pMem[i] = q.pMem[i];
		}
	}

	~TQueue() {
		if (pMem) {
			delete[] pMem;
			pMem = 0;
		}
	}

	TQueue& operator=(const TQueue<T>& q) {
		if (MaxSize != q.MaxSize) {
			delete[] pMem;
			MaxSize = q.MaxSize;
			pMem = new T[MaxSize];
		}
		head = q.head;
		tail = q.tail;
		DataCount = q.DataCount;
		for (int i = 0; i < MaxSize; i++) {
			pMem[i] = q.pMem[i];
		}
		return *this;
	}

	T front() {
		if (!empty()) return pMem[head];
		else throw 0;
	}

	bool empty() {	return DataCount == 0;	}

	bool full() { return DataCount == MaxSize; }

	void push(const T elem);
	T pop();
};

template <class T>
void TQueue<T>::push(T elem) {
	if (!full()) {
		DataCount++;
		tail = (tail + 1) % MaxSize;
		pMem[tail] = elem;
	}
	else {
		throw 1;
	}
}

template <class T>
T TQueue<T>::pop() {
	if (!empty()) {
		T tmp = pMem[head];
		DataCount--;
		head = (head + 1) % MaxSize;
		return tmp;
	}
	else {
		throw 0;
	}
}