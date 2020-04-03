#include <iostream>
#include <memory>

using namespace std;

//Данные в буффер
struct Node {
	int data;
	shared_ptr<Node> next;
};

//Реализация буфера. 
class Queue {
private:
	
	shared_ptr<Node> top;
	shared_ptr<Node> bottom; //указывает на последний элемент в очереди
	unsigned int count = 0;    //счетчик количества элементов

public:

	Queue(unsigned int size) {
	
		shared_ptr<Node> current(new Node);
		shared_ptr<Node> begin(new Node);
		current->data = 0;
		current->next = current;   //закольцовываем если буфер размером 1
		begin = current;

		this->top = begin;
		for (int i = 1; i < size; i++) {
			shared_ptr<Node> tmp(new Node);
			bottom = tmp;
			tmp->data = 0;
			tmp->next = begin;
			current->next = tmp;
			current = current->next;
		}
	}

	//Добавение элемента в буфер
	void enqueue(int value){

		bottom = bottom->next;
		bottom->data = value;
		count++;

	}

	//Удаление элемента из буфера	
	int dequeue(){
		if (count != 0) {
			int deleted;
			deleted = top->data;
			top->data = 0;
			top = top->next;         //теперь первый элемент следующий в очереди.
			count--;
			return deleted;
		}
		else {
			return -1;
		}
	}

	//Возвращает количество элементов в буфере
	unsigned int size() {
		return count;
	}

	//Флаг пустого буфера
	bool isEmpty(){
		if (count == 0) { return true; }
		else return false;
	}

	//Возвращение первого элемента в очереди
	int first() {
		return top->data;
	}

};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	unsigned int size = 10;
	Queue Buffer(10);
	cout << "=Заполните буффер=\n";
	for (int i = 0; i < size; i++) {
		cout << "Введите число: ";
		cin >> n;
		if (n == -1) { i = size; }
		else Buffer.enqueue(n);
	}
	for (int i = 0; i < size - 3; i++) {
		cout << "\nСодержание очереди: " << Buffer.first();
		Buffer.dequeue();
	}
	for (int i = 0; i < 3; i++) {
		cout << "Введите число: ";
		cin >> n;
		if (n == -1) { i = size; }
		else Buffer.enqueue(n);
	}
	for (int i = 0; i < size; i++) {
		cout << "\nСодержание очереди: " << Buffer.first();
		Buffer.dequeue();
	}
}