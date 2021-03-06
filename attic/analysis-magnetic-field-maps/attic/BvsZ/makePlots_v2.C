/** Script for B vs Z scan
 *
 *
 */

makePlots_v2()
{
  TTree *t0 = new TTree();
  t0->ReadFile("Input/data_2014_6_16_BvZ_helmholtz_profile_highres_2mT.txt","");
  // t0->ReadFile("Input/data_2014_06_13_BvZ_helmholtz_profile_2mT.txt","");
  t0->Print();

  TTree *t1 = new TTree();
  t1->ReadFile("Input/data_2014_6_16_BvZ_helix_highres_helmholtz.txt","");
  // t1->ReadFile("Input/data_2014_06_13_BvZ_new_helix_helmholtz.txt","");
  // t1->ReadFile("Input/data_2014_06_13_BvZ_helmholtz_profile_2mT.txt","");
  t1->Print();

  TTree *t2 = new TTree();
  // t2->ReadFile("Input/data_2014_06_13_BvZ_new_helix_helmholtz.txt","");
  // t2->ReadFile("Input/data_2014_06_13_BvZ_old_helix_2layer_helmholtz.txt","");
  t2->ReadFile("Input/data_2014_6_17_BvZ_helix_2layer_highres_helmholtz.txt","");
  t2->Print();

  TTree *t3 = new TTree();
  // t3->ReadFile("Input/data_2013_12_10_BvsZCryo2Layer.txt","");
  // t3->ReadFile("Input/data_2014_06_13_BvZ_vertical_helmholtz.txt","");
  // t3->ReadFile("Input/data_2014_6_16_BvZ_vertical_1layer_highres.txt","");
  t3->ReadFile("Input/data_2014_6_17_BvZ_vertical_rewrapped_helmholtz.txt","");
  // t3->ReadFile("Input/data_2014_6_16_BvZ_helix_2layer_highres_helmholtz.txt","");
  t3->Print();

  TTree *t4 = new TTree();
  t4->ReadFile("Input/data_2014_6_16_BvZ_vertical_2layer_highres.txt","");
  // t4->ReadFile("Input/data_2013_12_10_BvsZCryo2Layer.txt","");
  // t4->ReadFile("Input/data_2014_06_13_BvZ_verticals_2layer_helmholtz.txt","");
  t4->Print();

  vector<float> v_x_0, v_y_0, v_ex_0, v_ey_0;
  t0->Draw("B - (B_I0 - B_I0_T0) - B_I0_T0:z","");
  for ( int i = 0; i < t0->GetEntries(""); i++ )
    {
      v_x_0.push_back(t0->GetV2()[i]);
      v_y_0.push_back(t0->GetV1()[i]);
      v_ex_0.push_back(0);
      v_ey_0.push_back(0.03 / 100. * t0->GetV1()[i]);
    }
  TGraphErrors* g0 = new TGraphErrors( t0->GetEntries(""), &(v_x_0[0]), &(v_y_0[0]), &(v_ex_0[0]), &(v_ey_0[0]) );
  g0->SetLineColor(kRed);
  g0->SetMarkerColor(kRed);
  g0->SetMarkerStyle(20);
  g0->SetMarkerSize(1.1);

  vector<float> v_x_1, v_y_1, v_ex_1, v_ey_1;
  t1->Draw("B-(B_I0-B_I0_T0):z","");
  for ( int i = 0; i < t1->GetEntries(""); i++ )
    {
      v_x_1.push_back(t1->GetV2()[i]);
      v_y_1.push_back(t1->GetV1()[i]);
      v_ex_1.push_back(0);
      v_ey_1.push_back(0.03 / 100. * t1->GetV1()[i]);
    }
  TGraphErrors* g1 = new TGraphErrors( t1->GetEntries(""), &(v_x_1[0]), &(v_y_1[0]), &(v_ex_1[0]), &(v_ey_1[0]) );
  g1->SetLineColor(kBlue);
  g1->SetMarkerColor(kBlue);
  g1->SetMarkerStyle(21);
  g1->SetMarkerSize(1.1);

  vector<float> v_x_2, v_y_2, v_ex_2, v_ey_2;
  t2->Draw("B - (B_I0 - B_I0_T0) - B_I0_T0:z","");
  for ( int i = 0; i < t2->GetEntries(""); i++ )
    {
      v_x_2.push_back(t2->GetV2()[i]);
      v_y_2.push_back(t2->GetV1()[i]);
      v_ex_2.push_back(0);
      v_ey_2.push_back(0.03 / 100. * t2->GetV1()[i]);
    }
  TGraphErrors* g2 = new TGraphErrors( t2->GetEntries(""), &(v_x_2[0]), &(v_y_2[0]), &(v_ex_2[0]), &(v_ey_2[0]) );
  g2->SetLineColor(kMagenta+2);
  g2->SetMarkerColor(kMagenta+2);
  g2->SetMarkerStyle(22);
  g2->SetMarkerSize(1.2);

  vector<float> v_x_3, v_y_3, v_ex_3, v_ey_3;
  t3->Draw("B - (B_I0 - B_I0_T0) - B_I0_T0:z","");
  for ( int i = 0; i < t3->GetEntries(""); i++ )
    {
      v_x_3.push_back(t3->GetV2()[i]);
      v_y_3.push_back(t3->GetV1()[i]);
      v_ex_3.push_back(0);
      v_ey_3.push_back(0.03 / 100. * t3->GetV1()[i]);
    }
  TGraphErrors* g3 = new TGraphErrors( t3->GetEntries(""), &(v_x_3[0]), &(v_y_3[0]), &(v_ex_3[0]), &(v_ey_3[0]) );
  g3->SetLineColor(kGreen+1);
  g3->SetMarkerColor(kGreen+1);
  g3->SetMarkerStyle(22);
  g3->SetMarkerStyle(23);
  g3->SetMarkerSize(1.2);

  vector<float> v_x_4, v_y_4, v_ex_4, v_ey_4;
  t4->Draw("B - (B_I0 - B_I0_T0) - B_I0_T0:z","");
  for ( int i = 0; i < t4->GetEntries(""); i++ )
    {
      v_x_4.push_back(t4->GetV2()[i]);
      v_y_4.push_back(t4->GetV1()[i]);
      v_ex_4.push_back(0);
      v_ey_4.push_back(0.03 / 100. * t4->GetV1()[i]);
    }
  TGraphErrors* g4 = new TGraphErrors( t4->GetEntries(""), &(v_x_4[0]), &(v_y_4[0]), &(v_ex_4[0]), &(v_ey_4[0]) );
  g4->SetLineColor(kGray+2);
  g4->SetMarkerColor(kGray+2);
  g4->SetMarkerStyle(22);
  g4->SetMarkerStyle(29);
  g4->SetMarkerSize(1.2);

  TLine* lLeft = new TLine(-37,0,-37,2.2);
  //lLeft->SetLineColor(kGreen+1);
  lLeft->SetLineStyle(2);

  TLine* lRight = new TLine(37,0,37,2.2);
  //lRight->SetLineColor(kGreen+1);
  lRight->SetLineStyle(2);

  //  TLegend *leg1 = new TLegend(0.7,0.7,0.9,0.9);
  TLegend *leg1 = new TLegend(0.4,0.6,0.8,0.8);
  leg1->SetNColumns(1);
  leg1->AddEntry(g0,"No SC","p");
  leg1->AddEntry(g1,"Helix 1 layer","p");
  leg1->AddEntry(g2,"Helix 2 layers","p");
  leg1->AddEntry(g3,"Vertical 1 layer","p");
  leg1->AddEntry(g4,"Vertical 2 layers","p");

  TH1F* h_frame = new TH1F("h_frame","",131,-65.5,65.5);
  h_frame->GetYaxis()->SetTitle("B_{y} [mT]");
  h_frame->GetXaxis()->SetTitle("z - z_{c} [mm]");
  h_frame->GetYaxis()->SetRangeUser(0,2.2);
  h_frame->GetXaxis()->SetTitleOffset(1.5);

  gStyle->SetOptStat(0);

  TCanvas *c1 = new TCanvas();
  h_frame->Draw("rad");
  lLeft->Draw("same");
  lRight->Draw("same");
  leg1->Draw();
  g0->Draw("LPsame");
  g1->Draw("LPsame");
  g2->Draw("LPsame");
  g3->Draw("LPsame");
  g4->Draw("LPsame");
  gPad->RedrawAxis();
  c1->Print("../Plots/Public/BvsZ_v2_warm_cryo.eps");
  c1->Print("../Plots/Public/BvsZ_v2_warm_cryo.png");

}
