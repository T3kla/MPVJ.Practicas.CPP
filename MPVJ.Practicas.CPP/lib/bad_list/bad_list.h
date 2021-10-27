#pragma once

namespace bl
{

template <typename T> struct node
{
  public:
    const T *value;

    node<T> *prev;
    node<T> *next;

    node(const T *value, node<T> *prev = nullptr, node<T> *next = nullptr) : value(value), prev(prev), next(next)
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

    int size()
    {
        return m_size;
    }

    int push(const T *psz)
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

    const T *first()
    {
        return m_first;
    }

    const T *next()
    {
        if (m_it == 0)
        {
            m_it++;
            return m_first;
        }

        auto ptr = m_first;

        for (int i = 0; i < m_it; i++)
        {
            if (i == m_it)
            {
                m_it++;
                return ptr;
            }

            if (ptr->next == nullptr)
            {
                m_it = 1;
                return m_first;
            }

            ptr = ptr->next;
        }
    }

    const T *pop()
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

        if (m_first == nullptr)
            return;

        do
        {
            auto temp = ptr;
            ptr = ptr->next;
            delete (temp);
        } while (ptr != nullptr);
    }
};

} // namespace bl
