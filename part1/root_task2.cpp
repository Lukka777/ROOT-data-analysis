#include <TApplication.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TF1.h>      // для функції розподілу
#include <TStyle.h>

int main(int argc, char** argv) {
  // Ініціалізація ROOT-додатка (щоб з’явилось вікно)
  TApplication app("app", &argc, argv);

  // Канва
  TCanvas* c = new TCanvas("c", "task1", 900, 600);

  // 1D гістограма: 100 бінів у [0,4]
  TH1F h("h1", "task1 histogram;X;Entries (normalized)", 100, 0.0, 4.0);

  // Функція-джерело випадкових чисел (норм. розподіл усередині [0,4])
  TF1 fgaus("fgaus", "gaus(0)", 0.0, 4.0);
  fgaus.SetParameters(1.0, 2.0, 0.5); // амплітуда, середнє, sigma

  // Наповнюємо
  h.FillRandom("fgaus", 100000);

  // Оформлення (аналог твоїх SetHist.../SetLine...)
  h.SetFillStyle(1001);
  h.SetLineWidth(2);

  // Малюємо нормованою (на 1.0)
  h.DrawNormalized("HIST", 1.0);

  c->Update();              // промалювати
  app.Run(); 

  return 0;

/*
ROOTSYS_OPTS="-b" g++ root_task2.cpp -o task1 `root-config --cflags --libs` && ./task2
*/

}