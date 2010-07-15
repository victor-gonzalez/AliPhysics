#ifndef ALIANALYSISTASKCORRECTIONSUE_H
#define ALIANALYSISTASKCORRECTIONSUE_H

/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

////////////////////////////////////////////////////////////////////////
//
// Analysis class to Correct Underlying Event studies
//
// This class needs as input AOD with track and Jets.
// The output is a list of histograms
//
// AOD can be either connected to the InputEventHandler  
// for a chain of AOD files 
// or 
// to the OutputEventHandler
// for a chain of ESD files, so this case class should be 
// in the train after the Jet finder
//
// 
// vallero@physi.uni-heidelberg.de
////////////////////////////////////////////////////////////////////////

#include "AliAnalysisTask.h"

class AliAnalyseUE;
class AliCFManager;
class AliHistogramsUE;
class AliInputEventHandler;
class AliAODEvent;
class AliESDEvent;
class AliAODInputHandler;
class AliESDEventHandler;
class AliMCEventHandler;
class AliMCEvent;
class TH1F;
class TH2F;
class TH1I;
class TProfile;
class TTree;
class TVector3;

class  AliAnalysisTaskCorrectionsUE : public AliAnalysisTask
  {
  public:
    
    enum {
	kCFStepTriggered     = 0,
	kCFStepPhysSelect    = 1, 
	kCFStepVertexSelect  = 2,
	kCFStepAnaTopology   = 3,
	kCFStepLtPtCut1      = 4,
	kCFStepLtCorrect     = 5
    };



    AliAnalysisTaskCorrectionsUE(const char* name="AliAnalysisTaskCorrectionsUE");
    virtual           ~AliAnalysisTaskCorrectionsUE() {if ( fListOfHistos ) delete fListOfHistos; }
    AliAnalysisTaskCorrectionsUE(const  AliAnalysisTaskCorrectionsUE &det);
    AliAnalysisTaskCorrectionsUE&   operator=(const  AliAnalysisTaskCorrectionsUE &det);
       
    // return instance of the singleton
    static  AliAnalysisTaskCorrectionsUE* Instance();
      
    // Implementation of interace methods
    virtual     Bool_t Notify();
    virtual     void   ConnectInputData(Option_t *);
    virtual     void   CreateOutputObjects();
    virtual     void   Exec(Option_t *option);
    virtual     void   Terminate(Option_t *);

    //  Setters/Getters
    virtual     void         SetDebugLevel( Int_t level )  { fDebug = level; }
    virtual    Int_t         GetDebugLevel() const { return fDebug; }
    
    void   	SetPtRangeInHist( Int_t bin, Double_t min, Double_t max ) {
      			fBinsPtInHist = bin; 
      			fMinJetPtInHist = min; 
      			fMaxJetPtInHist = max; 
    			}

    // Read AODs
    void   	  SelectAODBranch(const char* val)     { fAODBranch = val;   }
    virtual       TString      	 GetAODBranch() const { return fAODBranch;   }
    virtual       AliAODEvent*   GetAOD() const               { return fAOD; } 

    // Setters/Getters for MC
    void   	SetConstrainDistance(Bool_t val1, Double_t val2){ fMinDistance = val2; fConstrainDistance = val1;}
    void   	SetSimulateChJetPt(){fSimulateChJetPt = kTRUE;}
    void   	SetUseAODMCParticle(){fUseAliStack = kFALSE;}
    void	SetUseMCBranch(){fUseMCParticleBranch = kTRUE;}

    virtual  Bool_t 	GetConstrainDistance() const {return fConstrainDistance;}
    virtual  Double_t 	GetMinDistance()       const {return fMinDistance;}
    virtual  Bool_t 	GetSimulateChJetPt()   const {return fSimulateChJetPt;}
    virtual  Bool_t 	GetUseAODMCParticle()  const {return fUseAliStack;}
    virtual  Bool_t 	GetUseMCParticleBranch() const {return fUseMCParticleBranch;}

    //Event QA
    void  SetZVertex( Double_t val ) { fZVertex = val; }
    void  SetTracksInVertex( Int_t val ){ fnTracksVertex = val; }
    void  SetCFManager(AliCFManager* cfm){ fCFManager = cfm; }
    AliCFManager* GetCFManager() const {return fCFManager;}

    // Setters/Getters for UE Analysis
    void   SetAnaTopology( Int_t val )       { fAnaType = val;    }
    void   SetConePosition(Int_t val)        { fConePosition= val; }
    void   SetConeRadius( Double_t val )     { fConeRadius = val; }
    void   SetDoNotNormalizeQuantities()     { fIsNorm2Area = kFALSE; }
    void   SetFilterBit( UInt_t val )        { fFilterBit = val;  }
    void   SetJetsOnFly( Bool_t val )        { fJetsOnFly = val;  }
    void   SetPtSumOrdering( Int_t val )     { fOrdering = val;   }
    void   SetRegionType( Int_t val )        { fRegionType = val; }
    void   SetUseChargeHadrons( Bool_t val ) { fUseChargeHadrons = val; }
    void   SetUseChPartJet( Int_t val )      { fUseChPartJet = val; }
    void   SetUseNegativeChargeType()        { fUsePositiveCharge = kFALSE; }
    void   SetUseSingleCharge()              { fUseSingleCharge = kTRUE; } 
    
    virtual Int_t     GetAnaTopology()  const  		  { return fAnaType; }
    virtual Int_t     GetConePosition() const             { return fConePosition; }
    virtual Double_t  GetConeRadius()  	const             { return fConeRadius; }
    virtual Bool_t    GetDoNotNormalizeQuantities() const { return fIsNorm2Area; }
    virtual UInt_t    GetFilterBit()    const 		  { return fFilterBit;  }
    virtual Bool_t    GetJetsOnFly()    const 	          { return fJetsOnFly;  }
    virtual Int_t     GetPtSumOrdering() const            { return fOrdering;   }
    virtual Int_t     GetRegionType()    const            { return fRegionType; }
    virtual Bool_t    GetUseChargeHadrons() const         { return fUseChargeHadrons; }
    virtual Int_t     GetUseChPartJet() const             { return fUseChPartJet; }
    virtual Bool_t    GetUseNegativeChargeType()    const { return fUsePositiveCharge; }
    virtual Bool_t    GetUseSingleCharge()  const         { return fUseSingleCharge; } 
    
    // Jet cuts
    void   SetJet1EtaCut( Double_t val )      { fJet1EtaCut = val; }
    void   SetJet2DeltaPhiCut( Double_t val ) { fJet2DeltaPhiCut = val; }
    void   SetJet2RatioPtCut( Double_t val )  { fJet2RatioPtCut = val; }
    void   SetJet3PtCut( Double_t val )       { fJet3PtCut = val; }
    void   SetPtMinChPartJet( Double_t val )  { fChJetPtMin = val; }
    
    virtual Double_t   GetJet1EtaCut()       const         { return fJet1EtaCut; }
    virtual Double_t   GetJet2DeltaPhiCut()  const	   { return fJet2DeltaPhiCut; }
    virtual Double_t   GetJet2RatioPtCut()   const         { return fJet2RatioPtCut; }
    virtual Double_t   GetJet3PtCut()        const         { return fJet3PtCut; }
    virtual Double_t   GetPtMinChPartJet()   const         { return fChJetPtMin; }
    
    // track cuts
    void   SetTrackEtaCut( Double_t val ) { fTrackEtaCut = val; }
    void   SetTrackPtCut( Double_t val )  { fTrackPtCut = val; }

    virtual Double_t   GetTrackEtaCut()  const         { return fTrackEtaCut; }
    virtual Double_t   GetTrackPtCut()   const         { return fTrackPtCut; }
    
	
  protected:
    static AliAnalysisTaskCorrectionsUE*     fgTaskCorrectionsUE;        // Pointer to single instance
  private:
    void         AddSettingsTree();
    Bool_t       EvaluateCorrections();
    void         FillAvePartPtRegion( Double_t leadingE, Double_t ptMax, Double_t ptMin );
    void         FillMultRegion( Double_t leadingE, Double_t nTrackPtmax, Double_t nTrackPtmin, Double_t ptMin );
    void         FillSumPtRegion( Double_t leadingE, Double_t ptMax, Double_t ptMin );
    TObjArray*   FindChargedParticleJets();
    Int_t        IsTrackInsideRegion(TVector3 *jetVect, TVector3 *partVect);
    void         WriteSettings();
    
    AliAnalyseUE*  fAnaUE;           //! points to AliAnalyseUE class
    AliAODEvent*   fAOD;             //! AOD Event 
    AliESDEventHandler*   fESDHandler;        //! ESD Event
    TString        fAODBranch;       //  Jet branch name from standard AOD
    AliCFManager*  fCFManager;       //  pointer to CORRECTION FRAMEWORK manager
    Int_t          fDebug;           //  Debug flag
    AliHistogramsUE* fHistosUE;      //  Points to UE histograms class
    AliInputEventHandler* fInputHandler; // Input event handler
    TList*         fListOfHistos;    //  Output list of histograms
    AliMCEventHandler* fMcHandler;   //  pointer to MC handler
    AliMCEvent*        fMcEvent;     //  pointer to MC event
    
    // Config
    Int_t          fBinsPtInHist;     //  # bins for Pt histos range
    Bool_t         fIsNorm2Area;      // Apply Area Normalization to collected observables
    Double_t       fMaxJetPtInHist;   //  max Jet Pt value for histo range
    Double_t       fMinJetPtInHist;   //  min Jet Pt value for histo range
    
    // For MC
    Bool_t 	   fConstrainDistance;    // Constrain Distance between rec jet and pyth
    Double_t       fMinDistance;          // Minimum distance between rec jet and pyth
    Bool_t         fSimulateChJetPt;      // Naive simulation of charged jet Pt from original Jet in MC Header
    Bool_t         fUseAliStack;          // Use AliSatck for particle info otherwise "mcparticles" branch in AOD
    Bool_t         fUseMCParticleBranch;  // Run Over mcparticles branch in AOD
    
    // Cuts Events type
    Int_t          fnTracksVertex;        // QA tracks pointing to principal vertex (= 3 default) 
    Double_t       fZVertex;              // Position of Vertex in Z direction
    
    // Cuts UE analysis
    Int_t          fAnaType;              // Analysis type on jet topology: 
    						//     1=inclusive  (default) 
    						//     2=back to back inclusive
    						//     3=back to back exclusive
    						//     4=Pt max (max Pt track in region)
    						//     5=gama jet (back to back) ???
    						//  Minimum bias
    						//     31 = Semi jet (charged leading particle jets)
    						//     32 = Random jetcone  ?
    						//     33 = Swiss chees   ?
    
    
    Int_t          fConePosition;         // This parameter set how will cone center in transversal zone will be set
                                          //    1 : To be used in any jet topology (default value)
                                          //        eta_cone = eta_leadingjet
                                          //        phi_cone = phi_leadingjet + - 90
                                          //    2 : To be used in multiple jet topology (code will cry otherwise)
                                          //        eta_cone = (eta_leadingjet + eta_subleadingjet)/2
                                          //        phi_cone = phi_leadingjet + - 90
    
    Double_t       fConeRadius;           // if selected Cone-like region type, set Radius (=0.7 default)
    
    UInt_t         fFilterBit;            // Select tracks from an specific track cut (default 0xFF all track selected)
    
    Bool_t         fJetsOnFly;            // if jets are reconstructed on the fly from AOD tracks (see ConnectInputData() )
    
    // UE analysis is conducted in different type of regions
    // Transverse are those like defined in: R. Field Acta Physica Polonica B. Vol 36 No. 2 pg 167 (2005) 
    // Cone regions like defined in: Phys. Rev. D 70, 072002 (2004)
    Int_t	   fRegionType;           // 1 = transverse regions (default)
                                          // 2 = cone regions   
    


    Bool_t         fUseChargeHadrons;     // Only use charge hadrons
    Bool_t         fUseChPartJet;         // Use "Charged Particle Jet" instead of jets from AOD see FindChargedParticleJets()
    
    // Theoreticians ask for tools charge-aware
    // especially those which are related to multiplicity and MC-tunings
    // see arXiv:hep-ph/0507008v3
    Bool_t         fUsePositiveCharge;    //If Single type of charge used then set which one (=kTRUE default positive)
    Bool_t         fUseSingleCharge;      //Make analysis for a single type of charge (=kFALSE default)
    
    Int_t          fOrdering;             //  Pt and multiplicity summation ordering:
                   //     1=CDF-like -independent sorting according quantity to be scored: Double sorting- (default)
                   //        if Pt summation will be scored take Pt minimum between both zones and 
                   //        fill Pt Max. and Min. histog. accordingly
                   //        if Multiplicity summation will be scored take Mult. minimum between both zones and 
                   //        fill Mult Max and Min histog. accordingly
                   //       Bib:
                   //     2=Marchesini-like (Only Pt sorting: Single sorting)
                   //        sort only according Pt summation scored, find minimum between both zones and
                   //        fill Pt and Multiplicity Max and Min summation histog. following only this criterium
                   //        Bib: Phys. Rev. D 38, 3419 (1988)
                   //     3=Nameless pt per track single sorting
                   //        sort according to pt per track scored in each transverse zone 
                   //        lowest values indicates minimum zone.   
                   //     4=User Selection sorting (NOTE: USER must implement it within cxx)
   
    
    // Jet cuts 
    Double_t      fChJetPtMin;       // Min Pt for charged Particle Jet
    Double_t      fJet1EtaCut;       // |jet1 eta| < fJet1EtaCut   (fAnaType = 1,2,3)
    Double_t      fJet2DeltaPhiCut;  // |Jet1.Phi - Jet2.Phi| < fJet2DeltaPhiCut (fAnaType = 2,3)
    Double_t      fJet2RatioPtCut;   // Jet2.Pt/Jet1Pt > fJet2RatioPtCut  (fAnaType = 2,3)
    Double_t      fJet3PtCut;        // Jet3.Pt < fJet3PtCut  (fAnaType = 3)

    // track cuts
    Double_t      fTrackEtaCut;      // Eta cut on tracks in the regions (fRegionType=1)
    Double_t      fTrackPtCut;       // Pt cut of tracks in the regions
   
    // MC cross-section 
    Double_t      fAvgTrials;        // average trials used to fill the fh1Trials histogram in case we do not have trials on a event by event basis
    //TProfile*     fh1Xsec;           //!
    //TH1F*         fh1Trials;         //!
   

    ClassDef( AliAnalysisTaskCorrectionsUE, 5); // Analysis task for Underlying Event analysis
  };

#endif

    
