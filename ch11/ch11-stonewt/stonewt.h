#ifndef __STONEWT_H__
#define __STONEWT_H__

class Stonewt {
    private:
        enum {Lbs_per_stn = 14};
        int m_stone;
        double m_pds_left;
        double m_pounds;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt(void);
        ~Stonewt(void);
        void ShowLbs(void);
        void ShowStn(void);
};

#endif
