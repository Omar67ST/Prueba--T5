#include <iostream>
#include <vector>
#include "Mesa_Electoral.h"
#include "Polling_Center_Subject.h"
#include "Vote.h"
#include "Candidate.h"

int main() {
    std::cout << "=== SIMULACION SISTEMA DE VOTACION BLOCKCHAIN ===\n\n";

    // --- crear las 3 mesas electorales (observers) ---
    MesaElectoral mesa1("Mesa 1 - Lima");
    MesaElectoral mesa2("Mesa 2 - Arequipa");
    MesaElectoral mesa3("Mesa 3 - Cusco");

    // --- crear la red electoral (subject) y registrar las mesas ---
    PollingCenterSubject red_electoral;
    red_electoral.attach(&mesa1); // mesa1 escucha la red
    red_electoral.attach(&mesa2); // mesa2 escucha la red
    red_electoral.attach(&mesa3); // mesa3 escucha la red

    std::cout << "3 mesas registradas en la red electoral.\n\n";

    // --- crear el primer lote de votos ---
    std::vector<Vote> lote1 = {
        {"hash_votante_001", Candidate::KEIKO_FUJIMORI},
        {"hash_votante_002", Candidate::ROBERTO_PALOMINO},
        {"hash_votante_003", Candidate::RAFAEL_LOPEZ},
        {"hash_votante_004", Candidate::CESAR_ACUNA},
        {"hash_votante_005", Candidate::KEIKO_FUJIMORI},
    };

    std::cout << "--- Mesa 1 mina el Bloque 1 ---\n";

    // mesa1 crea y mina el bloque (usa el singleton directamente)

    Block bloque1(1, "0", lote1); // id=1, sin bloque previo
    bloque1.mineBlock(3);         // dificultad 3: hash debe empezar con "000"

    std::cout << "Bloque 1 minado con nonce=" << bloque1.getNonce()
              << " | Hash: " << bloque1.getCurrentHash() << "\n\n";

    // --- notificar a las otras dos mesas ---
    std::cout << "--- Propagando bloque a la red ---\n";
    red_electoral.notificarNuevoBloque(bloque1); // dispara update() en mesa2 y mesa3

    std::cout << "\n--- Segundo lote de votos ---\n";

    // --- crear el segundo lote de votos ---
    std::vector<Vote> lote2 = {
        {"hash_votante_006", Candidate::KEIKO_FUJIMORI},
        {"hash_votante_007", Candidate::ROBERTO_PALOMINO},
    };

    Block bloque2(2, bloque1.getCurrentHash(), lote2); // enlaza con bloque1
    bloque2.mineBlock(3);

    std::cout << "Bloque 2 minado con nonce=" << bloque2.getNonce()
              << " | Hash: " << bloque2.getCurrentHash() << "\n\n";

    std::cout << "--- Propagando bloque 2 a la red ---\n";
    red_electoral.notificarNuevoBloque(bloque2);

    std::cout << "\n=== FIN DE SIMULACION ===\n";
    
    system("pause");
    return 0;
}