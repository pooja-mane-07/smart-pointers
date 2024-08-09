template<typename T>
class UniquePointer {
  T* res;

 public:
  UniquePointer(T* new_res = nullptr) : res(new_res) {}

  UniquePointer(const UniquePointer<T>& other) = delete;

  UniquePointer& operator=(const UniquePointer<T>& other) = delete;

  UniquePointer(UniquePointer<T>&& other) {
    res       = other.res;
    other.res = nullptr;
  }

  UniquePointer& operator=(UniquePointer<T>&& other) {
    if (this != &other) {
      if (res) {
        delete res;
      }
      res       = other.res;
      other.res = nullptr;
    }
    return *this;
  }

  T* operator->() { return res; }

  T& operator*() { return *res; }

  T* get() { return res; }

  void reset(T* new_res = nullptr) {
    if (res) {
      delete res;
    }
    res = new_res;
  }

  explicit operator bool() const { return res != nullptr; }

  ~UniquePointer() {
    if (res) {
      delete res;
      res = nullptr;
    }
  }
};