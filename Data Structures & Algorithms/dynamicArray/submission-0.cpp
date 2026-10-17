class DynamicArray {
    int *arr;
    int capacity;
    int size;
public:
    DynamicArray(int capacity) {
        arr = new int[capacity];
        this->capacity = capacity;
        size = 0;
    }

    int get(int i) {
        if (i >= 0 && i < size) {
            return arr[i];
        }
        else {
            return -1;
        }
    }

    void set(int i, int n) {
        if (i >= 0 && i < size) {
            arr[i] = n;
        }
    }

    void pushback(int n) {
        if (size >= capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        if (size > 0) {
            return arr[--size];
        }
        return -1;
    }

    void resize() {
        int* newArr = new int[capacity * 2];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        this->capacity = capacity * 2;
        delete[] arr;
        this->arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
    ~DynamicArray() {
        delete[] arr;
    }
};
