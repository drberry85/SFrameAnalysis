#ifndef SelectionModules_H
#define SelectionModules_H

#include "Objects.h"
#include "Utils.h"
#include "BaseCycleContainer.h"
#include <algorithm>
#include "Selection.h"

class TriggerSelection: public SelectionModule{
 public:
  TriggerSelection(std::string);
  ~TriggerSelection(){};

  virtual bool pass(BaseCycleContainer*);
  virtual std::string description();

 private:
  std::string m_name;

};

class NMuonSelection: public SelectionModule{
 public:
  NMuonSelection(int min_nparticle, int max_nparticle=999999, double ptmin=0., double etamax=9999.);
  ~NMuonSelection(){};

  virtual bool pass(BaseCycleContainer*);
  virtual std::string description();

 private:
  int m_min_nparticle;
  int m_max_nparticle;
  double m_ptmin;
  double m_etamax;
};

class NElectronSelection: public SelectionModule{
 public:
  NElectronSelection(int min_nparticle, int max_nparticle=999999,  double ptmin=0., double etamax=9999.);
  ~NElectronSelection(){};

  virtual bool pass(BaseCycleContainer*);
  virtual std::string description();

 private:
  int m_min_nparticle;
  int m_max_nparticle;
  double m_ptmin;
  double m_etamax;
};

class NTauSelection: public SelectionModule{
 public:
  NTauSelection(int min_nparticle, int max_nparticle=999999,  double ptmin=0., double etamax=9999.);
  ~NTauSelection(){};

  virtual bool pass(BaseCycleContainer*);
  virtual std::string description();

 private:
  int m_min_nparticle;
  int m_max_nparticle;
  double m_ptmin;
  double m_etamax;
};


class NJetSelection: public SelectionModule{
 public:
  NJetSelection(int min_nparticle, int max_nparticle=999999,  double ptmin=0., double etamax=9999.);
  ~NJetSelection(){};

  virtual bool pass(BaseCycleContainer*);
  virtual std::string description();

 private:
  int m_min_nparticle;
  int m_max_nparticle;
  double m_ptmin;
  double m_etamax;
};

class NTopJetSelection: public SelectionModule{
 public:
  NTopJetSelection(int min_nparticle, int max_nparticle=999999,  double ptmin=0., double etamax=9999.);
  ~NTopJetSelection(){};

  virtual bool pass(BaseCycleContainer*);
  virtual std::string description();

 private:
  int m_min_nparticle;
  int m_max_nparticle;
  double m_ptmin;
  double m_etamax;
};

class NTopTagSelection: public SelectionModule{
 public:
  NTopTagSelection(int min_ntoptag, int max_ntoptag=999999);
  ~NTopTagSelection(){};

  virtual bool pass(BaseCycleContainer*);
  virtual std::string description();

 private:
  int m_min_ntoptag;
  int m_max_ntoptag;
};

#endif