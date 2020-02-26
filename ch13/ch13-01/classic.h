#ifndef __CLASSIC_H__
#define __CLASSIC_H__

#include "cd.h"

class Classic : public Cd {
    private:
        char plays[200];
    public:
        Classic();
        Classic(char * ps, char * perf, char * lab,
                int sel, double time);
        Classic(const Classic & cd);
        virtual ~Classic();
        virtual void Report() const;
        virtual Classic & operator=(const Classic & cd);
};

#endif
