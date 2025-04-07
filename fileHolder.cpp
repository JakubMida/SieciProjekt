//#include <iostream>
//#include <fstream>
//#include <stdexcept>
//#include "UAR.h"
//#include "arx.h"
//#include "regulator.h"
//class KonfiguracjaIO {
//public:
//    static void zapiszDoPlikuBinarnego(const UkladRegulacji& uklad, const std::string& nazwaPliku) {
//        std::ofstream plik(nazwaPliku, std::ios::binary);
//        if (!plik) {
//            throw std::ios_base::failure("Nie uda³o siê otworzyæ pliku do zapisu.");
//        }
//
//        // Zapisz dane regulatora PID
//        const RegulatorPID& regulator = uklad.getRegulator();   //do tego tez cos jeszcze trzeba wymyslic bo narazie lipa fhuj
//        plik.write(reinterpret_cast<const char*>(&regulator.kp), sizeof(regulator.kp));
//        plik.write(reinterpret_cast<const char*>(&regulator.ki), sizeof(regulator.ki));
//        plik.write(reinterpret_cast<const char*>(&regulator.kd), sizeof(regulator.kd));
//        plik.write(reinterpret_cast<const char*>(&regulator.poprzedni_uchyb), sizeof(regulator.poprzedni_uchyb));
//        plik.write(reinterpret_cast<const char*>(&regulator.sumaryczny_uchyb), sizeof(regulator.sumaryczny_uchyb));
//
//        // Zapisz dane modelu ARX
//        const ARXModel& model = uklad.getModel();
//        plik.write(reinterpret_cast<const char*>(&model.rozmiarA), sizeof(model.rozmiarA));
//        plik.write(reinterpret_cast<const char*>(&model.rozmiarB), sizeof(model.rozmiarB));
//        plik.write(reinterpret_cast<const char*>(&model.opoznienie), sizeof(model.opoznienie));
//        plik.write(reinterpret_cast<const char*>(&model.zaklocenie), sizeof(model.zaklocenie));
//
//        plik.write(reinterpret_cast<const char*>(model.A), model.rozmiarA * sizeof(double));
//        plik.write(reinterpret_cast<const char*>(model.B), model.rozmiarB * sizeof(double));
//
//        plik.close();
//    }
//
//    static UkladRegulacji wczytajZPlikuBinarnego(const std::string& nazwaPliku) {
//        std::ifstream plik(nazwaPliku, std::ios::binary);
//        if (!plik) {
//            throw std::ios_base::failure("Nie uda³o siê otworzyæ pliku do odczytu.");
//        }
//
//        // Odczytaj dane regulatora PID
//        double kp, ki, kd, poprzedni_uchyb, sumaryczny_uchyb;
//        plik.read(reinterpret_cast<char*>(&kp), sizeof(kp));
//        plik.read(reinterpret_cast<char*>(&ki), sizeof(ki));
//        plik.read(reinterpret_cast<char*>(&kd), sizeof(kd));
//        plik.read(reinterpret_cast<char*>(&poprzedni_uchyb), sizeof(poprzedni_uchyb));
//        plik.read(reinterpret_cast<char*>(&sumaryczny_uchyb), sizeof(sumaryczny_uchyb));
//        RegulatorPID regulator(kp, ki, kd);
//        regulator = poprzedni_uchyb;//seter poprzedniego uchybu dodac
//        regulator.sumaryczny_uchyb = sumaryczny_uchyb;//seter sumy uchybow
//
//        // Odczytaj dane modelu ARX
//        int rozmiarA, rozmiarB, opoznienie;
//        double zaklocenie;
//        plik.read(reinterpret_cast<char*>(&rozmiarA), sizeof(rozmiarA));
//        plik.read(reinterpret_cast<char*>(&rozmiarB), sizeof(rozmiarB));
//        plik.read(reinterpret_cast<char*>(&opoznienie), sizeof(opoznienie));
//        plik.read(reinterpret_cast<char*>(&zaklocenie), sizeof(zaklocenie));
//
//        std::vector<double> A,B;
//        plik.read(reinterpret_cast<char*>(A.data()), rozmiarA * sizeof(double));
//        plik.read(reinterpret_cast<char*>(B.data()), rozmiarB * sizeof(double));
//        ARXModel model(A, B, opoznienie, zaklocenie);
//
//        plik.close();
//        return UkladRegulacji(regulator, model);
//    }
//};
