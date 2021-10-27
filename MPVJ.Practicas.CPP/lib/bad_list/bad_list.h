#pragma once

namespace bl
{

template <typename T> struct node
{
  public:
    node(const T *value, const node *prev = nullptr, const node *next = nullptr) : value(value), prev(prev) next(next);
    T *value;
    node *prev;
    node *next;
};

template <typename T> struct bad_list
{
  private:
    node *first = nullptr;
    node *last = nullptr;
    unsigned int size = 0;
    unsigned int it = 0;

  public:
    bad_list()
    {
    }

    int size()
    {
        return size;
    }

    int push(const T *psz)
    {
        auto ptr = new (node(psz));

        if (count == 0)
        {
            first = ptr;
            last = ptr;
        }
        else
        {
            last->next = ptr;
            ptr->prev = last;
            last = ptr;
        }

        return ++count;
    }

    const T *first()
    {
        return first;
    }

    const T *next()
    {
        if (it == 0)
        {
            it++;
            return first;
        }

        auto ptr = first;

        for (int i = 0; i < it; i++)
        {
            if (i == it)
            {
                it++;
                return ptr;
            }

            if (ptr->next == nullptr)
            {
                it = 1;
                return first;
            }

            ptr = ptr->next;
        }
    }

    const T *pop()
    {
        auto oldFirst = first;
        auto oldFirstVal = oldFirst->value;

        first = first->next;

        delete (oldFirst);
        oldFirst = nullptr;

        count--;

        return oldFirstVal;
    }

    void reset()
    {
        auto ptr = first;

        if (first == nullptr)
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
