//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: CaloSimDetectorConstruction.cc,v 1.5 2002/01/09 17:23:48 ranjard Exp $
// GEANT4 tag $Name: geant4-04-00-patch-02 $
//

#include "CaloSimDetectorConstruction.hh"
#include "CaloSimMagneticField.hh"
#include "CaloSimSD.hh"

#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Polyhedra.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4PVPlacement.hh"
#include "globals.hh"
#include "G4SDManager.hh"

#include <fstream>
#include <iostream>

#include "Config.h"

//#define CaloMaterial  Tungsten
//#define GlueMaterial  BC404
//#define FilberMaterial  BC404
////static const G4double Shower_blockDepth = 15.0 * cm; // First Batch Run
////static const G4double Shower_blockDepth = 25.0 * cm; // 2nd Batch Run
//static const G4double Shower_blockDepth = (11.0) * cm; // 3rd Batch Run
//static const G4double fiberFrac = 0.5; // ratio of fiber layer
//static const G4double PreShower_blockWidth = 4.0 * cm;

//#define CaloMaterial  Lead
//#define GlueMaterial  Lead
//#define FilberMaterial  BC404
//static const G4double Shower_blockDepth = (24.0) * cm; // 3rd Batch Run
//static const G4double fiberFrac = 0.7; // ratio of fiber layer
//static const G4double PreShower_blockWidth = 6.0 * cm;

//#define CaloMaterial  Lead
//#define GlueMaterial  Lead
//#define FilberMaterial  BC404
//static const G4double Shower_blockDepth = (24.0) * cm; // 3rd Batch Run
//static const G4double fiberFrac = 0.7; // ratio of fiber layer
//static const G4double PreShower_blockWidth = 6.0 * cm;

//#define CaloMaterial  PbGl
//#define GlueMaterial  PbGl
//#define FilberMaterial  PbGl
//
//static const G4double Shower_blockDepth = (36.0) * cm; // 3rd Batch Run
//static const G4double fiberFrac = 0.7; // ratio of fiber layer
//static const G4double PreShower_blockWidth = 8.5 * cm;

//#define CaloMaterial  PbGl
//#define GlueMaterial  PbGl
//#define FilberMaterial  PbGl
//
//static const G4double Shower_blockDepth = (36.0) * cm; // 3rd Batch Run
//static const G4double fiberFrac = 0.7; // ratio of fiber layer
//static const G4double PreShower_blockWidth = 8.5 * cm;
//
//static const G4double OverallShiftZ = -17 *cm + PreShower_blockWidth + Shower_blockDepth/2;

//static const G4double Shower_blockDepth = (36.0) * cm; // 3rd Batch Run
//static const G4double PreShower_blockWidth = 8.5 * cm;

// If you specify the output file name when you run the program, that will be the name of the root file
// if not, this sets default to output.root
CaloSimDetectorConstruction::CaloSimDetectorConstruction(G4String outputFile)
// :fpMagField(0)
{
	if (outputFile.isNull())
	{
		outputFileName = "output.root";
	}
	else
	{
		outputFileName = outputFile;
	}

	//     fpMagField = new CaloSimMagneticField();
}

CaloSimDetectorConstruction::~CaloSimDetectorConstruction()
{
	/*
	 delete calorimeterLayer_log;
	 delete calorimeterBlock_log;
	 delete tracker_log;
	 delete experimentalHall_log;
	 delete tracker_phys;
	 delete calorimeterBlock_phys;
	 delete calorimeterLayer_phys;
	 delete experimentalHall_phys;
	 */
}

