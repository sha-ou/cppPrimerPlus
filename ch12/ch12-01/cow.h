#ifndef __COW_H__
#define __COW_H__

class Cow {
    private:
        char name[20];
        char *hobby;
        double weight;
    public:
        Cow();
        Cow(const char *nm, const char *ho, double wei);
        Cow(const Cow & c);
        ~Cow();
        Cow & operator=(const Cow & c);
        void ShowCow() const;
};

#endif
