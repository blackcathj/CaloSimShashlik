// --------------------------------------------------------------
//      GEANT 4 - CaloSim 
//
// --------------------------------------------------------------
// Simulation of the new g-2 calorimeter
//
// 
// --------------------------------------------------------------

//#define G4VIS_USE 1

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"
#include "CaloSimDetectorConstruction.hh"
#include "CaloSimPhysicsList.hh"
#include "CaloSimPrimaryGeneratorAction.hh"
#include "G4TrajectoryDrawByParticleID.hh"
#include "CaloSimRunAction.hh"
#include "CaloSimVisManager.hh"
#include "CaloSimSteppingVerbose.hh"
#include "G4PhysListFactory.hh"
#include "G4Colour.hh"
#include "G4VVisManager.hh"
//#define NDEBUG 1
#include <assert.h>
#include <iostream>

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

int main(int argc, char** argv)
{
	G4String outputFileName = "out.root";
	if (argc >= 3)
		outputFileName = argv[2];

	G4VSteppingVerbose* verbosity = new CaloSimSteppingVerbose;
	G4VSteppingVerbose::SetInstance(verbosity);

	// Construct the default run manager
	G4RunManager* runManager = new G4RunManager;

	// set mandatory initialization classes
	CaloSimDetectorConstruction* CaloSimDetector =
	        new CaloSimDetectorConstruction(outputFileName);
	runManager->SetUserInitialization(CaloSimDetector);

//	G4VUserPhysicsList* physics = new CaloSimPhysicsList;
//	runManager->SetUserInitialization(physics);

	G4PhysListFactory factory;
	G4VModularPhysicsList* physlist = factory.GetReferencePhysList(PHYSICS_LIST);
	physlist->SetVerboseLevel(0);
	physlist->SetCutValue(prod_thre, "gamma");
	physlist->SetCutValue(prod_thre, "e+");
	physlist->SetCutValue(prod_thre, "e-");
	physlist->SetCutValue(prod_thre, "pi+");
	physlist->SetCutValue(prod_thre, "pi-");
	physlist->SetCutValue(prod_thre, "kaon+");
	physlist->SetCutValue(prod_thre, "kaon-");
	runManager->SetUserInitialization(physlist);

	// set mandatory user action class
	G4VUserPrimaryGeneratorAction* gen_action =
	        new CaloSimPrimaryGeneratorAction(CaloSimDetector);
	runManager->SetUserAction(gen_action);

	G4UserRunAction* run_action = new CaloSimRunAction;
	runManager->SetUserAction(run_action);

	// Initialize G4 kernel
	runManager->Initialize();

	// get the pointer to the UI manager and set verbosities
	G4UImanager* UI = G4UImanager::GetUIpointer();

	if (argc > 1) // batch mode
	{
		G4String command = "/control/execute ";
		G4String fileName = argv[1];
		G4cout << command + fileName << G4endl;
		UI->ApplyCommand(command + fileName);
	}
	else // interactive mode : define visualization and UI terminal
	{
#ifdef G4VIS_USE
		G4VisManager* visManager = new G4VisExecutive;
		visManager->Initialize();

		G4TrajectoryDrawByParticleID *traj = new G4TrajectoryDrawByParticleID;
		G4Colour transp = G4Colour(1,1,1,.5);

		traj->Set("gamma", transp);
//		traj->Set("gamma","green");
		traj->Set("e-", "red");
		traj->Set("e+", "red");
		traj->Set("mu+", "yellow");
		traj->Set("mu-", "yellow");
		traj->Set("nu_e", "cyan");
		traj->Set("anti_nu_e", "cyan");
		traj->Set("nu_mu", "cyan");
		traj->Set("anti_nu_mu", "cyan");
		traj->Set("pi+", "green");
		traj->Set("pi-", "green");
		traj->SetDefault("magenta");

		visManager->RegisterModel(traj);
		visManager->SelectTrajectoryModel(traj->Name());

#ifdef G4UI_USE
		G4UIExecutive* ui = new G4UIExecutive(argc, argv);
		ui->SessionStart();
		delete ui;
#else

		G4UIsession * session = 0;
#ifdef G4UI_USE_TCSH
		session = new G4UIterminal(new G4UItcsh);
#else
		session = new G4UIterminal();
#endif
//		UI->ApplyCommand("/control/execute mac/vis.mac");
		session->SessionStart();
		delete session;

#endif

		delete visManager;

#endif

		//      G4UIsession * session = 0;
		//#ifdef G4UI_USE_TCSH
		//      session = new G4UIterminal(new G4UItcsh);
		//#else
		//      session = new G4UIterminal();
		//#endif
		//      UI->ApplyCommand("/control/execute mac/vis.mac");
		//      session->SessionStart();
		//      delete session;

	}

	delete runManager;
	delete verbosity;
	return 0;
}