//G4VPhysicalVolume*
//CaloSimDetectorConstruction::ConstructShowerOnly()
//{
//
//	//------------------------------------------------------ materials
//
//
//	G4String name;
//
//	//makes colors for visualization
//	//--------- Set Visualization Attributes -----------------------
//	whiteSolid = new G4VisAttributes(G4Colour(1, 1, 1));
//	blackSolid = new G4VisAttributes(G4Colour(0, 0, 0));
//	redSolid = new G4VisAttributes(G4Colour(1, 0, 0));
//	greenSolid = new G4VisAttributes(G4Colour(0, 1, 0));
//	blueSolid = new G4VisAttributes(G4Colour(0, 0, 1));
//	magentaSolid = new G4VisAttributes(G4Colour(1, 0, 1));
//	cyanSolid = new G4VisAttributes(G4Colour(0, 1, 1));
//	yellowSolid = new G4VisAttributes(G4Colour(1, 1, 0));
//	whiteFrame = new G4VisAttributes(G4Colour(1, 1, 1));
//	redFrame = new G4VisAttributes(G4Colour(1, 0, 0));
//	greenFrame = new G4VisAttributes(G4Colour(0, 1, 0));
//	blueFrame = new G4VisAttributes(G4Colour(0, 0, 1));
//	magentaFrame = new G4VisAttributes(G4Colour(1, 0, 1));
//	cyanFrame = new G4VisAttributes(G4Colour(0, 1, 1));
//	yellowFrame = new G4VisAttributes(G4Colour(1, 1, 0));
//	offAtt = new G4VisAttributes();
//
//	//sets style (solid vs. wireframe)
//	whiteSolid->SetForceSolid(true);
//	blackSolid->SetForceSolid(true);
//	redSolid->SetForceSolid(true);
//	greenSolid->SetForceSolid(true);
//	blueSolid->SetForceSolid(true);
//	magentaSolid->SetForceSolid(true);
//	cyanSolid->SetForceSolid(true);
//	yellowSolid->SetForceSolid(true);
//	whiteFrame->SetForceWireframe(true);
//	redFrame->SetForceWireframe(true);
//	greenFrame->SetForceWireframe(true);
//	blueFrame->SetForceWireframe(true);
//	magentaFrame->SetForceWireframe(true);
//	cyanFrame->SetForceWireframe(true);
//	yellowFrame->SetForceWireframe(true);
//
//	//offAtt is essentially an invisible status you can use for stuff you dont want to see
//	//e.g. fibers would clog up most visualizations
//	offAtt->SetVisibility(false);
//
//	buildMaterials();
//
//	//------------------------------------------------
//	// Create Sensitive Detector Manager
//	//------------------------------------------------
//
//	G4SDManager* SDman = G4SDManager::GetSDMpointer();
//
//	G4String SDname = "CaloSim/SD";
//	CaloSimSD* aSD = new CaloSimSD(SDname, outputFileName);
//	SDman->AddNewDetector(aSD);
//
//	//  //magetic filed
//	//  CaloSimMagneticField *fpMagField = new CaloSimMagneticField();
//	//  fpMagField->SetMagFieldValue(2 * tesla);
//
//	//------------------------------------------------------ volumes
//
//	//------------------------------ experimental hall (world volume)
//	//------------------------------ beam line along x axis
//	// these are the actual widths of the objects
//	// in construction of boxes, you input the half width
//
//	G4double expHall_x = 1.0 * m;
//	G4double expHall_y = 1.0 * m;
//	G4double expHall_z = 5.0 * m;
//
//	//for example, here the actual x-y-z is 2-2-10
//	// a solid is a shape
//	G4Box* experimentalHall_box = new G4Box("expHall_box", expHall_x,
//	        expHall_y, expHall_z);
//	//a solid gets made into a logic here, a logic volume is a solid but the material is defined, here Air
//	experimentalHall_log = new G4LogicalVolume(experimentalHall_box, Air,
//	        "expHall_log", 0, 0, 0);
//
//	// a logic gets turned into a physical volume and placed here, a physical volume is a logic with position defined
//	experimentalHall_phys = new G4PVPlacement(0, G4ThreeVector(), "expHall",
//	        experimentalHall_log, 0, false, 0);
//	//this sets the hall to invisible, and makes it sensitive to particle data
//	experimentalHall_log->SetVisAttributes(offAtt);
//	experimentalHall_log->SetSensitiveDetector(aSD);
//
//	// THIS SETS UP THE CALOBOX, that is, the volume that will contain the calorimeter
//	//just a reminder, box does not equal block
//	G4ThreeVector positionCaloBox = G4ThreeVector(0, 0, 0);
//
//	// these are the segments, first define how big you want your blocks
//	static const G4double blockHeight = Shower_blockHeight;
//
//	static const G4double blockWidth = Shower_blockWidth;
//	//  G4double blockDepth=11.0*cm;
//	static const G4double blockDepth = Shower_blockDepth;
//	// set divisions in calo
//	//	static const G4int nX = 48 * cm / blockWidth;
//	//	static const G4int nX = 48 * cm / blockWidth;
//	//	static const G4int nX = 8;
//	//	static const G4int nY = 4; -> to header file
//
//	//define calobox size relative to block sizes
//	static const G4double caloWidth = blockWidth * nX;
//	static const G4double caloHeight = blockHeight * nY;
//	static const G4double caloDepth = blockDepth;
//
//	// Set up the box containing the calorimeter
//	G4Box* solidCaloBox = new G4Box("caloBox", caloWidth / 2, caloHeight / 2,
//	        caloDepth / 2);
//	G4LogicalVolume* logicCaloBox = new G4LogicalVolume(solidCaloBox, Air,
//	        "CaloBoxLV");
//
//	G4VPhysicalVolume* physiCaloBox = new G4PVPlacement(0, positionCaloBox,
//	        "CaloBox", logicCaloBox, experimentalHall_phys, false, 0);
//
//	logicCaloBox->SetVisAttributes(offAtt);
//	logicCaloBox->SetSensitiveDetector(aSD);
//
//	//HERE IS WHERE I SET UP THE HODOSCOPE
//	G4double SVertWidth = 1.0 * cm;
//	G4double SVertHeight = caloHeight;
//	G4double SVertDepth = 3.0 * mm;
//
//	G4double SHorizWidth = caloWidth;
//	G4double SHorizHeight = 1.0 * cm;
//	G4double SHorizDepth = 3.0 * mm;
//	// # of staves in each direction
//	static const int nsV = caloWidth / SVertWidth; //20
//	static const int nsH = caloHeight / SHorizHeight; //16
//
//	//  Set up the logical for staves
//	G4Box* solidSVert = new G4Box("SVert", SVertWidth / 2, SVertHeight / 2,
//	        SVertDepth / 2);
//	G4Box* solidSHoriz = new G4Box("SHoriz", SHorizWidth / 2, SHorizHeight / 2,
//	        SHorizDepth / 2);
//
//	//   G4LogicalVolume* logicSVert = new G4LogicalVolume(solidSVert,BC404,"SVertLV");
//	//   G4LogicalVolume* logicSHoriz = new G4LogicalVolume(solidSHoriz,BC404,"SHorizLV");
//	G4LogicalVolume* logicSVert = new G4LogicalVolume(solidSVert, Vacuum,
//	        "SVertLV");
//	G4LogicalVolume* logicSHoriz = new G4LogicalVolume(solidSHoriz, Vacuum,
//	        "SHorizLV");
//	logicSVert->SetSensitiveDetector(aSD);
//	logicSHoriz->SetSensitiveDetector(aSD);
//	logicSVert->SetVisAttributes(whiteFrame);
//	logicSHoriz->SetVisAttributes(whiteFrame);
//	logicSVert->SetVisAttributes(whiteFrame);
//	logicSHoriz->SetVisAttributes(whiteFrame);
//
//	//here is where we place the staves. You create the physical volume and specify the number of staves
//	//note that the indexing is weird for this part
//	//
//	G4VPhysicalVolume* physiSVert[500];
//	for (G4int xi = 0; xi < nsV; xi++)
//	{
//		G4double xpos = -caloWidth / 2 + (0.5 + xi) * SVertWidth;
//		G4double ypos = 0;
//		G4double zpos = -caloDepth / 2 - 2.5 * SVertDepth;
//		G4ThreeVector positionSVert = G4ThreeVector(xpos, ypos, zpos);
//
//		//                                                                                                note the again weird indexing
//		physiSVert[xi] = new G4PVPlacement(0, positionSVert, "SVert",
//		        logicSVert, experimentalHall_phys, false, xi + 1);
//	}
//
//	G4VPhysicalVolume* physiSHoriz[500];
//	for (G4int xi = 0; xi < nsH; xi++)
//	{
//		G4double ypos = -caloHeight / 2 + (0.5 + xi) * SHorizHeight;
//		G4double xpos = 0;
//		G4double zpos = -caloDepth / 2 - 1.5 * SHorizDepth;
//		G4ThreeVector positionSHoriz = G4ThreeVector(xpos, ypos, zpos);
//		physiSVert[xi] = new G4PVPlacement(0, positionSHoriz, "SHoriz",
//		        logicSHoriz, experimentalHall_phys, false, xi + 1);
//	}
//
//	//sheet to represent the casing of the calo
//	G4Box* solidSheet = new G4Box("Sheet", caloWidth / 2, caloHeight / 2,
//	        SVertDepth / 2);
//	G4LogicalVolume* logicSheet = new G4LogicalVolume(solidSheet, BC404,
//	        "SheetLV");
//	G4ThreeVector positionSheet = G4ThreeVector(0, 0, -caloDepth / 2
//	        - SVertDepth / 2);
//	G4VPhysicalVolume* physiSheet = new G4PVPlacement(0, positionSheet,
//	        "Sheet", logicSheet, experimentalHall_phys, false, 0);
//
//	//start to form the individual blocks
//	G4Box* solidCaloBlock = new G4Box("caloBlock", blockWidth / 2, blockHeight
//	        / 2, blockDepth / 2);
//
//	//set up logical for calo box
//	G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,
//	        CaloMaterial, "CaloBlockLV");
//	//     G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Iron,"CaloBlockLV");
//	//   G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Aluminum,"CaloBlockLV");
//
//	logicCaloBlock->SetVisAttributes(blueFrame);
//	logicCaloBlock->SetSensitiveDetector(aSD);
//
//	assert(nX * nY<100);
//	G4VPhysicalVolume* physiCaloBlock[100];
//	for (G4int xi = 0; xi < nX; xi++)
//	{
//		for (G4int yi = 0; yi < nY; yi++)
//		{
//			G4double xpos = -caloWidth / 2 + (0.5 + xi) * blockWidth;
//			G4double ypos = -caloHeight / 2 + (0.5 + yi) * blockHeight;
//
//			G4ThreeVector positionCaloBlock = G4ThreeVector(xpos, ypos, 0);
//
//			physiCaloBlock[xi + nX * yi] = new G4PVPlacement(0,
//			        positionCaloBlock, "CaloBlock", logicCaloBlock,
//			        physiCaloBox, false, xi + yi * nX + 1);
//
//		}
//	}
//
//	//Here is one of the best parts about geant
//	//here we make a layer of glue in a BLOCK, one of the 1x1cm things, and if we make alot of layers in one block,
//	//those layers will get made in every single copy of the one block
//	// The layers of scintillator/glue
//	G4int nlayers = 40;
//	G4double layerSep = blockWidth / nlayers;
//	//  G4double layerThick= 0.5*mm;
////	G4double fiberFrac = 0.5;
//	G4double layerThick = layerSep * fiberFrac;
//
//	G4Box* solidLayer = new G4Box("Layer", layerThick / 2, blockHeight / 2,
//	        blockDepth / 2);
//
//	// **** TEST WITH TUNGSTEN FIBER
//	//  BC404=Tungsten; // TEMPORARY CHANGE TO MAKE CALO ALL TUNGSTEN 4/21
//	G4Material *glueTemp = GlueMaterial;
//	//  G4Material *glueTemp = Tungsten;
//	G4LogicalVolume* logicLayer = new G4LogicalVolume(solidLayer, glueTemp,
//	        "LayerLV");
//	logicLayer->SetVisAttributes(offAtt);
//	logicLayer->SetSensitiveDetector(aSD);
//
//	for (G4int li = 0; li < nlayers; li++)
//	{
//		G4double xPosLayer = -blockWidth / 2 + layerSep * (li + 0.5);
//		G4ThreeVector positionLayer = G4ThreeVector(xPosLayer, 0, 0);
//		//                                                                                      it knows to make copies because here the mother volume is a volume that has copies
//		G4VPhysicalVolume* physiLayer = new G4PVPlacement(0, positionLayer,
//		        logicLayer, "Layer", logicCaloBlock, false, li);
//	}
//
//	/*
//	 // These are the original fiber specifications modified *incorrectly*
//	 // for smaller effective fiber diameter (inefficiency on the outside)
//	 // I'm commenting it out and rewriting it to allow me to do it correctly
//	 // -Ron McNabb 12/14/08
//
//	 // Fibers
//	 G4double fiberDiameter=layerThick;
//	 G4int nfibers=blockHeight/fiberDiameter;
//	 //  G4double fiberSep=fiberDiameter;
//
//	 // changed fiber diameter to account for respose 11/8/08
//	 G4double fiberSep=fiberDiameter*0.94;
//	 //  G4double fiberSep=blockHeight/nfibers;
//	 */
//
//	// Fibers (updated 12/14)
//	G4double fiberFracSensitive = 1.0;// fraction of fiber radius that is sensitive
//	G4double fiberSep = layerThick;
//	G4double fiberDiameter = fiberSep * fiberFracSensitive;
//	G4int nfibers = blockHeight / fiberSep;
//
//	G4Tubs *solidFiber = new G4Tubs("FiberSolid", 0., fiberDiameter / 2,
//	        blockDepth / 2, 0., twopi);
//
//	G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber, BC404,
//	        "FiberLV");
//
//	// ***** TEST WITH TUNGSTEN FIBERS***
//	//  G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber,
//	// 						    Tungsten, "FiberLV");
//
//
//	logicFiber->SetVisAttributes(offAtt);
//	//         logicFiber->SetVisAttributes(redFrame);
//	logicFiber->SetSensitiveDetector(aSD);
//
//	//here we make the fibers, but we only have to make one column in one layer -
//	// that column will get copied to all the other layers in that block, and thus to all the layers everywhere in the calo
//	for (G4int fi = 0; fi < nfibers; fi++)
//	{
//		G4double yPosFiber = -blockHeight / 2 + fiberSep * (fi + 0.5);
//		G4ThreeVector positionFiber = G4ThreeVector(0, yPosFiber, 0);
//
//		G4VPhysicalVolume* physiFiber = new G4PVPlacement(0, positionFiber,
//		        logicFiber, "Fiber", logicLayer, false, fi);
//	}
//
//	return experimentalHall_phys;
//}
//
//G4VPhysicalVolume*
//CaloSimDetectorConstruction::ConstructTotoalShower()
//{
//
//	//------------------------------------------------------ materials
//
//
//	G4String name;
//
//	//makes colors for visualization
//	//--------- Set Visualization Attributes -----------------------
//	whiteSolid = new G4VisAttributes(G4Colour(1, 1, 1));
//	blackSolid = new G4VisAttributes(G4Colour(0, 0, 0));
//	redSolid = new G4VisAttributes(G4Colour(1, 0, 0));
//	greenSolid = new G4VisAttributes(G4Colour(0, 1, 0));
//	blueSolid = new G4VisAttributes(G4Colour(0, 0, 1));
//	magentaSolid = new G4VisAttributes(G4Colour(1, 0, 1));
//	cyanSolid = new G4VisAttributes(G4Colour(0, 1, 1));
//	yellowSolid = new G4VisAttributes(G4Colour(1, 1, 0));
//	whiteFrame = new G4VisAttributes(G4Colour(1, 1, 1));
//	redFrame = new G4VisAttributes(G4Colour(1, 0, 0));
//	greenFrame = new G4VisAttributes(G4Colour(0, 1, 0));
//	blueFrame = new G4VisAttributes(G4Colour(0, 0, 1));
//	magentaFrame = new G4VisAttributes(G4Colour(1, 0, 1));
//	cyanFrame = new G4VisAttributes(G4Colour(0, 1, 1));
//	yellowFrame = new G4VisAttributes(G4Colour(1, 1, 0));
//	offAtt = new G4VisAttributes();
//
//	//sets style (solid vs. wireframe)
//	whiteSolid->SetForceSolid(true);
//	blackSolid->SetForceSolid(true);
//	redSolid->SetForceSolid(true);
//	greenSolid->SetForceSolid(true);
//	blueSolid->SetForceSolid(true);
//	magentaSolid->SetForceSolid(true);
//	cyanSolid->SetForceSolid(true);
//	yellowSolid->SetForceSolid(true);
//	whiteFrame->SetForceWireframe(true);
//	redFrame->SetForceWireframe(true);
//	greenFrame->SetForceWireframe(true);
//	blueFrame->SetForceWireframe(true);
//	magentaFrame->SetForceWireframe(true);
//	cyanFrame->SetForceWireframe(true);
//	yellowFrame->SetForceWireframe(true);
//
//	//offAtt is essentially an invisible status you can use for stuff you dont want to see
//	//e.g. fibers would clog up most visualizations
//	offAtt->SetVisibility(false);
//
//	buildMaterials();
//
//	//------------------------------------------------
//	// Create Sensitive Detector Manager
//	//------------------------------------------------
//
//	G4SDManager* SDman = G4SDManager::GetSDMpointer();
//
//	G4String SDname = "CaloSim/SD";
//	CaloSimSD* aSD = new CaloSimSD(SDname, outputFileName);
//	SDman->AddNewDetector(aSD);
//
//	//  //magetic filed
//	//  CaloSimMagneticField *fpMagField = new CaloSimMagneticField();
//	//  fpMagField->SetMagFieldValue(2 * tesla);
//
//	//------------------------------------------------------ volumes
//
//	//------------------------------ experimental hall (world volume)
//	//------------------------------ beam line along x axis
//	// these are the actual widths of the objects
//	// in construction of boxes, you input the half width
//
//	G4double expHall_x = 5.0 * m;
//	G4double expHall_y = 5.0 * m;
//	G4double expHall_z = 5.0 * m;
//
//	//for example, here the actual x-y-z is 2-2-10
//	// a solid is a shape
//	G4Box* experimentalHall_box = new G4Box("expHall_box", expHall_x,
//	        expHall_y, expHall_z);
//	//a solid gets made into a logic here, a logic volume is a solid but the material is defined, here Air
//	experimentalHall_log = new G4LogicalVolume(experimentalHall_box, Vacuum,
//	        "expHall_log", 0, 0, 0 );
//
//	// a logic gets turned into a physical volume and placed here, a physical volume is a logic with position defined
//	experimentalHall_phys = new G4PVPlacement(0, G4ThreeVector(0,0,0), "expHall",
//	        experimentalHall_log, 0, false, 0);
//	//this sets the hall to invisible, and makes it sensitive to particle data
//	experimentalHall_log->SetVisAttributes(offAtt);
//	experimentalHall_log->SetSensitiveDetector(aSD);
//
//	ConstructShower(experimentalHall_phys, aSD);
//	ConstructPreShower(experimentalHall_phys, aSD);
//
//	return experimentalHall_phys;
//}
//
//G4VPhysicalVolume*
//CaloSimDetectorConstruction::ConstructShower(
//        G4VPhysicalVolume* experimentalHall_phys, CaloSimSD* aSD)
//{
//	assert(experimentalHall_phys);
//	assert(aSD);
//
//	// THIS SETS UP THE CALOBOX, that is, the volume that will contain the calorimeter
//	//just a reminder, box does not equal block
//	G4ThreeVector positionCaloBox = G4ThreeVector(0, 0, OverallShiftZ);
//
//	// these are the segments, first define how big you want your blocks
//	static const G4double blockHeight = Shower_blockHeight;
//
//	static const G4double blockWidth = Shower_blockWidth;
//	//  G4double blockDepth=11.0*cm;
//	static const G4double blockDepth = Shower_blockDepth;
//	// set divisions in calo
//	//	static const G4int nX = 48 * cm / blockWidth;
//
//
//	//define calobox size relative to block sizes
//	static const G4double caloWidth = blockWidth * nX;
//	static const G4double caloHeight = blockHeight * nY;
//	static const G4double caloDepth = blockDepth;
//
//	// Set up the box containing the calorimeter
//	G4Box* solidCaloBox = new G4Box("caloBox", caloWidth / 2, caloHeight / 2,
//	        caloDepth / 2);
//	G4LogicalVolume* logicCaloBox = new G4LogicalVolume(solidCaloBox, Vacuum,
//	        "CaloBoxLV");
//
//	G4VPhysicalVolume* physiCaloBox = new G4PVPlacement(0, positionCaloBox,
//	        "CaloBox", logicCaloBox, experimentalHall_phys, false, 0);
//
//	logicCaloBox->SetVisAttributes(offAtt);
//	logicCaloBox->SetSensitiveDetector(aSD);
//
//	//start to form the individual blocks
//	G4Box* solidCaloBlock = new G4Box("caloBlock", blockWidth / 2, blockHeight
//	        / 2, blockDepth / 2);
//
//	//set up logical for calo box
//	G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,
//	        CaloMaterial, "CaloBlockLV");
//	//     G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Iron,"CaloBlockLV");
//	//   G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Aluminum,"CaloBlockLV");
//
//	logicCaloBlock->SetVisAttributes(blueFrame);
//	logicCaloBlock->SetSensitiveDetector(aSD);
//
//	assert(nX * nY<100);
//	G4VPhysicalVolume* physiCaloBlock[100];
//	for (G4int xi = 0; xi < nX; xi++)
//	{
//		for (G4int yi = 0; yi < nY; yi++)
//		{
//			G4double xpos = -caloWidth / 2 + (0.5 + xi) * blockWidth;
//			G4double ypos = -caloHeight / 2 + (0.5 + yi) * blockHeight;
//
//			G4ThreeVector positionCaloBlock = G4ThreeVector(xpos, ypos, 0);
//
//			assert(xi + nX * yi<100);
//			physiCaloBlock[xi + nX * yi] = new G4PVPlacement(0,
//			        positionCaloBlock, "CaloBlock", logicCaloBlock,
//			        physiCaloBox, false, xi + yi * nX + 1);
//
//		}
//	}
//
//	//Here is one of the best parts about geant
//	//here we make a layer of glue in a BLOCK, one of the 1x1cm things, and if we make alot of layers in one block,
//	//those layers will get made in every single copy of the one block
//	// The layers of scintillator/glue
//	G4int nlayers = 40;
//	G4double layerSep = blockWidth / nlayers;
//	//  G4double layerThick= 0.5*mm;
////	G4double fiberFrac = 0.5;
//	G4double layerThick = layerSep * fiberFrac;
//
//	G4Box* solidLayer = new G4Box("Layer", layerThick / 2, blockHeight / 2,
//	        blockDepth / 2);
//
//	// **** TEST WITH TUNGSTEN FIBER
//	//  BC404=Tungsten; // TEMPORARY CHANGE TO MAKE CALO ALL TUNGSTEN 4/21
//	G4Material *glueTemp = GlueMaterial;
//	//  G4Material *glueTemp = Tungsten;
//	G4LogicalVolume* logicLayer = new G4LogicalVolume(solidLayer, glueTemp,
//	        "LayerLV");
//	logicLayer->SetVisAttributes(offAtt);
//	logicLayer->SetSensitiveDetector(aSD);
//
//	for (G4int li = 0; li < nlayers; li++)
//	{
//		G4double xPosLayer = -blockWidth / 2 + layerSep * (li + 0.5);
//		G4ThreeVector positionLayer = G4ThreeVector(xPosLayer, 0, 0);
//		//                                                                                      it knows to make copies because here the mother volume is a volume that has copies
//		G4VPhysicalVolume* physiLayer = new G4PVPlacement(0, positionLayer,
//		        logicLayer, "Layer", logicCaloBlock, false, li);
//	}
//
//	/*
//	 // These are the original fiber specifications modified *incorrectly*
//	 // for smaller effective fiber diameter (inefficiency on the outside)
//	 // I'm commenting it out and rewriting it to allow me to do it correctly
//	 // -Ron McNabb 12/14/08
//
//	 // Fibers
//	 G4double fiberDiameter=layerThick;
//	 G4int nfibers=blockHeight/fiberDiameter;
//	 //  G4double fiberSep=fiberDiameter;
//
//	 // changed fiber diameter to account for respose 11/8/08
//	 G4double fiberSep=fiberDiameter*0.94;
//	 //  G4double fiberSep=blockHeight/nfibers;
//	 */
//
//	// Fibers (updated 12/14)
//	G4double fiberFracSensitive = 1.0;// fraction of fiber radius that is sensitive
//	G4double fiberSep = layerThick;
//	G4double fiberDiameter = fiberSep * fiberFracSensitive;
//	G4int nfibers = blockHeight / fiberSep;
//
//	G4Tubs *solidFiber = new G4Tubs("FiberSolid", 0., fiberDiameter / 2,
//	        blockDepth / 2, 0., twopi);
//
//	G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber, FilberMaterial,
//	        "FiberLV");
//
//	// ***** TEST WITH TUNGSTEN FIBERS***
//	//  G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber,
//	// 						    Tungsten, "FiberLV");
//
//
//	logicFiber->SetVisAttributes(offAtt);
//	//         logicFiber->SetVisAttributes(redFrame);
//	logicFiber->SetSensitiveDetector(aSD);
//
//	//here we make the fibers, but we only have to make one column in one layer -
//	// that column will get copied to all the other layers in that block, and thus to all the layers everywhere in the calo
//	for (G4int fi = 0; fi < nfibers; fi++)
//	{
//		G4double yPosFiber = -blockHeight / 2 + fiberSep * (fi + 0.5);
//		G4ThreeVector positionFiber = G4ThreeVector(0, yPosFiber, 0);
//
//		G4VPhysicalVolume* physiFiber = new G4PVPlacement(0, positionFiber,
//		        logicFiber, "Fiber", logicLayer, false, fi);
//	}
//
//	return experimentalHall_phys;
//}
//
//G4VPhysicalVolume*
//CaloSimDetectorConstruction::ConstructPreShower(
//        G4VPhysicalVolume* experimentalHall_phys, CaloSimSD* aSD)
//{
//
//	assert(experimentalHall_phys);
//	assert(aSD);
//
//	// THIS SETS UP THE CALOBOX, that is, the volume that will contain the calorimeter
//	//just a reminder, box does not equal block
//
//	// these are the segments, first define how big you want your blocks
//	static const G4double blockHeight = Shower_blockHeight;
//
//	static const G4double blockWidth =PreShower_blockWidth;
//	//  G4double blockDepth=11.0*cm;
//	static const G4double blockDepth =  Shower_blockWidth * nX; // match shower dementions
//	// set divisions in calo
//	//	static const G4int nX = 48 * cm / blockWidth;
//
//
//	//define calobox size relative to block sizes
//	static const G4double caloWidth = blockWidth * nX_ps;
//	static const G4double caloHeight = blockHeight * nY_ps;
//	static const G4double caloDepth = blockDepth;
//
//	// Set up the box containing the calorimeter
//	G4Box* solidCaloBox = new G4Box("caloBox_ps", caloWidth / 2, caloHeight / 2,
//	        caloDepth / 2);
//	G4LogicalVolume* logicCaloBox = new G4LogicalVolume(solidCaloBox, Vacuum,
//	        "CaloBox_psLV");
//
//	G4ThreeVector positionCaloBox = G4ThreeVector(0, 0, -Shower_blockDepth/2-caloWidth/2+OverallShiftZ);
//	G4RotationMatrix * rotCaloBox  = new G4RotationMatrix();
//	rotCaloBox->rotateY(90 * degree);
//
//	G4VPhysicalVolume* physiCaloBox = new G4PVPlacement(rotCaloBox, positionCaloBox,
//	        "CaloBox_ps", logicCaloBox, experimentalHall_phys, false, 0);
//
//	logicCaloBox->SetVisAttributes(offAtt);
//	logicCaloBox->SetSensitiveDetector(aSD);
//
//	//start to form the individual blocks
//	G4Box* solidCaloBlock = new G4Box("caloBlock_ps", blockWidth / 2, blockHeight
//	        / 2, blockDepth / 2);
//
//	//set up logical for calo box
//	G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,
//	        CaloMaterial, "CaloBlock_psLV");
//	//     G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Iron,"CaloBlockLV");
//	//   G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Aluminum,"CaloBlockLV");
//
//	logicCaloBlock->SetVisAttributes(blueFrame);
//	logicCaloBlock->SetSensitiveDetector(aSD);
//
//	assert(nX_ps * nY_ps<100);
//	G4VPhysicalVolume* physiCaloBlock[100];
//	for (G4int xi = 0; xi < nX_ps; xi++)
//	{
//		for (G4int yi = 0; yi < nY_ps; yi++)
//		{
//			G4double xpos = -caloWidth / 2 + (0.5 + xi) * blockWidth;
//			G4double ypos = -caloHeight / 2 + (0.5 + yi) * blockHeight;
//
//			G4ThreeVector positionCaloBlock = G4ThreeVector(xpos, ypos, 0);
//
//			assert(xi + nX_ps * yi<100);
//			physiCaloBlock[xi + nX_ps * yi] = new G4PVPlacement(0,
//			        positionCaloBlock, "CaloBlock_ps", logicCaloBlock,
//			        physiCaloBox, false, xi + yi * nX_ps + 1);
//
//		}
//	}
//
//	//Here is one of the best parts about geant
//	//here we make a layer of glue in a BLOCK, one of the 1x1cm things, and if we make alot of layers in one block,
//	//those layers will get made in every single copy of the one block
//	// The layers of scintillator/glue
//	G4int nlayers = 40;
//	G4double layerSep = blockWidth / nlayers;
//	//  G4double layerThick= 0.5*mm;
////	G4double fiberFrac = 0.5;
//	G4double layerThick = layerSep * fiberFrac;
//
//	G4Box* solidLayer = new G4Box("Layer_ps", layerThick / 2, blockHeight / 2,
//	        blockDepth / 2);
//
//	// **** TEST WITH TUNGSTEN FIBER
//	//  BC404=Tungsten; // TEMPORARY CHANGE TO MAKE CALO ALL TUNGSTEN 4/21
//	G4Material *glueTemp = GlueMaterial;
//	//  G4Material *glueTemp = Tungsten;
//	G4LogicalVolume* logicLayer = new G4LogicalVolume(solidLayer, glueTemp,
//	        "LayerLV");
//	logicLayer->SetVisAttributes(offAtt);
//	logicLayer->SetSensitiveDetector(aSD);
//
//	for (G4int li = 0; li < nlayers; li++)
//	{
//		G4double xPosLayer = -blockWidth / 2 + layerSep * (li + 0.5);
//		G4ThreeVector positionLayer = G4ThreeVector(xPosLayer, 0, 0);
//		//                                                                                      it knows to make copies because here the mother volume is a volume that has copies
//		G4VPhysicalVolume* physiLayer = new G4PVPlacement(0, positionLayer,
//		        logicLayer, "Layer_ps", logicCaloBlock, false, li);
//	}
//
//	/*
//	 // These are the original fiber specifications modified *incorrectly*
//	 // for smaller effective fiber diameter (inefficiency on the outside)
//	 // I'm commenting it out and rewriting it to allow me to do it correctly
//	 // -Ron McNabb 12/14/08
//
//	 // Fibers
//	 G4double fiberDiameter=layerThick;
//	 G4int nfibers=blockHeight/fiberDiameter;
//	 //  G4double fiberSep=fiberDiameter;
//
//	 // changed fiber diameter to account for respose 11/8/08
//	 G4double fiberSep=fiberDiameter*0.94;
//	 //  G4double fiberSep=blockHeight/nfibers;
//	 */
//
//	// Fibers (updated 12/14)
//	G4double fiberFracSensitive = 1.0;// fraction of fiber radius that is sensitive
//	G4double fiberSep = layerThick;
//	G4double fiberDiameter = fiberSep * fiberFracSensitive;
//	G4int nfibers = blockHeight / fiberSep;
//
//	G4Tubs *solidFiber = new G4Tubs("FiberSolid_ps", 0., fiberDiameter / 2,
//	        blockDepth / 2, 0., twopi);
//
//	G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber, FilberMaterial,
//	        "Fiber_psLV");
//
//	// ***** TEST WITH TUNGSTEN FIBERS***
//	//  G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber,
//	// 						    Tungsten, "FiberLV");
//
//
//	logicFiber->SetVisAttributes(offAtt);
//	//         logicFiber->SetVisAttributes(redFrame);
//	logicFiber->SetSensitiveDetector(aSD);
//
//	//here we make the fibers, but we only have to make one column in one layer -
//	// that column will get copied to all the other layers in that block, and thus to all the layers everywhere in the calo
//	for (G4int fi = 0; fi < nfibers; fi++)
//	{
//		G4double yPosFiber = -blockHeight / 2 + fiberSep * (fi + 0.5);
//		G4ThreeVector positionFiber = G4ThreeVector(0, yPosFiber, 0);
//
//		G4VPhysicalVolume* physiFiber = new G4PVPlacement(0, positionFiber,
//		        logicFiber, "Fiber_ps", logicLayer, false, fi);
//	}
//
//	return experimentalHall_phys;
//
//	return experimentalHall_phys;
//}

