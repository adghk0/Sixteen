/*
ArrayList class
Made by Eom Kyoungjun
Copyright 2020. Eom Kyoungjun. All rights reversed.
*/
#pragma once

// Arraylist class
// ���� �迭 Ŭ����
template<typename T>
class ArrayList {
private:
	// the variable of data;
	// ������ ����
	T* array;
	// the length of array
	// �迭�� ����
	int length;

public:
	// constructor
	// ������
	ArrayList() {
		// assign spaces in memory
		// �޸� �Ҵ�
		length = 0;
		array = (T*)malloc(sizeof(T) * length);
	}
	// destructor
	// �Ҹ���
	~ArrayList() {
		// return spaces in memory
		// �޸� ��ȯ
		free(array);
	}

	// return the size of array
	// �迭 ũ�� ��ȯ
	int size() { return length; }

	// get all array
	// ��ü �� ��������
	T* get() { return array; }
	// get value at index
	// ���� ��ġ�� �� ��������
	T get(int index) { return array[index]; }

	// add data at the end
	// �� �ڿ� �� �߰�
	bool add(T data);
	// add data at index
	// ���� ��ġ�� �� �߰�
	bool add(T data, int index);
	// set data at index
	// ���� ��ġ �� ����
	bool set(T data, int index);
	// delete data at index
	// ���� ��ġ �� ����
	bool del(int index);

	// get the first data
	// �� ó�� �� ��������
	T getFirst() { return get(0); }
	// get the last data
	// �� ������ �� ��������
	T getLast() { return get(length - 1); }
	// delete the first data
	// �� ó�� �� ����
	bool delFirst() { return del(0); }
	// delete the last data
	// �� ������ �� ����
	bool delLast() { return del(length - 1); }

	// make a new object which is same as this 
	// ������ ��ü ����
	ArrayList<T>* clone();
};

template<typename T>
inline bool ArrayList<T>::add(T data)
{
	// ���� 1����
	length++;
	array = (T*)realloc(array, length * sizeof(T));

	array[length - 1] = data;
	return true;
}
template<typename T>
inline bool ArrayList<T>::add(T data, int index)
{
	if (index < 0 || index > length) // �ε��� ������ ��� (0 <= index <= length)
		return false;

	// ���� 1����
	length++;
	array = (T*)realloc(array, length * sizeof(T));

	// index ���� ���� �̵�
	memmove(array + index + 1, array + index, sizeof(T) * (length - index));

	array[index] = data;
	return true;
}

template<typename T>
inline bool ArrayList<T>::set(T data, int index)
{
	if (index < 0 || index >= length) // �ε��� ������ ��� (0 <= index < length)
		return false;

	array[index] = data;
	return true;
}
template<typename T>
inline bool ArrayList<T>::del(int index)
{
	if (index < 0 || index >= length) // �ε��� ������ ��� (0 <= index < length)
		return false;

	length--;

	// index ���� �� �̵�
	memmove(array + index, array + index + 1, sizeof(T) * (length - index));
	array = (T*)realloc(array, length * sizeof(T));

	return true;
}
template<typename T>
inline ArrayList<T>* ArrayList<T>::clone()
{
	// ���ο� ��ü ����
	ArrayList<T>* cl = new ArrayList<T>();
	// ��� ���� ����
	cl->length = length;
	cl->array = (T*)realloc(cl->array, length * sizeof(T));
	// �� ����
	memcpy(cl->array, array, length * sizeof(T));
	return cl;
}