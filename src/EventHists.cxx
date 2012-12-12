#include "include/EventHists.h"
#include "include/ObjectHandler.h"
#include "include/SelectionModules.h"
#include <iostream>

using namespace std;

EventHists::EventHists(const char* name) : BaseHists(name)
{
  // named default constructor
  
}

EventHists::~EventHists()
{
  // default destructor, does nothing
}

void EventHists::Init()
{
  // book all histograms here
  Book( TH1F( "N_PrimVertices","number of primary vertices", 56,-0.5,55.5));
  Book( TH1F( "N_PrimVertices_ly","number of primary vertices", 56,-0.5,55.5));
  Book( TH1F( "HT", "H_{T}", 100,0,5000 ) );
  Book( TH1F( "HT_ly", "H_{T}", 100,0,5000 ) );
  Book( TH1F( "HTLep", "H_{T}Lep", 100,0,5000 ) );
  Book( TH1F( "HTLep_ly", "H_{T}Lep", 100,0,5000 ) );
  Book( TH1F( "HT_TopJets", "H_{T} TopJets", 100,0,3500 ) );
  Book( TH1F( "HT_TopJets_ly", "H_{T} TopJets", 100,0,3500 ) );
  Book( TH1F( "HT_Jets", "H_{T} Jets", 100,0,3500 ) );
  Book( TH1F( "HT_Jets_ly", "H_{T} Jets", 100,0,3500 ) );
  Book( TH1F( "MET", "missing E_{T}", 700,0,700 ) );
  Book( TH1F( "MET_ly", "missing E_{T}", 700,0,700 ) );
  Book( TH1F( "HT_MET_TopJets", "H_{T} + missing E_{T} TopJets", 100,0,3500 ) );
  Book( TH1F( "HT_MET_TopJets_ly", "H_{T} + missing E_{T} TopJets", 100,0,3500 ) );
  Book( TH1F( "HT_MET_Jets", "H_{T} + missing E_{T} Jets", 100,0,3500 ) );
  Book( TH1F( "HT_MET_Jets_ly", "H_{T} + missing E_{T} Jets", 100,0,3500 ) );
  
}

void EventHists::Fill()
{
   // important: get the event weight
  EventCalc* calc = EventCalc::Instance();
  double weight = calc -> GetWeight();
  
  ObjectHandler* objs = ObjectHandler::Instance();
  BaseCycleContainer* bcc = objs->GetBaseCycleContainer();


  int NPrimVertices = bcc-> pvs -> size();
  Hist("N_PrimVertices")-> Fill(NPrimVertices,weight);
  Hist("N_PrimVertices_ly")-> Fill(NPrimVertices,weight);


  double H_T =0;
  double H_T_TopJets =0;
  double HT_MET = 0;
  double H_T_Jets =0;
  double HT_MET_Jets = 0;
  
  H_T = calc -> GetHT();
  double H_Tlep = calc -> GetHTlep();

  for(unsigned int i=0; i< bcc->topjets->size(); ++i)
   {
     TopJet topjet =  bcc->topjets->at(i);
     H_T_TopJets= H_T_TopJets + topjet.pt();      
   }
  for(unsigned int i=0; i< bcc->jets->size(); ++i)
   {
     Jet jet =  bcc->jets->at(i);
     H_T_Jets= H_T_Jets + jet.pt();      
   }
  double met = bcc->met->pt();
  HT_MET = H_T_TopJets+ met;
  HT_MET_Jets = H_T_Jets+ met;
  
  Hist("HT")->Fill(H_T, weight);
  Hist("HT_ly")->Fill(H_T, weight);
  Hist("HTLep")->Fill(H_Tlep, weight);
  Hist("HTLep_ly")->Fill(H_Tlep, weight);
  Hist("HT_TopJets")->Fill(H_T_TopJets, weight);
  Hist("HT_TopJets_ly")->Fill(H_T_TopJets, weight);
  Hist("HT_Jets")->Fill(H_T_Jets, weight);
  Hist("HT_Jets_ly")->Fill(H_T_Jets, weight);
  Hist("MET")->Fill(met, weight);
  Hist("MET_ly")->Fill(met, weight);
  Hist("HT_MET_TopJets")->Fill(HT_MET, weight);
  Hist("HT_MET_TopJets_ly")->Fill(HT_MET, weight);
  Hist("HT_MET_Jets")->Fill(HT_MET_Jets, weight);
  Hist("HT_MET_Jets_ly")->Fill(HT_MET_Jets, weight);

}



void EventHists::Finish()
{
  // final calculations, like division and addition of certain histograms
}