G4VPhysicalVolume*
CaloSimDetectorConstruction::Construct()
{
	//	return ConstructShowerOnly();
//	return ConstructTotoalShower();
//	return ConstructShowerShashlik();
//	return ConstructShowerShashlikLayout("./SIDIS_LAEC_coordinates.coord");
	return ConstructShowerShashlikHexagon();
}

//////////////////////////////////////////////////////////////////
// Shashlik type
//////////////////////////////////////////////////////////////////
G4VPhysicalVolume*
CaloSimDetectorConstruction::ConstructShowerShashlik()
{

	//------------------------------------------------------ materials

	G4String name;

	//makes colors for visualization
	//--------- Set Visualization Attributes -----------------------
	whiteSolid = new G4VisAttributes(G4Colour(1, 1, 1));
	blackSolid = new G4VisAttributes(G4Colour(0, 0, 0));
	redSolid = new G4VisAttributes(G4Colour(1, 0, 0));
	greenSolid = new G4VisAttributes(G4Colour(0, 1, 0));
	blueSolid = new G4VisAttributes(G4Colour(0, 0, 1));
	magentaSolid = new G4VisAttributes(G4Colour(1, 0, 1));
	cyanSolid = new G4VisAttributes(G4Colour(0, 1, 1));
	yellowSolid = new G4VisAttributes(G4Colour(1, 1, 0));
	whiteFrame = new G4VisAttributes(G4Colour(1, 1, 1));
	redFrame = new G4VisAttributes(G4Colour(1, 0, 0));
	greenFrame = new G4VisAttributes(G4Colour(0, 1, 0));
	blueFrame = new G4VisAttributes(G4Colour(0, 0, 1));
	magentaFrame = new G4VisAttributes(G4Colour(1, 0, 1));
	cyanFrame = new G4VisAttributes(G4Colour(0, 1, 1));
	yellowFrame = new G4VisAttributes(G4Colour(1, 1, 0));
	offAtt = new G4VisAttributes();

	//sets style (solid vs. wireframe)
	whiteSolid->SetForceSolid(true);
	blackSolid->SetForceSolid(true);
	redSolid->SetForceSolid(true);
	greenSolid->SetForceSolid(true);
	blueSolid->SetForceSolid(true);
	magentaSolid->SetForceSolid(true);
	cyanSolid->SetForceSolid(true);
	yellowSolid->SetForceSolid(true);
	whiteFrame->SetForceWireframe(true);
	redFrame->SetForceWireframe(true);
	greenFrame->SetForceWireframe(true);
	blueFrame->SetForceWireframe(true);
	magentaFrame->SetForceWireframe(true);
	cyanFrame->SetForceWireframe(true);
	yellowFrame->SetForceWireframe(true);

	//offAtt is essentially an invisible status you can use for stuff you dont want to see
	//e.g. fibers would clog up most visualizations
	offAtt->SetVisibility(false);

	buildMaterials();

	//------------------------------------------------
	// Create Sensitive Detector Manager
	//------------------------------------------------

	G4SDManager* SDman = G4SDManager::GetSDMpointer();

	G4String SDname = "CaloSim/SD";
	CaloSimSD* aSD = new CaloSimSD(SDname, outputFileName);
	SDman->AddNewDetector(aSD);

	//  //magetic filed
	//  CaloSimMagneticField *fpMagField = new CaloSimMagneticField();
	//  fpMagField->SetMagFieldValue(2 * tesla);

	//------------------------------------------------------ volumes

	//------------------------------ experimental hall (world volume)
	//------------------------------ beam line along x axis
	// these are the actual widths of the objects
	// in construction of boxes, you input the half width

	G4double expHall_x = 5.0 * m;
	G4double expHall_y = 5.0 * m;
	G4double expHall_z = 5.0 * m;

	//for example, here the actual x-y-z is 2-2-10
	// a solid is a shape
	G4Box* experimentalHall_box = new G4Box("expHall_box", expHall_x, expHall_y,
	        expHall_z);
	//a solid gets made into a logic here, a logic volume is a solid but the material is defined, here Air
	experimentalHall_log = new G4LogicalVolume(experimentalHall_box, Vacuum,
	        "expHall_log", 0, 0, 0);

	// a logic gets turned into a physical volume and placed here, a physical volume is a logic with position defined
	experimentalHall_phys = new G4PVPlacement(0, G4ThreeVector(0, 0, 0),
	        "expHall", experimentalHall_log, 0, false, 0);
	//this sets the hall to invisible, and makes it sensitive to particle data
	experimentalHall_log->SetVisAttributes(offAtt);
	experimentalHall_log->SetSensitiveDetector(aSD);

//	ConstructShower(experimentalHall_phys, aSD);
//	ConstructPreShower(experimentalHall_phys, aSD);

	//------------------------------------------------------------
	// Detector Block Construction
	//------------------------------------------------------------

	assert(experimentalHall_phys);
	assert(aSD);

	// THIS SETS UP THE CALOBOX, that is, the volume that will contain the calorimeter
	//just a reminder, box does not equal block
	G4ThreeVector positionCaloBox = G4ThreeVector(0, 0, OverallShiftZ);

	// these are the segments, first define how big you want your blocks
	static const G4double blockHeight = Shower_blockHeight;

	static const G4double blockWidth = Shower_blockWidth;
	//  G4double blockDepth=11.0*cm;
	static const G4double blockDepth = ShashlikBlockDepth;
	// set divisions in calo
	//	static const G4int nX = 48 * cm / blockWidth;

	//define calobox size relative to block sizes
	static const G4double caloWidth = blockWidth * nX;
	static const G4double caloHeight = blockHeight * nY;
	static const G4double caloDepth = blockDepth;

	// Set up the box containing the calorimeter
	G4Box* solidCaloBox = new G4Box("caloBox", caloWidth / 2, caloHeight / 2,
	        caloDepth / 2);
	G4LogicalVolume* logicCaloBox = new G4LogicalVolume(solidCaloBox, Vacuum,
	        "CaloBoxLV");

	G4VPhysicalVolume* physiCaloBox = new G4PVPlacement(0, positionCaloBox,
	        "CaloBox", logicCaloBox, experimentalHall_phys, false, 0);

	logicCaloBox->SetVisAttributes(offAtt);
	logicCaloBox->SetSensitiveDetector(aSD);

	//start to form the individual blocks
	G4Box* solidCaloBlock = new G4Box("caloBlock", blockWidth / 2,
	        blockHeight / 2, blockDepth / 2);

	//set up logical for calo box
	G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,
	        CaloMaterial, "CaloBlockLV");
	//     G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Iron,"CaloBlockLV");
	//   G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Aluminum,"CaloBlockLV");

	logicCaloBlock->SetVisAttributes(blueFrame);
	logicCaloBlock->SetSensitiveDetector(aSD);

