#include "TCanvas.h"
#include "TTree.h"
#include "TString.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>

void plotter_comparing_histograms(){
  
  TString inputFolder = "/eos/user/c/clasaosa/Ph2pixel3D/";
  TString fname = "DQM_5um_edgeGap_final.root";
  TString fname2 = "DQM_ChSh_changeDoWhile.root";
  //  TString fname3 = "DQM_0.4um_NaNvalues_new2.root";

  TFile* file1 = new TFile(inputFolder+"Validate_4Elec_Pt5.6_2026D65_eta0_ChSh_5um_edgeGap/"+fname);
  TFile* file2 = new TFile(inputFolder+"Validate_4Elec_Pt5.6_2026D65_eta0_ChSh_changeDoWhile/"+fname2);
  //  TFile* file3 = new TFile(inputFolder+"Validate_4Elec_Pt5.6_2026D65_eta0_ChSh_0.4um_NaNvalues/"+fname3);

  std::vector<TString> list_layers = {"Layer1/", "Layer2/"};

  std::vector<TString> list_hnames = {"Charge1D", "ChargeElec1D", "ClusterSize1D", "ClusterSize1Dx", "ClusterSize1Dy", "Dx1D", "Dy1D", "DigiCharge1D"};

  TString pathFolder_o = "/DQMData/Run 1/PixelCell/Run summary/Barrel/";

  for(TString nlayer : list_layers){

    TString pathFolder = pathFolder_o + nlayer;

    for(TString hname : list_hnames){

      TString histogram = pathFolder + hname;

      TH1F* histo1 = (TH1F*)file1->Get(histogram);
      TH1F* histo2 = (TH1F*)file2->Get(histogram);
      //      TH1F* histo3 = (TH1F*)file3->Get(histogram);

      gStyle->SetOptStat(0);
      TCanvas* c1 = new TCanvas("c1", "Title", 800, 800);
      TLegend* legend1;
                                                                
      c1->cd();
      c1->SetLogy();
      gPad->SetLeftMargin(0.18);
      gPad->SetRightMargin(0.05);

      histo2->Draw("HIST");

      if(hname == "ChargeElec1D"){
	histo2->Rebin(4);
      }

      histo2->SetLineColor(kRed+2);
      histo2->SetLineWidth(3);
      if(hname == "Charge1D" || hname == "ChargeElec1D" || hname == "ClusterSize1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy" || hname == "Dx1D" || hname == "Dy1D"){
	histo2->GetYaxis()->SetTitle("N_{clusters}");
      }else if(hname == "DigiCharge1D"){
	histo2->GetYaxis()->SetTitle("N_{digis}");
      }
      histo2->GetYaxis()->SetTitleSize(34);
      histo2->GetYaxis()->SetTitleFont(63);
      if(hname == "Dx1D" || hname == "Dy1D"){
	histo2->GetYaxis()->SetTitleOffset(1.7);
      }else{
	histo2->GetYaxis()->SetTitleOffset(2);
      }
      histo2->GetYaxis()->SetLabelFont(63);                  
      histo2->GetYaxis()->SetLabelSize(28);
      if(hname == "Charge1D"){
	histo2->GetXaxis()->SetTitle("Cluster charge [ToT]");
      }else if(hname == "ChargeElec1D"){
	histo2->GetXaxis()->SetTitle("Cluster charge [electrons]");
      }else if(hname == "ClusterSize1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy"){
	histo2->GetXaxis()->SetTitle("Cluster size");
      }else if(hname == "DigiCharge1D"){
	histo2->GetXaxis()->SetTitle("Digi charge [ToT]");
      }else if(hname == "Dx1D"){
	histo2->GetXaxis()->SetTitle("x_{PSimHit}-x_{cluster} [#mum]");
      }else if(hname == "Dy1D"){
	histo2->GetXaxis()->SetTitle("y_{PSimHit}-y_{cluster} [#mum]");
      }
      if(hname == "Dx1D" || hname == "Dy1D"){
	histo2->GetXaxis()->SetTitleSize(34);
      }else{
	histo2->GetXaxis()->SetTitleSize(28);
      }
      histo2->GetXaxis()->SetTitleFont(63);
      if(hname == "Dx1D" || hname == "Dy1D"){
	histo2->GetXaxis()->SetTitleOffset(1);
      }else{
	histo2->GetXaxis()->SetTitleOffset(1.15);
      }
      histo2->GetXaxis()->SetLabelFont(63);
      histo2->GetXaxis()->SetLabelSize(28);
      if(hname == "Charge1D"){
	//        histo2->GetXaxis()->SetRangeUser(0,16);
	histo2->GetXaxis()->SetRangeUser(0,50);
      }else if(hname == "DigiCharge1D"){ // No need of this one on logarithm scale -> it's not useful
        histo2->GetXaxis()->SetRangeUser(0,16);
      }else if(hname == "ChargeElec1D"){
	//	histo2->GetXaxis()->SetRangeUser(0,25000);
	histo2->GetXaxis()->SetRangeUser(0,60000);
      }else if(hname == "ClusterSize1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy"){
	histo2->GetXaxis()->SetRangeUser(0,10);
	// histo2->GetXaxis()->SetRangeUser(0,10);
      }else if(hname == "Dx1D"){
	histo2->GetXaxis()->SetRangeUser(-50,50);
	// histo2->GetXaxis()->SetRangeUser(-50,50);
      }else if(hname == "Dy1D"){
	histo2->GetXaxis()->SetRangeUser(-150,150);
	// histo2->GetXaxis()->SetRangeUser(-150,150);
      }

      histo1->Draw("SAME");
      if(hname == "ChargeElec1D"){
	histo1->Rebin(4);
      }
      histo1->SetLineColor(kBlue+3);
      histo1->SetLineWidth(3);

      // histo3->Draw("SAME");
      // if(hname == "ChargeElec1D"){
      // 	histo3->Rebin(4);
      // }
      // histo3->SetLineColor(kGreen+3);
      // histo3->SetLineWidth(3);

      legend1 = new TLegend(0.7,0.76,0.9,0.86);
      legend1->SetBorderSize(0);
      legend1->AddEntry(histo1,"do-while loop","l");
      legend1->AddEntry(histo2,"for loop","l");
      //      legend1->AddEntry(histo3,"w/o NaN - new2","l");
      legend1->Draw();

  /////////////////////////
  ///////SAVE PLOT/////////
  /////////////////////////

      TString png_name = hname;
      if(nlayer == "Layer1/"){
	//	c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_comp.png");
	c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_logy_comp.png");
      }else {
	//	c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_l2_comp.png");
	c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_logy_l2_comp.png");
      }
    }
  }
}
