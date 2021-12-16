#pragma once

namespace tkl {

template <typename T> struct TList {
private:
  template <typename T> struct node {
    const T value;
    node<T> *prev;
    node<T> *next;
    node(const T value, node<T> *prev = nullptr, node<T> *next = nullptr)
        : value(value), prev(prev), next(next) {}
  };

  node<T> *first = nullptr;
  node<T> *last = nullptr;
  node<T> *it = nullptr;

  size_t size = 0;

  void ResetNodes() {
    auto ptr = first;

    while (ptr != nullptr) {
      auto temp = ptr;
      ptr = ptr->next;
      delete (temp);
    }
  }

  void ResetData() {
    first = nullptr;
    last = nullptr;
    it = nullptr;
    size = 0;
  }

public:
  TList() {}
  ~TList() { ResetNodes(); }

  TList(const TList &value) {
    auto ptr = value.first;

    for (auto i = 0; i < value.size; i++) {
      this->Push(ptr->value);
      ptr = ptr->next;
    }
  }

  TList(TList &&value) noexcept {
    size = value.size;
    first = value.first;
    last = value.last;
    it = value.it;
    value.ResetData();
  }

  node<T> *operator[](size_t index) const {
    auto ptr = first;

    for (auto i = 0; i < size; i++) {
      if (i == index)
        return ptr;

      ptr = ptr->next;
    }

    return nullptr;
  }

  size_t Size() const { return size; }

  size_t Push(const T psz) {
    auto ptr = new node<T>(psz);

    if (size == 0) {
      first = ptr;
      last = ptr;
    } else {
      last->next = ptr;
      ptr->prev = last;
      last = ptr;
    }

    return ++size;
  }

  const T First() const { return first->value; }

  const T Next() {
    if (it == nullptr) {
      it = first->next;
      return first->value;
    }

    auto current = it;
    it = it->next;
    return current->value;
  }

  const T Pop() {
    auto oldFirst = first;
    auto oldFirstVal = oldFirst->value;

    first = first->next;

    delete (oldFirst);
    oldFirst = nullptr;

    size--;

    return oldFirstVal;
  }

  void Reset() {
    ResetNodes();
    ResetData();
  }

  template <typename T> friend void InvertNoCopy(TList<T> &value);
  template <typename T> friend TList<T> InvertCopy(TList<T> &value);
};

template <typename T> void InvertNoCopy(TList<T> &value) {
  auto size = value.Size();
  auto ptr = value.last;

  for (auto i = size - 1; i < size; i--) {
    auto v = ptr;
    ptr = ptr->prev;

    auto n = v->next;
    v->next = v->prev;
    v->prev = n;
  }

  auto f = value.first;
  value.first = value.last;
  value.last = f;
}

template <typename T> TList<T> InvertCopy(TList<T> &value) {
  TList<T> bl;

  auto size = value.Size();
  auto ptr = value.last;

  for (auto i = size - 1; i < size; i--) {
    auto v = ptr;
    ptr = ptr->prev;
    bl.Push(v->value);
  }

  return bl;
}

} // namespace tkl