//	assert(nX * nY<100);
	G4VPhysicalVolume* physiCaloBlock[nblock] =
	{ NULL };
	for (G4int xi = 0; xi < nX; xi++)
	{
		for (G4int yi = 0; yi < nY; yi++)
		{
			G4double xpos = -caloWidth / 2 + (0.5 + xi) * blockWidth;
			G4double ypos = -caloHeight / 2 + (0.5 + yi) * blockHeight;

			const G4int blockID = xi + nX * yi;

			aSD->blockX[blockID] = xpos;
			aSD->blockY[blockID] = ypos;

			G4ThreeVector positionCaloBlock = G4ThreeVector(xpos, ypos, 0);

			assert(blockID<nblock);
			physiCaloBlock[blockID] = new G4PVPlacement(0, positionCaloBlock,
			        "CaloBlock", logicCaloBlock, physiCaloBox, false, blockID);
		}
	}

	//Here is one of the best parts about geant
	//here we make a layer of glue in a BLOCK, one of the 1x1cm things, and if we make alot of layers in one block,
	//those layers will get made in every single copy of the one block
	// The layers of scintillator/glue

	////////////////////////////////////////////////
	// layerThick = gap between absorber : Air + Scintillator
	////////////////////////////////////////////////

//	const G4double fiberFrac = ScintThick/layerSep; // ratio of fiber layer
	const G4int nlayers = nScintlayer;
	G4cout << "Shashlik Layer Number = " << nlayers << G4endl;

	G4double layerThick = (layerSep - AbsorbThick);

	G4Box* solidLayer = new G4Box("Layer", blockWidth / 2, blockHeight / 2,
	        layerThick / 2);

	G4LogicalVolume* logicLayer = new G4LogicalVolume(solidLayer, GlueMaterial,
	        "LayerLV");
	logicLayer->SetVisAttributes(offAtt);
	logicLayer->SetSensitiveDetector(aSD);

	for (G4int li = 1; li < nlayers - 1; li++)
	{
		G4double zPosLayer = -blockDepth / 2 + layerSep * (li - 0.5)
		        + phrej_Scint + leading_Pb + leading_Scint;
		assert(zPosLayer + layerThick / 2<blockDepth / 2);

		G4ThreeVector positionLayer = G4ThreeVector(0, 0, zPosLayer);
		//                                                                                      it knows to make copies because here the mother volume is a volume that has copies
		G4VPhysicalVolume* physiLayer = new G4PVPlacement(0, positionLayer,
		        logicLayer, "Layer", logicCaloBlock, false, //
		        li + 1 // moved +1 to take over id for Backend_Scint
		                );
		assert(physiLayer);
	}

	// Scint befer preshower
	G4Box* boxphrej_Scint = new G4Box("boxphrej_Scint", blockWidth / 2,
	        blockHeight / 2, phrej_Scint / 2);

	G4LogicalVolume* lvphrej_Scint = new G4LogicalVolume(boxphrej_Scint,
	        FilberMaterial, "lvphrej_Scint");
	lvphrej_Scint->SetVisAttributes(magentaFrame);
	lvphrej_Scint->SetSensitiveDetector(aSD);

	G4ThreeVector posphrej_Scint = G4ThreeVector(0, 0,
	        -blockDepth / 2 + phrej_Scint / 2);
	G4VPhysicalVolume* physphrej_Scint = new G4PVPlacement(0, posphrej_Scint,
	        lvphrej_Scint, "phrej_Scint", logicCaloBlock, false, 0);

	assert(physphrej_Scint);

	// Pb-Scint before calorimeter
	G4Box* boxLeading_Scint = new G4Box("boxLeading_Scint", blockWidth / 2,
	        blockHeight / 2, leading_Scint / 2);

	G4LogicalVolume* lvLeading_Scint = new G4LogicalVolume(boxLeading_Scint,
	        FilberMaterial, "lvLeading_Scint");
	lvLeading_Scint->SetVisAttributes(yellowFrame);
	lvLeading_Scint->SetSensitiveDetector(aSD);

	G4ThreeVector posLeading_Scint = G4ThreeVector(0, 0,
	        -blockDepth / 2 + phrej_Scint + leading_Pb + leading_Scint / 2);
	G4VPhysicalVolume* physLeading_Scint = new G4PVPlacement(0,
	        posLeading_Scint, lvLeading_Scint, "Leading_Scint", logicCaloBlock,
	        false, 1);

	assert(physLeading_Scint);

	// Scint after calorimeter
	G4Box* boxBackend_Scint = new G4Box("boxBackend_Scint", blockWidth / 2,
	        blockHeight / 2, backend_Scint / 2);

	G4LogicalVolume* lvBackend_Scint = new G4LogicalVolume(boxBackend_Scint,
	        FilberMaterial, "lvBackend_Scint");
	lvBackend_Scint->SetVisAttributes(yellowFrame);
	lvBackend_Scint->SetSensitiveDetector(aSD);

	G4cout
	        << "Depth check = "
	        << (blockDepth / 2 - backend_Scint / 2
	                - (-blockDepth / 2 + layerSep * (nlayers - 2) + phrej_Scint
	                        + leading_Pb + leading_Scint + backend_Scint / 2))
	                / mm << G4endl;

