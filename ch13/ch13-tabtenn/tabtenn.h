#ifndef __TABTENN_H__
#define __TABTENN_H__

#include <string>
using std::string;

class TableTennisPlayer {
    private:
        string m_firstname;
        string m_lastname;
        bool m_hastable;
    public:
        TableTennisPlayer(const string & fn="none",
                const string & ln="none", bool ht=false);
        void Name(void) const;
        bool HasTable(void) const {
            return m_hastable;
        }
        void ResetTable(bool v) {
            m_hastable = v;
        }
};

class RatePlayer : public TableTennisPlayer {
    private:
        unsigned int m_rate;
    public:
        RatePlayer(unsigned int r=0, const string & fn="none",
                const string & ln="none", bool ht=false);
        RatePlayer(unsigned int r, const TableTennisPlayer & tp);
        unsigned int Rating(void) const {
            return m_rate;
        }
        void ResetRating(unsigned int r) {
            m_rate = r;
        }

};

#endif
