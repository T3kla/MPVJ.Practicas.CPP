#pragma once

namespace tkl
{

template <typename T> struct llist
{
  private:
    template <typename T> struct node
    {
      public:
        const T value;

        node<T> *prev;
        node<T> *next;

        node(const T value, node<T> *prev = nullptr, node<T> *next = nullptr) : value(value), prev(prev), next(next)
        {
        }
    };

    node<T> *m_first = nullptr;
    node<T> *m_last = nullptr;
    node<T> *m_iter = nullptr;

    size_t m_size = 0;

    void reset_nodes()
    {
        auto ptr = m_first;

        while (ptr != nullptr)
        {
            auto temp = ptr;
            ptr = ptr->next;
            delete (temp);
        }
    }

    void reset_data()
    {
        m_first = nullptr;
        m_last = nullptr;
        m_iter = nullptr;
        m_size = 0;
    }

  public:
    llist()
    {
    }

    ~llist()
    {
        reset_nodes();
    }

    llist(const llist &value)
    {
        auto ptr = value.m_first;

        for (auto i = 0; i < value.m_size; i++)
        {
            this->push(ptr->value);
            ptr = ptr->next;
        }
    }

    llist(llist &&value) noexcept
    {
        m_size = value.m_size;
        m_first = value.m_first;
        m_last = value.m_last;
        m_iter = value.m_iter;
        value.reset_data();
    }

    node<T> *operator[](size_t index) const
    {
        auto ptr = m_first;

        for (auto i = 0; i < m_size; i++)
        {
            if (i == index)
                return ptr;

            ptr = ptr->next;
        }

        return nullptr;
    }

    size_t size() const
    {
        return m_size;
    }

    size_t push(const T psz)
    {
        auto ptr = new node<T>(psz);

        if (m_size == 0)
        {
            m_first = ptr;
            m_last = ptr;
        }
        else
        {
            m_last->next = ptr;
            ptr->prev = m_last;
            m_last = ptr;
        }

        return ++m_size;
    }

    const T first() const
    {
        return m_first->value;
    }

    const T next()
    {
        if (m_iter == nullptr)
        {
            m_iter = m_first->next;
            return m_first->value;
        }

        auto current = m_iter;
        m_iter = m_iter->next;
        return current->value;
    }

    const T pop()
    {
        auto oldFirst = m_first;
        auto oldFirstVal = oldFirst->value;

        m_first = m_first->next;

        delete (oldFirst);
        oldFirst = nullptr;

        m_size--;

        return oldFirstVal;
    }

    void reset()
    {
        reset_nodes();
        reset_data();
    }

    template <typename T> friend void invert_noCopy(llist<T> &value);
    template <typename T> friend llist<T> invert_copy(llist<T> &value);
};

template <typename T> void invert_noCopy(llist<T> &value)
{
    auto size = value.size();
    auto ptr = value.m_last;

    for (auto i = size - 1; i < size; i--)
    {
        auto v = ptr;
        ptr = ptr->prev;

        auto n = v->next;
        v->next = v->prev;
        v->prev = n;
    }

    auto f = value.m_first;
    value.m_first = value.m_last;
    value.m_last = f;
}

template <typename T> llist<T> invert_copy(llist<T> &value)
{
    llist<T> bl;

    auto size = value.size();
    auto ptr = value.m_last;

    for (auto i = size - 1; i < size; i--)
    {
        auto v = ptr;
        ptr = ptr->prev;
        bl.push(v->value);
    }

    return bl;
}

} // namespace tkl
