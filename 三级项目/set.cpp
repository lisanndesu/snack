//����Set�࣬�̳���List�ࡣSet�ཫʹ��List�Ļ����ṹ���洢Ԫ�أ�����Ӷ���ķ�����ִ�м��ϲ�����
#include <iostream>
#include "head.h"

using namespace std;

template <typename T>
class Set : public List<T> {
public:
    // ���캯������������
    Set() : List<T>() {}
    ~Set() {}

    // ���ϵĲ���
    Set<T> operator-(const Set<T>& other) const {
        Set<T> result;
        Node<T>* current = this->head;
        while (current != nullptr) {
            if (!other.contains(current->data)) {
                result.add(current->data);
            }
            current = current->next;
        }
        return result;
    }

    // ���ϵĲ���������
    Set<T> operator+(const Set<T>& other) const {
        Set<T> result = *this;  // �ȸ��Ƶ�ǰ����
        Node<T>* current = other.head;
        while (current != nullptr) {
            if (!result.contains(current->data)) {
                result.add(current->data);
            }
            current = current->next;
        }
        return result;
    }

    // ���ϵĽ���������
    Set<T> intersection(const Set<T>& other) const {
        Set<T> result;
        Node<T>* current = this->head;
        while (current != nullptr) {
            if (other.contains(current->data)) {
                result.add(current->data);
            }
            current = current->next;
        }
        return result;
    }

    // ��鵱ǰ�����Ƿ�����ض�Ԫ��
    bool contains(const T& value) const {
        Node<T>* current = this->head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    // ���Ԫ�ص�����
    void add(const T& value) {
        if (!contains(value)) {  // ȷ�������в������ظ�Ԫ��
            Node<T>* new_node = new Node<T>(value);
            if (this->tail != nullptr) {
                this->tail->next = new_node;
                new_node->prev = this->tail;
            } else {
                this->head = new_node;
            }
            this->tail = new_node;
        }
    }
};
//���ϵĲ� (- ���������): ����һ���µļ��ϣ����������ڵ�ǰ���ϵ�������һ�������е�Ԫ�ء�
//���ϵĲ� (+ ���������): ����һ���µļ��ϣ������������ϵ�����ΨһԪ�ء�
//���ϵĽ� (intersection ����): ����һ���µļ��ϣ��������������й�ͬ��Ԫ�ء�
//ʹ��ʾ��
int main() {
    Set<int> setA;
    setA.add(1);
    setA.add(2);
    setA.add(3);

    Set<int> setB;
    setB.add(2);
    setB.add(3);
    setB.add(4);

    Set<int> resultDiff = setA - setB;
    Set<int> resultUnion = setA + setB;
    Set<int> resultIntersection = setA.intersection(setB);

    // ������
    return 0;
}

