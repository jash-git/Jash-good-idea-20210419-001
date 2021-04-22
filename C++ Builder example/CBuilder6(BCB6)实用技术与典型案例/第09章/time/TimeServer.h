//---------------------------------------------------------------------------

#ifndef TimeServerH
#define TimeServerH
#include "time_s.hh"
//---------------------------------------------------------------------------
class TimeImpl: public _sk_MyTime::_sk_Time
{
protected:
public:
        TimeImpl(const char *object_name=NULL); 
        MyTime::TimeOfDay get_gmt();
};
#endif
