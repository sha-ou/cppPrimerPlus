#ifndef __CD_H__
#define __CD_H__

class Cd {
    private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
    public:
        Cd(char * perf, char * lab, int sel, double time);
        Cd(const Cd & d);
        Cd();
        virtual ~Cd();
        virtual void Report() const;
        virtual Cd & operator=(const Cd & d);
};

#endif
