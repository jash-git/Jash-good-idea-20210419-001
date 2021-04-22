//---------------------------------------------------------------------------


#pragma hdrstop

#include <corba.h>
#include "TimeServer.h"
#include "main_s.h"
#include <time.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)


TimeImpl::TimeImpl(const char *object_name):
        _sk_MyTime::_sk_Time(object_name)                 
{                                   
}

MyTime::TimeOfDay TimeImpl::get_gmt()
{
   try
  {
    time_t time_now =time(NULL);
    struct tm * time_p =localtime(&time_now);

    Form1->Memo1->Lines->Add("**Send time to client**");

    MyTime::TimeOfDay tod;
    tod.hour = time_p->tm_hour;
    tod.minute = time_p->tm_min;
    tod.second = time_p->tm_sec;

    return tod;
  }
  catch (::Exception & e)
  {
    throw MyTime::Time::TimeException(e.Message.c_str());
  }
}
