
class clsPeriod {
    clsDate Period1;
    clsDate Period2;
public:
    clsPeriod( clsDate Period1, clsDate Period2) {
        this->Period1 = Period1;
        this->Period2 = Period2;
    }

    static bool is2PeriodsOverlaped(clsPeriod StartDate, clsPeriod EndDate) {
        if (clsDate::CompareDates(StartDate.Period1,EndDate.Period2)==clsDate::After
           ||
           clsDate::CompareDates(StartDate.Period1,EndDate.Period2)==clsDate::Before) return true;

        else return false; // p1=p2
    }

    bool is2PeriodsOverlaped( clsPeriod Period2) {
        return is2PeriodsOverlaped(*this,Period2);
    }

    void PrintPeriods() {
        cout<<"the start date is: "<<Period1.FullDate()<<endl;
        cout<<"the end date is: "<<Period2.FullDate()<<endl;
    }
};
