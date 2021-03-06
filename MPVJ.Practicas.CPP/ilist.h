#pragma once

namespace tkl {

struct IListable {
  virtual void Print() const {};
};

struct IList {
private:
  struct node {
  public:
    const IListable *value;
    node *prev;
    node *next;
    node(const IListable *value, node *prev = nullptr, node *next = nullptr)
        : value(value), prev(prev), next(next) {}
  };

  node *first = nullptr;
  node *last = nullptr;
  node *it = nullptr;

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
  IList() {}

  ~IList() { ResetNodes(); }

  IList(const IList &value) {
    auto ptr = value.first;

    for (auto i = 0; i < value.size; i++) {
      this->Push(ptr->value);
      ptr = ptr->next;
    }
  }

  IList(IList &&value) noexcept {
    size = value.size;
    first = value.first;
    last = value.last;
    it = value.it;
    value.ResetData();
  }

  node *operator[](size_t index) const {
    auto ptr = first;

    for (auto i = 0; i < size; i++) {
      if (i == index)
        return ptr;

      ptr = ptr->next;
    }

    return nullptr;
  }

  size_t Size() const { return size; }

  size_t Push(const IListable *psz) {
    auto ptr = new node(psz);

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

  const IListable *First() const { return first->value; }

  const IListable *Next() {
    if (it == nullptr) {
      it = first->next;
      return first->value;
    }

    auto current = it;
    it = it->next;
    return current->value;
  }

  const IListable *Pop() {
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

  friend void InvertNoCopy(IList &value);
  friend IList InvertCopy(IList &value);
};

void InvertNoCopy(IList &value) {
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

IList InvertCopy(IList &value) {
  IList bl;

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
