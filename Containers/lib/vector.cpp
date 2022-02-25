#include "vector.h"
#include <string>
#include <vector>
namespace tc
{
    template<class T>
    Vector<T>::Vector() :
        m_data(nullptr),
        m_capacity(8),
        m_size(0)
    {
        m_data = (T*)std::malloc(sizeof(T) * m_capacity);
    }

    template<class T>
    void Vector<T>::Reserve(size_t capacity)
    {
        if (capacity > m_capacity)
        {
            // TODO: Max size check
            T* new_data = static_cast<T*>(std::malloc(sizeof(T) * capacity));
            std::memcpy(new_data, m_data, m_size * sizeof(T));
            delete m_data;
            m_data = new_data;
            m_capacity = capacity;
        }
    }

    template<class T>
    void Vector<T>::PushBack(T& item)
    {
        if (m_size + 1 > m_capacity)
        {
            Reserve(m_capacity * 2);
        }

        m_data[m_size++] = item;
    }

    template<class T>
    void Vector<T>::PopBack()
    {
        --m_size;
        delete m_data[m_size];
    }

    template<class T>
    T& Vector<T>::operator[](const size_t pos) // noexcept want je wil exception gooien omdat je mist(toch?)
    {
        return m_data[pos];
    }
}
