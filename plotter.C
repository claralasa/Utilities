///////////////////////////////////////////////////////////////////
////////// Creation of a list storing the input files /////////////
///////////////////////////////////////////////////////////////////
//////////////// Author: Clara Lasaosa Garcia /////////////////////
///////////////////////////////////////////////////////////////////

#include "TCanvas.h"
#include "TTree.h"
#include "TString.h"
#include "TH1D.h"
#include "TFile.h"
#include <iostream>
#include <fstream>

/////////////////////
/// HOW TO USE IT ///
/////////////////////

// root -l -q -b "plotter.C"

////////////////////

void plotter(){
  
  TString inputFolder = "/eos/user/c/clasaosa/Ph2pixel3D/";
  TString fname = "DQM_4Mu_Pt1_200_2026D65_eta0.root";
  TString fname2 = "DQM_V0001_R000000001__Global__CMSSW_X_Y_Z__RECO_1600_NPColumn.root";

  TFile* file = new TFile(inputFolder+"Validate_4Mu_Pt1_200_2026D65_eta0_newGeom/"+fname);
  TFile* file2 = new TFile(inputFolder+"Validate_4Mu_Pt1_200_2026D54_eta0_oldGeom/"+fname2);

  std::vector<TString> list_layers = {"Layer1/", "Layer2/"};

  std::vector<TString> list_hnames = {"Charge1D", "ChargeElec1D", "ClusterSize1D", "ClusterSize1Dx", "ClusterSize1Dy", "DigiCharge1D", "Dx1D", "Dy1D", "TrackAngleDxdz", "TrackAngleDydz", "Charge_1", "Charge_elec_1", "ClusterSize_1", "Dx_1", "Dy_1", "Efficiency_1", "MatchedPosition_1", "Position_1", "SimClusterCharge"};

  std::vector<TString> list_gnames = {"DigiRZ", "DigiXY", "TrackRZ", "TrackXY"};

  TString pathFolder_g = "/DQMData/Run 1/PixelCell/Run summary/";
  TString pathFolder_b = pathFolder_g + "Barrel/";

  // -------------------------------------------------- General histograms

  for(TString gname : list_gnames){

    TString histogram_g = pathFolder_g + gname;
    
    TH2F* histo = (TH2F*)file->Get(histogram_g);
    TH2F* histo2 = (TH2F*)file2->Get(histogram_g);

    gStyle->SetOptStat(0);
    TCanvas* c9 = new TCanvas("c9", "Title", 800, 800);
    TCanvas* c10 = new TCanvas("c10", "Title", 800, 800);


    //////////////////
    // First Canvas //
    //////////////////

    c9->cd();
    gPad->SetLeftMargin(0.10);
    gPad->SetRightMargin(0.19);
    gPad->SetBottomMargin(0.2);

    histo->Draw("colz");
    gPad->Update();
    TPaletteAxis* palette = (TPaletteAxis*)histo->GetListOfFunctions()->FindObject("palette");
    palette->SetX1NDC(0.83);
    palette->SetX2NDC(0.87);
    palette->SetY1NDC(0.2);
    palette->SetY2NDC(0.9);

    if(gname == "TrackRZ" || gname == "DigiRZ"){
      histo->GetXaxis()->SetRangeUser(-40,40);
    }else{
      histo->GetXaxis()->SetRangeUser(-20,20);
    }
    if(gname == "TrackRZ" || gname == "DigiRZ"){
      histo->GetXaxis()->SetTitle("z [cm]");
    }else{
      histo->GetXaxis()->SetTitle("x [cm]");
    }
    histo->GetXaxis()->SetTitleFont(63);
    histo->GetXaxis()->SetTitleSize(28);
    histo->GetXaxis()->SetTitleOffset(1);
    histo->GetXaxis()->SetLabelFont(63);
    histo->GetXaxis()->SetLabelSize(28);

    if(gname == "TrackRZ" || gname == "DigiRZ"){
      histo->GetYaxis()->SetRangeUser(0,16);
    }else{
      histo->GetYaxis()->SetRangeUser(-20,20);
    }
    if(gname == "TrackRZ" || gname == "DigiRZ"){
      histo->GetYaxis()->SetTitle("r [cm]");
    }else{
      histo->GetYaxis()->SetTitle("y [cm]");
    }
    histo->GetYaxis()->SetTitleFont(63);
    histo->GetYaxis()->SetTitleSize(28);
    histo->GetYaxis()->SetTitleOffset(1.2);
    histo->GetYaxis()->SetLabelFont(63);
    histo->GetYaxis()->SetLabelSize(28);

    if(gname == "DigiRZ" || gname == "DigiXY"){
      histo->GetZaxis()->SetTitle("N_{digi}");
    }else{
      histo->GetZaxis()->SetTitle("N_{tracks}");
    }
    histo->GetZaxis()->SetTitleFont(63);
    histo->GetZaxis()->SetTitleSize(28);
    histo->GetZaxis()->SetTitleOffset(1.8);
    histo->GetZaxis()->SetLabelFont(63);
    histo->GetZaxis()->SetLabelSize(28);


    ///////////////////
    // Second Canvas //
    ///////////////////

    c10->cd();
    gPad->SetLeftMargin(0.10);
    gPad->SetRightMargin(0.19);
    gPad->SetBottomMargin(0.2);

    histo2->Draw("colz");
    gPad->Update();
    TPaletteAxis* palette2 = (TPaletteAxis*)histo2->GetListOfFunctions()->FindObject("palette");
    palette2->SetX1NDC(0.83);
    palette2->SetX2NDC(0.87);
    palette2->SetY1NDC(0.2);
    palette2->SetY2NDC(0.9);

    if(gname == "TrackRZ" || gname == "DigiRZ"){
      histo2->GetXaxis()->SetRangeUser(-40,40);
    }else{
      histo2->GetXaxis()->SetRangeUser(-20,20);
    }
    if(gname == "TrackRZ" || gname == "DigiRZ"){
      histo2->GetXaxis()->SetTitle("z [cm]");
    }else{
      histo2->GetXaxis()->SetTitle("x [cm]");
    }
    histo2->GetXaxis()->SetTitleFont(63);
    histo2->GetXaxis()->SetTitleSize(28);
    histo2->GetXaxis()->SetTitleOffset(1);
    histo2->GetXaxis()->SetLabelFont(63);
    histo2->GetXaxis()->SetLabelSize(28);

    if(gname == "TrackRZ" || gname == "DigiRZ"){
      histo2->GetYaxis()->SetRangeUser(0,16);
    }else{
      histo2->GetYaxis()->SetRangeUser(-20,20);
    }
    if(gname == "TrackRZ" || gname == "DigiRZ"){
      histo2->GetYaxis()->SetTitle("r [cm]");
    }else{
      histo2->GetYaxis()->SetTitle("y [cm]");
    }
    histo2->GetYaxis()->SetTitleFont(63);
    histo2->GetYaxis()->SetTitleSize(28);
    histo2->GetYaxis()->SetTitleOffset(1.2);
    histo2->GetYaxis()->SetLabelFont(63);
    histo2->GetYaxis()->SetLabelSize(28);

    if(gname == "DigiRZ" || gname == "DigiXY"){
      histo2->GetZaxis()->SetTitle("N_{digi}");
    }else{
      histo2->GetZaxis()->SetTitle("N_{tracks}");
    }
    histo2->GetZaxis()->SetTitleFont(63);
    histo2->GetZaxis()->SetTitleSize(28);
    histo2->GetZaxis()->SetTitleOffset(1.8);
    histo2->GetZaxis()->SetLabelFont(63);
    histo2->GetZaxis()->SetLabelSize(28);


    /////////////////////////
    ///////SAVE PLOT/////////
    /////////////////////////

    TString png_name = gname;
    c9->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+".png");
    c10->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_old.png");

  }

  // -------------------------------------------------- Histograms per layer

  for(TString nlayer : list_layers){

    TString pathFolder = pathFolder_b + nlayer;

    for(TString hname : list_hnames){

      TString histogram = pathFolder + hname;

      if(hname == "Charge_1" || hname == "Charge_elec_1" || hname == "ClusterSize_1" || hname == "Dx_1" || hname == "Dy_1" || hname == "Efficiency_1"){

	TH2F* histo = (TH2F*)file->Get(histogram);
	TH2F* histo2 = (TH2F*)file2->Get(histogram);

	gStyle->SetOptStat(0);
	TCanvas* c3 = new TCanvas("c3", "Title", 400, 800);
	TCanvas* c4 = new TCanvas("c4", "Title", 400, 800);

	TProfile2D* profile = (TProfile2D*)histo->Clone("profile");
	TProfile2D* profile2 = (TProfile2D*)histo2->Clone("profile2");


	//////////////////
	// First Canvas //
	//////////////////

	c3->cd();
	if(hname == "Charge_elec_1"){
	  gPad->SetLeftMargin(0.23);
	  gPad->SetRightMargin(0.37);
	}else{
          gPad->SetLeftMargin(0.3);
          gPad->SetRightMargin(0.3);
	}

	profile->Draw("colz");
	gPad->Update();
	TPaletteAxis* palette = (TPaletteAxis*)profile->GetListOfFunctions()->FindObject("palette");
	if(hname == "Charge_elec_1"){
	  palette->SetX1NDC(0.66);
	  palette->SetX2NDC(0.71);
	  palette->SetY1NDC(0.1);
	  palette->SetY2NDC(0.9);
	}else{
          palette->SetX1NDC(0.73);
          palette->SetX2NDC(0.78);
          palette->SetY1NDC(0.1);
	  palette->SetY2NDC(0.9);
	}

	profile->GetXaxis()->SetTitle("x [#mum]");
	profile->GetXaxis()->SetTitleFont(63);
	profile->GetXaxis()->SetTitleSize(28);
	profile->GetXaxis()->SetTitleOffset(1);
        profile->GetXaxis()->SetLabelFont(63);
        profile->GetXaxis()->SetLabelSize(28);

	profile->GetYaxis()->SetTitle("y [#mum]");
        profile->GetYaxis()->SetTitleFont(63);
        profile->GetYaxis()->SetTitleSize(28);
	profile->GetYaxis()->SetTitleOffset(2.9);
        profile->GetYaxis()->SetLabelFont(63);
        profile->GetYaxis()->SetLabelSize(28);
	profile->GetYaxis()->SetLabelOffset(0.02);

	if(hname == "Charge_1"){
	  profile->GetZaxis()->SetRangeUser(0,14);
	}else if (hname == "Charge_elec_1"){
	  profile->GetZaxis()->SetRangeUser(0,20000);
	}else if (hname == "ClusterSize_1"){
	  profile->GetZaxis()->SetRangeUser(0,2);
	}else if (hname == "Dx_1"){
	  profile->GetZaxis()->SetRangeUser(-50,50);
	}else if (hname == "Dy_1"){
	  profile->GetZaxis()->SetRangeUser(-150,150);
	}else if (hname == "Efficiency_1"){
	  profile->GetZaxis()->SetRangeUser(0,1);
	}

	if(hname == "Charge_1"){
	  profile->GetZaxis()->SetTitle("<ToT>");
	}else if (hname == "Charge_elec_1"){
	  profile->GetZaxis()->SetTitle("<Electrons>");
        }else if (hname == "ClusterSize_1"){
	  profile->GetZaxis()->SetTitle("<Cluster size>");
	}else if (hname == "Dx_1"){
	  profile->GetZaxis()->SetTitle("<#Deltax [#mum]>");
	}else if (hname == "Dy_1"){
	  profile->GetZaxis()->SetTitle("<#Deltay [#mum]>");
	}else if (hname == "Efficiency_1"){
	  profile->GetZaxis()->SetTitle("<#varepsilon>");
	}

	profile->GetZaxis()->SetTitleFont(63);

	if(hname == "Efficiency_1"){
	  profile->GetZaxis()->SetTitleSize(32);
	}else{
          profile->GetZaxis()->SetTitleSize(28);
	}

	if(hname == "Dx_1" || hname == "ClusterSize_1"){
	  profile->GetZaxis()->SetTitleOffset(2.6);
	}else if(hname == "Dy_1"){
          profile->GetZaxis()->SetTitleOffset(2.95);
	}else if (hname == "Charge_elec_1"){
          profile->GetZaxis()->SetTitleOffset(4.1);
	}else{
          profile->GetZaxis()->SetTitleOffset(2.2);
	}

	profile->GetZaxis()->SetLabelOffset(0.02);
        profile->GetZaxis()->SetLabelFont(63);
        profile->GetZaxis()->SetLabelSize(28);


	///////////////////
	// Second Canvas //
	///////////////////

	c4->cd();
	if(hname == "Charge_elec_1"){
	  gPad->SetLeftMargin(0.23);
	  gPad->SetRightMargin(0.37);
	}else{
          gPad->SetLeftMargin(0.3);
          gPad->SetRightMargin(0.3);
	}

	profile2->Draw("colz");
	gPad->Update();
	TPaletteAxis* palette2 = (TPaletteAxis*)profile2->GetListOfFunctions()->FindObject("palette");
	if(hname == "Charge_elec_1"){
	  palette2->SetX1NDC(0.66);
	  palette2->SetX2NDC(0.71);
	  palette2->SetY1NDC(0.1);
	  palette2->SetY2NDC(0.9);
	}else{
          palette2->SetX1NDC(0.73);
          palette2->SetX2NDC(0.78);
          palette2->SetY1NDC(0.1);
	  palette2->SetY2NDC(0.9);
	}

	profile2->GetXaxis()->SetTitle("x [#mum]");
	profile2->GetXaxis()->SetTitleFont(63);
	profile2->GetXaxis()->SetTitleSize(28);
	profile2->GetXaxis()->SetTitleOffset(1);
        profile2->GetXaxis()->SetLabelFont(63);
        profile2->GetXaxis()->SetLabelSize(28);

	profile2->GetYaxis()->SetTitle("y [#mum]");
        profile2->GetYaxis()->SetTitleFont(63);
        profile2->GetYaxis()->SetTitleSize(28);
	profile2->GetYaxis()->SetTitleOffset(2.9);
        profile2->GetYaxis()->SetLabelFont(63);
        profile2->GetYaxis()->SetLabelSize(28);
	profile2->GetYaxis()->SetLabelOffset(0.02);

	if(hname == "Charge_1"){
	  profile2->GetZaxis()->SetRangeUser(0,14);
	}else if (hname == "Charge_elec_1"){
	  profile2->GetZaxis()->SetRangeUser(0,20000);
	}else if (hname == "ClusterSize_1"){
	  profile2->GetZaxis()->SetRangeUser(0,2);
	}else if (hname == "Dx_1"){
	  profile2->GetZaxis()->SetRangeUser(-50,50);
	}else if (hname == "Dy_1"){
	  profile2->GetZaxis()->SetRangeUser(-150,150);
	}else if (hname == "Efficiency_1"){
	  profile2->GetZaxis()->SetRangeUser(0,1);
	}

	if(hname == "Charge_1"){
	  profile2->GetZaxis()->SetTitle("<ToT>");
	}else if (hname == "Charge_elec_1"){
	  profile2->GetZaxis()->SetTitle("<Electrons>");
        }else if (hname == "ClusterSize_1"){
	  profile2->GetZaxis()->SetTitle("<Cluster size>");
	}else if (hname == "Dx_1"){
	  profile2->GetZaxis()->SetTitle("<#Deltax [#mum]>");
	}else if (hname == "Dy_1"){
	  profile2->GetZaxis()->SetTitle("<#Deltay [#mum]>");
	}else if (hname == "Efficiency_1"){
	  profile2->GetZaxis()->SetTitle("<#varepsilon>");
	}

	profile2->GetZaxis()->SetTitleFont(63);
	
	if(hname == "Efficiency_1"){
	  profile2->GetZaxis()->SetTitleSize(32);
	}else{
          profile2->GetZaxis()->SetTitleSize(28);
	}

	if(hname == "Dx_1" || hname == "ClusterSize_1"){
	  profile2->GetZaxis()->SetTitleOffset(2.6);
	}else if(hname == "Dy_1"){
          profile2->GetZaxis()->SetTitleOffset(2.95);
	}else if (hname == "Charge_elec_1"){
          profile2->GetZaxis()->SetTitleOffset(4.1);
	}else{
          profile2->GetZaxis()->SetTitleOffset(2.2);
	}

        profile2->GetZaxis()->SetLabelFont(63);
        profile2->GetZaxis()->SetLabelSize(28);


	/////////////////////////
	///////SAVE PLOT/////////
	/////////////////////////

	TString png_name = hname;
	if(nlayer == "Layer1/"){
	  c3->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer1.png");
	  c4->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer1_old.png");
	}else if(nlayer == "Layer2/"){
	  c3->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer2.png");
	  c4->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer2_old.png");
	}

      }else if(hname == "Position_1" || hname == "MatchedPosition_1"){

	TH2F* histo = (TH2F*)file->Get(histogram);
	TH2F* histo2 = (TH2F*)file2->Get(histogram);

	gStyle->SetOptStat(0);
	TCanvas* c5 = new TCanvas("c5", "Title", 400, 800);
	TCanvas* c6 = new TCanvas("c6", "Title", 400, 800);


	//////////////////
	// First Canvas //
	//////////////////

	c5->cd();
        gPad->SetLeftMargin(0.3);
        gPad->SetRightMargin(0.3);

	histo->Draw("colz");
	gPad->Update();
	TPaletteAxis* palette = (TPaletteAxis*)histo->GetListOfFunctions()->FindObject("palette");
        palette->SetX1NDC(0.73);
        palette->SetX2NDC(0.78);
        palette->SetY1NDC(0.1);
	palette->SetY2NDC(0.9);

	histo->GetXaxis()->SetTitle("x [#mum]");
	histo->GetXaxis()->SetTitleFont(63);
	histo->GetXaxis()->SetTitleSize(28);
	histo->GetXaxis()->SetTitleOffset(1);
        histo->GetXaxis()->SetLabelFont(63);
        histo->GetXaxis()->SetLabelSize(28);

	histo->GetYaxis()->SetTitle("y [#mum]");
        histo->GetYaxis()->SetTitleFont(63);
        histo->GetYaxis()->SetTitleSize(28);
	histo->GetYaxis()->SetTitleOffset(2.9);
        histo->GetYaxis()->SetLabelFont(63);
        histo->GetYaxis()->SetLabelSize(28);
	histo->GetYaxis()->SetLabelOffset(0.02);

	histo->GetZaxis()->SetTitle("N_{clusters}");
	histo->GetZaxis()->SetTitleFont(63);
        histo->GetZaxis()->SetTitleSize(32);
        histo->GetZaxis()->SetTitleOffset(2.4);
	histo->GetZaxis()->SetLabelOffset(0.02);
        histo->GetZaxis()->SetLabelFont(63);
        histo->GetZaxis()->SetLabelSize(28);


	///////////////////
	// Second Canvas //
	///////////////////

	c6->cd();
        gPad->SetLeftMargin(0.3);
        gPad->SetRightMargin(0.3);

	histo2->Draw("colz");
	gPad->Update();
	TPaletteAxis* palette2 = (TPaletteAxis*)histo2->GetListOfFunctions()->FindObject("palette");
        palette2->SetX1NDC(0.73);
        palette2->SetX2NDC(0.78);
        palette2->SetY1NDC(0.1);
	palette2->SetY2NDC(0.9);

	histo2->GetXaxis()->SetTitle("x [#mum]");
	histo2->GetXaxis()->SetTitleFont(63);
	histo2->GetXaxis()->SetTitleSize(28);
	histo2->GetXaxis()->SetTitleOffset(1);
        histo2->GetXaxis()->SetLabelFont(63);
        histo2->GetXaxis()->SetLabelSize(28);

	histo2->GetYaxis()->SetTitle("y [#mum]");
        histo2->GetYaxis()->SetTitleFont(63);
        histo2->GetYaxis()->SetTitleSize(28);
	histo2->GetYaxis()->SetTitleOffset(2.9);
        histo2->GetYaxis()->SetLabelFont(63);
        histo2->GetYaxis()->SetLabelSize(28);
	histo2->GetYaxis()->SetLabelOffset(0.02);

	histo2->GetZaxis()->SetTitle("N_{clusters}");
	histo2->GetZaxis()->SetTitleFont(63);
        histo2->GetZaxis()->SetTitleSize(32);
        histo2->GetZaxis()->SetTitleOffset(2.4);
	histo2->GetZaxis()->SetLabelOffset(0.02);
        histo2->GetZaxis()->SetLabelFont(63);
        histo2->GetZaxis()->SetLabelSize(28);


	/////////////////////////
	///////SAVE PLOT/////////
	/////////////////////////

	TString png_name = hname;
	if(nlayer == "Layer1/"){
	  c5->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer1.png");
	  c6->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer1_old.png");
	}else if(nlayer == "Layer2/"){
	  c5->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer2.png");
	  c6->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer2_old.png");
	}

      }else if(hname == "SimClusterCharge"){

	TH2F* histo = (TH2F*)file->Get(histogram);
	TH2F* histo2 = (TH2F*)file2->Get(histogram);

	gStyle->SetOptStat(0);
	TCanvas* c7 = new TCanvas("c7", "Title", 800, 800);
	TCanvas* c8 = new TCanvas("c8", "Title", 800, 800);


	//////////////////
	// First Canvas //
	//////////////////

	c7->cd();
	gPad->SetLeftMargin(0.15);
	gPad->SetRightMargin(0.15);

	histo->Draw("colz");
	gPad->Update();
	TPaletteAxis* palette = (TPaletteAxis*)histo->GetListOfFunctions()->FindObject("palette");
        palette->SetX1NDC(0.87);
        palette->SetX2NDC(0.91);
        palette->SetY1NDC(0.1);
	palette->SetY2NDC(0.9);

	histo->GetXaxis()->SetTitle("deposited E_{sim} [keV]");
	histo->GetXaxis()->SetTitleFont(63);
	histo->GetXaxis()->SetTitleSize(28);
	histo->GetXaxis()->SetTitleOffset(1.1);
        histo->GetXaxis()->SetLabelFont(63);
        histo->GetXaxis()->SetLabelSize(28);

	histo->GetYaxis()->SetTitle("cluster_{charge} [Electrons]");
        histo->GetYaxis()->SetTitleFont(63);
        histo->GetYaxis()->SetTitleSize(28);
	histo->GetYaxis()->SetTitleOffset(1.5);
        histo->GetYaxis()->SetLabelFont(63);
        histo->GetYaxis()->SetLabelSize(28);

        histo->GetZaxis()->SetLabelFont(63);
        histo->GetZaxis()->SetLabelSize(28);


	///////////////////
	// Second Canvas //
	///////////////////

	c8->cd();
	gPad->SetLeftMargin(0.15);
	gPad->SetRightMargin(0.15);

	histo2->Draw("colz");
	gPad->Update();
	TPaletteAxis* palette2 = (TPaletteAxis*)histo2->GetListOfFunctions()->FindObject("palette");
        palette2->SetX1NDC(0.87);
        palette2->SetX2NDC(0.91);
        palette2->SetY1NDC(0.1);
	palette2->SetY2NDC(0.9);

	histo2->GetXaxis()->SetTitle("deposited E_{sim} [keV]");
	histo2->GetXaxis()->SetTitleFont(63);
	histo2->GetXaxis()->SetTitleSize(28);
	histo2->GetXaxis()->SetTitleOffset(1.1);
        histo2->GetXaxis()->SetLabelFont(63);
        histo2->GetXaxis()->SetLabelSize(28);

	histo2->GetYaxis()->SetTitle("cluster_{charge} [Electrons]");
        histo2->GetYaxis()->SetTitleFont(63);
        histo2->GetYaxis()->SetTitleSize(28);
	histo2->GetYaxis()->SetTitleOffset(1.5);
        histo2->GetYaxis()->SetLabelFont(63);
        histo2->GetYaxis()->SetLabelSize(28);

        histo2->GetZaxis()->SetLabelFont(63);
        histo2->GetZaxis()->SetLabelSize(28);


	/////////////////////////
	///////SAVE PLOT/////////
	/////////////////////////

	TString png_name = hname;
	if(nlayer == "Layer1/"){
	  c7->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer1.png");
	  c8->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer1_old.png");
	}else if(nlayer == "Layer2/"){
	  c7->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer2.png");
	  c8->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer2_old.png");
	}

      }else{

	TH1F* histo = (TH1F*)file->Get(histogram);
	TH1F* histo2 = (TH1F*)file2->Get(histogram);

	gStyle->SetOptStat(0);
	TCanvas* c1 = new TCanvas("c1", "Title", 800, 800);
	TCanvas* c2 = new TCanvas("c2", "Title", 800, 800);


	//////////////////
	// First Canvas //
	//////////////////

	c1->cd();
	gPad->SetLeftMargin(0.18);
	gPad->SetRightMargin(0.05);

	histo->Draw("HIST");

	if(hname == "ChargeElec1D"){
	  histo->Rebin(5);
	}

	histo->SetLineColor(kBlue+3);
	histo->SetLineWidth(3);

	if(hname == "ChargeElec1D"){
	  histo->GetXaxis()->SetRangeUser(0,25000);
	}else if(hname == "Charge1D" || hname == "DigiCharge1D"){
	  histo->GetXaxis()->SetRangeUser(0,16);
	}else if(hname == "ClusterSize1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy"){
	  histo->GetXaxis()->SetRangeUser(0,10);
	}else if(hname == "Dx1D"){
	  histo->GetXaxis()->SetRangeUser(-50,50);
	}else if(hname == "Dy1D"){
	  histo->GetXaxis()->SetRangeUser(-150,150);
	}else if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo->GetXaxis()->SetRangeUser(-0.05,0.05);
	}

	if(hname == "Charge1D" || hname == "ChargeElec1D" || hname == "ClusterSize1D" || hname == "Dx1D" || hname == "Dy1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy"){
	  histo->GetYaxis()->SetTitle("N_{clusters}");
	}else if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo->GetYaxis()->SetTitle("N_{tracks}");
	}else if(hname == "DigiCharge1D"){
	  histo->GetYaxis()->SetTitle("N_{digis}");
	}

	histo->GetYaxis()->SetTitleSize(34);
	histo->GetYaxis()->SetTitleFont(63);

	if(hname == "Charge1D" || hname == "ChargeElec1D" || hname == "ClusterSize1D" || hname == "ClusterSize1Dy" || hname == "ClusterSize1Dx" || hname == "DigiCharge1D"){
	  histo->GetYaxis()->SetTitleOffset(2);
	}else if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo->GetYaxis()->SetTitleOffset(1.5);
	}else if(hname == "Dx1D" || hname == "Dy1D"){
	  histo->GetYaxis()->SetTitleOffset(1.7);
	}

	histo->GetYaxis()->SetLabelFont(63);                  
	histo->GetYaxis()->SetLabelSize(28);

	if(hname == "ChargeElec1D"){
	  histo->GetXaxis()->SetTitle("Cluster charge [electrons]");
	}else if(hname == "Charge1D"){
	  histo->GetXaxis()->SetTitle("Cluster charge [ToT]");
	}else if(hname == "ClusterSize1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy"){
	  histo->GetXaxis()->SetTitle("Cluster size");
	}else if(hname == "DigiCharge1D"){
	  histo->GetXaxis()->SetTitle("Digi charge [ToT]");
	}else if(hname == "TrackAngleDxdz"){
	  histo->GetXaxis()->SetTitle("#pi/2-#theta_{x} [rad]");
	}else if(hname == "TrackAngleDydz"){
	  histo->GetXaxis()->SetTitle("#pi/2-#theta_{y} [rad]");
	}else if(hname == "Dx1D"){
	  histo->GetXaxis()->SetTitle("x_{PSimHit}-x_{cluster} [#mum]");
	}else if(hname == "Dy1D"){
	  histo->GetXaxis()->SetTitle("y_{PSimHit}-y_{cluster} [#mum]");
	}

	if(hname == "Dx1D" || hname == "Dy1D"){
	  histo->GetXaxis()->SetTitleSize(34);
	}else if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo->GetXaxis()->SetTitleSize(34);
	}else{
	  histo->GetXaxis()->SetTitleSize(28);
	}

	if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo->GetXaxis()->SetTitleOffset(1);
	}else if(hname == "Dx1D" || hname == "Dy1D"){
	  histo->GetXaxis()->SetTitleOffset(1);
	}else{
	  histo->GetXaxis()->SetTitleOffset(1.15);
	}

	histo->GetXaxis()->SetTitleFont(63);
	histo->GetXaxis()->SetLabelFont(63);
	histo->GetXaxis()->SetLabelSize(28);


	///////////////////
	// Second Canvas //
	///////////////////

	c2->cd();
	gPad->SetLeftMargin(0.18);
	gPad->SetRightMargin(0.05);

	histo2->Draw("HIST");

	if(hname == "ChargeElec1D"){
	  histo2->Rebin(5);
	}

	histo2->SetLineColor(kBlue+3);
	histo2->SetLineWidth(3);

	if(hname == "ChargeElec1D"){
	  histo2->GetXaxis()->SetRangeUser(0,25000);
	}else if(hname == "Charge1D" || hname == "DigiCharge1D"){
	  histo2->GetXaxis()->SetRangeUser(0,16);
	}else if(hname == "ClusterSize1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy"){
	  histo2->GetXaxis()->SetRangeUser(0,10);
	}else if(hname == "Dx1D"){
	  histo2->GetXaxis()->SetRangeUser(-50,50);
	}else if(hname == "Dy1D"){
	  histo2->GetXaxis()->SetRangeUser(-150,150);
	}else if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo2->GetXaxis()->SetRangeUser(-0.05,0.05);
	}

	if(hname == "Charge1D" || hname == "ChargeElec1D" || hname == "ClusterSize1D" || hname == "Dx1D" || hname == "Dy1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy"){
	  histo2->GetYaxis()->SetTitle("N_{clusters}");
	}else if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo2->GetYaxis()->SetTitle("N_{tracks}");
	}else if(hname == "DigiCharge1D"){
	  histo2->GetYaxis()->SetTitle("N_{digis}");
	}

	histo2->GetYaxis()->SetTitleSize(34);
	histo2->GetYaxis()->SetTitleFont(63);

	if(hname == "Charge1D" || hname == "ChargeElec1D" || hname == "ClusterSize1D" || hname == "ClusterSize1Dy" || hname == "ClusterSize1Dx" || hname == "DigiCharge1D"){
	  histo2->GetYaxis()->SetTitleOffset(2);
	}else if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo2->GetYaxis()->SetTitleOffset(1.5);
	}else if(hname == "Dx1D" || hname == "Dy1D"){
	  histo2->GetYaxis()->SetTitleOffset(1.7);
	}

	histo2->GetYaxis()->SetLabelFont(63);                  
	histo2->GetYaxis()->SetLabelSize(28);

	if(hname == "ChargeElec1D"){
	  histo2->GetXaxis()->SetTitle("Cluster charge [electrons]");
	}else if(hname == "Charge1D"){
	  histo2->GetXaxis()->SetTitle("Cluster charge [ToT]");
	}else if(hname == "ClusterSize1D" || hname == "ClusterSize1Dx" || hname == "ClusterSize1Dy"){
	  histo2->GetXaxis()->SetTitle("Cluster size");
	}else if(hname == "DigiCharge1D"){
	  histo2->GetXaxis()->SetTitle("Digi charge [ToT]");
	}else if(hname == "TrackAngleDxdz"){
	  histo2->GetXaxis()->SetTitle("#pi/2-#theta_{x} [rad]");
	}else if(hname == "TrackAngleDydz"){
	  histo2->GetXaxis()->SetTitle("#pi/2-#theta_{y} [rad]");
	}else if(hname == "Dx1D"){
	  histo2->GetXaxis()->SetTitle("x_{PSimHit}-x_{cluster} [#mum]");
	}else if(hname == "Dy1D"){
	  histo2->GetXaxis()->SetTitle("y_{PSimHit}-y_{cluster} [#mum]");
	}

	if(hname == "Dx1D" || hname == "Dy1D"){
	  histo2->GetXaxis()->SetTitleSize(34);
	}else if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo2->GetXaxis()->SetTitleSize(34);
	}else{
	  histo2->GetXaxis()->SetTitleSize(28);
	}

	if(hname == "TrackAngleDxdz" || hname == "TrackAngleDydz"){
	  histo2->GetXaxis()->SetTitleOffset(1);
	}else if(hname == "Dx1D" || hname == "Dy1D"){
	  histo2->GetXaxis()->SetTitleOffset(1);
	}else{
	  histo2->GetXaxis()->SetTitleOffset(1.15);
	}

	histo2->GetXaxis()->SetTitleFont(63);
	histo2->GetXaxis()->SetLabelFont(63);
	histo2->GetXaxis()->SetLabelSize(28);


	/////////////////////////
	///////SAVE PLOT/////////
	/////////////////////////

	TString png_name = hname;
	if(nlayer == "Layer1/"){
	  c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer1.png");
	  c2->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer1_old.png");
	}else if(nlayer == "Layer2/"){
	  c1->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer2.png");
	  c2->SaveAs("/afs/cern.ch/user/c/clasaosa/plotter/ElectronsPerADC/"+png_name+"_layer2_old.png");
	}
      }
    }
  }
}
