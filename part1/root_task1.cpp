#include <TApplication.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TStyle.h>

int main(int argc, char** argv) {

  TApplication app("app", &argc, argv);

  TCanvas* c = new TCanvas("c", "task1", 900, 600);

  TH1F h("h1", "task1 histogram;X;Entries (normalized)", 100, 0.0, 4.0);

  const int n = 5;
  double xs[n] = {1.1, 2.3, 3.7, 4.0, 5.9};
  double ws[n] = {1,   2,   0.5, 1,   1}; 

  h.FillN(n, xs, ws);

  h.SetFillStyle(1001);
  h.SetLineWidth(2);

  h.Draw("Hist");

  c->Update();              
  app.Run(); 

  return 0;

  /*
  g++ root_task1.cpp -o root_task1 `root-config --cflags --libs` ./root_task1
  */
}