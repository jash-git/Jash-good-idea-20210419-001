//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "main_s.h"

#include <corba.h>
USEFORM("main_s.cpp", Main_sForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 // Initialize the ORB
                 CORBA::ORB_var orb = CORBA::ORB_init(__argc, __argv);
                 // get a reference to the root POA
                 PortableServer::POA_var rootPOA = PortableServer::POA::_narrow(orb->resolve_initial_references("RootPOA"));
                 CORBA::PolicyList policies;
                 policies.length(1);
                 policies[(CORBA::ULong)0] = rootPOA->create_lifespan_policy(PortableServer::PERSISTENT);
                 // get the POA Manager
                 PortableServer::POAManager_var poa_manager = rootPOA->the_POAManager();
                 // Create myPOA with the right policies
                 PortableServer::POA_var myPOA = rootPOA->create_POA("signal_poa",poa_manager, policies);
                  SignalImpl managerServant;
                 // Decide on the ID for the servant
                 PortableServer::ObjectId_var managerId = PortableServer::string_to_ObjectId("SignalManager");
                 // Activate the servant with the ID on myPOA
                 myPOA->activate_object_with_id(managerId, &managerServant);
                 // Activate the POA Manager
                 poa_manager->activate();
                 
                 
                 Application->CreateForm(__classid(TMain_sForm), &Main_sForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
