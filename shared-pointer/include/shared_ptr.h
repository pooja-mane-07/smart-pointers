template <typename T>
class SharedPointer
{
    T *res;
    int *ref_count;

    void releaseResource()
    {
        if (res && ref_count && --(*ref_count) == 0)
        {
            delete res;
            delete ref_count;
            res = nullptr;
            ref_count = nullptr;
        }
    }

public:
    SharedPointer() : res(nullptr), ref_count(nullptr) {}
    explicit SharedPointer(T *new_res) : res(new_res), ref_count(new int(1)) {}

    SharedPointer(const SharedPointer &other) : res(other.res), ref_count(other.ref_count)
    {
        if (ref_count)
        {
            (*ref_count)++;
        }
    }

    SharedPointer(SharedPointer &&other) noexcept : res(other.res), ref_count(other.ref_count)
    {
        other.res = nullptr;
        other.ref_count = nullptr;
    }

    SharedPointer &operator=(const SharedPointer &other)
    {
        if (this != &other)
        {
            releaseResource();

            res = other.res;
            ref_count = other.ref_count;
            if (ref_count)
            {
                (*ref_count)++;
            }
        }
        return *this;
    }

    SharedPointer &operator=(SharedPointer &&other)
    {
        if (this != &other)
        {
            releaseResource();

            res = other.res;
            ref_count = other.ref_count;

            other.res = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    void reset(T *new_res = nullptr)
    {
        releaseResource();
        res = new_res;
        if (new_res == nullptr)
        {
            ref_count = nullptr;
        }
        else
        {
            ref_count = new int(1);
        }
    }

    int useCount() const
    {
        return ref_count ? *ref_count : 0;
    }

    T *get() const
    {
        return res;
    }

    T &operator*() const
    {
        return *res;
    }

    T *operator->() const
    {
        return res;
    }

    explicit operator bool() const
    {
        return res != nullptr;
    }

    ~SharedPointer()
    {
        releaseResource();
    }
};