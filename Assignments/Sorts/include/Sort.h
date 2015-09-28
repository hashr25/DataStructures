#ifndef SORT_H
#define SORT_H


class Sort
{
    public:
        Sort();

        virtual int* intSort(int*, long) = 0;
        virtual long* longSort(long*, long) = 0;
    private:
};

#endif // SORT_H
