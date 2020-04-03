#include <iostream>

using namespace std;

//Данные в буффер
struct Node {
	int data;
	Node* next;
};

//Реализация буфера. 
class Queue {
private:
	
	Node* top = new Node();    //указание на первый в очереди элемент
	Node* bottom = new Node(); //указывает на последний элемент в очереди
	unsigned int count = 0;    //счетчик количества элементов

public:

	Queue(unsigned int n) {
		Node* current = new Node();
		Node* begin = new Node();
		current->data = 0;
		current->next = current;   //закольцовываем если буфер размером 1
		begin = current;
		top = begin;
		for (int i = 1; i < n; i++) {
			Node* tmp = new Node();
			bottom = tmp;
			tmp->data = 0;
			tmp->next = begin;
			current->next = tmp;
			current = current->next;
		}
	}

	//Добавение элемента в буфер
	void Enqueue(int n){
		bottom = bottom->next;
		bottom->data = n;
		count++;
	}

	//Удаление элемента из буфера	
	int Dequeue(){
		if (count != 0) {
			int deleted;
			deleted = top->data;
			top->data = 0;
			top = top->next;         //теперь первый элемент следующий в очереди.
			return deleted;
		}
		else {
			return -1;
		}
	}

	//Возвращает количество элементов в буфере
	unsigned int Count() {
		return count;
	}

	//Флаг пустого буфера
	bool isEmpty(){
		if (count == 0) { return true; }
		else return false;
	}

	//Возвращение первого элемента в очереди
	int Top() {
		return top->data;
	}

};

/*
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
		else Buffer.Enqueue(n);
	}
	for (int i = 0; i < size - 3; i++) {
		cout << "\nСодержание очереди: " << Buffer.Top();
		Buffer.Dequeue();
	}
	for (int i = 0; i < 3; i++) {
		cout << "Введите число: ";
		cin >> n;
		if (n == -1) { i = size; }
		else Buffer.Enqueue(n);
	}
	for (int i = 0; i < size; i++) {
		cout << "\nСодержание очереди: " << Buffer.Top();
		Buffer.Dequeue();
	}
}*/