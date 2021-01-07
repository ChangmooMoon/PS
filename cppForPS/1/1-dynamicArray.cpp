#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
class dynamic_array {
    T* data;
    size_t n;

   public:
    dynamic_array(int n) {  // 배열 크기를 인자로 받는 constructor
        this->n = n;        // (*this).n
        data = new T[n];
    }

    dynamic_array(const dynamic_array<T>& other) {  // 복사생성자
        n = other.n;
        data = new T[n];

        for (int i = 0; i < n; ++i)
            data[i] = other[i];
    }

    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {return data[index]}

    T& at(int index) {
        if (index < n)
            return data[index];
        throw "Index out of range"
    }

    size_t size() const { return n; }

    ~dynamic_array() { delete[] data; }

    T* begin() { return data; }

    const T* begin() const { return data; }

    T* end() { return data + n; }

    const T* end() const { return data + n; }

    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2) {
        dynamic_array<T> result(arr1.size() + arr2.size());
        copy(arr1.begin(), arr1.end(), result.begin());
        copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    string to_string(const string& sep = ", ") {
        if (n == 0) return "";

        ostringstream os;
        os << data[0];

        for (int i = 1; i < n; i++)
            os << sep << data[i];

        return os.str()
    }
};

int main() {
    return 0;
}