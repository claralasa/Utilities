#include "TCanvas.h"
#include "TTree.h"
#include "TString.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>

void plotter_comparing_profilesFromPixelCellHistograms(){
  
  TString inputFolder = "/eos/user/c/clasaosa/Ph2pixel3D/";
  TString fname = "DQM_5um_edgeGap_final.root";
  TString fname2 = "DQM_ChSh_changeDoWhile.root";
  //  TString fname3 = "DQM_0.4um_NaNvalues_new2.root";

  TFile* file1 = new TFile(inputFolder+"Validate_4Elec_Pt5.6_2026D65_eta0_ChSh_5um_edgeGap/"+fname);
  TFile* file2 = new TFile(inputFolder+"Validate_4Elec_Pt5.6_2026D65_eta0_ChSh_changeDoWhile/"+fname2);
  //  TFile* file3 = new TFile(inputFolder+"Validate_4Elec_Pt5.6_2026D65_eta0_ChSh_0.4um_NaNvalues/"+fname3);

  std::vector<TString> list_layers = {"Layer1/", "Layer2/"};

  std::vector<TString> list_hnames = {"Charge_1", "Charge_elec_1", "ClusterSize_1", "Efficiency_1", "MatchedPosition_1", "Position_1", "Dx_1", "Dy_1"};

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
      TCanvas* c2 = new TCanvas("c2", "Title", 800, 800);
      TLegend* legend1;
      TLegend* legend2;

      TProfile2D* profile1 = (TProfile2D*)histo1->Clone("profile1");
      TProfile2D* profile2 = (TProfile2D*)histo2->Clone("profile2");
      //      TProfile2D* profile3 = (TProfile2D*)histo3->Clone("profile3");
                                                                
      ///////// X Profile

      c1->cd();
      gPad->SetLeftMargin(0.18);
      gPad->SetRightMargin(0.05);
      gPad->SetGridy();

      TH1* prof1 = (TH1*)profile1->ProfileX();
      TH1* prof2 = (TH1*)profile2->ProfileX();
      //      TH1* prof3 = (TH1*)profile3->ProfileX();

      prof1->Draw();
      gPad->Update();

      prof1->SetLineColor(kBlue+3);
      prof1->SetLineWidth(3);
      if(hname == "Charge_1"){
	prof1->GetYaxis()->SetTitle("Average <ToT>");
      }else if(hname == "Charge_elec_1"){
	prof1->GetYaxis()->SetTitle("Average <Electrons>");
      }else if(hname == "ClusterSize_1"){
	prof1->GetYaxis()->SetTitle("Average <Cluster Size>");
      }else if(hname == "Efficiency_1"){
	prof1->GetYaxis()->SetTitle("Average <#varepsilon>");
      }else if(hname == "MatchedPosition_1" || hname == "Position_1"){
	prof1->GetYaxis()->SetTitle("Average N_{clusters}");
      }else if(hname == "Dx_1"){
	prof1->GetYaxis()->SetTitle("Average <#Deltax [#mum]>");
      }else if(hname == "Dy_1"){
	prof1->GetYaxis()->SetTitle("Average <#Deltay [#mum]>");
      }
      prof1->GetYaxis()->SetTitleSize(32);
      prof1->GetYaxis()->SetTitleFont(63);
      if(hname == "Charge_1" || hname == "Dx_1" || hname == "Dy_1"){
	prof1->GetYaxis()->SetTitleOffset(1.75);
      }else if(hname == "Charge_elec_1" || hname == "ClusterSize_1" || hname == "Efficiency_1" || hname == "MatchedPosition_1" || hname == "Position_1"){
	prof1->GetYaxis()->SetTitleOffset(2);
      }
      prof1->GetYaxis()->SetLabelFont(63);                 
      prof1->GetYaxis()->SetLabelSize(28);
      prof1->GetXaxis()->SetTitle("x [#mum]");
      prof1->GetXaxis()->SetTitleSize(28);
      prof1->GetXaxis()->SetTitleFont(63);
      prof1->GetXaxis()->SetTitleOffset(1.15);
      prof1->GetXaxis()->SetLabelFont(63);
      prof1->GetXaxis()->SetLabelSize(28);

      prof2->Draw("SAME");
      prof2->SetLineColor(kRed+2);
      prof2->SetLineWidth(3);

      // prof3->Draw("SAME");
      // prof3->SetLineColor(kGreen+3);
      // prof3->SetLineWidth(3);

      if(hname == "Charge_1" || hname == "Charge_elec_1" || hname == "Efficiency_1" || hname == "Dx_1" || hname == "Dy_1"){
	legend1 = new TLegend(0.67,0.16,0.87,0.26);
      }else if(hname == "ClusterSize_1" || hname == "MatchedPosition_1" || hname == "Position_1"){
	legend1 = new TLegend(0.67,0.76,0.87,0.86);
      }
      legend1->SetBorderSize(0);
      legend1->AddEntry(prof1,"do-while loop","l");
      legend1->AddEntry(prof2,"for loop","l");
      //      legend1->AddEntry(prof3,"w/o NaN - new2","l");
      legend1->Draw();

      ///////// Y Profile

      c2->cd();
      gPad->SetLeftMargin(0.18);
      gPad->SetRightMargin(0.05);
      gPad->SetGridy();

      TH1* prof4 = (TH1*)profile1->ProfileY();
      TH1* prof5 = (TH1*)profile2->ProfileY();
      //      TH1* prof6 = (TH1*)profile3->ProfileY();

      prof4->Draw();
      gPad->Update();

      prof4->SetLineColor(kBlue+3);
      prof4->SetLineWidth(3);
      if(hname == "Charge_1"){
	prof4->GetYaxis()->SetTitle("Average <ToT>");
      }else if(hname == "Charge_elec_1"){
	prof4->GetYaxis()->SetTitle("Average <Electrons>");
      }else if(hname == "ClusterSize_1"){
	prof4->GetYaxis()->SetTitle("Average <Cluster Size>");
      }else if(hname == "Efficiency_1"){
	prof4->GetYaxis()->SetTitle("Average <#varepsilon>");
      }else if(hname == "MatchedPosition_1" || hname == "Position_1"){
	prof4->GetYaxis()->SetTitle("Average N_{clusters}");
      }else if(hname == "Dx_1"){
	prof4->GetYaxis()->SetTitle("Average <#Deltax [#mum]>");
      }else if(hname == "Dy_1"){
	prof4->GetYaxis()->SetTitle("Average <#Deltay [#mum]>");
      }
      prof4->GetYaxis()->SetTitleSize(32);
      prof4->GetYaxis()->SetTitleFont(63);
      if(hname == "Charge_1" || hname == "Dx_1" || hname == "Dy_1"){
	prof4->GetYaxis()->SetTitleOffset(1.75);
      }else if(hname == "Charge_elec_1" || hname == "ClusterSize_1" || hname == "Efficiency_1" || hname == "MatchedPosition_1" || hname == "Position_1"){
	prof4->GetYaxis()->SetTitleOffset(2);
      }
      prof4->GetYaxis()->SetLabelFont(63);
      prof4->GetYaxis()->SetLabelSize(28);
      prof4->GetXaxis()->SetTitle("y [#mum]");
      prof4->GetXaxis()->SetTitleSize(28);
      prof4->GetXaxis()->SetTitleFont(63);
      prof4->GetXaxis()->SetTitleOffset(1.15);
      prof4->GetXaxis()->SetLabelFont(63);
      prof4->GetXaxis()->SetLabelSize(28);

      prof5->Draw("SAME");
      prof5->SetLineColor(kRed+2);
      prof5->SetLineWidth(3);

      // prof6->Draw("SAME");
      // prof6->SetLineColor(kGreen+3);
      // prof6->SetLineWidth(3);

      if(hname == "Charge_1" || hname == "Charge_elec_1" || hname == "Efficiency_1" || hname == "Dx_1" || hname == "Dy_1"){
	legend2 = new TLegend(0.67,0.16,0.87,0.26);
      }else if(hname == "ClusterSize_1" || hname == "MatchedPosition_1" || hname == "Position_1"){
	legend2 = new TLegend(0.67,0.76,0.87,0.86);
      }
      legend2->SetBorderSize(0);
      legend2->AddEntry(prof4,"do-while loop","l");
      legend2->AddEntry(prof5,"for loop","l");
      //      legend2->AddEntry(prof6,"w/o NaN - new2","l");
      legend2->Draw();


      /////////////////////////
      ///////SAVE PLOT/////////
      /////////////////////////

      TString png_name = hname;
      if(nlayer == "Layer1/"){
	c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_profx_comp.png");
	c2->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_profy_comp.png");
      }else {
	c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_profx_l2_comp.png");
	c2->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_profy_l2_comp.png");
      }
    }
  }
}
