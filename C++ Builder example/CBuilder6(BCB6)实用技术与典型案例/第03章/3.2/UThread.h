//---------------------------------------------------------------------------

#ifndef UThreadH
#define UThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TComputeThread : public TThread
{
private:
protected:
        void __fastcall Execute();
public:
        __fastcall TComputeThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
 