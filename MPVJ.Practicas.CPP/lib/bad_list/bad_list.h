#pragma once

namespace bl
{

template <typename T> struct bad_list
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

    size_t m_size = 0;
    size_t m_it = 0;

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
        m_size = 0;
        m_it = 0;
    }

  public:
    bad_list()
    {
    }

    ~bad_list()
    {
        reset_nodes();
    }

    //      gracioso hasta que te das cuenta que buscar
    //      con [] en una lista enlazada genera O(n^2)
    // bad_list(const bad_list &value)
    //  {
    //    for (auto i = 0; i < value.m_size; i++)
    //        this->push(value[i]->value);
    //  }

    bad_list(const bad_list &value)
    {
        auto ptr = value.m_first;

        for (auto i = 0; i < value.m_size; i++)
        {
            this->push(ptr->value);
            ptr = ptr->next;
        }
    }

    bad_list(bad_list &&value) noexcept
    {
        m_size = value.m_size;
        m_it = value.m_it;
        m_first = value.m_first;
        m_last = value.m_last;
        value.reset_data();
    }

    // tentacion de hacer un vector de punteros...
    // pero eso ya no sería una linked list
    node<T> *operator[](size_t index) const
    {
        auto ptr = m_first;

        for (auto i = 0; i < m_size; i++)
        {
            if (i == index)
                return ptr;

            ptr = ptr->next;
        }
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
        auto ptr = m_first;

        for (auto i = 0; i < m_size; i++)
        {
            if (m_it >= m_size)
                m_it = 0;

            if (i == m_it)
            {
                m_it++;
                return ptr->value;
            }

            ptr = ptr->next;
        }
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

    template <typename T> friend void invert_noCopy(bad_list<T> &value);
    template <typename T> friend bad_list<T> invert_copy(bad_list<T> &value);
};

template <typename T> void invert_noCopy(bad_list<T> &value)
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

template <typename T> bad_list<T> invert_copy(bad_list<T> &value)
{
    bad_list<T> bl;

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

} // namespace bl