//	assert(blockDepth / 2	- backend_Scint/2 ==
//			-blockDepth / 2 + layerSep * (nlayers-2)
//			+ leading_Pb + leading_Scint + backend_Scint/2); // geometry consistency check
	G4ThreeVector posBackend_Scint = G4ThreeVector(0, 0,
	        blockDepth / 2 - backend_Scint / 2);
	G4VPhysicalVolume* physBackend_Scint = new G4PVPlacement(0,
	        posBackend_Scint, lvBackend_Scint, "Backend_Scint", logicCaloBlock,
	        false, nlayers - 1);

	assert(physBackend_Scint);

	////////////////////////////////////////////////
	// use scintillator tiles instead of fibers
	////////////////////////////////////////////////

	G4Box* solidFiber = new G4Box("FiberSolid", blockWidth / 2, blockHeight / 2,
	        ScintThick / 2);

	G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber,
	        FilberMaterial, "FiberLV");
	logicFiber->SetVisAttributes(offAtt);
//	logicFiber->SetVisAttributes(yellowFrame);
	logicFiber->SetSensitiveDetector(aSD);

	G4ThreeVector positionFiber = G4ThreeVector(0, 0, 0);

	G4VPhysicalVolume* physiFiber = new G4PVPlacement(0, positionFiber,
	        logicFiber, "Fiber", logicLayer, false, 0);

	assert(physiFiber);

	return experimentalHall_phys;
}

