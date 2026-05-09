#include <iostream>

#include <cblasl0.hh>
#include <cblasl1.hh>
#include <cblasl3.hh>

#include <cinttypes>

extern __inline__ uint64_t rdtsc(void)
{
  uint64_t a, d;
  __asm__ volatile ("rdtsc" : "=a" (a), "=d" (d));
  return (d<<32) | a;
}


int main(int argc, char **argv)
{
  
  int Size = 252;  // Valeur par défaut

  if (argc > 1) {
      Size = atoi(argv[1]);  // Mise à jour si un argument est passé
  } 

  // Création des vecteurs
  float **m1=mmsalloc(Size,Size);
  float **m2=mmsalloc(Size,Size);
  float **m3=mmsalloc(Size,Size);


  // Initialisation des Vecteurs
  mmsinit(Size,Size, m1,1.0,1.0);
  mmsinit(Size,Size, m2,1.0,0.0);
  mmsinit(Size,Size, m3,0.0,0.0);
  //scopy(Size, sv2, 1, sv3, 1);

  if (Size<128)
  {
    std::cout << "\n\n===========================================\n";
    std::cout << "Matrices before computations : \n";
    std::cout << "===========================================\n";
    mmsdump(Size, Size, m1);
    mmsdump(Size, Size, m2);
    mmsdump(Size, Size, m3);
  }


  ssgemm(Size, Size, Size, 1.0, m1, m2, 1.0, m3);


  if (Size<128)
  {
    std::cout << "\n\n===========================================\n";
    std::cout << "Matrices after computations : \n";
    std::cout << "===========================================\n";
    mmsdump(Size, Size, m1);
    mmsdump(Size, Size, m2);
    mmsdump(Size, Size, m3);
  }
  mmsfree(m1, Size, Size);
  mmsfree(m2, Size, Size);
  mmsfree(m3, Size, Size);

  return 0;
}
