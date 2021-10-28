#pragma once

namespace bl
{

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

template <typename T> struct bad_list
{
  private:
    node<T> *m_first = nullptr;
    node<T> *m_last = nullptr;

    unsigned int m_size = 0;
    unsigned int m_it = 0;

  public:
    bad_list()
    {
    }

    ~bad_list()
    {
        reset();
    }

    bad_list(const bad_list &value)
    {
        for (unsigned int i = 0; i < value.m_size; i++)
            this->push(value[i]->value);
    }

    node<T> const *operator[](unsigned int index) const
    {
        auto ptr = m_first;

        for (int i = 0; i < m_size; i++)
        {
            if (i == index)
                return ptr;

            ptr = ptr->next;
        }
    }

    unsigned int size() const
    {
        return m_size;
    }

    int push(const T psz)
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

        for (unsigned int i = 0; i < m_size; i++)
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
        auto ptr = m_first;

        while (ptr != nullptr)
        {
            auto temp = ptr;
            ptr = ptr->next;
            delete (temp);
        }

        m_first = nullptr;
        m_last = nullptr;

        m_size = 0;
        m_it = 0;
    }
};

} // namespace bl