//////////////////////////////////////////////////////////////////
// Shashlik type from layout file
//////////////////////////////////////////////////////////////////
G4VPhysicalVolume*
CaloSimDetectorConstruction::ConstructShowerShashlikLayout(G4String layout_file)
{

	assert(phrej_Scint == 0);

	//------------------------------------------------------ materials

	G4String name;

	//makes colors for visualization
	//--------- Set Visualization Attributes -----------------------
	whiteSolid = new G4VisAttributes(G4Colour(1, 1, 1));
	blackSolid = new G4VisAttributes(G4Colour(0, 0, 0));
	redSolid = new G4VisAttributes(G4Colour(1, 0, 0));
	greenSolid = new G4VisAttributes(G4Colour(0, 1, 0));
	blueSolid = new G4VisAttributes(G4Colour(0, 0, 1));
	magentaSolid = new G4VisAttributes(G4Colour(1, 0, 1));
	cyanSolid = new G4VisAttributes(G4Colour(0, 1, 1));
	yellowSolid = new G4VisAttributes(G4Colour(1, 1, 0));
	whiteFrame = new G4VisAttributes(G4Colour(1, 1, 1));
	redFrame = new G4VisAttributes(G4Colour(1, 0, 0));
	greenFrame = new G4VisAttributes(G4Colour(0, 1, 0));
	blueFrame = new G4VisAttributes(G4Colour(0, 0, 1));
	magentaFrame = new G4VisAttributes(G4Colour(1, 0, 1));
	cyanFrame = new G4VisAttributes(G4Colour(0, 1, 1));
	yellowFrame = new G4VisAttributes(G4Colour(1, 1, 0));
	offAtt = new G4VisAttributes();

	//sets style (solid vs. wireframe)
	whiteSolid->SetForceSolid(true);
	blackSolid->SetForceSolid(true);
	redSolid->SetForceSolid(true);
	greenSolid->SetForceSolid(true);
	blueSolid->SetForceSolid(true);
	magentaSolid->SetForceSolid(true);
	cyanSolid->SetForceSolid(true);
	yellowSolid->SetForceSolid(true);
	whiteFrame->SetForceWireframe(true);
	redFrame->SetForceWireframe(true);
	greenFrame->SetForceWireframe(true);
	blueFrame->SetForceWireframe(true);
	magentaFrame->SetForceWireframe(true);
	cyanFrame->SetForceWireframe(true);
	yellowFrame->SetForceWireframe(true);

	//offAtt is essentially an invisible status you can use for stuff you dont want to see
	//e.g. fibers would clog up most visualizations
	offAtt->SetVisibility(false);

	buildMaterials();

	//------------------------------------------------
	// Create Sensitive Detector Manager
	//------------------------------------------------

	G4SDManager* SDman = G4SDManager::GetSDMpointer();

	G4String SDname = "CaloSim/SD";
	CaloSimSD* aSD = new CaloSimSD(SDname, outputFileName);
	SDman->AddNewDetector(aSD);

	//  //magetic filed
	//  CaloSimMagneticField *fpMagField = new CaloSimMagneticField();
	//  fpMagField->SetMagFieldValue(2 * tesla);

	//------------------------------------------------------ volumes

	//------------------------------ experimental hall (world volume)
	//------------------------------ beam line along x axis
	// these are the actual widths of the objects
	// in construction of boxes, you input the half width

	G4double expHall_x = 5.0 * m;
	G4double expHall_y = 5.0 * m;
	G4double expHall_z = 5.0 * m;

	//for example, here the actual x-y-z is 2-2-10
	// a solid is a shape
	G4Box* experimentalHall_box = new G4Box("expHall_box", expHall_x, expHall_y,
	        expHall_z);
	//a solid gets made into a logic here, a logic volume is a solid but the material is defined, here Air
	experimentalHall_log = new G4LogicalVolume(experimentalHall_box, Vacuum,
	        "expHall_log", 0, 0, 0);

	// a logic gets turned into a physical volume and placed here, a physical volume is a logic with position defined
	experimentalHall_phys = new G4PVPlacement(0, G4ThreeVector(0, 0, 0),
	        "expHall", experimentalHall_log, 0, false, 0);
	//this sets the hall to invisible, and makes it sensitive to particle data
	experimentalHall_log->SetVisAttributes(offAtt);
	experimentalHall_log->SetSensitiveDetector(aSD);

//	ConstructShower(experimentalHall_phys, aSD);
//	ConstructPreShower(experimentalHall_phys, aSD);

	//------------------------------------------------------------
	// Detector Block Construction
	//------------------------------------------------------------

	assert(experimentalHall_phys);
	assert(aSD);

	// THIS SETS UP THE CALOBOX, that is, the volume that will contain the calorimeter
	//just a reminder, box does not equal block
	G4ThreeVector positionCaloBox = G4ThreeVector(0, 0, OverallShiftZ);

	// these are the segments, first define how big you want your blocks
	static const G4double blockHeight = 10 * cm;

	static const G4double blockWidth = 10 * cm;
	//  G4double blockDepth=11.0*cm;
	static const G4double blockDepth = ShashlikBlockDepth;
	// set divisions in calo
	//	static const G4int nX = 48 * cm / blockWidth;

	//define calobox size relative to block sizes
	static const G4double caloWidth = 2 * 150 * cm;
	static const G4double caloHeight = 2 * 150 * cm;
	static const G4double caloDepth = blockDepth;

	// Set up the box containing the calorimeter
	G4Box* solidCaloBox = new G4Box("caloBox", caloWidth / 2, caloHeight / 2,
	        caloDepth / 2);
	G4LogicalVolume* logicCaloBox = new G4LogicalVolume(solidCaloBox, Vacuum,
	        "CaloBoxLV");

	G4VPhysicalVolume* physiCaloBox = new G4PVPlacement(0, positionCaloBox,
	        "CaloBox", logicCaloBox, experimentalHall_phys, false, 0);

	logicCaloBox->SetVisAttributes(offAtt);
	logicCaloBox->SetSensitiveDetector(aSD);

	//start to form the individual blocks
	G4Box* solidCaloBlock = new G4Box("caloBlock", blockWidth / 2,
	        blockHeight / 2, blockDepth / 2);

	//set up logical for calo box
	G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,
	        CaloMaterial, "CaloBlockLV");
	//     G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Iron,"CaloBlockLV");
	//   G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Aluminum,"CaloBlockLV");

	logicCaloBlock->SetVisAttributes(blueFrame);
	logicCaloBlock->SetSensitiveDetector(aSD);

	//start to form the individual blocks - smaller version
	G4Box* solidCaloBlock_Small = new G4Box("caloBlock_Small",
	        blockWidth / 2 / 2, blockHeight / 2 / 2, blockDepth / 2 / 2);

	//set up logical for calo box
	G4LogicalVolume* logicCaloBlock_Small = new G4LogicalVolume(
	        solidCaloBlock_Small, CaloMaterial, "CaloBlockLV_Small");

	logicCaloBlock_Small->SetVisAttributes(cyanFrame);
	logicCaloBlock_Small->SetSensitiveDetector(aSD);

	std::fstream f_lay_out(layout_file, std::ios_base::in);
	assert( f_lay_out.is_open());
	std::string sline;
	G4int blockID = 0;
	while (getline(f_lay_out, sline))
	{

		G4double xpos = 0;
		G4double ypos = 0;
		G4double width = 0;
		G4double height = 0;
		G4double length = 0;

		std::stringstream sin(sline);
		sin >> xpos >> ypos >> width >> height >> length;

		assert(xpos || ypos);
		assert(width);
		assert(height);
		assert(length);

		xpos *= cm;
		ypos *= cm;
		width *= cm;
		height *= cm;
		length *= cm;

		const bool b_norm = height >= blockHeight;

		G4cout << blockID << ": Build " << (b_norm ? "normal" : "small")
		        << " blocks @ \t[" << xpos << ", " << ypos << "]" << G4endl;

		aSD->blockX[blockID] = xpos;
		aSD->blockY[blockID] = ypos;
		const G4double zpos = b_norm ? 0 : -blockDepth / 4;

		G4ThreeVector positionCaloBlock = G4ThreeVector(xpos, ypos, zpos);

		assert(blockID<nblock);
		new G4PVPlacement(0, positionCaloBlock, "CaloBlock",
		        (b_norm ? logicCaloBlock : logicCaloBlock_Small), physiCaloBox,
		        false, blockID);

		blockID++;
	}

	aSD->NBlockHit = blockID;

	//Here is one of the best parts about geant
	//here we make a layer of glue in a BLOCK, one of the 1x1cm things, and if we make alot of layers in one block,
	//those layers will get made in every single copy of the one block
	// The layers of scintillator/glue

	////////////////////////////////////////////////
	// layerThick = gap between absorber : Air + Scintillator
	////////////////////////////////////////////////

//	const G4double fiberFrac = ScintThick/layerSep; // ratio of fiber layer
	const G4int nlayers = nScintlayer;
	G4cout << "Shashlik Layer Number = " << nlayers << G4endl;

	G4double layerThick = (layerSep - AbsorbThick);

	G4Box* solidLayer = new G4Box("Layer", blockWidth / 2, blockHeight / 2,
	        layerThick / 2);

	G4LogicalVolume* logicLayer = new G4LogicalVolume(solidLayer, GlueMaterial,
	        "LayerLV");
	logicLayer->SetVisAttributes(offAtt);
	logicLayer->SetSensitiveDetector(aSD);

	// Normal modules
	for (G4int li = 1; li < nlayers - 1; li++)
	{
		G4double zPosLayer = -blockDepth / 2 + layerSep * (li - 0.5)
		        + leading_Pb + leading_Scint;
		assert(zPosLayer + layerThick / 2<blockDepth / 2);

		G4ThreeVector positionLayer = G4ThreeVector(0, 0, zPosLayer);
		//                                                                                      it knows to make copies because here the mother volume is a volume that has copies
		G4VPhysicalVolume* physiLayer = new G4PVPlacement(0, positionLayer,
		        logicLayer, "Layer", logicCaloBlock, false, li);
		assert(physiLayer);
	}
	// Small modules
	for (G4int li = 1; li < nlayers - 1; li++)
	{
		G4double zPosLayer = -blockDepth / 4 + layerSep * (li - 0.5)
		        + leading_Pb + leading_Scint;
		if (zPosLayer + layerThick / 2 > blockDepth / 4)
			break;

		G4ThreeVector positionLayer = G4ThreeVector(0, 0, zPosLayer);
		//                                                                                      it knows to make copies because here the mother volume is a volume that has copies
		G4VPhysicalVolume* physiLayer = new G4PVPlacement(0, positionLayer,
		        logicLayer, "Layer", logicCaloBlock_Small, false, li);
		assert(physiLayer);
	}

	// Pb-Scint befer calorimeter
	G4Box* boxLeading_Scint = new G4Box("boxLeading_Scint", blockWidth / 2,
	        blockHeight / 2, leading_Scint / 2);

	G4LogicalVolume* lvLeading_Scint = new G4LogicalVolume(boxLeading_Scint,
	        FilberMaterial, "lvLeading_Scint");
	lvLeading_Scint->SetVisAttributes(yellowFrame);
	lvLeading_Scint->SetSensitiveDetector(aSD);

	G4ThreeVector posLeading_Scint = G4ThreeVector(0, 0,
	        -blockDepth / 2 + leading_Pb + leading_Scint / 2);
	G4VPhysicalVolume* physLeading_Scint = new G4PVPlacement(0,
	        posLeading_Scint, lvLeading_Scint, "Leading_Scint", logicCaloBlock,
	        false, 0);
	assert(physLeading_Scint);

	// Pb-Scint befer calorimeter
	G4Box* boxLeading_Scint_Small = new G4Box("boxLeading_Scint_Small",
	        blockWidth / 2 / 2, blockHeight / 2 / 2, leading_Scint / 2);

	G4LogicalVolume* lvLeading_Scint_Small = new G4LogicalVolume(
	        boxLeading_Scint_Small, FilberMaterial, "lvLeading_Scint_Small");
	lvLeading_Scint->SetVisAttributes(yellowFrame);
	lvLeading_Scint->SetSensitiveDetector(aSD);
	G4ThreeVector posLeading_Scint_Small = G4ThreeVector(0, 0,
	        -blockDepth / 4 + leading_Pb + leading_Scint / 2);
	G4VPhysicalVolume* physLeading_Scint_Small = new G4PVPlacement(0,
	        posLeading_Scint_Small, lvLeading_Scint_Small, "Leading_Scint",
	        logicCaloBlock_Small, false, 0);
	assert(physLeading_Scint);

	// Scint after calorimeter
	G4Box* boxBackend_Scint = new G4Box("boxBackend_Scint", blockWidth / 2,
	        blockHeight / 2, backend_Scint / 2);

	G4LogicalVolume* lvBackend_Scint = new G4LogicalVolume(boxBackend_Scint,
	        FilberMaterial, "lvBackend_Scint");
	lvBackend_Scint->SetVisAttributes(yellowFrame);
	lvBackend_Scint->SetSensitiveDetector(aSD);

	G4cout
	        << "Depth check = "
	        << (blockDepth / 2 - backend_Scint / 2
	                - (-blockDepth / 2 + layerSep * (nlayers - 2) + leading_Pb
	                        + leading_Scint + backend_Scint / 2)) / mm << G4endl;

