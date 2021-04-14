#include "TCanvas.h"
#include "TTree.h"
#include "TString.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>

void plotter(){
  
  TString inputFolder = "/eos/user/c/clasaosa/TFM/";
  TString fname = "DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO.root";

  //  TFile* file1 = new TFile(inputFolder+"DIGI_4Mu_eta0/"+fname);
  TFile* file2 = new TFile(inputFolder+"DIGI_4Mu_eta0_2/"+fname);
  TFile* file3 = new TFile(inputFolder+"DIGI_4Mu_eta0_3/"+fname);
  TFile* file4 = new TFile(inputFolder+"DIGI_4Mu_eta0_4/"+fname);

  TString pathFolder = "/DQMData/Run 1/PixelCell/Run summary/Barrel/Layer1/";
  TString hname = "ChargeElec1D";
  TString histogram = pathFolder + hname;

  //  TH1F* histo1 = (TH1F*)file1->Get(histogram);
  TH1F* histo2 = (TH1F*)file2->Get(histogram);
  TH1F* histo3 = (TH1F*)file3->Get(histogram);
  TH1F* histo4 = (TH1F*)file4->Get(histogram);

  gStyle->SetOptStat(0);
  TCanvas* c1 = new TCanvas("c1", "Title", 800, 800);
  TLegend* legend1;

  //  TF1* f1 = new TF1("f1","[0]*TMath::Landau(x,[1],[2])",0,40000);
  TF1* f2 = new TF1("f2","[0]*TMath::Landau(x,[1],[2])",0,40000);
  TF1* f3 = new TF1("f3","[0]*TMath::Landau(x,[1],[2])",0,40000);
  TF1* f4 = new TF1("f4","[0]*TMath::Landau(x,[1],[2])",0,40000);

  ////////////////////////
  ///////Charge1D/////////
  ////////////////////////
                                                                                                                                                     
  // histo1->Draw("HIST");
  // histo1->SetLineColor(8);
  // histo1->SetLineWidth(3);
  // histo1->GetXaxis()->SetRangeUser(0,20);

  // histo1->GetYaxis()->SetTitle("N_{clusters}");
  // histo1->GetYaxis()->SetTitleSize(18);
  // histo1->GetYaxis()->SetTitleFont(63);
  // histo1->GetYaxis()->SetTitleOffset(2.35);
  // histo1->GetYaxis()->SetLabelFont(63);                  
  // histo1->GetYaxis()->SetLabelSize(18);
  // histo1->GetXaxis()->SetTitle("Cluster charge [ToT]");
  // histo1->GetXaxis()->SetTitleSize(15);
  // histo1->GetXaxis()->SetTitleFont(63);
  // histo1->GetXaxis()->SetTitleOffset(1.35);
  // histo1->GetXaxis()->SetLabelFont(63);
  // histo1->GetXaxis()->SetLabelSize(18);

  // histo2->Draw("SAME");
  // histo2->SetLineColor(1);
  // histo2->SetLineWidth(3);
  // histo2->GetXaxis()->SetRangeUser(0,20);

  // histo3->Draw("SAME");
  // histo3->SetLineColor(9);
  // histo3->SetLineWidth(3);
  // histo3->GetXaxis()->SetRangeUser(0,20);

  // histo4->Draw("SAME");
  // histo4->SetLineColor(46);
  // histo4->SetLineWidth(3);
  // histo4->GetXaxis()->SetRangeUser(0,20);

  //////////////////////////////////////////////
  ///////Charge1D for normalized histos/////////
  //////////////////////////////////////////////

  // histo2->Draw("HIST");
  // histo2->SetLineColor(1);
  // histo2->SetLineWidth(3);
  // histo2->GetXaxis()->SetRangeUser(0,20);

  // histo2->GetYaxis()->SetTitle("N_{clusters}");
  // histo2->GetYaxis()->SetTitleSize(18);
  // histo2->GetYaxis()->SetTitleFont(63);
  // histo2->GetYaxis()->SetTitleOffset(2.35);
  // histo2->GetYaxis()->SetLabelFont(63);                  
  // histo2->GetYaxis()->SetLabelSize(18);
  // histo2->GetXaxis()->SetTitle("Cluster charge [ToT]");
  // histo2->GetXaxis()->SetTitleSize(15);
  // histo2->GetXaxis()->SetTitleFont(63);
  // histo2->GetXaxis()->SetTitleOffset(1.35);
  // histo2->GetXaxis()->SetLabelFont(63);
  // histo2->GetXaxis()->SetLabelSize(18);

  // histo3->Draw("SAME");
  // histo3->SetLineColor(9);
  // histo3->SetLineWidth(3);
  // histo3->GetXaxis()->SetRangeUser(0,20);

  // histo4->Draw("SAME");
  // histo4->SetLineColor(46);
  // histo4->SetLineWidth(3);
  // histo4->GetXaxis()->SetRangeUser(0,20);




  ////////////////////////
  /////ChargeElec1D///////
  ////////////////////////

  //////////////////////////////////////
  //1st Option: use circles as markers//
  //////////////////////////////////////

  // histo1->Draw("HIST pe1");
  // histo1->Rebin(6);
  // histo1->SetMarkerStyle(20);
  // histo1->SetMarkerColor(8);
  // histo1->SetLineColor(8);
  // histo1->GetXaxis()->SetRangeUser(0,40000);

  // histo1->GetYaxis()->SetTitle("N_{clusters}");
  // histo1->GetYaxis()->SetTitleSize(18);
  // histo1->GetYaxis()->SetTitleFont(63);
  // histo1->GetYaxis()->SetTitleOffset(2.35);
  // histo1->GetYaxis()->SetLabelFont(63);                  
  // histo1->GetYaxis()->SetLabelSize(18);
  // histo1->GetXaxis()->SetTitle("Cluster charge [Electrons]");
  // histo1->GetXaxis()->SetTitleSize(15);
  // histo1->GetXaxis()->SetTitleFont(63);
  // histo1->GetXaxis()->SetTitleOffset(1.35);
  // histo1->GetXaxis()->SetLabelFont(63);
  // histo1->GetXaxis()->SetLabelSize(18);

  // histo2->Draw("SAME pe1");
  // histo2->Rebin(6);
  // histo2->SetMarkerStyle(20);
  // histo2->SetMarkerColor(1);
  // histo2->SetLineColor(1);
  // histo2->GetXaxis()->SetRangeUser(0,40000);

  // histo3->Draw("SAME pe1");
  // histo3->Rebin(6);
  // histo3->SetMarkerStyle(20);
  // histo3->SetMarkerColor(9);
  // histo3->SetLineColor(9);
  // histo3->GetXaxis()->SetRangeUser(0,40000);

  // histo4->Draw("SAME pe1");
  // histo4->Rebin(6);
  // histo4->SetMarkerStyle(20);
  // histo4->SetMarkerColor(46);
  // histo4->SetLineColor(46);
  // histo4->GetXaxis()->SetRangeUser(0,40000);

  ///////////////////////////////  
  //2nd Option: fit with landau//
  ///////////////////////////////

  // histo1->Draw("HIST pe1");
  // histo1->Rebin(6);
  // f1->SetParameters(histo1->GetMaximum(),12000,1000);
  // histo1->Fit("f1","","",6000,21000);
  // histo1->GetFunction("f1")->SetLineColor(8);
  // histo1->Draw("SAME pe1");
  // //  f1->Draw("SAME");
  // //  f1->SetLineColor(8);
  // histo1->SetMarkerStyle(20);
  // histo1->SetMarkerColor(8);
  // histo1->SetLineColor(8);
  // histo1->GetXaxis()->SetRangeUser(0,40000);

  // histo1->GetYaxis()->SetTitle("N_{clusters}");
  // histo1->GetYaxis()->SetTitleSize(18);
  // histo1->GetYaxis()->SetTitleFont(63);
  // histo1->GetYaxis()->SetTitleOffset(2.35);
  // histo1->GetYaxis()->SetLabelFont(63);                  
  // histo1->GetYaxis()->SetLabelSize(18);
  // histo1->GetXaxis()->SetTitle("Cluster charge [Electrons]");
  // histo1->GetXaxis()->SetTitleSize(15);
  // histo1->GetXaxis()->SetTitleFont(63);
  // histo1->GetXaxis()->SetTitleOffset(1.35);
  // histo1->GetXaxis()->SetLabelFont(63);
  // histo1->GetXaxis()->SetLabelSize(18);

  // histo2->Draw("SAME pe1");
  // histo2->Rebin(6);
  // f2->SetParameters(histo2->GetMaximum(),12000,1000);
  // histo2->Fit("f2","","",6000,21000);
  // histo2->GetFunction("f2")->SetLineColor(1);
  // //  f2->Draw("SAME");
  // //  f2->SetLineColor(1);
  // histo2->SetMarkerStyle(20);
  // histo2->SetMarkerColor(1);
  // histo2->SetLineColor(1);
  // histo2->GetXaxis()->SetRangeUser(0,40000);

  // histo3->Draw("SAME pe1");
  // histo3->Rebin(6);
  // f3->SetParameters(histo3->GetMaximum(),12000,1000);
  // histo3->Fit("f3","","",6000,21000);
  // histo3->GetFunction("f3")->SetLineColor(9);
  // //  f3->Draw("SAME");
  // //  f3->SetLineColor(9);
  // histo3->SetMarkerStyle(20);
  // histo3->SetMarkerColor(9);
  // histo3->SetLineColor(9);
  // histo3->GetXaxis()->SetRangeUser(0,40000);

  // histo4->Draw("SAME pe1");
  // histo4->Rebin(6);
  // f4->SetParameters(histo4->GetMaximum(),12000,1000);
  // histo4->Fit("f4","","",6000,21000);
  // histo4->GetFunction("f4")->SetLineColor(46);
  // //  f4->Draw("SAME");
  // //  f4->SetLineColor(46);
  // histo4->SetMarkerStyle(20);
  // histo4->SetMarkerColor(46);
  // histo4->SetLineColor(46);
  // histo4->GetXaxis()->SetRangeUser(0,40000);



  ///////////////////////////////////////////////////////////
  //1st Option: use circles as markers for normalized plots//
  ///////////////////////////////////////////////////////////

  // histo2->Draw("HIST pe1");
  // histo2->Rebin(6);
  // histo2->SetMarkerStyle(20);
  // histo2->SetMarkerColor(1);
  // histo2->SetLineColor(1);
  // histo2->GetXaxis()->SetRangeUser(0,40000);

  // histo2->GetYaxis()->SetTitle("N_{clusters}");
  // histo2->GetYaxis()->SetTitleSize(18);
  // histo2->GetYaxis()->SetTitleFont(63);
  // histo2->GetYaxis()->SetTitleOffset(2.35);
  // histo2->GetYaxis()->SetLabelFont(63);                  
  // histo2->GetYaxis()->SetLabelSize(18);
  // histo2->GetXaxis()->SetTitle("Cluster charge [Electrons]");
  // histo2->GetXaxis()->SetTitleSize(15);
  // histo2->GetXaxis()->SetTitleFont(63);
  // histo2->GetXaxis()->SetTitleOffset(1.35);
  // histo2->GetXaxis()->SetLabelFont(63);
  // histo2->GetXaxis()->SetLabelSize(18);

  // histo3->Draw("SAME pe1");
  // histo3->Rebin(6);
  // histo3->SetMarkerStyle(20);
  // histo3->SetMarkerColor(9);
  // histo3->SetLineColor(9);
  // histo3->GetXaxis()->SetRangeUser(0,40000);

  // histo4->Draw("SAME pe1");
  // histo4->Rebin(6);
  // histo4->SetMarkerStyle(20);
  // histo4->SetMarkerColor(46);
  // histo4->SetLineColor(46);
  // histo4->GetXaxis()->SetRangeUser(0,40000);

  ////////////////////////////////////////////////////////
  ///2nd Option: fit with landau for normalized histos////
  ////////////////////////////////////////////////////////

  histo2->Draw("HIST pe1");
  histo2->Rebin(6);
  f2->SetParameters(histo2->GetMaximum(),12000,1000);
  histo2->Fit("f2","","",6000,18000);
  histo2->GetFunction("f2")->SetLineColor(1);
  histo2->Draw("SAME pe1");
  //  f2->Draw("SAME");
  //  f2->SetLineColor(1);
  histo2->SetMarkerStyle(20);
  histo2->SetMarkerColor(1);
  histo2->SetLineColor(1);
  histo2->GetXaxis()->SetRangeUser(0,40000);

  histo2->GetYaxis()->SetTitle("N_{clusters}");
  histo2->GetYaxis()->SetTitleSize(18);
  histo2->GetYaxis()->SetTitleFont(63);
  histo2->GetYaxis()->SetTitleOffset(2.35);
  histo2->GetYaxis()->SetLabelFont(63);                  
  histo2->GetYaxis()->SetLabelSize(18);
  histo2->GetXaxis()->SetTitle("Cluster charge [Electrons]");
  histo2->GetXaxis()->SetTitleSize(15);
  histo2->GetXaxis()->SetTitleFont(63);
  histo2->GetXaxis()->SetTitleOffset(1.35);
  histo2->GetXaxis()->SetLabelFont(63);
  histo2->GetXaxis()->SetLabelSize(18);

  histo3->Draw("SAME pe1");
  histo3->Rebin(6);
  f3->SetParameters(histo3->GetMaximum(),12000,1000);
  histo3->Fit("f3","","",6000,23000);
  histo3->GetFunction("f3")->SetLineColor(9);
  //  f3->Draw("SAME");
  //  f3->SetLineColor(9);
  histo3->SetMarkerStyle(20);
  histo3->SetMarkerColor(9);
  histo3->SetLineColor(9);
  histo3->GetXaxis()->SetRangeUser(0,40000);

  histo4->Draw("SAME pe1");
  histo4->Rebin(6);
  f4->SetParameters(histo4->GetMaximum(),12000,1000);
  histo4->Fit("f4","","",6000,28000);
  histo4->GetFunction("f4")->SetLineColor(46);
  //  f4->Draw("SAME");
  //  f4->SetLineColor(46);
  histo4->SetMarkerStyle(20);
  histo4->SetMarkerColor(46);
  histo4->SetLineColor(46);
  histo4->GetXaxis()->SetRangeUser(0,40000);


  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // histo1->SetMaximum(histo4->GetMaximum());
  // histo2->SetMaximum(histo4->GetMaximum());
  // histo3->SetMaximum(histo4->GetMaximum());
  // histo4->SetMaximum(histo4->GetMaximum());

  histo2->SetMaximum(28000);
  histo3->SetMaximum(28000);
  histo4->SetMaximum(28000);


  /////////////////////////
  ///////ADD TEXT//////////
  /////////////////////////

  char latexString[80];
  sprintf(latexString,"MPV for 1700 e^{-} per ADC: %3i #pm %2i", 8790, 13);
  char latexString2[80];
  sprintf(latexString2,"MPV for 2000 e^{-} per ADC: %3i #pm %2i", 8737, 12);
  char latexString3[80];
  sprintf(latexString3,"MPV for 2400 e^{-} per ADC: %3i #pm %2i", 8749, 11);

  TLatex* tl = new TLatex(0.5,0.65,latexString);
  tl->SetNDC();
  tl->SetTextSize(0.025);
  TLatex* tl2 = new TLatex(0.5,0.60,latexString2);
  tl2->SetNDC();
  tl2->SetTextSize(0.025);
  TLatex* tl3 = new TLatex(0.5,0.55,latexString3);
  tl3->SetNDC();
  tl3->SetTextSize(0.025);

  tl->Draw();
  tl2->Draw();
  tl3->Draw();

  /////////////////////////
  /////////LEGEND//////////
  /////////////////////////

  legend1 = new TLegend(0.67,0.76,0.87,0.86);

  //  legend1->AddEntry(histo1,"1500 e^{-} per ADC","pe1");
  legend1->AddEntry(histo2,"1700 e^{-} per ADC","pe1");
  legend1->AddEntry(histo3,"2000 e^{-} per ADC","pe1");
  legend1->AddEntry(histo4,"2400 e^{-} per ADC","pe1");

  legend1->Draw();


  /////////////////////////
  ///////SAVE PLOT/////////
  /////////////////////////

  c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/chargeElec1D_norm_landau.png");
}
