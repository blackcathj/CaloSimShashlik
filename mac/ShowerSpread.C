/*
 * ShowerSpread.C
 *
 *  Created on: Mar 23, 2013
 *      Author: jinhuang
 */

void ShowerSpread()
{
	gStyle -> SetOptStat(0);

	TFile *_file0 = TFile::Open("script/ShowerSpread.root");

	TH1D * hY = Hit_YZ->ProjectionX();
	TH1D * hX = Hit_XZ->ProjectionX();
	const int nbins = hY->GetXaxis()->GetNbins();
	TH1D * hY_Int = new TH1D("hY_Int", "", nbins / 2, 0, 300);

	double inte = 0;
	for (int i = 0; i < nbins / 2 - 1; i++)
	{
		inte += hY->GetBinContent(nbins / 2 - i);
		inte += hY->GetBinContent(nbins / 2 + i + 1);

		hY_Int->SetBinContent(i + 1, inte);
	}
	hY_Int->Scale(1. / inte);

	TCanvas* c1 = new TCanvas("ShowerSpread", "ShowerSpread", 1800, 800);

	c1->Divide(2, 1);
	int idx = 1;

	c1->cd(idx++);
	c1->Update();

	hY_Int->SetTitle(
	        "Lateral containment of 3GeV shower (perpendicular to track);Distance from shower center (mm);Ratio of energy contained");
	hY_Int->Draw();

	gPad->SetLogx();

	c1->cd(idx++);
	c1->Update();

	hX -> SetTitle("Lateral containment of 3GeV shower (in plane with track);X (cm), particle indenting at x=0 mm;Ratio of energy deposition per mm");
	hX -> Scale(1./hX->GetSum());
	hX -> Draw();

}