//	assert(blockDepth / 2	- backend_Scint/2 ==
//			-blockDepth / 2 + layerSep * (nlayers-2)
//			+ leading_Pb + leading_Scint + backend_Scint/2); // geometry consistency check
	G4ThreeVector posBackend_Scint = G4ThreeVector(0, 0,
	        blockDepth / 2 - backend_Scint / 2);
	G4VPhysicalVolume* physBackend_Scint = new G4PVPlacement(0,
	        posBackend_Scint, lvBackend_Scint, "Backend_Scint", logicCaloBlock,
	        false, nlayers - 1);

	assert(physBackend_Scint);

	////////////////////////////////////////////////
	// Build glue + scintillators
	// use scintillator tiles instead of fibers
	////////////////////////////////////////////////

	G4Box* solidFiber = new G4Box("FiberSolid", blockWidth / 2, blockHeight / 2,
	        ScintThick / 2);

	G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber,
	        FilberMaterial, "FiberLV");
	logicFiber->SetVisAttributes(offAtt);
//	logicFiber->SetVisAttributes(yellowFrame);
	logicFiber->SetSensitiveDetector(aSD);

	G4ThreeVector positionFiber = G4ThreeVector(0, 0, 0);

	G4VPhysicalVolume* physiFiber = new G4PVPlacement(0, positionFiber,
	        logicFiber, "Fiber", logicLayer, false, 0);

	assert(physiFiber);

	return experimentalHall_phys;
}

//////////////////////////////////////////////////////////////////
// Shashlik type
//////////////////////////////////////////////////////////////////
G4VPhysicalVolume*
CaloSimDetectorConstruction::ConstructShowerShashlikHexagon()
{

	//------------------------------------------------------ materials

	G4String name;

	//makes colors for visualization
	//--------- Set Visualization Attributes -----------------------
	whiteSolid = new G4VisAttributes(G4Colour(1, 1, 1));
	blackSolid = new G4VisAttributes(G4Colour(0, 0, 0));
	redSolid = new G4VisAttributes(G4Colour(1, 0, 0));
	greenSolid = new G4VisAttributes(G4Colour(0, 1, 0));
	blueSolid = new G4VisAttributes(G4Colour(0, 0, 1));
	magentaSolid = new G4VisAttributes(G4Colour(1, 0, 1));
	cyanSolid = new G4VisAttributes(G4Colour(0, 1, 1));
	yellowSolid = new G4VisAttributes(G4Colour(1, 1, 0));
	whiteFrame = new G4VisAttributes(G4Colour(1, 1, 1));
	redFrame = new G4VisAttributes(G4Colour(1, 0, 0));
	greenFrame = new G4VisAttributes(G4Colour(0, 1, 0));
	blueFrame = new G4VisAttributes(G4Colour(0, 0, 1));
	magentaFrame = new G4VisAttributes(G4Colour(1, 0, 1));
	cyanFrame = new G4VisAttributes(G4Colour(0, 1, 1));
	yellowFrame = new G4VisAttributes(G4Colour(1, 1, 0));
	offAtt = new G4VisAttributes();

	//sets style (solid vs. wireframe)
	whiteSolid->SetForceSolid(true);
	blackSolid->SetForceSolid(true);
	redSolid->SetForceSolid(true);
	greenSolid->SetForceSolid(true);
	blueSolid->SetForceSolid(true);
	magentaSolid->SetForceSolid(true);
	cyanSolid->SetForceSolid(true);
	yellowSolid->SetForceSolid(true);
	whiteFrame->SetForceWireframe(true);
	redFrame->SetForceWireframe(true);
	greenFrame->SetForceWireframe(true);
	blueFrame->SetForceWireframe(true);
	magentaFrame->SetForceWireframe(true);
	cyanFrame->SetForceWireframe(true);
	yellowFrame->SetForceWireframe(true);

	//offAtt is essentially an invisible status you can use for stuff you dont want to see
	//e.g. fibers would clog up most visualizations
	offAtt->SetVisibility(false);

	buildMaterials();

	//------------------------------------------------
	// Create Sensitive Detector Manager
	//------------------------------------------------

	G4SDManager* SDman = G4SDManager::GetSDMpointer();

	G4String SDname = "CaloSim/SD";
	CaloSimSD* aSD = new CaloSimSD(SDname, outputFileName);
	SDman->AddNewDetector(aSD);

	//  //magetic filed
	//  CaloSimMagneticField *fpMagField = new CaloSimMagneticField();
	//  fpMagField->SetMagFieldValue(2 * tesla);

	//------------------------------------------------------ volumes

	//------------------------------ experimental hall (world volume)
	//------------------------------ beam line along x axis
	// these are the actual widths of the objects
	// in construction of boxes, you input the half width

	G4double expHall_x = 5.0 * m;
	G4double expHall_y = 5.0 * m;
	G4double expHall_z = 5.0 * m;

	//for example, here the actual x-y-z is 2-2-10
	// a solid is a shape
	G4Box* experimentalHall_box = new G4Box("expHall_box", expHall_x, expHall_y,
	        expHall_z);
	//a solid gets made into a logic here, a logic volume is a solid but the material is defined, here Air
	experimentalHall_log = new G4LogicalVolume(experimentalHall_box, Vacuum,
	        "expHall_log", 0, 0, 0);

	// a logic gets turned into a physical volume and placed here, a physical volume is a logic with position defined
	experimentalHall_phys = new G4PVPlacement(0, G4ThreeVector(0, 0, 0),
	        "expHall", experimentalHall_log, 0, false, 0);
	//this sets the hall to invisible, and makes it sensitive to particle data
	experimentalHall_log->SetVisAttributes(offAtt);
	experimentalHall_log->SetSensitiveDetector(aSD);

//	ConstructShower(experimentalHall_phys, aSD);
//	ConstructPreShower(experimentalHall_phys, aSD);

	//------------------------------------------------------------
	// Detector Block Construction
	//------------------------------------------------------------

	assert(experimentalHall_phys);
	assert(aSD);

	// THIS SETS UP THE CALOBOX, that is, the volume that will contain the calorimeter
	//just a reminder, box does not equal block
	G4ThreeVector positionCaloBox = G4ThreeVector(0, 0, OverallShiftZ);

	// these are the segments, first define how big you want your blocks
	static const G4double blockHeight = Shower_blockHeight;

	static const G4double blockWidth = Shower_blockWidth;
	//  G4double blockDepth=11.0*cm;
	static const G4double blockDepth = ShashlikBlockDepth;
	// set divisions in calo
	//	static const G4int nX = 48 * cm / blockWidth;

	//define calobox size relative to block sizes
	static const G4double caloWidth = blockWidth * (nX + 1) * sqrt(3) / 2;
	static const G4double caloHeight = blockHeight * (nY + 1);
	static const G4double caloDepth = blockDepth;

	// Set up the box containing the calorimeter
	G4Box* solidCaloBox = new G4Box("caloBox", caloWidth / 2, caloHeight / 2,
	        caloDepth / 2);
	G4LogicalVolume* logicCaloBox = new G4LogicalVolume(solidCaloBox, Vacuum,
	        "CaloBoxLV");

	G4VPhysicalVolume* physiCaloBox = new G4PVPlacement(0, positionCaloBox,
	        "CaloBox", logicCaloBox, experimentalHall_phys, false, 0);

	logicCaloBox->SetVisAttributes(redFrame);
	logicCaloBox->SetSensitiveDetector(aSD);

	// -----------------------------------------------------------------------
	//start to form the individual blocks

	// construction of hexagonal prism
	const G4double phiStart = 0. * deg;
	const G4double phiTotal = 360. * deg;
	const G4int numSidesH = 6;
	const G4int numZ = 2;
	const G4double router = (blockWidth + blockHeight) / 2 / 2;
	const G4double rOuter[] =
	{ router, router };
	const G4double rInner[] =
	{ 0, 0 };
	const G4double zPlane[] =
	{ -caloDepth / 2, caloDepth / 2 };

	//One row of Hexs in the z direction
	G4VSolid* solidCaloBlock = new G4Polyhedra("caloBlock", phiStart, phiTotal,
	        numSidesH, numZ, zPlane, rInner, rOuter);

//	G4Box* solidCaloBlock = new G4Box("caloBlock", blockWidth / 2, blockHeight
//	        / 2, blockDepth / 2);

	//set up logical for calo box
	G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,
	        CaloMaterial, "CaloBlockLV");
	//     G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Iron,"CaloBlockLV");
	//   G4LogicalVolume* logicCaloBlock = new G4LogicalVolume(solidCaloBlock,Aluminum,"CaloBlockLV");

	logicCaloBlock->SetVisAttributes(blueFrame);
	logicCaloBlock->SetSensitiveDetector(aSD);

