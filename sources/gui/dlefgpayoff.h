//
// FILE: dlefgpayoff.h -- Dialog for editing outcome payoffs
//
// $Id$
//

#ifndef DLEFGPAYOFF_H
#define DLEFGPAYOFF_H

class dialogEfgPayoffs : public guiPagedDialog {
private:
  Efg::Outcome m_outcome;
  const FullEfg &m_efg;
  gText m_name;
  wxTextCtrl *m_outcomeName;

  const char *HelpString(void) const { return "Change Payoffs Dialog"; }

public:
  dialogEfgPayoffs(const FullEfg &, const Efg::Outcome &, wxWindow *parent);
  virtual ~dialogEfgPayoffs() { }

  gArray<gNumber> Payoffs(void) const;
  gText Name(void) const;
};

#endif  // DLEFGPAYOFF_H