#ifndef __GOLF_H__
#define __GOLF_H__

class Golf {
    private:
        static const int LEN = 40;
        char m_fullname[LEN];
        int m_hc;
    public:
        Golf(void);
        Golf(const char * fullname, int hc);
        ~Golf(void);
        void handicap(int hc);
        void show(void) const;
};

// const int Len = 40;
// struct golf {
    // char fullname[Len];
    // int handicap;
// };

// void setgolf(golf &g, const char *name, int hc);
// int setgolf(golf &g);
// void handicap(golf &g, int hc);
// void showgolf(const golf &g);


#endif