//	assert(nX * nY<100);
	G4VPhysicalVolume* physiCaloBlock[nblock] =
	{ NULL };
	for (G4int xi = 0; xi < nX; xi++)
	{
		const G4double yposshift = xi % 2 == 1 ? blockHeight / 2 : 0;

		for (G4int yi = 0; yi < nY; yi++)
		{
			assert(blockWidth == blockHeight);

			G4double xpos = (-nX / 2. + 0.5 + xi) * blockWidth * sqrt(3) / 2;
			G4double ypos = (-nY / 2. + 0.5 + yi) * blockHeight + yposshift;

			const G4int blockID = xi + nX * yi;

			aSD->blockX[blockID] = xpos / m;
			aSD->blockY[blockID] = ypos / m;

			G4ThreeVector positionCaloBlock = G4ThreeVector(xpos, ypos, 0);

			assert(blockID<nblock);
			physiCaloBlock[blockID] = new G4PVPlacement(0, positionCaloBlock,
			        "CaloBlock", logicCaloBlock, physiCaloBox, false, blockID);

		}
	}

	//Here is one of the best parts about geant
	//here we make a layer of glue in a BLOCK, one of the 1x1cm things, and if we make alot of layers in one block,
	//those layers will get made in every single copy of the one block
	// The layers of scintillator/glue

	////////////////////////////////////////////////
	// layerThick = gap between absorber : Air + Scintillator
	////////////////////////////////////////////////

//	const G4double fiberFrac = ScintThick/layerSep; // ratio of fiber layer
//	const G4int nlayers = (G4int) floor(blockDepth / layerSep);
//	G4cout << "Shashlik Layer Number = " << nlayers << G4endl;

	const G4int nlayers = nScintlayer;
	G4cout << "Shashlik Layer Number = " << nlayers << G4endl;

	G4double layerThick = (layerSep - AbsorbThick);

	const G4double zPlaneLayer[] =
	{ -layerThick / 2, layerThick / 2 };
	G4VSolid* solidLayer = new G4Polyhedra("Layer", phiStart, phiTotal,
	        numSidesH, numZ, zPlaneLayer, rInner, rOuter);

//	G4Box* solidLayer = new G4Box("Layer", blockWidth/2 , blockHeight / 2,
//			layerThick / 2);

	G4LogicalVolume* logicLayer = new G4LogicalVolume(solidLayer, GlueMaterial,
	        "LayerLV");
	logicLayer->SetVisAttributes(offAtt);
	logicLayer->SetSensitiveDetector(aSD);

//	for (G4int li = 0; li < nlayers; li++)
//	{
//		G4double zPosLayer = -blockDepth / 2 + layerSep * (li + 0.5);
//		G4ThreeVector positionLayer = G4ThreeVector(0, 0, zPosLayer);
//		//                                                                                      it knows to make copies because here the mother volume is a volume that has copies
//		G4VPhysicalVolume* physiLayer = new G4PVPlacement(0, positionLayer,
//		        logicLayer, "Layer", logicCaloBlock, false, li);
//		assert(physiLayer);
//	}

	for (G4int li = 1; li < nlayers - 1; li++)
	{
		G4double zPosLayer = -blockDepth / 2 + layerSep * (li - 0.5)
		        + phrej_Scint + leading_Pb + leading_Scint + front_spt_plate;
		assert(zPosLayer + layerThick / 2<blockDepth / 2);

		G4ThreeVector positionLayer = G4ThreeVector(0, 0, zPosLayer);
		//                                                                                      it knows to make copies because here the mother volume is a volume that has copies
		G4VPhysicalVolume* physiLayer = new G4PVPlacement(0, positionLayer,
		        logicLayer, "Layer", logicCaloBlock, false, //
		        li + 1 // moved +1 to take over id for Backend_Scint
		                );
		assert(physiLayer);
	}

	// Scint befer preshower
	const G4double zPlane_phrej_Scint[] =
	{ -phrej_Scint / 2, phrej_Scint / 2 };
	G4VSolid* boxphrej_Scint = new G4Polyhedra("boxphrej_Scint", phiStart,
	        phiTotal, numSidesH, numZ, zPlane_phrej_Scint, rInner, rOuter);

	G4LogicalVolume* lvphrej_Scint = new G4LogicalVolume(boxphrej_Scint,
	        FilberMaterial, "lvphrej_Scint");
	lvphrej_Scint->SetVisAttributes(yellowFrame);
	lvphrej_Scint->SetSensitiveDetector(aSD);

	G4ThreeVector posphrej_Scint = G4ThreeVector(0, 0,
	        -blockDepth / 2 + phrej_Scint / 2);
	G4VPhysicalVolume* physphrej_Scint = new G4PVPlacement(0, posphrej_Scint,
	        lvphrej_Scint, "phrej_Scint", logicCaloBlock, false, 0);

	assert(physphrej_Scint);

	// Pb-Scint before calorimeter
	const G4double zPlane_leading_Scint[] =
	{ -leading_Scint / 2, leading_Scint / 2 };
	G4VSolid* boxLeading_Scint = new G4Polyhedra("boxLeading_Scint", phiStart,
	        phiTotal, numSidesH, numZ, zPlane_leading_Scint, rInner, rOuter);

	G4LogicalVolume* lvLeading_Scint = new G4LogicalVolume(boxLeading_Scint,
	        FilberMaterial, "lvLeading_Scint");
	lvLeading_Scint->SetVisAttributes(yellowFrame);
	lvLeading_Scint->SetSensitiveDetector(aSD);

	G4ThreeVector posLeading_Scint = G4ThreeVector(0, 0,
	        -blockDepth / 2 + phrej_Scint + leading_Pb + leading_Scint / 2);
	G4VPhysicalVolume* physLeading_Scint = new G4PVPlacement(0,
	        posLeading_Scint, lvLeading_Scint, "Leading_Scint", logicCaloBlock,
	        false, 1);

	assert(physLeading_Scint);



	// support structure Al.- 2cm
	const G4double zPlane_spt_plate[] =
	{ -front_spt_plate / 2, front_spt_plate / 2 };
	G4VSolid* box_spt_plate = new G4Polyhedra("box_spt_plate", phiStart,
	        phiTotal, numSidesH, numZ, zPlane_spt_plate, rInner, rOuter);

	G4LogicalVolume* lv_spt_plate = new G4LogicalVolume(box_spt_plate,
			FrontPlateMaterial, "lv_spt_plate");
	lv_spt_plate->SetVisAttributes(whiteFrame);
	lv_spt_plate->SetSensitiveDetector(aSD);

	G4ThreeVector pos_spt_plate = G4ThreeVector(0, 0,
	        -blockDepth / 2 + phrej_Scint + leading_Pb+ leading_Scint + front_spt_plate / 2);
	G4VPhysicalVolume* phys_spt_plate = new G4PVPlacement(0,
			pos_spt_plate, lv_spt_plate, "spt_plate", logicCaloBlock,
	        false, 1);
	assert(phys_spt_plate);



	// Scint after calorimeter used as
	// support structure Al - 4cm.
	const G4double zPlane_backend_Scint[] =
	{ -backend_Scint / 2, backend_Scint / 2 };
	G4VSolid* boxBackend_Scint = new G4Polyhedra("boxBackend_spt_plate", phiStart,
	        phiTotal, numSidesH, numZ, zPlane_backend_Scint, rInner, rOuter);

	G4LogicalVolume* lvBackend_Scint = new G4LogicalVolume(boxBackend_Scint,
			FrontPlateMaterial, "lvBackend_spt_plate");
	lvBackend_Scint->SetVisAttributes(whiteFrame);
	lvBackend_Scint->SetSensitiveDetector(aSD);
	G4ThreeVector posBackend_Scint = G4ThreeVector(0, 0,
	        blockDepth / 2 - backend_Scint / 2);
	G4VPhysicalVolume* physBackend_Scint = new G4PVPlacement(0,
	        posBackend_Scint, lvBackend_Scint, "Backend_spt_plate", logicCaloBlock,
	        false, nlayers - 1);

	assert(physBackend_Scint);

	G4cout
	        << "Depth check = "
	        << (blockDepth / 2 - backend_Scint / 2
	                - (-blockDepth / 2 + layerSep * (nlayers - 2) + phrej_Scint
	                        + leading_Pb + leading_Scint +front_spt_plate + backend_Scint / 2))
	                / mm << G4endl;

	//	assert(blockDepth / 2	- backend_Scint/2 ==
	//			-blockDepth / 2 + layerSep * (nlayers-2)
	//			+ leading_Pb + leading_Scint + backend_Scint/2); // geometry consistency check

	////////////////////////////////////////////////
	// use scintillator tiles instead of fibers
	////////////////////////////////////////////////

	const G4double zPlaneFiberSolid[] =
	{ -ScintThick / 2, ScintThick / 2 };
	G4VSolid* solidFiber = new G4Polyhedra("FiberSolid", phiStart, phiTotal,
	        numSidesH, numZ, zPlaneFiberSolid, rInner, rOuter);
//	G4Box* solidFiber = new G4Box("FiberSolid", blockWidth/2 , blockHeight / 2,
//			ScintThick / 2);

	G4LogicalVolume* logicFiber = new G4LogicalVolume(solidFiber,
	        FilberMaterial, "FiberLV");
	logicFiber->SetVisAttributes(offAtt);
//	logicFiber->SetVisAttributes(yellowFrame);
	logicFiber->SetSensitiveDetector(aSD);

	G4ThreeVector positionFiber = G4ThreeVector(0, 0, 0);

	G4VPhysicalVolume* physiFiber = new G4PVPlacement(0, positionFiber,
	        logicFiber, "Fiber", logicLayer, false, 0);

	assert(physiFiber);

	return experimentalHall_phys;
}

