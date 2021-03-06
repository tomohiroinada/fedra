EdbPVRec    *ali=0;

//------------------------------------------------------------
int cut_seg(float x0, float y0, float tx0, float ty0, float puls )
{
  // this function is called by GetDataEdb() to reject bad segments

  //  if( TMath::Abs(ty0)>.15 ) return 0;
  if( puls < 3 ) return 0;
  if( TMath::Abs(y0- 139.70)<1.35 && TMath::Abs(x0+  64.45)<1.4 )  return 0;
  if( TMath::Abs(y0+ 158.2 )<1.3  && TMath::Abs(x0+ 108.55)<1.3 )  return 0;
  if( TMath::Abs(y0- 139.38)<1.5  && TMath::Abs(x0+  44.95)<1.5 )  return 0;
  if( TMath::Abs(y0+ 121.30)<1.35 && TMath::Abs(x0- 104.45)<1.35)  return 0;
  if( TMath::Abs(y0+  13.90)<1.45 && TMath::Abs(x0- 118.50)<1.35)  return 0;
  if( TMath::Abs(y0+ 143.75)<1.35 && TMath::Abs(x0- 133.25)<1.35)  return 0;
  return 1;
}

//------------------------------------------------------------
void link()
{
  gROOT->LoadMacro("ScanCond.C");
  gROOT->LoadMacro("IO.C");

  EdbRun *edbRun =  new EdbRun(
			       "/mnt/nusrv4_2/week/scan1.root"
			       //"/mnt/operalabdb_e/data/rawr/b1_sep2002/Pl02/Sep2002_pl2_1.root"
			       //"/mnt/operalabdb_e/data/rawr/b1_jun2003/pl09/raw_Jun2003_03010109_nc1.root"
   ,"READ");

  //                up base down  - nominal values during exposure (up/down are used for projection only)
  float  plate[3] = {40, 214, 40}; // we do not rely yet on values coming after convertor

  float  shrU  = 1.12;              //  (exposure thickness) / (measured on stage thickness):
  float  shrD  = .98;              //  tx_exp = tx_stage/shr

  float  uOff[2] = {0.,0.};      // s1.eTX-s.eTX, s1.eTY-s.eTY  (at 0 angle)
  float  dOff[2] = {0.,0.};      // s2.eTX-s.eTX, -(s2.eTY-s.eTY)

  TTree *tree = inittree("couples",
			 "link.root",
			 "RECREATE");  // "RECREATE" "NEW" or "UPDATE" open modes

  EdbScanCond *scanCond = new EdbScanCond();
  Set_Prototype_OPERA_microtrack( scanCond );
  EdbPatternsVolume *pvol = (EdbPatternsVolume *)ali;

  TIndexCell uplist;
  TIndexCell downlist;

  make_views_coord_map(edbRun,uplist,downlist);
  //make_views_map(edbRun,uplist,downlist);

  int nareas= uplist->N(1);

  TIndexCell *up=0;
  TIndexCell *down=0;

  //for(int aid=1; aid<11; aid++) {
  for(int aid=0; aid<nareas+1; aid++) {

    up   = uplist.Find(aid);      if(!up)   continue;
    down = downlist.Find(aid);    if(!down) continue; 

    ali      = new EdbPVRec();
    ali->SetScanCond(scanCond);

    getDataEdb( edbRun, ali, up,down, shrU, shrD, uOff, dOff, plate );

    ali->GetScanCond()->Print();
    ali->SetSegmentsErrors();

    ali->SetCouplesAll();
    ali->SetChi2Max(2.5);
    ali->Link();

    filltree(tree, ali,0);
    delete pvol;
    delete ali;
  }
  
}



//-------------------------------------------------------------------------------

//    "/mnt/operalabdb_e/data/rawr/b1_sep2002/PL03/Sept2002_pl3_1.root"
//    float  plate[3] = {44,215,44}; // we do not rely yet on values coming after convertor
//    float  shrD  = 1.02;           //
//    float  shrU  = 0.93;           //
//    float  uOff[2] = {0.,0.};      // s1.eTX-s.eTX, s1.eTY-s.eTY  (at 0 angle)
//    float  dOff[2] = {0.,0.};      // s2.eTX-s.eTX, -(s2.eTY-s.eTY)

