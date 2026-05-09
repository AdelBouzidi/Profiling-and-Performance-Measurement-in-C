#include <iostream>

/**
 * Fonction de multiplication de matrices SSGEMM
 * C = beta * C + alpha * (A * B)
 * A (m, k)
 * B (k, n)
 * C (m, n)
 */
void ssgemm(int m, int n, int k, float alpha, float **A, float **B, float beta, float **C) {
    
    // Répéter 1000 fois pour forcer un temps d'exécution plus long
    for (int rep = 0; rep < 1000; ++rep) {  
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                float sum = 0.0f;
                for (int p = 0; p < k; ++p) {
                    sum += A[i][p] * B[p][j];
                }
                C[i][j] = alpha * sum + beta * C[i][j];
            }
        }
    }

    // Affichage pour vérifier que l'exécution a bien eu lieu
    std::cout << "Multiplication terminée pour une matrice de " << m << "x" << n << " exécutée 1000 fois." << std::endl;
}










//#include <iostream>
//#include <cinttypes>  // ==> Pour uint64_t
//#include <cstdlib>
//#include <ctime>

// Fonction pour récupérer les cycles CPU avec rdtsc
//inline uint64_t rdtsc() {
//    uint32_t lo, hi;
//    __asm__ volatile("rdtsc" : "=a"(lo), "=d"(hi));
//    return ((uint64_t)hi << 32) | lo;
//}
//
// Fonction de multiplication de matrices avec des tailles très grandes
//void ssgemm(int m, int n, int k, float alpha, float **A, float **B, float beta, float **C) {
//    uint64_t start_time = rdtsc();  // Mesure avant l'exécution
//
//    for (int rep = 0; rep < 100; ++rep) {  // Répéter 100 fois pour accumuler 
//du temps d'exécution
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                float sum = 0.0f;
//                for (int p = 0; p < k; ++p) {
//                    sum += A[i][p] * B[p][j];
//                }
//                C[i][j] = alpha * sum + beta * C[i][j];
//            }
//        }
//    }
//
//    uint64_t end_time = rdtsc();  // Mesure après l'exécution
//   uint64_t cycles = end_time - start_time;  // Calcul du nombre de cycles
//    std::cout << "Cycles d'exécution de ssgemm: " << cycles << std::endl;
//}








// //cblasl3.cc

// #include <cblasl3.hh>
// #include <iostream>
// /*
//  * Routines of cblas level 3
//  */

// void ssgemm(
//     int m, int n, int k,
//     float alpha,
//     float ** A,
//     float ** B,
//     float beta,
//     float ** C)
// {
    
//     for (int i = 0; i < m; ++i) { // i<m not i<=m
        
//         for (int j = 0; j < n; ++j) { //j < n not j <= n
            
//             float sum = 0.0f;
            
            
//             for (int p = 0; p < k; ++p) {
//                 sum += A[i][p] * B[p][j];
//             }

//             C[i][j] = alpha * sum + beta * C[i][j];
//         }
//     }
// 	// std::cout << "***************************************" << std::endl;
// 	// std::cout << "   WARNING: Not Yet Implemented..." << std::endl;
// 	// std::cout << "***************************************" << std::endl;
// }




